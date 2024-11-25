#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk Buku
struct databuku {
    string ISBN;
    string judul;
    string penerbit;
    int jumlah;  // Jumlah buku yang tersedia
};

// Struktur data untuk Peminjam
struct peminjam {
    int no;
    string nama;
    string NISN;
    string kelas;
    string bukuPinjam; // Buku yang dipinjam
    bool statusPinjam; // true jika buku dipinjam, false jika dikembalikan
};

// Data buku yang tersedia (array statis)
databuku buku[100] = {
    {"1", "Anak Semua Bangsa", "Bentang Pustaka", 3},
    {"2", "Ayah", "Bentang Pustaka", 3},
    {"3", "Bumi Manusia", "Pustaka Sastra", 3},
    {"4", "Cinta Brontosaurus", "Gramedia", 3},
    {"5", "Hafalan Shalat Delisa", "Republika", 3},
    {"6", "Hujan", "Bentang Pustaka", 3},
    {"7", "Koala Kumal", "GagasMedia", 3},
    {"8", "Laskar Pelangi", "Pustaka Sastra", 3},
    {"9", "Negeri 5 Menara", "Gramedia", 3},
    {"10", "Orang-Orang Biasa", "Bentang Pustaka", 3},
    {"11", "Perahu Kertas", "Bentang Pustaka", 3},
    {"12", "Pulang", "Bentang Pustaka", 3},
    {"13", "Sang Pemimpi", "Pustaka Sastra", 3},
    {"14", "Si Anak Pintar", "Bentang Pustaka", 3},
    {"15", "Supernova", "Bentang Pustaka", 3}
};

// Data peminjam siswa (array statis)
peminjam siswa[100] = {
    {1, "ALDA ANASTASIA ADRIANA", "9801109826", "X MP 1", "", false},
    {2, "AKMALUSIRI DINATA", "3419300280", "XI ULW 1", "", false},
    // Tambahkan siswa lainnya sesuai kebutuhan
};

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku() {
    cout << "\nDaftar Buku:\n";
    for (int i = 0; i < 15; i++) {  // Menampilkan buku yang ada
        cout << "ISBN: " << buku[i].ISBN
             << ", Judul: " << buku[i].judul
             << ", Penerbit: " << buku[i].penerbit
             << ", Jumlah Tersedia: " << buku[i].jumlah << endl;
    }
}

// Fungsi untuk menampilkan daftar siswa yang meminjam buku
void tampilkanSiswaPeminjam() {
    cout << "\nDaftar Siswa Peminjam Buku:\n";
    bool adaPeminjam = false;
    for (int i = 0; i < 100; i++) {  // Menampilkan siswa yang meminjam buku
        if (siswa[i].statusPinjam) {
            cout << "Nama: " << siswa[i].nama
                 << ", Buku yang dipinjam: " << siswa[i].bukuPinjam << endl;
            adaPeminjam = true;
        }
    }
    if (!adaPeminjam) {
        cout << "Tidak ada siswa yang meminjam buku saat ini.\n";
    }
}

// Fungsi untuk menambahkan buku baru
void tambahBuku() {
    string ISBN, judul, penerbit;
    int jumlah;

    cout << "\nMasukkan ISBN buku: ";
    cin >> ISBN;
    cin.ignore();  // Membersihkan buffer input
    cout << "Masukkan Judul buku: ";
    getline(cin, judul);
    cout << "Masukkan Penerbit buku: ";
    getline(cin, penerbit);
    cout << "Masukkan Jumlah buku yang akan ditambahkan: ";
    cin >> jumlah;

    // Cari indeks buku yang kosong untuk dimasukkan
    for (int i = 0; i < 100; i++) {
        if (buku[i].ISBN.empty()) {  // Cek apakah posisi ini kosong
            buku[i].ISBN = ISBN;
            buku[i].judul = judul;
            buku[i].penerbit = penerbit;
            buku[i].jumlah = jumlah;
            cout << "Buku baru berhasil ditambahkan!\n";
            return;
        }
    }
    cout << "Maaf, kapasitas buku sudah penuh.\n";
}

