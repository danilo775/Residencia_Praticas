#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Passageiro {
    string nome, cpf;
    int idade;
};

struct Data {
    int dia, mes, ano;
    string hora;
};

struct Poltrona {
    Passageiro passageiro;
    int numero_assento; // Adicionar o número do assento
    bool disponivel = true;
};

struct Viagem {
    Poltrona poltrona[40];
    bool tipo = false; // true para ida ou volta
    double valor = 80.00; // valor padrão da viagem
    string destino, saida;
    Data data;
};

bool validarData(int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2100 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        diasNoMes[2] = 29; // Ano bissexto
    }

    return dia <= diasNoMes[mes];
}

void criarOrigemDestino(vector<Viagem>& viagens) {
    Viagem novaViagem;
    cout << "Informe o destino da viagem: ";
    cin >> novaViagem.destino;
    cout << "Informe o local de saida da viagem: ";
    cin >> novaViagem.saida;
    
    if (novaViagem.destino == novaViagem.saida) {
        cout << "Erro: O destino não pode ser o mesmo que a origem." << endl<< endl;
        return;
    }
    
    do {
        cout << "Informe a data da viagem: " << endl;
        cout << "Dia (dd): ";
        cin >> novaViagem.data.dia;
        cout << "Mes (mm): ";
        cin >> novaViagem.data.mes;
        cout << "Ano (aaaa): ";
        cin >> novaViagem.data.ano;
    } while (!validarData(novaViagem.data.dia, novaViagem.data.mes, novaViagem.data.ano));
    
    cout << "Informe a hora da viagem: (hh:mm) ";
    cin >> novaViagem.data.hora;

    viagens.push_back(novaViagem);
    cout << "Viagem criada com sucesso!" << endl;
}

void comprar_Passagem(vector<Viagem>& viagens) {
    string destino;
    cout << "Informe o destino da viagem que deseja comprar passagem: ";
    cin >> destino;

    for (Viagem& viagem : viagens) {
        if (viagem.destino == destino) {
            for (int i = 0; i < 40; i++) {
                if (viagem.poltrona[i].disponivel) {
                    Passageiro passageiro;
                    cout << "Informe o nome do passageiro: ";
                    cin >> passageiro.nome;
                    cout << "Informe o CPF do passageiro: ";
                    cin >> passageiro.cpf;
                    cout << "Informe a idade do passageiro: ";
                    cin >> passageiro.idade;

                    viagem.poltrona[i].passageiro = passageiro;
                    viagem.poltrona[i].disponivel = false;
                    viagem.poltrona[i].numero_assento = i + 1; // Atribui o numero do assento
                    cout << "Passagem comprada com sucesso!" << endl;
                    return;
                }
            }
            cout << "Desculpe, todas as poltronas estão ocupadas para esta viagem." << endl;
            return;
        }
    }
    cout << "Viagem não encontrada." << endl;
}

void verPassagens(const vector<Viagem>& viagens) {
    for (const Viagem& viagem : viagens) {
        cout << "Destino: " << viagem.destino << endl;
        cout << "Local de Saida: " << viagem.saida << endl;
        cout << "Data da Viagem: " << viagem.data.dia << "/" << viagem.data.mes << "/" << viagem.data.ano << " " << viagem.data.hora << endl;
        cout << "Passagens vendidas:" << endl;

        for (int i = 0; i < 40; i++) {
            if (!viagem.poltrona[i].disponivel) {
                cout << "Poltrona " << viagem.poltrona[i].numero_assento << ": " << endl;
                cout << "Nome do passageiro: " << viagem.poltrona[i].passageiro.nome << endl;
                cout << "CPF do passageiro: " << viagem.poltrona[i].passageiro.cpf << endl;
                cout << "Idade do passageiro: " << viagem.poltrona[i].passageiro.idade << endl;
            }
        }

        cout << "-------------------------" << endl;
    }
}
string buscaNomePorPoltrona(const vector<Viagem>& viagens, int poltrona) {
    for (const Viagem& viagem : viagens) {
        for (int i = 0; i < 40; i++) {
            if (!viagem.poltrona[i].disponivel && viagem.poltrona[i].numero_assento == poltrona) {
                return viagem.poltrona[i].passageiro.nome;
            }
        }
    }
    return "Poltrona nao encontrada ou vazia.";
}
double arrecadamentoPorViagem(const vector<Viagem>& viagens) {
    double arrecadacao = 0.0;

    for (const Viagem& viagem : viagens) {
        for (int i = 0; i < 40; i++) {
            if (!viagem.poltrona[i].disponivel) {
                arrecadacao += viagem.valor;
            }
        }
    }

    return arrecadacao;
}

