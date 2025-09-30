#include <iostream>
using namespace std;

// Fun��o recursiva que soma apenas os n�meros pares de 0 at� n
int somaPares(int n) {
    if (n <= 0) return 0;              // caso base: se n <= 0, soma � 0
    if (n % 2 != 0) return somaPares(n-1); // se for �mpar, ignora e chama para n-1
    return n + somaPares(n-2);         // se for par, soma e continua recurs�o
}

int main() {
    int n;  // vari�vel para armazenar entrada do usu�rio
    cout << "Digite um numero: ";  // mensagem para o usu�rio
    cin >> n;  // recebe o valor digitado

    int resultado = somaPares(n); // chama a fun��o somaPares passando n e guarda resultado 
    cout << "Soma dos pares de 0 ate " << n << " = " << resultado << endl;  // mostra resultado

    return 0;
}