#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    FILE *fp;
    int r,a[100],temp;
    double start,stop;
    fp=fopen("array.txt","w+");
    for(int i=0;i<100;i++)
    {
        r=rand();
        r=r%100;
        fprintf(fp,"%d ",r);
    }
    rewind(fp);

    for(int i=0;i<100;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    fclose(fp);
    fp=NULL;
    fp=fopen("array1.txt","w");

    if(fp==NULL)
    {
        printf("file not created");
        exit(0);
    }

    start=clock();

    for(int i=0;i<99;i++)
    {
        for(int j=0;j<99-i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=a[j];
            }
        }
    }
    stop=clock();
    fprintf(fp,"%lf",(stop-start)/CLOCKS_PER_SEC);
    fclose(fp);
}
