/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>*/
//#include "menu_utama.c"

//struct
struct tb_wahana {
	int id;
	char nama[30];
	int kategori;
	int prc_dom;
	int prc_inter;
}tambah,cek,hapus,sort[100],temp;


float validasiangka(){
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
        validasiangka();
    }else{
        val = atof(angka);
        return val;
    }
}

/*int main(){
    wahanaAdmin();
}*/
void wahanaAdmin(){
    int pilihan;
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund  Land                 |\n");
    printf("\t\t\t\t|                   Tabel Wahana                  |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tPilihan Tabel Wahana :\n\n");
    printf("\n\t\t\t\t[1]. Tambah Data Wahana");
    printf("\n\t\t\t\t[2]. Edit Data Wahana");
    printf("\n\t\t\t\t[3]. Lihat Data Wahana");
    printf("\n\t\t\t\t[4]. Hapus Data Wahana");
    printf("\n\t\t\t\t[5]. Kembali");
    printf("\n\t\t\t\t[6]. Keluar");
    printf("\n\t\t\t\t-------------------------------------------------\n");
    printf("\t\t\t\tMasukkan Pilihan Anda :");
    pilihan=validasiangka();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
            tambahdata();
	    break;
        case 2:
            editdata();
	    break;
	    case 3:
            lihatdata();
        break;
        case 4:
            hapusdata();
        break;
        case 5:
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
            printf("\t\t\t\t||         ^.^ PILIHAN TIDAK TERSEDIA ^.^          ||\n");
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
		//	tambah.id++;
		}
		//cek.id = tambah.id;
		fclose(ptr1);
		printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                                                 |\n");
        printf("\t\t\t\t|                   LalaFund Land                 |\n");
        printf("\t\t\t\t+-------------------------------------------------+\n");
        printf("\t\t\t\t|          T A M B A H  D A T A  W A H A N A      |\n");
        printf("\t\t\t\t|                                                 |\n");
        printf("\t\t\t\t+=================================================+\n");
		printf ("\t\t\t\tMasukan ID Wahana : ");fflush(stdin);
        tambah.id=validasiangka();
		printf ("\t\t\t\tMasukan Nama Wahana : ");fflush(stdin);
        scanf ("%[^\n]",tambah.nama);
		printf ("\t\t\t\tMasukan Kategori Wahana : ");fflush(stdin);
		tambah.kategori=validasiangka();
		printf ("\t\t\t\tMasukan Harga Domestik : ");fflush(stdin);
		tambah.prc_dom=validasiangka();
		printf ("\t\t\t\tMasukan Harga Internasional : ");fflush(stdin);
		tambah.prc_inter=validasiangka();
		fprintf(ptr,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
		fclose(ptr);

        printf("\n\n\t\t\t\t+..................................................+\n");
		printf("\t\t\t\t^,^ Data Wahana Sudah Disimpan ^,^");
		add_valid();
}

void add_valid(){
    int pilihan;
    printf("\n\t\t\t\t+.................................................+\n");
    printf("\n\t\t\t\t[1] Mengulang");
    printf("\n\t\t\t\t[2] Menu Utama      ");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\n\n\t\t\t\tMasukkan Pilihan Anda  : ");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            tambahdata();
        break;
        case 2:
            wahanaAdmin();
        break;
        case 0:
            exit(1);
        break;
        default:
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
    printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            wahanaAdmin();
        break;
        case 0:
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
            printf("\t\t\t\t||      U_U  MAAF PILIHAN TIDAK TERSEDIA  U_U      ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            add_valid();
        break;

    }
    }
}

