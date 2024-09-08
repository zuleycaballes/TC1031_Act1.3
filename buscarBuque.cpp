#include "Datos.h"

/*
Complejidad: O(n)
Donde 'n' es el número de elementos en el vector 'buques'
Esta función booleana utiliza un algoritmo de búsqueda de tipo binaria. 
Este tipo de algoritmo es utilizado para encontrar un elemento dentro de un arreglo. 
El arreglo es dividido en 2 partes, para después elegir una de las mitades (verificando si el elemento que se busca es mayor o menor al elemento central) y así hasta encontrar el elemento,
lo que va reduciendo la cantidad de comparaciones que realiza el algoritmo. Recibe el vector buques y los 3 primeros dígitos de la serie que se desea buscar.
*/

bool buscarBuque(const vector<Datos>& buques, const string& serieElegida) {
    for (const auto& buque : buques) {
        if (buque.ubi.substr(0, 3) == serieElegida) {
            return true;
        }
    }
    return false;
}
