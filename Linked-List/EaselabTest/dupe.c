#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

// Insert node at end
struct node *insertAtEnd(struct node *first) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return first;
    }

    printf("Enter data to insert: ");
    scanf("%d", &newNode->info);
    newNode->link = NULL;

    if (first == NULL) {
        return newNode;
    }

    struct node *save = first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;
    return first;
}

// Display the list
void display(struct node *first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *save = first;
    printf("Linked List: ");
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// Remove duplicate nodes
struct node *removeDuplicates(struct node *first) {
    struct node *curr = first;

    while (curr != NULL && curr->link != NULL) {
        struct node *prev = curr;
        struct node *save = curr->link;

        while (save != NULL) {
            if (save->info == curr->info) {
                prev->link = save->link;
                free(save);
                save = prev->link;
            } else {
                prev = save;
                save = save->link;
            }
        }
        curr = curr->link;
    }

    return first;
}

// Main function
int main() {
    struct node *first = NULL;
    int choice;

    do {
        printf("\nMain Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Remove Duplicates\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                first = insertAtEnd(first);
                break;

            case 2:
                display(first);
                break;

            case 3:
                first = removeDuplicates(first);
                printf("Duplicates removed successfully.\n");
                break;

            case 0:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
