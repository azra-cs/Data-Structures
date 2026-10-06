//Create two Nodes containing the values ​​10 and 20, and create the list 10 → 20 → NULL.
#include <stdio.h>
struct Node {
    int data;
    struct Node *next;
};
int main(){
    struct Node n1;
    struct Node n2;

    n1.data=10;
    n2.data=20;

    n1.next=&n2;
    n2.next=NULL;
    
    printf("%d -> %d -> NULL\n", n1.data, n2.next->data);
    return 0;
}

