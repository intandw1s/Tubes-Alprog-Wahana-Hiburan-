#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "menu_utama.c"

//variabel global
int psn_id;


const char* nm_wahana(int id_wahana){
    char*wahana_name;
    int total;

    if(!strcmp(id_wahana, "11")){
        wahana_name="Waterpark";
    }else if(!strcmp(id_wahana, "12")){
        wahana_name="Outbound Games Kids";
    }else if(!strcmp(id_wahana, "13")){
        wahana_name="LalaFundPark";
    }else if(!strcmp(id_wahana, "21")){
        wahana_name="Waterpark";
    }else if(!strcmp(id_wahana, "22")){
        wahana_name="Arung Jeram";
    }else if(!strcmp(id_wahana, "23")){
        wahana_name="Surf Rider";
    }else if(!strcmp(id_wahana, "24")){
        wahana_name="Lazy River";
    }else if(!strcmp(id_wahana, "25")){
        wahana_name="Outbound Games";
    }else if(!strcmp(id_wahana, "26")){
        wahana_name="ATV Ride";
    }else if(!strcmp(id_wahana, "27")){
        wahana_name="LalaFundBOOM";
    }else if(!strcmp(id_wahana, "31")){
        wahana_name="Waterpark";
    }else if(!strcmp(id_wahana, "32")){
        wahana_name="Outbound Family";
    }else if(!strcmp(id_wahana, "33")){
        wahana_name="LalaFundFam";
    }else {
        total=0;
    }
    return wahana_name;

}


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



struct tb_pemesanan {
	int id_psn;
	char nama_psn[30];

}tambah_psn,cek_psn,hapus_psn,sort_psn[100],temp_psn;

struct dt_pemesanan {
	int id_det_psn;
	int id_pemesanan;
	char id_wahana[100];
	char* nama_whn;
	int subtotal_anak_dom;
    int subtotal_anak_inter;
	int subtotal_dws_dom;
    int subtotal_dws_inter;
	int subtotal_harga;

}tambah_dtpsn,cek_dtpsn,hapus_dtpsn,sort_dtpsn[100],temp_dtpsn;



float validasibilangan(){
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
        printf("\t\t\t\t||       ^_^ MAAF MASUKKAN ANDA TIDAK VALID ^_^    ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t  Silahkan Masukkan Ulang : ");
        validasibilangan();
    }else{
        val = atof(angka);
        return val;
    }
}

void pesanan(){
    int pilihan;
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund  Land                 |\n");
    printf("\t\t\t\t|                     Pemesanan                   |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tPilihan Tabel Pemesanan :\n\n");
    printf("\n\t\t\t\t[1] Tambah Data Pemesanan");
    printf("\n\t\t\t\t[2] Tambah Data Detail Pemesanan");
    printf("\n\t\t\t\t[3] Edit Data Pemesanan");
    printf("\n\t\t\t\t[4] Edit Data Detail Pemesanan");
    printf("\n\t\t\t\t[5] Lihat Data Pemesanan");
    printf("\n\t\t\t\t[6] Cetak Data Pemesanan");
    printf("\n\t\t\t\t[7] Hapus Data Pemesanan");
    printf("\n\t\t\t\t[8] Hapus Data Detail Pemesanan");
    printf("\n\t\t\t\t[9] Kembali");
    printf("\n\t\t\t\t[0] Keluar");
    printf("\n\t\t\t\t--------------------------------------------------\n");
    printf("\t\t\t\tMasukkan Pilihan Anda :");
    pilihan=validasibilangan();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
            tambahdata_psn();
	    break;
        case 2:
            dtpsn_tambah();
	    break;
	    case 3:
            editdata_psn();
        break;
        case 4:
            editdatadt_psn();
        break;
        case 5:
            lihatdata_psn();
        break;
        case 6:
            cetakdata_psn();
        break;
        case 7:
            hapusdata_psn();
        break;
        case 8:
            hapusdatadt_psn();
        break;
        case 9:
            menu();
        break;
        case 0:
            printf("\t\t\t\t+=================================================+\n");
            printf("\t\t\t\t|                     PROGRAM                     |\n");
            printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
            printf("\t\t\t\t|.................................................|\n");
            printf("\t\t\t\t|    ^o^ TERIMAKASIH ATAS KERJA KERAS ANDA ^v^    |\n");
            printf("\t\t\t\t+=================================================+\n\n");
            exit(1);
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
        printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                                                 |\n");
        printf("\t\t\t\t|                   LalaFund Land                 |\n");
        printf("\t\t\t\t+-------------------------------------------------+\n");
        printf("\t\t\t\t|             M E N U  P E M E S A N A N          |\n");
        printf("\t\t\t\t|                                                 |\n");
        printf("\t\t\t\t+=================================================+\n");
		printf("\t\t\t\tMasukan Nama Pemesan : ");fflush(stdin);
        scanf ("%[^\n]",tambah_psn.nama_psn);

		fprintf(ptr,"%d;%s;\n",tambah_psn.id_psn,tambah_psn.nama_psn);
		psn_id=tambah_psn.id_psn;
		fclose(ptr);
        printf("\n\n\t\t\t\t+..................................................+\n");
		printf("\t\t\t\t(✿◕‿◕✿) Data Pemesanan Sudah Disimpan (✿◕‿◕✿)");
		add_done();
}


