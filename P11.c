/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 09/02/2019
 * @file P11.c
 * @brief A2 Problem 1.3 - a) brute force bubble sort to count number of inversions 
 */

#include "a2header.h"

/**
 * Brute force algorithm that counts number of inversions in 50000 integers read from
 * data_1.txt using Bubble Sort algorithm
 */
void p11() {
    // declare variables
    int arr[50000];
    int count = 0;
    struct timeb t_start, t_end;
    int t_diff;

    // read in the data
    read_ints("data_1.txt", arr);
    
    // count #of inversions, also track time
    ftime(&t_start);
    bubble_count(arr, &count);
    ftime(&t_end);

    // calc execution time, then display results
    t_diff = (int) (1000.0 * (t_end.time - t_start.time) + (t_end.millitm - t_start.millitm));
    printf("Inversion count = %d | time = %d milliseconds\n", count, t_diff);
}

void bubble_count(int arr[50000], int *count) {
    *count = 0;
    for(int i = 0; i < 49999; i++) {
        for(int j = i+1; j < 50000; j++) {
            if(arr[i] > arr[j]) {
                (*count)++;
            }
        }
    }
    return;
}

/**
 * @param char* filename -the name of the text file being read
 * @param int arr[] -the created integer array of 50,000
 */
void read_ints(char* filename, int arr[50000]) {
    char buffer[31] = ""; //30 char max

    FILE *fp = fopen(filename, "r");
    // checks if fopen messed up
    if(fp == NULL) {
        fprintf(stderr, "ERROR: File could not be opened\n");

    } else {
        // read one integer at a time until the end of the file
        int i = 0;
        while(!feof(fp) && i < 50000) {
            fscanf(fp, " %s ", buffer);
            arr[i] = atoi(buffer);
            i++;
        }
    }
    fclose(fp);
}