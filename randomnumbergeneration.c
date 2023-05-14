

//.GENERATION OF RANDOM NUMBER.

#include <stdio.h>


#include <stdlib.h>


void sort(int a[],int n,FILE *fp)  //SORTING OF ARRAY

{
    for(int i=0;i<n-1;i++)

    {
        for(int j=0;j< n-i-1;j++)

        {
            if(a[j]>a[j+1])


            {
                int temp=0;

                temp=a[j];

                a[j]=a[j+1];

                a[j+1]=temp;

            }
        }
    }

    for(int i=0;i<n;i++)


    {
        fprintf(fp,"%d ",a[i]);

    }
}

int main()

{
    int n;

    FILE *fp;

    fp=fopen("test.txt","w");  //OPEN THE FILE IN WRITE MODE

    if(fp==NULL)
    {
        printf("\nFile not created.");

        exit(0);
    }
    printf("\nEnter number of elements:  ");

    scanf("%d",&n);

    int a[n];

    for(int i=0;i<n;i++)

    {
        a[i]=rand()%100;   //GENERATION OF RANDOM NUMBER.

    }

    for(int i=0;i<n;i++)

    {
        fprintf(fp,"%d ",a[i]);     //PRINTING THE DATA IN FILE.

    }
    fclose(fp);

    fp=fopen("test1.txt","w");

    if(fp==NULL)
    {
        printf("\nFile not opened.");

        exit(0);
    }
    sort(a,n,fp);

    fclose(fp);

    return 0;
}

