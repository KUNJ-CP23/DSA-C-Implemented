#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

// Insert node at end
struct node* insertAtEnd(struct node* first) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return first;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->info);
    newNode->link = NULL;

    if (first == NULL)
        return newNode;

    struct node* save = first;
    while (save->link != NULL)
        save = save->link;

    save->link = newNode;
    return first;
}

// Display the list
void display(struct node* first) {
    struct node* save = first;
    printf("List: ");
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// Reverse the linked list
struct node* reverseList(struct node* first) {
    struct node* prev = NULL;
    struct node* current = first;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    return prev; // new head
}

// Main function
int main() {
    struct node* first = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Reverse List\n");
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
                first = reverseList(first);
                printf("List reversed.\n");
                display(first);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
