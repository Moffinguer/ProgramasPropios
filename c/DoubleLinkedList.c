#include <stdio.h>
#include <stdlib.h>
typedef struct ElementDouble {
  double value;
  struct ElementDouble *nextNode;
  struct ElementDouble *prevNode;
} doubleNode;

typedef struct {
  struct ElementDouble *nextNode;
} doubleLinkedList;

int addElement(doubleLinkedList *container, double value) {
  int flag = 1;
  doubleNode *element = container->nextNode;
  if (element == NULL) {
    element->nextNode = NULL;
    element->prevNode = NULL;
    element->value = value;
  } else {
    while (element->nextNode != NULL)
      element = element->nextNode;
    doubleNode *newElement = malloc(sizeof(doubleNode));
    newElement->prevNode = element;
    newElement->nextNode = container->nextNode;
    newElement->value = value;
    element->nextNode = newElement;
    container->nextNode->prevNode = newElement;
  }
  return flag;
}