//
//  Fahrzeug.cpp
//  Aufgabenblock_1
//
//  Created by Julius Wolf on 01.10.23.
//

#include "Fahrzeug.hpp"
#include "global.hpp"


//Globale Variablen
double dGlobaleZeit = 0.0;

// Initialisierung der statischen Klassenvariable außerhalb der Klasse
int Fahrzeug::p_iMaxID = 1;
//double Fahrzeug::p_dZeit = 0;
//double Fahrzeug::p_dMaxGeschwindigkeit = 40;

// Konstruktor mit Parameter für den Namen und Initialisierung der ID
Fahrzeug::Fahrzeug(std::string name) : p_iID(p_iMaxID++), p_sName(name), p_dZeit(p_dZeit=0), p_dMaxGeschwindigkeit(p_dMaxGeschwindigkeit=0) {}

// Default-Konstruktor: Initialisiert den Namen mit einem leeren String und vergibt eine ID
Fahrzeug::Fahrzeug() : p_iID(p_iMaxID++), p_sName(""),p_dZeit(0.0), p_dMaxGeschwindigkeit(0), p_dGesamtStrecke(0.0), p_dGesamtZeit(0.0) {}


// KOnstruktor der Auto-Namen und Vmax in Beziehung stellt
Fahrzeug::Fahrzeug(std::string name, double p_dMaxGeschwindigkeit)
: p_sName(name), p_dMaxGeschwindigkeit(p_dMaxGeschwindigkeit), p_iID(p_iMaxID++), p_dGesamtStrecke(0.0), p_dZeit(0.0), p_dGesamtZeit(0.0){}

//Konstruktor der die Ausgabefunktion in TAbellenform ermöglicht
Fahrzeug::Fahrzeug(std::string name, double MaxGeschwindigkeit, int iID, double GesamtStrecke)
: p_sName(name), p_dMaxGeschwindigkeit(MaxGeschwindigkeit), p_iID(p_iMaxID++), p_dGesamtStrecke(GesamtStrecke), p_dZeit(0.0), p_dGesamtZeit(0.0){}



// Funktion zum Anzeigen der Informationen über das Fahrzeug
void Fahrzeug::vAusgeben(std::ostream& os) const{ // @suppress("Member declaration not found")
    os << std::setw(15) << std::left << p_iID << std::setw(15) << std::left << p_sName << std::setw(15) << std::right << dGeschwindigkeit() << " km/h" << std::setw(20) << std::right << std::fixed << std::setprecision(6) << (p_dGesamtStrecke / 10) << " km ";
}


void Fahrzeug::vKopf() {
    std::cout << std::setw(15) << std::left << "ID" << std::setw(15) << "Name" << std::setw(15) << "Aktuelle Geschwindigkeit" << std::setw(15) << " " << "Gesamtstrecke" << "  " << std::right << "Gesamtverbrauch" << std::setw(15) << std::right << "Tankinhalt" << "  "  << "MaxGeschwindigkeit" << std::endl;
}

void Fahrzeug::vSimulieren() {
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

Fahrzeug::~Fahrzeug() {
    std::cout << "Fahrzeug " << p_sName << " geloescht!" << std::endl;
}

double Fahrzeug::dGeschwindigkeit () const
{return 1;}
