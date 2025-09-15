#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void  inicializarMatrices(double **A, double **B, double **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i;
            B[i][j] = 1.0;
            C[i][j] = 0.0;
        }
    }
}

void multiplicarMatrices(double **A, double **B, double **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            double temp = A[i][k];
            for (int j = 0; j < n; j++) {
                C[i][j] += temp * B[k][j];
            }
        }
    }
}

int main() {
    clock_t inicio, fin;
    double tiempo;

    int tam[] = {16, 32, 64, 128, 256, 512, 1024};

    for (int i = 0; i < 7; i++) {
        int n = tam[i];
        double **A = new double*[n];
        double **B = new double*[n];
        double **C = new double*[n];

        for (int j = 0; j < n; j++) {
            A[j] = new double[n];
            B[j] = new double[n];
            C[j] = new double[n];
        }

        inicializarMatrices(A, B, C, n);

        // Medir tiempo de multiplicación
        inicio = clock();
        multiplicarMatrices(A, B, C, n);
        fin = clock();

        tiempo = double(fin - inicio) / CLOCKS_PER_SEC;
        cout << "Tiempo de multiplicación para n = " << n << ": " << tiempo << " segundos" << endl;

        // Liberar memoria
        for (int x = 0; x < n; x++) {
            delete[] A[x];
            delete[] B[x];
            delete[] C[x];
        }
        delete[] A;
        delete[] B;
        delete[] C;
    }
    
    return 0;
}