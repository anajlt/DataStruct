#include <iostream> 
using namespace std;

// Estrutura do n� da lista duplamente encadeada
struct NO {
    int info;    // valor armazenado no n�
    NO* prox;    // ponteiro para o pr�ximo n� da lista
    NO* ant;     // ponteiro para o n� anterior da lista
};

// Classe da lista duplamente encadeada
class ListaDupla {
private:
    NO* inicio;   // ponteiro para o in�cio da lista
    NO* fim;      // ponteiro para o fim da lista
    int tamanho;  // quantidade de elementos na lista

    // Fun��o auxiliar privada para busca recursiva
    NO* BuscarRecAux(NO* no, int valor) {
        if (no == NULL) return NULL;   // caso base: fim da lista, retorna NULL
        if (no->info == valor) return no; // encontrou o valor, retorna o n�
        return BuscarRecAux(no->prox, valor); // chamada recursiva para o pr�ximo n�
    }

public:
    // Construtor da lista
    ListaDupla() {
        inicio = fim = NULL; // inicializa ponteiros como NULL
        tamanho = 0;         // inicializa tamanho da lista como zero
    }

    // Verifica se a lista est� vazia
    bool ListaVaziaLD() { 
        return inicio == NULL; 
    }

    // Inserir elemento no in�cio da lista
    // Evita duplicatas
    void InserirInicioLD(int k) {
        // percorre a lista para verificar duplicata
        NO* temp = inicio;
        while (temp != NULL) {
            if (temp->info == k) {  // se j� existir
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return; // sai sem inserir
            }
            temp = temp->prox; // avan�a para o pr�ximo n�
        }

        // Cria um novo n�
        NO* novo = new NO;
        novo->info = k;   // atribui valor
        novo->ant = NULL; // como ser� o primeiro, n�o tem anterior

        // Inser��o
        if (ListaVaziaLD()) { // lista vazia
            novo->prox = NULL;
            inicio = fim = novo; // primeiro e �nico n�
        } else { // lista com elementos
            novo->prox = inicio; // pr�ximo do novo aponta para antigo in�cio
            inicio->ant = novo;  // anterior do antigo in�cio aponta para o novo
            inicio = novo;       // atualiza in�cio da lista
        }

        tamanho++; // atualiza tamanho
    }

    // Inserir elemento em qualquer posi��o
    void InserirPosicao(int k, int pos) {
        // verifica posi��o v�lida
        if (pos < 0 || pos > tamanho) {
            cout << "Posi��o inv�lida!" << endl;
            return;
        }

        // Se posi��o 0, chama inser��o no in�cio
        if (pos == 0) {
            InserirInicioLD(k);
            return;
        }

        // Verificar duplicata
        NO* temp = inicio;
        while (temp != NULL) {
            if (temp->info == k) {
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return;
            }
            temp = temp->prox;
        }

        // Criar novo n�
        NO* novo = new NO;
        novo->info = k;

        // Percorrer at� o n� anterior � posi��o desejada
        temp = inicio;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->prox;

        // Ajustar ponteiros para inserir no meio ou final
        novo->prox = temp->prox;
        novo->ant = temp;
        if (temp->prox != NULL)
            temp->prox->ant = novo; // pr�ximo n� aponta para o novo
        else
            fim = novo; // atualiza fim se inserir no final
        temp->prox = novo;

        tamanho++; // atualiza tamanho
    }

    // Imprimir todos os elementos da lista
    void Imprimir() {
        NO* temp = inicio;  // come�a do in�cio
        cout << "Lista: ";
        while (temp != NULL) {
            cout << temp->info << " "; // imprime valor do n�
            temp = temp->prox;         // vai para pr�ximo n�
        }
        cout << endl;
    }

    // Busca recursiva de elemento
    NO* BuscarRec(int valor) {
        return BuscarRecAux(inicio, valor); // chama fun��o auxiliar
    }

    // Excluir elemento em qualquer posi��o
    void Excluir(int pos) {
        if (ListaVaziaLD()) { // lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }

        if (pos < 0 || pos >= tamanho) { // posi��o inv�lida
            cout << "Posi��o inv�lida!" << endl;
            return;
        }

        NO* temp = inicio;

        // Excluir primeiro n�
        if (pos == 0) {
            inicio = temp->prox;   // atualiza in�cio
            if (inicio != NULL)
                inicio->ant = NULL; // ajusta anterior
            else
                fim = NULL;         // lista ficou vazia
            delete temp;             // libera mem�ria
            tamanho--;
            return;
        }

        // Percorrer at� a posi��o desejada
        for (int i = 0; i < pos; i++)
            temp = temp->prox;

        // Ajustar ponteiros dos n�s vizinhos
        if (temp->ant != NULL)
            temp->ant->prox = temp->prox;
        if (temp->prox != NULL)
            temp->prox->ant = temp->ant;
        else
            fim = temp->ant; // atualiza fim se for o �ltimo

        delete temp; // libera mem�ria do n�
        tamanho--;
    }

    // Retorna o tamanho atual da lista
    int Tamanho() { return tamanho; }
};

// Fun��o principal para testar a lista
int main() {
    ListaDupla lista; // cria objeto da lista

    // Inser��es no in�cio
    lista.InserirInicioLD(10); 
    lista.InserirInicioLD(20); 

    // Inser��o no meio
    lista.InserirPosicao(15, 1); 
    lista.Imprimir(); // esperado: 20 15 10

    // Tentativa de duplicata
    lista.InserirInicioLD(15); // mensagem: j� existe

    // Busca recursiva
    NO* encontrado = lista.BuscarRec(15);
    if (encontrado != NULL)
        cout << "Elemento 15 encontrado!" << endl;
    else
        cout << "Elemento 15 n�o encontrado!" << endl;

    // Exclus�o de elemento da posi��o 1
    lista.Excluir(1); 
    lista.Imprimir(); // esperado: 20 10

    return 0;
}