#include <stdio.h>

#define MAX_SIZE 100 // maximum size of stack

int stack[MAX_SIZE]; // stack array
int top = -1; // top index of stack

void push(int data) {
    if (top == MAX_SIZE - 1) { // stack is full
        printf("Error: stack overflow\n");
        return;
    }
    stack[++top] = data; // increment top index and insert data
}

int pop() {
    if (top == -1) { // stack is empty
        printf("Error: stack underflow\n");
        return -1;
    }
    return stack[top--]; // return top element and decrement top index
}

int peek() {
    if (top == -1) { // stack is empty
        printf("Error: stack empty\n");
        return -1;
    }
    return stack[top]; // return top element
}

int isEmpty() {
    return (top == -1); // check if stack is empty
}

int isFull() {
    return (top == MAX_SIZE - 1); // check if stack is full
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop()); // should print 3
    printf("%d\n", peek()); // should print 2
    printf("%d\n", isEmpty()); // should print 0 (false)
    printf("%d\n", isFull()); // should print 0 (false)
    push(4);
    push(5);
    push(6);
    push(7);
    push(8); // should print "Error: stack overflow"
    return 0;
}