void add_done(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\t\t\t\t Masukkan '1' untuk ke menu selanjutnya : ");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            dtpsn_tambah();
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
            add_done();
        break;

    }
}

void dtpsn_tambah(){
    FILE *ptr,*ptr1;
	int count=0;
    int subtotal;
    int id_psn;
    char whn_id;
    char *wahana_id;
    tambah_dtpsn.id_det_psn=1;
	ptr =fopen("Data Detail Pemesanan.txt","a");
		system("cls");
		ptr1 =fopen("Data Detail Pemesanan.txt","r");
		while (fscanf(ptr1,"%d;%d;%d;%d;%d;%d;%d;%[^\n];%[^\n]\n",&tambah_dtpsn.id_det_psn,&tambah_dtpsn.id_pemesanan,&tambah_dtpsn.subtotal_anak_dom,&tambah_dtpsn.subtotal_anak_inter,&tambah_dtpsn.subtotal_dws_dom,&tambah_dtpsn.subtotal_dws_inter,&tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn)!=EOF)
		{
			tambah_dtpsn.id_det_psn++;
		}
		cek_dtpsn.id_det_psn = tambah_dtpsn.id_det_psn;
		fclose(ptr1);
		printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                                                 |\n");
        printf("\t\t\t\t|                   LalaFund Land                 |\n");
        printf("\t\t\t\t+-------------------------------------------------+\n");
        printf("\t\t\t\t|         D E T A I L   P E M E S A N A N         |\n");
        printf("\t\t\t\t|                                                 |\n");
        printf("\t\t\t\t+=================================================+\n");
		printf ("\t\t\t\tMasukkan ID Pemesanan : ");
		fflush(stdin);
		tambah_dtpsn.id_pemesanan = validasibilangan();
		printf ("\t\t\t\tMasukan ID Wahana : ");
		fflush(stdin);
        scanf ("%[^\n]",tambah_dtpsn.id_wahana);
		printf ("\t\t\t\tMasukkan Jumlah Anak Domestik : ");
		fflush(stdin);
		tambah_dtpsn.subtotal_anak_dom=validasibilangan();
		printf ("\t\t\t\tMasukkan Jumlah Anak Internasional: ");
		fflush(stdin);
		tambah_dtpsn.subtotal_anak_inter=validasibilangan();
		printf ("\t\t\t\tMasukkan Jumlah Dewasa Domestik : ");
		fflush(stdin);
		tambah_dtpsn.subtotal_dws_dom=validasibilangan();
		printf ("\t\t\t\tMasukkan Jumlah Dewasa Internasional : ");
		fflush(stdin);
		tambah_dtpsn.subtotal_dws_inter=validasibilangan();

		subtotal= calstotal(tambah_dtpsn.id_wahana,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
		tambah_dtpsn.subtotal_harga = subtotal;
		wahana_id=nm_wahana(tambah_dtpsn.id_wahana);
		tambah_dtpsn.nama_whn = wahana_id;
		fprintf(ptr,"%d;%d;%d;%d;%d;%d;%d;%s;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
		id_psn = tambah_dtpsn.id_pemesanan;
		fclose(ptr);

		struk_1(id_psn);
        printf("\n\n\t\t\t\t+.................................................+\n");
		printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
		add_done2();
}


int calstotal(char*id_wahana,int subtotal_anak_dom,int subtotal_anak_inter,int subtotal_dws_dom,int subtotal_dws_inter){
    int total;
    if(!strcmp(id_wahana, "11")){
        total=((subtotal_anak_dom*harga_anak[0][0])+(subtotal_anak_inter*harga_anak[0][1]));
    }else if(!strcmp(id_wahana,"12")){
        total=((subtotal_anak_dom*harga_anak[1][0])+(subtotal_anak_inter*harga_anak[1][1]));
    }else if(!strcmp(id_wahana,"13")){
        total=((subtotal_anak_dom*harga_anak[2][0])+(subtotal_anak_inter*harga_anak[2][1]));
    }else if(!strcmp(id_wahana,"21")){
        total=((subtotal_dws_dom*harga_dewasa[0][0])+(subtotal_dws_inter*harga_dewasa[0][1]));
    }else if(!strcmp(id_wahana,"22")){
        total=((subtotal_dws_dom*harga_dewasa[1][0])+(subtotal_dws_inter*harga_dewasa[1][1]));
    }else if(!strcmp(id_wahana,"23")){
        total=((subtotal_dws_dom*harga_dewasa[2][0])+(subtotal_dws_inter*harga_dewasa[2][1]));
    }else if(!strcmp(id_wahana,"24")){
        total=((subtotal_dws_dom*harga_dewasa[3][0])+(subtotal_dws_inter*harga_dewasa[3][1]));
    }else if(!strcmp(id_wahana,"25")){
        total=((subtotal_dws_dom*harga_dewasa[4][0])+(subtotal_dws_inter*harga_dewasa[4][1]));
    }else if(!strcmp(id_wahana,"26")){
        total=((subtotal_dws_dom*harga_dewasa[5][0])+(subtotal_dws_inter*harga_dewasa[5][1]));
    }else if(!strcmp(id_wahana,"27")){
        total=((subtotal_dws_dom*harga_dewasa[6][0])+(subtotal_dws_inter*harga_dewasa[6][1]));
    }else if(!strcmp(id_wahana,"31")){
        total=((subtotal_anak_dom*harga_keluarga[0][0])+(subtotal_anak_inter*harga_keluarga[0][1])+(subtotal_dws_dom*harga_keluarga[0][0])+(subtotal_dws_inter*harga_keluarga[0][1]));
    }else if(!strcmp(id_wahana,"32")){
        total=((subtotal_anak_dom*harga_keluarga[1][0])+(subtotal_anak_inter*harga_keluarga[1][1])+(subtotal_dws_dom*harga_keluarga[1][0])+(subtotal_dws_inter*harga_keluarga[1][1]));
    }else if(!strcmp(id_wahana,"33")){
        total=((subtotal_anak_dom*harga_keluarga[2][0])+(subtotal_anak_inter*harga_keluarga[2][1])+(subtotal_dws_dom*harga_keluarga[2][0])+(subtotal_dws_inter*harga_keluarga[2][1]));
    }else {
        total=0;
    }
    return total;
}


void add_done2(){
    int pilihan;
    printf("\n\t\t\t\t+.................................................+\n");
    printf("\n\t\t\t\t[1] Menambah Pesanan");
    printf("\n\t\t\t\t[2] Menu Utama      ");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\n\n\t\t\t\tMasukkan Pilihan Anda  : ");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            dtpsn_tambah();
        break;
        case 2:
            printf("\t\t\t\t+=================================================+\n");
            printf("\t\t\t\t|                     PEMESANAN                   |\n");
            printf("\t\t\t\t|                  TELAH BERHASIL                 |\n");
            printf("\t\t\t\t|.................................................|\n");
            printf("\t\t\t\t|           ^o^ STRUK SIAP DI PRINT ^v^           |\n");
            printf("\t\t\t\t+=================================================+\n\n");
            system("pause");
            system("cls");
            pesanan();
        break;
        case 0:
            printf("\t\t\t\t+=================================================+\n");
            printf("\t\t\t\t|                     PEMESANAN                   |\n");
            printf("\t\t\t\t|                  TELAH BERHASIL                 |\n");
            printf("\t\t\t\t|.................................................|\n");
            printf("\t\t\t\t|           ^o^ STRUK SIAP DI PRINT ^v^           |\n");
            printf("\t\t\t\t+=================================================+\n\n");
            system("pause");
            system("cls");
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
            add_done2();
        break;

    }
}


/*void invoice(){
    fprintf(fPointer,"\t\t\t+========================================================================+\n");
    fprintf(fPointer,"\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer,"\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer,"\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer,"\t\t\t+========================================================================+\n\n");
    fprintf(fPointer,"\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer,"\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer,"\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer,"\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer,"\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer,"\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer,"\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD11 (struk[2]);
    fprintf(fPointer,"\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer,"\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer,"\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer,"\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer,"\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer,"\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer,"\t\t\t=========================================================================\n");
    fprintf(fPointer,"\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer,"\t\t\t-------------------------------------------------------------------------\n");


}*/

void struk_1(int pemesanan){
    int pilih,test=0;
    int total;
    char *wahana_id;
    char whn_id[100];
    int subtotal;
    int n=1;
    time_t mytime;
	time(&mytime);
	FILE *lama,*lama1,*baru,*baru1;
	lama = fopen("Data Detail Pemesanan.txt","r");
    lama1 = fopen("Data Pemesanan.txt","r");
	baru = fopen("struk pembayaran.txt","w");
	baru1 = fopen("struk pembayaran.txt","a");
	system("cls");
	printf("%d", pemesanan);
	cek_dtpsn.id_pemesanan = pemesanan;
	cek_psn.id_psn = pemesanan;
	fprintf(baru,"\t\t\t\t+========================================================================+\n");
    fprintf(baru,"\t\t\t\t|                              LalaFund Land                             |\n");
    fprintf(baru,"\t\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(baru,"\t\t\t\t|                       B U K T I  P E M B A Y A R A N                   |\n");
    fprintf(baru,"\t\t\t\t+========================================================================+\n\n");
    fprintf(baru,"\t\t\t\t %3s", ctime(&mytime));

	while(fscanf (lama,"%d;%d;%d;%d;%d;%d;%d;%[^\n];%[^\n]\n",&tambah_dtpsn.id_det_psn,&tambah_dtpsn.id_pemesanan,&tambah_dtpsn.subtotal_anak_dom,&tambah_dtpsn.subtotal_anak_inter,&tambah_dtpsn.subtotal_dws_dom,&tambah_dtpsn.subtotal_dws_inter,&tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn)!=EOF)
	{
        while (fscanf (lama1,"%d;%[^;];\n",&tambah_psn.id_psn,tambah_psn.nama_psn)!=EOF)
		{
			if (tambah_psn.id_psn==cek_psn.id_psn){
                /*fprintf(baru,"\n%s", ctime(&mytime));
                fprintf(baru,"\t\t\t ID Pemesanan      : %d\n", tambah_psn.id_psn);
                fprintf(baru,"\t\t\t Nama Pemesan      : %s\n", tambah_psn.nama_psn);*/
                fprintf(baru,"\t\t\t ID Pemesanan       : %d\n", tambah_psn.id_psn);
                fprintf(baru,"\t\t\t Nama Pemesan       : %s\n", tambah_psn.nama_psn);
			}


		}
		if (tambah_dtpsn.id_pemesanan==cek_dtpsn.id_pemesanan){
           /*fprintf(baru1,"\t\t\t ID Detail Pemesanan      : %d\n", tambah_dtpsn.id_det_psn);
           fprintf(baru1,"\t\t\t ID Pemesanan             : %d\n", tambah_dtpsn.id_pemesanan);
           fprintf(baru1,"\t\t\t Nama Wahana              : %s\n", tambah_dtpsn.nama_whn);
           fprintf(baru1,"\t\t\t Subtotal                 : %d\n", tambah_dtpsn.subtotal_harga);*/
           strncpy(whn_id,tambah_dtpsn.id_wahana,2);
           whn_id[2] = '\0';
           wahana_id=nm_wahana(whn_id);
           tambah_dtpsn.nama_whn = wahana_id;
           subtotal= calstotal(whn_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
           tambah_dtpsn.subtotal_harga = subtotal;
           fprintf(baru1,"\t\t\t ID Detail Pemesanan    : %d\n", tambah_dtpsn.id_det_psn);
           fprintf(baru1,"\t\t\t ID Pemesanan           : %d\n", tambah_dtpsn.id_pemesanan);
           fprintf(baru1,"\t\t\t Nama Wahana            : %s\n", tambah_dtpsn.nama_whn);
           fprintf(baru1,"\t\t\t Subtotal Harga         : %d\n", tambah_dtpsn.subtotal_harga);
           fprintf(baru1,"\t\t\t.........................................................................\n");
           test++;
           total+= tambah_dtpsn.subtotal_harga;
           n++;
		}

    }
           total = total - n;
           fprintf(baru1,"\t\t\t\t Total                    : %d\n", total);
    fprintf(baru1,"\t\t\t\t=========================================================================\n");
    fprintf(baru1,"\t\t\t\t                ^o^ THANKYOU & ENJOY YOUR DAY IN  ^v^                    \n");
    fprintf(baru1,"\t\t\t\t                      L A L A F U N D  L A N D                           \n");
    fprintf(baru1,"\t\t\t\t=========================================================================\n");
    fclose(lama);
	fclose(baru);
	if(test > 0){
        printf("Mantap");
	}

}

void editdata_psn(){
    int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("Data Pemesanan.txt","r");
	baru = fopen ("Data Pemesanan Update.txt","w");
	//system("cls");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|             E D I T   P E M E S A N A N         |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n");
	printf("\t\t\t\tMasukan ID Pemesanan : ");
	cek_psn.id_psn=validasibilangan();
	while(fscanf (lama,"%d;%[^;];\n",&tambah_psn.id_psn,tambah_psn.nama_psn)!=EOF)
	{
		if(tambah_psn.id_psn == cek_psn.id_psn){
			test=1;
			ganti:
                printf("\t\t\t\t+-------------------------------------------------+\n");
                printf("\t\t\t\tID Pemesanan : %d  ||  Pemesan dengan Nama : %s",tambah_psn.id_psn,tambah_psn.nama_psn);
				printf("\n\n\t\t\t\tData yang akan diganti : ");
				printf("\n\t\t\t\t[1]. Nama Pengguna");
                printf("\t\t\t\t+-------------------------------------------------+\n");
				printf("\n\t\t\t\tMasukkan Pilihan Anda  : ");
                pilih=validasibilangan();

				if(pilih == 1)
				{
                    printf("\n\t\t\t\t...................................................\n");
					printf("\t\t\t\tMasukan Nama Pemesan Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek_psn.nama_psn);
					strcpy(tambah_psn.nama_psn,cek_psn.nama_psn);
                    fprintf(baru,"%d;%s;\n",tambah_psn.id_psn,tambah_psn.nama_psn);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
				}else{

                    printf("\t\t\t\t||=================================================||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||=================================================||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||=================================================||\n");
                    editdata_psn();
				}
		}
		else
		{
			fprintf(baru,"%d;%s;\n",tambah_psn.id_psn,tambah_psn.nama_psn);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("Data Pemesanan.txt");
	rename("Data Pemesanan Update.txt","Data Pemesanan.txt");
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
            edit_psninvalid();
        }
    else{
    	edit_psnvalid();
        }
    }

void edit_psninvalid(){
    int pilih;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Silahkan Ulangi");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/0] :");
    pilih=validasibilangan();
    switch(pilih){
        case 1:
            editdata_psn();
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
            edit_psninvalid();
        break;
    }
}

void edit_psnvalid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Edit Detail ");
    printf("\n\t\t\t\t[2] Mengedit Pemesanan Lagi");
    printf("\n\t\t\t\t[3] Menu Utama");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/2/3/0] :");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            editdatadt_psn();
        break;
        case 2:
            editdata();
        break;
        case 3:
            pesanan();
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
            edit_psnvalid();
        break;
    }
}

void editdatadt_psn(){
    int pilih,test=0;
    int subtotal;
    int id_psn;
    char whn_id[100];
    char *wahana_id;
	FILE *lama,*baru;
	lama = fopen("Data Detail Pemesanan.txt","r");
	baru = fopen ("Data Detail Pemesanan Update.txt","w");
	//system("cls");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|      E D I T  D E T A I L  P E M E S A N A N    |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n");
	printf("\t\t\t\tMasukan ID Detail Pemesanan : ");
	cek_dtpsn.id_det_psn=validasibilangan();
	while(fscanf (lama,"%d;%d;%d;%d;%d;%d;%d;%[^\n];%[^\n]\n",&tambah_dtpsn.id_det_psn,&tambah_dtpsn.id_pemesanan,&tambah_dtpsn.subtotal_anak_dom,&tambah_dtpsn.subtotal_anak_inter,&tambah_dtpsn.subtotal_dws_dom,&tambah_dtpsn.subtotal_dws_inter,&tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn)!=EOF)
	{
		if(tambah_dtpsn.id_det_psn == cek_dtpsn.id_det_psn){
            test=1;
            ganti:
                printf("\t\t\t\t+-------------------------------------------------+\n");
				printf("\t\t\t\tID Detail Pemesanan : %d  || ID Pemesanan : %d",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan);
				printf("\n\n\t\t\t\tData yang akan diganti : ");
				printf("\n\t\t\t\t[1]. Id Pemesanan");
                printf("\n\t\t\t\t[2]. Id Wahana");
				printf("\n\t\t\t\t[3]. Jumlah Anak   [Domestik]");
				printf("\n\t\t\t\t[4]. Jumlah Anak   [Internasional]");
				printf("\n\t\t\t\t[5]. Jumlah Dewasa [Domestik] ");
				printf("\n\t\t\t\t[6]. Jumlah Dewasa [Internasional]");
				printf("\n\t\t\t\tMasukkan Pilihan Anda    : ");
                pilih=validasibilangan();

				if(pilih == 1)
				{
                    printf("\n\t\t\t\t...................................................\n");
                    printf("\n\t\t\t\tMasukan ID Pemesanan Baru            : ");
                    fflush(stdin);
					scanf ("%d",&cek_dtpsn.id_pemesanan);
                    tambah_dtpsn.id_pemesanan = cek_dtpsn.id_pemesanan;
                    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
				}else if (pilih == 2)
				{
                    printf("\n\t\t\t\t...................................................\n");
                    printf ("\n\t\t\t\tMasukan ID Wahana Baru              : ");
                    fflush(stdin);
					scanf ("%[^\n]",cek_dtpsn.id_wahana);
					strcpy(tambah_dtpsn.id_wahana,cek_dtpsn.id_wahana);
					wahana_id=nm_wahana(tambah_dtpsn.id_wahana);
                    tambah_dtpsn.nama_whn = wahana_id;
                    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
				}else if (pilih == 3)
				{
                    printf("\n\t\t\t\t...................................................\n");
					printf("\nMasukan Jumlah Anak [Domestik]       : ");fflush(stdin);
					cek_dtpsn.subtotal_anak_dom=validasibilangan();
					tambah_dtpsn.subtotal_anak_dom = cek_dtpsn.subtotal_anak_dom;
					//whn_id = tambah_dtpsn.id_wahana;
					strncpy(whn_id,tambah_dtpsn.id_wahana,2);
					whn_id[2] = '\0';
					subtotal= calstotal(whn_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
                    tambah_dtpsn.subtotal_harga = subtotal;
                    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
				}else if (pilih == 4)
				{
                    printf("\n\t\t\t\t...................................................\n");
					printf("\nMasukan Jumlah Anak [Internasional]   : ");fflush(stdin);
					cek_dtpsn.subtotal_anak_inter=validasibilangan();
					tambah_dtpsn.subtotal_anak_inter = cek_dtpsn.subtotal_anak_inter;
					strncpy(whn_id,tambah_dtpsn.id_wahana,2);
					whn_id[2] = '\0';
					subtotal= calstotal(whn_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
                    tambah_dtpsn.subtotal_harga = subtotal;
                    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
				}else if (pilih == 5)
				{
                    printf("\n\t\t\t\t...................................................\n");
					printf("\nMasukan Jumlah Dewasa [Domestik]      : ");fflush(stdin);
                    cek_dtpsn.subtotal_dws_dom=validasibilangan();
					tambah_dtpsn.subtotal_dws_dom=cek_dtpsn.subtotal_dws_dom;
                    strncpy(whn_id,tambah_dtpsn.id_wahana,2);
					whn_id[2] = '\0';
					subtotal= calstotal(whn_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
                    tambah_dtpsn.subtotal_harga = subtotal;
                    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
				}else if (pilih == 6)
				{
                    printf("\n\t\t\t\t...................................................\n");
					printf("\nMasukan Jumlah Dewasa [Internasional] : ");fflush(stdin);
					cek_dtpsn.subtotal_dws_inter=validasibilangan();
					tambah_dtpsn.subtotal_dws_inter=cek_dtpsn.subtotal_dws_inter;
                    strncpy(whn_id,tambah_dtpsn.id_wahana,2);
					whn_id[2] = '\0';
					subtotal= calstotal(whn_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
                    tambah_dtpsn.subtotal_harga = subtotal;
                    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
                    printf("\n\t\t\t\t+..................................................+\n");
                    printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah Disimpan (✿◕‿◕✿)");
				}else{
                    printf("\t\t\t\t||=================================================||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||=================================================||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U          ||\n");
                    printf("\t\t\t\t||                                                 ||\n");
                    printf("\t\t\t\t||=================================================||\n");
					editdatadt_psn();
				}
				id_psn = tambah_dtpsn.id_pemesanan;
                struk_1(id_psn);

		}else
		{
                    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
		}

	}

    //printf("%d;%d;%s;\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga);
	fclose(lama);
	fclose(baru);
	remove("Data Detail Pemesanan.txt");
	rename("Data Detail Pemesanan Update.txt","Data Detail Pemesanan.txt");
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
        editdt_invalid();
        }
    else{
    	editdt_valid();
        }
}

void editdt_invalid(){
    int pilih;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Silahkan Ulangi");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/0] :");
    pilih=validasibilangan();
    switch(pilih){
        case 1:
            editdatadt_psn();
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH    U_U        ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            editdt_invalid();
        break;
        }
}

void editdt_valid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Edit Detail Lagi ");
    printf("\n\t\t\t\t[2] Edit Pemesanan ");
    printf("\n\t\t\t\t[3] Menu Utama");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/2/3/0] :");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            editdatadt_psn();
        break;
        case 2:
            editdata();
        break;
        case 3:
            pesanan();
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U         ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            editdt_valid();
        break;
    }
}

