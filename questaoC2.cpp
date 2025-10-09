#include <iostream>        
#include <limits>          
using namespace std;       

// Estrutura do nó da lista duplamente encadeada
struct NO {
    int info;              // Armazena o valor do nó
    NO* prox;              // Ponteiro para o próximo nó
    NO* ant;               // Ponteiro para o nó anterior
};

// Classe que representa a lista duplamente encadeada
class ListaDupla {
private:
    NO* inicio;            // Ponteiro para o primeiro nó da lista
    NO* fim;               // Ponteiro para o último nó da lista
    int tamanho;           // Contador do número de elementos

    // Função auxiliar recursiva para buscar valor
    NO* BuscarRecAux(NO* no, int valor) {
        if (no == NULL) return NULL;       // Caso base: nó nulo, não encontrou
        if (no->info == valor) return no;  // Encontrou o valor, retorna ponteiro do nó
        return BuscarRecAux(no->prox, valor); // Chamada recursiva para o próximo nó
    }

public:
    // Construtor da lista
    ListaDupla() {
        inicio = fim = NULL;   // Inicializa lista vazia
        tamanho = 0;           // Inicializa tamanho como zero
    }

    // Destrutor da lista para liberar memória
    ~ListaDupla() {
        NO* aux = inicio;
        while (aux != NULL) {             // Percorre todos os nós
            NO* tmp = aux->prox;         // Guarda ponteiro para próximo nó
            delete aux;                  // Libera memória do nó atual
            aux = tmp;                   // Vai para o próximo nó
        }
    }

    // Verifica se a lista está vazia
    bool ListaVaziaLD() { return inicio == NULL; }

    // Insere elemento no início da lista
    void InserirInicioLD(int k) {
        // Evita duplicatas
        NO* temp = inicio;
        while (temp != NULL) {
            if (temp->info == k) {
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return;
            }
            temp = temp->prox;
        }

        NO* novo = new NO;   // Cria novo nó
        novo->info = k;      // Atribui valor
        novo->ant = NULL;    // Como será o primeiro nó, não tem anterior

        if (ListaVaziaLD()) {  // Lista vazia
            novo->prox = NULL;
            inicio = fim = novo;
        } else {                // Lista com elementos
            novo->prox = inicio;  // Aponta para o nó atual inicial
            inicio->ant = novo;   // Nó inicial atual aponta para novo nó
            inicio = novo;        // Atualiza ponteiro inicio
        }
        tamanho++;               // Incrementa tamanho
        cout << "Elemento " << k << " inserido no inicio." << endl;
    }

    // Insere elemento em uma posição específica
    void InserirPosicao(int k, int pos) {
        if (pos < 0 || pos > tamanho) { // Valida posição
            cout << "Posicao invalida!" << endl;
            return;
        }

        if (pos == 0) { // Se for no início
            InserirInicioLD(k);
            return;
        }

        // Evita duplicata
        NO* temp = inicio;
        while (temp != NULL) {
            if (temp->info == k) {
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return;
            }
            temp = temp->prox;
        }

        NO* novo = new NO;   // Cria novo nó
        novo->info = k;

        temp = inicio;
        for (int i = 0; i < pos - 1; i++)   // Percorre até o nó anterior à posição desejada
            temp = temp->prox;

        novo->prox = temp->prox;  // Próximo do novo nó será o próximo do temp
        novo->ant = temp;         // Anterior do novo nó é temp

        if (temp->prox != NULL)       // Se não for inserido no final
            temp->prox->ant = novo;   // Próximo nó aponta para novo nó como anterior
        else
            fim = novo;               // Se for final, atualiza ponteiro fim

        temp->prox = novo;            // temp aponta para novo nó
        tamanho++;                    // Incrementa tamanho
        cout << "Elemento " << k << " inserido na posicao " << pos << "." << endl;
    }

    // Imprime a lista
    void Imprimir() {
        if (ListaVaziaLD()) {
            cout << "Lista vazia." << endl;
            return;
        }
        NO* temp = inicio;
        cout << "Lista: ";
        while (temp != NULL) {       // Percorre todos os nós
            cout << temp->info << " "; 
            temp = temp->prox;
        }
        cout << endl;
    }

