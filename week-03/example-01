/*Tasks:
Implement the following functions in C using a singly linked list:
● void addOrdered(Node** head, int value);
Adds a new node to the linked list in sorted order. If the list is empty, the new node becomes the head.
For this function to produce a sorted result, the existing list must already be sorted; the function
does not reorder existing nodes.
Example: When the numbers 23, 11, 5, 9, 6, 4, 12, and 24 are added sequentially to an empty list using this function,
the list's content should be: 4 → 5 → 6 → 9 → 11 → 12 → 23 → 24.
● void removeNode(Node** head, int value);
Deletes the first node in the linked list that contains the given value.
● int count(Node* head);
Returns the number of nodes in the list.
● void printList(Node* head);
Prints the list elements to the screen from beginning to end.
● void clear(Node** head);
Frees all nodes in the list and empties the list.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
// 1. sequential addition
void addOrdered(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty or the new value is smaller than the first value
    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;

    // Find a location to add
    while (temp->next != NULL &&
           temp->next->data < value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


// 2. Remove the first node with the given value
void removeNode(Node** head, int value) {
    if (*head == NULL)
        return;

    Node* temp = *head;

    // If the node to remove is the head
    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the node immediately before the one to remove
    while (temp->next != NULL &&
           temp->next->data != value) {
        temp = temp->next;
    }

    // Remove the node if the value was found
    if (temp->next != NULL) {
        Node* deleted = temp->next;
        temp->next = deleted->next;
        free(deleted);
    }
}


// 3. Count the nodes
int count(Node* head) {
    int total = 0;

    while (head != NULL) {
        total++;
        head = head->next;
    }

    return total;
}


// 4. Print the list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}


// 5. Clear the entire list
void clear(Node** head) {
    Node* temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}



int main(void) {
    Node* head = NULL;

    int values[] = {23, 11, 5, 9, 6, 4, 12, 24};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        addOrdered(&head, values[i]);
    }

    printList(head);

    printf("Dugum sayisi: %d\n", count(head));

    removeNode(&head, 9);
    printList(head);

    clear(&head);

    printf("Dugum sayisi: %d\n", count(head));

    return 0;
}


