#include <iostream>
using namespace std;

// Definição da estrutura do nó da lista encadeada
struct No {
    int info;   // valor armazenado no nó
    No* prox;   // ponteiro para o próximo nó
};

// a) Imprimir lista recursivamente
void imprimir(No* lista) {
    if (lista == NULL) return;        // caso base: se a lista está vazia, para
    cout << lista->info << " ";       // imprime o valor do nó atual
    imprimir(lista->prox);            // chama recursivamente para o próximo nó
}

// b) Buscar elemento recursivamente
bool buscar(No* lista, int x) {
    if (lista == NULL) return false;   // caso base: chegou ao fim e não encontrou
    if (lista->info == x) return true; // se encontrou o valor, retorna verdadeiro
    return buscar(lista->prox, x);     // continua buscando no restante da lista
}

// c) Excluir elemento recursivamente
No* excluir(No* lista, int x) {
    if (lista == NULL) return NULL;  // caso base: lista vazia, não há o que excluir

    if (lista->info == x) {          // se encontrou o elemento
        No* temp = lista->prox;      // salva o próximo nó
        delete lista;                // libera a memória do nó atual
        return temp;                 // retorna o próximo como novo início da lista
    }

    // caso contrário, ajusta o ponteiro prox e continua recursivamente
    lista->prox = excluir(lista->prox, x);
    return lista; // retorna a cabeça da lista (pode ter mudado ou não)
}

// Função auxiliar para inserir elemento no início da lista
No* inserir(No* lista, int x) {
    No* novo = new No();  // cria um novo nó dinamicamente
    novo->info = x;       // atribui o valor ao nó
    novo->prox = lista;   // aponta o novo nó para o antigo início
    return novo;          // retorna o novo nó como início da lista
}

// Programa principal para testar as funções
int main() {
    No* lista = NULL;  // Inicializa a lista vazia (NULL = sem elementos)

    // Inserindo elementos na lista:
    // Inserções no início ? lista final = 30 -> 20 -> 10
    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);

    cout << "Lista original: ";
    imprimir(lista);   // deve mostrar: 30 20 10
    cout << endl;

    // Testando busca
    cout << "Buscar 20: " << (buscar(lista, 20) ? "Encontrado" : "Nao encontrado") << endl;
    cout << "Buscar 50: " << (buscar(lista, 50) ? "Encontrado" : "Nao encontrado") << endl;

    // Testando exclusão
    lista = excluir(lista, 20); // remove o elemento 20 da lista

    cout << "Lista apos excluir 20: ";
    imprimir(lista);   // deve mostrar: 30 10
    cout << endl;

    return 0;
}