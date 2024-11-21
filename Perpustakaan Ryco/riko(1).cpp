#include <iostream>
#include <string>
using namespace std;

struct databuku {
    string ISBN;
    string judul;
    string Penerbit;
    int jumlah;
};

struct peminjam {
    int no;
    string nama;
    string NISN;
    string kelas;
    string bukuPinjam;
    bool statusPinjam; // true jika buku dipinjam, false jika dikembalikan
};

databuku buku[15] = {
    {"1" , "Anak Semua Bangsa"      , "Bentang Pustaka", 3},
    {"2" , "Ayah"                   , "Bentang Pustaka", 3},
    {"3" , "Bumi Manusia"           , "Pustaka Sastra" , 3},
    {"4" , "Cinta Brontosaurus"     , "Gramedia"       , 3},
    {"5" , "Hafalan Shalat Delisa"  , "Republika"      , 3},
    {"6" , "Hujan"                  , "Bentang Pustaka", 3},
    {"7" , "Koala Kumal"            , "GagasMedia"     , 3},
    {"8" , "Laskar Pelangi"         , "Pustaka Sastra" , 3},
    {"9" , "Negeri 5 Menara"        , "Gramedia"       , 3},
    {"10", "Orang-Orang Biasa"      , "Bentang Pustaka", 3},
    {"11", "Perahu Kertas"          , "Bentang Pustaka", 3},
    {"12", "Pulang"                 , "Bentang Pustaka", 3},
    {"13", "Sang Pemimpi"           , "Pustaka Sastra" , 3},
    {"14", "Si Anak Pintar"         , "Bentang Pustaka", 3},
    {"15", "Supernova"              , "Bentang Pustaka", 3},
};

peminjam siswa[39] = {
    {1,  "ALDA ANASTASIA ADRIANA"      , "9801109826", "X MP 1"  ,"", false},
    {2,  "AKMALUSIRI DINATA"           , "3419300280", "XI ULW 1","", false},
    {3,  "ARDHI EKA"                   , "3334558694", "X TKJ 2" ,"", false},
    {4,  "ASYAFA TYAS DAMAYANTI"       , "6575390882", "XI TKI 1","", false},
    {5,  "AVISA VINA KHUMAIRA"         , "8294009832", "X DKV 1" ,"", false},
    {6,  "BERLIANA PUTRI"              , "8914274780", "X DKV 1" ,"", false},
    {7,  "BILLY SAPUTRA"               , "7078349385", "XI RPL 1","", false},
    {8,  "DIMAS ARYA ADIYATMA"         , "2932488516", "XI MP 3" ,"", false},
    {9,  "ECHA SAPUTRI"                , "3009252019", "XI TKJ 1","", false},
    {10, "MUHAMMAD IRFAN RAFA PUTRA"   , "8864351864", "XI RPL 2","", false},
    {11, "MUHAMMAD NUR IZZATUL HUDA"   , "8643454636", "X RPL 2" ,"", false},
    {12, "MUHAMMAD RIDWAN ANDIKA"      , "8576434958", "X RPL 1" ,"", false},
    {13, "MUHAMMAD ZAINY ARIF MIMA"    , "8764658494", "XI ANM 1","", false},
    {14, "MEGA PUTRI JELYTA"           , "8948937430", "X MP 3"  ,"", false},
    {15, "NAWFAL DWI HISAN RAMADHANI"  , "6484649480", "X TKJ 2" ,"", false},
    {16, "NIDA'UL RAHIMA"              , "6494649934", "XI AK 1" ,"", false},
    {17, "NIMAS AYU MIFTAKHUL JANAH"   , "3728706683", "XI ULW"  ,"", false},
    {18, "NUR AZIS DWI PRATAMA"        , "7864876664", "X ULW 2" ,"", false},
    {19, "NURSELA PUTRI"               , "7286274939", "X MP 3"  ,"", false},
    {20, "PILAR SAKTI INDERA WASPADA"  , "6498694658", "X BP 2"  ,"", false},
    {21, "RAJNI SABINA SUDARSONO"      , "2153769443", "XI MP 2" ,"", false},
    {22, "RANIA PUTRI SAVERA"          , "1863666877", "X RPL 1" ,"", false},
    {23, "RAYHAN MAHARDIKA"            , "4883473494", "X RPL 2" ,"", false},
    {24, "RADO FARISTRA AMSAH"         , "6846494931", "XI DKV 2","", false},
    {25, "SANIA MARIA"                 , "9435405121", "XI AK 4" ,"", false},
    {26, "SHOULTON HABIYAKSO"          , "9302846335", "X RPL 2" ,"", false},
    {27, "SINTA LESTARI"               , "7542146780", "X RPL 1" ,"", false},
    {28, "SRI MUHAMMAD HAMURWO BUMI"   , "9754321245", "XI RPL 2","", false},
    {29, "VRINSA LAUDYA PERMATA"       , "7392784634", "X AK 4"  ,"", false},
    {30, "YUAN RIZKA AGUSTIN"          , "9087654321", "X ANM 2" ,"", false},
    {31, "YUSUF LIAN RADITYA ABIDIN"   , "8899665547", "XI ANM 2","", false},
    {32, "ZAKI MAULANA AYUBI"          , "9876543210", "X DKV 1" ,"", false},
    {33, "ZHANDY SATRIA WIBAWA"        , "1234567899", "X TKJ 1" ,"", false},
    {34, "ZORINA GABRIELA VALENTINA"   , "6543211234", "X MP 3"  ,"", false},
    {35, "ZUNITA DWI HANDAYANI"        , "6543217898", "X PM 2"  ,"", false},
    {36, "ZYNA ARABELA CLLARISA"       , "7899876543", "X TKI 2" ,"", false},
    {37, "ZYNA CANTIKA PUTRI"          , "3346789981", "X AK 2"  ,"", false}
};

