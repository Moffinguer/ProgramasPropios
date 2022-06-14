#include <stdio.h>

struct Node
{
  double value;
  struct Node *nextNode;
};

struct LinkedList
{
  struct Node *initialNode;
};

int
addFirstElement (struct LinkedList *container, struct Node *newElement)
{
  container->initialNode = newElement;
  return 1;
}

int
add (struct LinkedList *container, struct Node *newElement)
{
  struct Node *iterator = container->initialNode;
  int addedCorrectly = 1;
  if (iterator == NULL)
    addedCorrectly = addFirstElement (container, newElement);
  else
    {
      while (iterator->nextNode != NULL)
	iterator = iterator->nextNode;
      iterator->nextNode = newElement;
    }
  return addedCorrectly;

}
/*Esta funcion no genera bien la dirección de memoria, pasa algo raro*/
int
addValue (struct LinkedList *container, double val)
{
  struct Node newElement = {val, NULL};
  return add (container, &newElement);
}

void
printList (struct LinkedList *container)
{
  struct Node *element = container->initialNode;
  printf("HEADER => ");
  while (element != NULL)
    {
      printf ("%f -> ", element->value);
      element = element->nextNode;
    }
    printf("NULL\n");
}

int
main ()
{
  struct LinkedList container = { NULL };
  struct Node val = { 15., NULL };
  struct Node val2 = { -19., NULL };
  struct Node val3 = {29., NULL};
  if (add(&container, &val))
    printf ("Añadimos un elemento en la cabecera: %f\n",
	    container.initialNode->value);
  if (add(&container, &val2))
    printf ("Añadimos un elemento después: %f\n",
	    container.initialNode->nextNode->value);
  if (add(&container, &val3))
    printf ("Otro más: %f\n",
	    container.initialNode->nextNode->nextNode->value);
  if(addValue(&container, 29.5)){
      printf ("Y otro más: %f\n",
	    container.initialNode->nextNode->nextNode->nextNode->value);
  }
  printList(&container);
}