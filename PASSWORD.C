#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void pass() {
    char password[20], username[20];
    char ch, choice;
    int i,k;

    while (1) {
	clrscr(); // use clrscr() if you're on Turbo C++
	printf("Enter UID: ");
	scanf("%s", username);

	printf("Enter Password: ");
	i = 0;
	while (1) {
	    ch = getch();
	    if (ch == 13) // Enter key
		break;
	    if (ch == 8 && i > 0) { // Backspace
		i--;
		printf("\b \b");
	    } else if (i < sizeof(password) - 1) {
		password[i++] = ch;
		printf("*");
	    }
	}
	password[i] = '\0';

	if (strcmp(username, "hemant") == 0 && strcmp(password, "12345") == 0) {
	     goto k;
	} else {
	    printf("\n\nLogin Failed!\nTry again? (Y/N): ");
	    scanf(" %c", &choice);
	    if (choice == 'n' || choice == 'N') {
		exit(0);
	    }
	}
    }
   k:

}
