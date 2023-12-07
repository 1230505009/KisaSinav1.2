#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {

//de�er atamalar� :	
int artis;
char mesaj[100];
int i;
char cevap;




//�ifreleme veya de�ifreleme eylemi belirleme :
printf("\nMetni sifrelemek istiyorsaniz (e) Metnin sifresini cozmek istiyorsaniz (d) yaziniz  :  ");
scanf("%c", &cevap);

//�ifrelenecek ise :
if(cevap == 'e'){
	
	    //dosya tan�m�
		FILE *dosya;
	
	    //art��'�n pozitif tam say� oldu�undan emin olma
	    artisBelirleme : 
	
	
	    printf("Sifreleme icin ASCII degerlerinin artis miktarini belirleyiniz : ");
	    scanf("%d", &artis);
	
	    if(artis <= 0){
		
		    goto artisBelirleme;
	    }
	
	
	    //input dosya tan�m�
	    dosya = fopen("C:\\Users\\Pc\\Desktop\\input 1.txt", "r");   //read modu                                                  //Adres de�i�ikli�i 1  (input)
	
	    //dosya adresi e�le�meme durumu
	    if(dosya == NULL){
		    printf("Dosya acilamadi. 'Input 1.txt' adresini kodlardan degistirmeniz gerekebilir.");
		    return 1;
	    }
	    
	    //verinin sonuna kadar okunmas�
	    while (fgets(mesaj, sizeof(mesaj), dosya) != NULL){
		     
		     //elemanlar�n tek tek �ifrelenmesi : 
		     for(i = 0; i < sizeof(mesaj); i++ ){
		 	
		 	    //B�y�k harfleri k���ltme i�lemi :
		 	    mesaj[i] = tolower(mesaj[i]);
	    	   
	    	   //alfabetik harf testi
	    	   if(mesaj[i] <= 'z' && mesaj[i] >= 'a'){
	    		    
	    		    //ASCII de�erinin belirlenen kadar art�r�lmas�
	    		    mesaj[i] = mesaj[i] + artis;
	    		
	    		    //art�r�lan de�erin z harfinden b�y�k olma durumu
	    		    if(mesaj[i] > 'z'){
	    			    mesaj[i] -= 26;
	    			
	    			
				    }
			    }
	    	
		    }
	    
	        //�ifrenin atanaca�� dosyan�n tan�m�
	        FILE *sifreliDosya;
	    
	        sifreliDosya = fopen("C:\\Users\\Pc\\Desktop\\SifreliBelge.txt", "a");  //appends                                        //Adres de�i�ikli�i 2 (�ifre belgesi)
	    
	        //adresin e�le�meme durumu
	        if(sifreliDosya == NULL){
	    	    printf("Dosya acilamadi. Kodlardan adresi degistirmeniz gerekebilir.");
	            return 1;
			
		    }
		
		    //mesajdaki verinin �ifreli dosyaya yaz�lmas�
		    fputs(mesaj , sifreliDosya);
	    	
	    	//dosyan�n kapat�lmas�
	        fclose(sifreliDosya);
		
		
		
	    }   
	        //dosyan�n kapat�lmas�
	        fclose(dosya);
		
		
		
	}

//de�ifreleme i�lemi :
else if(cevap == 'd'){
	    
	    //dosya tan�m�
	    FILE *sifreliDosya;
	
	
	    artisBelirlemeDesifre : 
	    
	    //�ifrelenmi� olan ASCII de�eri
	    printf("Sifrelenmis mesaj�n sifrelendigi ASCII degerini giriniz : ");
	    scanf("%d", &artis);
	    
	    //art��'�n pozitif tam say� olmas�
	    if(artis <= 0){
		
		    goto artisBelirlemeDesifre;
	    }
	    
	    //dosya tan�m�
	    sifreliDosya = fopen("C:\\Users\\Pc\\Desktop\\SifreliBelge.txt", "r");                                                          //Adres de�i�ikli�i 3 (�ifre belgesi)
	    
	    //dosya adresi e�le�meme durumu
	    if(sifreliDosya == NULL){
		    printf("Dosya acilamadi. 'Input 1.txt' adresini kodlardan degistirmeniz gerekebilir.");
		    return 1;
	    }
	    
	    //dosyan�n sonuna kadar okunmas�
	    while (fgets(mesaj, sizeof(mesaj), sifreliDosya) != NULL){
	    	
	    	//elemanlar�n tek tek de�ifrelenmesi
	    	for(i = 0; i < sizeof(mesaj); i++){
	    		
	    		//varsa b�y�k elemanlar�n k���lt�lmesi
	    		mesaj[i] = tolower(mesaj[i]);
	    		
	    		//elemanlar�n alfabetik olma durumu
	    		if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {
                    
                    //�nceden eklenmi� olan art���n ��kar�lmas�
					mesaj[i] -= artis;
					
					//mesaj�n ASCII degerinin a'dan k���k olma durumu
					if (mesaj[i] < 'a') {
                        mesaj[i] += 26;
                        
                    } 
		        }
	        }
	        
	        //dosya tan�m�
	        FILE *dosya;
	    
	        dosya = fopen("C:\\Users\\Pc\\Desktop\\input 1.txt", "a");                                                                    //Adres de�i�ikli�i 4 (input)
	    
	        //dosya adresinin uyu�mazl�k durumu
	        if(dosya == NULL){
	    	    printf("Dosya acilamadi. Kodlardan adresi degistirmeniz gerekebilir."); 
	            return 1;
			
		    }
		    
			//de�ifrelenmi� verinin yaz�lmas�
		    fputs(mesaj , dosya);
	    	
	    	//dosyan�n kapat�lmas�
	        fclose(dosya);
	        
	        
	        
	        
        }	

        
		//dosyan�n kapat�lmas�
		fclose(sifreliDosya);

    }
    
// d veya e d���nda bir cevab�n yaz�lma durumu    
else{
	
	printf("\nLutfen gecerli bir sonuc giriniz.\n");
	
	return 1;
	
	
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
	return 0;
}
