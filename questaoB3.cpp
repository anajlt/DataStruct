#include <iostream>
using namespace std;

// Defini��o de um n� da lista encadeada
typedef struct Reg {
    int infor;        // dado armazenado no n�
    Reg *prox;        // ponteiro para o pr�ximo n�
} No;

// Estrutura da fila
typedef struct TipoFila {
    No *frente;       // ponteiro para o primeiro elemento (in�cio da fila)
    No *tras;         // ponteiro para o �ltimo elemento (final da fila)
    int tamanho;      // quantidade de elementos na fila
} Fila;

// Inicializar a fila
void inicializarFila(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}

// a) Inserir elemento na fila (enqueue)
void enqueue(Fila *f, int valor) {
    No *novo = new No;          // cria novo n�
    novo->infor = valor;        // guarda o valor
    novo->prox = NULL;       // como ser� o �ltimo, prox = null

    if (f->tras == NULL) {   // se a fila est� vazia
        f->frente = novo;       // novo n� ser� o primeiro
    } else {
        f->tras->prox = novo;   // �ltimo n� aponta para o novo
    }
    f->tras = novo;             // atualiza o "tras"
    f->tamanho++;

    cout << "Elemento " << valor << " inserido na fila.\n";
}

// b) Remover elemento da fila (dequeue)
int dequeue(Fila *f) {
    if (f->frente == NULL) {   // Fila vazia
        cout << "Fila vazia, nada a remover.\n";
        return -1;
    }
    No *remover = f->frente;      // n� a ser removido � o da frente
    int valor = remover->infor;   // guarda o valor
    f->frente = remover->prox;    // avan�a o ponteiro da frente
    if (f->frente == NULL) {   // se a fila ficou vazia
        f->tras = NULL;        // ajusta o tras tamb�m
    }
    delete remover;               // libera mem�ria
    f->tamanho--;
    cout << "Elemento " << valor << " removido da fila.\n";
    return valor;
}

// c) Listar conte�do da fila
void listar(Fila *f) {
    if (f->frente == NULL) {            // se n�o h� nenhum elemento na fila
        cout << "A fila esta vazia.\n";    // imprime mensagem de fila vazia
        return;                            // sai da fun��o
    }

    cout << "Conteudo da fila (da frente para o final): ";
    No *aux = f->frente;                   // ponteiro auxiliar come�a na frente da fila
    while (aux != NULL) {               // percorre at� o final (prox == NULL)
        cout << aux->infor << " ";         // imprime o valor armazenado no n�
        aux = aux->prox;                   // avan�a para o pr�ximo n�
    }
    cout << endl;                          // quebra de linha no final da impress�o
}

// d) Verificar se um dado elemento est� presente na fila
bool buscar(Fila *f, int valor) {
    No *aux = f->frente;                   // come�a a busca pela frente da fila
    while (aux != NULL) {               // percorre cada n� at� o final
        if (aux->infor == valor) {         // se o valor do n� for o procurado
            cout << "Elemento " << valor 
                 << " encontrado na fila.\n";
            return true;                   // retorna verdadeiro e encerra
        }
        aux = aux->prox;                   // avan�a para o pr�ximo n�
    }
    // se percorreu tudo e n�o achou
    cout << "Elemento " << valor << " NAO encontrado na fila.\n";
    return false;                          // retorna falso
}

// Fun��o principal para testar
int main() {
    Fila f;                     // declara uma fila chamada "f"
    inicializarFila(&f);        // inicializa a fila (frente e tras = NULL, tamanho = 0)

    enqueue(&f, 10);            // insere o n�mero 10 na fila
    enqueue(&f, 20);            // insere o n�mero 20 na fila (vem depois do 10)
    enqueue(&f, 30);            // insere o n�mero 30 na fila (vem depois do 20)
                                // estado atual da fila: frente -> 10, 20, 30 <- tras

    listar(&f);                 // mostra o conte�do da fila: 10 20 30

    buscar(&f, 20);             // procura o elemento 20 (vai encontrar)
    buscar(&f, 40);             // procura o elemento 40 (n�o est� na fila)

    dequeue(&f);                // remove o primeiro elemento (10)
                                // agora a fila fica: 20, 30

    listar(&f);                 // mostra novamente o conte�do: 20 30

    return 0;                   
}