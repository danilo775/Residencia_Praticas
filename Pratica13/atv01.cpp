#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Passageiro {
    string name, cpf;
    int idade;
};

struct Data {
    int dia, mes, ano;
    string hora;
};

struct Poltrona {
    Passageiro passageiro;
    int numero_assento;
    bool disponivel = true;
};

struct Viagem {
    Poltrona potrona[40];
    bool tipo = false; // true ida ou volta
    double valor = 80.00; //
    string destino, saida;
    Data data;
};

void verHorarioViagem(const vector<Viagem>& viagens);
void criarOrigemDestino(vector<Viagem>& viagens);
void comprar_Passagem(vector<Viagem>& viagens);
void verPassagens(const vector<Viagem>& viagem);
double arrecadamentoPorViagem(const vector<Viagem>& viagens);
double arrecadamentoPorMes(const vector<Viagem>& viagens);
string buscaNomePorPlotrona(const vector<Viagem>& viagens, int plotrona);
string buscaNomePorasdasdaPsdasdaslotrona(const vector<Viagem>& viagens, int plotrona);




int main() {
    vector<Viagem> viagens;

    while (true) {
        int opcao;
        cout << "Menu:" << endl;
        cout << "1. Cadastrar destino" << endl;
        cout << "2. Vender Passagem" << endl;
        cout << "3. Obter Total Arrecadado para uma Viagem" << endl;
        cout << "4. Obter Total Arrecadado em um Mes" << endl;
        cout << "5. Obter Nome do Passageiro de uma Poltrona em uma Viagem" << endl;
        cout << "6. Obter Horário de Viagem Mais Rentavel" << endl;
        cout << "7. Obter Media de Idade dos Passageiros" << endl;
        cout << "8. Ver passagens" << endl;
        cout << "9. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            criarOrigemDestino(viagens);
        } else if (opcao == 2) {
            comprar_Passagem(viagens);
        } else if (opcao == 3) {
            double arrecadacao = arrecadamentoPorViagem(viagens);
            cout << "Total arrecadado para a viagem: " << arrecadacao << " reais" << endl;
        } else if (opcao == 4) {
            
        } else if (opcao == 5) {
            
        } else if (opcao == 6) {
           
        } else if (opcao == 7) {
            
        } else if (opcao == 8) {
            verPassagens(viagens);         
        } else if (opcao == 9) {
            break; // Sair do programa
        } else {
            cout << "Opção invalida. Tente novamente" << endl;
        }
    }

    return 0;
}

void criarOrigemDestino(vector<Viagem>& viagens)
 {
    Viagem viagem;
    cout << "Data, destino e hora" << endl << endl;
    cout << "Voce ira viajar para: ";
    cin >> viagem.destino;
    cout << "Hora de saída: ";
    cin >> viagem.data.hora;
    cout << "Saindo de: ";
    cin >> viagem.saida;
    cout << "Digite o ano da viagem: ";
    cin >> viagem.data.ano;
    cout << "Digite o mes da viagem: ";
    cin >> viagem.data.mes;
    cout << "Digite o dia da viagem: ";
    cin >> viagem.data.dia;
    viagem.tipo = true;
    viagens.push_back(viagem);
}





void verHorarioViagem(const vector<Viagem>& viagens) {
    string destino;
    int dia, poltronaDisponivel = 0;
    
    for (int i = 0; i < viagens.size(); i++) {
        if (viagens[i].tipo == true) {
            for (int j = 0; j < 40; j++) {
                if (viagens[i].potrona[j].disponivel == true) {
                    poltronaDisponivel++;
                }
            }
        }
    }
    
    for (int i = 0; i < viagens.size(); i++) {
        cout << "Data " << viagens[i].data.dia << "/" << viagens[i].data.mes << "/" << viagens[i].data.ano << " Horario " << viagens[i].data.hora << endl;
        cout << "Saida " << viagens[i].saida << endl;
        cout << "Destino " << viagens[i].destino << endl;
        cout << "Preço da passagem " << viagens[i].valor << endl;
        cout << "Poltronas disponiveis: " << poltronaDisponivel << endl;
    }
}

void comprar_Passagem(vector<Viagem>& viagens) {
    string destino;
    int dia;
    cout << "Voce ira viajar para qual cidade: ";
    cin >> destino;
    cout << "Para qual dia a viagem: ";
    cin >> dia;
    
    for (int i = 0; i < viagens.size(); i++) {
        if (viagens[i].destino == destino && viagens[i].data.dia == dia) {
            verHorarioViagem(viagens);
        }
    }
    
    Viagem viagem;
    cout << "Qual seu nome: ";
    cin >> viagem.potrona->passageiro.name;
    cout << "Qual seu cpf: ";
    cin >> viagem.potrona->passageiro.cpf;
    cout << "Qual sua idade: ";
    cin >> viagem.potrona->passageiro.idade;
    cout << "Qual o numero do seu assento: ";
    cin >> viagem.potrona->numero_assento;
    viagens.push_back(viagem);
}

double arrecadamentoPorViagem(const vector<Viagem>& viagens) {
    double soma = 0.0;
    string hora;
    int dia, mes, ano;
    cout << "Digite o ano para busca: ";
    cin >> ano;
    cout << "Digite o mes para busca: ";
    cin >> mes;
    cout << "Digite a Hora para busca: ";
    cin >> hora;
    for (int i = 0; i < viagens.size(); i++) {      
        if (ano == viagens[i].data.ano && mes == viagens[i].data.mes && hora == viagens[i].data.hora) {
            for (int j = 0; j < 40; j++) {
                
                    soma += viagens[i].valor;
                
            }
        }
    }
    return soma;
}

void verPassagens(const vector<Viagem>& viagem){
    for(int i = 0; i <viagem.size(); i++) {
        cout << "Nome: " << viagem[i].potrona->passageiro.name << " idade " << viagem[i].potrona->passageiro.idade << endl;
        cout << "CPF: " << viagem[i].potrona->passageiro.cpf << endl;
        cout << "Saida: " << viagem[i].saida << endl;
        cout << "Destino: " << viagem[i].destino << endl;
        cout << "Poltrona: " << viagem[i].potrona->numero_assento << endl;
        cout << "Valor: " << viagem[i].valor << endl;
        cout << "Data " << viagem[i].data.dia << "/" << viagem[i].data.mes << "/" << viagem[i].data.ano << " Horario " << viagem[i].data.hora << endl;
        cout << "Hora: " << viagem[i].data.hora << endl;
        cout << "====================================================================" << endl; 
           
    }
}
