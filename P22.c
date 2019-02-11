/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 10/02/2019
 * @file P22.c
 * @brief A2 Problem 2.3 - b) quicksort-based, recursive, divide-and-conquer algorithm to solve the Convex Hull problem (Quickhull)
 */

#include "a2header.h"

void p22() {
    // declare variables
    Point points[30000];
    Point hull_set[30000];
    int count = 0;
    struct timeb t_start, t_end;
    
    // read in the data
    read_points("data_2.txt", points);
    
    // determine bounding convex hull set
    ftime(&t_start);
    //int count = brute_convex_hull(points, hull_set);
    printHull(points, 30000, hull_set, &count);
    ftime(&t_end);

    // calc execution time, then display results
    int t_elapsed = (int)( 1000.0*(t_end.time - t_start.time) + (t_end.millitm - t_start.millitm) );
    
    printf("\n\tBounding Convex Hull Set:\n\t===============================\n");
    for(int i = 0; i < count; i++) {
        printf("\tPoint %03d: (%8.1lf, %8.1lf)\n", i+1, hull_set[i].x, hull_set[i].y);
    }
    printf("Recursive Divide-and-Conquer Quicklhull Algorithm Execution Time = %d milliseconds\n", t_elapsed);
}

// ======================================================================
  
// Returns the side of point p with respect to line 
// joining points p1 and p2. 
int findSide(Point p1, Point p2, Point p) { 
    int val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x); 
  
    if (val > 0) 
        return 1; 
    if (val < 0) 
        return -1; 
    return 0; 
} 
  
// returns a value proportional to the distance 
// between the point p and the line joining the 
// points p1 and p2 
int lineDist(Point p1, Point p2, Point p) { 
    return abs ((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x)); 
} 
  
// End points of line L are p1 and p2.  side can have value 
// 1 or -1 specifying each of the parts made by the line L 
void quickHull(Point a[], int n, Point p1, Point p2, int side, Point hull_set[30000], int *count) 
{ 
    int ind = -1; 
    int max_dist = 0; 
  
    // finding the point with maximum distance 
    // from L and also on the specified side of L. 
    for (int i=0; i<n; i++) 
    { 
        int temp = lineDist(p1, p2, a[i]); 
        if (findSide(p1, p2, a[i]) == side && temp > max_dist) 
        { 
            ind = i; 
            max_dist = temp; 
        } 
    } 
  
    // If no point is found, add the end points 
    // of L to the convex hull. 
    if (ind == -1) 
    {
        bool unique1 = true;
        bool unique2 = true;
        for(int i = 0; i < *count; i++) {
            if(p1.x == a[i].x && p1.y == a[i].y) {
                unique1 = false;
            }
            if(p2.x == a[i].x && p2.y == a[i].y) {
                unique2 = false;
            }
        }
        if(unique1) {
            hull_set[(*count)++] = p1;
        }
        if(unique2 && !(p2.x == p1.x && p2.y == p1.y)) {
            hull_set[(*count)++] = p2;
        }
        
        return; 
    } 
  
    // Recur for the two parts divided by a[ind] 
    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2), hull_set, count); 
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1), hull_set, count); 
} 
  
void printHull(Point a[], int n, Point hull_set[30000], int *count) { 
    // a[i].second -> y-coordinate of the ith point 
    if (n < 3) { 
        fprintf(stderr, "\nConvex hull not possible\n"); 
        return; 
    } 
  
    // Finding the point with minimum and 
    // maximum x-coordinate 
    int min_x = 0, max_x = 0; 
    for (int i=1; i<n; i++) 
    { 
        if (a[i].x < a[min_x].x) 
            min_x = i; 
        if (a[i].x > a[max_x].x) 
            max_x = i; 
    } 
  
    // Recursively find convex hull points on 
    // one side of line joining a[min_x] and 
    // a[max_x] 
    quickHull(a, n, a[min_x], a[max_x], 1, hull_set, count); 
  
    // Recursively find convex hull points on 
    // other side of line joining a[min_x] and 
    // a[max_x] 
    quickHull(a, n, a[min_x], a[max_x], -1, hull_set, count); 
  
    /*printf("\nThe points in Convex Hull are:\n"); 
    for(int i = 0; i < *count; i++) {
        printf("\tPoint %03d: (%8.1lf, %8.1lf)\n", i+1, hull_set[i].x, hull_set[i].y);
    }*/
}