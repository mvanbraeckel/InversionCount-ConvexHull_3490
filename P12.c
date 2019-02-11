/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 10/02/2019
 * @file P12.c
 * @brief A2 Problem 1.3 - b) mergesort-based, recursive divide-and-conquer algorithm to count the number of inversions
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
    
    // count #of inversions, also track time
    ftime(&t_start);
    int* temp = (int*)malloc(sizeof(int) * 50000);
    mergeSort(arr, temp, 0, 49999, &count);
    ftime(&t_end);

    // calc execution time, then display results
    int t_elapsed = (int)( 1000.0*(t_end.time - t_start.time) + (t_end.millitm - t_start.millitm) );
    printf("Inversion Count = %d | Recursive Divide-and-Conquer Time = %d milliseconds\n", count, t_elapsed);
    free(temp);
}

// Sorts the input array, returns the #of inversions
void mergeSort(int arr[], int temp[], int left, int right, int *count) {
    if(left < right) {
        // divide array into halves, then mergeSort each separately, then merge it back together
        int mid = left + (right - left) / 2; // = (l+r)/2, avoids overflow for large numbers

        // total #of inversions = left-part + right-part + merging-part
        mergeSort(arr, temp, left, mid, count);
        mergeSort(arr, temp, mid+1, right, count);
        merge(arr, temp, left, mid+1, right, count);
    }
}

// Merges two sorted arrays, returns #of inversions
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

/*// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r, int *count) { 
    // create temp arrays
    int n1 = m - l + 1;
    int n2 =  r - m;
    int left[n1], right[n2];

    // Copy data to temp arrays
    for(int i = 0; i < n1; i++) left[i] = arr[l + i];
    for(int j = 0; j < n2; j++) right[j] = arr[m + 1+ j];

    // Merge the temp arrays back into arr[l..r]
    // Initial indices of 1st, 2nd, merged subarrays
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            //arr[k] = left[i];
            i++;
        } else {
            //arr[k] = right[j];
            j++;
            (*count)++;
        }
        k++;
    } 
  
    // Copy the remaining elements of left and right arrays, if there are any
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
} 
  
// l is for left index and r is right index of the sub-array of arr to be sorted
void mergesort(int arr[], int l, int r, int *count) {
    if(l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergesort(arr, l, m, count);
        mergesort(arr, m+1, r, count);
        merge(arr, l, m, r, count);
    }
}*/


/* Function to print an array */
void printArray(int A[], int size) {
    for(int i = 1; i <= size; i++) {
        printf("%d ", A[i-1]);
        if(i % 5 == 0) printf("\n");
    }
    printf("\n");
}