#include <iostream>
using namespace std;

bool VerificaPrimo(int num);
int conta_primos (int *vet, int qtde);

int main() {
    int tam = 100;
    int vet[tam];

    cout << "Digite a quantidadede para contar os primos: ";
    cin >> tam;

    for (int i = 0; i <= tam; i++) {
       vet[i] = i;
    }

    cout << endl;
    cout << "Contagem de primos: " << conta_primos(vet, tam) << endl;
    return 0;
}
bool VerificaPrimo(int num){
   int resultado = 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            resultado++;
            break;
        }
 }
 
 if (resultado == 0)
   return true;
 else
   return false;
}

int conta_primos (int *vet, int qtde){
    int cont = 0;
    for (int i = 0; i < qtde; i++) {
        if (VerificaPrimo(vet[i])) {
            cont++;
        }
    }
    return cont;
}