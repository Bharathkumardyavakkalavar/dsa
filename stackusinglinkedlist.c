#include<stdio.h>
#include<stdlib.h>
struct NODE{
int data;
struct NODE *next};
typedef struct NODE *node;
FILE *fp1,*fp2,*fp3,*fp4,*fp5;
node head=NULL,cur,temp,prev,top,newn;
void push(FILE *fp1,FILE *fp2,FILE *fp3)
{
    int ele;
    fscanf(fp1,"%d",&ele);
    fp3=fopen("push.txt","a");
    newn=(node)malloc(sizeof(struct NODE));
    newn->data=ele;
    newn->next=NULL;
    //printf("%d",newn->data);
    if(head==NULL)
    {
        head=newn;
        top=newn;
        //printf("%d",top->data);
    }
    else{
        top->next=newn;
        top=newn;
    }
    fprintf(fp3,"%d\t",top->data);
    fp2=fopen("stack.txt","w+");
    temp=head;
    while(temp!=NULL)
    {
        //printf("%d  ",top->data);
        fprintf(fp2,"%d\t",temp->data);
        temp=temp->next;
    }
    fclose(fp2);
    fclose(fp3);
}

void pop(FILE *fp2,FILE *fp4)
{
    int ele;
    fp4=fopen("pop.txt","a");
    if(head==NULL)
    {
        printf("File underflow\n");
    }
    else
    {
        ele=top->data;
        temp=head;
        while(temp->next!=top)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        top=temp;
        fprintf(fp4,"%d ",ele);
    }
    while(temp!=NULL)
    {
        //printf("%d  ",top->data);
        fprintf(fp2,"%d\t",temp->data);
        temp=temp->next;
    }
    fclose(fp2);
    fclose(fp4);
}

main()
{

    int r,flag=1,ch;
    fp1=fopen("random.txt","w+");



    fp5=fopen("operation.txt","w+");
    for(int i=0;i<1000;i++)
    {
        fprintf(fp1,"%d\t",rand()%1000);
    }
    fclose(fp1);
    fp1=fopen("random.txt","r");
    while(flag)
    {
        printf("1.Push,2.Pop,3.Exit\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(fp1,fp2,fp3);
            fprintf(fp5,"Push\n");
            break;
            case 2: pop(fp2,fp4);
            fprintf(fp5,"Pop\n");
            break;
            case 3: flag=0;
            break;
            default: break;
        }
    }
    fclose(fp1);
    fclose(fp2);


    fclose(fp5);
}







