
#include <iostream>

using namespace std;

int insere_meio(int *vetor, int qtde, int elemento);

int main(){
    int vetor[5], tamanho =6, quat =0; 

    for(int i=0; i< tamanho; i++){
        cout << "add " << i+1 << " numero ao vetor ";
        cin >> vetor[i];
    }  
    for(int i=0; i< tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
    quat = insere_meio(vetor, tamanho, 100);

    for(int i=0; i< quat; i++){
        cout << vetor[i] << " ";
    }
    
}
int insere_meio(int *vetor, int qtde, int elemento){
    int meio = qtde/2;
    for(int i=qtde-1; i>meio; i--){
        vetor[i] = vetor[i-1];
    }
    vetor[meio] = elemento;
    qtde++;
    return qtde;
}
