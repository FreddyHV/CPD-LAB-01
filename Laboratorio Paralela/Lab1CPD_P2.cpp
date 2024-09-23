#include <iostream>
#include <vector>
#include <chrono>  // Para medir el tiempo de ejecución

// Función para multiplicar dos matrices de tamaño n x n
void multiplicarMatrices(const std::vector<std::vector<double>>& A, 
                         const std::vector<std::vector<double>>& B, 
                         std::vector<std::vector<double>>& C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Definir tamaños de matriz para evaluar el rendimiento
    std::vector<int> tamanos = {100, 200, 500, 1000}; // Puedes agregar más tamaños si lo deseas

    for (int tamano : tamanos) {
        std::cout << "Multiplicando matrices de tamano " << tamano << "x" << tamano << std::endl;

        // Inicialización de matrices A, B y C de tamaño 'tamano' x 'tamano'
        std::vector<std::vector<double>> A(tamano, std::vector<double>(tamano, 1.0)); // Matriz A con valores 1.0
        std::vector<std::vector<double>> B(tamano, std::vector<double>(tamano, 1.0)); // Matriz B con valores 1.0
        std::vector<std::vector<double>> C(tamano, std::vector<double>(tamano, 0.0)); // Matriz C para el resultado

        // Medir el tiempo de ejecución de la multiplicación de matrices
        auto inicio = std::chrono::high_resolution_clock::now();

        // Llamada a la función de multiplicación de matrices
        multiplicarMatrices(A, B, C, tamano);

        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracion = fin - inicio;

        std::cout << "Tiempo de ejecucion: " << duracion.count() << " segundos" << std::endl;
    }

    return 0;
}