void lihatdata_psn(){
    int pilih,test=0;
    int total;
    char *wahana_id;
    char whn_id[100];
    int subtotal;
    time_t mytime;
	time(&mytime);
	FILE *lama,*lama1;
	lama = fopen("Data Detail Pemesanan.txt","r");
    lama1 = fopen("Data Pemesanan.txt","r");
	system("cls");

    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|            D A T A   P E M E S A N A N          |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n\n");
    printf("\t\t\t\t %s", ctime(&mytime));
    printf("\n\t\t\t\t||------------------------------------------------||\n");
    printf("\t\t\t\t                   Data Transaksi                   \n");
    printf("\t\t\t\t||------------------------------------------------||\n");

    while (fscanf (lama1,"%d;%[^;];\n",&tambah_psn.id_psn,tambah_psn.nama_psn)!=EOF)
    {

                printf("\n");
                printf("\t\t\t\t ID Pemesanan      : %d\n", tambah_psn.id_psn);
                printf("\t\t\t\t Nama Pemesan      : %s\n", tambah_psn.nama_psn);
                printf("\n");


    }
    printf("\n\n\t\t\t\t||------------------------------------------------||\n");
    printf("\t\t\t\t                 Data Detail Transaksi              \n");
    printf("\t\t\t\t||------------------------------------------------||\n");
	while(fscanf (lama,"%d;%d;%d;%d;%d;%d;%d;%[^\n];%[^\n]\n",&tambah_dtpsn.id_det_psn,&tambah_dtpsn.id_pemesanan,&tambah_dtpsn.subtotal_anak_dom,&tambah_dtpsn.subtotal_anak_inter,&tambah_dtpsn.subtotal_dws_dom,&tambah_dtpsn.subtotal_dws_inter,&tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn)!=EOF)
	{

           strncpy(whn_id,tambah_dtpsn.id_wahana,2);
           whn_id[2] = '\0';
           wahana_id=nm_wahana(whn_id);
           tambah_dtpsn.nama_whn = wahana_id;
           subtotal= calstotal(whn_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
           tambah_dtpsn.subtotal_harga = subtotal;

           printf("\t\t\t\t ID Detail Pemesanan    : %d\n", tambah_dtpsn.id_det_psn);
           printf("\t\t\t\t ID Pemesanan           : %d\n", tambah_dtpsn.id_pemesanan);
           printf("\t\t\t\t Nama Wahana            : %s\n", tambah_dtpsn.nama_whn);
           printf("\t\t\t\t Subtotal Harga         : %d\n", tambah_dtpsn.subtotal_harga);
           printf("\n");

           test=1;
           //total+= tambah_dtpsn.subtotal_harga-1;


    }
           //printf("\t\t\t Total                    : %d\n", total);

    fclose(lama);
	fclose(lama1);
	if(test == 1){
        printf("Mantap");
	}


}

void cetakdata_psn(){
    int pilih,test=0;
    int total;
    char *wahana_id;
    char whn_id[100];
    int subtotal;
    time_t mytime;
	time(&mytime);
	FILE *lama,*lama1,*baru;
	lama = fopen("Data Detail Pemesanan.txt","r");
    lama1 = fopen("Data Pemesanan.txt","r");
    baru = fopen("Riwayat Pemesanan.txt","w");
	system("cls");
    fprintf(baru,"\t\t\t\t+=================================================+\n");
    fprintf(baru,"\t\t\t\t|                                                 |\n");
    fprintf(baru,"\t\t\t\t|                   LalaFund Land                 |\n");
    fprintf(baru,"\t\t\t\t+-------------------------------------------------+\n");
    fprintf(baru,"\t\t\t\t|            D A T A   P E M E S A N A N          |\n");
    fprintf(baru,"\t\t\t\t|                                                 |\n");
    fprintf(baru,"\t\t\t\t+=================================================+\n\n");
    fprintf(baru,"\t\t\t\t %s", ctime(&mytime));
    fprintf(baru,"\n\t\t\t\t||------------------------------------------------||\n");
    fprintf(baru,"\t\t\t\t                   Data Transaksi                   \n");
    fprintf(baru,"\t\t\t\t||------------------------------------------------||\n");
    while (fscanf (lama1,"%d;%[^;];\n",&tambah_psn.id_psn,tambah_psn.nama_psn)!=EOF)
    {

                fprintf(baru,"\t\t\t ID Pemesanan      : %d\n", tambah_psn.id_psn);
                fprintf(baru,"\t\t\t Nama Pemesan      : %s\n", tambah_psn.nama_psn);
                fprintf(baru,"\n");



    }

    fprintf(baru,"\n\t\t\t\t||------------------------------------------------||\n");
    fprintf(baru,"\t\t\t\t                Data Detail Transaksi                 \n");
    fprintf(baru,"\t\t\t\t||------------------------------------------------||\n");
    while(fscanf (lama,"%d;%d;%d;%d;%d;%d;%d;%[^\n];%[^\n]\n",&tambah_dtpsn.id_det_psn,&tambah_dtpsn.id_pemesanan,&tambah_dtpsn.subtotal_anak_dom,&tambah_dtpsn.subtotal_anak_inter,&tambah_dtpsn.subtotal_dws_dom,&tambah_dtpsn.subtotal_dws_inter,&tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn)!=EOF)
	{

           strncpy(whn_id,tambah_dtpsn.id_wahana,2);
           whn_id[2] = '\0';
           wahana_id=nm_wahana(whn_id);
           tambah_dtpsn.nama_whn = wahana_id;
           subtotal= calstotal(whn_id,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter);
           tambah_dtpsn.subtotal_harga = subtotal;
           //printf("\n\n\t\t\t Data Detail Transaksi \n\n");
           fprintf(baru,"\t\t\t\tID Detail Pemesanan   : %d\n", tambah_dtpsn.id_det_psn);
           fprintf(baru,"\t\t\t\tID Pemesanan          : %d\n", tambah_dtpsn.id_pemesanan);
           fprintf(baru,"\t\t\t\tNama Wahana           : %s\n", tambah_dtpsn.nama_whn);
           fprintf(baru,"\t\t\t\tSubtotal              : %d\n", tambah_dtpsn.subtotal_harga);
           fprintf(baru,"\n");
           test=1;
           //total+= tambah_dtpsn.subtotal_harga-1;


    }
           //printf("\t\t\t Total                    : %d\n", total);

    fclose(lama);
	fclose(lama1);
	//fclose(baru);
	if(test == 1){
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||           >,<  DATA SUDAH DICETAK   >,<         ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
	}


}

/*void lihatdatadt_psn(){
    FILE *view;
	view = fopen("Data Wahana.txt","r");
	int test=0;
	system ("cls");
	while (fscanf (view,"%d;%[^;];%d;%d;%d\n",&tambah.id,tambah.nama,&tambah.kategori,&tambah.prc_dom,&tambah.prc_inter)!=EOF)
	{
        printf("\t\t\t\--------------------------\n");
        printf("\n");
        printf("\t\t\tID Pemesanan              : %d\n", tambah.id);
        printf("\t\t\tNama Pemesan              : %d\n", tambah.id);
        printf("\t\t\tID Wahana                 : %d\n", tambah.id);
        printf("\t\t\tNama Wahana               : %s\n", tambah.nama);
        printf("\t\t\tJumlah Anak Domestik      : %d\n", tambah.prc_dom);
        printf("\t\t\tHarga Anak Internasional  : %d\n", tambah.prc_dom);
        printf("\t\t\tJumlah Dewasa Domestik    : %d\n", tambah.prc_dom);
        printf("\t\t\tHarga Dewasa Internasional: %d\n", tambah.prc_dom);
        printf("\t\t\t--------------------------\n");
        printf("\n");
        printf("\n");
            test++;

	}
	printf ("\n\t\t\t\t\tJumlah Pemesanan : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
		printf ("\n\t\t\tData Kosong ! \n");
	}
        list_invalid();
}

void list_invaliddt(){
    int pilihan;
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    pilihan=validasibilangan();
    switch(pilihan){
    	case 1:
    	    pesanan();
        break;
        case 0:
            exit(0);
        break;
        default:
            printf("\nMaaf Kesalahan Input !");
        	list_invalid();
        break;
    }
}*/

void hapusdata_psn(){
    FILE *lama, *baru;
	int test=0;
	lama = fopen("Data Pemesanan.txt","r");
	baru = fopen("Data Pemesanan Update.txt","w");
	system("cls");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|            H A P U S   P E M E S A N A N        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n\n");
	printf("\t\t\t\tSilahkan Masukkan ID Pemesanan yang akan di Hapus : ");
	scanf("%d", &hapus_psn.id_psn);
	while(fscanf (lama,"%d;%[^;];\n",&tambah_psn.id_psn,tambah_psn.nama_psn)!=EOF)
	{
		if(tambah_psn.id_psn != hapus_psn.id_psn)
		{
			fprintf(baru,"%d;%s;\n",tambah_psn.id_psn,tambah_psn.nama_psn);
		}
		else{
			test++;
            printf("\t\t\t\t+-------------------------------------------------+\n");
			printf("\n\t\t\t\tData Pemesanan No ID : %d ||  Nama Pemesan : %s\n",tambah_psn.id_psn,tambah_psn.nama_psn);
            printf("\t\t\t\t+-------------------------------------------------+\n");
            printf("\t\t\t\t(✿◕‿◕✿) Data Pemesanan Sudah Berhasil Terhapus dari Daftar (✿◕‿◕✿)");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("Data Pemesanan.txt");
	rename("Data Pemesanan Update.txt","Data Pemesanan.txt");
    if(test==0){
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||           U_U  DATA TIDAK DITEMUKAN  U_U        ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        hapus_invalid();
    }
    else{
    	hapus_valid();
        }
}

void hapus_invalid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Silahkan Ulangi");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/0] :");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            hapusdata_psn();
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH    U_U        ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
        	hapus_invalid();
        break;
    }
}

