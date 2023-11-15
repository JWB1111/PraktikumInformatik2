/*
 * Tempolimit.hpp
 *
 *  Created on: 14.11.2023
 *      Author: julius
 */

#ifndef TEMPOLIMIT_HPP_
#define TEMPOLIMIT_HPP_

enum class Tempolimit {
    Innerorts = 50,
    Landstrasse = 100,
    Autobahn = std::numeric_limits<int>::max()
};

#endif /* TEMPOLIMIT_HPP_ */
