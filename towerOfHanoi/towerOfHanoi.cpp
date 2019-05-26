#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include "stack.h"
#define NUMBER_OF_DISKS 3

void menu();
void rules();
void play();

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
	int from, to;
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

	while(!compare(result, destination))
	{
		system("cls");
		printf("peg 1:  ");
		print(source);
		printf("\n");
		printf("peg 2:  ");
		print(temporary);
		printf("\n");
		printf("peg 1:  ");
		print(destination);
		printf("\n");
		printf("Move from: ");
		scanf("%d", &from);
		printf("\nMove to: ");
		scanf("%d", &to);

		switch (from)
		{
		case 1:
			if (isEmpty(source))
			{
				printf("This move is not allowed, please try again");
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
				printf("This move is not allowed, please try again");
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
				printf("This move is not allowed, please try again");
				break;
			}
			else
			{
				printf("Wrong input, try again");
				break;
			}
		case 2:
			if (isEmpty(temporary))
			{
				printf("This move is not allowed, please try again");
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
				printf("This move is not allowed, please try again");
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
				printf("This move is not allowed, please try again");
				break;
			}
			else
			{
				printf("Wrong input, try again");
				break;
			}
		case 3:
			if (isEmpty(destination))
			{
				printf("This move is not allowed, please try again");
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
				printf("This move is not allowed, please try again");
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
				printf("This move is not allowed, please try again");
				break;
			}
			else
			{
				printf("Wrong input, try again");
				break;
			}
		default:
			printf("wrong input, try again");
			break;
		}
	}
	printf("\nCongratulations, you won!\n\n");
	system("pause");
	menu();
}