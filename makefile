# @author Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
# @course CIS*3490: Analysis and Design of Computer Algorithms - A2
# @version 09/02/2019
# @file makefile
# @brief compiles everything for A2
 
CC = gcc
CFLAGS = -g -Wall -std=c11 -pedantic

all: P11 P12 P21 main git

main: P11 P21 main.c a2header.h
	$(CC) $(CFLAGS) -c main.c -o bin/main.o
	$(CC) $(CFLAGS) bin/*.o -o bin/run

P11: P11.c
	$(CC) $(CFLAGS) -c P11.c -o bin/P11.o
P12: P12.c
	$(CC) $(CFLAGS) -c P12.c -o bin/P12.o
P21: P21.c
	$(CC) $(CFLAGS) -c P21.c -o bin/P21.o

git: *.c makefile
	git add makefile
	git add README.md
	git add bin
	git add *.txt
	git add *.h
	git add *.c
	git commit -m "automatic backup via makefile"
	git remote rm origin
	git config credential.helper store
	git config --global credential.helper 'cache --timeout 3600'
	git remote add origin https://github.com/mvanbraeckel/InversionCount-ConvexHull_3490.git
	git push -u origin master

clean:
	rm -f *.o bin/*