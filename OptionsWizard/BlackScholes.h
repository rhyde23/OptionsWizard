#pragma once
#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

//Black-Scholes model class
class BlackScholes {

//Define inputs
private:

    //Spot price of underlying asset
    double spotPriceOfUnderlying;

    //Strike price
    double strikePrice;

    //Risk-free interest rate
    double interestRate;

    //Years to maturity
    double yearsToMaturity;
    
    //Volatility of underlying asset
    double volatilityOfUnderlying;

    //The "getNormalDistribution" method calculates the normal cumulative distribution function
    double getNormalDistribution(double x) const;

//Define methods
public:

    //Constructor
    BlackScholes(double spotPriceOfUnderlying, double strikePrice, double interestRate, double yearsToMaturity, double volatilityOfUnderlying);

    //The "getCallPrice" method returns the call price using Black-Scholes
    double getCallPrice() const;

    //The "getPutPrice" method returns the put price using Black-Scholes
    double getPutPrice() const;
};

#endif // BLACKSCHOLES_H