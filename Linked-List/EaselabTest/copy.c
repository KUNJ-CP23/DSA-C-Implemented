#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

// Insert at end
struct node* insertAtEnd(struct node* first) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
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

// Display
void display(struct node* first) {
    struct node* save = first;
    printf("List: ");
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// Copy list
struct node* copyList(struct node* first) {
    if (first == NULL)
        return NULL;

    struct node* copyHead = NULL;
    struct node* copyTail = NULL;

    struct node* save = first;
    while (save != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = save->info;
        newNode->link = NULL;

        if (copyHead == NULL) {
            copyHead = newNode;
            copyTail = newNode;
        } else {
            copyTail->link = newNode;
            copyTail = newNode;
        }

        save = save->link;
    }

    return copyHead;
}
