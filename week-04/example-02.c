/*Undo Feature Simulation
Requirements:
 The user enters a word using "add text" → it is added to the stack.
 If "undo" is selected, the last added word is undone (popped).
 If "show" is selected, display the words added so far.
Expected example usage:
 &gt; add Hello
 &gt; add World
 &gt; show -&gt; Hello World
 &gt; undo
 &gt; show -&gt; Hello

Code skeleton:

typedef struct Word {
char text[50];
struct Word* next;
} Word;
void pushWord(Word** top, char* text);
void popWord(Word** top);
void showWords(Word* top);*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

// Add a new word to the stack (Push)
void pushWord(Word** top, char* text) {
    Word* newWord = (Word*)malloc(sizeof(Word));
    if (newWord == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Copy the word and add it to the list
    strncpy(newWord->text, text, sizeof(newWord->text) - 1);
    newWord->text[sizeof(newWord->text) - 1] = '\0';
    
    newWord->next = *top;
    *top = newWord;
}

// Remove the last added word from the stack (Pop - Undo)
void popWord(Word** top) {
    if (*top == NULL) {
        printf("There is no word to undo!\n");
        return;
    }
    
    Word* temp = *top;
    *top = (*top)->next;
    free(temp);
}

// Helper recursive function to display words from first to last
void printRecursive(Word* current) {
    if (current == NULL) {
        return;
    }
    // Print lower elements first so the first word entered appears first (reverse LIFO order for reading)
    printRecursive(current->next);
    printf("%s ", current->text);
}

// Display the words added so far in order
void showWords(Word* top) {
    if (top == NULL) {
        printf("The text is empty.\n");
        return;
    }
    
    printf("show -> ");
    printRecursive(top);
    printf("\n");
}

int main() {
    Word* stackTop = NULL;
    char command[10];
    char arg[50];

    while (1) {
        printf("> ");
        if (scanf("%s", command) == EOF) break;

        if (strcmp(command, "add") == 0) {
            scanf("%s", arg);
            pushWord(&stackTop, arg);
        } 
        else if (strcmp(command, "undo") == 0) {
            popWord(&stackTop);
        } 
        else if (strcmp(command, "show") == 0) {
            showWords(stackTop);
        } 
        else if (strcmp(command, "exit") == 0) {
            break;
        } 
        else {
            printf("Invalid command! (add <word>, undo, show, exit)\n");
        }
    }

    // Free the memory when the program closes
    while (stackTop != NULL) {
        popWord(&stackTop);
    }

    return 0;
}