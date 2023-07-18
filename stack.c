#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct
{
    int top;
    int ele[max];

}stack;
int main()
{
    stack s;
    FILE * fp1,* fp2, * fp3;
    int p,t,q,i,num;
    fp1=fopen("stack1.txt","w");
    printf("Enter the value of a  and  b  \n");
    scanf("%d %d",&p,&q);
    printf("Enter the value of t  ");
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
    num = (rand() % (p - q +1))+ p;
    printf("%d\n ",num);
    fprintf(fp1,"%d ",num);
    }
    fclose(fp1);
    fp1=fopen("stack1.txt","r");
    fp2=fopen("push.txt","w");
    fp3 = fopen("pop.txt","w");
    initstack(&s);
    int e,ch;
    while(1)
    {
        printf("\n1.push\n 2.pop\n 3.peek\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
              case 1: if(isFull(&s))
                      printf("stack is overflow\n");
                      else
                      {
                        printf("enter the element:");
                        fscanf(fp1,"%d",&e);
                       printf("%d",e);
                        fprintf(fp2,"  %d",e);
                        push(&s,e);
                      }
                      break;
              case 2: if(isEmpty(&s))
                      printf("stack is underflow\n");
                      else
                      {
                         e=pop(&s);
                         fprintf(fp3,"  %d",e);
                      }
                      break;
              case 3:  display(&s);
                      break;
              case 4: exit(0);
        }
    }
}
void initstack(stack *s)
{
   s->top=-1;
}
int isFull(stack *s)
{
       return (s->top==max-1);
}
void push(stack *s, int e)
{
    s->top++;
    s->ele[s->top]=e;
}
int isEmpty(stack *s)
{
    return  (s->top==-1);
}
int pop(stack *s)
{
     int e=s->ele[s->top];
      s->top--;
     return e;
}
int peek(stack *s)
{
     int e=s->ele[s->top];
     return e;
}
void display(stack *s)
{
    FILE * fp4 = fopen("stack1.txt","w");
    if((s->top )==-1)
    {
         printf("Stack is empty. \n");
    }
    else
    {
            printf("Stack elements are\n");
            for(int i=s->top;i>=0;i--)
            {
                printf("%d\n",s->ele[s->top]);
                fprintf(fp4,"%d",s->ele[s->top]);
            }
    }
}