void hapus_valid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Hapus Data Next ");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/2/3/0] :");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            editdatadt_psn();
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U         ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
        	hapus_valid();
        break;
    }
}


void hapusdatadt_psn(){
    FILE *lama, *baru;
	int test=0;
	lama = fopen("Data Detail Pemesanan.txt","r");
	baru = fopen("Data Detail Pemesanan Update.txt","w");
	system("cls");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                   LalaFund Land                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|              H A P U S   D E T A I L            |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+=================================================+\n\n");
    printf("Silahkan Masukkan Detail ID Pemesanan yang akan di Hapus : ");
	scanf("%d", &hapus_dtpsn.id_det_psn);
	while(fscanf (lama,"%d;%d;%d;%d;%d;%d;%d;%[^\n];%[^\n]\n",&tambah_dtpsn.id_det_psn,&tambah_dtpsn.id_pemesanan,&tambah_dtpsn.subtotal_anak_dom,&tambah_dtpsn.subtotal_anak_inter,&tambah_dtpsn.subtotal_dws_dom,&tambah_dtpsn.subtotal_dws_inter,&tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn)!=EOF)
	{

		if(tambah_dtpsn.id_det_psn != hapus_dtpsn.id_det_psn)
		{
		    fprintf(baru,"%d;%d;%d;%d;%d;%d;%d;%s\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan,tambah_dtpsn.subtotal_anak_dom,tambah_dtpsn.subtotal_anak_inter,tambah_dtpsn.subtotal_dws_dom,tambah_dtpsn.subtotal_dws_inter,tambah_dtpsn.subtotal_harga,tambah_dtpsn.id_wahana,tambah_dtpsn.nama_whn);
		}
		else{
			test++;
            printf("\t\t\t\t+-------------------------------------------------+\n");
			printf("\n\t\t\t\tData Detail Pemesanan No ID : %d || ID Pemesanan : %d\n",tambah_dtpsn.id_det_psn,tambah_dtpsn.id_pemesanan);
            printf("\t\t\t\t+-------------------------------------------------+\n");
            printf("\t\t\t\t(✿◕‿◕✿) Data Detail Pemesanan Sudah  Berhasil Terhapus dari Daftar (✿◕‿◕✿)");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("Data Detail Pemesanan.txt");
	rename("Data Detail Pemesanan Update.txt","Data Detail Pemesanan.txt");
    if(test==0){
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||           U_U  DATA TIDAK DITEMUKAN  U_U        ||\n");
        printf("\t\t\t\t||                                                 ||\n");
        printf("\t\t\t\t||=================================================||\n");
        erase_dtinvalid();
    }
    else{
    	erase_dtvalid();
        }
}

void erase_dtinvalid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Ulangi Hapus Data Detail Lagi ");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/2/3/0] :");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            hapusdatadt_psn();
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
        	erase_dtinvalid();
        break;
    }
}

void erase_dtvalid(){
    int pilihan;
    printf("\n\t\t\t\t+..................................................+\n");
    printf("\n\t\t\t\t[1] Hapus Data Detail Lagi ");
    printf("\n\t\t\t\t[2] Hapus Pemesanan ");
    printf("\n\t\t\t\t[3] Menu Utama");
    printf("\n\t\t\t\t[0] Keluar          ");
    printf("\n\t\t\t\t+=================================================+\n");
    printf("\t\t\t\tSilahkan Masukkan Pilihan Anda [1/2/3/0] :");
    pilihan=validasibilangan();
    switch(pilihan){
        case 1:
            hapusdatadt_psn();
        break;
        case 2:
            hapusdata_psn();
        break;
        case 3:
            pesanan();
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
            printf("\t\t\t\t||           U_U  MAAF INPUTAN SALAH  U_U         ||\n");
            printf("\t\t\t\t||                                                 ||\n");
            printf("\t\t\t\t||=================================================||\n");
        	erase_dtvalid();
        break;
    }
}
/*int main(){
    pesanan();
}*/
