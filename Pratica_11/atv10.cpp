#include <iostream>
#include <vector>

using namespace std;

void buscaLetra(const string& texto, char letra, int* tamanho, vector<int>& posicao ) ;
int main() {
    string texto ;
    char letra ;

    cout << "Digite um texto: ";
    getline(cin, texto);

    cout << "Digite a letra para verificar o posicao : ";
    cin >> letra;

    vector<int> posicao;
    int tamanho = 0;

    buscaLetra(texto, letra, &tamanho, posicao);

    cout << "A posicao onde a letra '" << letra << "' foi encontrada:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << posicao[i] << " ";
    }
    cout << endl;

    return 0;
}

void buscaLetra(const string& texto, char letra, int* tamanho, vector<int>& posicao ) 
{
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] == letra) {
            posicao.push_back(i); 
        }
    }

    *tamanho = posicao.size(); 
}