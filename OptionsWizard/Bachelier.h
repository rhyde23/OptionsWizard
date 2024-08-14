#pragma once
#ifndef BACHELIER_H
#define BACHELIER_H

#include <cmath>

class Bachelier {
private:
    //Spot price of underlying asset
    double spotPriceOfUnderlying;

    //Strike price
    double strikePrice;

    //Years to maturity
    double yearsToMaturity;

    //Interest rate
    double interestRate;

    //Volatility of underlying asset
    double volatilityOfUnderlying;

public:

    //Constructor
    Bachelier(double spotPriceOfUnderlying, double strikePrice, double yearsToMaturity, double interestRate, double volatilityOfUnderlying);

    //The "getCallPrice" method calculates the Bachelier call option price
    double getCallPrice() const;

    //The "getPutPrice" method calculates the Bachelier put option price
    double getPutPrice() const;

    //The "getNormalDistribution" method calculates the normal cumulative distribution function
    double getNormalDistribution(double x) const;
};

#endif