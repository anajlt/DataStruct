#include <iostream>        
#include <limits>           
using namespace std;       

// Estrutura do nó da lista duplamente encadeada
struct No {
    int dado;    // Valor armazenado no nó
    No* prox;    // Ponteiro para o próximo nó na lista
    No* ant;     // Ponteiro para o nó anterior na lista
};

// Função para inserir um elemento em qualquer posição
void inserir(No*& cabeca, int valor, int pos) {
    No* novo = new No;    // Cria um novo nó dinamicamente
    novo->dado = valor;   // Atribui o valor ao nó
    novo->prox = NULL;    // Inicialmente aponta para NULL
    novo->ant = NULL;     // Inicialmente aponta para NULL

    if (pos == 0) {       // Inserção no início da lista
        novo->prox = cabeca;      // Novo nó aponta para a antiga cabeÃ§a
        if (cabeca != NULL)       // Se a lista não estava vazia
            cabeca->ant = novo;   // Atualiza o ponteiro "ant" da antiga cabeça
        cabeca = novo;            // Atualiza a cabeça da lista
        return;                   // Fim da função
    }

    No* temp = cabeca;   // Ponteiro auxiliar para percorrer a lista
    int i = 0;
    while (temp != NULL && i < pos - 1) { // Avança até a posição anterior a desejada
        temp = temp->prox;
        i++;
    }

    if (temp == NULL) { // Inserir no final caso posição maior que tamanho
        cout << "PosiÃ§Ã£o maior que o tamanho da lista. Inserindo no final.\n";
        temp = cabeca;
        if (temp == NULL) { // Lista estava vazia
            cabeca = novo;
            return;
        }
        while (temp->prox != NULL)  // Vai até o último nó
            temp = temp->prox;
        temp->prox = novo;         // Último nó aponta para o novo
        novo->ant = temp;          // Novo nó aponta para o anterior
        return;
    }

    // Inserção no meio da lista
    novo->prox = temp->prox;     // Novo nó aponta para o próximo do temp
    novo->ant = temp;            // Novo nó aponta para o anterior (temp)
    if (temp->prox != NULL)      // Se temp não é o último
        temp->prox->ant = novo;  // Próximo nó aponta para o novo
    temp->prox = novo;           // Temp aponta para o novo
}

// Função para imprimir a lista
void imprimir(No* cabeca) {
    No* temp = cabeca;           // Ponteiro auxiliar
    if (temp == NULL) {          // Se a lista esá vazia
        cout << "Lista vazia.\n";
        return;
    }
    cout << "Lista: ";
    while (temp != NULL) {       // Percorre todos os nós
        cout << temp->dado << " "; // Imprime o valor
        temp = temp->prox;       // Vai para o próximo nó
    }
    cout << endl;
}

// Função recursiva para buscar um elemento (retorna ponteiro do nó)
No* buscarRec(No* cabeca, int valor) {
    if (cabeca == NULL)          // Caso base: lista vazia ou fim da lista
        return NULL;
    if (cabeca->dado == valor)   // Encontrou o valor
        return cabeca;
    return buscarRec(cabeca->prox, valor); // Chamada recursiva para o próximo nó
}

// Função para excluir um elemento em qualquer posição
void excluir(No*& cabeca, int pos) {
    if (cabeca == NULL) {        // Lista vazia
        cout << "Lista vazia!\n";
        return;
    }

    No* temp = cabeca;           // Ponteiro auxiliar

    if (pos == 0) {              // Remover do iní­cio
        cabeca = temp->prox;     // Atualiza a cabeça
        if (cabeca != NULL)
            cabeca->ant = NULL;  // Atualiza o ponteiro ant do novo primeiro nó
        delete temp;             // Libera memória
        return;
    }

    int i = 0;
    while (temp != NULL && i < pos) { // Percorre até a posição desejada
        temp = temp->prox;
        i++;
    }

    if (temp == NULL) {           // Posição inválida
        cout << "PosiÃ§Ã£o invÃ¡lida!\n";
        return;
    }

    // Atualiza ponteiros dos nós vizinhos
    if (temp->ant != NULL)
        temp->ant->prox = temp->prox;
    if (temp->prox != NULL)
        temp->prox->ant = temp->ant;

    delete temp;                  // Libera memória
}

// Função para contar elementos
int contar(No* cabeca) {
    int c = 0;                     // Contador
    No* temp = cabeca;             // Ponteiro auxiliar
    while (temp != NULL) {         // Percorre toda a lista
        c++;                        // Incrementa contador
        temp = temp->prox;         // Avança para próximo nó
    }
    return c;                      // Retorna quantidade de elementos
}

// Função para liberar memória da lista
void liberarLista(No*& cabeca) {
    while (cabeca != NULL) {       // Enquanto houver nós
        No* tmp = cabeca;          // Guarda nó atual
        cabeca = cabeca->prox;     // Avança para o próximo
        delete tmp;                // Libera memória
    }
}

int main() {
    No* lista = NULL;             // Inicializa lista vazia
    int opcao;                    // Variável para armazenar opção do usuário

    do {
        // Menu de opções
        cout << "\n=== MENU LISTA DUPLAMENTE ENCADEADA ===\n";
        cout << "1 - Inserir (valor + posicao)\n";
        cout << "2 - Imprimir\n";
        cout << "3 - Buscar valor\n";
        cout << "4 - Excluir por posicao\n";
        cout << "5 - Contar elementos\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";

        // Validação de entrada
        if (!(cin >> opcao)) {
            cin.clear();           // Limpa flag de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
            cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }

        int valor, pos;
        switch (opcao) {
            case 1:  // Inserir
                cout << "Valor: ";
                if (!(cin >> valor)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido.\n";
                    break;
                }
                cout << "Posicao (0 = inicio): ";
                if (!(cin >> pos)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "PosiÃ§Ã£o invalida.\n";
                    break;
                }
                if (pos < 0) {
                    cout << "Posicao invalida.\n";
                } else {
                    inserir(lista, valor, pos); // Chama função inserir
                    cout << "Inserido.\n";
                }
                break;
            case 2:  // Imprimir
                imprimir(lista);
                break;
            case 3:  // Buscar
                cout << "Valor a buscar: ";
                if (!(cin >> valor)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido.\n";
                    break;
                }
                {
                    No* achou = buscarRec(lista, valor);
                    if (achou != NULL)
                        cout << "Elemento " << valor << " encontrado.\n";
                    else
                        cout << "Elemento " << valor << " NAO encontrado.\n";
                }
                break;
            case 4:  // Excluir
                cout << "Posicao a excluir (0 = inicio): ";
                if (!(cin >> pos)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Posicao invalida.\n";
                    break;
                }
                if (pos < 0) {
                    cout << "Posicao invalida.\n";
                } else {
                    excluir(lista, pos);
                    cout << "Operacao concluida.\n";
                }
                break;
            case 5:  // Contar
                cout << "Numero de elementos: " << contar(lista) << endl;
                break;
            case 0:  // Sair
                cout << "Saindo e liberando memoria...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    liberarLista(lista);   // Libera toda a memória da lista
    return 0;              
}
