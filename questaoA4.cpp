#include <iostream>
#include <limits> // necessário para numeric_limits
using namespace std;

// Estrutura de um nó da lista encadeada
struct No {
    int info;
    No* prox;
};

// Função para imprimir a lista recursivamente
void imprimir(No* lista) {
    if (lista == NULL) {
        cout << "(vazia)";
        return;
    }
    cout << lista->info << " ";
    imprimir(lista->prox);
}

// Função para buscar um valor na lista (recursiva)
bool buscar(No* lista, int x) {
    if (lista == NULL) return false;
    if (lista->info == x) return true;
    return buscar(lista->prox, x);
}

// Função para excluir a primeira ocorrência de um valor na lista
No* excluir(No* lista, int x) {
    if (lista == NULL) return NULL;
    if (lista->info == x) {
        No* temp = lista->prox;
        delete lista;
        return temp;
    }
    lista->prox = excluir(lista->prox, x);
    return lista;
}

// Função para inserir um novo valor no iní­cio da lista
No* inserir(No* lista, int x) {
    No* novo = new No();
    novo->info = x;
    novo->prox = lista;
    return novo;
}

// Função para liberar toda a memória da lista
void liberarLista(No* lista) {
    while (lista != NULL) {
        No* temp = lista->prox;
        delete lista;
        lista = temp;
    }
}

// Função principal
int main() {
    No* lista = NULL;
    int opcao;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Inserir (no inicio)\n";
        cout << "2. Imprimir\n";
        cout << "3. Buscar\n";
        cout << "4. Excluir\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";

        if (!(cin >> opcao)) { // tratamento de entrada inválida
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }

        int valor;
        switch (opcao) {
            case 1:
                cout << "Valor para inserir: ";
                cin >> valor;
                lista = inserir(lista, valor);
                cout << "Inserido.\n";
                break;

            case 2:
                cout << "Lista: ";
                imprimir(lista);
                cout << "\n";
                break;

            case 3:
                cout << "Valor a buscar: ";
                cin >> valor;
                cout << (buscar(lista, valor) ? "Encontrado\n" : "Nao encontrado\n");
                break;

            case 4:
                cout << "Valor a excluir: ";
                cin >> valor;
                if (buscar(lista, valor)) {
                    lista = excluir(lista, valor);
                    cout << "Excluido (primeira ocorrencia).\n";
                } else {
                    cout << "Valor nao encontrado.\n";
                }
                break;

            case 0:
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    liberarLista(lista);
    return 0;
}


