#include <stdio.h>
// Define an integer array with 10 elements in C. Take 10 elements from the user and then print these elements to the screen.
int main(){
    int num, originalNumber, reversedNumber=0, remainder;
    printf("enter an integer: ");
    scanf("%d",&num);
    
    originalNumber=num;
    while(num!=0){
        remainder=num%10;
        reversedNumber=reversedNumber*10+remainder;
        num=num/10;
    }
    if(originalNumber==reversedNumber){
        printf("the number is a palindrome.\n");
    }
    else{
        printf("the number is not a palindrome\n");
    }
    return 0;
    }