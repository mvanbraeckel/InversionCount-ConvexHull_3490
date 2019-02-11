/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 09/02/2019
 * @file P11.c
 * @brief A2 Problem 1.3 - a) brute force selection count to find the number of inversions 
 */

#include "a2header.h"

/**
 * Brute force algorithm that counts number of inversions in 50000 integers
 * read from data_1.txt using Selection Sort-based counting
 */
void p11() {
    // declare variables
    int arr[50000];
    int count = 0;
    struct timeb t_start, t_end;
    
    // read in the data
    read_ints("data_1.txt", arr);
    
    // count #of inversions, also track time
    ftime(&t_start);
    selection_count(arr, &count);
    ftime(&t_end);

    // calc execution time, then display results
    double t_elapsed = (double)( 1000.0*(t_end.time - t_start.time) + (t_end.millitm - t_start.millitm) );
    printf("Inversion Count = %d | Brute Force Time = %lf milliseconds\n", count, t_elapsed);
}

// ======================================================================

/**
 * Counts the number of inversions in the array
 * @param int arr[] -the array of 50000 integers to check
 * @param int *count -pass by ref to store number of inversions
 */
void selection_count(int arr[50000], int *count) {
    *count = 0;
    for(int i = 0; i < 49999; i++) {
        for(int j = i+1; j < 50000; j++) {
            if(arr[i] > arr[j]) {
                (*count)++;
            }
        }
    }
}