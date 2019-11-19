#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){
    int Nx = 30;
    double x1 = -1;
    double x2 = 1;
    double dx = abs(x2-x1)/Nx;
    double dt = 2.27e-3;
    int Nt = int(1/dt);
    double D = 1;
    double s = 1;
    double matrizfi[Nx][Nt];

    //Initial conditions
    for(int j = 0; j < Nt; j++){
        for(int i  = 0; i < Nx; i++){
            matrizfi[i][j] = 0;
        }
    }

    for(int j = 0; j < Nt; j++){
        for(int i = 1; i < Nx-1; i++){
            matrizfi[i][j+1] = matrizfi[i][j] + (D*dt/(dx*dx))*(matrizfi[i+1][j] - 2*matrizfi[i][j] + matrizfi[i-1][j]) + dt*s;
        }
    }

    for(int i = 0; i < Nx; i++){
        for(int j  = 1; j < Nt; j++){
            cout << i*dx + x1 << ' ' << j*dt << ' ' << matrizfi[i][j] << endl;
        }
    }

    return 0;
}