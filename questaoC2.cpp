#include <iostream> 
using namespace std;

// Estrutura do nó da lista duplamente encadeada
struct NO {
    int info;    // valor armazenado no nó
    NO* prox;    // ponteiro para o próximo nó da lista
    NO* ant;     // ponteiro para o nó anterior da lista
};

// Classe da lista duplamente encadeada
class ListaDupla {
private:
    NO* inicio;   // ponteiro para o início da lista
    NO* fim;      // ponteiro para o fim da lista
    int tamanho;  // quantidade de elementos na lista

    // Função auxiliar privada para busca recursiva
    NO* BuscarRecAux(NO* no, int valor) {
        if (no == NULL) return NULL;   // caso base: fim da lista, retorna NULL
        if (no->info == valor) return no; // encontrou o valor, retorna o nó
        return BuscarRecAux(no->prox, valor); // chamada recursiva para o próximo nó
    }

public:
    // Construtor da lista
    ListaDupla() {
        inicio = fim = NULL; // inicializa ponteiros como NULL
        tamanho = 0;         // inicializa tamanho da lista como zero
    }

    // Verifica se a lista está vazia
    bool ListaVaziaLD() { 
        return inicio == NULL; 
    }

    // Inserir elemento no início da lista
    // Evita duplicatas
    void InserirInicioLD(int k) {
        // percorre a lista para verificar duplicata
        NO* temp = inicio;
        while (temp != NULL) {
            if (temp->info == k) {  // se já existir
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return; // sai sem inserir
            }
            temp = temp->prox; // avança para o próximo nó
        }

        // Cria um novo nó
        NO* novo = new NO;
        novo->info = k;   // atribui valor
        novo->ant = NULL; // como será o primeiro, não tem anterior

        // Inserção
        if (ListaVaziaLD()) { // lista vazia
            novo->prox = NULL;
            inicio = fim = novo; // primeiro e único nó
        } else { // lista com elementos
            novo->prox = inicio; // próximo do novo aponta para antigo início
            inicio->ant = novo;  // anterior do antigo início aponta para o novo
            inicio = novo;       // atualiza início da lista
        }

        tamanho++; // atualiza tamanho
    }

    // Inserir elemento em qualquer posição
    void InserirPosicao(int k, int pos) {
        // verifica posição válida
        if (pos < 0 || pos > tamanho) {
            cout << "Posição inválida!" << endl;
            return;
        }

        // Se posição 0, chama inserção no início
        if (pos == 0) {
            InserirInicioLD(k);
            return;
        }

        // Verificar duplicata
        NO* temp = inicio;
        while (temp != NULL) {
            if (temp->info == k) {
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return;
            }
            temp = temp->prox;
        }

        // Criar novo nó
        NO* novo = new NO;
        novo->info = k;

        // Percorrer até o nó anterior à posição desejada
        temp = inicio;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->prox;

        // Ajustar ponteiros para inserir no meio ou final
        novo->prox = temp->prox;
        novo->ant = temp;
        if (temp->prox != NULL)
            temp->prox->ant = novo; // próximo nó aponta para o novo
        else
            fim = novo; // atualiza fim se inserir no final
        temp->prox = novo;

        tamanho++; // atualiza tamanho
    }

    // Imprimir todos os elementos da lista
    void Imprimir() {
        NO* temp = inicio;  // começa do início
        cout << "Lista: ";
        while (temp != NULL) {
            cout << temp->info << " "; // imprime valor do nó
            temp = temp->prox;         // vai para próximo nó
        }
        cout << endl;
    }

    // Busca recursiva de elemento
    NO* BuscarRec(int valor) {
        return BuscarRecAux(inicio, valor); // chama função auxiliar
    }

    // Excluir elemento em qualquer posição
    void Excluir(int pos) {
        if (ListaVaziaLD()) { // lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }

        if (pos < 0 || pos >= tamanho) { // posição inválida
            cout << "Posição inválida!" << endl;
            return;
        }

        NO* temp = inicio;

        // Excluir primeiro nó
        if (pos == 0) {
            inicio = temp->prox;   // atualiza início
            if (inicio != NULL)
                inicio->ant = NULL; // ajusta anterior
            else
                fim = NULL;         // lista ficou vazia
            delete temp;             // libera memória
            tamanho--;
            return;
        }

        // Percorrer até a posição desejada
        for (int i = 0; i < pos; i++)
            temp = temp->prox;

        // Ajustar ponteiros dos nós vizinhos
        if (temp->ant != NULL)
            temp->ant->prox = temp->prox;
        if (temp->prox != NULL)
            temp->prox->ant = temp->ant;
        else
            fim = temp->ant; // atualiza fim se for o último

        delete temp; // libera memória do nó
        tamanho--;
    }

    // Retorna o tamanho atual da lista
    int Tamanho() { return tamanho; }
};

// Função principal para testar a lista
int main() {
    ListaDupla lista; // cria objeto da lista

    // Inserções no início
    lista.InserirInicioLD(10); 
    lista.InserirInicioLD(20); 

    // Inserção no meio
    lista.InserirPosicao(15, 1); 
    lista.Imprimir(); // esperado: 20 15 10

    // Tentativa de duplicata
    lista.InserirInicioLD(15); // mensagem: já existe

    // Busca recursiva
    NO* encontrado = lista.BuscarRec(15);
    if (encontrado != NULL)
        cout << "Elemento 15 encontrado!" << endl;
    else
        cout << "Elemento 15 não encontrado!" << endl;

    // Exclusão de elemento da posição 1
    lista.Excluir(1); 
    lista.Imprimir(); // esperado: 20 10

    return 0;
}