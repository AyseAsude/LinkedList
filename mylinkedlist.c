#include "mylinkedlist.h"

Node *head;
Node *tail;

Node * makenode(char * name, int rank, double percentage, int numOfBabies){
    Node *new;
    if ( (new = (Node *) malloc( sizeof(Node) ) )!= NULL) {
      new -> data.name = name ;
      new -> data.rank = rank;
      new -> data.percentage = percentage;
      new -> data.numOfBabies = numOfBabies;
    }else{
        printf("Out of memory!\n");
        exit(0);
    }
    return new;
}

void addFirst(char *name, int rank, double percentage, int numOfBabies){
    Node *new;
    new = makenode(name,rank,percentage,numOfBabies);
    if(head == NULL){
      tail = head = new;
    }else{
      new -> next = head;
    }

  }

void addLast(char * name, int rank, double percentage, int numOfBabies){
    Node *new;
    new = makenode(name,rank,percentage,numOfBabies);
    if(tail == NULL){
      tail = head = new;
    }else{
      tail -> next = new;
      tail = new;
    }

}

void printForward(){
    Node *current = head;
    while(current != NULL){
        printf("%s\t%d\t%d\t%f\n", current->data.name, current->data.rank, current->data.numOfBabies, current->data.percentage);
        current = current -> next;
    }
}
