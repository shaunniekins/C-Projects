/**
A program that uses a linked list to store product information. It includes functions to add products and display all products. Each product is represented as a node in the linked list.
**/

#include <stdio.h>
#include <stdlib.h>

struct Product {
  int id;
  char name[50];
  int quantity;
  struct Product* next;
};

struct Product* head = NULL;

void add(int id, char name[], int quantity) {
  struct Product* newNode = (struct Product*)malloc(sizeof(struct Product));
  newNode->id = id;
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->next = head;
  head = newNode;
}

void display() {
  struct Product* current = head;
  while (current != NULL) {
    printf("Product ID: %d\nProduct Name: %s\nProduct Quantity: %d\n",
           current->id, current->name, current->quantity);
    current = current->next;
  }
}

void menu() {
  int choice;
  printf("\n\n--------------\n");
  printf(
      "1. Add a product\n2. Display products\n3. Exit\nChoice (1, 2 or 3) => ");
  scanf("%d", &choice);
  printf("--------------\n\n");

  switch (choice) {
  case 1:
    int id;
    char name[50];
    int quantity;
    printf("Product ID: ");
    scanf("%d", &id);
    printf("Product Name: ");
    scanf(" %s", name);
    printf("Product Quantity: ");
    scanf("%d", &quantity);
    add(id, name, quantity);
    break;
  case 2:
    display();
    break;
  case 3:
    break;
  default:
    break;
  }
}

int main() {
  menu();

  return 0;
}
