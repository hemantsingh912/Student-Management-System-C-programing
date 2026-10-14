#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include"password.c"
void mai()
{
      int i;
      while(1){
printf("[1]  Admin\n");
printf("[2]  Custmor\n");
printf("[3]  Exit\n");

printf("Enter a choice:- ");
scanf("%d",&i);

switch(i)
{
	case 1:
	pass();
	break;
	case 2:
	printf("Custmor\n");
	break;
	case 3:
	exit(0);
	break;

}



}


getch();
}