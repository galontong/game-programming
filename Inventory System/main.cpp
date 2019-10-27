#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    vector<string> daftarItem {"Pedang","Mace","Pistol","Tongkat","Kayu"};
    vector<int> daftarStat {8,9,12,5,3};
    vector<int> daftarInventory; //MENYIMPAN INDEX PADA DAFTAR STAT & DAFTAR ITEM
    vector<int>::iterator penunjuk;
    int jumlahInventory,pilihan,indexAcak,pilihHapus;
    char lanjut = 'y';
    srand(static_cast<unsigned int> (time(0))); //MEMBUAT NILAI RANDOM KETIKA PROGRAM PERTAMA KALI DIJALANKAN

    cout << "Jumlah item tersedia : " << daftarItem.size() << endl;
    cout << "Masukan jumlah inventory : ";
    cin >> jumlahInventory;

    while(lanjut == 'y' || lanjut == 'Y'){
        //PILIHAN MENU
        cout << endl;
        cout << "Inventory System " << endl;
        cout << "1. Lihat Inventory " << endl;
        cout << "2. Hapus Inventory " << endl;
        cout << "3. Tambah Inventory " << endl;
        cout << "pilihan : ";
        cin >> pilihan;

        if(pilihan == 1){ //LIHAT INVENTORY
            cout << endl;
            cout << "Daftar di inventory" << endl;
            cout << endl;
            if(daftarInventory.size() == 0)
                cout << "Inventory Kosong ! " << endl;
            else{
                for(penunjuk = daftarInventory.begin(); penunjuk != daftarInventory.end(); penunjuk++)
                    cout << daftarItem[(*penunjuk)] << " Dengan Kekuatan : " << daftarStat[(*penunjuk)] << endl;
            }
        }
        else if(pilihan == 2){ //HAPUS INVENTORY
            if(daftarInventory.size() == 0)
                cout << "Tidak Ada Item !" << endl;
            else{
                cout << "Pilih item yang ingin di hapus : ";
                cin >> pilihHapus;
                daftarInventory.erase(daftarInventory.begin()+pilihHapus-1); //MENGHAPUS NILAI INDEX YANG DISIMPAN DI DAFTAR INVENTORY
                cout << "Item " << daftarItem[daftarInventory[pilihHapus]] << " telah di hapus" << endl;
            }
        }
        else if(pilihan == 3){ //TAMBAH INVENTORY
            if(daftarInventory.size() == jumlahInventory)
                cout << "Inventory Penuh !" << endl;
            else{
                indexAcak = rand() % daftarItem.size(); //MENGAMBIL NILAI ACAK UNTUK INDEX DAFTAR ITEM
                daftarInventory.push_back(indexAcak); //MENAMBAH INDEX ACAK DAFTAR ITEM KE DAFTAR INVENTORY
                cout << endl;
                cout << "Mendapatkan item " << daftarItem[indexAcak] << " dengan kekuatan " << daftarStat[indexAcak] << endl;
            }
        }

        cout << endl;
        cout << "Apakah ingin lanjut (Y/N) ? ";
        cin >> lanjut;
    }
    return 0;
}
