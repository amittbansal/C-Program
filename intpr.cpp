#include<iostream.h>
#include<conio.h>
#include<string.h>

char *infix,*prefix,*stack,*temp,c;
int length,counti,countp,top=-1,tmp;

void pre(void )
{
   int i;
   for(i=0;i<length;i++)
     if((infix[i]=='(')||(infix[i]==')')||(infix[i]==' '))
 tmp++;
   tmp=length-tmp;
   countp=tmp;
   cout<<"\nreverse exp is : ";
   for(i=0;i<length;i++)
      cout<<infix[i];
   stack=new char[length-countp];
   prefix=new char[countp];

   for(counti=0;counti<length;counti++)
   {
      c=infix[counti];
      if(((c>47)&&(c<58))||((c>64)&&(c<91))||((c>96)&&(c<123)))
  prefix[--countp]=c;
     
      if(c==')')
  stack[++top]=c;

      if(c=='^')
  stack[++top]=c;

      if((c=='+')||(c=='-'))
      {
  while((stack[top]=='^')||(stack[top]=='*')||(stack[top]=='/'))
     prefix[--countp]=stack[top--];

  stack[++top]=c;
      }

      if((c=='*')||(c=='/'))
      {
  while(stack[top]=='^')
     prefix[--countp]=stack[top--];

  stack[++top]=c;
      }

      if(c=='(')
      {
  while(stack[top]!=')')
  {
     prefix[--countp]=stack[top--];
  }
  top--;
      }

   }

   while(top>-1)
     prefix[--countp]=stack[top--];

   cout<<"\n\nPrefix exp is : \n";
   for(i=0;i<tmp;i++)
   cout<<prefix[i];

}

void main()
{
   clrscr();
   int i=0;
   cout<<"\nEnter the infix expression : \n";
   cin>>temp;
   length=strlen(temp);

   //cout<<"\nlength of infix : "<<length;
   infix=new char[length];
   for(i=0;i<length;i++)
      infix[i]=temp[length-1-i];
   cout<<endl;
   delete temp;
   pre();
   getch();

}
