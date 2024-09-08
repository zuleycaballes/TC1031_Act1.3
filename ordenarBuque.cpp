#include "Datos.h"
#include <vector>
#include <algorithm>

using namespace std;

// Compara dos objetos de clase Datos. Compara los atributos de UBI de los objetos y los ordena en menor y mayor. 
// En el caso de que los atributos de UBI sean iguales en ambos objetos, pasa a comparar los atributos de fecha.
bool compararDatos(const Datos& a, const Datos& b) {
    if (a.ubi != b.ubi) return a.ubi < b.ubi;
    return a.fecha < b.fecha;
}

// Función para combinar dos subarreglos ordenados
// Complejidad: O(n)
void merge(vector<Datos>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
   
    vector<Datos> L(n1), R(n2);
   
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
   
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (compararDatos(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
   
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
   
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
Función de ordenamiento merge sort
Complejidad: O(n log n)
Divide, de forma recursiva, al vector en mitades sucesivamente hasta llegar a subvectores con un solo elemento; después, utiliza la función merge para
combinar estas mitades y ordenarlas respecto a su valor y así reconstruir al vector original de manera ordenada. Recibe un vector arr y el rango de este (l y r).
*/
void mergeSort(vector<Datos>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/*
Función principal para ordenar el vector de buques
Complejidad: O(n log n)
Esta función de tipo void implementa un algoritmo de ordenamiento por mezcla (merge sort). Recibe el vector buques y el rango de este (left y right).
*/
void ordenarBuque(vector<Datos>& buques, int left, int right) {
    mergeSort(buques, left, right);
}
