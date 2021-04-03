#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main() {
    ifstream in_file;
    in_file.open("test.in", ios::in);
    int N;

    ofstream out_file;
    out_file.open("test.out", ios::out);

    if (in_file.is_open()) {
        while (in_file >> N) {
            std::cout << "N = " << N << "\n\n";
            double X[N][N];
            std::cout << "X = \n";
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    in_file >> X[i][j];
                    std::cout << X[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";

            double a;
            double dct[N][N];
            std::cout << "C = \n";
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    if (i == 0) {
                        a = sqrt(1.0 / N);
                    } else {
                        a = sqrt(2.0 / N);
                    }
                    dct[i][j] = a * cos(M_PI * (2 * j + 1) * i  / (2 * N));

                    std::cout << dct[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";

            double dct_t[N][N];
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    dct_t[i][j] = dct[j][i];
                }
            }

            double Y[N][N];
            double temp[N][N];
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    double val = 0;
                    for (int k = 0; k<N; k++) {
                        val += dct[i][k] * X[k][j];
                    }
                    temp[i][j] = val;
                }
            }

            std::cout << "Y = \n";
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    double val = 0;
                    for (int k = 0; k<N; k++) {
                        val += temp[i][k] * dct_t[k][j];
                    }
                    Y[i][j] = val;

                    std::cout << Y[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";

            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    if (round(Y[i][j]) == 0) {
                        out_file << 0;
                    } else {
                        out_file << round(Y[i][j]);
                    }
                    if (j != N-1) {
                        out_file << " ";
                    }
                }
                out_file << "\n";
            }
            out_file << "\n";
        }
    }

    in_file.close();
    out_file.close();
}