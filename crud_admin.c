#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "crud_wahana.c"
#include "crud_pemesanan.c"

//Cek Bilangan
float validasipil(){
    int i = 0;
    int salah =0;
    int titik=0;
    char angka[100];
    float val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

    }else{
        salah += 1;
    }

    for(i=1;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "."
            titik += 1;
        }else{
            salah += 1;
        }
    }

    if(salah>0 || titik>1){
        printf("\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||     ^.^  MAAF MASUKKAN ANDA TIDAK VALID ^.^     ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t  Silahkan Masukkan Ulang : ");
        validasipil();
    }else{
        val = atof(angka);
        return val;
    }
}

/*int main(){
    menuadmin();
}*/

    printf("\t\t\t\t+===========================================================================+\n");
    printf("\t\t\t\t|           	           Om swastyastu! Hi! Ni Hao!                       |\n");
    printf("\t\t\t\t|              	       ^0^ S E L A M A T  D A T A N G ^v^                   |\n");
    printf("\t\t\t\t|...........................................................................|\n");
    printf("\t\t\t\t|========================= Welcome to LalaFund Land ========================|\n");
    printf("\t\t\t\t|...........................................................................|\n");
    printf("\t\t\t\t|                                 A D M I N                                 |\n");
    printf("\t\t\t\t+===========================================================================+\n\n");

int sekalimuncul = 0;
void menuadmin(){
    if (sekalimuncul != 1){
    cover();
    sekalimuncul=1;
    }
    int pilihan;
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund Land                  |\n");
    printf("\t\t\t\t|                   Menu Admin                    |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\tPilihan Menu :\n\n");
    printf("\t\t\t\t1.Tabel Wahana\n");
    printf("\t\t\t\t2.Tabel Pemesanan\n");
    printf("\t\t\t\t3.Keluar\n");
    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\t\t\t\tMasukkan Pilihan Anda :");
    pilihan=validasipil();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
           wahanaAdmin();
	    break;
        case 2:
            pesanan()
	    break;
        case 4:
            printf("\t\t\t\t+=================================================+\n");
            printf("\t\t\t\t|                     PROGRAM                     |\n");
            printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
            printf("\t\t\t\t|.................................................|\n");
            printf("\t\t\t\t|    ^o^ TERIMAKASIH ATAS KERJA KERAS ANDA ^v^    |\n");
            printf("\t\t\t\t+=================================================+\n\n");
            exit(1);
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
