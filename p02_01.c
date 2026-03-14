// 12S25008-Rafli Batubara
#include <stdio.h>
#include <string.h>

int main() {
    char kodeKota[10];
    float beratButet, beratUcok, totalBerat, tarifPerKg, totalOngkir;
    char namaKota[20], keterangan[20], infoPromo[100];
    int luarPulau;

    printf("=== Program Kasir Del-Express ===\n");
    printf("Ketik 'END' pada kode kota untuk keluar.\n\n");

    while (1) {
        printf("Masukkan Kode Kota (MDN/BLG/JKT/SBY): ");
        scanf("%s", kodeKota);

        // Berhenti jika input adalah END
        if (strcmp(kodeKota, "END") == 0) {
            break;
        }

        printf("Masukkan Berat Paket Butet (kg): ");
        scanf("%f", &beratButet);

        // Logika penentuan tarif dan lokasi berdasarkan tabel
        luarPulau = 0; // 0 = Dalam Pulau, 1 = Luar Pulau
        if (strcmp(kodeKota, "MDN") == 0) {
            strcpy(namaKota, "Medan");
            tarifPerKg = 8000;
        } else if (strcmp(kodeKota, "BLG") == 0) {
            strcpy(namaKota, "Balige");
            tarifPerKg = 5000;
        } else if (strcmp(kodeKota, "JKT") == 0) {
            strcpy(namaKota, "Jakarta");
            tarifPerKg = 12000;
            luarPulau = 1;
        } else if (strcmp(kodeKota, "SBY") == 0) {
            strcpy(namaKota, "Surabaya");
            tarifPerKg = 13000;
            luarPulau = 1;
        } else {
            printf("Kode kota tidak valid! Silakan coba lagi.\n\n");
            continue;
        }

        // Perhitungan berat
        beratUcok = (3.0 / 2.0) * beratButet;
        totalBerat = beratButet + beratUcok;
        totalOngkir = totalBerat * tarifPerKg;

        // Cek Promo Lebaran
        strcpy(infoPromo, "");
        if (totalBerat > 10) {
            float diskon = totalOngkir * 0.10;
            totalOngkir -= diskon;
            strcat(infoPromo, "- Diskon 10% (Berat > 10kg)\n");
        }
        
        if (luarPulau == 1) {
            strcat(infoPromo, "- Mendapatkan Asuransi Gratis (Luar Pulau)\n");
        }

        if (strlen(infoPromo) == 0) {
            strcpy(infoPromo, "- Tidak ada promo yang didapat\n");
        }

        // Output Struk
        printf("\n==================================\n");
        printf("      STRUK PENGIRIMAN DEL      \n");
        printf("==================================\n");
        printf("Kota Tujuan    : %s\n", namaKota);
        printf("Berat Butet    : %.2f kg\n", beratButet);
        printf("Berat Ucok     : %.2f kg\n", beratUcok);
        printf("Total Berat    : %.2f kg\n", totalBerat);
        printf("----------------------------------\n");
        printf("Total Ongkir   : Rp %.2f\n", totalOngkir);
        printf("Informasi Promo:\n%s", infoPromo);
        printf("==================================\n\n");
    }

    printf("Terima kasih telah menggunakan layanan Del-Express!\n");
    return 0;
}