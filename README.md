# Get Next Line - C Dilinde Satır Okuma Fonksiyonu

**Bu projenin amacı, C dilinde bir dosyadan veya stdin'den satır satır veri okuma işlemini gerçekleştirecek bir fonksiyon yazmaktır. Bu proje, dosya okuma işlemlerine dair temel anlayışı geliştirirken, dinamik bellek yönetimi ve buffer yönetimi gibi konularda deneyim kazandırır.**

### Projenin Amacı:

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

### Desteklenen Özellikler:

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

### Testler ve Örnek Kullanım:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0) {
        printf("%s
", line);
        free(line);  // Bellek yönetimi
    }

    close(fd);
    return 0;
}
```

### Fonksiyonlar:

* **`get_next_line`**:
  * Satır okuma işlemini başlatır ve dosya tanımlayıcısından (fd) veri okur.
  * Okunan satır bir karakter dizisi olarak geri döndürülür.

* **`ft_strjoin`**:
  * İki karakter dizisini birleştirir.

* **`ft_strdup`**:
  * Karakter dizisinin bir kopyasını oluşturur.

* **`ft_strlen`**:
  * Bir karakter dizisinin uzunluğunu hesaplar.

### Kurulum:

Projeyi yerel sisteminize klonlamak için aşağıdaki komutu kullanabilirsiniz:

```bash
git clone https://github.com/kullanici_adiniz/get_next_line.git
```

### Kullanım:

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

### Notlar:

* Dosya okuma işlemi, belirtilen dosyanın sonuna kadar devam eder.
* `get_next_line` fonksiyonu her satırda belleği doğru şekilde yönetir.
* Proje, bellekte sızıntılar yaşanmaması için dikkatli bir şekilde yazılmalıdır.

---

### Created by Sude Naz Karayıldırım
