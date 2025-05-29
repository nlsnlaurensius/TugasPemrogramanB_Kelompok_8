# Kelompok 8 - Integrasi Numerik (Kuadratur)

## 📜 Deskripsi Program

Program ini adalah implementasi dalam bahasa C dari metode **integrasi numerik** (juga dikenal sebagai kuadratur) untuk mengaproksimasi nilai integral tentu dari suatu fungsi matematika. Metode spesifik yang digunakan adalah **Metode Persegi Panjang (Rectangular Method) dengan evaluasi titik tengah (Midpoint Rule)**.

Program ini memungkinkan pengguna untuk:
1.  Memasukkan batas bawah dan batas atas interval integrasi.
2.  Memasukkan ukuran langkah (dx) yang diinginkan untuk aproksimasi.
3.  Menghitung perkiraan nilai integral dari fungsi yang telah ditentukan (defaultnya $f(x) = x^2$, namun dapat dengan mudah dimodifikasi di dalam kode sumber pada fungsi `fungsi_integrasi`).
4.  Menampilkan hasil integrasi numerik.
5.  Menampilkan hasil analitik (jika fungsi yang diintegrasikan adalah $f(x) = x^2$) sebagai perbandingan untuk memvalidasi akurasi metode numerik.

Program ini juga menyertakan validasi input dasar untuk memastikan bahwa batas integrasi dan ukuran langkah yang dimasukkan oleh pengguna adalah valid.

---

## 🧑‍💻 Anggota Kelompok

* 2306225981 - Jonathan Frederick Kosasih
* 2306161845 - Nelson Laurensius
* 2306209095 - Benedict Aurelius
* 2306161952 - Christian Hadiwijaya

---

## 🖼️ Gambar Referensi Materi

Untuk pemahaman konsep integrasi numerik yang lebih mendalam, beberapa gambar referensi dari buku "MATLAB Programming for Engineers" oleh Stephen J. Chapman (6th Edition) disertakan dalam folder `Materi` di *root* direktori proyek ini. 

![picture 0](./Materi/1.png) 
![picture 1](./Materi/2.png) 
![picture 2](./Materi/3.png) 
![picture 3](./Materi/4.png) 
![picture 4](./Materi/5.png) 


---


### Kompilasi 
Buka terminal atau command prompt, navigasikan ke direktori tempat file `.c` disimpan yaitu folder `Pemrograman`, dan jalankan perintah berikut:
```bash
gcc NumericalIntegration.c -o NumericalIntegration 
```

### Menjalankan Program
Setelah kompilasi berhasil, jalankan program dari terminal:
```bash
./NumericalIntegration
```
Program akan meminta Anda untuk memasukkan batas bawah, batas atas, dan ukuran langkah.

---

## 🔧 Modifikasi Fungsi Integrasi
Untuk mengintegrasikan fungsi yang berbeda, Anda perlu memodifikasi fungsi fungsi_integrasi di dalam kode sumber.

Contoh (default):
```bash
double fungsi_integrasi(double x) {
    return x * x; // f(x) = x^2
}
```
Untuk mengganti dengan, misalnya, $f(x) = \sin(x)$
```bash
#include <math.h> // Pastikan ini ada di bagian atas file

double fungsi_integrasi(double x) {
    return sin(x); // f(x) = sin(x)
}
```
Jangan lupa untuk juga menyesuaikan bagian perhitungan hasil analitik di fungsi main jika Anda ingin tetap memiliki perbandingan yang akurat.