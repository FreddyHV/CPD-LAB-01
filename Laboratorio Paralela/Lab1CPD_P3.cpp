#include <iostream>
#include <vector>
#include <chrono>  // Para medir el tiempo de ejecución

// Función para multiplicar matrices por bloques
void multiplicarMatricesPorBloques(const std::vector<std::vector<double>>& A, 
                                   const std::vector<std::vector<double>>& B, 
                                   std::vector<std::vector<double>>& C, 
                                   int n, int b) {
    for (int ii = 0; ii < n; ii += b) {
        for (int jj = 0; jj < n; jj += b) {
            for (int kk = 0; kk < n; kk += b) {
                // Multiplicación de bloques
                for (int i = ii; i < std::min(ii + b, n); ++i) {
                    for (int j = jj; j < std::min(jj + b, n); ++j) {
                        for (int k = kk; k < std::min(kk + b, n); ++k) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Definir tamaños de matriz para evaluar el rendimiento
    std::vector<int> tamanos = {100, 200, 500, 1000};  // Puedes agregar más tamaños si lo deseas
    int bloque = 64;  // Tamaño del bloque

    for (int tamano : tamanos) {
        std::cout << "Multiplicando matrices de tamano " << tamano << "x" << tamano 
                  << " con tamaño de bloque " << bloque << "x" << bloque << std::endl;

        // Inicialización de matrices A, B y C de tamaño 'tamano' x 'tamano'
        std::vector<std::vector<double>> A(tamano, std::vector<double>(tamano, 1.0));  // Matriz A con valores 1.0
        std::vector<std::vector<double>> B(tamano, std::vector<double>(tamano, 1.0));  // Matriz B con valores 1.0
        std::vector<std::vector<double>> C(tamano, std::vector<double>(tamano, 0.0));  // Matriz C para el resultado

        // Medir el tiempo de ejecución de la multiplicación de matrices por bloques
        auto inicio = std::chrono::high_resolution_clock::now();

        // Llamada a la función de multiplicación de matrices por bloques
        multiplicarMatricesPorBloques(A, B, C, tamano, bloque);

        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracion = fin - inicio;

        std::cout << "Tiempo de ejecucion: " << duracion.count() << " segundos" << std::endl;
    }

    return 0;
}
