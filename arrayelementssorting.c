#include<stdio.h>
void main()
{
    FILE *fp;
    int n,temp,a[100];
    fp=fopen("array.txt","r");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    fclose(fp);
    fp=fopen("array1.txt","w");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
        fprintf(fp,"%d ",a[i]);
    fclose(fp);
}
