# Tugas Kelompok - Aplikasi Queue

Repositori ini berisi implementasi program simulasi antrean layanan oleh pengunjung pada sebuah instansi menggunakan bahasa C. Program ini merupakan tugas kelompok untuk mengimplementasikan Abstract Data Type (ADT) Queue.

## Anggota Kelompok 1

1. **Ahmad Bilal Murtadho** - 24060125140186
   - Tugas: Modul Pengunjung dan Finalisator Laporan
2. **Joshua Briliant Suryana** - 24060125120048
   - Tugas: Modul Queue (Antrean)
3. **Wendi Adi Ardiansah** - 24060125120027
   - Tugas: Modul Loket
4. **Raditya Arganta Anantio** - 24060125120021
   - Tugas: Modul Setup Skenario dan Kamus Data (Main Program - Awal)
5. **Benedictus David Purnomo** - 24060125140179
   - Tugas: Modul Logika Simulasi dan Output (Main Program - Inti)

## Deskripsi Program

Program ini mensimulasikan antrean layanan pengunjung dengan aturan sebagai berikut:
- Terdapat 4 jenis layanan: Administrasi (A), Pembayaran (B), Informasi (I), dan Pengaduan (P).
- Pengunjung dilayani berdasarkan prinsip FIFO (First In First Out).
- Terdapat 4 loket dengan ketentuan penanganan:
  - Loket 1: Melayani Administrasi dan Pembayaran (A, B)
  - Loket 2: Melayani Pembayaran (B)
  - Loket 3: Melayani Informasi dan Pengaduan (I, P)
  - Loket 4: Melayani Pengaduan (P)
- Loket hanya mengambil pengunjung dari layanan yang sesuai dengan kapasitasnya.
- Jika terdapat beberapa loket kosong yang dapat melayani layanan yang sama, prioritas diberikan kepada loket dengan ID terkecil.

## Struktur File Modular

Kode program dibagi menjadi beberapa *file header* (.h) dan *file source* (.c) agar lebih terstruktur:
- `boolean.h`: Definisi tipe data boolean dasar.
- `pengunjung.h` & `pengunjung.c`: ADT Pengunjung beserta operasinya.
- `queue.h` & `queue.c`: ADT QueueP menggunakan representasi array.
- `loket.h` & `loket.c`: ADT Loket beserta operasi perubahan status dan pencatatan riwayat.
- `main.c`: Program utama untuk inisialisasi data dan eksekusi simulasi layanan.

## Cara Menjalankan Program

1. Clone repositori ini ke komputer lokal:
   ```bash
   git clone [https://github.com/][Username-GitHub-Kamu]/Kelompok1-Aplikasi-Queue.git
   ```
2. Buka folder proyek di Terminal atau Command Prompt.
3. Lakukan kompilasi (compile) menggunakan compiler C (seperti GCC):
   ```bash
   gcc main.c pengunjung.c queue.c loket.c -o program_antrean
   ```
4. Jalankan program hasil kompilasi:
   ```bash
   ./program_antrean
   ```