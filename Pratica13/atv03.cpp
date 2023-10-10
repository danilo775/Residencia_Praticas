#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct Produto {
    string codigo;
    string nome;
    double preco;
};

void listaProdutos(const vector<Produto>& produtos);
void addProduto(vector<Produto>& produtos);
void consultarPreco(const vector<Produto>& produtos, const string& codigo);
bool produtoExiste(const vector<Produto>& produtos, const string& codigo, const string& nome);
void excluirProduto(vector<Produto>& produtos, const string& codigo);

int main() {
    vector<Produto> produtos;
    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Listar todos os produtos" << endl;
        cout << "3. Excluir um produto" << endl;
        cout << "4. Consultar o preco de um produto" << endl;
        cout << "5. Sair" << endl;
        cout << "Digite sua opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                addProduto(produtos);
                break;
            case 2:
                listaProdutos(produtos);
                break;
            case 3:
            {
                cout << "Digite o codigo do produto para excluir: ";
                string codigo;
                cin >> codigo;
                excluirProduto(produtos, codigo);
            }
                break;
            case 4:
            {
                cout << "Digite o codigo do produto para consultar o preço: ";
                string codigoConsulta;
                cin >> codigoConsulta;
                consultarPreco(produtos, codigoConsulta);
            }    
                break;
            case 5:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção invalida." << endl;
                break;
        }

    } while (opcao != 5);

    return 0;
}

void excluirProduto(vector<Produto>& produtos, const string& codigo) {
    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->codigo == codigo) {
            produtos.erase(it);
            cout << "Produto com codigo " << codigo << " excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Produto com codigo " << codigo << " nao encontrado." << endl;
}

bool produtoExiste(const vector<Produto>& produtos, const string& codigo, const string& nome) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo || produto.nome == nome) {
            return true;
        }
    }
    return false;
}
void consultarPreco(const vector<Produto>& produtos, const string& codigo) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo) {
            cout << "Codigo: " << produto.codigo << endl;
            cout << "Nome: " << produto.nome << endl;
            cout << "Preco: " << fixed << setprecision(2) << produto.preco << endl;
            return;
        }
    }
    cout << "Produto com codigo " << codigo << " nao encontrado." << endl;
}

void addProduto(vector<Produto>& produtos) {
    char opcao;
    do {
        if (produtos.size() >= 300) {
            cout << "Erro: O sistema nao permite o cadastro de mais de 300 produtos." << endl;
            return;
        }

        Produto novoProduto;
        cout << "Digite o codigo do produto (13 caracteres numericos): ";
        cin >> novoProduto.codigo;

        if (novoProduto.codigo.size() != 13 || !all_of(novoProduto.codigo.begin(), novoProduto.codigo.end(), ::isdigit)) {
            cout << "Codigo invalido. Deve conter 13 caracteres numericos." << endl;
            return;
        }

        cout << "Digite o nome do produto (ate 20 caracteres): ";
        cin.ignore();
        getline(cin, novoProduto.nome);

        if (novoProduto.nome.size() > 20) {
            cout << "Nome invalido. Deve conter ate 20 caracteres." << endl;
            return;
        }

        if (produtoExiste(produtos, novoProduto.codigo, novoProduto.nome)) {
            cout << "Produto com o mesmo codigo ou nome já existe. Nao e possivel adicionar." << endl;
            return;
        }

        cout << "Digite o preço do produto: ";
        cin >> novoProduto.preco;

        produtos.push_back(novoProduto);
        cout << "Produto adicionado com sucesso." << endl;

        cout << "Deseja adicionar outro produto? (s/n): ";
        cin >> opcao;

    } while (opcao != 'n' && opcao != 'N');
}


void listaProdutos(const vector<Produto>& produtos) {
    for (const Produto& produto : produtos) {
        cout << "Codigo: " << produto.codigo << endl;
        cout << "Nome: " << produto.nome << endl;
        cout << "Preço: " << fixed << setprecision(2) << produto.preco << endl;
        cout << "------------------------" << endl;
    }
}
