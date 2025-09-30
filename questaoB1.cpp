#include <iostream> 
using namespace std;

// Estrutura do nó da lista encadeada
struct No {
    int info;      // campo que guarda o valor do nó
    No* proximo;   // ponteiro para o próximo nó da lista
};

// Função a) Criar uma lista vazia
No* criarLista() {
    return NULL; // lista vazia: NULL = nao existe nó inicial
}

// Função b) Inserir um elemento na lista (no início)
void inserirElemento(No*& lista, int valor) {
    No* novo = new No;    // cria um novo nó na memória
    novo->info = valor;   // atribui o valor ao campo "info"
    novo->proximo = lista; // faz o novo nó apontar para o primeiro nó atual
    lista = novo;         // atualiza o ponteiro da lista para o novo nó
}

// Função c) Percorrer toda a lista e imprimir os elementos
void percorrerLista(No* lista) {
    No* atual = lista;    // começa pelo primeiro nó da lista
    while (atual != NULL) { // enquanto não chegar ao fim da lista
        cout << atual->info << " "; // imprime o valor do nó atual
        atual = atual->proximo;     // avança para o próximo nó
    }
    cout << endl;         // quebra de linha ao final
}

// Função d) Retornar o número de elementos da lista
int contarElementos(No* lista) {
    int contador = 0;     // inicializa contador
    No* atual = lista;    // começa pelo primeiro nó
    while (atual != NULL) { // percorre até o fim da lista
        contador++;       // conta um nó
        atual = atual->proximo; // avança para o próximo nó
    }
    return contador;      // retorna o total de nós
}

int main() {
    No* minhaLista = criarLista(); // criar lista vazia

    // Inserindo elementos na lista
    inserirElemento(minhaLista, 10); // inserir elemento 10
    inserirElemento(minhaLista, 20); // inserir elemento 20
    inserirElemento(minhaLista, 30); // inserir elemento 30

    // Percorrer lista e mostrar elementos
    cout << "Elementos da lista: ";
    percorrerLista(minhaLista);

    // Mostrar quantidade de elementos na lista
    cout << "Numero de elementos na lista: " << contarElementos(minhaLista) << endl;

    return 0; 
}