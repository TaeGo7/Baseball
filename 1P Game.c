/* 1P Baseball Game */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create();		// create number & check duplicate numbers
void play();
void check();
void game();

int i, j;
int user[3];
int answer[3];
int strike = 0;
int ball = 0;
int count = 0;

void main()
{
	srand(time(NULL));
	printf("Do not enter duplicate numbers.\n");
	create();

	do {
		strike = 0;
		ball = 0;

		play();
		check();
		count++;
		game();
	} while (strike != 3 && count != 10);
}

void create()
{
	for (i = 0; i < 3; i++) {
		answer[i] = rand() % 9 + 1;

		for (j = 0; j < i; j++) {
			if (answer[i] == answer[j]) {
				answer[i] = rand() % 9 + 1;
				j--;
			}
		}
	}
}
void play()
{
	printf("Enter numbers : ");
	for (i = 0; i < 3; i++) {
		scanf("%d", &user[i]);
	}
}
void check()
{
	for (i = 0; i < 3; i++) {
		if (user[i] == answer[i])
			strike++;
	}

	if (user[0] == answer[1] || user[0] == answer[2])
		ball++;
	if (user[1] == answer[0] || user[1] == answer[2])
		ball++;
	if (user[2] == answer[0] || user[2] == answer[1])
		ball++;

	printf("%d Strike %d Ball\n", strike, ball);
}
void game()
{
	if (strike == 3) {
		printf("User WIN !\n");
		printf("Count = %d\n", count);
	}
	else if (count == 10) {
		printf("User LOSE ... \n");
	}
}
