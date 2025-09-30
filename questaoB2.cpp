#include <iostream>
using namespace std;

// Defini��o de um n� da lista encadeada
typedef struct Reg {  // reg representa n� da lista encadeada
    int infor;        // dado armazenado no n�
    Reg *prox;        // ponteiro para o pr�ximo n�
} No;

// Estrutura da pilha
typedef struct TipoPilha {
    No *Topo;         // ponteiro para o n� do topo da pilha
    int tamanho;      // quantidade de elementos na pilha
} Pilha;

// Fun��o para inicializar a pilha
void inicializarPilha(Pilha *p) {
    p->Topo = NULL;  // no in�cio a pilha est� vazia
    p->tamanho = 0;
}

// a) Inserir elementos (push)
void push(Pilha *p, int valor) {
    No *novo = new No;        // cria novo n� dinamicamente
    novo->infor = valor;      // armazena o valor
    novo->prox = p->Topo;     // faz o novo n� apontar para o antigo topo
    p->Topo = novo;           // atualiza o topo para o novo n�
    p->tamanho++;
    cout << "Elemento " << valor << " inserido na pilha.\n";
}

// b) Excluir elementos (pop)
int pop(Pilha *p) {
    if (p->Topo == NULL) {   // se a pilha est� vazia
        cout << "Pilha vazia, nada a remover.\n";
        return -1;  // valor de erro
    }
    No *remover = p->Topo;      // n� a ser removido
    int valor = remover->infor; // guarda o valor
    p->Topo = remover->prox;    // atualiza o topo
    delete remover;             // libera mem�ria
    p->tamanho--;
    cout << "Elemento " << valor << " removido da pilha.\n";
    return valor;
}

// c) Listar conte�do da pilha
void listar(Pilha *p) {
    if (p->Topo == NULL) {               // se n�o h� elementos (pilha vazia)
        cout << "A pilha esta vazia.\n";    // mensagem de aviso
        return;                             // sai da fun��o
    }
    
    cout << "Conteudo da pilha (do topo para base): ";
    No *aux = p->Topo;                      // ponteiro auxiliar come�a no topo
    while (aux != NULL) {                // enquanto n�o chegar no fim da lista
        cout << aux->infor << " ";          // imprime o valor do n� atual
        aux = aux->prox;                    // avan�a para o pr�ximo n�
    }
    cout << endl;                           // quebra de linha no final
}

// d) Verificar se um dado elemento est� presente na pilha
bool buscar(Pilha *p, int valor) {
    No *aux = p->Topo;                      // come�a a busca a partir do topo
    while (aux != NULL) {                // percorre enquanto houver n�s
        if (aux->infor == valor) {          // se encontrou o valor
            cout << "Elemento " << valor 
                 << " encontrado na pilha.\n";
            return true;                    // retorna verdadeiro
        }
        aux = aux->prox;                    // avan�a para o pr�ximo n�
    }
    // Se percorreu toda a pilha e n�o achou
    cout << "Elemento " << valor << " NAO encontrado na pilha.\n";
    return false;                           // retorna falso
}

// Fun��o principal para testar
int main() {
    Pilha p;                     // declara uma pilha chamada "p"
    inicializarPilha(&p);        // inicializa a pilha (Topo = nullptr, tamanho = 0)

    // Inserindo elementos na pilha
    push(&p, 10);                // insere o n�mero 10 no topo
    push(&p, 20);                // insere o n�mero 20 no topo
    push(&p, 30);                // insere o n�mero 30 no topo
                                 // agora a pilha est� assim (Topo -> Base): 30, 20, 10

    listar(&p);                  // lista os elementos da pilha: 30 20 10

    // Verifica se certos elementos est�o na pilha
    buscar(&p, 20);              // procura o elemento 20 (vai encontrar)
    buscar(&p, 40);              // procura o elemento 40 (n�o vai encontrar)

    // Remove elemento do topo da pilha
    pop(&p);                     // remove o 30 (que est� no topo)
                                 // agora a pilha est� assim: 20, 10

    listar(&p);                  // lista novamente: 20 10

    return 0;                    
}