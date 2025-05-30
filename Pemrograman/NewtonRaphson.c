#include <stdio.h>
#include <math.h> // Untuk fungsi matematika seperti fabs()

// Deklarasi fungsi yang akan digunakan

/*
 * Fungsi f(x) yang akan dicari akarnya.
 * Contoh: f(x) = x^2 - 4
 * Silakan ganti sesuai kebutuhan.
 */
double fungsi(double x);

/*
 * Turunan dari fungsi f(x).
 * Untuk f(x) = x^2 - 4, turunannya adalah 2x.
 * Pastikan turunan sesuai jika fungsi diubah.
 */
double turunan_fungsi(double x);

/*
 * Implementasi metode Newton-Raphson.
 * Mengembalikan jumlah iterasi, atau -1 jika gagal konvergen.
 * Hasil akar disimpan di alamat ptr_akar.
 */
int metode_newton_raphson(double tebakan_awal, double toleransi, int maks_iterasi, double *ptr_akar);

// Fungsi utama
int main() {
    double tebakan_awal_input;
    double toleransi_input = 0.00001;
    int maks_iterasi_input = 100;
    double akar_ditemukan;
    int jumlah_iterasi;

    printf("Program Metode Newton-Raphson\n");
    printf("----------------------------------\n");
    printf("Fungsi yang akan dicari akarnya: f(x) = e^(-x) - x\n");
    printf("Turunan fungsi: f'(x) = -e^(-x) - 1\n\n");

    printf("Masukkan tebakan awal: ");
    scanf("%lf", &tebakan_awal_input);

    printf("Masukkan toleransi error (misal, 0.00001): ");
    scanf("%lf", &toleransi_input);

    printf("Masukkan jumlah maksimum iterasi (misal, 100): ");
    scanf("%d", &maks_iterasi_input);

    jumlah_iterasi = metode_newton_raphson(tebakan_awal_input, toleransi_input, maks_iterasi_input, &akar_ditemukan);

    if (jumlah_iterasi != -1) {
        printf("\nAkar ditemukan setelah %d iterasi.\n", jumlah_iterasi);
        printf("Akar perkiraan: %.6f\n", akar_ditemukan);
        printf("Nilai f(akar): %.6f\n", fungsi(akar_ditemukan));
    } else {
        printf("\nMetode gagal konvergen setelah %d iterasi.\n", maks_iterasi_input);
        printf("Akar terakhir: %.6f\n", akar_ditemukan);
        printf("Nilai f(akar terakhir): %.6f\n", fungsi(akar_ditemukan));
    }

    printf("\nAkar analitik untuk f(x) = x^2 - 4 adalah 2.000000 dan -2.000000.\n");

    return 0;
}

// Definisi fungsi f(x)
double fungsi(double x) {
    return exp(-x) - x; // f(x) = e^(-x) - x
    // Contoh lain:
    // return x*x*x - x - 1;
    // return cos(x) - x;
}

// Definisi turunan f(x)
double turunan_fungsi(double x) {
    return -exp(-x) - 1.0; // f'(x) = -e^(-x) - 1
    // Contoh lain:
    // return 3*x*x - 1;
    // return -sin(x) - 1;
}

// Implementasi metode Newton-Raphson
int metode_newton_raphson(double tebakan_awal, double toleransi, int maks_iterasi, double *ptr_akar) {
    double x0 = tebakan_awal;
    double x1;
    double fx0;
    double f_turunan_x0;
    int iterasi = 0;

    printf("\nIterasi |    x_i    |   f(x_i)   |  f'(x_i)  |   x_{i+1}  |  |x1-x0|/|x1| \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        fx0 = fungsi(x0);
        f_turunan_x0 = turunan_fungsi(x0);

        // Cek jika turunan mendekati nol
        if (fabs(f_turunan_x0) < 1e-9) {
            printf("Error: Turunan mendekati nol pada x = %f. Proses dihentikan.\n", x0);
            *ptr_akar = x0;
            return -1;
        }

        x1 = x0 - fx0 / f_turunan_x0;

        double error_relatif = (fabs(x1) > toleransi) ? fabs((x1 - x0) / x1) : fabs(x1-x0);
        printf("%5d   | %9.6f | %10.6f | %9.6f | %10.6f | %12.6e \n",
               iterasi, x0, fx0, f_turunan_x0, x1, error_relatif);

        x0 = x1;
        iterasi++;

        if (iterasi >= maks_iterasi) {
            printf("Peringatan: Iterasi maksimum tercapai.\n");
            *ptr_akar = x1;
            return -1;
        }

    } while ((fabs(x1) > toleransi ? fabs((x1 - (x0 - fx0 / f_turunan_x0)) / x1) : fabs(x1 - (x0 - fx0 / f_turunan_x0))) > toleransi && fabs(fungsi(x1)) > toleransi);

    *ptr_akar = x1;
    return iterasi;
}
