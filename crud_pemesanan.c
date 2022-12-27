#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const char* nm_wahana(int id_wahana){
    char *wahana_name;
    int total;
    if(id_wahana==11){
        wahana_name="Waterpark";
    }/*else if (id_wahana==12){
        total=((subtotal_anak_dom*harga_anak[1][0])+(subtotal_anak_inter*harga_anak[1][1]));
    }else if (id_wahana==13){
        total=((subtotal_anak_dom*harga_anak[2][0])+(subtotal_anak_inter*harga_anak[2][1]));
    }else if (id_wahana==21){
        total=((subtotal_dws_dom*harga_dewasa[0][0])+(subtotal_dws_inter*harga_dewasa[0][1]));
    }else if (id_wahana==22){
        total=((subtotal_dws_dom*harga_dewasa[1][0])+(subtotal_dws_inter*harga_dewasa[1][1]));
    }else if (id_wahana==23){
        total=((subtotal_dws_dom*harga_dewasa[2][0])+(subtotal_dws_inter*harga_dewasa[2][1]));
    }else if (id_wahana==24){
        total=((subtotal_dws_dom*harga_dewasa[3][0])+(subtotal_dws_inter*harga_dewasa[3][1]));
    }else if (id_wahana==25){
        total=((subtotal_dws_dom*harga_dewasa[4][0])+(subtotal_dws_inter*harga_dewasa[4][1]));
    }else if (id_wahana==26){
        total=((subtotal_dws_dom*harga_dewasa[5][0])+(subtotal_dws_inter*harga_dewasa[5][1]));
    }else if (id_wahana==27){
        total=((subtotal_dws_dom*harga_dewasa[6][0])+(subtotal_dws_inter*harga_dewasa[6][1]));
    }else if (id_wahana==31){
        total=((subtotal_anak_dom*harga_keluarga[0][0])+(subtotal_anak_inter*harga_keluarga[0][1])+(subtotal_dws_dom*harga_keluarga[0][0])+(subtotal_dws_inter*harga_keluarga[0][1]));
    }else if (id_wahana==32){
        total=((subtotal_anak_dom*harga_keluarga[1][0])+(subtotal_anak_inter*harga_keluarga[1][1])+(subtotal_dws_dom*harga_keluarga[1][0])+(subtotal_dws_inter*harga_keluarga[1][1]));
    }else if (id_wahana==33){
        total=((subtotal_anak_dom*harga_keluarga[2][0])+(subtotal_anak_inter*harga_keluarga[2][1])+(subtotal_dws_dom*harga_keluarga[2][0])+(subtotal_dws_inter*harga_keluarga[2][1]));
    }else {
        total=0;
    }*/
    return wahana_name;

}

//variabel global
int psn_id;
//const char* nm_wahana(char*id_wahana);

//harga wahana 1
int harga_anak [3][2]=  {{50000,80000},
                        {80000,100000},
                        {75000,110000}};

int harga_dewasa [7][2]=  {{100000,150000},
                          {125000,175000},
                          {50000,85000},
                          {45000,75000},
                          {110000,145000},
                          {150000},{250000},
                          {80000, 120000}};

int harga_keluarga [3][2]={{35000,65000},
                          {50000,80000},
                          {55000,85000}};


//wahana
//char wahana_anak[][]= {{Waterpark},{Outbound Games},{LalaFund Park}};

//struct
struct tb_pemesanan {
	int id_psn;
	char nama_psn[30];

}tambah_psn,cek_psn,hapus_psn,sort_psn[100],temp_psn;

struct dt_pemesanan {
	int id_det_psn;
	//int id_pemesanan;
	int id_wahana;
	char nama_whn[100];
	int subtotal_anak_dom;
    int subtotal_anak_inter;
	int subtotal_dws_dom;
    int subtotal_dws_inter;
	int subtotal_harga;

}tambah_dtpsn,cek_dtpsn,hapus_dtpsn,sort_dtpsn[100],temp_dtpsn;


//Cek Bilangan
/*float validasiBil(){
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
        validasiBil1();
    }else{
        val = atof(angka);
        return val;
    }
}*/

float validasiBil1(){
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
        validasiBil1();
    }else{
        val = atof(angka);
        return val;
    }
}

