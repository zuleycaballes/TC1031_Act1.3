#include "Datos.h"

bool buscarBuque(const vector<Datos>& buques, const string& serieElegida) {
    for (const auto& buque : buques) {
        if (buque.ubi.substr(0, 3) == serieElegida) {
            return true;
        }
    }
    return false;
}
