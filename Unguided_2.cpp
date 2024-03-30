#include <iostream>
#include <vector>

using namespace std;

struct Produk
{
    string nama;
    int harga;
};

class TokoSkincare
{
private:
    vector<Produk> produkList;

public:
    void tambahData(string nama, int harga)
    {
        Produk newProduk;
        newProduk.nama = nama;
        newProduk.harga = harga;
        produkList.push_back(newProduk);
    }

    void hapusData(string nama)
    {
        for (int i = 0; i < produkList.size(); i++)
        {
            if (produkList[i].nama == nama)
            {
                produkList.erase(produkList.begin() + i);
                return;
            }
        }
        cout << "Produk " << nama << " tidak ditemukan!" << endl;
    }

    void updateData(string nama, int harga)
    {
        bool found = false;
        for (int i = 0; i < produkList.size(); i++)
        {
            if (produkList[i].nama == nama)
            {
                produkList[i].harga = harga;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Produk " << nama << " tidak ditemukan!" << endl;
        }
    }

    void tambahDataUrutanTertentu(string nama, int harga, int urutan)
    {
        if (urutan < 0 || urutan > produkList.size())
        {
            cout << "Urutan tidak valid!" << endl;
            return;
        }
        Produk newProduk;
        newProduk.nama = nama;
        newProduk.harga = harga;
        produkList.insert(produkList.begin() + urutan, newProduk);
    }

    void hapusDataUrutanTertentu(int urutan)
    {
        if (urutan < 0 || urutan >= produkList.size())
        {
            cout << "Urutan tidak valid!" << endl;
            return;
        }
        produkList.erase(produkList.begin() + urutan);
    }

    void tampilkanData()
    {
        cout << "============================" << endl;
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "============================" << endl;
        for (Produk produk : produkList)
        {
            cout << "Nama Produk: " << produk.nama << endl;
            cout << "Harga: " << produk.harga << endl
                 << endl;
        }
    }

    void hapusSeluruhData()
    {
        produkList.clear();
        cout << "Data berhasil dihapus!" << endl;
    }
};

int main()
{
    TokoSkincare toko;

    // Menambahkan beberapa produk awal
    toko.tambahData("Originote", 60000);
    toko.tambahData("Somethinc", 150000);
    toko.tambahData("Skintific", 100000);
    toko.tambahData("Wardah", 50000);
    toko.tambahData("Hanasui", 30000);

    int pilihan;
    string nama;
    int harga, urutan;

    do
    {
        cout << "\n============================" << endl;
        cout << "Menu Toko Skincare Purwokerto" << endl;
        cout << "============================" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl
             << endl;

        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama produk: ";
            cin >> nama;
            cout << "Masukkan harga produk: ";
            cin >> harga;
            toko.tambahData(nama, harga);
            break;
        case 2:
            cout << "Masukkan nama produk yang ingin dihapus: ";
            cin >> nama;
            toko.hapusData(nama);
            break;
        case 3:
            cout << "Masukkan nama produk yang ingin diupdate: ";
            cin >> nama;
            cout << "Masukkan harga baru: ";
            cin >> harga;
            toko.updateData(nama, harga);
            break;
        case 4:
            cout << "Masukkan nama produk: ";
            cin >> nama;
            cout << "Masukkan harga produk: ";
            cin >> harga;
            cout << "Masukkan urutan penempatan (1-based): ";
            cin >> urutan;
            toko.tambahDataUrutanTertentu(nama, harga, urutan - 1);
            break;
        case 5:
            cout << "Masukkan urutan data yang ingin dihapus (1-based): ";
            cin >> urutan;
            toko.hapusDataUrutanTertentu(urutan - 1);
            break;
        case 6:
            toko.hapusSeluruhData();
            break;
        case 7:
            toko.tampilkanData();
            break;
        case 8:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
}
