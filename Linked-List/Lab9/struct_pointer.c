// 55. WAP to define a C structure named Student (roll_no, name, branch and 
//batch_no) and also to access the structure members using Pointer. 

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[100];
    char branch[50];
    int batch_no;
    float marks;
};

int main() {
    int n;
    
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Enter roll no: ");
        scanf("%d", &students[i].roll_no);

        printf("Enter name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Enter branch: ");
        scanf(" %[^\n]s", students[i].branch);

        printf("Enter batch no: ");
        scanf("%d", &students[i].batch_no);

        printf("Enter marks (float): ");
        scanf("%f", &students[i].marks);
    }

    printf("\n----- All Student Details -----\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Branch: %s\n", students[i].branch);
        printf("Batch No: %d\n", students[i].batch_no);
        printf("Marks: %.2f\n", students[i].marks); 
    }

    free(students);
    return 0;
}






 
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Student {
    int roll_no;
    char name[100];
    float marks;
};

int main() {
    // Declare a pointer to a structure
    struct Student *ptr;

    // Allocate memory for one Student structure
    ptr = (struct Student *)malloc(sizeof(struct Student));

    // Check if malloc was successful
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Take input using pointer and -> operator
    printf("Enter roll number: ");
    scanf("%d", &ptr->roll_no);

    printf("Enter name: ");
    scanf(" %[^\n]s", ptr->name);  // Read string with spaces

    printf("Enter marks: ");
    scanf("%f", &ptr->marks);

    // Display the structure data using pointer
    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);

    // Free the dynamically allocated memory
    free(ptr);

    return 0;
}


