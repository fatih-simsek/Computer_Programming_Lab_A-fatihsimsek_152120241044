#include <iostream>
using namespace std;

int main() {
    int secim;
    int biletSayisi;
    double fiyat = 0;
    double toplam;

    cout << "===== SINEMA MENU =====" << endl;
    cout << "1. Aksiyon Filmi (100 TL)" << endl;
    cout << "2. Komedi Filmi (80 TL)" << endl;
    cout << "3. Dram Filmi (90 TL)" << endl;
    cout << "4. Cikis" << endl;

    cout << "Seciminizi yapiniz: ";
    cin >> secim;

    switch(secim) {
        case 1:
            fiyat = 100;
            cout << "Aksiyon filmi sectiniz." << endl;
            break;
        case 2:
            fiyat = 80;
            cout << "Komedi filmi sectiniz." << endl;
            break;
        case 3:
            fiyat = 90;
            cout << "Dram filmi sectiniz." << endl;
            break;
        case 4:
            cout << "Cikis yapiliyor..." << endl;
            return 0;
        default:
            cout << "Gecersiz secim!" << endl;
            return 0;
    }

    cout << "Kac bilet almak istiyorsunuz? ";
    cin >> biletSayisi;

    toplam = fiyat * biletSayisi;

    cout << "Toplam tutar: " << toplam << " TL" << endl;

    return 0;
}