/**
An extension of the simple_1_product_management.c. It adds additional functionality to delete and update product information. The program includes new functions for deleting a product and updating a product's information. The menu is modified to include options for deleting and updating.
**/

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
  printf("\n-------------------------------------------------------------------"
         "-\n");
  printf("%20s %20s %20s\n", "Product ID", "Product Name", "Product Quantity");
  printf("-------------------------------------------------------------------"
         "-\n");
  for (int i = 0; i < totalProd; i++) {
    printf("\n%20d %20s %20d\n", (pr + i)->id, (pr + i)->name,
           (pr + i)->quantity);
  }
  printf("\n-------------------------------------------------------------------"
         "-\n");

  menu(pr);
}

void delete(Product *pr) {
  int id_del;
  printf("Product ID to delete: ");
  scanf("%d", &id_del);

  int found = 0;
  for (int i = 0; i < totalProd; i++) {
    if (id_del == (pr + i)->id) {
      found = 1;
      for (int j = i; j < totalProd; j++) {
        *(pr + j) = *(pr + j + 1);
      }
      totalProd--;
      printf("Product with ID %d deleted successfully.\n", id_del);
      break;
    }
  }

  if (found == 0) {
    printf("Product with ID %d not found.\n", id_del);
  }

  menu(pr);
}

void update(Product *pr) {
  int id_upd;
  printf("Product ID to update: ");
  scanf("%d", &id_upd);

  int found = 0;
  for (int i = 0; i < totalProd; i++) {
    if (id_upd == (pr + i)->id) {
      found = 1;
      printf("PRODUCT FOUND:\n");
      printf("Product Name: %s\n", (pr + i)->name);
      printf("Product Quantity: %d\n\n", (pr + i)->quantity);

      printf("Enter new product name: ");
      scanf(" %s", (pr + i)->name);

      printf("Enter new product quantity: ");
      scanf("%d", &(pr + i)->quantity);

      printf("Product information updated successfully.\n");
      break;
    }
  }

  if (found == 0) {
    printf("Product with ID %d not found.\n", id_upd);
  }

  menu(pr);
}

void menu(Product *pr) {
  int choice;
  printf("\n\n--------------\n");
  printf("1. Add a product\n2. Display products\n3. Delete a product info\n4. "
         "Update a product info\nChoice (1, 2, 3 or 4) => ");
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
    delete (pr);
    break;
  case 4:
    update(pr);
    break;
  default:
    break;
  }
}