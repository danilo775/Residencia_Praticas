
#include <iostream>
using namespace std;

void multiplica_por_n(int *vet, int qtde, int n);

int main(){
    int vet[5], tam =3, multiplicador = 0;

    cout << "Digite o tamanho do vetor: ";
    cin >> tam;

    for(int i=0; i< tam; i++){
        cout << "Digite o valor " << i+1 << " : ";
        cin >> vet[i];
    }

    cout << "Valores no vetor: " << endl; 
    for(int i=0; i< tam; i++){
        cout << vet[i] << " ";
    }

    cout << "\nDigite o valor que quer multiplicar: ";
    cin >> multiplicador;

    multiplica_por_n(vet, tam, multiplicador);

     cout << "Valores no vetor mutiplicado por " << multiplicador << ":" << endl; 
    for(int i=0; i< tam; i++){
        cout << vet[i] << " ";
    }


    return 0;
}

void multiplica_por_n(int *vet, int qtde, int n){
    for(int i=0; i< qtde; i++){
        vet[i] = vet[i] * n;
    }
}