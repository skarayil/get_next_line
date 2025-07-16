get_next_line
Bu proje, her çağrıldığında dosya tanımlayıcısından bir satır okuyup döndüren ve dosyanın sonuna ulaşana kadar bu satırı döndüren get_next_line adlı bir fonksiyonun uygulamasıdır.

Nasıl Çalışır

get_next_line fonksiyonu, her çağrıldığında dosya tanımlayıcısı fd'den bir satır okur. Fonksiyon, okunan satırı içeren bir dizgeye işaretçi döndürür (yeni satır karakteri \n olmadan). Fonksiyon, dosya sonuna ulaşıldığında veya bir hata oluştuğunda NULL döndürür. Fonksiyon, varsa önceki çağrıdan kalan karakterleri depolamak için statik bir değişken kullanır.

Arabellek Boyutu

Dosya tanımlayıcısından okumak için kullanılan arabelleğin boyutu. Belirtilmezse, varsayılan değer 42'dir. Dosyalarda kendi arabellek boyutunuzu ayarlamak için, fonksiyonları derleme sırasında -D BUFFER_SIZE=n işaretini kullanın.

Bonus

Proje, aynı anda birden fazla dosya tanımlayıcısından okuma yapabilen get_next_line fonksiyonunun bonus bir sürümünü içerir.