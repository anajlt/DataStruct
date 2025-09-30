#include <iostream> 
using namespace std;

// Estrutura de um nó da lista duplamente encadeada
struct No {
    int dado;     // valor armazenado no nó
    No* prox;     // ponteiro para o próximo nó
    No* ant;      // ponteiro para o nó anterior
};

// Função para inserir um elemento em qualquer posição
void inserir(No*& cabeca, int valor, int pos) {
    No* novo = new No;  // cria um novo nó
    novo->dado = valor; // atribui o valor ao novo nó
    novo->prox = NULL; // inicializa o ponteiro próximo como NULL
    novo->ant = NULL;  // inicializa o ponteiro anterior como NULL

    if (pos == 0) { // inserção no início
        novo->prox = cabeca; // o próximo do novo nó aponta para o antigo primeiro nó
        if (cabeca != NULL)
            cabeca->ant = novo; // o anterior do antigo primeiro nó aponta para o novo nó
        cabeca = novo; // atualiza a cabeça da lista
        return; // termina a função
    }

    No* temp = cabeca; // nó temporário para percorrer a lista
    int i = 0;
    // percorre até a posição anterior à desejada
    while (temp != NULL && i < pos - 1) {
        temp = temp->prox; // avança para o próximo nó
        i++; // incrementa o contador
    }

    if (temp == NULL) { // posição inválida
        cout << "Posição inválida!" << endl;
        delete novo; // libera memória do nó não inserido
        return;
    }

    // Ajusta os ponteiros para inserir no meio ou no final
    novo->prox = temp->prox; // próximo do novo nó aponta para o nó que vem depois
    novo->ant = temp;        // anterior do novo nó aponta para o nó atual
    if (temp->prox != NULL)
        temp->prox->ant = novo; // o anterior do próximo nó aponta para o novo nó
    temp->prox = novo;          // próximo do nó atual aponta para o novo nó
}

// Função para imprimir a lista
void imprimir(No* cabeca) {
    No* temp = cabeca; // nó temporário para percorrer a lista
    cout << "Lista: ";
    while (temp != NULL) {
        cout << temp->dado << " "; // imprime o valor do nó atual
        temp = temp->prox;         // avança para o próximo nó
    }
    cout << endl; // quebra de linha após imprimir todos os elementos
}

// Função recursiva para buscar um elemento
No* buscarRec(No* cabeca, int valor) {
    if (cabeca == NULL) // lista vazia ou fim da lista
        return NULL;
    if (cabeca->dado == valor) // encontrou o valor
        return cabeca;
    return buscarRec(cabeca->prox, valor); // chamada recursiva para o próximo nó
}

// Função para excluir um elemento em qualquer posição
void excluir(No*& cabeca, int pos) {
    if (cabeca == NULL) { // lista vazia
        cout << "Lista vazia!" << endl;
        return;
    }

    No* temp = cabeca; // nó temporário para percorrer a lista

    if (pos == 0) { // excluir o primeiro nó
        cabeca = temp->prox;      // atualiza a cabeça da lista
        if (cabeca != NULL)
            cabeca->ant = NULL; // atualiza o anterior do novo primeiro nó
        delete temp;               // libera memória do nó removido
        return;
    }

    int i = 0;
    while (temp != NULL && i < pos) {
        temp = temp->prox; // avança para o nó a ser removido
        i++;
    }

    if (temp == NULL) { // posição inválida
        cout << "Posição inválida!" << endl;
        return;
    }

    // Ajusta os ponteiros dos nós vizinhos
    if (temp->ant != NULL)
        temp->ant->prox = temp->prox; // nó anterior aponta para o próximo do nó a ser removido
    if (temp->prox != NULL)
        temp->prox->ant = temp->ant;  // nó próximo aponta para o anterior do nó a ser removido

    delete temp; // libera memória do nó removido
}

int main() {
    No* lista = NULL; // cabeça da lista inicializada como vazia

    // Testando inserção
    inserir(lista, 10, 0); // inserir no início
    inserir(lista, 20, 1); // inserir no final
    inserir(lista, 15, 1); // inserir no meio
    imprimir(lista);       // esperado: 10 15 20

    // Testando busca recursiva
    int valor = 15; // valor a ser buscado
    No* encontrado = buscarRec(lista, valor); // chama a função recursiva de busca
    if (encontrado != NULL)
        cout << "Elemento " << valor << " encontrado!" << endl;
    else
        cout << "Elemento " << valor << " não encontrado!" << endl;

    // Testando exclusão
    excluir(lista, 1); // excluir o elemento da posição 1 (15)
    imprimir(lista);   // esperado: 10 20

    return 0; 
}