double arrecadamentoPorMes(const vector<Viagem>& viagens, int mes, int ano) {
    double arrecadacao = 0.0;

    for (const Viagem& viagem : viagens) {
        if (viagem.data.mes == mes && viagem.data.ano == ano) {
            for (int i = 0; i < 40; i++) {
                if (!viagem.poltrona[i].disponivel) {
                    arrecadacao += viagem.valor;
                }
            }
        }
    }

    return arrecadacao;
}

string horarioViagemMaisRentavel(const vector<Viagem>& viagens) {
    double maxArrecadacao = 0.0;
    string horarioMaisRentavel = "";

    for (const Viagem& viagem : viagens) {
        double arrecadacaoViagem = arrecadamentoPorViagem({viagem}); // Calcula a arrecadação da viagem atual
        if (arrecadacaoViagem > maxArrecadacao) {
            maxArrecadacao = arrecadacaoViagem;
            horarioMaisRentavel = viagem.data.hora;
        }
    }

    return horarioMaisRentavel;
}



int main() {
    vector<Viagem> viagens;
    string nomePassageiro;
    int opcao;
    int poltrona;
    
    do {
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Criar Origem e Destino de Viagem" << endl;
        cout << "2. Comprar Passagem" << endl;
        cout << "3. Ver Passagens Vendidas" << endl;
        cout << "4. Buscar Nome do Passageiro de uma Poltrona" << endl;
        cout << "5. Obter o total arrecadado para uma determinada viagem." << endl;
        cout << "6. Obter o total arrecadado em um determinado mes." << endl;
        cout << "7. Obter   o horario de viagem mais rentável." << endl;
        cout << "8. Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                criarOrigemDestino(viagens);
                break;
            case 2:
                comprar_Passagem(viagens);
                break;
            case 3:
                verPassagens(viagens);
                break;
            case 4:
                cout << "Digite o numero da Poltrona: " << endl;
                cin >> poltrona;
                nomePassageiro = buscaNomePorPoltrona(viagens, poltrona);
                cout << "===========================" << endl;
                cout << (nomePassageiro != "Poltrona nao encontrada ou vazia." ? nomePassageiro : "Poltrona vazia") << endl;
                cout << "===========================" << endl;
                break;
            case 5:
            {
                double arrecadacaoTotal = arrecadamentoPorViagem(viagens);
                cout << "Arrecadacao total por viagem: R$" << arrecadacaoTotal << endl;
                break;
            }
            case 6:
            {
                int mes, ano;
                cout << "Informe o mes e o ano (mm aaaa) para calcular a arrecadação por mes: ";
                cout<<"Mes (mm): ";
                cin >> mes;
                cout<<"Ano (aaaa): ";
                cin >> ano;
                double arrecadacaoPorMesResult = arrecadamentoPorMes(viagens, mes, ano);
                cout << "Arrecadacao total por mes: R$" << arrecadacaoPorMesResult << endl;
                break;
            }
            case 7:
            {
                string horarioMaisRentavel = horarioViagemMaisRentavel(viagens);
                cout << "Horario da viagem mais rentavel: " << horarioMaisRentavel << endl;
                break;
            }
            case 8:
                return 0;
            default:
                cout << "Opção invalida. Tente novamente." << endl;
                break;
        }
    }while (opcao!=8);

    return 0;
}