void editdata(){
    int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("Data Wahana.txt","r");
	baru = fopen ("baru.txt","w");
	//system("cls");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|          E D I T  D A T A  W A H A N A          |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n");
	printf("\t\t\t\tMasukkan ID Wahana : ");
	cek.id=validasiangka();
	while(fscanf (lama,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
		if(tambah.id == cek.id)
		{
			test=1;
			ganti:
                printf("\t\t\t\t+-------------------------------------------------+\n");
				printf("\t\t\t\tNo. ID : %d  ||  Wahana dengan Nama : %s",tambah.id,tambah.nama);
				printf("\n\n\t\t\t\tData yang akan diganti : ");
				printf("\n\t\t\t\t[1]. Nama Wahana");
				printf("\n\t\t\t\t[2]. Kategori Wahana");
				printf("\n\t\t\t\t[3]. Harga Domestik");
				printf("\n\t\t\t\t[4]. Harga Internasional");
                printf("\n\t\t\t\t+-------------------------------------------------+\n");
				printf("\t\t\t\tMasukkan Pilihan Anda  : ");
                pilih=validasiangka();

				if(pilih == 1)
				{
                    printf("\n\t\t\t\t...................................................\n");
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
                    printf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t^,^ Data Wahana Sudah Disimpan ^,^");
				}
				else if (pilih == 2)
				{
                    printf("\n\t\t\t\t...................................................\n");
					printf("\nMasukan Data Kategori Wahana : ");fflush(stdin);
					scanf ("%d",&cek.kategori);
					tambah.kategori = cek.kategori;
                    fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
					printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t^,^ Data Wahana Sudah Disimpan ^,^");
				}
				else if (pilih == 3)
				{
				    printf("\n\t\t\t\t...................................................\n");
					printf ("\nMasukan Data Harga Domestik Baru : ");
					scanf ("%d",&cek.prc_dom);
					tambah.prc_dom = cek.prc_dom;
                    fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
					printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t^,^ Data Wahana Sudah Disimpan ^,^");
				}
                else if (pilih == 4)
				{
				    printf("\n\t\t\t\t...................................................\n");
					printf ("\nMasukan Data Harga Internasional Baru : ");
					scanf ("%d",&cek.prc_inter);
					tambah.prc_inter = cek.prc_inter;
                    fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
					printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t^,^ Data Wahana Sudah Disimpan ^,^");
				}
				else{
					printf("\t\t\t\t||=================================================||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||=================================================||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||=================================================||\n");
					editdata();
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("Data Wahana.txt");
	rename("baru.txt","Data Wahana.txt");
	if(test!=1){
		system("cls");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||           U_U  DATA TIDAK DITEMUKAN  U_U        ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        edit_invalid();
        }
    else{
    	edit_valid();
        }
    }

void edit_invalid(){
    int pilih;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Silahkan Ulangi");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/0] :");
    pilih=validasiangka();
    switch(pilih){
        case 1:
            editdata();
        break;
        case 0:
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            edit_invalid();
            break;
        }
}

void edit_valid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Edit Data Lagi ");
    printf("\n\t\t\t\t[2] Menu Utama");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/2/3/0] :");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            editdata();
        break;
        case 2:
            wahanaAdmin();
        break;
        case 0:
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            edit_valid();
        break;
    }
}

void lihatdata(){
    FILE *view;
	view = fopen("Data Wahana.txt","r");
	int test=0;
	system ("cls");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|               D A T A  W A H A N A              |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n\n");
	while (fscanf (view,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
        printf("\t\t\t\tID Wahana               : %d\n", tambah.id);
        printf("\t\t\t\tNama Wahana             : %s\n", tambah.nama);
        printf("\t\t\t\tKategori                : %d\n", tambah.kategori);
        printf("\t\t\t\tHarga Domestik          : %d\n", tambah.prc_dom);
        printf("\t\t\t\tHarga Internasional     : %d\n", tambah.prc_inter);
        printf("\t\t\t\t..................................................\n\n");
            test++;

	}
	printf ("\n\t\t\t\t\tJumlah Wahana : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||            U_U  MAAF DATA KOSONG  U_U           ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
	}
        list_invalid();
}

void datalihat(){
    FILE *view;
	view = fopen("Data Wahana.txt","r");
	int test=0;
	system ("cls");
	printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|               D A T A  W A H A N A              |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n\n");
	while (fscanf (view,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{

        printf("\t\t\t\tID Wahana               : %d\n", tambah.id);
        printf("\t\t\t\tNama Wahana             : %s\n", tambah.nama);
        printf("\t\t\t\tKategori                : %d\n", tambah.kategori);
        printf("\t\t\t\tHarga Domestik          : %d\n", tambah.prc_dom);
        printf("\t\t\t\tHarga Internasional     : %d\n", tambah.prc_inter);
        printf("\t\t\t\t..................................................\n\n");
            test++;
	}
	printf ("\n\t\t\t\tJumlah Wahana : %d",test);
    printf("\n\t\t\t\t+=================================================+");
	fclose(view);

	if(test==0)
	{
		system("cls");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||            U_U  MAAF DATA KOSONG  U_U           ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
	}
        list_invalid1();
}

void list_invalid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t [1] Menu Utama  : ");
    printf("\n\t\t\t\t [0] Keluar      : ");
    printf("\t\t\t\t Masukkan Pilihan Anda  : ");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            wahanaAdmin();
        break;
        case 0:
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
        	list_invalid();
        break;
    }
}

void list_invalid1(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t [1] Menu Utama  : ");
    printf("\n\t\t\t\t [0] Keluar      : ");
    printf("\n\t\t\t\t Masukkan Pilihan Anda  : ");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            menu();
        break;
        case 0:
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
        	list_invalid1();
        break;
    }
}
/*void edit_valid(){
    int pilihan;
    printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            wahanaAdmin();
        break;
        case 0:
            close();
        break;
        default:
            printf("\nMaaf Kesalahan Input !");
            edit_valid();
        break;
    }
}*/

