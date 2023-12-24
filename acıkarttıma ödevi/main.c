#include <stdio.h>
#include <stdlib.h>
#include <string.h>//string.h k�t�phanesi ekledim.��nk� bu k�t�phaneden haz�r fonksiyon kulland�m.

#define MAX_BIDDERS 100 //a��k artt�rma oyununa kat�lan ki�i say�s�
#define ITEM_NAME_SIZE 50// a��k artt�r�lmaya ��kar�lan ��enin ad�.

struct Acikarttirmaoyunu {
    char item_name[ITEM_NAME_SIZE];//en fazla 50 karekterlik metni depolayabilir.
    float mevcutfiyat;//fiyat�s�yler
    char mevcutteklifsahibi[20];//teklifi veren ki�inin ad�n� s�yler
};

void acikarttirmabasliyor(struct Acikarttirmaoyunu *acikarttirma) {//acikarttirma adli i�aretci acikarttirmabasliyor t�r�ndeki veri yap�s�n�n bir �rne�ini bellek adresinde tutacakt�r.
    printf("acik arttirma oyunu %s 	 %.2f fiyatla basliyor.\n", acikarttirma->item_name, acikarttirma->mevcutfiyat);//bir elemana eri�im sa�lamak i�in kullan�l�r.

    while (1) {
        char teklifiniz[20];
        printf("teklifinizi girin (acikarttirmayi sonlandirmak icin 'bitir' yazin): ");
        scanf("%s", teklifiniz);

        if (strcmp(teklifiniz, "bitir") == 0) {//burda teklifiniz adli dizi ile bitir stringini kar�ila�tirir.srtcmp fonk. kar��la�t�rma yapmak i�in kullan�l�r.
            printf("acikarttirma sona erdi.artik baska teklif alamiyoruz.\n");
            break;
        }

        if (teklifver(acikarttirma, teklifiniz)) {
            printf("mevcut en yuksek teklif:%.2f\n", acikarttirma->mevcutfiyat, acikarttirma->mevcutteklifsahibi);/*acikarttirma->mevcutfiyat ifadesi
            acikartt�rma i�aret�isinin g�sterdi�i struct a�ikartt�rmaoyunu t�r�nden bir veri yap�s�n�n mevcut fiyat adli veri alan�na eri�im sa�lams�n� sa�lar
            bu ifade o anki a��karttirma fiyat�n� temsil eden bir float de�eri d�nd�recek.27'nci sat�rdan ise ifade edecek olursak e�er teklif ge�erli ise mevcut 
            teklif en y�ksek teklif olur.*/
            
            
        }
    }
}

int teklifver(struct Acikarttirmaoyunu *acikarttirma, char *teklifiniz) {
    float bidAmount;//burda bidamount say� miktar�n� ondal�kl� bir say� olacak �ekilde bir float de�i�keni tan�mlar.
    if (sscanf(teklifiniz, "%f", &bidAmount) == 1) {//girilen say� ondal�kl� ise de�er bidamount de�i�kenine atan�r.
        if (bidAmount > acikarttirma->mevcutfiyat) {//girilen teklifin en y�ksek tekliften b�y�k olup olmad���n� kontrol eder.
            acikarttirma->mevcutfiyat = bidAmount;//e�er yeni teklif mevcut tekliften b�y�kse yeni teklif max teklif olur art�k.
            snprintf(acikarttirma->mevcutteklifsahibi, sizeof(acikarttirma->mevcutteklifsahibi), "teklifveren%d", rand() % MAX_BIDDERS + 1);
            //bu sat�r teklif veren ki�inin ad�n� rastgele olarak atama yapar.
            return 1;/*teklifin ba�ar�yla i�lendi�ini ve g�ncelleme yap�ld��n� belirten bir de�erle fonsiyondan ��k�� yapar.*/
        } else {
            printf("teklif mevcut fiyattan yuksek olmalidir.\n");//kullan�c�n�n girdi�i teklif mevcut tekliften k���kse bu blok �al���r ve hata mesaj� gelir
        }
    } else {
        printf("ge�ersiz teklif.l�tfen gecerli bir teklif girin.\n");//kullan�c�n�n girdi�i deger ondal�kl� de�il ise bu blok �al���r ve hata mesaj� gelir.
    }

    return 0;
}

int main() {
    struct Acikarttirmaoyunu acikarttirma;//a��karttirma tan�mlan�r.
    strncpy(acikarttirma.item_name, "Antique Painting", sizeof(acikarttirma.item_name));
    //strncpy fonsiyonu ifadesi item_name adl� bir dizeye kopyalar.strncpy fon. belirli bir uzunluktaki karekter dizilerini kopyalamak i�in kullan�l�rve hedef dizinin ta��ma sorunlar�na kar�� daha g�venli olmas�n� sa�lar.
    acikarttirma.mevcutfiyat = 100.0;//ac�kartt�rma oyununun ba�lang�� fiyat�n� 100 lira olarak belirliyor

    acikarttirmabasliyor(&acikarttirma);

    return 0;

}      
                                    
                                    
                                    
