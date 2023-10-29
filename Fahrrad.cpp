//
//  Fahrrad.cpp
//  Aufgabenblock_1
//
//  Created by Julius Wolf on 11.10.23.
//

#include "Fahrrad.hpp"

Fahrrad::Fahrrad(std::string name, double MaxGeschwindigkeit, int iID, double dGesamtStrecke)
: Fahrzeug(name, MaxGeschwindigkeit, iID, dGesamtStrecke){}

void Fahrrad::vSimulieren() {
    Fahrzeug::vSimulieren();
    double gefahreneStrecke = dGeschwindigkeit() / 3.6; // in Metern pro Sekunde
    p_dGesamtStrecke += gefahreneStrecke;

}
void Fahrrad::vAusgeben(std::ostream& os) const {
    Fahrzeug::vAusgeben(os); // Aufruf der Basisklassenmethode

}


double Fahrrad::dGeschwindigkeit() const {
    Fahrzeug::dGeschwindigkeit();
    double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit;

    int iGesamtStreckeCopy = int(p_dGesamtStrecke/200);

   if (dAktuelleGeschwindigkeit >= 12) {
        if (iGesamtStreckeCopy >= 1) {
            dAktuelleGeschwindigkeit = dAktuelleGeschwindigkeit * pow(0.9,iGesamtStreckeCopy);
        }
   }
    double dGeschwindigkeit = dAktuelleGeschwindigkeit;

    return dGeschwindigkeit;
}

std::ostream& operator<<(std::ostream& os, const Fahrrad& fahrrad) {
    fahrrad.vAusgeben(os);
    return os;
}
