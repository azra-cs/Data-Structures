//Delete the value entered by the user from the list 10 → 20 → 30 → 40 → NULL.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = n4;
    n4->data = 40; n4->next = NULL;

    struct Node *head = n1;
    int target;

    printf("Silinecek degeri girin: ");
    scanf("%d", &target);

    struct Node *current = head;
    struct Node *previous = NULL;

    while (current != NULL && current->data != target) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }

    current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}