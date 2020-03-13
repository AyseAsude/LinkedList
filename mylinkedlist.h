#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct popularname{
  char *name;
  int rank;
  double percentage;
  int numOfBabies;
};

struct node{
  struct node *next;
  struct popularname data;
};

typedef struct node Node;
typedef struct popularname PopName;

Node * makenode(char * name, int rank, int numOfBabies);
void addFirst(Node * head, Node * tail , char *name, int rank, int numOfBabies);
void addLast(Node ** head, Node ** tail, char * name, int rank, int numOfBabies);
void printForward(Node ** head);
