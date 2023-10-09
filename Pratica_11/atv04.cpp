#include <iostream>
using namespace std;

void calcula(int &x, int &y);

int main(){
    
 int x = 0, y = 0;
    cout << "digite o valor de x: ";
    cin >> x;
    cout << "digite o valor de y: ";
    cin >> y;

calcula(x, y);

cout <<"O valor da soma x e Y = "<< x << endl;


cout  <<"O valor da subtarcao x e Y = "<< y << endl;

    return 0;
}


void calcula(int &x, int &y){
    int soma = x + y;
    int subtracao = x - y;
    x = soma;
    y = subtracao;

}