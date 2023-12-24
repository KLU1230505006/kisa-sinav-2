#include <stdio.h>
#include <stdlib.h>
#include <string.h>//string.h kütüphanesi ekledim.çünkü bu kütüphaneden hazýr fonksiyon kullandým.

#define MAX_BIDDERS 100 //açýk arttýrma oyununa katýlan kiþi sayýsý
#define ITEM_NAME_SIZE 50// açýk arttýrýlmaya çýkarýlan öðenin adý.

struct Acikarttirmaoyunu {
    char item_name[ITEM_NAME_SIZE];//en fazla 50 karekterlik metni depolayabilir.
    float mevcutfiyat;//fiyatýsöyler
    char mevcutteklifsahibi[20];//teklifi veren kiþinin adýný söyler
};

void acikarttirmabasliyor(struct Acikarttirmaoyunu *acikarttirma) {//acikarttirma adli iþaretci acikarttirmabasliyor türündeki veri yapýsýnýn bir örneðini bellek adresinde tutacaktýr.
    printf("acik arttirma oyunu %s 	 %.2f fiyatla basliyor.\n", acikarttirma->item_name, acikarttirma->mevcutfiyat);//bir elemana eriþim saðlamak için kullanýlýr.

    while (1) {
        char teklifiniz[20];
        printf("teklifinizi girin (acikarttirmayi sonlandirmak icin 'bitir' yazin): ");
        scanf("%s", teklifiniz);

        if (strcmp(teklifiniz, "bitir") == 0) {//burda teklifiniz adli dizi ile bitir stringini karþilaþtirir.srtcmp fonk. karþýlaþtýrma yapmak için kullanýlýr.
            printf("acikarttirma sona erdi.artik baska teklif alamiyoruz.\n");
            break;
        }

        if (teklifver(acikarttirma, teklifiniz)) {
            printf("mevcut en yuksek teklif:%.2f\n", acikarttirma->mevcutfiyat, acikarttirma->mevcutteklifsahibi);/*acikarttirma->mevcutfiyat ifadesi
            acikarttýrma iþaretçisinin gösterdiði struct açikarttýrmaoyunu türünden bir veri yapýsýnýn mevcut fiyat adli veri alanýna eriþim saðlamsýný saðlar
            bu ifade o anki açýkarttirma fiyatýný temsil eden bir float deðeri döndürecek.27'nci satýrdan ise ifade edecek olursak eðer teklif geçerli ise mevcut 
            teklif en yüksek teklif olur.*/
            
            
        }
    }
}

int teklifver(struct Acikarttirmaoyunu *acikarttirma, char *teklifiniz) {
    float bidAmount;//burda bidamount sayý miktarýný ondalýklý bir sayý olacak þekilde bir float deðiþkeni tanýmlar.
    if (sscanf(teklifiniz, "%f", &bidAmount) == 1) {//girilen sayý ondalýklý ise deðer bidamount deðiþkenine atanýr.
        if (bidAmount > acikarttirma->mevcutfiyat) {//girilen teklifin en yüksek tekliften büyük olup olmadýðýný kontrol eder.
            acikarttirma->mevcutfiyat = bidAmount;//eðer yeni teklif mevcut tekliften büyükse yeni teklif max teklif olur artýk.
            snprintf(acikarttirma->mevcutteklifsahibi, sizeof(acikarttirma->mevcutteklifsahibi), "teklifveren%d", rand() % MAX_BIDDERS + 1);
            //bu satýr teklif veren kiþinin adýný rastgele olarak atama yapar.
            return 1;/*teklifin baþarýyla iþlendiðini ve güncelleme yapýldðýný belirten bir deðerle fonsiyondan çýkýþ yapar.*/
        } else {
            printf("teklif mevcut fiyattan yuksek olmalidir.\n");//kullanýcýnýn girdiði teklif mevcut tekliften küçükse bu blok çalýþýr ve hata mesajý gelir
        }
    } else {
        printf("geçersiz teklif.lütfen gecerli bir teklif girin.\n");//kullanýcýnýn girdiði deger ondalýklý deðil ise bu blok çalýþýr ve hata mesajý gelir.
    }

    return 0;
}

int main() {
    struct Acikarttirmaoyunu acikarttirma;//açýkarttirma tanýmlanýr.
    strncpy(acikarttirma.item_name, "Antique Painting", sizeof(acikarttirma.item_name));
    //strncpy fonsiyonu ifadesi item_name adlý bir dizeye kopyalar.strncpy fon. belirli bir uzunluktaki karekter dizilerini kopyalamak için kullanýlýrve hedef dizinin taþýma sorunlarýna karþý daha güvenli olmasýný saðlar.
    acikarttirma.mevcutfiyat = 100.0;//acýkarttýrma oyununun baþlangýç fiyatýný 100 lira olarak belirliyor

    acikarttirmabasliyor(&acikarttirma);

    return 0;

}      
                                    
                                    
                                    
