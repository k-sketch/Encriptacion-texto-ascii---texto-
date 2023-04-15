#include <iostream>
#include <fstream>
using namespace std;

int inverso_m(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 0;
}

void encriptar(int n) {
    ifstream archivo_n("plain.txt");
    ofstream archivo_e("cifer.txt");
    char text;
    int ascii;
    while (archivo_n.get(text)) {
        ascii = text;
        ascii = (ascii * n) % 256;
        archivo_e << (char)ascii << " ";
    }
    archivo_n.close();
    archivo_e.close();
    cout << "Texto encriptado\n";
}

void desencriptar(int n) {
    int inverso = inverso_m(n, 256);
    if (inverso == 0) {
        cout << "El número ingresado no tiene inverso\n";
        return;
    }
    ifstream archivo_e("cifer.txt");
    ofstream archivo_d("plainz.txt");
    char ascii;
    while (archivo_e >> ascii) {
        ascii = ((int)ascii * inverso) % 256;
        archivo_d << (char)ascii;
    }
    archivo_e.close();
    archivo_d.close();
    cout << "Texto desencriptado\n";
}

int main() {
    int op;
    int num;
    cout << "1. Encriptar\n";
    cout << "2. Desencriptar\n";
    cout << "3. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> op;
    switch (op) {
        case 1:
            cout << "Ingresa un number: ";
            cin >> num;
            encriptar(num);
            break;
        case 2:
            cout << "Ingrese el number utilizado para encriptar: ";
            cin >> num;
            desencriptar(num);
            break;
        case 3:
            cout << "Para que ejecutas :)\n";
            break;
        }
    return 0;
}