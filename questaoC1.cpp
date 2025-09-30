#include <iostream> 
using namespace std;

// Estrutura de um n� da lista duplamente encadeada
struct No {
    int dado;     // valor armazenado no n�
    No* prox;     // ponteiro para o pr�ximo n�
    No* ant;      // ponteiro para o n� anterior
};

// Fun��o para inserir um elemento em qualquer posi��o
void inserir(No*& cabeca, int valor, int pos) {
    No* novo = new No;  // cria um novo n�
    novo->dado = valor; // atribui o valor ao novo n�
    novo->prox = NULL; // inicializa o ponteiro pr�ximo como NULL
    novo->ant = NULL;  // inicializa o ponteiro anterior como NULL

    if (pos == 0) { // inser��o no in�cio
        novo->prox = cabeca; // o pr�ximo do novo n� aponta para o antigo primeiro n�
        if (cabeca != NULL)
            cabeca->ant = novo; // o anterior do antigo primeiro n� aponta para o novo n�
        cabeca = novo; // atualiza a cabe�a da lista
        return; // termina a fun��o
    }

    No* temp = cabeca; // n� tempor�rio para percorrer a lista
    int i = 0;
    // percorre at� a posi��o anterior � desejada
    while (temp != NULL && i < pos - 1) {
        temp = temp->prox; // avan�a para o pr�ximo n�
        i++; // incrementa o contador
    }

    if (temp == NULL) { // posi��o inv�lida
        cout << "Posi��o inv�lida!" << endl;
        delete novo; // libera mem�ria do n� n�o inserido
        return;
    }

    // Ajusta os ponteiros para inserir no meio ou no final
    novo->prox = temp->prox; // pr�ximo do novo n� aponta para o n� que vem depois
    novo->ant = temp;        // anterior do novo n� aponta para o n� atual
    if (temp->prox != NULL)
        temp->prox->ant = novo; // o anterior do pr�ximo n� aponta para o novo n�
    temp->prox = novo;          // pr�ximo do n� atual aponta para o novo n�
}

// Fun��o para imprimir a lista
void imprimir(No* cabeca) {
    No* temp = cabeca; // n� tempor�rio para percorrer a lista
    cout << "Lista: ";
    while (temp != NULL) {
        cout << temp->dado << " "; // imprime o valor do n� atual
        temp = temp->prox;         // avan�a para o pr�ximo n�
    }
    cout << endl; // quebra de linha ap�s imprimir todos os elementos
}

// Fun��o recursiva para buscar um elemento
No* buscarRec(No* cabeca, int valor) {
    if (cabeca == NULL) // lista vazia ou fim da lista
        return NULL;
    if (cabeca->dado == valor) // encontrou o valor
        return cabeca;
    return buscarRec(cabeca->prox, valor); // chamada recursiva para o pr�ximo n�
}

// Fun��o para excluir um elemento em qualquer posi��o
void excluir(No*& cabeca, int pos) {
    if (cabeca == NULL) { // lista vazia
        cout << "Lista vazia!" << endl;
        return;
    }

    No* temp = cabeca; // n� tempor�rio para percorrer a lista

    if (pos == 0) { // excluir o primeiro n�
        cabeca = temp->prox;      // atualiza a cabe�a da lista
        if (cabeca != NULL)
            cabeca->ant = NULL; // atualiza o anterior do novo primeiro n�
        delete temp;               // libera mem�ria do n� removido
        return;
    }

    int i = 0;
    while (temp != NULL && i < pos) {
        temp = temp->prox; // avan�a para o n� a ser removido
        i++;
    }

    if (temp == NULL) { // posi��o inv�lida
        cout << "Posi��o inv�lida!" << endl;
        return;
    }

    // Ajusta os ponteiros dos n�s vizinhos
    if (temp->ant != NULL)
        temp->ant->prox = temp->prox; // n� anterior aponta para o pr�ximo do n� a ser removido
    if (temp->prox != NULL)
        temp->prox->ant = temp->ant;  // n� pr�ximo aponta para o anterior do n� a ser removido

    delete temp; // libera mem�ria do n� removido
}

int main() {
    No* lista = NULL; // cabe�a da lista inicializada como vazia

    // Testando inser��o
    inserir(lista, 10, 0); // inserir no in�cio
    inserir(lista, 20, 1); // inserir no final
    inserir(lista, 15, 1); // inserir no meio
    imprimir(lista);       // esperado: 10 15 20

    // Testando busca recursiva
    int valor = 15; // valor a ser buscado
    No* encontrado = buscarRec(lista, valor); // chama a fun��o recursiva de busca
    if (encontrado != NULL)
        cout << "Elemento " << valor << " encontrado!" << endl;
    else
        cout << "Elemento " << valor << " n�o encontrado!" << endl;

    // Testando exclus�o
    excluir(lista, 1); // excluir o elemento da posi��o 1 (15)
    imprimir(lista);   // esperado: 10 20

    return 0; 
}