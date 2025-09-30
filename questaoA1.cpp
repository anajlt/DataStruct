#include <iostream> //biblioteca para entrada e saída padrão (cin, cout)
using namespace std; //evitar escrever "std::" antes de cout, cin, etc.

// Função 1: fatorial de um número n usando recursão
int f1(int n) {
    if (n == 0) return 1; // caso base: fatorial de 0 é 1
    else return n * f1(n - 1); // caso recursivo: n! = n * (n-1)!
}

// Função 2: sequência recursiva específica
int f2(int n) {
    if (n == 0) return 1;  // caso base: F2(0) = 1
    if (n == 1) return 1;  // caso base: f2(1) = 1
    return f2(n - 1) + 2 * f2(n - 2);  // caso recursivo: f2(n) = f2(n-1) + 2*f2(n-2)
}

// Função 3: imprime números de n até 0 recursivamente
void f3(int n) {
    if (n == 0) {
        cout << "Zero ";  // caso base: imprimir zero
    } else {
        cout << n << " ";  // imprime n
        cout << n << " "; // repete conforme o enunciado
        f3(n - 1);      // chamada recursiva com n-1
    }
}

int main() {
    int opcao, n;    // variáveis para escolha do menu e entrada do usuário
    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Calcular fatorial (f1)\n";
        cout << "2 - Calcular sequencia (f2)\n";
        cout << "3 - Imprimir ate zero (f3)\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;  // recebe a opção do usuário

        switch (opcao) {
            case 1:
                cout << "Digite n: ";
                cin >> n;  // entrada para fatorial
                cout << "f1(" << n << ") = " << f1(n) << endl;  // mostra resultado
                break;

            case 2:
                cout << "Digite n: ";
                cin >> n;  // entrada para sequência
                cout << "f2(" << n << ") = " << f2(n) << endl;  // mostra resultado
                break;

            case 3:
                cout << "Digite n: ";
                cin >> n;  // entrada para impressão até 0
                cout << "f3(" << n << ") => ";  // chama a função de impressão
                f3(n);
                cout << endl;
                break;

            case 0:
                cout << "Encerrando..." << endl;  // mensagem de encerramento
                break;

            default:
                cout << "Opcao invalida!" << endl;  // tratamento de entrada inválida
        }
    } while (opcao != 0);  // repete o menu até o usuário escolher 0

    return 0;

}