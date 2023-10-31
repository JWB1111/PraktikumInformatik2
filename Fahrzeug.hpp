//
//  Fahrzeug.hpp
//  Aufgabenblock_1
//
//  Created by Julius Wolf on 01.10.23.
//

#ifndef FAHRZEUG_HPP
#define FAHRZEUG_HPP

#include "Simulationsobjekt.hpp"




class Fahrzeug : public Simulationsobjekt {
public:
    double p_dMaxGeschwindigkeit = 0;
    double p_dGesamtStrecke = 0;
    double p_dGesamtZeit = 0; //gesamte Fahrzeit des Objektes
    double p_dGefahreneStrecke = 0;

    // Konstruktoren
    Fahrzeug(std::string name);
    Fahrzeug(std::string name, double MaxGeschwindigkeit);
    Fahrzeug(std::string name, double MaxGeschwindigkeit, int iID, double dGesamtStrecke);
    Fahrzeug();
    virtual ~Fahrzeug()= default;

    double p_dTankinhalt = 0;

    std::string getName() const;

    // Funktion für UI
    static void vKopf();

//    virtual void vAusgeben() const;


    // Simulationsfunktion
    virtual void vSimulieren();

//    // Hauptfunktion zu Aufgabe 4.3.9
//    virtual void vAufgabe_1a() const;

//    // Variablen Check
//    virtual void vTestSim();

    int getMaxGeschwindigkeit(){return p_dMaxGeschwindigkeit;}

    double getGefahreneStrecke() const {return p_dGefahreneStrecke;}

    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity()){return 0;};

    virtual double dGeschwindigkeit () const;

    virtual void vAusgeben(std::ostream& os) const;



    bool operator<(const Fahrzeug& other) const {
            return this->getGefahreneStrecke() < other.getGefahreneStrecke();
        }

    Fahrzeug& operator=(const Fahrzeug& other) {
            if (this != &other) {
                // Kopieren der Stammdaten (name, MaxGeschwindigkeit, ID)
                this->p_sName = other.p_sName;
                this->p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
                this->p_iID = other.p_iID;
            }
            return *this;
        }

};


std::ostream& operator<<(std::ostream& os, const Fahrzeug& fahrzeug);

#endif // FAHRZEUG_HPP
