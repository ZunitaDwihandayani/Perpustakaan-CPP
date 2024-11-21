
#include <iostream> //untuk input - output cin dan cout
#include <vector>  //
#include <string> //

using namespace std;

// Struktur data untuk siswa/peminjam
struct Siswa {
    string nama;   // Nama siswa
    string nis;    // Nomor Induk Siswa
    string kelas;  // Kelas siswa
};

// Fungsi untuk menambah data siswa
void tambahSiswa(vector<Siswa>& daftarSiswa) {
    char lanjut;  // Variabel untuk menanyakan apakah ingin menambah data lagi
    do {
        Siswa siswaBaru;  // Membuat objek Siswa baru untuk menyimpan data siswa

        // Input nama siswa
        cout << "Masukkan nama siswa: ";
        getline(cin, siswaBaru.nama);

        // Input NIS siswa
        cout << "Masukkan NIS siswa: ";
        getline(cin, siswaBaru.nis);

        // Input kelas siswa
        cout << "Masukkan kelas siswa: ";
        getline(cin, siswaBaru.kelas);

        // Menambahkan siswa baru ke dalam vector
        daftarSiswa.push_back(siswaBaru);
        cout << "Data siswa berhasil ditambahkan!\n";

        // Menanyakan apakah pengguna ingin menambah data lagi
        cout << "Apakah ingin menambah data lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore();  // Membersihkan buffer input setelah menerima karakter
    } while (lanjut == 'y' || lanjut == 'Y');  // Perulangan akan terus berlanjut jika pengguna menekan 'y' atau 'Y'
}

// Fungsi untuk menampilkan daftar siswa
void tampilkanSiswa(const vector<Siswa>& daftarSiswa) {
    // Mengecek apakah daftar siswa kosong
    if (daftarSiswa.empty()) {
        cout << "Tidak ada data siswa.\n";
        return;  // Jika daftar kosong, keluar dari fungsi
    }

    // Menampilkan daftar siswa jika ada data
    cout << "\nDaftar Siswa/Peminjam:\n";
    for (size_t i = 0; i < daftarSiswa.size(); ++i) {  // Perulangan untuk menampilkan semua siswa
        cout << i + 1 << ". Nama: " << daftarSiswa[i].nama
             << ", NIS: " << daftarSiswa[i].nis
             << ", Kelas: " << daftarSiswa[i].kelas << "\n";
    }
}

int main() {
    vector<Siswa> daftarSiswa;  // Vector untuk menyimpan data siswa
    int pilihan;  // Variabel untuk menyimpan pilihan menu pengguna

    // Menggunakan perulangan untuk menu utama
    while (true) {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Masukkan Data Siswa\n";
        cout << "2. Menampilkan Daftar Siswa\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();  // Membersihkan buffer input setelah pilihan

        // Menggunakan percabangan untuk memproses pilihan
        if (pilihan == 1) {
            tambahSiswa(daftarSiswa);  // Menambahkan data siswa
        } else if (pilihan == 2) {
            tampilkanSiswa(daftarSiswa);  // Menampilkan daftar siswa
        } else if (pilihan == 3) {
            cout << "Keluar dari program.\n";
            break;  // Keluar dari perulangan dan menghentikan program
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.";  // Input yang tidak valid
        }
    }

    return 0;
}

