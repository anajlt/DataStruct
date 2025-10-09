#include <iostream>  
using namespace std; 

// Estrutura do nó da lista encadeada
struct No {
    int info;        // Valor armazenado dentro do nó (pode ser um número, por exemplo)
    No* proximo;     // Ponteiro que aponta para o próximo nó da lista
};

// a) Criar lista vazia
No* criarLista() {
    return NULL;     // Retorna NULL, indicando que a lista começa vazia (sem nós)
}

// b) Inserir elemento (no inÃ­cio)
void inserirElemento(No*& lista, int valor) { // "lista" é passada por referência (&) para atualizar o ponteiro original
    No* novo = new No;        // Cria um novo nó dinamicamente na memória
    novo->info = valor;       // Coloca o valor digitado dentro do nó
    novo->proximo = lista;    // Faz o novo nó apontar para o antigo primeiro nó da lista
    lista = novo;             // Atualiza o ponteiro da lista para que o novo nó seja o primeiro
}

// c) Percorrer e imprimir lista
void percorrerLista(No* lista) {
    No* atual = lista;        // Cria um ponteiro auxiliar para percorrer a lista

    if (atual == NULL) {      // Se a lista estiver vazia (sem nós)
        cout << "Lista vazia.\n";
        return;               // Sai da função
    }

    // Enquanto ainda houver nós na lista...
    while (atual != NULL) {
        cout << atual->info << " ";  // Mostra o valor do nó atual
        atual = atual->proximo;      // AvanÃ§a para o próximo nó
    }

    cout << endl; // Pula uma linha após mostrar todos os elementos
}

// d) Contar elementos
int contarElementos(No* lista) {
    int contador = 0;          // Contador começa em zero
    No* atual = lista;         // Ponteiro auxiliar para percorrer a lista

    while (atual != NULL) {    // Enquanto ainda houver nós na lista
        contador++;            // Incrementa o contador
        atual = atual->proximo; // Vai para o próximo nó
    }

    return contador;           // Retorna o total de elementos contados
}

// Função para liberar memória
void liberarLista(No*& lista) {
    while (lista != NULL) {           // Enquanto a lista não estiver vazia
        No* temp = lista;             // Guarda o nó atual em uma variável temporária
        lista = lista->proximo;       // Faz a lista apontar para o próximo nó
        delete temp;                  // Libera o nó atual da memória
    }
}

// Função principal (onde o programa começa)
int main() {
    No* minhaLista = criarLista(); // Cria a lista inicialmente vazia
    int opcao, valor;              // Variáveis para guardar a escolha do menu e o valor digitado

    do { // Estrutura de repetição que exibe o menu até o usuário escolher sair
        cout << "\n=== MENU ===\n";
        cout << "1 - Inserir elemento\n";
        cout << "2 - Mostrar elementos\n";
        cout << "3 - Contar elementos\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;              // Lê a opção do usuário

        switch (opcao) {           // Verifica qual opção foi escolhida
            case 1: // Inserir elemento
                cout << "Digite o valor: ";
                cin >> valor;                     // Lê o valor digitado
                inserirElemento(minhaLista, valor); // Chama a função para inserir no iní­cio da lista
                cout << "Valor inserido.\n";
                break;

            case 2: // Mostrar todos os elementos
                cout << "Elementos da lista: ";
                percorrerLista(minhaLista);        // Chama a função que percorre e imprime os elementos
                break;

            case 3: // Contar quantos elementos há na lista
                cout << "Numero de elementos: " << contarElementos(minhaLista) << endl;
                break;

            case 0: // Sair do programa
                cout << "Encerrando programa...\n";
                break;

            default: // Caso o usuário digite uma opção inválida
                cout << "Opcao invalida.\n";
        }

    } while (opcao != 0); // O menu repete até o usuário escolher "0"

    liberarLista(minhaLista); // Libera toda a memória ocupada pelos nãos antes de encerrar
    return 0;                 
}
