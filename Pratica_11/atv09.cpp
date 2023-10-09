#include <iostream>
using namespace std;

float calc_serie(int N); 

int main() {
    int N;

    cout << "Digite o valor de N: ";
    cin >> N;

    if (N <= 0) {
        cout << "N deve ser maior que zero." << endl;
        return 1;
    }

    float S = calc_serie(N);

    cout << "O valor de S de N = " << N << " e: " << S << endl;

    return 0;
}

float calc_serie(int N) 
{
    float S = 0.0;
    float denominador = N;

    for (int i = 1; i <= N; i++) {
        S += i / denominador;
        denominador--;
    }

    return S;
}