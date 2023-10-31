//
//  Fahrzeug.cpp
//  Aufgabenblock_1
//
//  Created by Julius Wolf on 01.10.23.
//

#include "Fahrzeug.hpp"
#include "Simulationsobjekt.hpp"
#include "global.hpp"
#define Simu Simulationsobjekt

//Globale Variablen
double dGlobaleZeit = 0.0;


//double Fahrzeug::p_dZeit = 0;
//double Fahrzeug::p_dMaxGeschwindigkeit = 40;
Fahrzeug::Fahrzeug(std::string name) : Simulationsobjekt(name), p_dMaxGeschwindigkeit(0), p_dGesamtStrecke(0), p_dGesamtZeit(0), p_dGefahreneStrecke(0) {}

Fahrzeug::Fahrzeug(std::string name, double maxGeschwindigkeit) : Simulationsobjekt(name), p_dMaxGeschwindigkeit(maxGeschwindigkeit), p_dGesamtStrecke(0), p_dGesamtZeit(0), p_dGefahreneStrecke(0) {}

Fahrzeug::Fahrzeug(std::string name, double maxGeschwindigkeit, int id, double gesamtStrecke)
    : Simulationsobjekt(name), p_dMaxGeschwindigkeit(maxGeschwindigkeit), p_dGesamtStrecke(gesamtStrecke), p_dGesamtZeit(0), p_dGefahreneStrecke(0) {}

// Funktion zum Anzeigen der Informationen über das Fahrzeug
void Fahrzeug::vAusgeben(std::ostream& os) const{ // @suppress("Member declaration not found")
    Simu::vAusgeben(os);
    os << std::setw(15) << std::right << dGeschwindigkeit() << " km/h" << std::setw(20) << std::right << std::fixed << std::setprecision(6) << (p_dGesamtStrecke / 10) << " km ";}


void Fahrzeug::vKopf() {
    std::cout << std::setw(15) << std::left << "ID" << std::setw(15) << "Name" << std::setw(15) << "Aktuelle Geschwindigkeit" << std::setw(15) << " " << "Gesamtstrecke" << "  " << std::right << "Gesamtverbrauch" << std::setw(15) << std::right << "Tankinhalt" << "  "  << "MaxGeschwindigkeit" << std::endl;
}

void Fahrzeug::vSimulieren() {
	Simu::vSimulieren();
    // Aktuelle Zeit in Sekunden seit dem Programmstart
    double dAktuelleZeit = dGlobaleZeit;

    // Zeitdifferenz seit dem letzten Simulationsschritt in Stunden
    double dZeitdifferenz = (dAktuelleZeit - p_dZeit) / 3600; // Convert seconds to hours


    // Strecke = Geschwindigkeit * Zeit (in Stunden)
    double gefahreneStrecke = (dGeschwindigkeit() / 3600) * dZeitdifferenz;
    p_dGefahreneStrecke += gefahreneStrecke; // Gesamte gefahrene Strecke erhöhen

    // Letzte Abfertigungszeit aktualisieren
    p_dZeit = dAktuelleZeit;

    // Gesamtstrecke aktualisieren
    p_dGesamtStrecke += gefahreneStrecke;
}

std::ostream& operator<<(std::ostream& os, const Fahrzeug& fahrzeug) {
    fahrzeug.vAusgeben(os);
    return os;
}





std::string Fahrzeug::getName() const
{
    return p_sName;
}


double Fahrzeug::dGeschwindigkeit () const
{return 1;}
