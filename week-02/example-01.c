#include <stdio.h>
//Create a Node structure. Store the value 10 in the Node and print it to the screen.
struct Node{
    int data;
    struct Node *next;
};
    int main(){
        struct Node n1;
        n1.data=10;
        n1.next=NULL;
        printf("%d\n", n1.data);
        return 0;
        
    }

