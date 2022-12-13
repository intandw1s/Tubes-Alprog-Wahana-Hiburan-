#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "intruksi.c"

void masuk(){

	char username [10];
	char password [20];

    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|            Om swastyastu! Hi! Ni Hao!           |\n");
    printf("\t\t\t\t|              ^0^SELAMAT DATANG ^v^              |\n");
    printf("\t\t\t\t|                 LalaFund Land                   |\n");
    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|          SILAHKAN LOGIN TERLEBIH DAHULU         | \n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t  Masukkan username     :");
    scanf("%s", username);
    printf("\t\t\t\t  Masukkan password     :");
    fflush(stdin);
	scanf("%s", password);
    printf("\t\t\t\t...................................................\n");
    system("cls");
	if ((strcmp(username, "admin") == 0) && (strcmp(password, "LalaFundyipihepi") ==0)){
        intruksi();

	}else {
        getchar();
		printf("\t\t\t\t MAAF USERNAME ATAU PASSWORD ANDA SALAH ^.^\n");
        printf("\t\t\t\t Tekan enter untuk mencoba kembali");
        printf("\t\t\t\t---------------------------------------------------\n");
        getchar();
        masuk();

	}
	return 0;
}
