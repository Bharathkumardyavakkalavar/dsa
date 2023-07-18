#include<stdio.h>
#include<stdlib.h>
#define max 1000

typedef struct
 {
    int front;
    int rear;
    int ele[max];
} queue;

void initQueue(queue *q)
 {
    q->front = -1;
    q->rear = -1;
}

int isFull(queue *q)
 {
    return (q->rear == max - 1);
}

int isEmpty(queue *q)
 {
    return (q->front == -1);
}

void enqueue(queue *q, int e)
 {
    if (isFull(q))
    {
        printf("Queue is full.\n");
    } else {
        if (isEmpty(q))
        {
            q->front = 0;
        }
        q->rear++;
        q->ele[q->rear] = e;
    }
}

int dequeue(queue *q)
 {
    int e;
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    } else {
        e = q->ele[q->front];
        if (q->front == q->rear)
        {
            initQueue(q);
        } else
         {
            q->front++;
        }
        return e;
    }
}

int peek(queue *q)
 {
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    } else
    {
        return q->ele[q->front];
    }
}

void display(queue *q)
 {
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++)
         {
            printf("%d\n", q->ele[i]);
        }
    }
}

int main()
{
    queue q;
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;
    FILE* fp5;
    int p, t, q1, i, num;

    fp1 = fopen("array.txt", "w");
    printf("Enter the range:\n");
    scanf("%d %d", &p, &q1);
    printf("Enter the number:\n");
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        num = (rand() % (p - q1 + 1)) + p;
        printf("%d\n", num);
        fprintf(fp1, "%d ", num);
    }

    fclose(fp1);
    fp1 = fopen("array.txt", "r");
    fp2 = fopen("array1.txt", "w");
    fp3 = fopen("new.txt", "w");
    fp5 = fopen("cngout.txt", "w");

    initQueue(&q);

    int e, ch;

    while (1) {
        printf("\n1.enqueue\n2.dequeue\n3.peek\n4.exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (isFull(&q))
                    printf("Queue is full.\n");
                else {
                    fprintf(fp5, "\nenqueue()");
                    printf("Enter the element: ");
                    fscanf(fp1, "%d", &e);
                    printf("%d ", e);
                    fprintf(fp2, "%d ", e);
                    enqueue(&q, e);
                }
                break;
            case 2:
                if (isEmpty(&q))
                    printf("Queue is empty.\n");
                else
                    {
        e = dequeue(&q);
        fprintf(fp3, "%d ", e);
        fprintf(fp5, "\ndequeue()");
}
    break;
    case 3:
    display(&q);
    break;
    case 4:
    exit(0);
        }
    }
}
