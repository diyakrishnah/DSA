#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev, *next;
} Node;

Node *current = NULL;

// Visit new page
void visitPage(char *url) {
    Node newNode = (Node)malloc(sizeof(Node));  // library function: malloc()
    strcpy(newNode->url, url);                   // library function: strcpy()
    newNode->next = NULL;

    if(current != NULL) {
        current->next = NULL; // delete forward history
        newNode->prev = current;
        current->next = newNode;
    } else {
        newNode->prev = NULL;
    }
    current = newNode;
    printf("Visited: %s\n", current->url);
}

// Go Back
void goBack() {
    if(current == NULL || current->prev == NULL) {
        printf("No Previous Pages!\n");
    } else {
        current = current->prev;
        printf("Went Back to: %s\n", current->url);
    }
}

// Go Forward
void goForward() {
    if(current == NULL || current->next == NULL) {
        printf("No Forward Pages!\n");
    } else {
        current = current->next;
        printf("Went Forward to: %s\n", current->url);
    }
}

// Show current page
void showCurrent() {
    if(current == NULL)
        printf("No page opened!\n");
    else
        printf("Current Page: %s\n", current->url);
}

int main() {
    int choice;
    char url[100];

    while(1){
        printf("\n=== Browser Navigation ===\n");
        printf("1. Visit Page\n2. Go Back\n3. Go Forward\n4. Show Current Page\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice); getchar();

        switch(choice){
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0;  // remove newline
                visitPage(url);
                break;

            case 2: goBack(); break;
            case 3: goForward(); break;
            case 4: showCurrent(); break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