// Fungsi untuk menambahkan siswa baru
void tambahSiswa() {
    string nama, nisn, kelas;

    // Cari siswa yang belum ada
    for (int i = 0; i < 100; i++) {
        if (siswa[i].nama.empty()) {  // Jika nama kosong, berarti posisi bisa diisi
            cout << "Masukkan nama siswa: ";
            cin.ignore();
            getline(cin, siswa[i].nama);  // Input nama siswa
            cout << "Masukkan NISN siswa: ";
            getline(cin, siswa[i].NISN);  // Input NISN siswa
            cout << "Masukkan kelas siswa: ";
            getline(cin, siswa[i].kelas);  // Input kelas siswa

            siswa[i].no = i + 1;  // Mengisi nomor siswa dengan urutan
            siswa[i].statusPinjam = false;  // Status pinjam belum
            siswa[i].bukuPinjam = "";  // Tidak ada buku yang dipinjam
            cout << "Siswa berhasil ditambahkan!\n";
            return;
        }
    }
    cout << "Maaf, kapasitas siswa sudah penuh.\n";
}

// Fungsi untuk menambahkan peminjam
void tambahPeminjam() {
    int nomorSiswa;
    string isbnBuku;

    cout << "\nDaftar Siswa:\n";
    for (int i = 0; i < 100; i++) {  // Menampilkan semua siswa yang ada
        if (!siswa[i].nama.empty()) {
            cout << siswa[i].no << ". " << siswa[i].nama << " (" << siswa[i].kelas << ")\n";
        }
    }

    cout << "\nMasukkan nomor siswa yang akan meminjam buku: ";
    cin >> nomorSiswa;

    if (nomorSiswa < 1 || nomorSiswa > 100 || siswa[nomorSiswa - 1].nama.empty()) {
        cout << "Nomor siswa tidak valid.\n";
        return;
    }

    // Cek apakah siswa sudah meminjam buku
    if (siswa[nomorSiswa - 1].statusPinjam) {
        cout << "Siswa ini sudah meminjam buku. Harap kembalikan buku terlebih dahulu.\n";
        return;
    }

    // Menampilkan daftar buku
    tampilkanBuku();

    // Memilih buku
    cout << "\nMasukkan ISBN buku yang ingin dipinjam: ";
    cin >> isbnBuku;

    bool bukuDitemukan = false;
    for (int i = 0; i < 100; i++) {
        if (buku[i].ISBN == isbnBuku) {
            bukuDitemukan = true;

            // Cek ketersediaan buku
            if (buku[i].jumlah > 0) {
                buku[i].jumlah--;  // Kurangi jumlah buku
                siswa[nomorSiswa - 1].bukuPinjam = buku[i].judul;
                siswa[nomorSiswa - 1].statusPinjam = true;
                cout << "Buku berhasil dipinjam!\n";
            } else {
                cout << "Maaf, buku ini sedang tidak tersedia.\n";
            }
            break;
        }
    }

    if (!bukuDitemukan) {
        cout << "ISBN buku tidak ditemukan.\n";
    }
}

int main() {
    int pilihan;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Daftar Buku\n";
        cout << "2. Tampilkan Siswa Peminjam\n";
        cout << "3. Tambah Buku\n";
        cout << "4. Tambah Peminjam\n";
        cout << "5. Keluar\n";
        cout << "6. Tambah Siswa Baru\n";  // Pilihan baru untuk menambah siswa
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        cin.ignore();  // Membersihkan buffer input

        if (pilihan == 1) {
            tampilkanBuku();  // Menampilkan daftar buku
        } else if (pilihan == 2) {
            tampilkanSiswaPeminjam();  // Menampilkan daftar siswa yang meminjam buku
        } else if (pilihan == 3) {
            tambahBuku();  // Menambahkan buku baru
        } else if (pilihan == 4) {
            tambahPeminjam();  // Menambahkan siswa peminjam
        } else if (pilihan == 5) {
            cout << "Keluar dari program.\n";
            break;  // Keluar dari perulangan dan program
        } else if (pilihan == 6) {
            tambahSiswa();  // Menambahkan siswa baru
        } else {
            cout << "Pilihan tidak valid, silahkan coba lagi.\n";
        }
    }
    return 0;
}
