#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "./admin/crud_wahana.c"

//Variabel global
int jmlanak, jmldewasa, jmlkeluarga, jmldomestik, jmlinter;
int tiketjmlanak1, tiketjmlanak2, tiketjmlanak3;
int tiketjmldewasa1, tiketjmldewasa2, tiketjmldewasa3;
int tiketjmlkeluarga1, tiketjmlkeluarga2, tiketjmlkeluarga3;

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
        printf("\t\t\t\t||        ^.^  MAAF JUMLAH TIDAK VALID ^.^         ||\n");
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
    pesan1();
}
void pesan1(){
    int pilihan;

    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund Land                  |\n");
    printf("\t\t\t\t|                    PEMESANAN                    |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\tMasukkan Jumlah Golongan Pengunjung :\n\n");
    printf("\t\t\t\t1.Domestik \n");
    printf("\t\t\t\tMasukkan Jumlah Domestik : ");
    jmldomestik=validasiBil();
    printf("\t\t\t\t2.Internasional\n");
    printf("\t\t\t\tMasukkan Jumlah Internasional : ");
    jmlinter=validasiBil();
    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\n");
    system("cls");
    pesan2();

}

void pesan2(){
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund Land                  |\n");
    printf("\t\t\t\t|               PEMESANAN BAGIAN DUA              |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\tMasukkan Jumlah Golongan Pengunjung :\n\n");
    printf("\t\t\t\t1.Anak-Anak (< 17 tahun)\n");
    printf("\t\t\t\tMasukkan Jumlah Anak-Anak : ");
    jmlanak=validasiBil();
    printf("\t\t\t\t2.Dewasa\n");
    printf("\t\t\t\tMasukkan Jumlah Dewasa : ");
    jmldewasa=validasiBil();
    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\n");
   // system("cls");
    pesan3();
}

void pesan3(){
    int pilihan;
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                  LalaFund Land                  |\n");
    printf("\t\t\t\t|               PEMESANAN BAGIAN TIGA             |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t+-------------------------------------------------+\n");
    printf("\t\t\t\tPilihan Wahana :\n\n");
    printf("\t\t\t\t1.Anak-Anak (< 17 tahun)\n");
    printf("\t\t\t\t2.Dewasa\n");
    printf("\t\t\t\t3.Keluarga\n");
    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\t\t\t\tMasukkan Pilihan Wahana :");
    pilihan=validasiBil();
    showwahana(pilihan);
    printf("\n");
    //system("cls");

    /*switch (pilihan){
	    case 1:
            anak();
	    break;
        case 2:
            dewasa();
	    break;
	    case 3:
            keluarga();
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
            pesan3();
	 }
	 */
}



/*void anak(){
    int pilihan;

    printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");
    printf("\t\t\t\t|                                                                                                        |\n");
    printf("\t\t\t\t|                                              LalaFund Land                                             |\n");
    printf("\t\t\t\t|                                           PEMESANAN WAHANA ANAK                                        |\n");
    printf("\t\t\t\t|                                                                                                        |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\t|       KODE        |     KATEGORI      |     NAMA WAHANA     | HARGA(DOMESTIK) |  HARGA(INTERNASIONAL)  |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\t|         1         |    WAHANA AIR     |      WATERPARK      |   Rp.50.000     |       Rp.80.000        |\n");
    printf("\t\t\t\t|         2         | WAHANA ADVENTURE  | OUTBOND GAMES KIDS  |   Rp.80.000     |       Rp.100.000       |\n");
    printf("\t\t\t\t|         3         |  WAHANA BERMAIN   |     LalaFundPark    |   Rp.75.000     |       Rp.110.000       |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\tMasukkan Kode(0) Untuk Kembali\n");
    printf("\t\t\t\tMasukkan Pilihan Anda           :");
    pilihan=validasiBil();
    printf("\n");
    printf("\t\t\t\t==========================================================================================================\n");
    switch (pilihan){
        case 0:
            pesan3();
        break;
	    case 1:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 1:");
            tiketjmlanak1=validasiBil();
	    break;
        case 2:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 2:");
            tiketjmlanak2=validasiBil();
	    break;
	    case 3:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 3:");
            tiketjmlanak3=validasiBil();
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
            anak();
	 }

             konfiranak();
}
*/
/*void konfiranak(){
     int pilihan ;

     printf("\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||     Apakah Anda Ingin Menambah Tiket Anak?      ||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t1.Yes\n");
     printf("\t\t\t\t2.No\n");
     printf("\t\t\t\tMasukkan Pilihan Anda :");
     pilihan=validasiBil();
     printf("\t\t\t\t-------------------------------------------------\n");
     printf("\n");
     system("cls");

     switch (pilihan){
	 case 1:
             anak();
	     break;
         case 2:
             dewasa();
             break;
	 case 3:
	     printf("data");
	     keluarga();
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
             konfiranak();
	  }
}
*/

