#include "mylinkedlist.h"


Node * makenode(char * name, int rank, int numOfBabies){
    Node *new;
    if ( (new = (Node *) malloc( sizeof(Node) ) )!= NULL) {
      //dynamic allocation for strings
      new -> data.name = malloc(sizeof(char) *20);
      strcpy(new -> data.name, name);
      new -> data.rank = rank;
      new -> data.numOfBabies = numOfBabies;
      new -> next = NULL;
      new -> previous = NULL;
    }else{
        printf("Out of memory!\n");
        exit(0);
    }
    return new;
}


void add(Node ** head, char * name, int rank, int numOfBabies){
    Node *new;
    new = makenode(name,rank,numOfBabies);
    if(*head == NULL){
      *head = new;
    }else{
      Node * current = *head;
      while ( current -> next != NULL && strcmp(current -> data.name, name) < 0  ) {
          current = current -> next;
      }
      //current is lexicographically greater than new node.
      //insert new node before current node.
      if(current -> previous == NULL){ // current node is head node.
        new -> next = current;
        current -> previous = new;
        *head = new;
        return;
      }else{
        current -> previous -> next = new;
      }
      new -> previous = current -> previous;
      new -> next = current;
      current -> previous = new;
    }
}

void printForward(Node ** head){
    Node *current = *head;
    while(current != NULL){
        printf("%s\t%d\t%d\t%f\n", current->data.name, current->data.rank, current->data.numOfBabies, current->data.percentage);
        current = current -> next;
    }
}

void addPercentages(Node **head){
    Node * current = *head;
    double sum = 0;
    int count = 0; // number of names in the list;
    while(current != NULL){
      sum += (double) (current -> data.numOfBabies);
      current = current -> next;
      count++;
    }

    current = *head;

    while(current != NULL){
      current -> data.percentage = 100 * ((current -> data.numOfBabies) / sum);
      current = current -> next;
    }
}
