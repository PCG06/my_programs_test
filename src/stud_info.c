/* C program to enter student information like:
- name
- register number
- marks in 3 subjects 
into an array of structures and display
- total
- average
- grade 
- details of the student 
in a neat format */

#include<stdio.h>

void main()
{
    struct student
    {
        int regno;
        char name[10];
        int m1, m2, m3, total;
        float avg;
        char grade;
    } s[100];

    int i, n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter register number: ");
        scanf("%d", &s[i].regno);
        printf("Enter the name: ");
        scanf("%s", s[i].name);
        printf("Enter marks in 3 subjects: ");
        scanf("%d%d%d", &s[i].m1, &s[i].m2, &s[i].m3);
        s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
        s[i].avg = s[i].total / 3.0;
        if (s[i].m1 < 35 || s[i].m2 < 35 || s[i].m3 < 35)
            s[i].grade = 'F';
        else if (s[i].avg >= 85)
            s[i].grade = 'A';
        else if (s[i].avg >= 60)
            s[i].grade = 'B';
        else if (s[i].avg >= 50)
            s[i].grade = 'C';
        else
            s[i].grade = 'D';
    }

    printf("\nStudent details:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nREG NO\tNAME\tMARKS1\tMARKS2\tMARKS3\tTOTAL\tAVERAGE\tGRADE");
        printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%c\n", s[i].regno, s[i].name, s[i].m1, s[i].m2, s[i].m3, s[i].total, s[i].avg, s[i].grade);
    }
}