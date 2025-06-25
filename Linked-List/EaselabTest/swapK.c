#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

// Insert at end
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

// Count number of nodes
int count(struct node* first) {
    int c = 0;
    struct node* save = first;
    while (save != NULL) {
        c++;
        save = save->link;
    }
    return c;
}

// Swap Kth node from beginning with Kth from end
struct node* swapKthNode(struct node* first, int k) {
    int n = count(first);
    if (k > n || k <= 0) {
        printf("Invalid K value.\n");
        return first;
    }

    if (2 * k - 1 == n) {
        // Same node from start and end
        return first;
    }

    // Find Kth node from beginning
    struct node* x_prev = NULL;
    struct node* x = first;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->link;
    }

    // Find Kth node from end
    struct node* y_prev = NULL;
    struct node* y = first;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->link;
    }

    // Swap previous node links
    if (x_prev != NULL)
        x_prev->link = y;
    if (y_prev != NULL)
        y_prev->link = x;

    // Swap next pointers
    struct node* temp = x->link;
    x->link = y->link;
    y->link = temp;

    // Fix head if needed
    if (k == 1)
        return y;
    if (k == n)
        return x;

    return first;
}

// Main function
int main() {
    struct node* first = NULL;
    int choice, k;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Swap Kth Node from Start and End\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                first = insertAtEnd(first);
                break;

            case 2:
                display(first);
                break;

            case 3:
                printf("Enter K: ");
                scanf("%d", &k);
                first = swapKthNode(first, k);
                printf("After swap:\n");
                display(first);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
