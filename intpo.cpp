#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{
       clrscr();
       cout<<"\n";
       cout<<"Infix to Postfix Conversion";
       cout<<"\n";
       char infix[30],postfix[30],stack[30],op;
       int i=0,pc=0,sc=0,flag=0;
       cout<<"\nEnter the expression in infix:\n\n";
       gets(infix);
      
       for(i=0;infix[i]!='\0';i++)
       {
              if(infix[i]>=97 && infix[i]<=122)
       {
      
              postfix[pc]=infix[i];
              pc++;
       }
      
              else

              {

                     op=infix[i];
      
                     if(sc==0)

                     {

                           stack[sc]=op;
      
                           sc++;
                     }

                     else

                     {
                           switch(op)
                     {
      
                           case '+':  flag=0;
         
                                  while(flag==0 && sc!=0)
         
                                  {
                                         if(stack[sc-1]=='+'|| stack[sc-1]=='*' || stack[sc-1]=='/')
                                  {
                                 
                                         postfix[pc]=stack[sc-1];
                 pc++;
                 sc--;
                 stack[sc]='+';
               }
          else
              {
                stack[sc]='+';
                flag=1;
              }
          }
          sc++;
          break;
case '-':
          flag=0;
          while(flag==0 && sc!=0)
          {
              if(stack[sc-1]=='+'||stack[sc-1]=='-'||stack[sc-1]=='*'||stack[sc-1]=='/')
              {
                 postfix[pc]=stack[sc-1];
                 pc++;
                 sc--;
                 stack[sc]='-';
               }
          else
              {
                stack[sc]='-';
                flag=1;
               }
          }
          sc++;
          break;
case '*': flag=0;
          while(flag==0 && sc!=0)
          {
              if(stack[sc-1]=='/'||stack[sc-1]=='*')
              {
                 postfix[pc]=stack[sc-1];
                 pc++;
                 sc--;
                 stack[sc]='*';
               }
          else
              {
                stack[sc]='*';
                flag=1;
               }
          }
          sc++;
          break;
case '/':
          flag=0;
          while(flag==0 && sc!=0)
          {
         if(stack[sc-1]=='/')
         {
                 postfix[pc]=stack[sc-1];
                 pc++;
                 sc--;
                 stack[sc]='/';
               }
          else
              {
                stack[sc]='/';
                  flag=1;
               }
               sc++;
          break;
          }
       }
     }
   }
 }
for(i=sc-1;i>=0;i--)
{
      postfix[pc]=stack[i];
      pc++;
}
postfix[pc]='\0';
cout<<"postfix expression:\t";
for(i=0;postfix[i]!='\0';i++)
{
cout<<postfix[i];
}
getch();
}