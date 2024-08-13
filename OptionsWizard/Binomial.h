#pragma once
#ifndef BINOMIAL_H
#define BINOMIAL_H

#include <cmath>
#include <algorithm>

class Binomial {
private:
    //Spot price of underlying asset
    double spotPriceOfUnderlying;

    //Strike price
    double strikePrice;

    //Years to maturity
    double yearsToMaturity;

    //Risk-free rate
    double riskFreeRate;

    //Volatility of underlying asset
    double volatilityOfUnderlying;

    //Number of steps for the binomial tree
    int stepsForBinomial;

    //True = call option, False = put option
    bool isCall;

    //Method to calculate the payoff of the option at expiration for a given stock price.
    double optionPayoff(double stockPrice);

public:

    //Constructor
    Binomial(double S, double K, double T, double r, double sigma, int steps, bool isCall);

    //Method to calculate option price for calls and puts
    double priceOption();

};

#endif // BINOMIAL_H