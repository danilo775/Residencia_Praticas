#include <iostream>
#include <cmath>

using namespace std;

// Definindo a struct Ponto
struct Ponto {
    double x;
    double y;
};

// Função para calcular a distância entre dois pontos
double calcularDistanciaEntrePontos(const Ponto& ponto1, const Ponto& ponto2) {
    double distanciaX = ponto1.x - ponto2.x;
    double distanciaY = ponto1.y - ponto2.y;
    return sqrt(distanciaX * distanciaX + distanciaY * distanciaY);
}

int main() {
    Ponto ponto1, ponto2;

    cout << "Digite as coordenadas do ponto 1 (x y): " << endl;
    cout<<"Ponto x: ";
    cin >> ponto1.x;
    cout<<"Ponto y: ";
    cin>> ponto1.y;

    cout << "Digite as coordenadas do ponto 2 (x y): " << endl;
    cout<<"Ponto x: ";
    cin >> ponto2.x;
    cout<<"Ponto y: "; 
    cin >> ponto2.y;

    double distancia = calcularDistanciaEntrePontos(ponto1, ponto2);

    cout << "A distancia entre os pontos 1 e 2 e: " << distancia << endl;

    return 0;
}