/*void dewasa(){
    int pilihan;

    printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");
    printf("\t\t\t\t|                                                                                                        |\n");
    printf("\t\t\t\t|                                              LalaFund Land                                             |\n");
    printf("\t\t\t\t|                                           PEMESANAN WAHANA DEWASA                                      |\n");
    printf("\t\t\t\t|                                                                                                        |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\t|       KODE        |     KATEGORI      |     NAMA WAHANA     | HARGA(DOMESTIK) |  HARGA(INTERNASIONAL)  |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\t|         1         |    WAHANA AIR     |     WATERPARK       |   Rp.100.000    |     Rp.150.000         |\n");
    printf("\t\t\t\t|                   |                   |     ARUNG JERAM     |   Rp.125.000    |     Rp.175.000         |\n");
    printf("\t\t\t\t|                   |                   |     SURF RIDER      |   Rp.50.000     |     Rp.85.000          |\n");
    printf("\t\t\t\t|                   |                   |     LAZY RIVER      |   Rp.45.000     |     Rp.75.000          |\n");
    printf("\t\t\t\t|         2         |  WAHANA ADVENTURE |     OUTBOND GAMES   |   Rp.110.000    |     Rp.145.000         |\n");
    printf("\t\t\t\t|                   |                   |     ATV RIDE        |   Rp.150.000    |     Rp.250.000         |\n");
    printf("\t\t\t\t|         3         |  WAHANA BERMAIN   |     LalaFundBOOM    |   Rp.80.000     |     Rp.120.000         |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\tMasukkan Kode(0) Untuk Kembali\n");
    printf("\t\t\t\tMasukkan Pilihan Anda           :");
    pilihan=validasiBil();
    printf("\n");
    printf("\t\t\t\t==========================================================================================================\n");
    switch (pilihan){
        case 0:
            pesan3();
        break;
	    case 1:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 1:");
            tiketjmldewasa1=validasiBil();
	    break;
        case 2:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 2:");
            tiketjmldewasa2=validasiBil();
	    break;
	    case 3:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 3:");
            tiketjmldewasa3=validasiBil();
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
            dewasa();
	 }

             konfirdewasa();
}
*/
/*void konfirdewasa(){
     int pilihan ;

     printf("\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||     Apakah Anda Ingin Menambah Tiket Dewasa?    ||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t1.Yes\n");
     printf("\t\t\t\t2.No\n");
     printf("\t\t\t\tMasukkan Pilihan Anda :");
     pilihan=validasiBil();
     printf("\t\t\t\t-------------------------------------------------\n");
     printf("\n");
     system("cls");

     switch (pilihan){
	 case 1:
             anak();
	     break;
         case 2:
             dewasa();
             break;
	 case 3:
	     printf("data");
	     keluarga();
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
             konfirdewasa();
	  }
}
*/

/*void keluarga(){
    int pilihan;

    printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");
    printf("\t\t\t\t|                                                                                                        |\n");
    printf("\t\t\t\t|                                              LalaFund Land                                             |\n");
    printf("\t\t\t\t|                                         PEMESANAN WAHANA KELUARGA                                      |\n");
    printf("\t\t\t\t|                                                                                                        |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\t|       KODE        |     KATEGORI      |     NAMA WAHANA     | HARGA(DOMESTIK) |  HARGA(INTERNASIONAL)  |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\t|         1         |    WAHANA AIR     |      WATERPARK      |   Rp.35.000     |       Rp.65.000        |\n");
    printf("\t\t\t\t|         2         | WAHANA ADVENTURE  |    OUTBOND Family   |   Rp.50.000     |       Rp.80.000        |\n");
    printf("\t\t\t\t|         3         |  WAHANA BERMAIN   |     LalaFundFam     |   Rp.55.000     |       Rp.85.000        |\n");
    printf("\t\t\t\t+-------------------+-------------------+---------------------+-----------------+------------------------+\n");
    printf("\t\t\t\tMasukkan Kode(0) Untuk Kembali\n");
    printf("\t\t\t\tMasukkan Pilihan Anda           :");
    pilihan=validasiBil();
    printf("\n");
    printf("\t\t\t\t==========================================================================================================\n");
    switch (pilihan){
        case 0:
            pesan3();
        break;
	    case 1:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 1:");
            tiketjmlkeluarga1=validasiBil();
	    break;
        case 2:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 2:");
            tiketjmlkeluarga2=validasiBil();
	    break;
	    case 3:
            printf("\t\t\t\tMasukkan Jumlah Tiket pada Kode 3:");
            tiketjmlkeluarga3=validasiBil();
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
            keluarga();
	 }

             konfirkeluarga();
}
*/
/*void konfirkeluarga(){
     int pilihan ;

     printf("\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||                  PEMBERITAHUAN                  ||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||     Apakah Anda Ingin Menambah Tiket Keluarga?  ||\n");
     printf("\t\t\t\t||                                                 ||\n");
     printf("\t\t\t\t||=================================================||\n");
     printf("\t\t\t\t1.Yes\n");
     printf("\t\t\t\t2.No\n");
     printf("\t\t\t\tMasukkan Pilihan Anda :");
     pilihan=validasiBil();
     printf("\t\t\t\t-------------------------------------------------\n");
     printf("\n");
     system("cls");

     switch (pilihan){
	 case 1:
             anak();
	     break;
         case 2:
             dewasa();
             break;
	 case 3:
	     printf("data");
	     keluarga();
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
             konfirkeluarga();
	  }
}
*/



