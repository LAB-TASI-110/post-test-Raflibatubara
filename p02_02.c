// 12S25008-Rafli Batubara
#include <stdio.h>

int main() {
    int N, kategori, totalStok = 0;

    // 1. Input Jumlah Total Data (N)
    scanf("%d", &N);

    int s[N]; // Deklarasi array sebesar N

    // 2. Input Deret Stok (s1, s2, ..., sN)
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }

    // 3. Input Kode Kategori (1 untuk Ganjil, 2 untuk Genap)
    scanf("%d", &kategori);

    // Proses Perhitungan berdasarkan Kategori
    for (int i = 0; i < N; i++) {
        // Penjelasan Posisi: 
        // Indeks array dimulai dari 0. 
        // Posisi ke-1 (Ganjil) = indeks 0, 2, 4...
        // Posisi ke-2 (Genap)  = indeks 1, 3, 5...
        
        if (kategori == 1) {
            // Cek jika posisi urutan barang adalah Ganjil
            if ((i + 1) % 2 != 0) {
                totalStok += s[i];
            }
        } else if (kategori == 2) {
            // Cek jika posisi urutan barang adalah Genap
            if ((i + 1) % 2 == 0) {
                totalStok += s[i];
            }
        }
    }

    // Output hasil akhir saja
    printf("%d\n", totalStok);

    return 0;
}