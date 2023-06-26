/**
Extends the functionality of the linked_list_1_product_management_linked_list.c by adding the options to delete and update a product's information. It includes the same features as the first code but with additional operations. 
**/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct product {
  int id;
  char name[MAX];
  int quantity;
  struct product* next;
} Product;

Product* head = NULL; // Head of the linked list

void add();
void display();
void menu();
void sort();
int search(int target);
void display_search();
void delete();
void update();

int main() {
  system("clear");
  menu();

  return 0;
}

void sort() {
  if (head == NULL || head->next == NULL) {
    return; // No need to sort if there are 0 or 1 nodes
  }

  int swapped;
  Product* current;
  Product* last = NULL;

  do {
    swapped = 0;
    current = head;

    while (current->next != last) {
      if (current->id > current->next->id) {
        // Swap the nodes
        int tempID = current->id;
        char tempName[MAX];
        strcpy(tempName, current->name);
        int tempQuantity = current->quantity;

        current->id = current->next->id;
        strcpy(current->name, current->next->name);
        current->quantity = current->next->quantity;

        current->next->id = tempID;
        strcpy(current->next->name, tempName);
        current->next->quantity = tempQuantity;

        swapped = 1;
      }

      current = current->next;
    }

    last = current;
  } while (swapped);
}

int search(int target) {
  if (head == NULL) {
    return -1; // List is empty
  }

  Product* current = head;
  int index = 0;

  while (current != NULL) {
    if (current->id == target) {
      return index; // Found the target ID at the current index
    }

    current = current->next;
    index++;
  }

  return -1; // Target ID not found
}

void display_search() {
  Product* node;
  // Product* current;
  Product* last = NULL;

  int value_search;

  printf("Product ID: ");
  scanf("%d", &value_search);

  if (search(value_search) != -1) {
    if (head != NULL) {
      printf("\n-------------------------------------------------------------------"
            "-\n");
      printf("%20s %20s %20s\n", "Product ID", "Product Name", "Product Quantity");
      printf("-------------------------------------------------------------------"
            "-\n");

      Product* current = head;
      while (current != NULL) {
        if(current->id == value_search){
          printf("\n%20d %20s %20d\n", current->id, current->name, current->quantity);
        }
        current = current->next;
      }

      printf("\n-------------------------------------------------------------------"
            "-\n");
    }
  } else {
    printf("No product found");
  }

  menu();
}


void add() {
  Product* newNode = (Product*)malloc(sizeof(Product));

  printf("Product ID: ");
  scanf("%d", &(newNode->id));

  // Check if the ID already exists
  if (search(newNode->id) != -1) {
    printf("ID already exists.\n");
    free(newNode); // Free the allocated memory
    menu();
    return;
  }

  printf("Product Name: ");
  scanf("%s", newNode->name);
  printf("Product Quantity: ");
  scanf("%d", &(newNode->quantity));

  newNode->next = NULL;

  if (head == NULL) {
    head = newNode; // First node in the linked list
  } else {
    // Traverse to the end of the linked list
    Product* current = head;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = newNode; // Append the new node at the end
  }

  menu();
}

void delete() {
  if (head == NULL) {
    printf("No products found.\n");
    menu();
    return;
  }

  int id_del;
  printf("Product ID to delete: ");
  scanf("%d", &id_del);

  if (head->id == id_del) {
    Product* temp = head;
    head = head->next;
    free(temp);
    printf("Product with ID %d deleted successfully.\n", id_del);
    menu();
    return;
  }

  Product* current = head;
  Product* prev = NULL;

  while (current != NULL && current->id != id_del) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Product with ID %d not found.\n", id_del);
  } else {
    prev->next = current->next;
    free(current);
    printf("Product with ID %d deleted successfully.\n", id_del);
  }

  menu();
}


void update() {
  if (head == NULL) {
    printf("No products found.\n");
    menu();
    return;
  }

  int id_upd;
  printf("Product ID to update: ");
  scanf("%d", &id_upd);

  Product* current = head;

  while (current != NULL && current->id != id_upd) {
    current = current->next;
  }

  if (current == NULL) {
    printf("Product with ID %d not found.\n", id_upd);
  } else {
    printf("PRODUCT FOUND:\n");
    printf("Product Name: %s\n", current->name);
    printf("Product Quantity: %d\n\n", current->quantity);

    int tempVal;
    printf("Enter new product id: ");
    scanf("%d", &tempVal);

    // Check if the new ID already exists
    if (search(tempVal) != -1) {
      printf("ID already exists.\n");
      menu();
      return;
    }

    current->id = tempVal;

    printf("Enter new product name: ");
    scanf("%s", current->name);

    printf("Enter new product quantity: ");
    scanf("%d", &(current->quantity));

    printf("Product information updated successfully.\n");
  }

  menu();
}

void display() {

  if (head == NULL) {
    printf("No products found.\n");
  } else {

    printf("\n-------------------------------------------------------------------"
          "-\n");
    printf("%20s %20s %20s\n", "Product ID", "Product Name", "Product Quantity");
    printf("-------------------------------------------------------------------"
          "-\n");

    Product* current = head;
    while (current != NULL) {
      printf("\n%20d %20s %20d\n", current->id, current->name, current->quantity);
      current = current->next;
    }

    printf("\n-------------------------------------------------------------------"
          "-\n");
  }

  menu();
}

void menu() {
  sort();

  int choice;
  printf("\n\n--------------\n");
  printf("1. Add a product\n2. Display products\n3. "
         "Search a product\n4. Delete a product info\n5. "
         "Update a product info\nChoice (1, 2, 3, 4 or 5) => ");
  scanf("%d", &choice);
  printf("--------------\n\n");

  switch (choice) {
    case 1:
      system("clear");
      add();
      break;
    case 2:
      system("clear");
      display();
      break;
    case 3:
      system("clear");
      display_search();
      break;
    case 4:
      system("clear");
      delete();
      break;
    case 5:
      system("clear");
      update();
      break;    
    default:
      break;
  }
}
