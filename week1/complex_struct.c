#include<stdio.h>
struct complex
{
	int real, imag;
};
void addition(struct complex c1, struct complex c2)
{
	struct complex c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;
	printf("%d+i%d\n",c3.real, c3.imag);
}
void subtraction(struct complex c1, struct complex c2)
{
	struct complex c3;
	c3.real = c1.real - c2.real;
	c3.imag = c1.imag - c2.imag;
	if (c2.imag > c1.imag)
		{
			c3.imag = c2.imag - c1.imag;
			printf("%d-i%d\n", c3.real, c3.imag);
		}
	else
		printf("%d+i%d\n", c3.real, c3.imag);
}
void multiplication(struct complex c1, struct complex c2)
{
	struct complex c3;
	c3.real = c1.real*c2.real - c1.imag*c2.imag;
	c3.imag = c1.imag*c2.real + c2.imag*c1.real;
	printf("%d+i%d\n",c3.real,c3.imag);
}
int main()
{
	struct complex c1,c2;
	scanf("%d%d%d%d",&c1.real,&c1.imag,&c2.real,&c2.imag);
	addition(c1,c2);
	subtraction(c1,c2);
	multiplication(c1,c2);
}