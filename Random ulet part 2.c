#include<conio.h>
#include<stdio.h>
void main()
{ int a[10]={1,2,3,4,5,6,7,8,9,10};
 int c, *b;
 b=a;
 printf("The elements of even index are:\n");
 for(c=0;c<=9;c++)
 { if((c % 2)==0)
    printf("%d\t",*(a+c));}
  printf("\nThe elements of odd index are:\n");
  for(c=0;c<=9;c++)
     { if((c % 2)==1)
	printf("%d\t",*(b+c)); }
getch();
}
