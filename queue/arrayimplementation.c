#include <stdio.h>

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

int isEmpty(void) {
    return (front == -1);
}

int isFull(void) {
    return (rear == MAX - 1);
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue is FULL\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    q[rear] = x;
    printf("Enqueued: %d\n", x);
}

void dequeue(void) {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Dequeued: %d\n", q[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void peek(void) {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Front: %d\n", q[front]);
}

int main(void) {
    int choice, x;

    while (1) {
        printf("\n--- Queue (Array) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Empty?\n");
        printf("5. Is Full?\n");
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
            case 5:
                printf(isFull() ? "YES, full\n" : "NO, not full\n");
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}