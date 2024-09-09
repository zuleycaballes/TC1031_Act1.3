#include "Datos.h"

/*
Complejidad: O(log n)
Donde 'n' es el número de elementos en el vector 'buques'
Esta función booleana utiliza un algoritmo de búsqueda binaria para
encontrar si existe un buque cuyo UBI comienza con la serie especificada.
La búsqueda binaria es un algoritmo eficiente que divide el arreglo en 
dos partes en cada paso, reduciendo la cantidad de comparaciones necesarias.
*/

bool buscarBuque(const vector<Datos>& buques, const string& serieElegida) {
    int i = 0;
    int f = buques.size() - 1; 
    while (i <= f) { 
        int m = i + (f - i) / 2; 
        if (buques[m].ubi.substr(0, 3) == serieElegida) { 
            return true;
        } else if (buques[m].ubi < serieElegida) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }
    return false;
}

