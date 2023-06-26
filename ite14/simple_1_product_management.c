/**
A simple program that allows the user to add and display products. It uses an array of structures to store product information. The program provides a menu to add a product, display all products, or exit.
*/

#include <stdio.h>
#define MAX 50
int totalProd = 0;

typedef struct product {
  int id;
  char name[MAX];
  int quantity;
} Product;

void add(Product *pr);
void display(Product *pr);
void menu(Product *pr);

int main() {
  Product pr[totalProd], *ptr;
  ptr = pr;
  menu(ptr);

  return 0;
}

void add(Product *pr) {
  (pr + totalProd)->id = totalProd + 1;
  printf("Product Name: ");
  scanf(" %s", (pr + totalProd)->name);
  printf("Product Quantity: ");
  scanf("%d", &(pr + totalProd)->quantity);
  totalProd++;

  menu(pr);
}

void display(Product *pr) {
  for (int i = 0; i < totalProd; i++) {
    printf("\n--------------\n");
    printf("Product ID: %d\nProduct Name: %s\nProduct Quantity: %d\n",
           (pr + i)->id, (pr + i)->name, (pr + i)->quantity);
    printf("--------------\n");
  }

  menu(pr);
}

void menu(Product *pr) {
  int choice;
  printf("\n\n--------------\n");
  printf(
      "1. Add a product\n2. Display products\n3. Exit\nChoice (1, 2 or 3) => ");
  scanf("%d", &choice);
  printf("--------------\n\n");

  switch (choice) {
  case 1:
    add(pr);
    break;
  case 2:
    display(pr);
    break;
  case 3:
    break;
  default:
    break;
  }
}