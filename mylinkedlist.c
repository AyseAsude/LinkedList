#include "mylinkedlist.h"


Node * makenode(char * name, int rank, int numOfBabies){
    Node *new;
    if ( (new = (Node *) malloc( sizeof(Node) ) )!= NULL) {
      new -> data.name = name ;
      new -> data.rank = rank;
      new -> data.numOfBabies = numOfBabies;
    }else{
        printf("Out of memory!\n");
        exit(0);
    }
    return new;
}

void addFirst(Node * head, Node * tail, char *name, int rank, int numOfBabies){
    Node *new;
    new = makenode(name,rank,numOfBabies);
    if(head == NULL){
      tail = head = new;
    }else{
      new -> next = head;
    }

  }

void addLast(Node ** head, Node ** tail, char * name, int rank, int numOfBabies){
    Node *new;
    new = makenode(name,rank,numOfBabies);
    if(tail == NULL){
      *tail = *head = new;
    }else{
      (*tail) -> next = new;
      *tail = new;
    }

}

void printForward(Node ** head){
  printf("%s\n", "here");
    Node *current = &head;
    while(current != NULL){
        printf("%s\t%d\t%d\t%f\n", current->data.name, current->data.rank, current->data.numOfBabies, current->data.percentage);
        current = current -> next;
    }
}
