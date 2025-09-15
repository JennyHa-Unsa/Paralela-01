#include <iostream>
#include <ctime>
#include <cmath>    

using namespace std;

const int MAX = 1000;

double A[MAX][MAX], x[MAX], y[MAX];

int main() {

    clock_t start, end;
    double timeFirtLoop, timeSecondLoop;

    /* Initialize A and x, assign y = 0 */
    for (int i = 0; i < MAX; i++) {
        x[i] = 2.0;
        y[i] = 0.0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = i;
        }
    }

    /* First pair of loops */
    start = clock();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    end = clock();
    timeFirtLoop = double(end - start) / CLOCKS_PER_SEC;

    /* Assign y = 0 */
    for (int i = 0; i < MAX; i++) {
        y[i] = 0.0;
    }

    /* Second pair of loops */
    start = clock();
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    end = clock();
    timeSecondLoop = double(end - start) / CLOCKS_PER_SEC;

    /* Visualizar tiempos de ejecución */
    cout << "Tiempo para el primer bucle: " << timeFirtLoop << " segundos" << endl;
    cout << "Tiempo para el segundo bucle: " << timeSecondLoop << " segundos" << endl;

    return 0;
}
