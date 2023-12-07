#Readme




                    Test Etme İşlemi


Test etmek için öncelikle indirdiğiniz "input 1.txt" ve "SifreliBelge.txt" dosyalarının bilgisayarınızdaki adresini
kodda belirtilen 4 yere, aralarda çift \ kullanarak yazmalısınız.

Programda şifreleme ve şifre çözme komutları bulunuyor en başta kullanıcıya hangisini istediği soruluyor;
şifreleme yapılacaksa "SifreliBelge" içindeki yazılar silinmeli, input dosyasında yazıların varolduğundan emin olunmalı.
deşifre yapılacaksa input dosyasındaki veriler silinmeli ve "SifreliBelge" de şifre bulundugundan emin olunmalı.
(şifreli belgedeki mesaj ASCII değerleri 3 artırılarak şifrelendi)

Bu şekilde çalıştırılırsa doğru çalışmalı.





                    Dosyadan Okuma İşlemi

FILE *(dosyanın adı) şeklinde dosyayı tanımlıyoruz.


(dosyanın adı) = fopen("(Dosyanın bilgisayardaki adresi)" , "(Dosyanın modu)")

Şeklinde dosyanın nerede olduğunu ve dosya ile ne yapılacağını bildiriyoruz.
Ödevde r / read ve a / append modları kullanıldı.


fgets((verinin atanacağı değişken) , (okunacak uzunluk) , (belgenin adı / input))

Şeklinde fgets komutu ile dosyadaki verileri bilgisayara okutuyoruz.


veriler işlemlerden geçtikten sonra verileri :

fputs((verinin atandığı değişkenin adı) , (atanacak belgenin adı / output))

Şeklinde fputs komutu ile bir belgeye yazdırıyoruz.






                     Şifreleme / Şifre Çözme İşlemi


Mesaj adında 100 karakter uzunluğunda bir dizi oluşturarak inputtaki veriyi oraya aktardım.

Verilen inputtaki metin 2 satır olduğundan
fgets ile okunacak belgenin kodunu while loop'un koşulu içine != NULL şeklinde yazarak metnin bitimine kadar
okumasını sağladım

for döngüsü kullanarak dizideki her bir elemanı agoritma şemasında yazdığı gibi küçük karaktere dönüştürdüm,
elemanların alfabeden küçükr bir harf olduğunu if komutu ile belirleyerek alfabeden bir harf olduğu halde
artış değerini ekledim.

if komutu ile, kendisine artış değerinin eklendiği elemanın 'z' harfinin ASCII değerinden daha büyük olması halinde
a ya geri dönmesi için 26 sayısını çıkardım.

yeni bir belge tanımlayarak fputs komutu ile şifrelenmiş mesajı yazdırdım.

şifre çözümüde ise a dan küçük olması halinde ASCII değerine 26 eklenmesi farkı var.






                      Süreçler


Ilk başta çalışan bir şifreleme kodu yazmış da olsam bunu nasıl dışarıya aktaracağımı bilmediğimden youtube'dan ve
chatgbt üzerinden öğrendim ve bunlardan büyük yardım aldım.

Inputtaki mesajın 2 satırdan oluşması çok başımı ağrıttı kendi yazdığım kodlarda sadece 1. satırı çevirerek yazdırıyordu,
sanırım bunu while loopu ile sonuna kadar okuttuk.

Algoritma şemasında "karakter" adlı bir değişken olduğundan, ilk önce mesajdaki her karakteri değişkene atayıp
o değişkeni şifreleme işleminden geçirdikten sonra bir dizide toplayarak diziyi yazdırmak istedim fakat beceremedim.
Bu yüzden direk olarak diziyi kullandım.

Input dosyasını şifreli olarak kendi üzerine yazdıramadım. Bunu yapmanın yolu var mı hala bilmiyorum.
Bu yüzden şifre bulunduracak ayrı bir dosya açtırdım.

