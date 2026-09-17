#include<stdio.h>
#include<conio.h>

void kar1(char *a, char *b, char *c)
{
*a = 'c'; *b='a'; *c ='b';
printf("%c %c %c\n", *a, *b, *c);
}

int main()
{
char a = 'c', b = 'b', c = 'a';
printf("%c %c %c\n", a, b, c);
kar1(&a,&b,&c);
printf("%c %c %c\n", a, b, c);
kar1(&c,&b,&a);
printf("%c %c %c\n", a, b, c);
kar1(&b,&a,&c);
printf("%c %c %c\n", a, b, c);
getch();
return 0;
}

