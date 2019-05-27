#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include "stack.h"
#include <cstring>
#define NUMBER_OF_DISKS 3

void menu();
void rules();
void play();
void display(node*, node*, node*);
void center_print(const char *, int );

void main()
{
	menu();

	_getch();
}

void menu()
{
	int choice;

	printf("===============================================================\n");
	printf("||                                                           ||\n");
	printf("||                         MENU                              ||\n");
	printf("||                                                           ||\n");
	printf("||                   1 . New Game                            ||\n");
	printf("||                   2 . Help                                ||\n");
	printf("||                   3 . Exit                                ||\n");
	printf("||                                                           ||\n");
	printf("===============================================================\n");
	printf("\n");
	printf("Choose an option: ");
	scanf("%d", &choice);
	switch(choice)
	{
	case 1:
		system("cls");
		play();

		break;
	case 2:
		system("cls");
		rules();
		system("cls");
		menu();

		break;
	case 3:
		system("cls");
		exit(0);
	default: printf("There is no such option, please try again..");
	}
	
}

void rules()
{
	printf("Make the same formation of the stack you see\n");
	printf("on the 3rd peg by any number of steps.\n");
	printf("Bigger Disks cannot be put above smaller ones\n");
	printf("The columns are numbered 1,2,3 from left.\n");
	printf("Try to accomplish the task in least number of steps.\n");
	printf("\n");
	printf("   *     |     |           |     |     *\n");
	printf("  ***    |     |    =>     |     |    ***\n");
	printf(" *****   |     |           |     |   *****\n");
	printf("==================      ===================\n");
	printf("\n");
	printf("\n");
	system("pause");
}


void play()
{
	int from, to, moveCounter=-1;
	node* source = NULL;
	node* temporary = NULL;
	node* destination = NULL;
	node* result = NULL;

	source = push(source, 3);
	source = push(source, 2);
	source = push(source, 1);

	result = push(result, 3);
	result = push(result, 2);
	result = push(result, 1);

	int error = 0, error2 = 0;

	while(!compare(result, destination))
	{
		moveCounter++;
		system("cls");
		printf("Move counter: %d\n\n", moveCounter);
		display(source, temporary, destination);
		if(error==1)
			printf("This move is not allowed, please try again.\n\n");
		else if (error2 == 1)
			printf("Wrong input, try again.\n\n");
		error = 0;
		error2 = 0;
		printf("Move from: ");
		scanf("%d", &from);
		printf("\nMove to: ");
		scanf("%d", &to);

		switch (from)
		{
		case 1:
			if (isEmpty(source))
			{
				error = 1;
				break;
			}
			if (to == 2)
			{
				if (isEmpty(temporary) || source->value < temporary->value)
				{
					temporary = push(temporary, source->value);
					source = pop(source);
					break;
				}
				error = 1;
				break;
			}
			else if (to == 3)
			{
				if (isEmpty(destination) || source->value < destination->value)
				{
					destination = push(destination, source->value);
					source = pop(source);
					break;
				}
				error = 1;
				break;
			}
			else
			{
				error2 = 1;
				break;
			}
		case 2:
			if (isEmpty(temporary))
			{
				error = 1;
				break;
			}
			if (to == 1)
			{
				if (isEmpty(source) || temporary->value < source->value)
				{
					source = push(source, temporary->value);
					temporary = pop(temporary);
					break;
				}
				error = 1;
				break;
			}
			else if (to == 3)
			{
				if (isEmpty(destination) || temporary->value < destination->value)
				{
					destination = push(destination, temporary->value);
					temporary = pop(temporary);
					break;
				}
				error = 1;
				break;
			}
			else
			{
				error2 = 1;
				break;
			}
		case 3:
			if (isEmpty(destination))
			{
				error = 1;
				break;
			}
			if (to == 2)
			{
				if (isEmpty(temporary) || destination->value < temporary->value)
				{
					temporary = push(temporary, destination->value);
					destination = pop(destination);
					break;
				}
				error = 1;
				break;
			}
			else if (to == 1)
			{
				if (isEmpty(source) || destination->value < source->value)
				{
					source = push(source, destination->value);
					destination = pop(destination);
					break;
				}
				error = 1;
				break;
			}
			else
			{
				error2 = 1;
				break;
			}
		default:
			error2 = 1;
			break;
		}
	}

	moveCounter++;
	system("cls\n\n");
	display(source, temporary, destination);
	printf("\nCongratulations, you won!\n\n");
	printf("You made %d moves.\n\n", moveCounter);
	system("pause");
	menu();
}

void display(node* source, node* temporary, node* destination)
{
	const char* stack[3][3] = { {" "," "," "},{" "," "," "},{" "," "," "} };
	node* peg1 = source;
	node* peg2 = temporary;
	node* peg3 = destination;

	const int count1 = count(source);
	const int count2 = count(temporary);
	const int count3 = count(destination);
	int r = 0, c = 0;

	//draw peg1
	if (count1 != 0)
	{
		for (int i = 0; i < 3 - count1; i++)
		{
			stack[r][c] = " ";
			r++;
		}
		for (int i = 0; i < count1; i++)
		{
			if (peg1->value == 1)
			{
				stack[r][c] = "*";
				r++;
			}
			else if (peg1->value == 2)
			{
				stack[r][c] = "***";
				r++;
			}
			else if (peg1->value == 3)
			{
				stack[r][c] = "*****";
				r++;
			}
			peg1 = peg1->pnext;
		}
	}

	if (count2 != 0)
	{
		r = 0;
		c = 1;
		//draw peg2
		for (int i = 0; i < 3 - count2; i++)
		{
			stack[r][c] = " ";
			r++;
		}
		for (int i = 0; i < count2; i++)
		{
			if (peg2->value == 1)
			{
				stack[r][c] = "*";
				r++;
			}
			else if (peg2->value == 2)
			{
				stack[r][c] = "***";
				r++;
			}
			else if (peg2->value == 3)
			{
				stack[r][c] = "*****";
				r++;
			}
			peg2 = peg2->pnext;
		}
	}

	if (count3 != 0)
	{
		r = 0;
		c = 2;
		//draw peg3
		for (int i = 0; i < 3 - count3; i++)
		{
			stack[r][c] = " ";
			r++;
		}
		for (int i = 0; i < count3; i++)
		{
			if (peg3->value == 1)
			{
				stack[r][c] = "*";
				r++;
			}
			else if (peg3->value == 2)
			{
				stack[r][c] = "***";
				r++;
			}
			else if (peg3->value == 3)
			{
				stack[r][c] = "*****";
				r++;
			}
			peg3 = peg3->pnext;
		}
	}

	center_print(stack[0][0], 10);
	center_print(stack[0][1], 10);
	center_print(stack[0][2], 10);
	printf("\n");
	center_print(stack[1][0], 10);
	center_print(stack[1][1], 10);
	center_print(stack[1][2], 10);
	printf("\n");
	center_print(stack[2][0], 10);
	center_print(stack[2][1], 10);
	center_print(stack[2][2], 10);
	printf("\n");
	printf("================================\n");
	center_print("1", 10);
	center_print("2", 10);
	center_print("3", 10);
	printf("\n\n");
}

void center_print(const char *s, int width)
{
	const int length = strlen(s);
	int i;
	for (i = 0; i <= (width - length) / 2; i++) {
		fputs(" ", stdout);
	}
	fputs(s, stdout);
	i += length;
	for (; i <= width; i++) {
		fputs(" ", stdout);
	}
}