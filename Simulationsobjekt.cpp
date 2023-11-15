/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 29.10.2023
 *      Author: julius
 */

#include "Simulationsobjekt.hpp"
#include <stdio.h>


Simulationsobjekt::~Simulationsobjekt() {
	  std::cout << "Fahrzeug " << p_sName << " geloescht!" << std::endl;

}

// Funktion zum Anzeigen der Informationen über das Fahrzeug
void Simulationsobjekt::vAusgeben(std::ostream& os) const{ // @suppress("Member declaration not found")
    os << std::setw(15) << std::left << p_iID << std::setw(15) << std::left << p_sName << "\n";
}

std::ostream& operator<<(std::ostream& os, const Simulationsobjekt& simu) {
    simu.vAusgeben(os);
    return os;
}

// Initialisierung der statischen Klassenvariable außerhalb der Klasse
int Simulationsobjekt::p_iMaxID = 1;

void Simulationsobjekt::vSimulieren(){}

bool Simulationsobjekt::operator==(const Simulationsobjekt& simu) const{
	return (p_iID == simu.p_iID);
}
