// : Reutilização de Funções
// • Escreva uma função em C++ que calcule o fatorial de um número inteiro.
// • Crie um programa que utilize essa função para calcular e exibir o fatorial de 
// três números diferentes.
#include <iostream>

using namespace std;

int fatorial(int n){
    if(n < 0){
        cout   << "Erro: Nao e possível calcular o fatorial de um numero negativo.";
        return 0;
    }
    else{
        int fat = 1;
        for(int i = 1; i <= n; i++){
            fat *= i;
        }   
        return fat;
    } 
}

int main(){
    int n1, n2, n3, fat1, fat2, fat3;

    cout << "Digite o valor de n1: ";
    cin >> n1;
    fat1 = fatorial(n1);
    cout << "O fatorial de " << n1 << " eh: " << fat1 << endl;

    cout << "Digite o valor de n2: ";
    cin >> n2;
    fat2 = fatorial(n2);
    cout << "O fatorial de " << n2 << " eh: " << fat2 << endl;

    cout << "Digite o valor de n3: ";
    cin >> n3;
    fat3 = fatorial(n3);
    cout << "O fatorial de " << n3 << " eh: " << fat3 << endl;


    return 0;
}