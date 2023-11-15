/*
 * main.cpp
 *
 *  Created on: 29.10.2023
 *      Author: julius
 */
#include "Fahrzeug.hpp"
#include "global.hpp"
#include "PKW.hpp"
#include "Fahrrad.hpp"
#include "Weg.hpp"
#include <stdio.h>

void vAufgabe4() {
//	// Erstellen der Objekte ohne Einlesen
//	std::unique_ptr<Fahrzeug> pkw1 = std::make_unique<PKW>("pkw1", 100.0, 1, 0, 12, 55, 0);
//	std::unique_ptr<PKW> pkw2 = std::make_unique<PKW>("PKW2", 150.0, 2, 0, 10.0, 50.0, 0);
//	std::unique_ptr<Fahrrad> fahrrad1 = std::make_unique<Fahrrad>("Fahrrad", 30.0, 3, 0);

	//Weg(std::string name, double laenge, Tempolimit tempolimit = Tempolimit::Autobahn);
	std::vector<std::unique_ptr<Weg>> vWege;
	std::unique_ptr<Weg> weg = std::make_unique<Weg>("A40", 120, Tempolimit::Autobahn);
	vWege.push_back(std::move(weg));

	std::vector<std::unique_ptr<Fahrzeug> > vPKWFahrrad;

	    short int siInputNumberFahrrad = 0;
	    short int siInputNumberPKW = 0;
	    std::cout << "Wie viele Fahrräder wollen Sie abspeichern?" << "\n";
	    std::cin >> siInputNumberFahrrad;
	    std::cout << "Wie viele PKW wollen Sie abspeichern?" << "\n";
	    std::cin >> siInputNumberPKW;

	    // Fahrräder erstellen
	    for (int iID=0; iID<siInputNumberFahrrad; ++iID) {
	        std::string sNameF ;
	        double dMaxGeschwindigkeit = 0;

	        std::cout << "Name des Fahrrads NR:" << iID+1 << ": ";
	        std::cin >> sNameF;
	        std::cout << "Höchstgeschwindigkeit?";
	        std::cin >> dMaxGeschwindigkeit;

	        vPKWFahrrad.push_back(std::make_unique<Fahrrad>(sNameF, dMaxGeschwindigkeit, iID, 0));
	    }

	    // PKW erstellen
	    for (int iID=0; iID<siInputNumberPKW; ++iID) {
	        std::string name;
	        double MaxGeschwindigkeit = 0;
	        double p_dVerbrauch = 0;
	        double p_dTankvolumen = 0;
	        double p_dGesamtStrecke = 0;
	        double dTankinhalt = 0;

	        std::cout << "Name des PKW: ";
	        std::cin >> name;
	        std::cout << "Höchstgeschwindigkeit: ";
	        std::cin >> MaxGeschwindigkeit;
	        std::cout << "Verbrauch: ";
	        std::cin >> p_dVerbrauch;
	        std::cout << "Tankvolumen: ";
	        std::cin >> p_dTankvolumen;

	        vPKWFahrrad.push_back(std::make_unique<PKW>(name, MaxGeschwindigkeit, iID, p_dGesamtStrecke, p_dVerbrauch, p_dTankvolumen,dTankinhalt));
	    }

	    for (int i=0; i<=30; i++){

	    	for (const auto& fz : vPKWFahrrad) {
	            // Dynamische Typumwandlung zu Fahrrad
	            if (auto fahrradPtr = dynamic_cast<Fahrrad*>(fz.get())) {
	                std::cout << *fahrradPtr << std::endl;
	            }
	            // Dynamische Typumwandlung zu PKW
	            else if (auto pkwPtr = dynamic_cast<PKW*>(fz.get())) {
	                std::cout << *pkwPtr << std::endl;
	            }

	    	    fz->vSimulieren();
	        }
	    	vPKWFahrrad.front()->vKopf();

		    for (const auto& weg : vWege) {
		        // Annahme: vKopf() und vSimulieren() sind in der Klasse Weg oder einer Basisklasse definiert
		        weg->vKopf();
		        weg->vSimulieren();
		        std::cout << *weg << "\n";

		        // Optional: Ausgabe der Fahrzeuge auf dem Weg
		        weg->vFahrzeugeAusgeben();
		    }

		    if (vWege.empty() || vPKWFahrrad.empty()) {
		        std::cerr << "Vektoren sind leer!" << std::endl;
		        return;
		    }
	    }

//	    std::cout << *Weg1_ptr << "\n";
//


}

int main()
{
	vAufgabe4();

	return 1;
}

