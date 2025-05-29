#include <stdio.h>
#include <math.h> // Untuk fungsi matematika seperti pow() dan sqrt()

// Deklarasi fungsi yang akan diintegrasikan
double fungsi_integrasi(double x);

// Fungsi untuk menghitung integral tentu dengan metode persegi panjang (titik tengah)
double integrasi_numerik(double (*fun_ptr)(double), double x1, double x2, double dx);

int main() {
    double batas_bawah, batas_atas, ukuran_langkah;
    double hasil_integral;

    printf("Program Integrasi Numerik (Metode Persegi Panjang - Titik Tengah)\n");
    printf("-----------------------------------------------------------------\n");
    printf("Fungsi yang akan diintegrasikan: f(x) = x^2\n\n");

    printf("Masukkan batas bawah integrasi (x1): ");
    scanf("%lf", &batas_bawah);

    printf("Masukkan batas atas integrasi (x2): ");
    scanf("%lf", &batas_atas);

    printf("Masukkan ukuran langkah (dx) yang diinginkan: ");
    scanf("%lf", &ukuran_langkah);

    // Hitung nilai integral dengan metode numerik
    hasil_integral = integrasi_numerik(fungsi_integrasi, batas_bawah, batas_atas, ukuran_langkah);

    printf("\nPerkiraan nilai integral dari %.2f hingga %.2f dengan dx = %.4f adalah: %.6f\n",
           batas_bawah, batas_atas, ukuran_langkah, hasil_integral);

    // Hitung nilai analitik untuk perbandingan (khusus f(x) = x^2)
    double hasil_analitik = (pow(batas_atas, 3) / 3.0) - (pow(batas_bawah, 3) / 3.0);
    printf("Nilai analitik (untuk f(x)=x^2): %.6f\n", hasil_analitik);

    return 0;
}

// Fungsi yang akan diintegrasikan, misal f(x) = x^2
double fungsi_integrasi(double x) {
    return x * x;
    // Bisa diganti dengan fungsi lain, misal: return sin(x);
    // Atau fungsi distribusi normal: return exp(-pow(x,2)/2.0) / sqrt(2*M_PI);
}

// Fungsi untuk menghitung integral tentu dengan metode persegi panjang (titik tengah)
double integrasi_numerik(double (*fun_ptr)(double), double x1, double x2, double dx) {
    if (x1 >= x2) {
        printf("Error: Batas bawah harus lebih kecil dari batas atas.\n");
        return 0.0;
    }
    if (dx <= 0) {
        printf("Error: Ukuran langkah harus positif.\n");
        return 0.0;
    }

    double total_luas = 0.0;
    double x_sekarang;
    double tinggi;
    int jumlah_persegi_panjang;

    // Hitung berapa banyak persegi panjang yang digunakan
    jumlah_persegi_panjang = floor((x2 - x1) / dx);
    double dx_fix = (x2 - x1) / jumlah_persegi_panjang; // Supaya pas sampai x2

    // Proses integrasi numerik
    for (int i = 0; i < jumlah_persegi_panjang; i++) {
        x_sekarang = x1 + (i * dx_fix);
        // Ambil nilai fungsi di titik tengah interval
        tinggi = fun_ptr(x_sekarang + dx_fix / 2.0);
        total_luas += dx_fix * tinggi;
    }

    return total_luas;
}
