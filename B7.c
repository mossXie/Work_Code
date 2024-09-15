#include <stdio.h>

int main() {
    int Nx, Ny;
    scanf("%d %d", &Nx, &Ny);
    
    double xStep = 1.0 / (Nx - 1);  
    double yStep = 1.0 / (Ny - 1);  

    for (int i = 0; i < Ny; i++) {  
        double y = (1 - (i * yStep));  
        for (int j = 0; j < Nx; ++j) {  
            double x = j * xStep;   
            printf("(%.3f, %.3f) ", x, y);  
        }  
    printf("\n");  
    }  

return 0;
}