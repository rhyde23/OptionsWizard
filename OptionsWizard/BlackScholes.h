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

    //Double method calculating the normal cumulative distribution function
    double getNormalDistribution(double x) const;

//Define methods
public:

    //Constructor
    BlackScholes(double spotPriceOfUnderlying, double strikePrice, double interestRate, double yearsToMaturity, double volatilityOfUnderlying);

    //Double method returning call price
    double getCallPrice() const;

    //Double method returning put price
    double getPutPrice() const;
};

#endif // BLACKSCHOLES_H