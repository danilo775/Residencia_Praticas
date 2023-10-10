# include <iostream>
# include <vector>

using namespace std;

struct Empregado{
    string name, sobreName, rg;
    int anoNascimento, anoAdmicao;
    double salario;
};

void Reajusta_dez_porcento(vector<Empregado>& empresa){
    for(int i = 0; i < empresa.size(); i++){
    empresa[i].salario = empresa[i].salario + (empresa[i].salario * 0.01);

    }
}
void addEmpregado(vector<Empregado>& empresa){
    Empregado empregados;
    cout << "Digite o nome do empregado: ";
    cin >> empregados.name;
    cout << "Digite o sobreNome do empregado: ";
    cin >> empregados.sobreName;
    cout << "Digite o rg do empregado: ";
    cin >> empregados.rg;
    cout << "Digite o ano de nascimento do empregado: ";
    cin >> empregados.anoNascimento;
    cout << "Digite o ano de admissao do empregado: ";
    cin >> empregados.anoAdmicao;
    cout << "Digite o salario do empregado: " << endl;
    cin >> empregados.salario;
    empresa.push_back(empregados);
}
void listaEmpregados(vector<Empregado>& empresa) {
    for(int i = 0; i < empresa.size(); i++){
        if(empresa[i].rg != "") {
            cout << "Nome: " << empresa[i].name << endl;
            cout << "Sobrenome: " << empresa[i].sobreName << endl;
            cout << "RG: " << empresa[i].rg << endl;
            cout << "Ano de nascimento: " << empresa[i].anoNascimento << endl;
            cout << "Ano de admissao: " << empresa[i].anoAdmicao << endl;
            cout << "Salario: " << empresa[i].salario << endl;
        }
    }
}

int main(void) {   
   vector<Empregado> empresa(50);
   int opcao;
    do{
        cout << "Digite 1 para adicionar um empregado" << endl;
        cout << "Digite 2 para listar os empregados" << endl;
        cout << "Digite 3 para reajustar os empregados" << endl;
        cout << "Digite 4 para sair" << endl;
        int opcao;
        cin >> opcao;
        switch(opcao){
            case 1:
                addEmpregado(empresa);
                break;
            case 2:
                listaEmpregados(empresa);
                break;
            case 3:
                Reajusta_dez_porcento(empresa);
                break;
            case 4:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida " << endl;
        }
    } while (opcao != 4);

    return 0;
}