#include <iostream> 
using namespace std;

// Estrutura do n� da lista circular duplamente encadeada
struct NO {
    int info;    // valor armazenado no n�
    NO* prox;    // ponteiro para o pr�ximo n�
    NO* ant;     // ponteiro para o n� anterior
};

// Classe da lista circular duplamente encadeada
class ListaCircular {
private:
    NO* inicio;   // ponteiro para o primeiro n� da lista
    int tamanho;  // quantidade de elementos na lista

public:
    // Construtor da lista
    ListaCircular() {
        inicio = NULL; // inicializa ponteiro de in�cio como NULL (lista vazia)
        tamanho = 0;   // inicializa tamanho como 0
    }

    // Verifica se a lista est� vazia
    bool ListaVazia() { 
        return inicio == NULL; // retorna true se a lista estiver vazia
    }

    // Inserir elemento no final da lista
    void Inserir(int valor) {
        NO* novo = new NO;  // cria um novo n� dinamicamente
        novo->info = valor; // atribui o valor ao novo n�

        if (ListaVazia()) { // se a lista estiver vazia
            novo->prox = novo;  // pr�ximo do novo n� aponta para ele mesmo
            novo->ant = novo;   // anterior do novo n� aponta para ele mesmo
            inicio = novo;      // o in�cio da lista aponta para o novo n�
        } else { // lista n�o vazia
            NO* fim = inicio->ant; // �ltimo n� da lista
            fim->prox = novo;      // �ltimo n� aponta para o novo
            novo->ant = fim;       // novo n� aponta para o �ltimo n�
            novo->prox = inicio;   // novo n� aponta para o in�cio
            inicio->ant = novo;    // in�cio aponta para o novo n�
        }

        tamanho++; // atualiza o tamanho da lista
    }

    // Remover elemento da lista pelo valor
    void Remover(int valor) {
        if (ListaVazia()) { // lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }

        NO* temp = inicio;    // come�a a percorrer do in�cio
        bool encontrado = false; // flag para saber se encontrou o valor

        // percorre todos os n�s (uma volta completa)
        for (int i = 0; i < tamanho; i++) {
            if (temp->info == valor) { // valor encontrado
                encontrado = true;
                break;
            }
            temp = temp->prox; // vai para pr�ximo n�
        }

        if (!encontrado) { // valor n�o encontrado
            cout << "Elemento " << valor << " NAO encontrado!" << endl;
            return;
        }

        // caso a lista tenha apenas um n�
        if (temp->prox == temp && temp->ant == temp) {
            delete temp;      // libera mem�ria
            inicio = NULL;    // lista fica vazia
        } else { // lista com mais de um n�
            temp->ant->prox = temp->prox; // n� anterior aponta para pr�ximo
            temp->prox->ant = temp->ant; // n� pr�ximo aponta para anterior

            if (temp == inicio) // se for o in�cio, atualiza in�cio
                inicio = temp->prox;

            delete temp; // libera mem�ria do n� removido
        }

        tamanho--; // atualiza tamanho da lista
    }

    // Imprimir todos os elementos da lista
    void Imprimir() {
        if (ListaVazia()) { // lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }

        NO* temp = inicio; // come�a do in�cio
        cout << "Lista: ";
        for (int i = 0; i < tamanho; i++) { // percorre uma volta completa
            cout << temp->info << " "; // imprime valor do n�
            temp = temp->prox;         // avan�a para o pr�ximo n�
        }
        cout << endl;
    }
};

// Fun��o principal para testar a lista
int main() {
    ListaCircular lista; // cria objeto da lista circular

    // inser��es de teste
    lista.Inserir(10); // inserir 10
    lista.Inserir(20); // inserir 20
    lista.Inserir(30); // inserir 30
    lista.Imprimir();  // esperado: 10 20 30

    // remover elemento do meio
    lista.Remover(20); 
    lista.Imprimir(); // esperado: 10 30

    // remover elemento n�o existente
    lista.Remover(50); // mensagem: n�o encontrado

    // remover in�cio
    lista.Remover(10); 
    lista.Imprimir(); // esperado: 30

    // remover �ltimo elemento
    lista.Remover(30); 
    lista.Imprimir(); // esperado: lista vazia!

    return 0;
}