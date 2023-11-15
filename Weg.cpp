/*
 * Weg.cpp
 *
 *  Created on: 29.10.2023
 *      Author: julius
 */

#include "Weg.hpp"
#include "Fahrzeug.hpp"

Weg::Weg(std::string name, double laenge, Tempolimit tempolimit)
    : Simulationsobjekt(name), p_dLaenge(laenge), p_eTempolimit(tempolimit) {
}

void Weg::vFahrzeugHinzufuegen(std::unique_ptr<Fahrzeug> fahrzeug) {
    p_pFahrzeuge.push_back(std::move(fahrzeug));
}

void Weg::vFahrzeugeAusgeben() const {
    for (const auto& fahrzeug : p_pFahrzeuge) {
        std::cout << *fahrzeug << "\n";
    }
}

double Weg::getLaenge() const {
    return p_dLaenge;
}

Tempolimit Weg::getTempolimit() const {
    return p_eTempolimit;
}

void Weg::vSimulieren() {
	for (auto& fahrzeug : p_pFahrzeuge) {
        fahrzeug->vSimulieren();
    }
}



void Weg::vAusgeben(std::ostream& os) const {
    Simulationsobjekt::vAusgeben(os);
    os << " (Länge: " << p_dLaenge << " km, Tempolimit: ";
    switch (p_eTempolimit) {
        case Tempolimit::Innerorts:
            os << "Innerorts";
            break;
        case Tempolimit::Landstrasse:
            os << "Landstraße";
            break;
        case Tempolimit::Autobahn:
            os << "Autobahn";
            break;
    }
    os << ", Fahrzeuge: ";
    vFahrzeugeAusgeben();
    os << ")";
}

void Weg::vKopf(){
    std::cout << std::setw(5) << "ID" << " | " << std::setw(15) << "Name" << " | " << std::setw(8) << "Laenge" << " | " << "Fahrzeuge\n";
    std::cout << std::setw(50) << std::setfill('-') << "\n";
    std::cout << std::setfill(' ');
}

std::ostream& operator<<(std::ostream& os, const Weg& weg) {
    weg.vAusgeben(os);
    return os;
}
