/*Write a C program that finds the value of the middle node in a singly linked list.
You are expected to implement the following functions:
● Node* findMiddle(Node* head);

Returns the middle node of the linked list.
If the number of elements in the list is odd, the middle node is returned.
If the number of elements is even, the second of the two middle nodes is returned.
Returns NULL if the list is empty.
You can use "slow" and "fast" pointers for this operation:
o slow → advances one node at each step
o fast → advances two nodes at each step
When fast reaches the end, slow is at the middle.

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
Node* findMiddle(Node* head);
void printList(Node* head);
void clear(Node** head);

// Helper function: adds a node to the end of the list
void append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 1. Function that finds the middle node
Node* findMiddle(Node* head) {
    // Empty list check
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    // The loop continues until fast reaches the end or NULL
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // slow moves one step
        fast = fast->next->next;    // fast moves two steps
    }

    // When fast reaches the end, slow points to the middle node
    return slow;
}

// 2. Print the list
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

// 3. Clear the entire list
void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main() {
    Node* head = NULL;

    // Single-element list
    printf("--- Test 1 (Odd number of elements: 5 elements) ---\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30); // Middle node
    append(&head, 40);
    append(&head, 50);

    printList(head);
    Node* mid1 = findMiddle(head);
    if (mid1 != NULL) {
        printf("Middle node value: %d\n", mid1->data);
    }
    clear(&head);

    // Even-numbered list
    printf("\n--- Test 2 (Even number of elements: 6 elements) ---\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40); // Second middle node
    append(&head, 50);
    append(&head, 60);

    printList(head);
    Node* mid2 = findMiddle(head);
    if (mid2 != NULL) {
        printf("Middle node value (second middle): %d\n", mid2->data);
    }
    clear(&head);

    // Empty list
    printf("\n--- Test 3 (Empty list) ---\n");
    printList(head);
    Node* mid3 = findMiddle(head);
    if (mid3 == NULL) {
        printf("NULL was returned because the list is empty.\n");
    }

    return 0;
}


