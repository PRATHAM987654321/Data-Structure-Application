//SORT AN ARRAY AND PUT IN OTHER FILE.

# include <stdio.h>

#include <stdlib.h>

int main()

{

   FILE *fp,*fp1;  //DECLEARING FILE POINTER

   int temp;

   fp=fopen("file1.txt","w");  //OPEN THE FILE IN READ MODE

   int a[5],b[5];      //DECLEARING THE ARRAY

   int i=0;

   printf("enter the array element");

   for(i=0;i<5;i++)

   {

    scanf("%d",&a[i]);    //READING THE DATA IN ARRAYS.

   }


  for(int i=0;i<5;i++)

   {

   fprintf(fp,"%d ",a[i]);   //PRINTING THE ARRAY IN FILE

   }

   fclose(fp);

  fp=fopen("file1.txt","r");

  for(i=0;i<5;i++)

 {

     fscanf(fp,"%d",&b[i]);   //READING DATA FROM THE FILE AND STORING IN ANOTHER ARRAY

 }

  fp1=fopen("file2.txt","w");


  for(i=0;i<5;i++)   //SORTING OF ARRAY

  {

      for(int j=i+1;j<5;j++)

      {

          if(b[j]<b[i])

          temp=b[j];

          b[j]=b[i];

          b[i]=temp;

      }

  }


   for(int i=0;i<5;i++)

   {

   fprintf(fp1,"%d ",b[i]);


   }

   fclose(fp);


}
