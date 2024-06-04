#include<stdio.h>
#include<string.h>
struct student
{
    char name[50];
    int roll;
    float marks[3];
}st[60];

int main()
{
    int i, n, rollno;
    float sum=0, avg;
    printf("Enter the number of students\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the name of %d student\n", i+1);
        scanf("%s",st[i].name);
        printf("Enter the roll no of %d student\n", i+1);
        scanf("%d",&st[i].roll);
        printf("Enter the marks of %d student\n", i+1);
        scanf("%f%f%f",&st[i].marks[0],&st[i].marks[1],&st[i].marks[2]);
    }
    for(i=0; i<n; i++)
    {
        sum = sum + st[i].marks[0] + st[i].marks[1] + st[i].marks[2];
    }
    avg = sum/n;
    printf("The average marks of %d students is : %f\n", n, avg);
    printf("Enter the roll no. of student detail required : ");
    scanf("%d",&rollno);
    for(i=0; i<n; i++)
    {
        if(st[i].roll == rollno)
        {
            printf("The name of student is : %s\n",st[i].name);
            printf("The 3 test scores are :\n %f %f %f\n",st[i].marks[0],st[i].marks[1],st[i].marks[2]);
            break;
        }
        else
        {
            continue;
        }
    }
    if(i == n)
        printf("Roll no. not found\n");

    return 0;
}