/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 10/02/2019
 * @file P22.c
 * @brief A2 Problem 2.3 - b) quicksort-based, recursive, divide-and-conquer algorithm to solve the Convex Hull problem (Quickhull)
 * https://www.geeksforgeeks.org/quickhull-algorithm-convex-hull/
 */

#include "a2header.h"

void p22() {
    // declare variables
    Point points[30000];
    int count = 0;
    struct timeb t_start, t_end;
    
    // read in the data
    read_points("data_2.txt", points);
    int size = sizeof(points)/sizeof(Point);
    Point hull_set[size];
    
    // determine bounding convex hull set
    ftime(&t_start);
    print_hull(points, hull_set, size, &count);
    ftime(&t_end);

    // selection sort by x-coord so it's a little easier to read
    for(int i = 0; i < count-1; i++) {
        for(int j = i+1; j < count; j++) {
            if(hull_set[i].x > hull_set[j].x) {
                Point temp = hull_set[i];
                hull_set[i] = hull_set[j];
                hull_set[j] = temp;
            }
        }
    }

    // calc execution time, then display results
    int t_elapsed = (int)( 1000.0*(t_end.time - t_start.time) + (t_end.millitm - t_start.millitm) );

    printf("\n\tMinimum Bounding Convex Hull Set:\n\t=================================\n");
    for(int i = 0; i < count; i++) {
        printf("\tPoint %03d: (%8.1lf, %8.1lf)\n", i+1, hull_set[i].x, hull_set[i].y);
    }
    printf("Recursive Divide-and-Conquer Quickhull Algorithm Execution Time = %d milliseconds\n", t_elapsed);
}

// ======================================================================

/**
 * Determines which side a Point P falls on with respect to a Line P1P2
 * @param Point p1 -first point in the line
 * @param Point p2 -second point in the line
 * @param Point p -the point being checked for where it falls wrt the line
 * @return 1 for RS, -1 for LS, 0 for in-line
 */
int which_side(Point p1, Point p2, Point p) {
    int d = (p.y-p1.y)*(p2.x-p1.x) - (p2.y-p1.y)*(p.x-p1.x);
    if(d > 0) return  1;
    if(d < 0) return -1;
    return 0;
}

/**
 * Calculates the distance a Point P and a Line P1P2
 * @param Point p1 -first point in the line
 * @param Point p2 -second point in the line
 * @param Point p -the point being checked for where it falls wrt the line
 * @return the distance between Point P and the line
 */
int line_dist(Point p1, Point p2, Point p) {
    return abs( (p.y-p1.y)*(p2.x-p1.x) - (p2.y-p1.y)*(p.x-p1.x) );
}

// End points of line L are p1 and p2.  side can have value 
// 1 or -1 specifying each of the parts made by the line L 
void quick_hull(Point a[], Point hull_set[], int size, Point p1, Point p2, int side, int *count) {
    int ind = -1;
    int max_dist = 0;

    // Find the extreme point (EP) from the line on the specified side
    for(int i = 0; i < size; i++) {
        int temp = line_dist(p1, p2, a[i]);
        if( which_side(p1, p2, a[i]) == side && temp > max_dist ) {
            ind = i;
            max_dist = temp;
        }
    }

    // If no EP, then add both to bounding set (make sure they're not already added)
    if(ind == -1) {
        bool unique1 = true;
        bool unique2 = true;
        for(int i = 0; i < *count; i++) {
            if(p1.x == hull_set[i].x && p1.y == hull_set[i].y) unique1 = false;
            if(p2.x == hull_set[i].x && p2.y == hull_set[i].y) unique2 = false;
        }
        if(unique1) hull_set[(*count)++] = p1;
        if(p1.x == p2.x && p1.y == p2.y) return; //unique2 = false;
        if(unique2) hull_set[(*count)++] = p2;
        return;
    }

    // Recur for the two parts divided by a[ind]
    quick_hull(a, hull_set, size, a[ind], p1, -which_side(a[ind], p1, p2), count);
    quick_hull(a, hull_set, size, a[ind], p2, -which_side(a[ind], p2, p1), count);
}

void print_hull(Point a[], Point hull_set[], int size, int *count) { 
    // a[i].second -> y-coordinate of the ith point 
    if (size < 3) { 
        fprintf(stderr, "\nConvex hull not possible\n"); 
        return; 
    } 
  
    // Finding the point with minimum and 
    // maximum x-coordinate 
    int min_x = 0, max_x = 0; 
    for (int i=1; i<size; i++) 
    { 
        if (a[i].x < a[min_x].x) 
            min_x = i; 
        if (a[i].x > a[max_x].x) 
            max_x = i; 
    } 
  
    // Recursively find convex hull points on 
    // one side of line joining a[min_x] and 
    // a[max_x] 
    quick_hull(a, hull_set, size, a[min_x], a[max_x], 1, count); 
  
    // Recursively find convex hull points on 
    // other side of line joining a[min_x] and 
    // a[max_x] 
    quick_hull(a, hull_set, size, a[min_x], a[max_x], -1, count); 
  
    /*printf("\nThe points in Convex Hull are:\n"); 
    for(int i = 0; i < *count; i++) {
        printf("\tPoint %03d: (%8.1lf, %8.1lf)\n", i+1, hull_set[i].x, hull_set[i].y);
    }*/
}