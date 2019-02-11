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
void selection_count(int arr[50000], int *count);
void mergesort(int arr[], int temp[], int left, int right, int *count); 
void merge(int arr[], int temp[], int left, int mid, int right, int *count); 

void read_points(char* filename, Point p[30000]);
int brute_convex_hull(Point p[30000], Point hull_set[30000]);
void printHull(Point a[], int n, Point hull_set[30000], int *count);
void quickHull(Point a[], int n, Point p1, Point p2, int side, Point hull_set[30000], int *count) ;
int lineDist(Point p1, Point p2, Point p);
int findSide(Point p1, Point p2, Point p);

#endif