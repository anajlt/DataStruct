#include <iostream>      
#include <limits>        
using namespace std;     

// Estrutura do nó da fila (cada elemento da fila)
struct No {
    int infor;   // Valor armazenado no nó
    No* prox;    // Ponteiro para o próximo nó na fila
};

// Estrutura da fila
struct Fila {
    No* frente;  // Ponteiro para o primeiro elemento da fila
    No* tras;    // Ponteiro para o último elemento da fila
    int tamanho; // Quantidade de elementos na fila
};

// Inicializa a fila (deixa vazia)
void inicializarFila(Fila* f) {
    f->frente = NULL;  // Não há primeiro elemento
    f->tras = NULL;    // Não há último elemento
    f->tamanho = 0;    // Tamanho inicial é zero
}

// Função para inserir elemento no final da fila (enqueue)
void enqueue(Fila* f, int valor) {
    No* novo = new No;  // Cria um novo nó dinamicamente
    novo->infor = valor; // Atribui o valor ao nó
    novo->prox = NULL;   // Como será o último nó, aponta para NULL

    // Se a fila está vazia, frente e tras apontam para o novo nó
    if (f->tras == NULL) {
        f->frente = novo;
    } else {
        f->tras->prox = novo; // O último nó atual aponta para o novo nó
    }
    f->tras = novo; // Atualiza o ponteiro "tras" para o novo nó
    f->tamanho++;   // Incrementa o tamanho da fila
    cout << "Elemento " << valor << " inserido na fila.\n";
}

// Função para remover elemento do iní­cio da fila (dequeue)
int dequeue(Fila* f) {
    if (f->frente == NULL) { // Se a fila está vazia
        cout << "Fila vazia, nada a remover.\n";
        return -1;           // Retorna valor inválido
    }
    No* remover = f->frente;       // Guarda o nó que será removido
    int valor = remover->infor;    // Salva o valor para retornar
    f->frente = remover->prox;     // Atualiza a frente para o próximo nó
    if (f->frente == NULL) {       // Se a fila ficou vazia
        f->tras = NULL;            // Atualiza também o ponteiro "tras"
    }
    delete remover;                // Libera a memória do nó removido
    f->tamanho--;                  // Decrementa o tamanho da fila
    cout << "Elemento " << valor << " removido da fila.\n";
    return valor;                  // Retorna o valor removido
}

// Função para listar todos os elementos da fila
void listar(Fila* f) {
    if (f->frente == NULL) {       // Se a fila está vazia
        cout << "A fila esta vazia.\n";
        return;
    }
    cout << "Conteudo da fila (da frente para o final): ";
    No* aux = f->frente;          // Auxiliar para percorrer a fila
    while (aux != NULL) {          // Enquanto houver elementos
        cout << aux->infor << " "; // Mostra o valor
        aux = aux->prox;           // Passa para o próximo nó
    }
    cout << endl;
}

// Função para buscar um valor na fila
bool buscar(Fila* f, int valor) {
    No* aux = f->frente;           // Auxiliar para percorrer a fila
    while (aux != NULL) {           // Enquanto houver elementos
        if (aux->infor == valor) {  // Se encontrar o valor
            cout << "Elemento " << valor << " encontrado na fila.\n";
            return true;
        }
        aux = aux->prox;           // Vai para o próximo nó
    }
    cout << "Elemento " << valor << " NAO encontrado na fila.\n";
    return false;                   // Retorna falso se não encontrou
}

// Função para liberar toda a memória da fila
void liberarFila(Fila* f) {
    while (f->frente != NULL) {     // Enquanto houver elementos
        No* tmp = f->frente;       // Guarda o nó atual
        f->frente = f->frente->prox; // Avança para o próximo nó
        delete tmp;                // Libera a memória do nó antigo
    }
    f->tras = NULL;                 // Ponteiro "tras" também fica NULL
    f->tamanho = 0;                 // Tamanho volta a zero
}

// Função principal
int main() {
    Fila f;                        // Declara a fila
    inicializarFila(&f);           // Inicializa a fila vazia

    int opcao;                     // Armazena a opção do usuário
    int valor;                     

    do {
        // Menu de opções
        cout << "\n=== MENU FILA ===\n";
        cout << "1 - Inserir\n";
        cout << "2 - Remover\n";
        cout << "3 - Listar\n";
        cout << "4 - Buscar elemento\n";
        cout << "5 - Mostrar tamanho\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";

        // Validação da entrada
        if (!(cin >> opcao)) {         
            cin.clear();              
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }

        // Executa ação de acordo com a opção
        switch (opcao) {
            case 1:
                cout << "Digite o valor a inserir: ";
                if (cin >> valor) {       // Valida entrada
                    enqueue(&f, valor);   // Chama função para inserir
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido.\n";
                }
                break;
            case 2:
                dequeue(&f);             // Chama função para remover
                break;
            case 3:
                listar(&f);              // Chama função para listar
                break;
            case 4:
                cout << "Valor a buscar: ";
                if (cin >> valor) {
                    buscar(&f, valor);   // Chama função de busca
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido.\n";
                }
                break;
            case 5:
                cout << "Tamanho da fila: " << f.tamanho << endl;
                break;
            case 0:
                cout << "Encerrando e liberando memoria...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);           // Repete até o usuário digitar 0

    liberarFila(&f);                 // Libera toda a memória da fila
    return 0;                        
}