void hapusdata(){
    FILE *lama, *baru;
	int test=0;
	lama = fopen("Data Wahana.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|          H A P U S  D A T A  W A H A N A        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n\n");
	printf("\t\t\t\tMasukkan ID Wahana yang akan di Hapus : ");
	scanf("%d", &hapus.id);
	while(fscanf (lama,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
		}
		else{
			test++;
            printf("\t\t\t\t+-------------------------------------------------+\n");
			printf("\n\t\t\t\tData Wahana No ID : %d dengan Nama : %s\n",tambah.id,tambah.nama);
            printf("\n\t\t\t\t+..................................................+\n");
            printf("\t\t\t\t^,^ Data Berhasil Terhapus dari Daftar ^,^");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("Data Wahana.txt");
	rename("baru.txt","Data Wahana.txt");
    if(test==0){
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||       U_U  MAAF DATA TIDAK DITEMUKAN  U_U       ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
    erase_invalid();
    }
    else{
    	erase_valid();
        }
}

void erase_invalid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t [1] Ulangi      : ");
    printf("\n\t\t\t\t [2] Menu Utama  : ");
    printf("\n\t\t\t\t [0] Keluar      : ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t Masukkan Pilihan Anda  : ");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            hapusdata();
        break;
        case 2:
            wahanaAdmin();
        break;
        case 0:
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
        	erase_invalid();
        break;
    }
}

void erase_valid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t [1] Ulangi      : ");
    printf("\n\t\t\t\t [2] Menu Utama  : ");
    printf("\n\t\t\t\t [0] Keluar      : ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t Masukkan Pilihan Anda  : ");
    pilihan=validasiangka();
    switch(pilihan){
        case 1:
            hapusdata();
        break;
        case 2:
            wahanaAdmin();
        break;
        case 0:
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
        	erase_valid();
        break;
    }
}


void showwahana(int kategori){
    FILE *view;
    view = fopen("./admin/Data Wahana.txt","r");
	int test=0;
	cek.kategori=kategori;
	//system ("cls");
	while (fscanf (view,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
	    if (tambah.kategori==cek.kategori){
            printf("\t\t\t\t-------------------------\n");
            printf("\n");
            printf("\t\t\t\tID Wahana               : %d\n", tambah.id);
            printf("\t\t\t\tNama Wahana             : %s\n", tambah.nama);
            printf("\t\t\t\tKategori                : %d\n", tambah.kategori);
            printf("\t\t\t\tHarga Domestik          : %d\n", tambah.prc_dom);
            printf("\t\t\t\tHarga Internasional     : %d\n", tambah.prc_dom);
            printf("\t\t\t\t-------------------------\n");
            printf("\n");
            printf("\n");
            test++;
	    }
	}
	printf ("\n\t\t\t\tJumlah Wahana : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
		printf ("\n\t\t\t\tData Kosong ! \n");
	}
        //list_invalid();
}
