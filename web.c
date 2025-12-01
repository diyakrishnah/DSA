#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 100

// Node of doubly linked list
typedef struct Node {
    char url[MAX_URL];
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;     // First page (optional)
Node *current = NULL;  // Current page pointer

// Function to delete all nodes after current (clear forward history)
void clearForwardHistory() {
    if (current == NULL) return;

    Node *temp = current->next;
    Node *nextNode;

    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    current->next = NULL;
}

// Visit a new page
void visitPage(char url[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newNode->url, url);
    newNode->next = NULL;

    if (current == NULL) {
        // No pages yet
        newNode->prev = NULL;
        head = newNode;
        current = newNode;
    } else {
        // Remove forward history
        clearForwardHistory();

        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    printf("Visited: %s\n", current->url);
}

// Go back to previous page
void goBack() {
    if (current == NULL) {
        printf("No pages visited yet.\n");
    } else if (current->prev == NULL) {
        printf("No previous page. Can't go back.\n");
    } else {
        current = current->prev;
        printf("Current page (after Back): %s\n", current->url);
    }
}

// Go forward to next page
void goForward() {
    if (current == NULL) {
        printf("No pages visited yet.\n");
    } else if (current->next == NULL) {
        printf("No next page. Can't go forward.\n");
    } else {
        current = current->next;
        printf("Current page (after Forward): %s\n", current->url);
    }
}

// Display current page
void showCurrentPage() {
    if (current == NULL) {
        printf("No page is currently open.\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

// Free all nodes before exit
void freeAll() {
    Node *temp = head;
    Node *nextNode;

    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

int main() {
    int choice;
    char url[MAX_URL];

    while (1) {
        printf("\n--- Simple Web Browser ---\n");
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Show current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL (no spaces): ");
                scanf("%s", url);  // simple for exam; real code use fgets
                visitPage(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                showCurrentPage();
                break;

            case 5:
                freeAll();
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
