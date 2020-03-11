m: main.o mylinkedlist.o
	gcc -o m main.o mylinkedlist.o
main.o: main.c
	gcc -c main.c
mylinkedlist.o: mylinkedlist.c
	gcc -c mylinkedlist.c
