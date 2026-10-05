#include <stdio.h>
#include <stdlib.h>
//Define an integer array with 10 elements in C. Take 10 elements from the user and then print these elements to the screen.
int main(){
    int arr[10];
    int i;
    //read 10 integers from user
    printf("please enter 10 integer values:\n");
    for(i=0;i<10;i++){
        printf("element  %d: ", i+1);
        scanf("%d", &arr[i]);
        }
   //display the entered elements
    printf("\n the elements of the array are:\n");
    for(i=0;i<10;i++){
        printf("element %d: %d\n", i+1, arr[i]);
    }
        }
        //T(n)=n+n=2n
        //O(n)=linear
        //S(n)=n S(n)=O(n) linear complexity

    
    
