#include <iostream>       
using namespace std;          

// Definição de um nó da lista encadeada
typedef struct Reg {  
    int infor;                // armazena o valor do nó
    Reg *prox;                // ponteiro para o próximo nó da lista
} No;                         // cria um alias "No" para a struct Reg

// Estrutura da pilha
typedef struct TipoPilha {
    No *Topo;                 // ponteiro para o topo da pilha (último elemento inserido)
    int tamanho;              // contador para controlar quantos elementos existem na pilha
} Pilha;                      // cria um alias "Pilha" para a struct TipoPilha

// Função para inicializar a pilha
void inicializarPilha(Pilha *p) {
    p->Topo = NULL;           // inicializa o topo como NULL (pilha vazia)
    p->tamanho = 0;           // inicializa o tamanho como 0
}

// Inserir elementos (push)
void push(Pilha *p, int valor) {
    No *novo = new No;        // aloca dinamicamente um novo nó
    novo->infor = valor;      // armazena o valor no novo nó
    novo->prox = p->Topo;     // faz o novo nó apontar para o topo atual
    p->Topo = novo;           // atualiza o topo da pilha para o novo nó
    p->tamanho++;             // incrementa o tamanho da pilha
    cout << "Elemento " << valor << " inserido na pilha.\n"; // mensagem de sucesso
}

// Remover elementos (pop)
int pop(Pilha *p) {
    if (p->Topo == NULL) {    // verifica se a pilha está vazia
        cout << "Pilha vazia, nada a remover.\n";
        return -1;            // retorna -1 se não houver elementos
    }
    No *remover = p->Topo;    // ponteiro temporário para o nó que será removido
    int valor = remover->infor; // armazena o valor do nó removido
    p->Topo = remover->prox;  // atualiza o topo para o próximo nó
    delete remover;           // libera a memória do nó removido
    p->tamanho--;             // decrementa o tamanho da pilha
    cout << "Elemento " << valor << " removido da pilha.\n"; // mensagem de sucesso
    return valor;             // retorna o valor removido
}

// Listar conteúdo da pilha
void listar(Pilha *p) {
    if (p->Topo == NULL) {    // verifica se a pilha está vazia
        cout << "A pilha esta vazia.\n";
        return;               // sai da função
    }
    
    cout << "Conteudo da pilha (do topo para base): ";
    No *aux = p->Topo;        // ponteiro auxiliar para percorrer a pilha
    while (aux != NULL) {     // enquanto não chegar ao final
        cout << aux->infor << " "; // mostra o valor do nó
        aux = aux->prox;           // passa para o próximo nó
    }
    cout << endl;              // quebra de linha após imprimir todos os elementos
}

// Buscar elemento na pilha
bool buscar(Pilha *p, int valor) {
    No *aux = p->Topo;        // ponteiro auxiliar para percorrer a pilha
    while (aux != NULL) {     // enquanto houver nós
        if (aux->infor == valor) { // se encontrar o valor
            cout << "Elemento " << valor 
                 << " encontrado na pilha.\n";
            return true;       // retorna verdadeiro
        }
        aux = aux->prox;       // avança para o próximo nó
    }
    cout << "Elemento " << valor << " NAO encontrado na pilha.\n";
    return false;              // retorna falso se não encontrar
}

// Função principal com menu
int main() {
    Pilha p;                   // declara uma pilha
    inicializarPilha(&p);      // inicializa a pilha

    int opcao, valor;          // variáveis para armazenar opção do menu e valor

    do {
        cout << "\n===== MENU PILHA =====\n";
        cout << "1 - Inserir elemento (push)\n";
        cout << "2 - Remover elemento (pop)\n";
        cout << "3 - Listar pilha\n";
        cout << "4 - Buscar elemento\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;          // lê a opção do usuário

        switch (opcao) {       // verifica a opção escolhida
            case 1:
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;  // lê o valor
                push(&p, valor);// chama a função push
                break;
            case 2:
                pop(&p);       // chama a função pop
                break;
            case 3:
                listar(&p);    // chama a função listar
                break;
            case 4:
                cout << "Digite o valor a buscar: ";
                cin >> valor;  // lê o valor a buscar
                buscar(&p, valor); // chama a função buscar
                break;
            case 0:
                cout << "Saindo...\n"; // mensagem ao sair
                break;
            default:
                cout << "Opcao invalida!\n"; // mensagem para opção inválida
        }

    } while (opcao != 0);      // repete o menu enquanto não for sair

    return 0;                   
}
