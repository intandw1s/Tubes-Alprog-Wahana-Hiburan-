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
            editdata();
	    break;
	    case 3:
            lihatdata();
        break;
        case 4:
            //hapusdata();
        break;
        case 5:
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

void editdata(){
    int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("Data Wahana.txt","r");
	baru = fopen ("baru.txt","w");
	//system("cls");

	printf ("Masukan ID Wahana : ");
	cek.id=validasiBil();
	while(fscanf (lama,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
		if(tambah.id == cek.id)
		{
			test=1;
			ganti:
				printf("\nNo. ID : %d dimiliki pada Wahana dengan Nama : %s",tambah.id,tambah.nama);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Nama Wahana");
				printf("\n[2]. Kategori Wahana");
				printf("\n[3]. Harga Domestik");
				printf("\n[4]. Harga Internasional");
				printf("\nInput Pilihan : ");
                pilih=validasiBil();

				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
						fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Kategori Wahana : ");fflush(stdin);
					scanf ("%d",cek.kategori);
					strcpy(tambah.kategori,cek.kategori);
						fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Harga Domestik Baru : ");
					scanf ("%d",&cek.prc_dom);
					tambah.prc_dom = cek.prc_dom;
                        fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
					printf ("\nPerubahan Sudah Disimpan !");
				}
                else if (pilih == 4)
				{
					printf ("\nMasukan Data Harga Internasional Baru : ");
					scanf ("%d",&cek.prc_inter);
					tambah.prc_inter = cek.prc_inter;
                        fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
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
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid();
        }
    else{
    	edit_valid();
        }
    }

void edit_invalid(){
    int pilih;
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        pilih=validasiBil();
        switch(pilih){
            case 0:
                editdata();
            break;
            case 1:
                wahanaAdmin();
            break;
            case 2:
                close();
            break;
            default:
                printf("\nMaaf Kesalahan Input !");
            edit_invalid();
            break;
        }
}

void edit_valid(){
    int pilihan;
    printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
    pilihan=validasiBil();
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
}

void lihatdata(){
    FILE *view;
	view = fopen("Data Wahana.txt","r");
	int test=0;
	system ("cls");
	printf ("ID\tNAMA WAHANA\t\tKATEGORI\t\tHARGA DOMESTIK\t\tHARGA INTERNASIONAL\t\t\n");
	while (fscanf (view,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
            printf("%d\t%s%10.2d\t\t%d\t\t%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
            test++;

	}
	printf ("\nJumlah Wahana : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
        list_invalid();
}

void list_invalid(){
    int pilihan;
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    pilihan=validasiBil();
    switch(pilihan){
    	case 1:
    	    wahanaAdmin();
        break;
        case 0:
            close();
        break;
        default:
            printf("\nMaaf Kesalahan Input !");
        	list_invalid();
        break;
    }
}
