//Determine whether the number entered by the user is in the list 10 → 20 → 30 → 40 → NULL.
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
    int target, found = 0;

    printf("Enter the value to search for: ");
    scanf("%d", &target);

    struct Node *current = head;
    while (current != NULL) {
        if (current->data == target) {
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found) {
        printf("%d found on the list.\n", target);
    } else {
        printf("%d Not found in the list.\n", target);
    }

    free(n1); free(n2); free(n3); free(n4);

    return 0;
}