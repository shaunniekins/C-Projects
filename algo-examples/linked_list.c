#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void printList(Node* node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = (Node*)malloc(sizeof(struct Node));
    second = (Node*)malloc(sizeof(struct Node));
    third = (Node*)malloc(sizeof(struct Node));

    // set data for each node
    head->data = 9;
    second->data = 3;
    third->data = 1;

    // link the nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // print the linked list
    printList(head);

    return 0;
}
struct