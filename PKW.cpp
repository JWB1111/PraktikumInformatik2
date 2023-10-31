//
//  PKW.cpp
//  Aufgabenblock_1
//
//  Created by Julius Wolf on 11.10.23.
//


#include "PKW.hpp"

PKW::PKW(std::string name, double MaxGeschwindigkeit, int iID, double dGesamtStrecke, double dVerbrauch, float dTankvolumen, double dTankinhalt)
    : Fahrzeug(name, MaxGeschwindigkeit, iID, dGesamtStrecke),
p_dVerbrauch(dVerbrauch),
p_dTankvolumen(dTankvolumen),
p_dTankinhalt(dTankvolumen / 2)
{}
PKW::PKW
(std::string name, double MaxGeschwindigkeit, double dVerbrauch, double dTankinhalt)
: Fahrzeug (name, MaxGeschwindigkeit) {}



double PKW::dTanken(double dMenge) {
    Fahrzeug::dTanken();
    double dGetankteMenge = std::min(dMenge, p_dTankvolumen - p_dTankinhalt);
    p_dTankinhalt += dGetankteMenge;
    std::cout << "GETANKT!\n";
    return dGetankteMenge;
}

void PKW::vSimulieren() {
    Fahrzeug::vSimulieren();
    if (p_dTankinhalt > 0) {
        double gefahreneStrecke = dGeschwindigkeit() / 3.6; // in Metern pro Sekunde
        double verbrauchteMenge = (p_dVerbrauch / 1000) * gefahreneStrecke; // in Litern pro Sekunde
        p_dTankinhalt -= verbrauchteMenge;
        p_dGesamtStrecke += gefahreneStrecke;
    }else {dTanken();}
}

void PKW::vAusgeben(std::ostream& os) const{
    Fahrzeug::vAusgeben(os);
    os << std::setw(15)
    << std::right << std::setprecision(6) << (p_dGesamtStrecke / 1000 * p_dVerbrauch) << " l" << std::setw(15) << std::right << std::fixed << std::setprecision(6) << p_dTankinhalt << " l" << std::setw(15) << std::right << std::fixed << std::setprecision(2) << dGeschwindigkeit() << " km/h\n";
}

double PKW::dGeschwindigkeit() const {
    Fahrzeug::dGeschwindigkeit();
    double dGeschwindigkeit = p_dMaxGeschwindigkeit;
    return dGeschwindigkeit;
}

std::ostream& operator<<(std::ostream& os, const PKW& pkw) {
    pkw.vAusgeben(os);
    return os;
}
