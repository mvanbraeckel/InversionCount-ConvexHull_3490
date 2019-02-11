/**
 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 09/02/2019
 * @file main.c
 * @brief A2 menu to run each different program to solve a program
 */

// ====================================== INCLUDES ======================================
#include "a2header.h"


int main(int argc, char* argv[]) {

    // declare variables
    char menu_input[3];

    // infinite menu loop, only ending program with '7' as input
    while(1) {
        printf("\n1. P11.c - Brute Force (Selection Sort) Inversion Count\n" \
                "2. P12.c - Recursive Divide-and-Conquer (Mergesort) Inversion Count\n" \
                "3. P21.c - Brute Force Algorithm to Solve Convex Hull Problem\n" \
                "4. P22.c - Recursive Divide-and-Conquer Quickhull Algorithm\n" \
                "5. Exit\n" \
                "Enter a code (1 – 5) and hit Return\n" \
                "algos/> ");
        fgets(menu_input, 3, stdin);    //only need the first character of input for menu option
        flush_input(menu_input);

        // checks user input
        if(strlen(menu_input) > 1) {
            // display error msg inputting more than just the number option
            printf("\nError: invald input - You must choose one of the menu options by number: [1,7]\nPlease try again\n");

        } else if(menu_input[0] == '1') {         // ================================= 1 =================================
            p11();

        } else if(menu_input[0] == '2') {         // ================================= 2 =================================
            p12();

        } else if(menu_input[0] == '3') {         // ================================= 3 =================================
            p21();

        } else if(menu_input[0] == '4') {         // ================================= 4 =================================
            p22();

        } else if(menu_input[0] == '5') {         // ================================= 7 =================================
            printf("\nGood bye!\n");    // display closing msg
            return 0;

        } else {                                  // =============================== ELSE ================================
            // display error msg for bad input
            printf("\nError: invald input - You must choose one of the menu options by number: [1,7]\nPlease try again\n");
        }
    } // end menu loop
}

// ======================================== HELPERS ========================================

/**
 * Flushes all leftover data in the stream
 * @param char *input -the string that was just read from stdin
 */
void flush_input(char *input) {
    // if the '\n' is NOT found in the word itself, flush the stream (null-terminate the input regardless)
    if(strchr(input, '\n') == NULL) {
        while ((getchar()) != '\n');
        input[strlen(input)] = '\0';
    } else {
        input[strlen(input)-1] = '\0';
    }
}

/**
 * Reads in up to 50000 integers from a file
 * @param char* filename -the name of the text file being read
 * @param int arr[] -the integer array of 50,000 to be loaded
 */
void read_ints(char* filename, int arr[50000]) {
    char buffer[51] = ""; //50 char max

    FILE *fp = fopen(filename, "r");
    // checks if fopen messed up
    if(fp == NULL) {
        fprintf(stderr, "ERROR: File could not be opened\n");

    } else {
        // read one integer at a time until the end of the file
        int i = 0;
        while(!feof(fp) && i < 50000) {
            fscanf(fp, " %s ", buffer);
            arr[i++] = atoi(buffer);
        }
    }
    fclose(fp);
}

/**
 * Reads in up to 30000 2D points from a file
 * @param char* filename -the name of the text file being read
 * @param Point p[] -the Point array of 30,000 to be loaded
 */
void read_points(char* filename, Point p[30000]) {
    char buffer[31] = ""; //30 char max

    FILE *fp = fopen(filename, "r");
    // checks if fopen messed up
    if(fp == NULL) {
        fprintf(stderr, "ERROR: File could not be opened\n");

    } else {
        // read one Point at a time until the end of the file
        int i = 0;
        while(!feof(fp) && i < 30000) {
            // read in x-value
            fscanf(fp, " %s ", buffer);
            p[i].x = atof(buffer);
            // read in y-value
            fscanf(fp, " %s ", buffer);
            p[i].y = atof(buffer);
            i++;
        }
    }
    fclose(fp);
}