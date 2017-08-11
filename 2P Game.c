#include <stdio.h>
#include <windows.h>

void check1();
void check2();
void game();
void gotoxy();

int user1[3] = { 0 };
int user2[3] = { 0 };
int answer1[3] = { 0 };
int answer2[3] = { 0 };
int strike1 = 0;
int strike2 = 0;
int ball1 = 0;
int ball2 = 0;
int n = 0;

void main()
{
	printf("Do not enter duplicate numbers.\n");
	printf("User 1 Enter number : ");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &answer1[i]);
	}
	system("cls");
	printf("Do not enter duplicate numbers.\n");
	printf("User 2 Enter number : ");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &answer2[i]);
	}
	system("cls");

	do {
		printf("User 1's turn\n");
		printf("Enter number : ");
		for (int i = 0; i < 3; i++) {
			scanf("%d", &user1[i]);
		}
		check1();

		gotoxy(50, n); n++;
		printf("User 2's turn\n");
		gotoxy(50, n); n++;
		printf("Enter number : ");
		for (int i = 0; i < 3; i++) {
			scanf("%d", &user2[i]);
		}
		check2();
		printf("\n");

		game();
	} while (strike1 != 3 && strike2 != 3);
}

void check1()
{
	strike1 = 0;
	ball1 = 0;

	for (int i = 0; i < 3; i++) {
		if (answer2[i] == user1[i]) {
			strike1++;
		}
	}
	if (user1[0] == answer2[1] || user1[0] == answer2[2])
		ball1++;
	if (user1[1] == answer2[0] || user1[1] == answer2[2])
		ball1++;
	if (user1[2] == answer2[0] || user1[2] == answer2[1])
		ball1++;
	printf("%d Strike %d Ball\n", strike1, ball1);
}
void check2()
{
	strike2 = 0;
	ball2 = 0;

	for (int i = 0; i < 3; i++) {
		if (answer1[i] == user2[i]) {
			strike2++;
		}
	}
	if (user2[0] == answer1[1] || user2[0] == answer1[2])
		ball2++;
	if (user2[1] == answer1[0] || user2[1] == answer1[2])
		ball2++;
	if (user2[2] == answer1[0] || user2[2] == answer1[1])
		ball2++;
	gotoxy(50, n); n += 2;
	printf("%d Strike %d Ball\n", strike2, ball2);
}
void game()
{
	if (strike1 == 3) {
		printf("User 1 WIN !\n");
	}
	if (strike2 == 3) {
		gotoxy(50, n); n += 2;
		printf("User 2 WIN !\n");
	}
}
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
