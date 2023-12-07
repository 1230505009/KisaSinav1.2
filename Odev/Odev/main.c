#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
	
int artis;
char mesaj[100];
int i;
char cevap;

baslangic : 

printf("\nMetni sifrelemek istiyorsaniz (e) Metnin sifresini cozmek istiyorsaniz (d) yaziniz  :  ");
scanf("%c", &cevap);

if(cevap == 'e'){
	
	
		FILE *dosya;
	
	
	    artisBelirleme : 
	
	    printf("Sifreleme icin ASCII degerlerinin artis miktarini belirleyiniz : ");
	    scanf("%d", &artis);
	
	    if(artis <= 0){
		
		    goto artisBelirleme;
	    }
	
	    dosya = fopen("C:\\Users\\Pc\\Desktop\\input 1.txt", "r");
	
	    if(dosya == NULL){
		    printf("Dosya acilamadi. 'Input 1.txt' adresini kodlardan degistirmeniz gerekebilir.");
		    return 1;
	    }
	
	    while (fgets(mesaj, sizeof(mesaj), dosya) != NULL){
		
		     for(i = 0; i < sizeof(mesaj); i++ ){
		 	
		 	    mesaj[i] = tolower(mesaj[i]);
	    	
	    	   if(mesaj[i] <= 'z' && mesaj[i] >= 'a'){
	    		
	    		    mesaj[i] = mesaj[i] + artis;
	    		
	    		    if((mesaj[i] > 'Z'  &&  mesaj[i] <= 'Z' + artis)  ||  mesaj[i] > 'z'){
	    			    mesaj[i] -= 26;
	    			
	    			
				    }
			    }
	    	
		    }
	    
	        FILE *sifreliDosya;
	    
	        sifreliDosya = fopen("C:\\Users\\Pc\\Desktop\\SifreliBelge.txt", "a");
	    
	        if(sifreliDosya == NULL){
	    	    printf("Dosya acilamadi. Kodlardan adresi degistirmeniz gerekebilir.");
	            return 1;
			
		    }
		
		    fputs(mesaj , sifreliDosya);
	    	
	        fclose(sifreliDosya);
		
		
		
	    }   
	    
	        fclose(dosya);
		
		
		
	}

else if(cevap == 'd'){
	
	    FILE *sifreliDosya;
	
	
	    artisBelirlemeDesifre : 
	
	    printf("Sifreleme icin ASCII degerlerinin artis miktarini belirleyiniz : ");
	    scanf("%d", &artis);
	
	    if(artis <= 0){
		
		    goto artisBelirlemeDesifre;
	    }
	    
	    sifreliDosya = fopen("C:\\Users\\Pc\\Desktop\\SifreliBelge.txt", "r");
	    
	    if(sifreliDosya == NULL){
		    printf("Dosya acilamadi. 'Input 1.txt' adresini kodlardan degistirmeniz gerekebilir.");
		    return 1;
	    }
	    
	    
	    while (fgets(mesaj, sizeof(mesaj), sifreliDosya) != NULL){
	    	
	    	for(i = 0; i < sizeof(mesaj); i++){
	    		
	    		mesaj[i] = tolower(mesaj[i]);
	    		
	    		if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {
                    
					mesaj[i] -= artis;
					
					if ((mesaj[i] < 'a') && (mesaj[i] >= 'a' - artis)) {
                        mesaj[i] += 26;
                        
                    } 
		        }
	        }
	        
	        
	        FILE *dosya;
	    
	        dosya = fopen("C:\\Users\\Pc\\Desktop\\input 1.txt", "a");
	    
	        if(dosya == NULL){
	    	    printf("Dosya acilamadi. Kodlardan adresi degistirmeniz gerekebilir.");
	            return 1;
			
		    }
		
		    fputs(mesaj , dosya);
	    	
	        fclose(dosya);
	        
	        
	        
	        
        }	

        
		
		fclose(sifreliDosya);

    }
    
    
else{
	
	printf("\nLutfen gecerli bir sonuc giriniz.\n");
	
	return 1;
	
	
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
	return 0;
}
