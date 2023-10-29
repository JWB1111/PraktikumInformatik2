//
//  Fahrrad.hpp
//  Aufgabenblock_1
//
//  Created by Julius Wolf on 11.10.23.
//

#ifndef Fahrrad_hpp
#define Fahrrad_hpp

#include "Fahrzeug.hpp"

#include <stdio.h>



class Fahrrad : public Fahrzeug {
private:
    int p_iGaenge = 21;

public:
    Fahrrad() = default;
    Fahrrad(std::string name, double MaxGeschwindigkeit, int iID, double dGesamtStrecke);

    void vSimulieren() override;
    void vAusgeben(std::ostream& os) const override;

    double dGeschwindigkeit() const override;

};

std::ostream& operator<<(std::ostream& os, const Fahrrad& Fahrrad);

#endif /* Fahrrad_hpp */
