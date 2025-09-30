#include <iostream>
using namespace std;

// Definição de um nó da lista encadeada
typedef struct Reg {  // reg representa nó da lista encadeada
    int infor;        // dado armazenado no nó
    Reg *prox;        // ponteiro para o próximo nó
} No;

// Estrutura da pilha
typedef struct TipoPilha {
    No *Topo;         // ponteiro para o nó do topo da pilha
    int tamanho;      // quantidade de elementos na pilha
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *p) {
    p->Topo = NULL;  // no início a pilha está vazia
    p->tamanho = 0;
}

// a) Inserir elementos (push)
void push(Pilha *p, int valor) {
    No *novo = new No;        // cria novo nó dinamicamente
    novo->infor = valor;      // armazena o valor
    novo->prox = p->Topo;     // faz o novo nó apontar para o antigo topo
    p->Topo = novo;           // atualiza o topo para o novo nó
    p->tamanho++;
    cout << "Elemento " << valor << " inserido na pilha.\n";
}

// b) Excluir elementos (pop)
int pop(Pilha *p) {
    if (p->Topo == NULL) {   // se a pilha está vazia
        cout << "Pilha vazia, nada a remover.\n";
        return -1;  // valor de erro
    }
    No *remover = p->Topo;      // nó a ser removido
    int valor = remover->infor; // guarda o valor
    p->Topo = remover->prox;    // atualiza o topo
    delete remover;             // libera memória
    p->tamanho--;
    cout << "Elemento " << valor << " removido da pilha.\n";
    return valor;
}

// c) Listar conteúdo da pilha
void listar(Pilha *p) {
    if (p->Topo == NULL) {               // se não há elementos (pilha vazia)
        cout << "A pilha esta vazia.\n";    // mensagem de aviso
        return;                             // sai da função
    }
    
    cout << "Conteudo da pilha (do topo para base): ";
    No *aux = p->Topo;                      // ponteiro auxiliar começa no topo
    while (aux != NULL) {                // enquanto não chegar no fim da lista
        cout << aux->infor << " ";          // imprime o valor do nó atual
        aux = aux->prox;                    // avança para o próximo nó
    }
    cout << endl;                           // quebra de linha no final
}

// d) Verificar se um dado elemento está presente na pilha
bool buscar(Pilha *p, int valor) {
    No *aux = p->Topo;                      // começa a busca a partir do topo
    while (aux != NULL) {                // percorre enquanto houver nós
        if (aux->infor == valor) {          // se encontrou o valor
            cout << "Elemento " << valor 
                 << " encontrado na pilha.\n";
            return true;                    // retorna verdadeiro
        }
        aux = aux->prox;                    // avança para o próximo nó
    }
    // Se percorreu toda a pilha e não achou
    cout << "Elemento " << valor << " NAO encontrado na pilha.\n";
    return false;                           // retorna falso
}

// Função principal para testar
int main() {
    Pilha p;                     // declara uma pilha chamada "p"
    inicializarPilha(&p);        // inicializa a pilha (Topo = nullptr, tamanho = 0)

    // Inserindo elementos na pilha
    push(&p, 10);                // insere o número 10 no topo
    push(&p, 20);                // insere o número 20 no topo
    push(&p, 30);                // insere o número 30 no topo
                                 // agora a pilha está assim (Topo -> Base): 30, 20, 10

    listar(&p);                  // lista os elementos da pilha: 30 20 10

    // Verifica se certos elementos estão na pilha
    buscar(&p, 20);              // procura o elemento 20 (vai encontrar)
    buscar(&p, 40);              // procura o elemento 40 (não vai encontrar)

    // Remove elemento do topo da pilha
    pop(&p);                     // remove o 30 (que está no topo)
                                 // agora a pilha está assim: 20, 10

    listar(&p);                  // lista novamente: 20 10

    return 0;                    
}