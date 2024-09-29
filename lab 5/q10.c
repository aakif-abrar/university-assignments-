#include <stdio.h>

int main() {
    float attendance, assignment, exam, finalGrade;

    printf("Enter attendance percentage (out of 100): ");
    scanf("%f", &attendance);

    printf("Enter assignment score (out of 100): ");
    scanf("%f", &assignment);

    printf("Enter exam score (out of 100): ");
    scanf("%f", &exam);

    if (attendance >= 75) {
        if (assignment >= 50) {
            if (exam >= 50) {
                finalGrade = (attendance * 0.2) + (assignment * 0.3) + (exam * 0.5);
                printf("Final Grade: %.2f\n", finalGrade);
            } else {
                printf("Failed: Exam score below 50.\n");
            }
        } else {
            printf("Failed: Assignment score below 50.\n");
        }
    } else {
        printf("Failed: Attendance below 75%%.\n");
    }

    return 0;
}
