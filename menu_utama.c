#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "admin/crud_wahana.c"

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
    printf("\t\t\t\t|           	         Om swastyastu! Hi! Ni Hao!                     |\n");
    printf("\t\t\t\t|              		   ^0^ SELAMAT DATANG ^v^                       |\n");
    printf("\t\t\t\t|...........................................................................|\n");
    printf("\t\t\t\t|============================ Welcome to LalaFund Land =====================|\n");
    printf("\t\t\t\t|...........................................................................|\n");
    printf("\t\t\t\t|-------------------------------------INTRUKSI------------------------------|\n");
    printf("\t\t\t\t+===========================================================================+\n\n");
    printf("\t\t--------- Mohon Perhatikan Instruksi Berikut Sebelum Melayani Pemesanan ---------\n");
    printf("\t\t1. Silahkan lihat informasi wahana untuk melihat info selengkapnya ! \n");
    printf("\t\t2. Masukkan golongan customer \n");
    printf("\t\t3. Selanjutnya, inputkan golongan tiket customer\n");
    printf("\t\t4. Hingga tampil menu wahana pilihan, anda dapat menginputkan pesanan customer \n");
    printf("\t\t  (Pastikan inputan anda telah benar)\n");
    printf("\t\t5. Kemudian inputkan data sesuai intruksi!\n\n");
    printf("\t\t\t\t=============================================================================\n");
    printf("\t\t\t\t                                Semanagat Hari Ini ^.^                       \n");
    printf("\t\t\t\t=============================================================================\n");
    printf("\n\t\t\t\t Tekan apapun untuk ke menu selanjutnya! : ");
    getch();
    system("cls");
    menu();
}


//MENU UTAMA
void menu(){
    int pilihan;

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
    printf("\t\t\t\t 5.Keluar\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\n\t\t\t\tMasukkan Menu Pilihan Anda(1/2/3/4) : ");
    pilihan = validasimenu();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
            printf("MENU 1");
            datalihat();
	    break;
        case 2:
            printf("MENU 2");
            //pesan1();
	    break;
	    case 3:
           // riwayat();
           printf("ini riwayat");
	    break;
	    case 4:
            intruksi();
        break;
        case 5:
            exit(0);
        break;
	    default:
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||             PILIHAN TIDAK TERSEDIA ^.^          ||\n");
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
