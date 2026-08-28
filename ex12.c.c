/* EX.NO: 12  MINI PROJECT: STUDENT RECORD SYSTEM
   AIM: To write a C program to implement a Student Record System using data structures. */

#include <stdio.h>
#include <string.h>
#define SIZE 50

struct Student {
    char name[30];
    int rollno;
    char course[30];
};

struct Student students[SIZE];
int count = 0;

int findByRoll(int rollno) {
    for (int i = 0; i < count; i++)
        if (students[i].rollno == rollno)
            return i;
    return -1;
}

void addStudent() {
    if (count >= SIZE) {
        printf("Error: Student list is full.\n");
        return;
    }
    int rollno;
    printf("Enter roll number: ");
    scanf("%d", &rollno);

    if (findByRoll(rollno) != -1) {
        printf("Error: Roll number already exists.\n");
        return;
    }

    students[count].rollno = rollno;
    printf("Enter name: ");
    scanf("%s", students[count].name);
    printf("Enter course: ");
    scanf("%s", students[count].course);
    count++;
    printf("Student added successfully.\n");
}

void findByRollMenu() {
    int rollno, idx;
    printf("Enter roll number to find: ");
    scanf("%d", &rollno);
    idx = findByRoll(rollno);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }
    printf("Roll No: %d, Name: %s, Course: %s\n",
           students[idx].rollno, students[idx].name, students[idx].course);
}

void findByName() {
    char name[30];
    int found = 0;
    printf("Enter first name to find: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Roll No: %d, Name: %s, Course: %s\n",
                   students[i].rollno, students[i].name, students[i].course);
            found = 1;
        }
    }
    if (!found) printf("No student found with that name.\n");
}

void findByCourse() {
    char course[30];
    int found = 0;
    printf("Enter course name to find: ");
    scanf("%s", course);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].course, course) == 0) {
            printf("Roll No: %d, Name: %s\n", students[i].rollno, students[i].name);
            found = 1;
        }
    }
    if (!found) printf("No student found registered in that course.\n");
}

void countStudents() {
    printf("Total number of students: %d\n", count);
}

void deleteStudent() {
    int rollno, idx;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollno);
    idx = findByRoll(rollno);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }
    for (int i = idx; i < count - 1; i++)
        students[i] = students[i + 1];
    count--;
    printf("Student deleted successfully.\n");
}

void updateStudent() {
    int rollno, idx, choice;
    printf("Enter roll number to update: ");
    scanf("%d", &rollno);
    idx = findByRoll(rollno);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }
    printf("What do you want to update?\n1. Name\n2. Course\n3. Both\n");
    scanf("%d", &choice);
    if (choice == 1 || choice == 3) {
        printf("Enter new name: ");
        scanf("%s", students[idx].name);
    }
    if (choice == 2 || choice == 3) {
        printf("Enter new course: ");
        scanf("%s", students[idx].course);
    }
    printf("Student record updated successfully.\n");
}

void displayAll() {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("Roll No\tName\t\tCourse\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%s\t\t%s\n", students[i].rollno, students[i].name, students[i].course);
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Record System Menu:\n");
        printf("1. Add Student\n2. Find by Roll No\n3. Find by Name\n");
        printf("4. Find by Course\n5. Count Students\n6. Delete Student\n");
        printf("7. Update Student\n8. Display All\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: findByRollMenu(); break;
            case 3: findByName(); break;
            case 4: findByCourse(); break;
            case 5: countStudents(); break;
            case 6: deleteStudent(); break;
            case 7: updateStudent(); break;
            case 8: displayAll(); break;
            case 9: return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
