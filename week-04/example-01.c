/*This application will work like a music player.
The user will be able to add and delete songs, and move to the next/previous song.
The goal is to demonstrate the dynamic management of prev and next pointers.
Requirements:
 addSongToEnd(Node** head, char* name)
 removeSong(Node** head, char* name)
 playNext() and playPrevious() functions.
 Menu: Let the user manage the list through selections.
Hint:
 Update the prev and next links correctly when deleting a song.
 Display a "List is empty" warning when the list is empty.

Code skeleton:
typedef struct Song {
char name[50];
struct Song* next;
struct Song* prev;
} Song;*/
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;


// Adds a song to the end of the list
void addSongToEnd(Song** head, char* isim) {

    Song* newSong = (Song*)malloc(sizeof(Song));

    if (newSong == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newSong->name, isim);
    newSong->next = NULL;
    newSong->prev = NULL;

    // If the list is empty
    if (*head == NULL) {
        *head = newSong;
        return;
    }

    // Go to the end of the list
    Song* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new song at the end
    temp->next = newSong;
    newSong->prev = temp;
}


// Deletes a song by name
void removeSong(Song** head, char* isim) {

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Song* temp = *head;

    // Find the song
    while (temp != NULL && strcmp(temp->name, isim) != 0) {
        temp = temp->next;
    }

    // Song not found
    if (temp == NULL) {
        printf("Song not found.\n");
        return;
    }

    // If the first node is being deleted
    if (temp->prev == NULL) {
        *head = temp->next;

        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    }
    else {
        // The previous node's next pointer
        temp->prev->next = temp->next;

        // The next node's prev pointer
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);

    printf("Song deleted.\n");
}


// Move to the next song
Song* playNext(Song* current) {

    if (current == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (current->next == NULL) {
        printf("You are at the last song.\n");
        return current;
    }

    return current->next;
}


// Move to the previous song
Song* playPrevious(Song* current) {

    if (current == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (current->prev == NULL) {
        printf("You are at the first song.\n");
        return current;
    }

    return current->prev;
}


// Print the list
void printSongs(Song* head) {

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Song* temp = head;

    printf("\n--- Songs ---\n");

    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}


int main() {

    Song* head = NULL;
    Song* current = NULL;

    int choice;
    char name[50];

    do {

        printf("\n===== MUSIC PLAYER =====\n");
        printf("1. Add a song\n");
        printf("2. Delete a song\n");
        printf("3. Next song\n");
        printf("4. Previous song\n");
        printf("5. List songs\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        getchar();

        switch (choice) {

            case 1:
                printf("Song name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                addSongToEnd(&head, name);

                // If this is the first song added, make current point to it too
                if (current == NULL) {
                    current = head;
                }

                break;


            case 2:
                printf("Song to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                // If the song being deleted is current
                if (current != NULL && strcmp(current->name, name) == 0) {

                    if (current->next != NULL)
                        current = current->next;
                    else
                        current = current->prev;
                }

                removeSong(&head, name);

                break;


            case 3:
                current = playNext(current);

                if (current != NULL)
                    printf("Now playing: %s\n", current->name);

                break;


            case 4:
                current = playPrevious(current);

                if (current != NULL)
                    printf("Now playing: %s\n", current->name);

                break;


            case 5:
                printSongs(head);
                break;


            case 0:
                printf("Program terminated.\n");
                break;


            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);


    // Free the memory
    while (head != NULL) {
        Song* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}