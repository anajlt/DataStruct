#include <iostream> 
using namespace std;

// Estrutura do nó da lista circular duplamente encadeada
struct NO {
    int info;    // valor armazenado no nó
    NO* prox;    // ponteiro para o próximo nó
    NO* ant;     // ponteiro para o nó anterior
};

// Classe da lista circular duplamente encadeada
class ListaCircular {
private:
    NO* inicio;   // ponteiro para o primeiro nó da lista
    int tamanho;  // quantidade de elementos na lista

public:
    // Construtor da lista
    ListaCircular() {
        inicio = NULL; // inicializa ponteiro de início como NULL (lista vazia)
        tamanho = 0;   // inicializa tamanho como 0
    }

    // Verifica se a lista está vazia
    bool ListaVazia() { 
        return inicio == NULL; // retorna true se a lista estiver vazia
    }

    // Inserir elemento no final da lista
    void Inserir(int valor) {
        NO* novo = new NO;  // cria um novo nó dinamicamente
        novo->info = valor; // atribui o valor ao novo nó

        if (ListaVazia()) { // se a lista estiver vazia
            novo->prox = novo;  // próximo do novo nó aponta para ele mesmo
            novo->ant = novo;   // anterior do novo nó aponta para ele mesmo
            inicio = novo;      // o início da lista aponta para o novo nó
        } else { // lista não vazia
            NO* fim = inicio->ant; // último nó da lista
            fim->prox = novo;      // último nó aponta para o novo
            novo->ant = fim;       // novo nó aponta para o último nó
            novo->prox = inicio;   // novo nó aponta para o início
            inicio->ant = novo;    // início aponta para o novo nó
        }

        tamanho++; // atualiza o tamanho da lista
    }

    // Remover elemento da lista pelo valor
    void Remover(int valor) {
        if (ListaVazia()) { // lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }

        NO* temp = inicio;    // começa a percorrer do início
        bool encontrado = false; // flag para saber se encontrou o valor

        // percorre todos os nós (uma volta completa)
        for (int i = 0; i < tamanho; i++) {
            if (temp->info == valor) { // valor encontrado
                encontrado = true;
                break;
            }
            temp = temp->prox; // vai para próximo nó
        }

        if (!encontrado) { // valor não encontrado
            cout << "Elemento " << valor << " NAO encontrado!" << endl;
            return;
        }

        // caso a lista tenha apenas um nó
        if (temp->prox == temp && temp->ant == temp) {
            delete temp;      // libera memória
            inicio = NULL;    // lista fica vazia
        } else { // lista com mais de um nó
            temp->ant->prox = temp->prox; // nó anterior aponta para próximo
            temp->prox->ant = temp->ant; // nó próximo aponta para anterior

            if (temp == inicio) // se for o início, atualiza início
                inicio = temp->prox;

            delete temp; // libera memória do nó removido
        }

        tamanho--; // atualiza tamanho da lista
    }

    // Imprimir todos os elementos da lista
    void Imprimir() {
        if (ListaVazia()) { // lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }

        NO* temp = inicio; // começa do início
        cout << "Lista: ";
        for (int i = 0; i < tamanho; i++) { // percorre uma volta completa
            cout << temp->info << " "; // imprime valor do nó
            temp = temp->prox;         // avança para o próximo nó
        }
        cout << endl;
    }
};

// Função principal para testar a lista
int main() {
    ListaCircular lista; // cria objeto da lista circular

    // inserções de teste
    lista.Inserir(10); // inserir 10
    lista.Inserir(20); // inserir 20
    lista.Inserir(30); // inserir 30
    lista.Imprimir();  // esperado: 10 20 30

    // remover elemento do meio
    lista.Remover(20); 
    lista.Imprimir(); // esperado: 10 30

    // remover elemento não existente
    lista.Remover(50); // mensagem: não encontrado

    // remover início
    lista.Remover(10); 
    lista.Imprimir(); // esperado: 30

    // remover último elemento
    lista.Remover(30); 
    lista.Imprimir(); // esperado: lista vazia!

    return 0;
}