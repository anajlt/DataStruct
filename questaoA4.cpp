#include <iostream>
using namespace std;

// Defini��o da estrutura do n� da lista encadeada
struct No {
    int info;   // valor armazenado no n�
    No* prox;   // ponteiro para o pr�ximo n�
};

// a) Imprimir lista recursivamente
void imprimir(No* lista) {
    if (lista == NULL) return;        // caso base: se a lista est� vazia, para
    cout << lista->info << " ";       // imprime o valor do n� atual
    imprimir(lista->prox);            // chama recursivamente para o pr�ximo n�
}

// b) Buscar elemento recursivamente
bool buscar(No* lista, int x) {
    if (lista == NULL) return false;   // caso base: chegou ao fim e n�o encontrou
    if (lista->info == x) return true; // se encontrou o valor, retorna verdadeiro
    return buscar(lista->prox, x);     // continua buscando no restante da lista
}

// c) Excluir elemento recursivamente
No* excluir(No* lista, int x) {
    if (lista == NULL) return NULL;  // caso base: lista vazia, n�o h� o que excluir

    if (lista->info == x) {          // se encontrou o elemento
        No* temp = lista->prox;      // salva o pr�ximo n�
        delete lista;                // libera a mem�ria do n� atual
        return temp;                 // retorna o pr�ximo como novo in�cio da lista
    }

    // caso contr�rio, ajusta o ponteiro prox e continua recursivamente
    lista->prox = excluir(lista->prox, x);
    return lista; // retorna a cabe�a da lista (pode ter mudado ou n�o)
}

// Fun��o auxiliar para inserir elemento no in�cio da lista
No* inserir(No* lista, int x) {
    No* novo = new No();  // cria um novo n� dinamicamente
    novo->info = x;       // atribui o valor ao n�
    novo->prox = lista;   // aponta o novo n� para o antigo in�cio
    return novo;          // retorna o novo n� como in�cio da lista
}

// Programa principal para testar as fun��es
int main() {
    No* lista = NULL;  // Inicializa a lista vazia (NULL = sem elementos)

    // Inserindo elementos na lista:
    // Inser��es no in�cio ? lista final = 30 -> 20 -> 10
    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);

    cout << "Lista original: ";
    imprimir(lista);   // deve mostrar: 30 20 10
    cout << endl;

    // Testando busca
    cout << "Buscar 20: " << (buscar(lista, 20) ? "Encontrado" : "Nao encontrado") << endl;
    cout << "Buscar 50: " << (buscar(lista, 50) ? "Encontrado" : "Nao encontrado") << endl;

    // Testando exclus�o
    lista = excluir(lista, 20); // remove o elemento 20 da lista

    cout << "Lista apos excluir 20: ";
    imprimir(lista);   // deve mostrar: 30 10
    cout << endl;

    return 0;
}