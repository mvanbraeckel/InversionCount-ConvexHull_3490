# InversionCount-ConvexHull_3490

 * @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * @course CIS*3490: Analysis and Design of Computer Algorithms - A2
 * @version 10/02/2019
 * @file README
 * @brief Analyze and compare efficiency of counting the number of inversions and solving the convex hull problem using a brute force and a recursive divide-and-conquer (mergesort or quicksort) algorithmic solution (Analysis and Design of Computer Algorithms course A2)

## Notes & Assumptions

* Assumption: data files passed are valid and have good formatting
* Assumption: max number of values in a file will be 50,000 and 30,000 respectively per question
* NOTE: the A2 description was not very strict in regards to many things, so if something was NOT explcitly outlined to be required it may not have been implemented
* NOTE: the A2 guide only recommended to "submit something like...", so I have decided to use this format of README (alternate format can be provided upon request), and I will be submitting a PDF instead of a design.txt (this would be too difficult to use to write all my answers)
* NOTE: Please see my in-code comments for more details
* NOTE: Significant references used have been sourced in my code

* Assumption: Convex Hull: emphasis on "minimum" convex hull set that encomappases the entire set -- i.e. If a point on the hull is between two other hull points, but not a vertex, it's not part of the "minimum" convex hull set
* Assumption: Inversions are counted on the original data set (no sorting while counting if sorting would interfere with/alter results)

## Makefile, then Run

My files: README.md, design.pdf, makefile, a2header.h, main.c, P11.c, P12.c, P21.c, P22.c, data_1.txt, and data_2.txt

_NOTE: make sure a bin folder exists before compiling using "make"
To compile: type "make" --all *.o files and the executable file "run" will be located in a bin folder

## main.c

Usage: ./bin/run

> You will see a menu come up, where you can choose which of the 4 questions to run, or exit. For example:

```
1. P11.c - Brute Force (Selection Sort) Inversion Count
2. P12.c - Recursive Divide-and-Conquer (Mergesort) Inversion Count
3. P21.c - Brute Force Algorithm to Solve Convex Hull Problem
4. P22.c - Recursive Divide-and-Conquer Quickhull Algorithm
5. Exit
Enter a code (1 – 5) and hit Return
algos/> 
```
* NOTE: entering '5' will exit the program
* NOTE: typing bad input will give an error message

### P11.c

Option 1: Brute Inversion Count - Example output: (approximately 6-8 seconds to run)

> ...counting inversions...
> Inversion Count = 623897407 | Brute Force Time = 7739 milliseconds

### P12.c

Option 2: Merge Inversion Count - Example output: (approximately 30 milliseconds to run)

> Inversion Count = 623897407 | Recursive Divide-and-Conquer Time = 33 milliseconds

### P21.c

Option 3: "Brute-Hull" - Example output: (approximately 45 seconds to run)
```
 ...calculating convex hull...
 	Minimum Bounding Convex Hull Set:
	=================================
	Point 001: (     1.1,   1705.6)
	Point 002: (     1.1,    331.7)
	Point 003: (     3.0,   2144.1)
	Point 004: (     3.2,     13.9)
	Point 005: (    12.3,      2.4)
	Point 006: (   137.8,   2146.6)
	Point 007: (   193.9,   2147.0)
	Point 008: (   438.8,   2147.5)
	Point 009: (   547.7,      1.2)
	Point 010: (   607.7,      1.2)
	Point 011: (  1298.6,   2147.3)
	Point 012: (  1858.6,   2146.9)
	Point 013: (  1962.2,      1.6)
	Point 014: (  2068.0,      1.9)
	Point 015: (  2110.5,      4.1)
	Point 016: (  2111.1,   2146.7)
	Point 017: (  2135.3,   2133.6)
	Point 018: (  2143.7,   2115.4)
	Point 019: (  2146.4,   2024.5)
	Point 020: (  2147.1,   1826.1)
	Point 021: (  2147.3,   1603.2)
	Point 022: (  2147.3,      7.4)
	Point 023: (  2147.4,     62.0)
	Point 024: (  2147.5,    165.4)
Brute Force Convex Hull Solution Execution Time = 48675 milliseconds
```

### P22.c

Option 4: "Quickhull" - Example Output: (approximately 50 milliseconds)

```
	Minimum Bounding Convex Hull Set:
	=================================
	Point 001: (     1.1,   1705.6)
	Point 002: (     1.1,    331.7)
	Point 003: (     3.0,   2144.1)
	Point 004: (     3.2,     13.9)
	Point 005: (    12.3,      2.4)
	Point 006: (   137.8,   2146.6)
	Point 007: (   193.9,   2147.0)
	Point 008: (   438.8,   2147.5)
	Point 009: (   547.7,      1.2)
	Point 010: (   607.7,      1.2)
	Point 011: (  1298.6,   2147.3)
	Point 012: (  1858.6,   2146.9)
	Point 013: (  1962.2,      1.6)
	Point 014: (  2068.0,      1.9)
	Point 015: (  2110.5,      4.1)
	Point 016: (  2111.1,   2146.7)
	Point 017: (  2135.3,   2133.6)
	Point 018: (  2143.7,   2115.4)
	Point 019: (  2146.4,   2024.5)
	Point 020: (  2147.1,   1826.1)
	Point 021: (  2147.3,   1603.2)
	Point 022: (  2147.3,      7.4)
	Point 023: (  2147.4,     62.0)
	Point 024: (  2147.5,    165.4)
Recursive Divide-and-Conquer Quickhull Algorithm Execution Time = 49 milliseconds
```
