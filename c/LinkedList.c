#include <stdio.h>
#include <stdlib.h>
struct Element
{
  double value;
  struct Element *nextNode;
};

struct Container
{
  int size;
  struct Element *initialNode;
};

typedef struct Container Linkedlist;
typedef struct Element Node;

int
addFirstElement (Linkedlist *container, Node *newElement)
{
  container->initialNode = newElement;
  return 1;
}

int
add (Linkedlist *container, Node *newElement)
{
  Node *iterator = container->initialNode;
  int addedCorrectly = 1;
  if (iterator == NULL)
    addedCorrectly = addFirstElement (container, newElement);
  else
    {
      while (iterator->nextNode != NULL)
	      iterator = iterator->nextNode;
      iterator->nextNode = newElement;
    }
    container->size++;
    return addedCorrectly;
}
/*El uso de malloc, reserva memoria, por lo tanto no perdemos el puntero*/
int
addValue (Linkedlist *container, double val)
{
  Node *newElement = malloc(sizeof(Node));
  newElement->value = val;
  newElement->nextNode = NULL;
  return add(container, newElement);
}
Node*
searchValue(Linkedlist *container, double val){
   Node *element = container->initialNode;
   while (element != NULL && element->value != val)
      element = element->nextNode;
   return element;
}

// TODO Remove by index

// int
// removeValue(Linkedlist* container, int index){
//    Node *element = container->initialNode;
//    int i = 0;
//    while (element != NULL)
//      element = element->nextNode;
//    return element;
// }

void
printList (Linkedlist *container)
{
  Node *element = container->initialNode;
  printf("[");
  int i = 0;
  while (element != NULL)
  {
    printf("(%d)%f, ",i++, element->value);
    element = element->nextNode;
    }
    printf("]\n");
}
int
main ()
{
  Linkedlist container;
  Node val, val2, val3;
  val.value = 15.;
  val.nextNode = NULL;
  val2.value = -19.;
  val2.nextNode = NULL;
  val3.value = 29.;
  val3.nextNode = NULL;
  //Tests manuales
  add(&container, &val);
  add(&container, &val2);
  add(&container, &val3);
  //Test con un solo valor
  addValue(&container, 29.5);
  //Test con un for
  for (int i = 0; i < 11; i++)
    addValue(&container, i * 1.);
  printList(&container);
  //Test elemento dentro, y fuera de la lista
  double ejemplo = 10.;
  Node* valor = searchValue(&container, ejemplo);
  printf("El valor %f está? %d\n", ejemplo, valor != NULL);
  ejemplo *= -1;
  valor = searchValue(&container, ejemplo);
  printf("El valor %f está? %d\n", ejemplo, valor != NULL);
  //Tamaño lista
  printf("Tamaño de %d\n", container.size);
}