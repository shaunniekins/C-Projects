/***
An extension of simple_3_enhanced_product_management.c. It adds sorting functionality to the product list based on the product IDs. The program includes a sorting function and modifies the menu to reflect the new options.
*/

#include <stdio.h>
#include <stdlib.h>
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
void sort(Product *pr);
void delete(Product *pr);
void update(Product *pr);
int search(Product *pr, int target);

int main() {
  Product pr[totalProd], *ptr;
  ptr = pr;
  system("clear");
  menu(ptr);

  return 0;
}

void sort(Product *pr) {
  for (int i = 0; i < totalProd - 1; i++) {
    for (int j = i + 1; j < totalProd; j++) {
      if ((pr + i)->id > (pr + j)->id) {
        Product tempProd = *(pr + i);
        *(pr + i) = *(pr + j);
        *(pr + j) = tempProd;
      }
    }
  }
}

int search(Product *pr, int target) {
  int low = 0;
  int high = totalProd - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (pr[mid].id == target) {
      return mid;
    } else if (pr[mid].id < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void add(Product *pr) {

  int tempVal;

  printf("Product ID: ");
  scanf("%d", &tempVal);
  for (int i = 0; i < totalProd; i++) {
    if (pr[i].id == tempVal) {
      printf("ID already exists");
      menu(pr);
    }
  }
  (pr + totalProd)->id = tempVal;

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

  int found_val = search(pr, id_del);

  if (found_val == -1) {
    printf("Product with ID %d not found.\n", id_del);
    return;
  }

  // shift elements one position to the right
  for (int i = found_val; i < totalProd - 1; i++) {
    *(pr + i) = *(pr + i + 1);
  }

  totalProd--;
  printf("Product with ID %d deleted successfully.\n", id_del);

  menu(pr);
}

void update(Product *pr) {
  int id_upd;
  printf("Product ID to update: ");
  scanf("%d", &id_upd);

  int found_val = search(pr, id_upd);
  int tempVal;

  if (found_val == -1) {
    printf("Product with ID %d not found.\n", id_upd);
  } else {
    printf("PRODUCT FOUND:\n");
    printf("Product Name: %s\n", (pr + found_val)->name);
    printf("Product Quantity: %d\n\n", (pr + found_val)->quantity);

    printf("Enter new product id: ");
    scanf("%d", &tempVal);
    // scanf("%d", &(pr + found_val)->id);
    for (int i = 0; i < totalProd; i++) {
      if (pr[i].id == tempVal) {
        printf("ID already exists");
        menu(pr);
      }
    }
    (pr + found_val)->id = tempVal;

    printf("Enter new product name: ");
    scanf(" %s", (pr + found_val)->name);

    printf("Enter new product quantity: ");
    scanf("%d", &(pr + found_val)->quantity);

    printf("Product information updated successfully.\n");
  }

  menu(pr);
}

void menu(Product *pr) {
  sort(pr);

  int choice;
  printf("\n\n--------------\n");
  printf("1. Add a product\n2. Display products\n3. Delete a product info\n4. "
         "Update a product info\nChoice (1, 2, 3 or 4) => ");
  scanf("%d", &choice);
  printf("--------------\n\n");

  switch (choice) {
  case 1:
    system("clear");
    add(pr);
    break;
  case 2:
    system("clear");
    display(pr);
    break;
  case 3:
    system("clear");
    delete (pr);
    break;
  case 4:
    system("clear");
    update(pr);
    break;
  default:
    break;
  }
}