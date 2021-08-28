/*

Simple Linked list implementation

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void printList (Node* n)
{
  while (n != NULL) {
    printf("%d ", n->data);
    n = n->next;
  }
  printf("\n");
}

// insert node at the start of the list
void push(Node** head_ref, int new_data)
{
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
  if (prev_node == NULL) {
    printf("the given prev_node cannot be null");
    return;
  }
  //alocate a new node
  Node* new_node = (Node*)malloc(sizeof(Node));
  //put data in node
  new_node->data = new_data;
  //make the next of the new node as the prev node
  new_node->next = prev_node->next;
  //move the prev_node next to the new_node;
  prev_node->next = new_node;
}

// insert node at the end of the list
void append(Node** head_ref, int new_data)
{
  // allocate node
  Node* new_node = (Node*)malloc(sizeof(Node));
  Node* last = *head_ref;
  // put data into node
  new_node->data = new_data;
  // last node so next will be null
  new_node->next = NULL;

  // if linked list is empty then make new node as head
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  // else traverse until the last node
  while (last->next != NULL)
    last = last->next;

  // change the next of last node;
  last->next = new_node;
  return;
}

int main(int argc, char *argv[])
{
  
  Node* head = NULL;

  // Testing the functionality
  append(&head, 6);
  printList(head);

  push(&head, 7);
  printList(head);

  push(&head, 1);
  printList(head);

  append(&head, 4);
  printList(head);

  insertAfter(head->next, 8);
  printList(head);

  return 0;
}
