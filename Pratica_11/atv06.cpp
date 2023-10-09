#include <iostream>
using namespace std;

int* intercala(int *vet1, int tam1, int *vet2, int tam2);


int main(){
    int tam1=3, tam2=5;
    int vet1[tam1], vet2[tam2];
    for(int i=0; i<tam1; i++){
        cout << "add " << i+1 << " numero ao vet1 ";
        cin >> vet1[i];
    }
    for(int i=0; i<tam2; i++){
        cout << "add " << i+1 << " numero ao vet2 ";
        cin >> vet2[i];
    }
  
   
    int *vet3 = intercala(vet1, tam1, vet2, tam2);

    cout << "Vetor intercalado: ";
    for (int i = 0; i < tam1 + tam2; i++) {
        cout << vet3[i] << " ";
    }

    cout << endl;

    return 0;
}

int* intercala(int *vet1, int tam1, int *vet2, int tam2){
    int *vet3 = new int[tam1 + tam2];
    int i = 0, j = 0, k = 0;

    while (i < tam1 || j < tam2) {
        if (i < tam1) {
            vet3[k++] = vet1[i++];
        }
        if (j < tam2) {
            vet3[k++] = vet2[j++];
        }
    }
    
    return vet3;
}