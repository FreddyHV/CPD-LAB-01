#include <iostream>
#include <vector>

const int MAX = 1000; // Definir el tamaño de la matriz y los vectores

int main() {
    // Inicialización de la matriz A y los vectores x, y
    std::vector<std::vector<double>> A(MAX, std::vector<double>(MAX, 1.0)); // Matriz A con valores 1.0
    std::vector<double> x(MAX, 1.0);  // Vector x con valores 1.0
    std::vector<double> y(MAX, 0.0);  // Vector y inicializado a 0

    // Primer par de bucles (mejor rendimiento esperado debido al acceso contiguo a memoria)
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j]; // Acceso contiguo en memoria (acceso fila por fila)
        }
    }

    // Reinicializar el vector y a 0
    std::fill(y.begin(), y.end(), 0.0);

    // Segundo par de bucles (peor rendimiento esperado debido a accesos menos contiguos en memoria)
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j]; // Acceso menos contiguo (acceso columna por columna)
        }
    }

    std::cout << "Calculo completado." << std::endl;
    return 0;
}
