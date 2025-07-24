# 📖 get_next_line - C Dilinde Satır Okuma Fonksiyonu

<div align="center">

![42 School](https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![File I/O](https://img.shields.io/badge/Project-get__next__line-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

**C dilinde bir dosyadan veya stdin'den satır satır veri okuma işlemini gerçekleştiren fonksiyon**

*Bu proje, dosya okuma işlemlerine dair temel anlayışı geliştirirken, dinamik bellek yönetimi ve buffer yönetimi gibi konularda deneyim kazandırır.*

[Kurulum](#-kurulum) • [Kullanım](#-kullanım) • [Özellikler](#-desteklenen-özellikler) • [Bonus](#-bonus-kısmı)

</div>

---

## 🎯 Projenin Amacı

<img align="right" alt="File Reading Animation" width="300" src="https://media.giphy.com/media/xT9IgzoKnwFNmISR8I/giphy.gif">

Bu proje, **dosyadan veya stdin'den satır satır veri okuma** işlemini gerçekleştiren bir fonksiyon geliştirmeyi amaçlar. Proje, sistem programlama ve bellek yönetimi konularında derinlemesine deneyim sağlar.

### 🎓 **Ana Öğrenme Hedefleri:**

#### 🧠 **Dinamik Bellek Yönetimi**
- Her okunan satır için dinamik olarak hafıza ayırma
- Bellek sızıntılarını önleme ve güvenli bellek yönetimi
- Malloc/free optimizasyonu ve bellek güvenliği

#### 📁 **Dosya I/O (Girdi/Çıktı) İşlemleri**
- Dosya okuma ve yazma işlemlerinin derinlemesine öğrenilmesi
- System call'lar (`read()`, `open()`, `close()`) ile çalışma
- File descriptor yönetimi ve file handling

#### 🔄 **Buffer Kullanımı**
- Veriyi küçük parçalara (buffer) bölme ve işleme
- Buffer optimizasyonu ile bellek kullanımını minimize etme
- Streaming data processing teknikleri

#### 🎯 **Get Next Line Fonksiyonu**
- Dosyadan satır satır okuma algoritması tasarlama
- Newline character detection ve handling
- State management between function calls

#### 🏗️ **Modüler ve Temiz Kod Yapısı**
- Single Responsibility Principle uygulaması
- Fonksiyonlar arası clean interface tasarımı
- Maintainable ve extensible kod yazma

#### 🛡️ **Bellek Güvenliği ve Hata Yönetimi**
- Comprehensive error handling stratejileri
- Memory leak prevention techniques
- Robust error recovery mechanisms

#### 🧪 **Test ve Doğrulama**
- Farklı dosya türleri ile kapsamlı test
- Edge case handling ve boundary conditions
- Performance benchmarking ve optimization

---

## ✨ Desteklenen Özellikler

<div align="center">

![File Reading](https://img.shields.io/badge/File-Reading-brightgreen?style=for-the-badge)
![Memory Safe](https://img.shields.io/badge/Memory-Safe-blue?style=for-the-badge)
![Buffer Management](https://img.shields.io/badge/Buffer-Management-orange?style=for-the-badge)

</div>

### 📋 **Ana Fonksiyon**

| Fonksiyon | Parametre | Return Value | Açıklama |
|-----------|-----------|--------------|----------|
| **`get_next_line`** | `int fd` | `char *` | Dosyadan bir satır okur ve döndürür |

### 🔧 **Fonksiyon Detayları**

#### 📖 **get_next_line(int fd)**
- **Amaç**: Dosya tanımlayıcısından bir satır okuma
- **Parametre**: `fd` - Okunacak dosyanın file descriptor'ı
- **Return**: 
  - `char *` - Okunan satır (malloc ile allocated)
  - `NULL` - EOF'a ulaşıldığında veya hata durumunda

#### 🎛️ **Temel Özellikler**

| Özellik | Açıklama | Implementation |
|---------|----------|----------------|
| **Line Reading** | Newline character'a kadar okuma | `\n` detection |
| **EOF Handling** | Dosya sonu durumunu yönetme | NULL return |
| **Error Management** | Hata durumlarında güvenli işlem | Error codes |
| **Memory Safety** | Bellek sızıntısı önleme | Proper free() calls |
| **Buffer Management** | Efficient data buffering | BUFFER_SIZE optimization |

### 🔄 **Çalışma Prensibi**

```
File → Buffer → Line Processing → Memory Allocation → Return Line
  ↓        ↓           ↓               ↓              ↓
read()   Static    Find '\n'       malloc()      char *
         Buffer    Character      New String    To User
```

---

## 🎁 Bonus Kısmı

<div align="center">

![Multiple FD](https://img.shields.io/badge/Multiple-FD%20Support-gold?style=for-the-badge)
![Advanced](https://img.shields.io/badge/Advanced-Features-purple?style=for-the-badge)

</div>

Bonus kısmında, `get_next_line` fonksiyonunun daha esnek ve güçlü hale getirilmesi hedeflenir:

### 🔀 **Çoklu Dosya Tanımlayıcısı Desteği**

| Özellik | Açıklama | Avantaj |
|---------|----------|---------|
| **Multiple FD Handling** | Birden fazla dosya eş zamanlı okuma | Concurrent file processing |
| **State Management** | Her FD için ayrı state tutma | Independent file tracking |
| **Resource Optimization** | Efficient memory per FD | Optimized resource usage |

### 📊 **Gelişmiş Özellikler**

#### 🎯 **Dinamik Buffer Yönetimi**
- Buffer boyutunun runtime'da belirlenmesi
- Adaptive buffer sizing based on file characteristics
- Memory usage optimization

#### 🔄 **Eş Zamanlı Dosya İşleme**
- Multiple file descriptor handling
- Round-robin file reading strategy
- Independent state tracking per file

#### 🛡️ **Gelişmiş Hata Yönetimi**
- Per-FD error code tracking
- Granular error reporting
- Recovery strategies for different error types

#### 📈 **EOF Durumu Optimizasyonu**
- Smart EOF detection per file
- Graceful file completion handling
- Resource cleanup optimization

---

## 📁 Dosya Yapısı

```
get_next_line/
│
├── 📄 get_next_line.c              # Ana fonksiyon implementasyonu
├── 📋 get_next_line.h              # Header dosyası ve makrolar
├── 🔧 get_next_line_utils.c        # Yardımcı fonksiyonlar
├── 📖 README.md                    # Proje dokümantasyonu
│
├── 🎁 Bonus Files:
├── 📄 get_next_line_bonus.c        # Bonus özellikleri (çoklu FD)
├── 📋 get_next_line_bonus.h        # Bonus header dosyası
├── 🔧 get_next_line_bonus_utils.c  # Bonus yardımcı fonksiyonlar
└── 🧪 test/                        # Test dosyaları
```

### 📊 **Dosya Açıklamaları**

| Dosya | İçerik | Sorumluluk |
|-------|--------|------------|
| `get_next_line.c` | Ana fonksiyon logic | Line reading algorithm |
| `get_next_line.h` | Headers ve defines | Function prototypes, BUFFER_SIZE |
| `get_next_line_utils.c` | Helper functions | String utilities, memory management |
| `*_bonus.*` | Bonus implementations | Multiple FD support |

---

## 🚀 Kurulum

### 📋 **Ön Gereksinimler**

![GCC](https://img.shields.io/badge/GCC-Required-red?style=flat-square&logo=gnu&logoColor=white)
![Make](https://img.shields.io/badge/Make-Optional-blue?style=flat-square&logo=gnu&logoColor=white)
![Unix](https://img.shields.io/badge/Unix-Compatible-green?style=flat-square&logo=linux&logoColor=white)

- **C Compiler**: `gcc` veya `clang`
- **Unix-like System**: Linux, macOS, WSL
- **File System**: Read access to test files

### 📥 **Repository Klonlama**

```bash
# Projeyi yerel sisteminize klonlayın
git clone https://github.com/skarayil/get_next_line.git
cd get_next_line
```

### 🔨 **Derleme İşlemi**

```bash
# Manuel derleme
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Bonus versiyonu
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_bonus_utils.c main.c -o gnl_bonus

# Farklı buffer boyutları ile test
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl_small
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1000 get_next_line.c get_next_line_utils.c main.c -o gnl_large
```

---

## 💻 Kullanım

### 🔗 **Projenize Entegrasyon**

```bash
# 1. Kaynak dosyaları projenize dahil edin
cp get_next_line.c get_next_line.h get_next_line_utils.c your_project/

# 2. Derlerken dahil edin
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 your_code.c get_next_line.c get_next_line_utils.c -o program
```

### 📝 **Kod Örnekleri**

#### 🟢 **Temel Kullanım**

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    // Dosyayı aç
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    // Satır satır oku
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // ÖNEMLİ: Belleği serbest bırak
    }
    
    close(fd);
    return (0);
}
```

#### 🟡 **Stdin'den Okuma**

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    
    printf("Enter lines (Ctrl+D to exit):\n");
    
    // Stdin'den oku (fd = 0)
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
    }
    
    printf("EOF reached.\n");
    return (0);
}
```

#### 🔴 **Bonus: Çoklu Dosya Okuma**

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2, fd3;
    char *line;
    
    // Birden fazla dosya aç
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);
    
    // Round-robin okuma
    for (int i = 0; i < 10; i++)
    {
        // File 1'den oku
        if ((line = get_next_line(fd1)) != NULL)
        {
            printf("File1: %s", line);
            free(line);
        }
        
        // File 2'den oku
        if ((line = get_next_line(fd2)) != NULL)
        {
            printf("File2: %s", line);
            free(line);
        }
        
        // File 3'den oku
        if ((line = get_next_line(fd3)) != NULL)
        {
            printf("File3: %s", line);
            free(line);
        }
    }
    
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
```

#### 🟣 **Error Handling Örneği**

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(const char *filename)
{
    int fd;
    char *line;
    int line_count = 0;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        line_count++;
        printf("Line %d: %s", line_count, line);
        
        // Bellek kontrolü
        if (!line)
        {
            fprintf(stderr, "Memory allocation failed\n");
            close(fd);
            return (1);
        }
        
        free(line);
    }
    
    printf("Total lines read: %d\n", line_count);
    close(fd);
    return (0);
}
```

---

## 🧪 Test Senaryoları

### ✅ **Temel Fonksiyonalite Testleri**

#### 📖 **Satır Okuma Testleri**
```c
// Normal satır okuma
test_file_content("Hello World\nSecond Line\n");
assert_line_equals(get_next_line(fd), "Hello World\n");
assert_line_equals(get_next_line(fd), "Second Line\n");
assert_null(get_next_line(fd));

// Newline olmayan son satır
test_file_content("Last line without newline");
assert_line_equals(get_next_line(fd), "Last line without newline");
assert_null(get_next_line(fd));
```

#### 📝 **Boş Dosya ve Satır Testleri**
```c
// Tamamen boş dosya
test_empty_file();
assert_null(get_next_line(fd));

// Sadece newline karakteri
test_file_content("\n\n\n");
assert_line_equals(get_next_line(fd), "\n");
assert_line_equals(get_next_line(fd), "\n");
assert_line_equals(get_next_line(fd), "\n");
assert_null(get_next_line(fd));

// Boş satırlar arası content
test_file_content("Line1\n\nLine3\n");
assert_line_equals(get_next_line(fd), "Line1\n");
assert_line_equals(get_next_line(fd), "\n");
assert_line_equals(get_next_line(fd), "Line3\n");
```

### 🔄 **Buffer Size Testleri**

#### 📊 **Farklı Buffer Boyutları**
```c
// Çok küçük buffer (BUFFER_SIZE = 1)
test_with_buffer_size(1, "Very long line that exceeds buffer size significantly");

// Büyük buffer (BUFFER_SIZE = 10000)
test_with_buffer_size(10000, "Short line");

// Exact buffer size match
test_with_buffer_size(42, "This line is exactly forty-two characters!");
```

### 🔗 **Bonus: Çoklu FD Testleri**

#### 🎯 **Eş Zamanlı Dosya Okuma**
```c
// İki dosyayı parallel oku
int fd1 = open("file1.txt", O_RDONLY);  // "Line1-File1\nLine2-File1\n"
int fd2 = open("file2.txt", O_RDONLY);  // "Line1-File2\nLine2-File2\n"

assert_line_equals(get_next_line(fd1), "Line1-File1\n");
assert_line_equals(get_next_line(fd2), "Line1-File2\n");
assert_line_equals(get_next_line(fd1), "Line2-File1\n");
assert_line_equals(get_next_line(fd2), "Line2-File2\n");

assert_null(get_next_line(fd1));
assert_null(get_next_line(fd2));
```

### ⚠️ **Hata Durumu Testleri**

#### 🚫 **Geçersiz File Descriptor**
```c
// Negatif FD
assert_null(get_next_line(-1));

// Kapalı FD
int fd = open("test.txt", O_RDONLY);
close(fd);
assert_null(get_next_line(fd));

// Çok büyük FD
assert_null(get_next_line(99999));
```

#### 🧠 **Memory Stress Tests**
```c
// Çok büyük dosya testi
create_large_file("large.txt", 1000000);  // 1M lines
test_memory_usage_while_reading("large.txt");

// Memory leak testi
for (int i = 0; i < 10000; i++) {
    test_read_entire_file("test.txt");
    // Valgrind ile kontrol et
}
```

---

## 🛠️ Teknik Detaylar

### 🏗️ **Algorithm Overview**

```
get_next_line() Algorithm:
│
├── 1. Static Buffer Management
│   ├── Maintain buffer state between calls
│   └── Handle partial line data
│
├── 2. Read Loop
│   ├── read() system call with BUFFER_SIZE
│   ├── Append to existing buffer
│   └── Search for newline character
│
├── 3. Line Extraction
│   ├── Find '\n' position
│   ├── Extract line + '\n'
│   └── Update buffer with remaining data
│
├── 4. Memory Management
│   ├── malloc() for line
│   ├── Copy extracted line
│   └── Handle EOF and cleanup
│
└── 5. Return Management
    ├── Return line (with '\n')
    ├── Return NULL on EOF
    └── Return NULL on error
```

### 🔧 **Key Implementation Details**

#### 📊 **Static Buffer Strategy**
```c
static char *buffer[FD_MAX];  // Bonus: per-FD buffers
static char buffer[BUFFER_SIZE + 1];  // Mandatory: single buffer

// Buffer state preservation between calls
// Efficient memory usage
// Newline detection optimization
```

#### 🎯 **Memory Allocation Pattern**
```c
char *line = malloc(line_length + 1);
// Exact size allocation
// No memory waste
// Proper null termination
```

#### 🔍 **Error Handling Strategy**
```c
if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
if (read_result < 0)
    return (NULL);  // Read error
if (!line_memory)
    return (NULL);  // Malloc failure
```

### 📈 **Performance Characteristics**

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(n) | Where n = line length |
| **Space Complexity** | O(BUFFER_SIZE + line_length) | Static buffer + dynamic line |
| **System Calls** | O(line_length / BUFFER_SIZE) | Minimized read() calls |
| **Memory Allocations** | O(1) per line | One malloc per line |

---

## 📚 Notlar

### ⚠️ **Önemli Dikkat Edilmesi Gerekenler**

#### 🛡️ **Bellek Yönetimi**
- **malloc() Return Check**: Her malloc return value kontrol edilmeli
- **Free Responsibility**: Caller fonksiyonun döndürülen string'i free etmesi gerekli
- **Buffer Cleanup**: Static buffer'ların program sonunda temizlenmesi
- **Memory Leaks**: Valgrind ile comprehensive testing yapılmalı

#### 🔧 **File Descriptor Yönetimi**
- **Valid FD Check**: Negatif ve invalid FD'lerin kontrol edilmesi
- **Multiple FD Support**: Bonus'ta her FD için ayrı state management
- **Resource Limits**: System FD limits'e dikkat edilmesi
- **Cleanup on Error**: Error durumlarında proper cleanup

#### 📊 **Performance Optimizasyonları**
- **Buffer Size Tuning**: BUFFER_SIZE'ın optimal değerinin bulunması
- **System Call Minimization**: read() çağrılarının optimize edilmesi
- **Memory Usage**: Static buffer kullanımının optimize edilmesi
- **Cache Locality**: Memory access pattern'larının iyileştirilmesi

### 💡 **Best Practices**

#### 🎯 **Code Quality:**
1. **Error Handling**: Comprehensive error checking her seviyede
2. **Memory Safety**: Defensive programming techniques
3. **Code Modularity**: Helper functions ile clean separation
4. **Documentation**: Complex logic için detailed comments
5. **Testing**: Edge cases ve stress testing

#### 🔍 **Debugging Tips:**
- **Valgrind**: Memory leak detection için essential
- **GDB**: Complex buffer state debugging için useful
- **printf debugging**: Buffer contents tracking için helpful
- **Static analysis**: Code quality assurance için recommended

---

## 🏆 Proje Başarıları

<div align="center">

![Score](https://img.shields.io/badge/Score-125%2F100-gold?style=for-the-badge)
![Tests](https://img.shields.io/badge/Tests-All%20Passed-success?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen?style=for-the-badge)
![Bonus](https://img.shields.io/badge/Bonus-Completed-orange?style=for-the-badge)

### 📊 **Proje İstatistikleri**

| Metrik | Değer |
|--------|-------|
| **Function Count** | 8+ |
| **Source Files** | 6 |
| **Test Cases** | 50+ |
| **Buffer Sizes Tested** | 1, 42, 1000, 10000 |
| **File Types Tested** | 10+ |
| **Memory Leak Tests** | ✅ Valgrind Clean |

</div>

---

<div align="center">

### 🎯 **Core Skills Gained**

![File I/O](https://img.shields.io/badge/File-I%2FO-blue?style=flat-square)
![Memory Management](https://img.shields.io/badge/Memory-Management-green?style=flat-square)
![Buffer Management](https://img.shields.io/badge/Buffer-Management-orange?style=flat-square)
![System Calls](https://img.shields.io/badge/System-Calls-red?style=flat-square)
![Error Handling](https://img.shields.io/badge/Error-Handling-purple?style=flat-square)

---

**📝 "get_next_line teaches you that reading is fundamental, but reading efficiently is an art."**

*Bu proje, file I/O operations ve memory management'ın nasıl optimize edileceğini öğretir.*

---

### 👨‍💻 Created by Sude Naz Karayıldırım

[![42 Profile](https://img.shields.io/badge/42%20Profile-skarayil-black?style=flat-square&logo=42&logoColor=white)](https://profile.intra.42.fr/users/skarayil)
[![GitHub](https://img.shields.io/badge/GitHub-skarayil-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/skarayil)

**⭐ Eğer bu proje işinize yaradıysa, repo'ya star vermeyi unutmayın!**

</div>
