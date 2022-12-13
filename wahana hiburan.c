//Pemesanan Tiket Wahana Hiburan
//Ni Putu Adelia Candra Swari 2205551017
//Ni Made Intan Dwi Sukma 2205551030


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//FUNGSI VALIDASI
//Cek Pilihan
int validasimenu() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=50){ // PEMBATAS PADA ASCII DIMANA 49-50 BERNILAI "1-2"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Menu : ");
        validasimenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=2){
            return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Menu : ");
            validasimenu();
        }
    }
}


int validasimenu2() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=49){ // PEMBATAS PADA ASCII DIMANA 48-49 BERNILAI "0-1"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Menu : ");
        validasimenu2();
    }else{
        val = atoi(angka);
        if(val>=0 && val<=1){
            return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Menu : ");
            validasimenu2();
        }
    }
}

int validasipil() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
    if(angka[i]>=49 && angka[i]<=51){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "1-3"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Anda : ");
        validasipil();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
        return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Anda : ");
            validasipil();
        }
    }
}

int validasipil1() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
    if(angka[i]>=49 && angka[i]<=52){ // PEMBATAS PADA ASCII DIMANA 49-52 BERNILAI "1-4"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Anda : ");
        validasipil1();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
        return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Anda : ");
            validasipil1();
        }
    }
}

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
        printf("\nHARAP Masukkan BILANGAN YANG SESUAI\n");
        printf("Silahkan masukkan ulang : ");
        validasiBil();
    }else{
        val = atof(angka);
        return val;
    }
}

//MAIN
int main(){
    system("COLOR E8");
    daftar();
    system("pause");
    return 0;
}

void daftar(){

    int pilihan;
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|            Om swastyastu! Hi! Ni Hao!           |\n");
    printf("\t\t\t\t|              ^0^SELAMAT DATANG ^v^              |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|================ LalaFund Land ==================|\n");
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t             1. Registrasi  | 2. Login             \n");
    printf("\t\t\t\t---------------------------------------------------\n");
    printf("\t\t\t\t 1. Login \n");
    printf("\t\t\t\t 2. Registrasi \n");
    printf("\t\t\t\t---------------------------------------------------\n");
    printf("\n\t\t\t\tMasukkan Pilihan Anda(1/2) : ");
    pilihan = validasimenu();
    printf("\n");
    system("cls");

    switch (pilihan){
            case 1:
            login();
            break;
            default:
            regis();
            break;
    }

    return 0;
}


//REGISTRASI
void regis(){
        char username[][10] ={"","","","","","","","","",""};
        char password[][10] ={"","","","","","","","","",""};
        FILE*fusername,*fpassword;
        fusername = fopen("username.txt", "a");
        fpassword = fopen("password.txt", "a");

        for(int i=0; i<10; i++){
            fgets(username[i], 255, (FILE*) fusername);
            fgets(password[i], 255, (FILE*) fpassword);
        }
        fclose(fusername);
        fclose(fpassword);
        printf("%s", username[1]);

        printf("===========================================================\n\n");
        printf("                        LalaFund Land                        \n");
        printf("-------------------------REGISTRASI------------------------  \n");
        printf("===========================================================\n\n");
        printf("Inputan username dan password harus sama, jadi pastikan anda membuat kode yang yang unik ^v^\n");
        printf("Masukkan Username          :");
        scanf("%s[^\n]",username[0]);

        printf("Masukkan Password          :");
        scanf("%s[^\n]",password[0]);

        FILE*f=fopen("username.txt","a");
        //input username ke file
        fputs (username[0],f);
        fputs("\n",f);
        fclose(f);
        //input password ke file
        f= fopen("password.txt","a");
        fputs (password[0],f);
        fputs("\n",f);
        fclose(f);

        printf("-----------------------------------------------------------\n\n");
        printf("                      REGISTRASI BERHASIL                    \n");
        printf("===========================================================\n\n");
        if(username==password){
            login();
        }else{
            printf("Maaf username dan password ada kesalahan ^,^\n");
            regis();
        }
}

int checkusername(){
    FILE*filePointer;
    int bufferlength = 255;
    char buffer[bufferlength];
    char checkus[255];
    filePointer = fopen("username.txt","t");
    int index=0;
    int indexfound=0;
    printf("Masukkan username :");
    scanf("%s",checkus);

    while(fgets(buffer,bufferlength, filePointer)){

    buffer[strlen(buffer)-1]='\0';
    int length= strlen(buffer);
    if(strcmp(buffer,checkus)==0)
    {
        indexfound= index;
        return indexfound;
    }
        index++;
    }
    fclose(filePointer);
    return 999;
}

