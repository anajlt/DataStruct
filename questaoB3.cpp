#include <iostream>
using namespace std;

// Definição de um nó da lista encadeada
typedef struct Reg {
    int infor;        // dado armazenado no nó
    Reg *prox;        // ponteiro para o próximo nó
} No;

// Estrutura da fila
typedef struct TipoFila {
    No *frente;       // ponteiro para o primeiro elemento (início da fila)
    No *tras;         // ponteiro para o último elemento (final da fila)
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
    No *novo = new No;          // cria novo nó
    novo->infor = valor;        // guarda o valor
    novo->prox = NULL;       // como será o último, prox = null

    if (f->tras == NULL) {   // se a fila está vazia
        f->frente = novo;       // novo nó será o primeiro
    } else {
        f->tras->prox = novo;   // último nó aponta para o novo
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
    No *remover = f->frente;      // nó a ser removido é o da frente
    int valor = remover->infor;   // guarda o valor
    f->frente = remover->prox;    // avança o ponteiro da frente
    if (f->frente == NULL) {   // se a fila ficou vazia
        f->tras = NULL;        // ajusta o tras também
    }
    delete remover;               // libera memória
    f->tamanho--;
    cout << "Elemento " << valor << " removido da fila.\n";
    return valor;
}

// c) Listar conteúdo da fila
void listar(Fila *f) {
    if (f->frente == NULL) {            // se não há nenhum elemento na fila
        cout << "A fila esta vazia.\n";    // imprime mensagem de fila vazia
        return;                            // sai da função
    }

    cout << "Conteudo da fila (da frente para o final): ";
    No *aux = f->frente;                   // ponteiro auxiliar começa na frente da fila
    while (aux != NULL) {               // percorre até o final (prox == NULL)
        cout << aux->infor << " ";         // imprime o valor armazenado no nó
        aux = aux->prox;                   // avança para o próximo nó
    }
    cout << endl;                          // quebra de linha no final da impressão
}

// d) Verificar se um dado elemento está presente na fila
bool buscar(Fila *f, int valor) {
    No *aux = f->frente;                   // começa a busca pela frente da fila
    while (aux != NULL) {               // percorre cada nó até o final
        if (aux->infor == valor) {         // se o valor do nó for o procurado
            cout << "Elemento " << valor 
                 << " encontrado na fila.\n";
            return true;                   // retorna verdadeiro e encerra
        }
        aux = aux->prox;                   // avança para o próximo nó
    }
    // se percorreu tudo e não achou
    cout << "Elemento " << valor << " NAO encontrado na fila.\n";
    return false;                          // retorna falso
}

// Função principal para testar
int main() {
    Fila f;                     // declara uma fila chamada "f"
    inicializarFila(&f);        // inicializa a fila (frente e tras = NULL, tamanho = 0)

    enqueue(&f, 10);            // insere o número 10 na fila
    enqueue(&f, 20);            // insere o número 20 na fila (vem depois do 10)
    enqueue(&f, 30);            // insere o número 30 na fila (vem depois do 20)
                                // estado atual da fila: frente -> 10, 20, 30 <- tras

    listar(&f);                 // mostra o conteúdo da fila: 10 20 30

    buscar(&f, 20);             // procura o elemento 20 (vai encontrar)
    buscar(&f, 40);             // procura o elemento 40 (não está na fila)

    dequeue(&f);                // remove o primeiro elemento (10)
                                // agora a fila fica: 20, 30

    listar(&f);                 // mostra novamente o conteúdo: 20 30

    return 0;                   
}