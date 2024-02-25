#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} LinearQueue;

void enqueue(LinearQueue *queue, int data) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = data;
    printf("Enqueued element: %d\n", data);
}

int dequeue(LinearQueue *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue->items[queue->front++];
    printf("Dequeued element: %d\n", data);
    return data;
}

void find(LinearQueue *queue, int data) {
	int i;
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty. No elements to find.\n");
        return;
    }
    for ( i = queue->front; i <= queue->rear; i++) {
        if (queue->items[i] == data) {
            printf("Element %d found at index %d.\n", data, i);
            return;
        }
    }
    printf("Element %d not found in the queue.\n", data);
}

void display(LinearQueue *queue) {
	int i;
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for ( i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->items[i]);
    printf("\n");
}

int main() {
    LinearQueue queue = {{0}, -1, -1};

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    display(&queue);

    dequeue(&queue);
    find(&queue, 30);
    find(&queue, 60);
    display(&queue);

    return 0;
}

