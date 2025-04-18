#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a song
struct Song {
    char title[100];
    struct Song* next;
};

// Head and current pointers
struct Song* head = NULL;
struct Song* current = NULL;

// Function to add a new song to the playlist
void addSong() {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));

    printf("Enter song title: ");
    getchar();  // clear newline from buffer
    fgets(newSong->title, 100, stdin);
    newSong->title[strcspn(newSong->title, "\n")] = '\0'; // remove newline
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        struct Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }

    printf("'%s' added to playlist.\n", newSong->title);
}

// Function to display the entire playlist
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n--- Playlist ---\n");
    struct Song* temp = head;
    while (temp != NULL) {
        printf("- %s\n", temp->title);
        temp = temp->next;
    }
}

// Function to play next song
void playNext() {
    if (current == NULL)
        current = head;
    else
        current = current->next;

    if (current != NULL)
        printf("Now playing: %s\n", current->title);
    else
        printf("No more songs in the playlist.\n");
}

// Main function with menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Music Playlist Manager ---\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Next Song\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displayPlaylist();
                break;
            case 3:
                playNext();
                break;
            case 0:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
