#pragma once
#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <vector>

class MonteCarlo {
private:

    //Spot price of underlying asset
    double spotPriceOfUnderlying;

    //Strike price
    double strikePrice;

    //Risk-free rate
    double riskFreeRate;

    //Volatility of underlying asset
    double volatilityOfUnderlying;

    //Years to maturity
    double yearsToMaturity;

    //Desired number of simulations
    int simulations;

    //The "generateRandomNormal" method generates and returns a random "shock value" from a normal distribution for simulating unexpected asset price flunctuations
    double generateRandomNormal();

    //The "simulatePrice" method simulates and returns a potential future price of the underlying asset
    double simulatePrice();

public:

    //Constructor
    MonteCarlo(double spotPriceOfUnderlying, double strikePrice, double riskFreeRate, double volatilityOfUnderlying, double yearsToMaturity, int simulations);

    //The "priceOption" method returns the Monte Carlo option price
    double priceOption();
};

#endif