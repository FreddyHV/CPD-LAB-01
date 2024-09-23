#include <iostream>
#include <vector>
#include <chrono>

const int MAX = 1000; // Puedes ajustar esto para diferentes tamaños

void multiplicarMatricesClasica(const std::vector<std::vector<double>>& A,
                                 const std::vector<std::vector<double>>& B,
                                 std::vector<std::vector<double>>& C,
                                 int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0; // Inicializar C
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplicarMatricesBloques(const std::vector<std::vector<double>>& A,
                                  const std::vector<std::vector<double>>& B,
                                  std::vector<std::vector<double>>& C,
                                  int n, int tamBloque) {
    for (int i = 0; i < n; i += tamBloque) {
        for (int j = 0; j < n; j += tamBloque) {
            for (int k = 0; k < n; k += tamBloque) {
                for (int ii = i; ii < std::min(i + tamBloque, n); ii++) {
                    for (int jj = j; jj < std::min(j + tamBloque, n); jj++) {
                        for (int kk = k; kk < std::min(k + tamBloque, n); kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    std::vector<int> tamanios = {100, 200, 500, 1000}; // Diferentes tamaños para evaluar

    for (int tamano : tamanios) {
        std::cout << "Multiplicando matrices de tamaño " << tamano << "x" << tamano << std::endl;

        // Inicializar matrices A, B y C
        std::vector<std::vector<double>> A(tamano, std::vector<double>(tamano, 1.0));
        std::vector<std::vector<double>> B(tamano, std::vector<double>(tamano, 1.0));
        std::vector<std::vector<double>> C(tamano, std::vector<double>(tamano, 0.0));

        // Medir tiempo para la multiplicación clasica
        auto inicio = std::chrono::high_resolution_clock::now();
        multiplicarMatricesClasica(A, B, C, tamano);
        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracion = fin - inicio;
        std::cout << "Tiempo (clasica): " << duracion.count() << " segundos" << std::endl;

        // Reiniciar matriz C
        C.assign(tamano, std::vector<double>(tamano, 0.0));

        // Medir tiempo para la multiplicación por bloques
        int tamBloque = 16; // Tamaño de bloque
        inicio = std::chrono::high_resolution_clock::now();
        multiplicarMatricesBloques(A, B, C, tamano, tamBloque);
        fin = std::chrono::high_resolution_clock::now();
        duracion = fin - inicio;
        std::cout << "Tiempo (bloques): " << duracion.count() << " segundos" << std::endl;

        std::cout << "---------------------------" << std::endl;
    }

    return 0;
}

