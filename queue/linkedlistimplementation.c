#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty() {
    return (front == NULL);
}

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", x);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    free(temp);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Front: %d\n", front->data);
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- Queue (Linked List) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Empty?\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input.\n");
                    return 0;
                }
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf(isEmpty() ? "YES, empty\n" : "NO, not empty\n");
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}