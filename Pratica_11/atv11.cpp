#include <iostream>
using namespace std;

string codificar(string texto);
string decodificar(string texto);
int main() {
    string texto;
    cout << "Digite uma Texto para codificar: ";
    getline(cin, texto);

    string codigo = codificar(texto);
    cout << "Texto codificado: " << codigo << endl;

    string decodificado = decodificar(codigo);
    cout << "Texto decodificado: " << decodificado << endl;

    return 0;
}


string codificar(string texto) {
    string codifica = texto;

    for (size_t i = 0; i < codifica.length(); i++) {
        char& c = codifica[i];
        if (isalpha(c)) {
            if (c == 'z') {
                c = 'a';
            } else if (c == 'Z') {
                c = 'A';
            } else {
                c++;
            }
        }
    }

    return codifica;
}

string decodificar(string texto) {
    string descodifica = texto;

    for (size_t i = 0; i < descodifica.length(); i++) {
        char& c = descodifica[i];
        if (isalpha(c)) {
            if (c == 'a') {
                c = 'z';
            } else if (c == 'A') {
                c = 'Z';
            } else {
                c--;
            }
        }
    }

    return descodifica;
}