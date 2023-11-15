/*
 * Simulationsobjekt.hpp
 *
 *  Created on: 29.10.2023
 *      Author: julius
 */

#ifndef SIMULATIONSOBJEKT_HPP_
#define SIMULATIONSOBJEKT_HPP_

#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include <memory>
#include <vector>
#include <math.h>

class Simulationsobjekt {
public:
	static int p_iMaxID;
	int p_iID;
    std::string p_sName;
    double p_dZeit; //Zeit, zu der das Fahrzeug zuletzt simuliert wurde
    // Verbieten des Copy-Konstruktors
     Simulationsobjekt(const Simulationsobjekt&) = delete;


    virtual void vAusgeben(std::ostream& os) const;
    virtual void vSimulieren();


    virtual void vEinlesen(){};

    Simulationsobjekt() : p_iID(p_iMaxID++), p_sName(""), p_dZeit(0.0) {}

    // Konstruktor mit Parameter für den Namen
    Simulationsobjekt(std::string name) : p_iID(p_iMaxID++), p_sName(name), p_dZeit(0.0) {}


	virtual ~Simulationsobjekt();


	bool operator==(const Simulationsobjekt& simu) const;

};

std::ostream& operator<<(std::ostream& os, const Simulationsobjekt& simulationsobjekt);



#endif /* SIMULATIONSOBJEKT_HPP_ */
