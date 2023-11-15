/*
 * Weg.hpp
 *
 *  Created on: 29.10.2023
 *      Author: julius
 */

#ifndef WEG_HPP_
#define WEG_HPP_

#include <iostream>
#include <list>
#include <memory>
#include "Simulationsobjekt.hpp"
#include "Tempolimit.hpp"

class Fahrzeug;

class Weg : public Simulationsobjekt {
private:
    double p_dLaenge; // Länge des Weges in km
    Tempolimit p_eTempolimit; // Maximal zulässige Geschwindigkeit auf dem Weg

public:
    Weg(std::string name, double laenge, Tempolimit tempolimit = Tempolimit::Autobahn);

    std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge; // Liste von Fahrzeugen auf dem Weg


    // Funktion zum Hinzufügen eines Fahrzeugs zum Weg
    void vFahrzeugHinzufuegen(std::unique_ptr<Fahrzeug> fahrzeug);

    void vFahrzeugeAusgeben() const;

    double getLaenge() const;

    Tempolimit getTempolimit() const;

    void vSimulieren() override;

    void vAusgeben(std::ostream& os) const override;

    static void vKopf();


};
std::ostream& operator<<(std::ostream& os, const Weg& weg);


#endif