int checkpassword(){
    FILE*filePointer;
    int bufferlength = 255;
    char buffer[bufferlength];
    char checkus[255];
    filePointer = fopen("password.txt","t");
    int index=0;
    int indexfound=0;
    printf("Masukkan password :");
    scanf("%s",checkus);

    while(fgets(buffer,bufferlength, filePointer)){

    buffer[strlen(buffer)-1]='\0';
    int length= strlen(buffer);
    if(strcmp(buffer,checkus)==0)
    {
        indexfound= index;
        return indexfound;
    }
        index++;
    }
    fclose(filePointer);
    return  193;
}

void login(){
    char a;
    do{
    printf("===========================================================\n\n");
    printf("                        LalaFund Land                        \n");
    printf("----------------------------LOGIN--------------------------  \n");
    printf("===========================================================\n\n");
    int username=999;
    int password=193;
    username=checkusername();
    password=checkpassword();

    if(username==password){
        cover();
    }else{
        printf("Maaf user tidak ditemukan ^,^\n");
        login();
    }
    printf("Silahkan login kembali dengan menginputkan ('y'[ya]/'t'[tidak]):  "); scanf("%s", &a);
    system("cls");
    }while (a=='y'|| a=='Y');
    return 0;

}


//COVER
int cover(){
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|            Om swastyastu! Hi! Ni Hao!           |\n");
    printf("\t\t\t\t|              ^0^SELAMAT DATANG ^v^              |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|=========== Welcome to LalaFund Land ============|\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|--------------------INTRUKSI---------------------|\n");
    printf("\t\t\t\t+=================================================+\n\n");
    printf("--------- Hallo Sahabat LalaFund Land! Mohon Perhatikan Instruksi Berikut Sebelum Melakukan Pemesanan Anda ---------\n");
    printf("\t1. Bacalah Berbagai Pilihan Wahana yang ada di LalaFund Land\n");
    printf("\t2. Tentukan pilihan wahana terbaik anda \n");
    printf("\t3. Selanjutnya, pilih golongan pelanggan dan golongan tiket anda\n");
    printf("\t4. Hingga tampil menu wahana pilihan, anda dapat menginputkan pesanan anda \n");
    printf("\t   (Pastikan pilihan anda telah benar)\n");
    printf("\t5. Kemudian inputkan data sesuai intruksi!\n\n");
    printf("\t\t\t\t=================================================\n");
    printf("\t\t\t\t                 Tunggu Apa Lagi?                \n");
    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\t\t\t\t  Order it NOW! Then Have Fun With Your Beloved  \n");
    printf("\t\t\t\t=================================================\n");
    printf("\n Tekan apapun untuk ke menu selanjutnya! : ");
    getch();
    system("cls");
}

//MENU UTAMA
int sekalimuncul = 0;
void menu(){
    if (sekalimuncul != 1){
    cover();
    sekalimuncul=1;
    }
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|------------------LalaFund Land------------------|\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|                 ^0^MENU UTAMA ^v^               |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("\t\t\t\t Silahkan Pilih Menu yang Ingin Anda  :\n\n");
    printf("\t\t\t\t 1.Informasi Wahana\n");
    printf("\t\t\t\t 2.Pemesanan\n");
    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\n\t\t\t\tMasukkan kelompok golongan anda\n(1/2) : ");
    pilihan = validasimenu();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    info();
	    break;
	    case 2:
	    pesan1();
	    break;
	 }
}


//MENU INFO WAHANA
void info(){
    int pilihan;


    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|------------------LalaFund Land------------------|\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|             ^0^ INFORMASI WAHANA ^v^            |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Golongan Customer  :\n\n");
    printf("\t1.Anak-Anak\n");
    printf("\t2.Dewasa \n");
    printf("\t3.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan kelompok golongan anda : ");
    pilihan = validasimenu2();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    infoanak();
	    break;
	    case 2:
	    infodewasa();
	    break;
	    default:
        menu();
	    break;
	 }
}

