/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 09/02/2019
 * @file a2header.h
 * @brief header file for A2
 */

#ifndef A2HEADER_H
#define A2HEADER_H

// ============================== INCLUDES ==============================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

// ============================== STRUCTS ===============================
typedef struct xy_coordinate_struct {
    double x, y;
} Point;


// ======================================================================
void p11();
void p12();
void p21();
void p22();

// ======================================================================

void flush_input(char *input);

void read_ints(char* filename, int arr[50000]);
int selection_count(int arr[], int size);
void mergesort(int arr[], int temp[], int left, int right, int *count); 
void merge(int arr[], int temp[], int left, int mid, int right, int *count); 

void read_points(char* filename, Point p[30000]);
int brute_convex_hull(Point p[], Point hull_set[], int size);
void calc_hull(Point p[], Point hull_set[], int size, int *count);
void quick_hull(Point p[], Point hull_set[], int size, Point p1, Point p2, int side, int *count) ;
int which_side(Point p1, Point p2, Point p);
int line_dist(Point p1, Point p2, Point p);

#endif