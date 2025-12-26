#include <stdio.h>
#include <math.h>

typedef struct {
    char isim[20];
    char model[20];
    float fiyat;
}Tel;
int main() {
    FILE*fp,*fp2;
    fp=fopen("C:\\Users\\LENOVO\\OneDrive\\Masaüstü\\FIYAT.txt","r");
    fp2 = fopen("C:\\Users\\LENOVO\\OneDrive\\Masaüstü\\ONERI.txt","w");
    Tel t1;
    if (!fp || !fp2) {
        printf("Dosya acma islemi hatayla sonuclandi!\n");
        return 1;
    }
    float ortalama =0;
    float fark;
    float toplam=0;
    int sayac=0;
    //sayac degiskenini tanimlama sebebimiz programi manuellikten kurtarip
    //daha kullanisli bir hale getirmek
    //bu sayede dosyada kac satir yani binevi telefon var ise o kadar deger alip
    //ortalamayi bulmayi sagladi
    float min=9000000;
     /*dongulere baslamadan;
    taslak projemizde şartimizi !feof(fp) ile kurmustuk ancak bu durum ortalmaya
    yanlis deger atanmasına sebep oluyordu biz de şöyle düşündük
    while dan istedigimiz seyi sarta baglayıp okutma
    basarili sekilde okuyor isen devam et
    basarisiz durum ise dosya bitince yasanacak ve okumayi birakacak*/
    while(fscanf(fp,"%s %s %f",t1.isim,t1.model,&t1.fiyat)==3)
          //while mantigi;
            //dosya her bir satirda uc sey okumali isim, model, fiyat
                //her satir basina 3 kere basarili bir okuma gerceklestirilmeli
    {
        sayac++;
        toplam += t1.fiyat;
    }
    rewind(fp);
    ortalama=toplam/sayac;
    while(fscanf(fp,"%s %s %f",t1.isim,t1.model,&t1.fiyat)==3)
    {
        fark =fabs(ortalama-t1.fiyat);
        if (fark<min) {
            min=fark;
        }
    }
    rewind(fp);
    fprintf(fp2,"Ortalama:%.3f\n",ortalama);
    fprintf(fp2,"Onerdigimiz cep telefonu:\n");
    while(fscanf(fp," %s %s %f",t1.isim,t1.model,&t1.fiyat)==3) {

        if (fabs(fabs(ortalama - t1.fiyat) - min) < 0.001){
            fprintf(fp2,"%s %s %.2f\n",t1.isim,t1.model,t1.fiyat);
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;

}
