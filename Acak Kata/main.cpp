#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string kata,kataAcak;
    int randIndex;
    char tempc;

    cout << "Masukan Kata : ";
    cin >> kata;
    kataAcak = kata;



    srand(static_cast<unsigned int> (time(0)));
    for(int i = 0;i<kata.size();i++){ //AKAN MENUKAR NILAI PADA INDEX 0 S/D PANJANG KATA,DITUKAR DENGAN INDEX RANDOM
        randIndex = rand() % kata.size();

        //SWAP
        tempc = kataAcak[randIndex];
        kataAcak[randIndex] = kataAcak[i];
        kataAcak[i] = tempc;
    }
    cout << "Jumlah kata " << kata.size() << endl;
    cout << "Hasil kata acak : " << kataAcak << endl;
    return 0;
}
