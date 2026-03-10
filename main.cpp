#include <iostream>
using namespace std;

int main() {
    double sayi1, sayi2;
    char islem;

    cout << "Birinci sayiyi girin: ";
    cin >> sayi1;

    cout << "Islemi girin (+, -, *, /): ";
    cin >> islem;

    cout << "Ikinci sayiyi girin: ";
    cin >> sayi2;

    double sonuc;

    switch(islem) {
        case '+':
            sonuc = sayi1 + sayi2;
            break;
        case '-':
            sonuc = sayi1 - sayi2;
            break;
        case '*':
            sonuc = sayi1 * sayi2;
            break;
        case '/':
            if(sayi2 != 0)
                sonuc = sayi1 / sayi2;
            else {
                cout << "0'a bolme hatasi!" << endl;
                return 0;
            }
            break;
        default:
            cout << "Gecersiz islem!" << endl;
            return 0;
    }

    cout << "Sonuc: " << sonuc << endl;

    return 0;
}