    // Busca recursiva de um valor na lista
    NO* BuscarRec(int valor) { return BuscarRecAux(inicio, valor); }

    // Retorna posição do valor na lista (-1 se não encontrado)
    int BuscarPos(int valor) {
        NO* temp = inicio;
        int i = 0;
        while (temp != NULL) {
            if (temp->info == valor) return i;
            temp = temp->prox;
            i++;
        }
        return -1;
    }

    // Exclui nó em determinada posição
    void Excluir(int pos) {
        if (ListaVaziaLD()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        if (pos < 0 || pos >= tamanho) {
            cout << "Posicao invalida!" << endl;
            return;
        }

        NO* temp = inicio;

        if (pos == 0) {  // Excluir do início
            inicio = temp->prox;
            if (inicio != NULL)
                inicio->ant = NULL;
            else
                fim = NULL;  // Lista ficou vazia
            delete temp;
            tamanho--;
            cout << "Elemento da posicao 0 excluido." << endl;
            return;
        }

        for (int i = 0; i < pos; i++)
            temp = temp->prox;  // Percorre até a posição

        if (temp->ant != NULL)
            temp->ant->prox = temp->prox;  // Nó anterior aponta para próximo
        if (temp->prox != NULL)
            temp->prox->ant = temp->ant;   // Próximo nó aponta para anterior
        else
            fim = temp->ant;               // Se for último, atualiza fim

        delete temp;                        // Libera memória
        tamanho--;                           // Atualiza tamanho
        cout << "Elemento da posicao " << pos << " excluido." << endl;
    }

    int Tamanho() { return tamanho; }       // Retorna tamanho da lista
};

// Função principal
int main() {
    ListaDupla lista;  // Cria objeto lista
    int opcao;

    do { // Loop do menu
        cout << "\n=== MENU LISTA DUPLA ===\n";
        cout << "1 - Inserir no inicio\n";
        cout << "2 - Inserir em posicao\n";
        cout << "3 - Imprimir\n";
        cout << "4 - Buscar valor (recursivo)\n";
        cout << "5 - Buscar posicao do valor\n";
        cout << "6 - Excluir por posicao\n";
        cout << "7 - Mostrar tamanho\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";

        if (!(cin >> opcao)) {   // Valida entrada
            cin.clear();          // Limpa flag de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
            cout << "Entrada invalida. Tente novamente." << endl;
            continue;
        }

        int valor, pos; 
        switch (opcao) {
            case 1:
                cout << "Valor a inserir no inicio: ";
                while (!(cin >> valor)) { // Valida entrada
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido. Digite novamente: ";
                }
                lista.InserirInicioLD(valor);
                break;
            case 2:
                cout << "Valor a inserir: ";
                while (!(cin >> valor)) { // Valida valor
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido. Digite novamente: ";
                }
                cout << "Posicao (0 = inicio): ";
                while (!(cin >> pos)) { // Valida posição
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Posicao invalida. Digite novamente: ";
                }
                lista.InserirPosicao(valor, pos);
                break;
            case 3:
                lista.Imprimir(); // Imprime lista
                break;
            case 4:
                cout << "Valor a buscar (recursivo): ";
                while (!(cin >> valor)) { // Valida entrada
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido. Digite novamente: ";
                }
                if (lista.BuscarRec(valor) != NULL)
                    cout << "Elemento " << valor << " encontrado." << endl;
                else
                    cout << "Elemento " << valor << " NAO encontrado." << endl;
                break;
            case 5:
                cout << "Valor a buscar a posicao: ";
                while (!(cin >> valor)) { // Valida entrada
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido. Digite novamente: ";
                }
                pos = lista.BuscarPos(valor);
                if (pos >= 0) cout << "Valor encontrado na posicao " << pos << "." << endl;
                else cout << "Valor NAO encontrado." << endl;
                break;
            case 6:
                cout << "Posicao a excluir (0 = inicio): ";
                while (!(cin >> pos)) { // Valida posição
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Posicao invalida. Digite novamente: ";
                }
                lista.Excluir(pos); // Exclui elemento
                break;
            case 7:
                cout << "Tamanho da lista: " << lista.Tamanho() << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 0); // Repete até sair

    return 0; 
}
