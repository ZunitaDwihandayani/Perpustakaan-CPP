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

// Data buku yang tersedia
databuku buku[20] = {
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

// Data peminjam siswa
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
void tampilkanBuku() {
    cout << "\nDaftar Buku:\n";
    for (int i = 0; i < 15; i++) {
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
    for (int i = 0; i < 39; i++) {
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

    // Menambahkan buku baru ke dalam array buku
    for (int i = 0; i < 20; i++) {
        if (buku[i].ISBN == "") { // Mencari posisi kosong
            buku[i].ISBN = ISBN;
            buku[i].judul = judul;
            buku[i].penerbit = penerbit;
            buku[i].jumlah = jumlah;
            cout << "Buku baru berhasil ditambahkan!\n";
            break;
        }
    }
}

int main() {
    int pilihan;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Daftar Buku\n";
        cout << "2. Tampilkan Siswa Peminjam\n";
        cout << "3. Tambah Buku\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        cin.ignore();  // Membersihkan buffer input

        if (pilihan == 1) {
            tampilkanBuku();  // Menampilkan daftar buku
        } else if (pilihan == 2) {
            tampilkanSiswaPeminjam();  // Menampilkan daftar siswa yang meminjam buku
        } else if (pilihan == 3) {
            tambahBuku();  // Menambahkan buku baru
        } else if (pilihan == 4) {
            cout << "Keluar dari program.\n";
            break;  // Keluar dari perulangan dan program
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    }
    return 0;
}
