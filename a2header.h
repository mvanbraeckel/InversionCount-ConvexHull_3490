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

// ======================================================================
void p11();

// ======================================================================

void flush_input(char *input);

void read_ints(char* filename, int arr[50000]);

#endif