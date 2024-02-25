 #include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

int isEmpty(CircularQueue *queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = data;
    printf("Enqueued element: %d\n", data);
}

int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    printf("Dequeued element: %d\n", data);
    return data;
}

int find(CircularQueue *queue, int data) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No elements to find.\n");
        return 0;
    }
    int i = queue->front;
    do {
        if (queue->items[i] == data) {
            printf("Element %d found at index %d.\n", data, i);
            return 1;
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("Element %d not found in the queue.\n", data);
    return 0;
}

void display(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

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
