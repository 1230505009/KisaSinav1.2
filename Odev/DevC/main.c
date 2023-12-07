#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {

//deðer atamalarý :	
int artis;
char mesaj[100];
int i;
char cevap;




//þifreleme veya deþifreleme eylemi belirleme :
printf("\nMetni sifrelemek istiyorsaniz (e) Metnin sifresini cozmek istiyorsaniz (d) yaziniz  :  ");
scanf("%c", &cevap);

//þifrelenecek ise :
if(cevap == 'e'){
	
	    //dosya tanýmý
		FILE *dosya;
	
	    //artýþ'ýn pozitif tam sayý olduðundan emin olma
	    artisBelirleme : 
	
	
	    printf("Sifreleme icin ASCII degerlerinin artis miktarini belirleyiniz : ");
	    scanf("%d", &artis);
	
	    if(artis <= 0){
		
		    goto artisBelirleme;
	    }
	
	
	    //input dosya tanýmý
	    dosya = fopen("C:\\Users\\Pc\\Desktop\\input 1.txt", "r");   //read modu                                                  //Adres deðiþikliði 1  (input)
	
	    //dosya adresi eþleþmeme durumu
	    if(dosya == NULL){
		    printf("Dosya acilamadi. 'Input 1.txt' adresini kodlardan degistirmeniz gerekebilir.");
		    return 1;
	    }
	    
	    //verinin sonuna kadar okunmasý
	    while (fgets(mesaj, sizeof(mesaj), dosya) != NULL){
		     
		     //elemanlarýn tek tek þifrelenmesi : 
		     for(i = 0; i < sizeof(mesaj); i++ ){
		 	
		 	    //Büyük harfleri küçültme iþlemi :
		 	    mesaj[i] = tolower(mesaj[i]);
	    	   
	    	   //alfabetik harf testi
	    	   if(mesaj[i] <= 'z' && mesaj[i] >= 'a'){
	    		    
	    		    //ASCII deðerinin belirlenen kadar artýrýlmasý
	    		    mesaj[i] = mesaj[i] + artis;
	    		
	    		    //artýrýlan deðerin z harfinden büyük olma durumu
	    		    if(mesaj[i] > 'z'){
	    			    mesaj[i] -= 26;
	    			
	    			
				    }
			    }
	    	
		    }
	    
	        //þifrenin atanacaðý dosyanýn tanýmý
	        FILE *sifreliDosya;
	    
	        sifreliDosya = fopen("C:\\Users\\Pc\\Desktop\\SifreliBelge.txt", "a");  //appends                                        //Adres deðiþikliði 2 (þifre belgesi)
	    
	        //adresin eþleþmeme durumu
	        if(sifreliDosya == NULL){
	    	    printf("Dosya acilamadi. Kodlardan adresi degistirmeniz gerekebilir.");
	            return 1;
			
		    }
		
		    //mesajdaki verinin þifreli dosyaya yazýlmasý
		    fputs(mesaj , sifreliDosya);
	    	
	    	//dosyanýn kapatýlmasý
	        fclose(sifreliDosya);
		
		
		
	    }   
	        //dosyanýn kapatýlmasý
	        fclose(dosya);
		
		
		
	}

//deþifreleme iþlemi :
else if(cevap == 'd'){
	    
	    //dosya tanýmý
	    FILE *sifreliDosya;
	
	
	    artisBelirlemeDesifre : 
	    
	    //þifrelenmiþ olan ASCII deðeri
	    printf("Sifrelenmis mesajýn sifrelendigi ASCII degerini giriniz : ");
	    scanf("%d", &artis);
	    
	    //artýþ'ýn pozitif tam sayý olmasý
	    if(artis <= 0){
		
		    goto artisBelirlemeDesifre;
	    }
	    
	    //dosya tanýmý
	    sifreliDosya = fopen("C:\\Users\\Pc\\Desktop\\SifreliBelge.txt", "r");                                                          //Adres deðiþikliði 3 (þifre belgesi)
	    
	    //dosya adresi eþleþmeme durumu
	    if(sifreliDosya == NULL){
		    printf("Dosya acilamadi. 'Input 1.txt' adresini kodlardan degistirmeniz gerekebilir.");
		    return 1;
	    }
	    
	    //dosyanýn sonuna kadar okunmasý
	    while (fgets(mesaj, sizeof(mesaj), sifreliDosya) != NULL){
	    	
	    	//elemanlarýn tek tek deþifrelenmesi
	    	for(i = 0; i < sizeof(mesaj); i++){
	    		
	    		//varsa büyük elemanlarýn küçültülmesi
	    		mesaj[i] = tolower(mesaj[i]);
	    		
	    		//elemanlarýn alfabetik olma durumu
	    		if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {
                    
                    //önceden eklenmiþ olan artýþýn çýkarýlmasý
					mesaj[i] -= artis;
					
					//mesajýn ASCII degerinin a'dan küçük olma durumu
					if (mesaj[i] < 'a') {
                        mesaj[i] += 26;
                        
                    } 
		        }
	        }
	        
	        //dosya tanýmý
	        FILE *dosya;
	    
	        dosya = fopen("C:\\Users\\Pc\\Desktop\\input 1.txt", "a");                                                                    //Adres deðiþikliði 4 (input)
	    
	        //dosya adresinin uyuþmazlýk durumu
	        if(dosya == NULL){
	    	    printf("Dosya acilamadi. Kodlardan adresi degistirmeniz gerekebilir."); 
	            return 1;
			
		    }
		    
			//deþifrelenmiþ verinin yazýlmasý
		    fputs(mesaj , dosya);
	    	
	    	//dosyanýn kapatýlmasý
	        fclose(dosya);
	        
	        
	        
	        
        }	

        
		//dosyanýn kapatýlmasý
		fclose(sifreliDosya);

    }
    
// d veya e dýþýnda bir cevabýn yazýlma durumu    
else{
	
	printf("\nLutfen gecerli bir sonuc giriniz.\n");
	
	return 1;
	
	
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
	return 0;
}