//MENU INFO WAHANA ANAK
void infoanak(){
    int pilihan;
    // maunya ditambahin info Daftar wahana
    //- Kenapa wahana ini ada
    //- Lokasi wahana
    //- Syarat masuk wahana (ex usia 17++ dsb)
    //- Harga tiket
    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|-------------------LalaFund Land-------------------|\n");
    printf("\t\t\t\t|...................................................|\n");
    printf("\t\t\t\t|               ^0^ WAHANA ANAK ^0^                 |\n");
    printf("\t\t\t\t|===================================================|\n\n");
    printf("\t\t\t\t*****************************************************\n");
    printf("\t\t\t\t  WAHANA  AIR |  WAHANA ADVENTURE  | WAHANA BERMAIN  \n");
    printf("\t\t\t\t   WATERPARK  | OUTBOND GAMES KIDS |  LalafundPark   \n");
    printf("\t\t\t\t*****************************************************\n");
    printf("\n Inputkan '0' untuk Kembali || Inputkan '1' untuk Keluar: ");
    pilihan = validasimenu2();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    info();
	    break;
	    default:
        exit(0);
        printf("\t\t\t\t+===================================================+\n");
        printf("\t\t\t\t|                     PROGRAM                       |\n");
        printf("\t\t\t\t|                  TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|...................................................|\n");
        printf("\t\t\t\t|^o^ TERIMAKASIH & SAMPAI JUMPA DI LALAFUND LAND ^v^|\n");
        printf("\t\t\t\t+=================================================+\n\n");
	    break;
	 }
}

//MENU INFO WAHANA DEWASA
void infodewasa(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|-------------------LalaFund Land-------------------|\n");
    printf("\t\t\t\t|...................................................|\n");
    printf("\t\t\t\t|               ^0^ WAHANA DEWASA ^0^               |\n");
    printf("\t\t\t\t|===================================================|\n\n\n");
    printf("\t\t\t\t*****************************************************\n");
    printf("\t\t\t\t  WAHANA  AIR |  WAHANA ADVENTURE  | WAHANA BERMAIN  \n");
    printf("\t\t\t\t.....................................................\n");
    printf("\t\t\t\t   WATERPARK  |                    |                 \n");
    printf("\t\t\t\t  ARUNG JERAM |    OUTBOND GAMES   |  LALAFUNDPARK   \n");
    printf("\t\t\t\t   SURF RIDER |      ATV RIDE      |                 \n");
    printf("\t\t\t\t   LAZY RIVER |                    |                 \n");
    printf("\t\t\t\t*****************************************************\n");
    printf("\n Inputkan '0' untuk Kembali || Inputkan '1' untuk Keluar: ");
    pilihan = validasimenu2();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    info();
	    break;
	    default:
        exit(0);
        printf("\t\t\t\t+===================================================+\n");
        printf("\t\t\t\t|                     PROGRAM                       |\n");
        printf("\t\t\t\t|                  TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|...................................................|\n");
        printf("\t\t\t\t|^o^ TERIMAKASIH & SAMPAI JUMPA DI LALAFUND LAND ^v^|\n");
        printf("\t\t\t\t+=================================================+\n\n");
	    break;
	 }
}

void pesan1(){
    int pilihan;

    printf("|=================================================|\n");
    printf("|------------------LalaFund Land------------------|\n");
    printf("|.................................................|\n");
    printf("|                   PEMESANAN                     |\n");
    printf("|=================================================|\n\n");
    printf("Pilihan Golongan Pengunjung :\n\n");
    printf("\t1.Lokal\n");
    printf("\t2.Domestik \n");
    printf("\t3.Internasional\n");
    printf("\t4.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nSilahkan masukkan golongan anda : ");
    pilihan = validasipil();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    lokal();
	    break;
	    default:
        menu();
	    break;
	 }
}

void lokal(){
    int pilihan;

    printf("|=================================================|\n");
    printf("|------------------LalaFund Land------------------|\n");
    printf("|.................................................|\n");
    printf("|                   PEMESANAN                     |\n");
    printf("|=================================================|\n\n");
    printf("Pilihan Golongan Tiket :\n\n");
    printf("\t1.Anak-Anak\n");
    printf("\t2.Dewasa \n");
    printf("\t3.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nSilahkan masukkan golongan anda : ");
    pilihan = validasipil();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    anakL();
	    break;
	    default:
        menu();
	    break;
	 }
}

void anakL(){
    int pilihan;

    printf("|=================================================|\n");
    printf("|------------------LalaFund Land------------------|\n");
    printf("|.................................................|\n");
    printf("|                   PEMESANAN                     |\n");
    printf("|=================================================|\n\n");
    printf("Pilihan Wahana Anak Tiket :\n\n");
    printf("\t1.Wahana Air\n");
    printf("\t2.Wahana Adventure \n");
    printf("\t3.Wahana Bermain\n");
    printf("-------------------------------------------------\n");
    printf("\nSilahkan masukkan golongan anda : ");
    pilihan = validasipil();
}
