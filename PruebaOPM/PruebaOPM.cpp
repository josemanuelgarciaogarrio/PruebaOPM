// PruebaOPM.cpp : 
// This file contains the 'main' function. 
// Program execution begins and ends there.
//
#include <iostream>
#include <omp.h>

#define N 2000
#define chunk 300
#define mostrar 30

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo\n";

    float a[N], b[N], c[N];

    int i;

    for (i = 0; i < N;i++)
    {
          a[i] = i * 10;
          b[i] = (i + 3) * 3.7;
    }

    int pedazos = chunk;
    
    # pragma omp parallel for \
    shared(a,b,c,pedazos) private(i)\
    schedule(static,pedazos)

    for (i = 0;i < N;i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primero" << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primero" << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primero" << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}

