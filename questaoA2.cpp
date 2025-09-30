#include <iostream>
using namespace std;

// Função recursiva que soma apenas os números pares de 0 até n
int somaPares(int n) {
    if (n <= 0) return 0;              // caso base: se n <= 0, soma é 0
    if (n % 2 != 0) return somaPares(n-1); // se for ímpar, ignora e chama para n-1
    return n + somaPares(n-2);         // se for par, soma e continua recursão
}

int main() {
    int n;  // variável para armazenar entrada do usuário
    cout << "Digite um numero: ";  // mensagem para o usuário
    cin >> n;  // recebe o valor digitado

    int resultado = somaPares(n); // chama a função somaPares passando n e guarda resultado 
    cout << "Soma dos pares de 0 ate " << n << " = " << resultado << endl;  // mostra resultado

    return 0;
}