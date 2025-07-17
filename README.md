
# Get Next Line - C Dilinde Satır Okuma Fonksiyonu

**Bu projenin amacı, C dilinde bir dosyadan veya stdin'den satır satır veri okuma işlemini gerçekleştirecek bir fonksiyon yazmaktır. Bu proje, dosya okuma işlemlerine dair temel anlayışı geliştirirken, dinamik bellek yönetimi ve buffer yönetimi gibi konularda deneyim kazandırır.**

## Projenin Amacı:

* **Dinamik Bellek Yönetimi:** 
  Proje, her okunan satır için dinamik olarak hafıza ayırmayı gerektirir. Bu işlem, her satırın belleğe doğru şekilde yerleştirilmesi ve sonraki satırlarla karışmaması için yönetilmelidir.

* **Dosya I/O (Girdi/Çıktı) İşlemleri:**
  Dosya okuma ve yazma işlemleri öğrenilir. Kullanıcıdan veya dosyadan gelen verileri almak için uygun I/O fonksiyonları kullanılır.

* **Buffer Kullanımı:**
  Veriyi küçük parçalara (buffer) bölüp, her bir parçayı işleyerek veriyi satır satır okumak gereklidir. Bu, bellek yönetimini optimize etmeyi sağlar.

* **Get Next Line Fonksiyonu:**
  Fonksiyon, bir dosyadan veya stdin'den gelen verileri satır satır okur ve her satırı kullanıcıya geri döndürür. Satır okuma işlemi, her seferinde bir satırın bitimine kadar devam eder ve bir satır okunduğunda geri döner.

* **Modüler ve Temiz Kod Yapısı:**
  Fonksiyonlar tek bir sorumluluğa sahip olacak şekilde yazılır, okunabilirliği artıracak şekilde yapılandırılır.

* **Bellek Güvenliği ve Hata Yönetimi:**
  Bellek sızıntıları engellenir, kullanılan bellek doğru bir şekilde serbest bırakılır. Aynı zamanda, potansiyel hatalar için uygun kontrol mekanizmaları uygulanır.

* **Test ve Doğrulama:**
  Yazılan fonksiyonlar, farklı dosyalarla test edilerek doğrulukları kontrol edilir. Geliştirilen fonksiyon ile `read()` fonksiyonu arasında karşılaştırmalar yapılır.

## Desteklenen Özellikler:

* **`get_next_line(int fd, char **line)`**
  * Dosyadaki bir satırı okur ve bir `char*` dizisine yazdırır.
  * `fd`: Okunacak dosyanın dosya tanımlayıcısı.
  * `line`: Satırın depolanacağı karakter dizisinin adresi.

* **Dosya Sonu (EOF) ve Hata Durumları:**
  * Satır okuma işlemi tamamlandığında, fonksiyon satırın sonunu (EOF) algılar ve `NULL` döner.
  * Hata durumlarında uygun hata yönetimi yapılır.

* **Veri Okuma ve Buffer Yönetimi:**
  * Satır okuma işlemi, verinin sonuna kadar devam eder, ve her okunan parça doğru bir şekilde buffer'a aktarılır.

* **Daha Fazla Veri Okuma:**
  * Eğer satırda veri bitmediyse, fonksiyon devam eder ve yeni veri okur.

## Bonus Kısmı:

Bonus kısmında, `get_next_line` fonksiyonunun daha esnek hale getirilmesi beklenir. Aşağıdaki özelliklerin eklenmesi gerekmektedir:

* **Daha Fazla Dosya Tanımlayıcısı Desteği:**
  `get_next_line` fonksiyonu, sadece bir dosya tanımlayıcısından (fd) veri okumamalıdır. Bonus kısmı ile fonksiyon, birden fazla dosya tanımlayıcısına (fd) aynı anda hizmet verebilecek şekilde geliştirilebilir.

* **Buffer Boyutunun Dinamik Olarak Belirlenmesi:**
  Buffer boyutunun sabit olmaması gerekir. Kullanıcı tarafından belirtilen bir boyutla dinamik olarak buffer boyutunun belirlenmesi sağlanabilir.

* **Dosya Tanımlayıcıları Arasında Koşullu Okuma:**
  Bonus kısmında, fonksiyonun birden fazla dosya tanımlayıcısı ile eşzamanlı olarak çalışması sağlanmalıdır. Kullanıcı birden fazla dosya okuma işlemi yaparken her dosyadan sırasıyla veri alabilmelidir.

* **Hata Yönetiminin İyileştirilmesi:**
  Fonksiyon, hata durumlarını daha ayrıntılı şekilde ele alacak şekilde güncellenebilir. Her dosya tanımlayıcısı için hata kodları döndürülebilir.

* **EOF Durumunun Yönetilmesi:**
  Fonksiyonun EOF durumunu doğru şekilde yönetmesi ve bir dosyanın sonunda okuma işlemi bitmeden diğer dosyaya geçiş yapması sağlanmalıdır.



## Dosya Yapısı

```
get_next_line/
│
├── get_next_line.c               # `get_next_line()` fonksiyonunun ana işlevini içerir.
├── get_next_line.h               # Fonksiyon prototipleri ve gerekli kütüphaneleri içerir.
├── get_next_line_utils.c         # Yardımcı fonksiyonları içerir (bellek kopyalama, string işlemleri vb.).
├── README.md                     # Proje hakkında bilgi ve kullanım talimatları içerir.
├── get_next_line_bonus.c         # Bonus özellikleri içerir (çoklu dosya tanımlayıcıları).
├── get_next_line_bonus_utils.c   # Bonus işlevlerin yardımcı fonksiyonlarını içerir.
├── get_next_line_bonus.h         # Bonus bölümündeki fonksiyonların prototiplerini içerir.


```

## Kurulum:

Projeyi yerel sisteminize klonlamak için aşağıdaki komutu kullanabilirsiniz:

```bash
git clone https://github.com/skarayil/get_next_line.git
```

## Kullanım:

`get_next_line` fonksiyonu, bir dosya tanımlayıcısı alır ve her çağrıldığında bir satır okur. Satır okuma işlemi bittiğinde, fonksiyon sıfır döner veya `NULL` değerini döndürür.

```c
#include "get_next_line.h"
int fd = open("file.txt", O_RDONLY);
char *line;

while (get_next_line(fd, &line)) {
    // satır işlemleri
    free(line); // Bellek serbest bırakma
}
close(fd);
```

## Notlar:

* Dosya okuma işlemi, belirtilen dosyanın sonuna kadar devam eder.
* `get_next_line` fonksiyonu her satırda belleği doğru şekilde yönetir.
* Proje, bellekte sızıntılar yaşanmaması için dikkatli bir şekilde yazılmalıdır.

---

### Created by SUDE NAZ KARAYILDIRIM
