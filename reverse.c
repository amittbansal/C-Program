#include<stdio.h>
#include<conio.h>
void main
{
int a,i,b,c=0;
clrscr();
printf("enter the no's ");
scanf("%d",&a);
for(i=0;i<100;i++)
{
b=(a%10)*10;
a=a/10;
c=(c*10)+b;
if(a==0)
{
printf("%d",&c);
}
}
getch();
}

