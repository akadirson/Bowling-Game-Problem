#include<stdio.h>
#include<time.h>

int main() {

	int i, j;
	int puan[10];
	int labut;
	int vurulan1;
	int vurulan2;
	int strike;
	int spare;
	int atislar[21];
	char isimler[2][40] = { "Mary","Harry" };


	srand(time(NULL));
	printf("Abdulkadir Sonmezisik akadirson27@gmail.com\n");
	printf("Bowling Game\n\n");

	printf("\n\n             ");

	for (i = 1; i <= 10; i++) {
		printf("%d     ", i);
	}

	for (j = 0; j < 2; j++) { //loop for two player

		for (i = 0; i < 21; i++) {
			atislar[i] = 0;
		}
		for (i = 0; i < 10; i++) {
			puan[i] = 0;
		}
		strike = 0;
		spare = 0;

		for (i = 0; i < 18; i = i + 2) {
			labut = 10;
			vurulan1 = 0;
			vurulan2 = 0;

			vurulan1 = 1 + rand() % labut;
			atislar[i] = vurulan1;
			if (vurulan1 != 10) { //if player can't hit 10 on the first shot, decrease the number of pins for the second shot
				labut -= vurulan1;
				vurulan2 = 1 + rand() % labut;
				atislar[i + 1] = vurulan2;
			}

		}
		//Tenth frames
		labut = 10;
		atislar[18] = 1 + rand() % labut;
		if (atislar[18] != 10) {
			labut -= atislar[18];
			atislar[19] = 1 + rand() % labut;
		}
		else { //If the first shot is 10, put 10 pins for the second shot
			atislar[19] = 1 + rand() % 10;
			labut -= atislar[19];
		}

		if (atislar[18] + atislar[19] >= 10) {
			if (atislar[18] == 10 && atislar[19] != 10) {
				atislar[20] = 1 + rand() % labut;
			}
			else {
				atislar[20] = 1 + rand() % 10;
			}

		}
		else {
			atislar[20] = 0;
		}


		strike = 0;
		spare = 0;
		for (i = 0; i < 20; i = i + 2) {
			if (strike == 1) { //strike
				if (atislar[i + 1] != 0) {
					puan[(i / 2) - 1] += atislar[i] + atislar[i + 1];
				}
				else {
					puan[(i / 2) - 1] += atislar[i] + atislar[i + 2];
				}

			}
			else if (spare == 1) { //spare
				puan[(i / 2) - 1] += atislar[i];
			}


			strike = 0;
			spare = 0;

			puan[(i / 2)] = atislar[i] + atislar[i + 1];

			if (atislar[i] == 10) {
				strike = 1;
			}
			else if (atislar[i] + atislar[i + 1] == 10) {
				spare = 1;
			}
		}

		puan[9] += atislar[20];

		for (i = 1; i < 10; i++) {
			puan[i] += puan[i - 1];
		}

		printf("\n\n");
		printf("%-10s| ", isimler[j % 2]);
		for (i = 0; i < 18; i = i + 2) { //print operations
			if (atislar[i] == 10) {
				printf(" %-2s | ", "X");
			}
			else if (atislar[i] + atislar[i + 1] == 10) {
				printf(" %d/ | ", atislar[i]);
			}
			else if (atislar[i] + atislar[i + 1] != 10) {
				printf(" %d%d | ", atislar[i], atislar[i + 1]);
			}
		}

		if (atislar[18] == 10) {
			printf("X");

			if (atislar[19] == 10) {
				printf("X");
				if (atislar[20] == 10) {
					printf("%s |", "X");
				}
				else {
					printf("%d |", atislar[20]);
				}
			}
			else {
				printf("%d", atislar[19]);
				if (atislar[20] == 10) {
					printf("%s |", "X");
				}
				else {
					printf("%d |", atislar[20]);
				}
			}
		}
		else {
			if (atislar[18] + atislar[19] == 10) {
				printf("%d/", atislar[18]);
				if (atislar[20] == 10) {
					printf("%s |", "X");
				}
				else {
					printf("%d |", atislar[20]);
				}

			}
			else {
				printf(" %d%d | ", atislar[18], atislar[19]);
			}
		}


		printf("\n%-10s| ", "SCORE");

		for (i = 0; i < 10; i++) {
			printf("%3d | ", puan[i]);
		}

	}
	printf("\n\n");
	return 0;
}
