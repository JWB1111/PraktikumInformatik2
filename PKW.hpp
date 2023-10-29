//
//  PKW.hpp
//  Aufgabenblock_1
//
//  Created by Julius Wolf on 11.10.23.
//


#ifndef PKW_hpp
#define PKW_hpp

#include <stdio.h>
#include "Fahrzeug.hpp"



class PKW : public Fahrzeug {
private:
    double p_dVerbrauch = 0; // Liter/100km
    const double p_dTankvolumen = 55; // Liter
    double p_dTankinhalt = 0; // Liter

public:
    PKW () = default;
    PKW(std::string name, double MaxGeschwindigkeit, int iID, double dGesamtStrecke, double dVerbrauch, float dTankvolumen, double dTankinhalt);

    PKW(std::string name, double MaxGeschwindigkeit, double dVerbrauch, double dTankinhalt);

    void vSimulieren() override;
    void vAusgeben(std::ostream& os) const override;
    double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;

    double dGeschwindigkeit() const override;


};

std::ostream& operator<<(std::ostream& os, const PKW& pkw);

#endif /* PKW_hpp */
