#include<stdio.h>
#include<string.h>
struct student
{
	char rollno[15], name[32];
	int m[4];
};
int main()
{
	float sum = 0, avg;
	char grade;
	struct student s[3];
	for(int i=0;i<3;i++)
	{
		scanf("%s",s[i].rollno);
		scanf("%s",s[i].name);
		for(int j=0;j<4;j++)
		{
			scanf("%d",&s[i].m[j]);
			sum = sum + s[i].m[j]; 
		}
	avg = sum / 4.0;
	if (avg >= 75.0)
		grade = 'A';
	else if (avg < 75 && avg >= 50)
		grade = 'B';
	else
		grade = 'C';
	printf("%s\t%s\t%c\t",s[i].rollno, s[i].name, grade);
	}
}
		