// Fungsi untuk menampilkan daftar buku
void tampilkanDaftarBuku() {
    cout << "\nDaftar Buku Perpustakaan:\n";
    for (int i = 0; i < 15; i++) {
        cout << i + 1 << ". " << buku[i].judul << " - " << buku[i].Penerbit;
        cout << " (Jumlah: " << buku[i].jumlah << ")\n";
    }
}

// Fungsi untuk meminjam buku
void pinjamBuku(int noPeminjam) {
    int pilihanBuku;
    cout << "\nMasukkan nomor buku yang ingin dipinjam: ";
    cin >> pilihanBuku;

    if (pilihanBuku < 1 || pilihanBuku > 15) {
        cout << "Buku tidak tersedia.\n";
        return;
    }

    // Cek apakah buku masih tersedia
    if (buku[pilihanBuku - 1].jumlah > 0) {
        // Cek status peminjaman siswa
        if (siswa[noPeminjam - 1].statusPinjam) {
            cout << "Anda sudah meminjam buku. Harap kembalikan buku terlebih dahulu.\n";
        } else {
            // Memperbarui data peminjaman
            siswa[noPeminjam - 1].bukuPinjam = buku[pilihanBuku - 1].judul;
            siswa[noPeminjam - 1].statusPinjam = true;
            buku[pilihanBuku - 1].jumlah--; // Kurangi jumlah buku yang tersedia
            cout << "Buku \"" << buku[pilihanBuku - 1].judul << "\" berhasil dipinjam.\n";
        }
    } else {
        cout << "Buku tersebut tidak tersedia. Coba pilih buku lain.\n";
    }
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku(int noPeminjam) {
    if (!siswa[noPeminjam - 1].statusPinjam) {
        cout << "Anda tidak meminjam buku apa pun.\n";
    } else {
        // Mengembalikan buku
        for (int i = 0; i < 15; i++) {
            if (buku[i].judul == siswa[noPeminjam - 1].bukuPinjam) {
                buku[i].jumlah++;  // Tambah jumlah buku yang tersedia
                break;
            }
        }

        siswa[noPeminjam - 1].statusPinjam = false; // Status peminjaman diubah
        siswa[noPeminjam - 1].bukuPinjam = "";      // Buku yang dipinjam dikosongkan
        cout << "Buku berhasil dikembalikan.\n";
    }
}

int main() {
    int pilihan, noPeminjam;

    while (true) {
        cout << "\n=== Program Peminjaman Buku ===\n";
        cout << "1. Tampilkan Daftar Buku\n";
        cout << "2. Pinjam Buku\n";
        cout << "3. Kembalikan Buku\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        }

        cout << "Masukkan nomor siswa (1-39): ";
        cin >> noPeminjam;

        if (noPeminjam < 1 || noPeminjam > 39) {
            cout << "Nomor siswa tidak valid.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                tampilkanDaftarBuku();
                break;
            case 2:
                pinjamBuku(noPeminjam);
                break;
            case 3:
                kembalikanBuku(noPeminjam);
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
/*

Algoritma Program Peminjaman Buku

Program ini merupakan aplikasi peminjaman buku sederhana dengan fungsi untuk menampilkan daftar buku, meminjam buku, dan mengembalikan buku. Berikut adalah langkah-langkah algoritma dari program tersebut:


---

1. Menampilkan Daftar Buku

Langkah Algoritma:

Program akan menampilkan daftar buku yang tersedia di perpustakaan.

Daftar buku terdiri dari judul, penerbit, dan jumlah buku yang tersedia.

Untuk setiap buku, nomor urut buku, judul, penerbit, dan jumlah buku akan ditampilkan.


Langkah-langkah:

Iterasi dari indeks 0 hingga 14 (karena ada 15 buku) untuk menampilkan data buku.

Output: Daftar buku dengan informasi yang lengkap.



---

2. Meminjam Buku

Langkah Algoritma:

Program meminta pengguna untuk memasukkan nomor siswa yang ingin meminjam buku.

Program kemudian meminta nomor buku yang ingin dipinjam.

Program akan memeriksa apakah nomor buku yang dipilih valid (antara 1 sampai 15).

Jika nomor buku valid, program memeriksa apakah buku masih tersedia dengan jumlah lebih dari 0.

Program memeriksa apakah siswa sudah meminjam buku sebelumnya. Jika sudah, siswa diminta untuk mengembalikan buku terlebih dahulu.

Jika buku tersedia dan siswa belum meminjam buku, status peminjaman siswa akan diperbarui (statusPinjam diubah menjadi true dan judul buku yang dipinjam disimpan).

Jumlah buku yang tersedia akan dikurangi 1.

Output: Jika berhasil, buku berhasil dipinjam dan jumlah buku yang tersedia dikurangi.


Langkah-langkah:

Cek apakah nomor buku valid.

Cek apakah buku masih tersedia.

Cek status peminjaman siswa.

Perbarui status peminjaman siswa dan jumlah buku yang tersedia.

Output: Konfirmasi peminjaman buku atau pesan kesalahan jika tidak bisa meminjam.



---

3. Mengembalikan Buku

Langkah Algoritma:

Program meminta nomor siswa yang ingin mengembalikan buku.

Program memeriksa apakah siswa tersebut sedang meminjam buku (statusPinjam true).

Jika siswa tidak meminjam buku, program memberi tahu bahwa buku belum dipinjam.

Jika siswa meminjam buku, buku yang dipinjam akan dikembalikan dengan cara menambah jumlah buku yang tersedia di perpustakaan.

Status peminjaman siswa akan diubah menjadi false dan buku yang dipinjam akan dihapus dari data siswa.

Output: Buku berhasil dikembalikan atau pesan kesalahan jika siswa tidak meminjam buku.


Langkah-langkah:

Cek apakah siswa meminjam buku.

Cari buku yang dipinjam dan tambah jumlah buku yang tersedia.

Perbarui status peminjaman siswa dan kosongkan data buku yang dipinjam.

Output: Konfirmasi pengembalian buku.



---

4. Keluar dari Program

Langkah Algoritma:

Program menunggu input dari pengguna untuk memilih menu keluar.

Jika pilihan menu adalah 4, program akan keluar dan menampilkan pesan terima kasih.

Program berhenti dan tidak ada aksi lebih lanjut.



---

Penjelasan Program

1. Struktur Data:

databuku adalah struktur untuk menyimpan data buku (ISBN, judul, penerbit, jumlah).

peminjam adalah struktur untuk menyimpan data peminjam (nomor siswa, nama, NISN, kelas, buku yang dipinjam, dan status peminjaman).



2. Daftar Buku dan Peminjam:

Daftar buku disimpan dalam array buku[15].

Daftar peminjam disimpan dalam array siswa[39].



3. Fungsi tampilkanDaftarBuku():

Fungsi ini digunakan untuk menampilkan daftar buku yang tersedia di perpustakaan.



4. Fungsi pinjamBuku(int noPeminjam):

Fungsi ini digunakan untuk memproses peminjaman buku. Berdasarkan input nomor siswa dan nomor buku yang dipilih, program memeriksa ketersediaan buku dan status peminjaman siswa.



5. Fungsi kembalikanBuku(int noPeminjam):

Fungsi ini digunakan untuk mengembalikan buku yang dipinjam oleh siswa. Status peminjaman siswa diperbarui dan jumlah buku yang tersedia ditambah.



6. Loop Utama:

Program menggunakan loop while(true) untuk terus menjalankan menu hingga pengguna memilih keluar (pilihan 4).

Setelah memilih menu, pengguna diminta untuk memasukkan nomor siswa yang ingin melakukan tindakan (peminjaman atau pengembalian buku).



7. Validasi Input:

Program memastikan input yang dimasukkan valid, baik untuk nomor buku (1-15) maupun nomor siswa (1-39).





---

Diagram Alur (Flowchart)

1. Tampilkan Menu Utama


2. Pilih Menu

Menu 1: Tampilkan Daftar Buku

Tampilkan semua buku.


Menu 2: Pinjam Buku

Masukkan nomor siswa.

Masukkan nomor buku.

Periksa ketersediaan buku dan status pinjam siswa.

Jika valid, perbarui status.


Menu 3: Kembalikan Buku

Masukkan nomor siswa.

Cek apakah buku sudah dipinjam.

Jika valid, kembalikan buku.


Menu 4: Keluar

Keluar dari program.






---

Program ini memungkinkan pengguna untuk mengelola peminjaman dan pengembalian buku dengan efisien menggunakan struktur data dan logika yang sederhana.


*/