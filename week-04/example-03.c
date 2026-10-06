/*This application will simulate a printer's job queue.
Each added file is queued, and the next job is removed with the "Print" command.
Requirements:
 enqueuePrintJob(Queue* q, char* fileName)
 processNextJob(Queue* q)
 showQueue(Queue q)
 Menu: 1) Add a new file, 2) Print, 3) Show the queue
Hint:
 Do not print when the queue is empty.

 Pay attention to the FIFO principle.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;

typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;


// Adds a new file to the queue
void enqueuePrintJob(Queue* q, char* fileName) {

    PrintJob* newJob = (PrintJob*)malloc(sizeof(PrintJob));

    if (newJob == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newJob->fileName, fileName);
    newJob->next = NULL;

    // If the queue is empty
    if (q->front == NULL) {
        q->front = newJob;
        q->rear = newJob;
    }
    else {
        // Add the new element to the end of the queue
        q->rear->next = newJob;
        q->rear = newJob;
    }

    printf("File added to the queue: %s\n", fileName);
}


// Prints the next file and removes it from the queue
void processNextJob(Queue* q) {

    // If the queue is empty
    if (q->front == NULL) {
        printf("The queue is empty. There are no files to print.\n");
        return;
    }

    PrintJob* temp = q->front;

    printf("Printing: %s\n", temp->fileName);

    // Move front to the next element
    q->front = q->front->next;

    // If the queue is empty, rear should also be NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}


// Displays the queue
void showQueue(Queue q) {

    if (q.front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    PrintJob* temp = q.front;

    printf("\n--- Print Queue ---\n");

    while (temp != NULL) {
        printf("%s\n", temp->fileName);
        temp = temp->next;
    }
}


int main() {

    Queue q;

    // Initialize the queue as empty
    q.front = NULL;
    q.rear = NULL;

    int choice;
    char fileName[50];

    do {

        printf("\n===== PRINTER QUEUE =====\n");
        printf("1. Add a new file\n");
        printf("2. Print\n");
        printf("3. Show the queue\n");
        printf("0. Exit\n");
        printf("Your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:

                printf("File name: ");
                fgets(fileName, sizeof(fileName), stdin);

                // Remove the '\n' character added by fgets
                fileName[strcspn(fileName, "\n")] = '\0';

                enqueuePrintJob(&q, fileName);

                break;


            case 2:

                processNextJob(&q);

                break;


            case 3:

                showQueue(q);

                break;


            case 0:

                printf("Program terminated.\n");

                break;


            default:

                printf("Invalid choice!\n");
        }

    } while (choice != 0);


    // Free the remaining elements
    while (q.front != NULL) {

        PrintJob* temp = q.front;
        q.front = q.front->next;

        free(temp);
    }

    q.rear = NULL;

    return 0;
}