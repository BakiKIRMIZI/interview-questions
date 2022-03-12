#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(){
    setlocale(LC_ALL, "Turkish");
    srand((unsigned)time(NULL));
    system("cls || clear");
    puts("\n");

    // 4x4 rastgele küçük harf tanımlama ve bastırma

    char oyuntahtasi[4][4];
    int i, j, k;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            oyuntahtasi[i][j] = 97 + rand()%26;

        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            printf("%4c",oyuntahtasi[i][j]);
        }
        printf("\n");
    }

    // Ekran silme
    
    puts("\n");
    sleep(2);
    system("cls || clear");

    // Tahmin sonrasındaki oyun tahtasını ayarlama

    char sahtetahta[4][4];
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            sahtetahta[i][j] = '_';

        }
    }


    // Oyun

    int satir[256], sutun[256];
    char tahmin[256] = {};
    int puan = 0, dogru = 0;


    while(puan >= 0 && dogru != 16){
        k = 0;
        printf("Tahmin edeceğiniz harf hangi satırda? (1-4):  ");
        scanf("%d",&satir[k]);
        printf("Tahmin edeceğiniz harf hangi sütunda? (1-4):  ");
        scanf("%d",&sutun[k]);
        printf("Tahmin edeceğiniz harf nedir? (a-z):  ");
        scanf("%s",&tahmin[k]);

        //puanlama ve kontrol
        if(oyuntahtasi[satir[k]-1][sutun[k]-1] == '*'){
            printf("UYARI!!! Bu harfi daha önce bildiniz. Tekrar deneyiniz.\n");
            printf("Puanınız:  %d",puan);
        }

        else if(oyuntahtasi[satir[k]-1][sutun[k]-1] == tahmin[k]){
            puan++;
            dogru++;
            printf("Doğru! Puanınız: %d",puan);

            puts("\n");
            sahtetahta[satir[k]-1][sutun[k]-1] = tahmin[k];
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    printf("%4c",sahtetahta[i][j]);
                }
                printf("\n");
            }

            oyuntahtasi[satir[k]-1][sutun[k]-1] = '*';

        }

        else{
            puan--;
            printf("Yanlış! Puanınız: %d",puan);

            puts("\n");
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    printf("%4c",sahtetahta[i][j]);
                }
                printf("\n");
            }
        }


        k++;
        puts("\n");
    }

    if(puan < 0){
        printf("\n\nKaybettiniz!!!");
    }    
    if(dogru == 16){
        printf("\n\nKAZANDINIZ!!!\n");
        printf("Toplam puanınız: %d",puan);
    }


    puts("\n");
    return 0;
}