#pragma once
#ifndef NORMALDISTRIBUTION_H
#define NORMALDISTRIBUTION_H

#include <cmath>

//The "getNormalDistribution" method calculates the normal cumulative distribution function
inline double getNormalDistribution(double x) {

    //The normal CDF formula is: 0.5 * erfc(-x / sqrt(2))
    return 0.5 * erfc(-x / sqrt(2));
    
#endif