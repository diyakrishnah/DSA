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

Node *head = NULL;
Node *current = NULL;

// Delete all nodes after "current" (clear forward history)
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
        newNode->prev = NULL;
        head = newNode;
        current = newNode;
    } else {
        clearForwardHistory();
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    printf("Visited: %s\n", current->url);
}

// Go back one page
void goBack() {
    if (current == NULL) {
        printf("No pages visited yet!\n");
    } else if (current->prev == NULL) {
        printf("No Previous pages!\n");
    } else {
        current = current->prev;
        printf("Went Back : %s\n", current->url);
    }
}

// Go forward one page
void goForward() {
    if (current == NULL) {
        printf("No pages visited yet!\n");
    } else if (current->next == NULL) {
        printf("No Forward pages!\n");
    } else {
        current = current->next;
        printf("Went Forward : %s\n", current->url);
    }
}

// Show current page
void showCurrentPage() {
    if (current == NULL) {
        printf("No pages visited yet!\n");
    } else {
        printf("Current pages : %s\n", current->url);
    }
}

// Free all nodes
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
        printf("\n\t\tBrowser Navigation\n");
        printf("1. Visit page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Show current page\n");
        printf("5. Exit\n");
        printf("Enter the choice :");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the URL:");
                scanf("%s", url);    // for exam: no spaces
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
                printf("Exiting the program!\n");
                freeAll();
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
