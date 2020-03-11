#include <stdlib.h>
#include <stdio.h>

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

Node * makenode(char * name, int rank, double percentage, int numOfBabies);
void addFirst(char *name, int rank, double percentage, int numOfBabies);
void addLast(char * name, int rank, double percentage, int numOfBabies);
void printForward();
