#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "crud_wahana.c"
#include "crud_pemesanan.c"

int validasimenu() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s",angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
    if(angka[i]>=49 && angka[i]<=52){ // PEMBATAS PADA ASCII DIMANA 49-52 BERNILAI "1-4"

        }else{
            salah += 1;
        }
    }

    if(salah>1){
        system("cls");
        listmenu();
        printf("\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||       ^.^  MAAF PILIHAN TIDAK TERSEDIA ^.^      ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t  Silahkan Masukkan Ulang : ");
        validasimenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=4){
        return val;
        }else{
            system("cls");
            listmenu();
            printf("\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||       ^.^  MAAF PILIHAN TIDAK TERSEDIA ^.^      ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t  Silahkan Masukkan Ulang : ");
            validasimenu();
        }
    }
}


//INTRUKSI
void intruksi(){
    printf("\t\t\t\t+===========================================================================+\n");
    printf("\t\t\t\t|           	           Om swastyastu! Hi! Ni Hao!                       |\n");
    printf("\t\t\t\t|              	           S E L A M A T  D A T A N G                       |\n");
    printf("\t\t\t\t|...........................................................................|\n");
    printf("\t\t\t\t|========================= Welcome to LalaFund Land ========================|\n");
    printf("\t\t\t\t|...........................................................................|\n");
    printf("\t\t\t\t|                                  INTRUKSI                                 |\n");
    printf("\t\t\t\t+===========================================================================+\n\n");
    printf("\t\t--------- Mohon Perhatikan Instruksi Berikut Sebelum Melayani Pemesanan ---------\n");
    printf("\t\t1. Silahkan lihat informasi wahana untuk melihat info selengkapnya ! \n");
    printf("\t\t2. Untuk melakukan memasukkan data pemesanan, mengedit data, menghapus serta melihat data silahkan pilih menu pemesanan! \n");
    printf("\t\t3. Untuk melihat riwayat pemesanan silahkan pilih menu ketiga!\n");
    printf("\t\t4. Pastikan anda telah menginputkan data dengan benar! \n");
    printf("\t\t5. Jangan lupa tersenyum :)\n\n");
    printf("\t\t\t\t=============================================================================\n");
    printf("\t\t\t\t                           ^.^  Semangat Hari Ini ^.^                       \n");
    printf("\t\t\t\t=============================================================================\n");
    printf("\n\t\t\t\t Tekan apapun untuk ke menu selanjutnya! : ");
    getch();
    system("cls");
    menu();
}


//MENU UTAMA
void menu(){
    int pilihan;

    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund Land                  |\n");
    printf("\t\t\t\t|                   MENU UTAMA                    |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t Silahkan Pilih Menu yang Ingin Anda  :\n\n");
    printf("\t\t\t\t 1.Informasi Wahana\n");
    printf("\t\t\t\t 2.Pemesanan\n");
    printf("\t\t\t\t 3.Intruksi\n");
    printf("\t\t\t\t 4.Keluar\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\n\t\t\t\tMasukkan Menu Pilihan Anda(1/2/3/4) : ");
    pilihan = validasimenu();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
            datalihat();
	    break;
        case 2:
            pesanan();
	    break;
	    case 3:
            intruksi();
        break;
        case 4:
            printf("\t\t\t\t+=================================================+\n");
            printf("\t\t\t\t|                     PROGRAM                     |\n");
            printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
            printf("\t\t\t\t|.................................................|\n");
            printf("\t\t\t\t|    ^o^ TERIMAKASIH ATAS KERJA KERAS ANDA ^v^    |\n");
            printf("\t\t\t\t+=================================================+\n\n");
            exit(0);
        break;
	    default:
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||         ^.^ PILIHAN TIDAK TERSEDIA ^.^          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            sleep(3);
            system("cls");

	 }
}

void listmenu(){
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund Land                  |\n");
    printf("\t\t\t\t|                   MENU UTAMA                    |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t Silahkan Pilih Menu yang Ingin Anda  :\n\n");
    printf("\t\t\t\t 1.Informasi Wahana\n");
    printf("\t\t\t\t 2.Pemesanan\n");
    printf("\t\t\t\t 3.Riwayat Pemesanan\n");
    printf("\t\t\t\t 4.Intruksi\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
}
