#include "DoubleLinkedList.c"
#include "LinkedList.c"
int main(int argc, char *argv[]) {
  printf("Testeo de una lista enlazada simple:\n");
  simpleLinkedList container;
  simpleNode val, val2, val3;
  val.value = 15.;
  val.nextNode = NULL;
  val2.value = -19.;
  val2.nextNode = NULL;
  val3.value = 29.;
  val3.nextNode = NULL;
  // Tests manuales
  add(&container, &val);
  add(&container, &val2);
  add(&container, &val3);
  // Test con un solo valor
  addValue(&container, 29.5);
  // Test con un for
  for (int i = 0; i < 11; i++)
    addValue(&container, i * 1.);
  printList(&container);
  // Test elemento dentro, y fuera de la lista
  double ejemplo = 10.;
  simpleNode *valor = searchByValue(&container, ejemplo);
  printf("El valor %f está? %d\n", ejemplo, valor != NULL);
  ejemplo *= -1;
  valor = searchByValue(&container, ejemplo);
  printf("El valor %f está? %d\n", ejemplo, valor != NULL);
  // Tamaño lista
  printf("Tamaño de %d\n", container.size);
  // Borrar elemento
  if (removeValue(&container, 5)) {
    printList(&container);
    printf("Tamaño de %d\n", container.size);
  } else
    printf("No se ha borrado el elemento");
  if (removeValue(&container, container.size - 1))
    printList(&container);
  else
    printf("No se ha borrado el elemento %d\n", container.size - 1);
  valor = searchByIndex(&container, 5);
  printf("El indice %d está? %d\n con el valor %f", 5, valor != NULL,
         valor->value);
  printf("\nTesteo de una lista enlazada doble");
  doubleLinkedList dll;
  for (int i = 0; i < 4; i++) {
    addElement(&dll, i * 1.);
  }
}