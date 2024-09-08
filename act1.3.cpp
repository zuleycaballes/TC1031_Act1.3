#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Datos.h"
using namespace std;


int main(){
    string nomArchivo;
    cout << "Ingresa el nombre del archivo de entrada. ";
    cin >> nomArchivo;


    ifstream inFile(nomArchivo);
    ofstream outFile("output.txt");


    if (!inFile) {
        cerr << "Error al abrir el archivo de entrada" << endl;
        return 1;
    }
    if (!outFile) {
        cerr << "Error al abrir output.txt" << endl;
        return -1;
    }


    vector<Datos> buques;
    Datos buque;


     while (inFile >> buque.fecha >> buque.hora >> buque.entrada >> buque.ubi) {
        buques.push_back(buque);
    }


    ordenarBuque(buques, 0, buques.size() - 1);


    string serieElegida;
    cout << "Ingresa los primeros 3 caracteres de el UBI a buscar. ";
    cin >> serieElegida;


    if (buscarBuque(buques, serieElegida)){
        cout << "La información de los buques de la serie " << serieElegida << ": " << endl;
        for (const Datos& buque : buques){
            if (buque.ubi.substr(0, 3) == serieElegida){
                cout << buque.fecha << " " << buque.hora << " " << buque.entrada << " " << buque.ubi << endl;
            }
        }
    } else {
        cout << "No se encontraron buques con la serie " << serieElegida << endl;
    }

    return 0;

}
