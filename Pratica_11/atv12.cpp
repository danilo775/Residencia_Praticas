#include <iostream>
#include <string>
#include <vector>

using namespace std;

string letrasEmComuns(string& a, string& b);

int main()
{
    string a, b, c;
    cout << "Digite a 1  palavra : ";
    cin >> a;

    cout << "Digite a 2 palavra: ";
    cin >> b;

    c = letrasEmComuns(a,b);

   if (!c.empty()) {
        cout << "As letras em comum nas palavras 1 e 2: " << c << endl;
    } else {
        cout << "nao a letras em comuns." << endl;
    }

    return 0;
}

string letrasEmComuns(string& a, string& b){
    string c;
    for (char caractere : a) {
    
            if (b.find(caractere) != string::npos && c.find(caractere) == string::npos) {
                c += caractere;
            }
        }
    return c;
}