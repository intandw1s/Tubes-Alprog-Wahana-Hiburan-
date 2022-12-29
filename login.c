/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>*/
//#include "menu_utama.c"
//#include "crud_admin.c"

void masuk(){

	char username [10];
	char password [20];

    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|            Om Swastyastu! Hi! Ni Hao!           |\n");
    printf("\t\t\t\t|              ^0^ SELAMAT DATANG ^v^             |\n");
    printf("\t\t\t\t|                  LalaFund Land                  |\n");
    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|          SILAHKAN LOGIN TERLEBIH DAHULU         | \n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t  Masukkan Username     :");
    scanf("%s", username);
    printf("\t\t\t\t  Masukkan Password     :");
    fflush(stdin);
	scanf("%s", password);
    printf("\t\t\t\t...................................................\n");
    system("cls");
	if ((strcmp(username, "admin") == 0) && (strcmp(password, "yipi") ==0)){
        menuadmin();

	}else if ((strcmp(username, "kasir") == 0) && (strcmp(password, "yes") ==0)){
        intruksi();

	} else {
        getchar();
		printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                  ^.^ M A A F ^.^                |\n");
        printf("\t\t\t\t|             USERNAME // PASSWORD SALAH          |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         ^o^ SILAHKAN  INPUTKAN KEMBALI ^v^      |\n");
        printf("\t\t\t\t+=================================================+\n\n");
        getchar();
        masuk();

	}
	return 0;
}
