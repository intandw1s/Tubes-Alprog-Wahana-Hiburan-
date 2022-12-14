#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//struct
struct tb_wahana {
	int id;
	char nama[30];
	int kategori;
	int prc_dom;
	int prc_inter;
}tambah,cek,hapus,sort[100],temp;


//Cek Bilangan
float validasiBil(){
    int i = 0;
    int salah =0;
    int titik=0;
    char angka[100];
    float val;
    int array;

    gets(angka);
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
        validasiBil();
    }else{
        val = atof(angka);
        return val;
    }
}

int main(){
    wahanaAdmin();
}

void wahanaAdmin(){
    int pilihan;
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund  Land                 |\n");
    printf("\t\t\t\t|                   Tabel Wahana                  |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\tPilihan Tabel Wahana :\n\n");
    printf("\n\t\t\t\t[1]. Tambah Data Wahana");
    printf("\n\t\t\t\t[2]. Edit Data Wahana");
    printf("\n\t\t\t\t[3]. Lihat Data Wahana");
    printf("\n\t\t\t\t[4]. Hapus Data Wahana");
    printf("\n\t\t\t\t[5]. Kembali");
    printf("\n\t\t\t\t[6]. Keluar");
    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\t\t\t\tMasukkan Pilihan Anda :");
    pilihan=validasiBil();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
            tambahdata();
	    break;
        case 2:
            //pesanAdmin();
	    break;
	    case 3:
            //detailAdmin();
        break;
        case 4:
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

void tambahdata(){
    FILE *ptr,*ptr1;
	int count=0;

	ptr =fopen("Data Wahana.txt","a");
		system("cls");
		ptr1 =fopen("Data Wahana.txt","r");
		tambah.id=1;
		while (fscanf (ptr1,"%d;%[^;];%d;%d;%d;\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
		{
			tambah.id++;
		}
		cek.id = tambah.id;
		fclose(ptr1);
		printf ("masukan nama wahana : ");fflush(stdin);
        scanf ("%[^\n]",tambah.nama);
		printf ("masukan kategori wahana : ");fflush(stdin);
		tambah.kategori=validasiBil();
		printf ("masukan harga domestik : ");fflush(stdin);
		tambah.prc_dom=validasiBil();
		printf ("masukan harga internasional : ");fflush(stdin);
		tambah.prc_inter=validasiBil();
		fprintf(ptr,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
		fclose(ptr);

		printf("\n\nData Wahana Sudah Disimpan !");
		add_invalid();
}

void add_invalid(){
    int pilihan;
    printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
    pilihan=validasiBil();
    switch(pilihan){
        case 1:
            wahanaAdmin();
        break;
        case 0:
            exit(1);
        break;
        default:
            printf("\nMaaf Kesalahan Input !");
            add_invalid();
        break;

    }
}
