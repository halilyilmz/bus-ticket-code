#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//kullanýcý adý ve þifresi kontrol eden alan
	char kullaniciadi[20],kullaniciadi2[20];
	int sifre,sifre2,tekrar;
	strcpy(kullaniciadi,"halil");
	sifre=1234;
	tekrar=1;
	
	while (tekrar!=0){
	printf("lutfen kullanici adi giriniz:");
	scanf("%s",&kullaniciadi2);
	printf("lutfen sifre giriniz:");
	scanf("%d",&sifre2);
	if(strcmp(kullaniciadi2,kullaniciadi)==0 &&(sifre2==sifre)){
		tekrar=0;
	}
printf("---------------------otobus rezarvasyon sistemine hos geldiniz-----------------\n");
}
int dongu=0;
while(dongu==0){
	printf("1-bilet almak icin 1'e basiniz\n2-bilet iptali icin 2'ye basiniz\n3-otobus ve koltuk kontrol etmek icin 3'e basiniz\n4-cikis\n");

//secenek kýsmý
int secenek,kackoltukkaldi;
kackoltukkaldi=0;
scanf("%d",&secenek);
if(secenek==1){
	char ad[20],soyad[20],otobus;
	int koltukno;
	int dizi[20];
	printf("bilet satin almak icin bilgilerinizi girniz;\n");
	printf("ad;");
	scanf("%s",&ad);
	printf("soyad;");
	scanf("%s",&soyad);
	printf("otobus;");
	scanf(" %c",&otobus);
	printf("koltukno;");
	scanf("%d",&koltukno);
	
	
	
	

	
	//dosyayý diziye donusturen alan
	if(otobus=='a'){
		FILE* otobusa;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusa=fopen("otobusa.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusa," %c",&otobusmarkasi);
			fscanf(otobusa,"%d",&satir);
			fscanf(otobusa,"%d",&bosdolu);
			dizi[i]=bosdolu;
			if(dizi[i]==0){
				kackoltukkaldi=kackoltukkaldi+1;
			}
			printf("%d",dizi[i]);
			int t;
		}
			fclose(otobusa);
	}
	
	if(otobus=='b'){
		FILE* otobusb;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusb=fopen("otobusb.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusb," %c",&otobusmarkasi);
			fscanf(otobusb,"%d",&satir);
			fscanf(otobusb,"%d",&bosdolu);
			dizi[i]=bosdolu;
			if(dizi[i]==0){
				kackoltukkaldi=kackoltukkaldi+1;
			}
			
		}
			fclose(otobusb);
	}
	if(otobus=='c'){
		FILE* otobusc;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusc=fopen("otobusc.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusc," %c",&otobusmarkasi);
			fscanf(otobusc,"%d",&satir);
			fscanf(otobusc,"%d",&bosdolu);
			dizi[i]=bosdolu;
			if(dizi[i]==0){
				kackoltukkaldi=kackoltukkaldi+1;
			}
			
		}
			fclose(otobusc);
	}

	//koltuk ayýrýan kýsým
	if(kackoltukkaldi==0){
		printf("sectiginiz otobus dolu lutfen farkli bir otobus deneyiniz\n");
	}
	else{
	
	int dongu;
	dongu=1;
	
	while(dongu==1){
	if(dizi[(koltukno-1)]==1){
		printf("koltuk onceden alinmistir lutfen tekrar deneyiniz\n");
		dongu=0;
	}
	else{
		printf("bos koltuk ayirilmistir\n");
		dongu=0;
	}
}
	//koltugu deðistirn kýsým
	if(otobus=='a'){
		remove("otobusa.txt");
		int i;
		FILE *geciciotobusa;
		geciciotobusa=fopen("geciciotobusa.txt","w+");
		for(i=0;i<=19;i++){
			if((koltukno-1)!=i){
			fprintf(geciciotobusa,"a ");
			fprintf(geciciotobusa,"%d ",i+1);
			fprintf(geciciotobusa,"%d\n",dizi[i]);
		}
			else{
				fprintf(geciciotobusa,"a ");
				fprintf(geciciotobusa,"%d ",i+1);
				fprintf(geciciotobusa,"1\n");
			}
			
		}
		fclose(geciciotobusa);
			rename("geciciotobusa.txt","otobusa.txt");
			kackoltukkaldi=kackoltukkaldi+1;
	}
	 if(otobus=='b'){
		remove("otobusb.txt");
		int i;
		FILE *geciciotobusb;
		geciciotobusb=fopen("geciciotobusb.txt","w+");
		for(i=0;i<=19;i++){
			if((koltukno-1)!=i){
			fprintf(geciciotobusb,"b ");
			fprintf(geciciotobusb,"%d ",i+1);
			fprintf(geciciotobusb,"%d\n",dizi[i]);
		}
			else{
				fprintf(geciciotobusb,"b ");
				fprintf(geciciotobusb,"%d ",i+1);
				fprintf(geciciotobusb,"1\n");
			}
			
		}
		fclose(geciciotobusb);
			rename("geciciotobusb.txt","otobusb.txt");
			kackoltukkaldi=kackoltukkaldi+1;
	}
	if(otobus=='c'){
		remove("otobusc.txt");
		int i;
		FILE *geciciotobusc;
		geciciotobusc=fopen("geciciotobusc.txt","w+");
		for(i=0;i<=19;i++){
			if((koltukno-1)!=i){
			fprintf(geciciotobusc,"c ");
			fprintf(geciciotobusc,"%d ",i+1);
			fprintf(geciciotobusc,"%d\n",dizi[i]);
		}
			else{
				fprintf(geciciotobusc,"c ");
				fprintf(geciciotobusc,"%d ",i+1);
				fprintf(geciciotobusc,"1\n");
			}
			
		}
		fclose(geciciotobusc);
			rename("geciciotobusc.txt","otobusc.txt");
			kackoltukkaldi=kackoltukkaldi+1;
	}
	
	//otobus biletini dosyaya yazan kýsým
	FILE *biletlistesi;
biletlistesi=fopen("bilet_listesi.txt","a");
fprintf(biletlistesi,"%s ",ad);
fprintf(biletlistesi,"%s ",soyad);
fprintf(biletlistesi,"%c ",otobus);
fprintf(biletlistesi,"%d \n",koltukno);
fclose(biletlistesi);
}


}

//bileti iptal eden kod
else if(secenek==2){
int koltuk[100], i = 0;
    char kullanicininverdigiad[100],kullanicininverdigisoyad[100];
    char alinanad[100][100], soyisim[100][100], otobusmarkasi[100][100];
    char kullaniciotobusmark;
    int koltukdolubos[100],a;

    printf("Adinizi giriniz: ");
    scanf("%s", kullanicininverdigiad);
    printf("soyadinizi giriniz: ");
    scanf("%s", kullanicininverdigisoyad);
    

    FILE *biletlistesi;
    biletlistesi = fopen("bilet_listesi.txt", "r");

    while (fscanf(biletlistesi, "%s %s %s %d", alinanad[i], soyisim[i], otobusmarkasi[i], &koltuk[i]) == 4) {
    	if (strcmp(kullanicininverdigiad, alinanad[i - 1]) == 0){
    		a=i-1;
    		kullaniciotobusmark=otobusmarkasi[i][0];
		}
        i++;
    }
    fclose(biletlistesi);

    remove("bilet_listesi.txt");

    FILE *biletlistesi2;
    biletlistesi2 = fopen("bilet_listesi.txt", "w+");


    while (i > 0) {
        if ((strcmp(kullanicininverdigiad, alinanad[i - 1]) == 0)&&(strcmp(kullanicininverdigisoyad, soyisim[i - 1]) == 0)) {
            //isimler eþitse biþey yapma
        } else {
            fprintf(biletlistesi2, "%s %s %s %d\n", alinanad[i - 1], soyisim[i - 1], otobusmarkasi[i - 1], koltuk[i - 1]);
        }
        i--;
    }

    fclose(biletlistesi2);
    
    int dizi[i];
if(kullaniciotobusmark=='a'){
		FILE* otobusa;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusa=fopen("otobusa.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusa," %c",&otobusmarkasi);
			fscanf(otobusa,"%d",&satir);
			fscanf(otobusa,"%d",&bosdolu);
			dizi[i]=bosdolu;
		}
			fclose(otobusa);
	}
else if(kullaniciotobusmark=='b'){
		FILE* otobusb;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusb=fopen("otobusb.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusb," %c",&otobusmarkasi);
			fscanf(otobusb,"%d",&satir);
			fscanf(otobusb,"%d",&bosdolu);
			dizi[i]=bosdolu;
		}
			fclose(otobusb);
	}
else if(kullaniciotobusmark=='c'){
		FILE* otobusc;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusc=fopen("otobusc.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusc," %c",&otobusmarkasi);
			fscanf(otobusc,"%d",&satir);
			fscanf(otobusc,"%d",&bosdolu);
			dizi[i]=bosdolu;
		}
			fclose(otobusc);
	}
//koltugu 0ra deiþtiren kisim
if(kullaniciotobusmark=='a'){
		remove("otobusa.txt");
		int i;
		FILE *geciciotobusa;
		geciciotobusa=fopen("geciciotobusa.txt","w+");
		for(i=0;i<=19;i++){
			if((koltuk[a])!=i+1){
			fprintf(geciciotobusa,"a ");
			fprintf(geciciotobusa,"%d ",i+1);
			fprintf(geciciotobusa,"%d\n",dizi[i+1]);
		}
			else{
				fprintf(geciciotobusa,"a ");
				fprintf(geciciotobusa,"%d ",i+1);
				fprintf(geciciotobusa,"0\n");
			}
			
		}
		fclose(geciciotobusa);
			rename("geciciotobusa.txt","otobusa.txt");
			kackoltukkaldi=kackoltukkaldi+1;
	}
	 if(kullaniciotobusmark=='b'){
	remove("otobusa.txt");
		int i;
		FILE *geciciotobusb;
		geciciotobusb=fopen("geciciotobusb.txt","w+");
		for(i=0;i<=19;i++){
			if((koltuk[a])!=i+1){
			fprintf(geciciotobusb,"a ");
			fprintf(geciciotobusb,"%d ",i+1);
			fprintf(geciciotobusb,"%d\n",dizi[i+1]);
		}
			else{
				fprintf(geciciotobusb,"a ");
				fprintf(geciciotobusb,"%d ",i+1);
				fprintf(geciciotobusb,"0\n");
			}
			
		}
		fclose(geciciotobusb);
			rename("geciciotobusb.txt","otobusb.txt");
			kackoltukkaldi=kackoltukkaldi+1;
	}
	if(kullaniciotobusmark=='c'){
		remove("otobusc.txt");
		int i;
		FILE *geciciotobusc;
		geciciotobusc=fopen("geciciotobusc.txt","w+");
		for(i=0;i<=19;i++){
			if((koltuk[a])!=i+1){
			fprintf(geciciotobusc,"a ");
			fprintf(geciciotobusc,"%d ",i+1);
			fprintf(geciciotobusc,"%d\n",dizi[i+1]);
		}
			else{
				fprintf(geciciotobusc,"a ");
				fprintf(geciciotobusc,"%d ",i+1);
				fprintf(geciciotobusc,"0\n");
			}
			
		}
		fclose(geciciotobusc);
			rename("geciciotobusc.txt","otobusc.txt");
			kackoltukkaldi=kackoltukkaldi+1;
}

}



else if(secenek==3){
	char yeniotobusadi;
	int boskoltuk,dizi[20],yenikackoltukkaldi=0;
	printf("otobusun sirketinin adini giriniz;\n");
	scanf(" %c",&yeniotobusadi);
	if(yeniotobusadi=='a'){
		FILE* otobusa;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusa=fopen("otobusa.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusa," %c",&otobusmarkasi);
			fscanf(otobusa,"%d",&satir);
			fscanf(otobusa,"%d",&bosdolu);
			dizi[i]=bosdolu;
			if(dizi[i]==0){
				yenikackoltukkaldi=yenikackoltukkaldi+1;
			}
		}
			fclose(otobusa);
	}
	if(yeniotobusadi=='b'){
		FILE* otobusb;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusb=fopen("otobusb.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusb," %c",&otobusmarkasi);
			fscanf(otobusb,"%d",&satir);
			fscanf(otobusb,"%d",&bosdolu);
			dizi[i]=bosdolu;
			if(dizi[i]==0){
				yenikackoltukkaldi=yenikackoltukkaldi+1;
			}
			
		}
			fclose(otobusb);
	}
	if(yeniotobusadi=='c'){
		FILE* otobusc;
		char otobusmarkasi;
		int satir,bosdolu,i;
		otobusc=fopen("otobusc.txt","r");
		for(i=0;i<20;i++){
			fscanf(otobusc," %c",&otobusmarkasi);
			fscanf(otobusc,"%d",&satir);
			fscanf(otobusc,"%d",&bosdolu);
			dizi[i]=bosdolu;
			if(dizi[i]==0){
				yenikackoltukkaldi=yenikackoltukkaldi+1;
			}
			
		}
			fclose(otobusc);
	}
	boskoltuk=20-yenikackoltukkaldi;
	printf("%c otobusu ankara istanbul istikametinde 14.00'da %d kisi ile gerceklestirilecektir %d koltuk bostur'",yeniotobusadi,yenikackoltukkaldi,boskoltuk);
	
}
else if(secenek==4){
	printf("menüden cikiliyor");
	dongu=1;
}
}

	return 0;
}
