#include <stdio.h>
#include <stdlib.h>

// School-related static memory variables
static int num_students = 0; // Number of students in the school
static int num_teachers = 0; // Number of teachers in the school
static int max_students = 100; // Maximum number of students the school can accommodate
static int max_teachers = 20; // Maximum number of teachers the school can hire

// Structure to represent a student
struct Student {
    char name[50];
    int age;
};

// Structure to represent a teacher
struct Teacher {
    char name[50];
    char subject[50];
};

// Function to push a student into the stack
void pushStudent(struct Student* student, struct Student** student_stack, int* top) {
    if (*top < max_students) {
        student_stack[++(*top)] = student;
        num_students++;
    } else {
        printf("Student stack overflow!\n");
    }
}

// Function to pop a student from the stack
struct Student* popStudent(struct Student** student_stack, int* top) {
    if (*top >= 0) {
        num_students--;
        return student_stack[(*top)--];
    } else {
        printf("Student stack underflow!\n");
        return NULL;
    }
}

// Function to push a teacher into the stack
void pushTeacher(struct Teacher* teacher, struct Teacher** teacher_stack, int* top) {
    if (*top < max_teachers) {
        teacher_stack[++(*top)] = teacher;
        num_teachers++;
    } else {
        printf("Teacher stack overflow!\n");
    }
}

// Function to pop a teacher from the stack
struct Teacher* popTeacher(struct Teacher** teacher_stack, int* top) {
    if (*top >= 0) {
        num_teachers--;
        return teacher_stack[(*top)--];
    } else {
        printf("Teacher stack underflow!\n");
        return NULL;
    }
}

int main() {
    // School-related heaps with different names
    struct Student** student_heap = (struct Student**)malloc(max_students * sizeof(struct Student*));
    struct Teacher** teacher_heap = (struct Teacher**)malloc(max_teachers * sizeof(struct Teacher*));

    // School-related stacks with different names
    struct Student** student_stack = (struct Student**)malloc(max_students * sizeof(struct Student*));
    struct Teacher** teacher_stack = (struct Teacher**)malloc(max_teachers * sizeof(struct Teacher*));
    int student_top = -1;
    int teacher_top = -1;

    // Add students to the school
    struct Student* student1 = (struct Student*)malloc(sizeof(struct Student));
    sprintf(student1->name, "John");
    student1->age = 10;

    pushStudent(student1, student_stack, &student_top);

    struct Student* student2 = (struct Student*)malloc(sizeof(struct Student));
    sprintf(student2->name, "Emily");
    student2->age = 9;

    pushStudent(student2, student_stack, &student_top);

    // Add teachers to the school
    struct Teacher* teacher1 = (struct Teacher*)malloc(sizeof(struct Teacher));
    sprintf(teacher1->name, "Mr. Smith");
    sprintf(teacher1->subject, "Mathematics");

    pushTeacher(teacher1, teacher_stack, &teacher_top);

    struct Teacher* teacher2 = (struct Teacher*)malloc(sizeof(struct Teacher));
    sprintf(teacher2->name, "Ms. Johnson");
    sprintf(teacher2->subject, "Science");

    pushTeacher(teacher2, teacher_stack, &teacher_top);

    // Retrieve and print students and teachers from the stack
    printf("Students:\n");
    while (student_top >= 0) {
        struct Student* student = popStudent(student_stack, &student_top);
        printf("Name: %s, Age: %d\n", student->name, student->age);
        free(student); // Free the memory of the popped student
    }

    printf("Teachers:\n");
    while (teacher_top >= 0) {
        struct Teacher* teacher = popTeacher(teacher_stack, &teacher_top);
        printf("Name: %s, Subject: %s\n", teacher->name, teacher->subject);
        free(teacher); // Free the memory of the popped teacher
    }

    // Free the memory allocated for the heaps and stacks
    free(student_heap);
    free(teacher_heap);
    free(student_stack);
    free(teacher_stack);

    return 0;
}
