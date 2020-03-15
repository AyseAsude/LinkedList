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
  struct node *previous;
  struct popularname data;
};

typedef struct node Node;
typedef struct popularname PopName;

Node * makenode(char * name, int rank, int numOfBabies);
void add(Node ** head, char * name, int rank, int numOfBabies);
void printForward(Node ** head);
void addPercentages(Node **head);
