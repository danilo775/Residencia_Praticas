// Faça uma função que receba (por referência) 4 variáveis float e ordena (crescente) os
// valores destas variáveis. Depois faça o programa principal para testar a sua função.

#include <iostream>

using namespace std;

void  crescente(float &a, float &b, float &c, float &d);

int main(){
    float a, b, c, d;
    cout << "digite o valor de a: ";
    cin >> a;
    cout << "digite o valor de b: ";
    cin >> b;
    cout << "digite o valor de c: ";
    cin >> c;
    cout << "digite o valor de d: ";
    cin >> d;

    cout << "ordem digitada: " << endl;
    cout << a << " " << b << " " << c << " " << d << endl;
    crescente(a, b, c, d);
     cout << "ordem crescente: " << endl;
    cout << a << " " << b << " " << c << " " << d << endl;

}

void  crescente(float &a, float &b, float &c, float &d){
    if(a > b){
        float aux = a;
        a = b;
        b = aux;
    }
    if(a > c){
        float aux = a;
        a = c;
        c = aux;
    }
    if(a > d){
        float aux = a;
        a = d;
        d = aux;
    }
    if(b > c){
        float aux = b;
        b = c;
        c = aux;
    }
    if(b > d){
        float aux = b;
        b = d;
        d = aux;
    }
    if(c > d){
        float aux = c;
        c = d;
        d = aux;
    }

}