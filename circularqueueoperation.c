#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insertAtEnd(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1)) {
        printf("Queue is full. Insertion not possible.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void insertAtFront(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1)) {
        printf("Queue is full. Insertion not possible.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[front] = data;
    } else if (front == 0 && rear != MAX_SIZE - 1) {
        front = MAX_SIZE - 1;
        queue[front] = data;
    } else {
        front--;
        queue[front] = data;
    }
}

void deleteAtEnd(FILE * fp1) {

    if (front == -1 && rear == -1) {
        fprintf(fp1,"Queue is empty. Deletion not possible.\n");
    } else if (front == rear) {
        fprintf(fp1,"Deleted end element: %d\n", queue[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        fprintf(fp1,"Deleted end  element: %d\n", queue[rear]);
        rear = MAX_SIZE - 1;
    } else {
        fprintf(fp1,"Deleted end element: %d\n", queue[rear]);
        rear--;
    }
}

void deleteAtFront(FILE * fp1) {

    if (front == -1 && rear == -1) {
        printf("Queue is empty. Deletion not possible.\n");
    } else if (front == rear) {
        fprintf(fp1,"Deleted front element: %d\n", queue[front]);
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        fprintf(fp1,"Deleted  front element: %d\n", queue[front]);
        front = 0;
    } else {
        fprintf(fp1,"Deleted  front element: %d\n", queue[front]);
        front++;
    }
}

void displayQueue(FILE * fp1) {

    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        fprintf(fp1,"Queue elements: ");
        if (front <= rear) {
            while (i <= rear) {
                fprintf(fp1,"%d ", queue[i]);
                i++;
            }
        } else {
            while (i < MAX_SIZE) {
                fprintf(fp1,"%d ", queue[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                fprintf(fp1,"%d ", queue[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, data;
    FILE * fp1;


    do {
        printf("1. Insert at end\n");
        printf("2. Insert at front\n");
        printf("3. Delete at end\n");
        printf("4. Delete at front\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp1=fopen("q12.txt","a");
                data = rand() % 100;
                fprintf(fp1,"element (%d) inserted  at end successfully.\n", data);
                insertAtEnd(data);
                break;
            case 2:
                fp1=fopen("q12.txt","a");

                data= rand() % 100;
                 fprintf(fp1,"element (%d) inserted at front successfully.\n", data);
                insertAtFront(data);
                break;
            case 3:
                deleteAtEnd(fp1);
                break;
            case 4:
                deleteAtFront(fp1);
                break;
            case 5:
                displayQueue(fp1);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}
