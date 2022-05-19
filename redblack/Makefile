############################
## Makefile RedBlack Tree ##
############################

# -c: gives current file as output.o
# -o: indicates an optional name for the .out file

main: obj/main.o obj/node.o
	gcc obj/main.o obj/node.o -o main

# main compiler
obj/main.o: main.c node/node.h
	gcc main.c -c -o obj/main.o

# node compiler
obj/node.o: node/node.c node/node.h
	gcc node/node.c -c -o obj/node.o
