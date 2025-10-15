#include<stdio.h>

struct student_info {
    char USN[10], name[50];
    int ia1, ia2, ia3, cta;
};
int calculateBestTwoIA(int ia1, int ia2, int ia3) {
    
    if (ia1 <= ia2 && ia1 <= ia3) {
        return ia2 + ia3; 
    } else if (ia2 <= ia1 && ia2 <= ia3) {
        return ia1 + ia3; 
    } else {
        return ia1 + ia2; 
    }
}
void displayStudentDetails(struct student_info s[], int n) {
    printf("USN\tName\tBest IA\tCTA\tTotal\n");
    for (int i = 0; i < n; i++) {
        int bestIA = calculateBestTwoIA(s[i].ia1, s[i].ia2, s[i].ia3);
        int total = bestIA + s[i].cta;
        printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", s[i].USN, s[i].name, bestIA, s[i].cta, total);
    }
}

void main() {
    printf("Enter the number of students: ");
    int n;
    scanf("%d", &n);
    struct student_info s1[n];

    printf("Enter USN: \n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s", s1[i].USN);
    }
    printf("Enter Name: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter name of Student %d: ", i + 1);
        scanf("%s", s1[i].name);
    }
    printf("Enter IA1, IA2, IA3, CTA: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter marks for Student %d: ", i + 1);
        scanf("%d %d %d %d", &s1[i].ia1, &s1[i].ia2, &s1[i].ia3, &s1[i].cta);
    }

    displayStudentDetails(s1, n);
}