#include <iostream>
using namespace std;

// Função recursiva que calcula a * b usando soma repetida
int produto(int a, int b) {
    if (b == 0) return 0;       // tratamento extra: qualquer a * 0 = 0
    if (b == 1) return a;       // caso base: a * 1 = a
    return a + produto(a, b-1); // passo recursivo: soma a + (a * (b-1))
}

int main() {
    int a, b;  // variáveis para armazenar valor de entrada
    cout << "Digite o valor de a: ";  // solicita valor de a
    cin >> a;  // lê valor de a
    cout << "Digite o valor de b: ";
    cin >> b;

    int resultado = produto(a, b);  // chama função produto para calcular a * b
    cout << a << " * " << b << " = " << resultado << endl;  // mostra resultado final

    return 0;
}