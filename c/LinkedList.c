#include <stdio.h>
#include <stdlib.h>
struct Element {
  double value;
  struct Element *nextNode;
};

struct Container {
  int size;
  struct Element *initialNode;
};

typedef struct Container simpleLinkedList;
typedef struct Element simpleNode;

int addFirstElement(simpleLinkedList *container, simpleNode *newElement) {
  container->initialNode = newElement;
  return 1;
}

int add(simpleLinkedList *container, simpleNode *newElement) {
  simpleNode *iterator = container->initialNode;
  int addedCorrectly = 1;
  if (iterator == NULL)
    addedCorrectly = addFirstElement(container, newElement);
  else {
    while (iterator->nextNode != NULL)
      iterator = iterator->nextNode;
    iterator->nextNode = newElement;
  }
  container->size++;
  return addedCorrectly;
}
/*El uso de malloc, reserva memoria, por lo tanto no perdemos el puntero*/
int addValue(simpleLinkedList *container, double val) {
  simpleNode *newElement = malloc(sizeof(simpleNode));
  newElement->value = val;
  newElement->nextNode = NULL;
  return add(container, newElement);
}
simpleNode *searchByValue(simpleLinkedList *container, double val) {
  simpleNode *element = container->initialNode;
  while (element != NULL && element->value != val)
    element = element->nextNode;
  return element;
}
simpleNode *searchByIndex(simpleLinkedList *container, int index) {
  simpleNode *element = container->initialNode;
  int i = 0;
  while (element != NULL && i++ < index)
    element = element->nextNode;
  return element;
}
int removeValue(simpleLinkedList *container, int index) {
  simpleNode *element = container->initialNode;
  int i = 0, flag = 0;
  // Stays on the previous element to modify that nextNode
  while (element != NULL && ++i < index)
    element = element->nextNode;

  if (i < container->size) {
    element->nextNode = element->nextNode->nextNode;
    container->size--;
    flag = 1;
  }
  return flag;
}

void printList(simpleLinkedList *container) {
 simpleNode *element = container->initialNode;
  printf("[");
  int i = 0;
  while (element != NULL) {
    printf("(%d)%f, ", i++, element->value);
    element = element->nextNode;
  }
  printf("]\n");
}
