#include <stdio.h>
#include <Windows.h>
//#pragma warning(disable: 4996)

void gotoxy();
void WriteLineup();
void ShowLineup();

struct Batter {
	int AVG;
	int HIT;
	/* int DOUBLE;
	int TRIPLE; 
	int RUN; */
	int BB;
	int SO;
};
struct Pitcher {
	int ER;
	int ERA;
	int INNING;
	int WIN;
	int LOSE;
	int HOLD;
	int SAVE;
	int SO;
	int BB;
	int HIT;
};
char TeamType[2][5] = { "Home", "Away" };
char TeamName[2][21];
char Batter[2][9][21];
char Pitcher[2][10][21];
int n[2] = { 0, 25 }; // Move right

void main()
{
	WriteLineup();
	ShowLineup();
}

void WriteLineup()
{
	//printf("Write your Baseball Lineup Card\n");

	for (int j = 0; j < 2; j++) {	// Team Order
		printf("%s Team : ", TeamType[j]);
		scanf("%s", TeamName[j]);

		printf("Batter\n");
		for (int i = 0; i < 9; i++) {	// Member Number
			printf("%d : ", i + 1);
			scanf("%s", Batter[j][i]);	// Input Name
		}
		system("cls");
	}
	/*
	printf("Home Team : ");
	scanf("%s", TeamName[0]);
	printf("Batter\n");
	for (int i = 0; i < 9; i++) {
	printf("%d : ", i + 1);
	scanf("%s", Batter[0][i]);
	}
	system("cls");
	printf("Away Team : ");
	scanf("%s", TeamName[1]);
	printf("Batter\n");
	for (int i = 0; i < 9; i++) {
	printf("%d : ", i + 1);
	scanf("%s", Batter[1][i]);
	}
	system("cls");
	*/
}
void ShowLineup()
{
	for (int j = 0; j < 2; j++) {
		gotoxy(n[j], 0);
		//printf("%s Team\n", TeamType[j]);
		printf("%s\n", TeamName[j]);
		for (int i = 1; i < 10; i++) {
			gotoxy(n[j], i + 1);
			printf("%d. %s\n",i, Batter[j][i - 1]);
		}
	}
}
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
