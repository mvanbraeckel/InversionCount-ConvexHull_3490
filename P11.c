/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 09/02/2019
 * @file P11.c
 * @brief A2 Problem 1.3 - a) brute force bubble sort to count number of inversions 
 */

#include "a2header.h"

void p11() {
    int arr[50000];
    read_ints("data_1.txt", arr);
    for(int i = 1; i <= 50000; i++) {
        printf("%d ", arr[i-1]);
        if(i % 5 == 0) printf("\n");
    }
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