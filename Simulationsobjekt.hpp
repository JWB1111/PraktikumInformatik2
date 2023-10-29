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
	static int p_iMaxID = 0;
	int p_iID = 0;
    std::string p_sName;
    double p_dZeit = 0; //Zeit, zu der das Fahrzeug zuletzt simuliert wurde

    virtual void vAusgeben(std::ostream& os) const;
    virtual void vSimulieren();


    virtual void vEinlesen(){};
	virtual Simulationsobjekt()= default;

	std::ostream& operator<<(std::ostream& os, const Simulationsobjekt& simulationsobjekt);

	virtual ~Simulationsobjekt();


};

#endif /* SIMULATIONSOBJEKT_HPP_ */
