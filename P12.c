/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 10/02/2019
 * @file P12.c
 * @brief A2 Problem 1.3 - b) mergesort-based, recursive divide-and-conquer algorithm to count the number of inversions
 * REFERENCES:
 * https://www.geeksforgeeks.org/merge-sort/
 * https://www.geeksforgeeks.org/counting-inversions/
 */

#include "a2header.h"

/**
 * Recursive divide-and-conquer algorithm that counts number of inversions in 50000 integers
 * read from data_1.txt using mergesort-based algorithm
 */
void p12() {
    // declare variables
    int arr[50000];
    int count = 0;
    struct timeb t_start, t_end;
    
    // read in the data
    read_ints("data_1.txt", arr);
    int size = sizeof(arr)/sizeof(int);
    int temp[size];
    
    // count #of inversions, also track time
    ftime(&t_start);
    mergesort(arr, temp, 0, size-1, &count);
    ftime(&t_end);

    // calc execution time, then display results
    int t_elapsed = (int)( 1000.0*(t_end.time - t_start.time) + (t_end.millitm - t_start.millitm) );
    printf("\nInversion Count = %d | Recursive Divide-and-Conquer Time = %d milliseconds\n", count, t_elapsed);
}

// ======================================================================

/**
 * Uses mergesort to count the number of inversions using a recursive divide-and-conquer method
 * @param int arr[] -the array of integers to be checked
 * @param int temp[] -the temp array of arr[] to hold things during merging
 * @param int left -the left index (begin)
 * @param int right -the right index (end)
 * @param int *count -holds the number of inversions
 */
void mergesort(int arr[], int temp[], int left, int right, int *count) {
    if(left < right) {
        // divide array into halves, then mergesort each separately, then merge it back together
        int mid = left + (right - left) / 2; // = (l+r)/2, avoids overflow for large numbers

        // total #of inversions = left-part + right-part + merging-part
        mergesort(arr, temp, left, mid, count);
        mergesort(arr, temp, mid+1, right, count);
        merge(arr, temp, left, mid+1, right, count);
    }
}

/**
 * Does the re-merging of two sorted arrays for mergesort
 * @param int arr[] -the array of integers to be checked
 * @param int temp[] -the temp array of arr[] to hold things during merging
 * @param int left -the left index (begin)
 * @param int mid -the middle index (half)
 * @param int right -the right index (end)
 * @param int *count -holds the number of inversions
 */
void merge(int arr[], int temp[], int left, int mid, int right, int *count) {
    // Initial indices of left, right, and merged subarrays
    int i = left;
    int j = mid;
    int k = left;

    // create sorted array using both halves
    while( i <= mid-1 && j <= right ) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            *count += mid-i; // (all left after item i are inversions)
        }
    }

    // Copy any remaining elements of left and right arrays to temp, then overwrite original with merged
    while(i <= mid-1) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    for(i = left; i <= right; i++) arr[i] = temp[i];
}
