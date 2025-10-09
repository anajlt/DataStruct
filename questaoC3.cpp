#include <iostream>       
#include <limits>         
using namespace std;      

struct NO {               // Estrutura do nó da lista circular duplamente encadeada
    int info;             // Valor armazenado no nó
    NO* prox;             // Ponteiro para o próximo nó
    NO* ant;              // Ponteiro para o nó anterior
};

class ListaCircular {
private:
    NO* inicio;           // Ponteiro para o primeiro nó da lista
    int tamanho;          // Contador de elementos da lista
public:
    ListaCircular() {     // Construtor: inicia lista vazia
        inicio = NULL;    // Nenhum nó na lista
        tamanho = 0;      // Tamanho inicial = 0
    }
    ~ListaCircular() {    // Destrutor: limpa a lista ao destruir objeto
        limpar();         // Remove todos os nós para liberar memória
    }
    bool ListaVazia() {   // Verifica se a lista está vazia
        return inicio == NULL;
    }
    void Inserir(int valor) {  // Insere elemento no final da lista
        NO* novo = new NO;     // Cria novo nó
        novo->info = valor;    // Atribui valor ao nó
        if (ListaVazia()) {    // Lista vazia: novo nó aponta para si mesmo
            novo->prox = novo;
            novo->ant = novo;
            inicio = novo;     // Início aponta para o novo nó
        } else {               // Lista com elementos
            NO* fim = inicio->ant;  // Último nó
            fim->prox = novo;       // Último nó aponta para novo
            novo->ant = fim;        // Novo nó aponta para antigo fim
            novo->prox = inicio;    // Novo nó aponta para início
            inicio->ant = novo;     // Início aponta para novo
        }
        tamanho++;             // Incrementa contador
        cout << "Inserido: " << valor << endl;  // Mensagem de confirmação
    }
    void Remover(int valor) {     // Remove nó por valor
        if (ListaVazia()) {       // Lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }
        NO* temp = inicio;        // Começa do início
        bool encontrado = false;  // Flag para verificar se o elemento existe
        for (int i = 0; i < tamanho; i++) {   // Percorre a lista uma vez
            if (temp->info == valor) { encontrado = true; break; }
            temp = temp->prox;
        }
        if (!encontrado) {        // Elemento não encontrado
            cout << "Elemento " << valor << " NAO encontrado!" << endl;
            return;
        }
        if (tamanho == 1) {       // Único nó
            delete temp;          // Libera memória
            inicio = NULL;        // Lista fica vazia
        } else {                   // Mais de um nó
            temp->ant->prox = temp->prox;  // Nó anterior aponta para o próximo
            temp->prox->ant = temp->ant;  // Nó próximo aponta para o anterior
            if (temp == inicio) inicio = temp->prox; // Atualiza início se necessário
            delete temp;           // Libera memória
        }
        tamanho--;                 // Decrementa contador
        cout << "Removido: " << valor << endl;  // Mensagem de confirmação
    }
    void Imprimir() {            // Imprime todos os elementos da lista
        if (ListaVazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        NO* temp = inicio;       // Começa do início
        cout << "Lista: ";
        for (int i = 0; i < tamanho; i++) {   // Percorre todos os nós
            cout << temp->info << " ";        // Imprime valor
            temp = temp->prox;                // Avança para o próximo nó
        }
        cout << endl;
    }
    int Tamanho() {              // Retorna o tamanho da lista
        return tamanho;
    }
    void limpar() {              // Limpa todos os elementos da lista
        while (!ListaVazia()) {  // Enquanto a lista não estiver vazia
            Remover(inicio->info); // Remove o início repetidamente
        }
    }
};

int main() {
    ListaCircular lista;         // Cria objeto da lista
    int opcao, valor;            // Variáveis para menu e valores

    do {
        cout << "\n=== MENU LISTA CIRCULAR DUPLA ===\n";
        cout << "1 - Inserir no final\n";
        cout << "2 - Remover por valor\n";
        cout << "3 - Imprimir\n";
        cout << "4 - Mostrar tamanho\n";
        cout << "5 - Limpar lista\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        if (!(cin >> opcao)) {   // Valida entrada
            cin.clear();         // Limpa erro do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora entrada inválida
            cout << "Entrada invalida.\n";
            continue;
        }

        switch (opcao) {          // Menu de opções
            case 1:
                cout << "Valor a inserir: ";
                while (!(cin >> valor)) { // Valida valor
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido. Digite novamente: ";
                }
                lista.Inserir(valor);      // Insere valor
                break;
            case 2:
                cout << "Valor a remover: ";
                while (!(cin >> valor)) { // Valida valor
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido. Digite novamente: ";
                }
                lista.Remover(valor);       // Remove valor
                break;
            case 3:
                lista.Imprimir();           // Imprime lista
                break;
            case 4:
                cout << "Tamanho: " << lista.Tamanho() << endl; // Mostra tamanho
                break;
            case 5:
                lista.limpar();            // Limpa lista
                cout << "Lista limpa.\n";
                break;
            case 0:
                cout << "Saindo...\n";     // Encerra programa
                break;
            default:
                cout << "Opcao invalida.\n"; // Opção não reconhecida
        }
    } while (opcao != 0);        // Repete até escolher 0

    return 0;                     
}
