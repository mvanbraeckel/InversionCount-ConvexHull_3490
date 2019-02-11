/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 10/02/2019
 * @file P21.c
 * @brief A2 Problem 2.3 - a) brute force algorithm to solve Convex Hull problem
 */

#include "a2header.h"

/**
 * Brute force algorithm that solves the Convex Hull problem for a set of 30000 2D points that are read from data_2.txt
 */
void p21() {
    // declare variables
    Point points[30000];
    Point hull_set[30000];
    struct timeb t_start, t_end;
    
    // read in the data
    read_points("data_2.txt", points);
    
    // determine bounding convex hull set
    printf("\n...calculating convex hull...\n");
    ftime(&t_start);
    int count = brute_convex_hull(points, hull_set);
    ftime(&t_end);

    // calc execution time, then display results
    int t_elapsed = (int)( 1000.0*(t_end.time - t_start.time) + (t_end.millitm - t_start.millitm) );
    
    for(int i = 0; i < count-1; i++) {
        for(int j = i+1; j < count; j++) {
            if(hull_set[i].x > hull_set[j].x) {
                Point temp = hull_set[i];
                hull_set[i] = hull_set[j];
                hull_set[j] = temp;
            }
        }
    }

    printf("\n\tBounding Convex Hull Set:\n\t===============================\n");
    for(int i = 0; i < count; i++) {
        printf("\tPoint %03d: (%8.1lf, %8.1lf)\n", i+1, hull_set[i].x, hull_set[i].y);
    }
    printf("Brute Force Convex Hull Solution Execution Time = %d milliseconds\n", t_elapsed);
}

// ======================================================================

/**
 * Uses brute force to solve the convex hull problem for a set of 30000 2D points
 * Two points A and B are part of the convex hull if all other points are in-line or on the same side of the line as AB,
 *      A=(x1,y1), B=(x2,y2), P(x,y)  |  d=(x−x1)(y2−y1)−(y−y1)(x2−x1) ; where d<0 is LS, d>0 is RS, & d=0 is in-line
 * @param Point p[] -the array of 30000 Points to check
 * @param Point hull_set[] -the array of Points that will contain the convex hull
 * @return the number of points in the convex hull
 * https://math.stackexchange.com/questions/274712/calculate-on-which-side-of-a-straight-line-is-a-given-point-located
 */
int brute_convex_hull(Point p[30000], Point hull_set[30000]) {
    int h = 0; // holds #of bounding points in the convex hull set

    // create line from Point I to Point J
    for(int i = 0; i < 30000; i++) {
        for(int j = 0; j < 30000; j++) {
            if(i == j) continue; //skip because same point
            bool all_left = true; //reset
            
            // if all other points are on the left or in-line, then it's a bounding point
            for(int k = 0; k < 30000; k++) {
                if(k == i || k == j) continue; // skip because same point

                // calc and check which side of line Point K is on
                double d = (p[k].x-p[i].x)*(p[j].y-p[i].y) - (p[k].y-p[i].y)*(p[j].x-p[i].x);
                if(d > 0) {
                    all_left = false;
                    break;
                }
            }

            // if it's good, add to bounding set and start checking a new one
            if(all_left) {
                //printf("\tPoint %d: (%8.1lf, %8.1lf)\n", h+1, p[i].x, p[i].y);
                bool unique1 = true;
                for(int m = 0; m < h; m++) {
                    if(p[i].x == p[m].x && p[i].y == p[m].y) {
                        unique1 = false;
                        break;
                    }
                }
                if(unique1) {
                    hull_set[h++] = p[i];
                    break;
                }
            }
        }
    }
    return h;
}
