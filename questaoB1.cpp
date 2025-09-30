#include <iostream> 
using namespace std;

// Estrutura do n� da lista encadeada
struct No {
    int info;      // campo que guarda o valor do n�
    No* proximo;   // ponteiro para o pr�ximo n� da lista
};

// Fun��o a) Criar uma lista vazia
No* criarLista() {
    return NULL; // lista vazia: NULL = nao existe n� inicial
}

// Fun��o b) Inserir um elemento na lista (no in�cio)
void inserirElemento(No*& lista, int valor) {
    No* novo = new No;    // cria um novo n� na mem�ria
    novo->info = valor;   // atribui o valor ao campo "info"
    novo->proximo = lista; // faz o novo n� apontar para o primeiro n� atual
    lista = novo;         // atualiza o ponteiro da lista para o novo n�
}

// Fun��o c) Percorrer toda a lista e imprimir os elementos
void percorrerLista(No* lista) {
    No* atual = lista;    // come�a pelo primeiro n� da lista
    while (atual != NULL) { // enquanto n�o chegar ao fim da lista
        cout << atual->info << " "; // imprime o valor do n� atual
        atual = atual->proximo;     // avan�a para o pr�ximo n�
    }
    cout << endl;         // quebra de linha ao final
}

// Fun��o d) Retornar o n�mero de elementos da lista
int contarElementos(No* lista) {
    int contador = 0;     // inicializa contador
    No* atual = lista;    // come�a pelo primeiro n�
    while (atual != NULL) { // percorre at� o fim da lista
        contador++;       // conta um n�
        atual = atual->proximo; // avan�a para o pr�ximo n�
    }
    return contador;      // retorna o total de n�s
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