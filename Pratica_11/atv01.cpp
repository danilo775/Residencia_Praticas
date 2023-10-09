#include <iostream>
#include <vector>

using namespace std;

void maxmin(int vetor[], int n, int &maximo, int &minimo){
    maximo = vetor[0];
    minimo = vetor[0];

    for(int i=0; i< n; i++){
        if(vetor[i] < minimo){
            minimo = vetor[i];
        }
        if (vetor[i] > maximo){
            maximo = vetor[i];
        }
     
        
    } 


}


int main(){
    int vetor[5], n =5, maximo, minimo; 

    for(int i=0; i< n; i++){
        cout << "add " << i+1 << " numero ao vetor ";
        cin >> vetor[i];
    }

    maxmin(vetor, n, maximo, minimo);
    cout << "O  maximo e : " << maximo << endl;
    cout << "O  minimo e : " << minimo << endl;

    return 0;
}