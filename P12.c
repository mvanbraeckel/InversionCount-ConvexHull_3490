/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 10/02/2019
 * @file P12.c
 * @brief A2 Problem 1.3 - b) mergesort-based, recursive divide-and-conquer algorithm to count the number of inversions
 * https://www.geeksforgeeks.org/merge-sort/
 */

#include "a2header.h"

/**
 * Recursive divide-and-conquer algorithm that counts number of inversions in 50000 integers
 * read from data_1.txt using mergesort-based algorithm
 */
void p12() {

    int arr[50000];
    read_ints("data_1.txt", arr);
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) { 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) { 
    int i; 
    for (i=1; i <= size; i++) {
        printf("%d ", A[i-1]); 
        if(i % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n"); 
}