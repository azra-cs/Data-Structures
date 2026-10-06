/*Write a C program that performs insertion and deletion operations based on position in a singly linked list.
You are expected to implement the following functions:
● void insertAt(Node** head, int value, int position);

Inserts the given `value` into the linked list at the specified `position` (index).
If the insertion is at position 0 or a negative position, the new node is added to the beginning of the list.
If the given position is greater than the number of elements in the list, the new node is added to the end of the list.

● void deleteAt(Node** head, int position);

Deletes the node at the given position from the list.
If the node at position 0 is deleted, the head node is updated to the next node.
If an invalid position is entered, no operation is performed.

● void printList(Node* head);

Prints the elements of the list from beginning to end.

● void clear(Node** head);

Frees all nodes in the list and empties the list.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
void insertAt(Node** head, int value, int position);
void deleteAt(Node** head, int position);
void printList(Node* head);
void clear(Node** head);

// 1. Insert a node according to position
void insertAt(Node** head, int value, int position) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Insert at the beginning if position <= 0 or the list is empty
    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Case 2: Move to the target position or the end of the list
    Node* temp = *head;
    int currentPos = 0;

    while (temp->next != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    // Link the new node
    newNode->next = temp->next;
    temp->next = newNode;
}

// 2. Delete a node according to position
void deleteAt(Node** head, int position) {
    // Do nothing if the list is empty or the position is negative
    if (*head == NULL || position < 0) {
        return;
    }

    Node* temp = *head;

    // Case 1: Delete the node at position 0
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Case 2: Move to the node before the one to be deleted
    int currentPos = 0;
    while (temp != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    // Invalid position check
    if (temp == NULL || temp->next == NULL) {
        return;
    }

    // Mark the node to be deleted and remove it from the list
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete); // Free memory
}

// 3. Print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 4. Clear the entire list
void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL; // Set the head to NULL to empty the list
}

int main() {
    Node* head = NULL;

    printf("--- Insertion Operations ---\n");
    insertAt(&head, 10, 0);   // List: 10 -> NULL (Insert at beginning)
    insertAt(&head, 20, 1);   // List: 10 -> 20 -> NULL
    insertAt(&head, 30, 2);   // List: 10 -> 20 -> 30 -> NULL
    insertAt(&head, 5, -2);   // List: 5 -> 10 -> 20 -> 30 -> NULL (Negative index -> insert at beginning)
    insertAt(&head, 40, 10);  // List: 5 -> 10 -> 20 -> 30 -> 40 -> NULL (Large index -> insert at end)
    insertAt(&head, 15, 2);   // List: 5 -> 10 -> 15 -> 20 -> 30 -> 40 -> NULL (Insert in the middle)

    printList(head);

    printf("\n--- Deletion Operations ---\n");
    deleteAt(&head, 0);       // Delete the first node 5
    printList(head);

    deleteAt(&head, 2);       // Delete the node at index 2 (20)
    printList(head);

    deleteAt(&head, 10);      // Invalid position -> no operation
    printList(head);

    printf("\n--- Clear the List ---\n");
    clear(&head);
    printList(head);

    return 0;
}