int main(){
    pesanan();
}
void pesanan(){
    int pilihan;
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund  Land                 |\n");
    printf("\t\t\t\t|                     Pemesanan                   |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\tPilihan Tabel Pemesanan :\n\n");
    printf("\n\t\t\t\t[1]. Tambah Data Pemesanan");
    printf("\n\t\t\t\t[2]. Edit Data Pemesanan");
    printf("\n\t\t\t\t[3]. Lihat Data Pemesanan");
    printf("\n\t\t\t\t[4]. Hapus Data Pemesanan");
    printf("\n\t\t\t\t[5]. Kembali");
    printf("\n\t\t\t\t[6]. Keluar");
    printf("\n\t\t\t\t-------------------------------------------------\n");
    printf("\t\t\t\tMasukkan Pilihan Anda :");
    pilihan=validasiBil1();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
            tambahdata_psn();
	    break;
        case 2:
           // dtpsn_tambah1();
	    break;
	    case 3:
            //lihatdata();
        break;
        case 4:
            //hapusdata();
        break;
        case 5:
            //exit(1);
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

void tambahdata_psn(){
    FILE *ptr,*ptr1;
	int count=0;

	ptr =fopen("Data Pemesanan.txt","a");
		system("cls");
		ptr1 =fopen("Data Pemesanan.txt","r");
		tambah_psn.id_psn=1;
		while (fscanf (ptr1,"%d;%[^;];\n",&tambah_psn.id_psn,tambah_psn.nama_psn)!=EOF)
		{
			tambah_psn.id_psn++;
		}
		cek_psn.id_psn = tambah_psn.id_psn;
		fclose(ptr1);
		printf ("masukan nama pelanggan : ");fflush(stdin);
        scanf ("%[^\n]",tambah_psn.nama_psn);

		fprintf(ptr,"%d;%s;\n",tambah_psn.id_psn,tambah_psn.nama_psn);
		psn_id=tambah_psn.id_psn;
		fclose(ptr);

		printf("\n\nData Pemesanan Sudah Disimpan !");
		add_invalid();
}


void add_invalid(){
    int pilihan;
    printf("\n\n\tEnter 1 untuk ke menu selanjutnya : ");
    pilihan=validasiBil1();
    switch(pilihan){
        case 1:
            dtpsn_tambah();
        break;
        default:
            printf("\nMaaf Kesalahan Input !");
            add_invalid();
        break;

    }
}

void dtpsn_tambah(){
    FILE *ptr,*ptr1;
	int count=0;
    int subtotal;
    char *wahana_id;
    tambah_dtpsn.id_det_psn=1;
	ptr =fopen("Data Detail Pemesanan.txt","a");
		system("cls");
		ptr1 =fopen("Data Detail Pemesanan.txt","r");
		while (fscanf(ptr1,"%d;%d;%d;%[^\n];%d;%d;%d;%d;%d\n",&tambah_dtpsn.id_det_psn,&psn_id,&tambah_dtpsn.id_wahana,wahana_id,&tambah_dtpsn.subtotal_anak_dom,&tambah_dtpsn.subtotal_anak_inter,&tambah_dtpsn.subtotal_dws_dom,&tambah_dtpsn.subtotal_dws_inter,&subtotal)!=EOF)
		{
			tambah_dtpsn.id_det_psn++;
		}
		cek_dtpsn.id_det_psn = tambah_dtpsn.id_det_psn;
		fclose(ptr1);
		printf ("masukan id wahana : ");
		fflush(stdin);
        //scanf ("%[^\n]",tambah_dtpsn.id_wahana);
        tambah_dtpsn.id_wahana=validasiBil1();
		printf ("masukan jumlah anak domestik : ");
		fflush(stdin);
		tambah_dtpsn.subtotal_anak_dom=validasiBil1();
		printf ("masukan jumlah anak internasional: ");
		fflush(stdin);
		tambah_dtpsn.subtotal_anak_inter=validasiBil1();
		printf ("masukan jumlah dewasa domestik : ");
		fflush(stdin);
		tambah_dtpsn.subtotal_dws_dom=validasiBil1();
		printf ("masukan jumlah dewasa internasional : ");
		fflush(stdin);
		tambah_dtpsn.subtotal_dws_inter=validasiBil1();
		subtotal= calstotal(tambah_dtpsn.id_wahana,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
		wahana_id=nm_wahana(tambah_dtpsn.id_wahana);
		fprintf(ptr,"%d;%d;%d;%s;%d;%d;%d;%d;%d\n",tambah_dtpsn.id_det_psn,psn_id,tambah_dtpsn.id_wahana,wahana_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,subtotal);
		fclose(ptr);

		printf("\n\nData Pemesanan Sudah Disimpan !");
		printf("%s", wahana_id);
		add_invalid2();
}


int calstotal(char*id_wahana,int subtotal_anak_dom,int subtotal_anak_inter,int subtotal_dws_dom,int subtotal_dws_inter){
    int total;
    if(id_wahana=='11'){
        total=((subtotal_anak_dom*harga_anak[0][0])+(subtotal_anak_inter*harga_anak[0][1]));
    }else if (id_wahana=='12'){
        total=((subtotal_anak_dom*harga_anak[1][0])+(subtotal_anak_inter*harga_anak[1][1]));
    }else if (id_wahana=='13'){
        total=((subtotal_anak_dom*harga_anak[2][0])+(subtotal_anak_inter*harga_anak[2][1]));
    }else if (id_wahana=='21'){
        total=((subtotal_dws_dom*harga_dewasa[0][0])+(subtotal_dws_inter*harga_dewasa[0][1]));
    }else if (id_wahana=='22'){
        total=((subtotal_dws_dom*harga_dewasa[1][0])+(subtotal_dws_inter*harga_dewasa[1][1]));
    }else if (id_wahana=='23'){
        total=((subtotal_dws_dom*harga_dewasa[2][0])+(subtotal_dws_inter*harga_dewasa[2][1]));
    }else if (id_wahana=='24'){
        total=((subtotal_dws_dom*harga_dewasa[3][0])+(subtotal_dws_inter*harga_dewasa[3][1]));
    }else if (id_wahana=='25'){
        total=((subtotal_dws_dom*harga_dewasa[4][0])+(subtotal_dws_inter*harga_dewasa[4][1]));
    }else if (id_wahana=='26'){
        total=((subtotal_dws_dom*harga_dewasa[5][0])+(subtotal_dws_inter*harga_dewasa[5][1]));
    }else if (id_wahana=='27'){
        total=((subtotal_dws_dom*harga_dewasa[6][0])+(subtotal_dws_inter*harga_dewasa[6][1]));
    }else if (id_wahana=='31'){
        total=((subtotal_anak_dom*harga_keluarga[0][0])+(subtotal_anak_inter*harga_keluarga[0][1])+(subtotal_dws_dom*harga_keluarga[0][0])+(subtotal_dws_inter*harga_keluarga[0][1]));
    }else if (id_wahana=='32'){
        total=((subtotal_anak_dom*harga_keluarga[1][0])+(subtotal_anak_inter*harga_keluarga[1][1])+(subtotal_dws_dom*harga_keluarga[1][0])+(subtotal_dws_inter*harga_keluarga[1][1]));
    }else if (id_wahana=='33'){
        total=((subtotal_anak_dom*harga_keluarga[2][0])+(subtotal_anak_inter*harga_keluarga[2][1])+(subtotal_dws_dom*harga_keluarga[2][0])+(subtotal_dws_inter*harga_keluarga[2][1]));
    }else {
        total=0;
    }
    return total;
}


void add_invalid2(){
    int pilihan;
    printf("\n\n\tEnter 1 untuk menu utama , 2 untuk menambahkan data lagi, 3 untuk membuat pesanan baru dan 0 untuk keluar : ");
    pilihan=validasiBil1();
    switch(pilihan){
        case 1:
            pesanan();
        break;
        case 2:
            dtpsn_tambah();
        break;
        case 3:
            tambahdata_psn();
        break;
        case 0:
            exit(1);
        break;
        default:
            printf("\nMaaf Kesalahan Input !");
            add_invalid2();
        break;

    }
}


/*void editdata(){
    int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("Data Wahana.txt","r");
	baru = fopen ("baru.txt","w");
	//system("cls");

	printf ("Masukan ID Wahana : ");
	cek.id=validasiBil1();
	while(fscanf (lama,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.jml_domestik,&tambah.jml_domestik,&tambah.prc_inter)!=EOF)
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
                pilih=validasiBil1();

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
        pilih=validasiBil1();
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
    pilihan=validasiBil1();
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
	while (fscanf (view,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
        printf("\t\t\t\-------------------------\n");
        printf("\n");
        printf("\t\t\tID Wahana               : %d\n", tambah.id);
        printf("\t\t\t\Nama Wahana            : %s\n", tambah.nama);
        printf("\t\t\tKategori                : %d\n", tambah.kategori);
        printf("\t\t\tHarga Domestik          : %d\n", tambah.prc_dom);
        printf("\t\t\tHarga Internasional     : %d\n", tambah.prc_dom);
        printf("\t\t\t-------------------------\n");
        printf("\n");
        printf("\n");
            test++;

	}
	printf ("\n\t\t\t\t\tJumlah Wahana : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
		printf ("\n\t\t\tData Kosong ! \n");
	}
        list_invalid();
}


void list_invalid(){
    int pilihan;
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    pilihan=validasiBil1();
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


/*void edit_valid(){
    int pilihan;
    printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
    pilihan=validasiBil1();
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

/*void hapusdata(){
    FILE *lama, *baru;
	int test=0;
	lama = fopen("Data Wahana.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input No. ID Wahana yang akan di hapus : ");
	scanf("%d", &hapus.id);
	while(fscanf (lama,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%d;%d;%d\n",tambah.id,tambah.nama,tambah.kategori,tambah.prc_dom,tambah.prc_inter);
		}
		else{
			test++;
			printf("\nData Wahana No ID : %d dengan Nama : %s\n",tambah.id,tambah.nama);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("Data Wahana.txt");
	rename("baru.txt","Data Wahana.txt");
    if(test==0){
        printf("\nData tidak ditemukan !\a\a\a");
        erase_invalid();
    }
    else{
    	erase_valid();
        }
}

void erase_invalid(){
    int pilihan;
    printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
    pilihan=validasiBil1();
    switch(pilihan){
    	case 0:
    	    hapusdata();
        break;
        case 1:
            wahanaAdmin();
        break;
        case 2:
            close();
        default:
            printf("\nMaaf Kesalahan Input !");
        	erase_invalid();
        break;
    }
}

void erase_valid(){
    int pilihan;
    printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
    pilihan=validasiBil1();
    switch(pilihan){
    	case 1:
    	    hapusdata();
        break;
        case 0:
            close();
        break;
        default:
            printf("\nMaaf Kesalahan Input !");
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
*/
