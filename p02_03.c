// 12S25008-Rafli Batubara
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU 100

// Struct untuk manajemen menu dan stok
typedef struct {
    char nama[50];
    int harga;
    int stok;
} Menu;

Menu daftarMenu[MAX_MENU];
int jumlahMenu = 0;

// Fungsi untuk memuat data dari file ke struct (Database)
void loadData() {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) return;

    while (fscanf(file, " %49[^,],%d,%d\n", daftarMenu[jumlahMenu].nama, 
           &daftarMenu[jumlahMenu].harga, &daftarMenu[jumlahMenu].stok) != EOF) {
        jumlahMenu++;
    }
    fclose(file);
}

// Fungsi untuk menyimpan data struct kembali ke file
void saveData() {
    FILE *file = fopen("menu.txt", "w");
    for (int i = 0; i < jumlahMenu; i++) {
        fprintf(file, "%s,%d,%d\n", daftarMenu[i].nama, daftarMenu[i].harga, daftarMenu[i].stok);
    }
    fclose(file);
}

// Fungsi mencatat riwayat penjualan
void catatTransaksi(char* nama, int jumlah, int total) {
    FILE *file = fopen("riwayat.txt", "a");
    fprintf(file, "Produk: %s | Jumlah: %d | Total: Rp%d\n", nama, jumlah, total);
    fclose(file);
}

void tampilkanMenu() {
    printf("\n--- DAFTAR MENU KAFETARIA IT DEL ---\n");
    printf("%-3s | %-20s | %-10s | %-5s\n", "No", "Nama Menu", "Harga", "Stok");
    for (int i = 0; i < jumlahMenu; i++) {
        printf("%-3d | %-20s | Rp%-8d | %-5d\n", i + 1, daftarMenu[i].nama, 
               daftarMenu[i].harga, daftarMenu[i].stok);
    }
}

void pemesananInteraktif() {
    char inputNama[50];
    int jumlahBeli;
    int ditemukan = 0;

    printf("\nMasukkan nama menu yang ingin dipesan: ");
    fgets(inputNama, sizeof(inputNama), stdin);
    inputNama[strcspn(inputNama, "\n")] = 0; // Menghapus newline

    for (int i = 0; i < jumlahMenu; i++) {
        // Validasi input menggunakan strcmp
        if (strcmp(daftarMenu[i].nama, inputNama) == 0) {
            ditemukan = 1;
            printf("Stok tersedia: %d. Masukkan jumlah: ", daftarMenu[i].stok);
            scanf("%d", &jumlahBeli);
            getchar(); // Membersihkan buffer

            if (jumlahBeli <= daftarMenu[i].stok && jumlahBeli > 0) {
                int total = jumlahBeli * daftarMenu[i].harga;
                
                // Update stok otomatis
                daftarMenu[i].stok -= jumlahBeli;
                
                printf("Pesanan Berhasil! Total: Rp%d\n", total);
                
                // Simpan perubahan ke file
                saveData();
                catatTransaksi(daftarMenu[i].nama, jumlahBeli, total);
            } else {
                printf("Maaf, stok tidak mencukupi atau input tidak valid.\n");
            }
            break;
        }
    }
    if (!ditemukan) printf("Menu tidak ditemukan.\n");
}

int main() {
    loadData(); // Ambil data saat program mulai
    int pilihan;

    do {
        printf("\n=== SISTEM INFORMASI KAFETARIA IT DEL ===\n");
        printf("1. Lihat Menu\n");
        printf("2. Pesan Makanan/Minuman\n");
        printf("3. Keluar\n");
        printf("Pilih menu (1-3): ");
        scanf("%d", &pilihan);
        getchar(); // Membersihkan buffer setelah scanf

        switch (pilihan) {
            case 1: tampilkanMenu(); break;
            case 2: pemesananInteraktif(); break;
            case 3: printf("Terima kasih!\n"); break;
            default: printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    return 0;
}