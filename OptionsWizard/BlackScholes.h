#pragma once
#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

//Black-Scholes model class
class BlackScholes {

//Define inputs
private:

    //Spot price of underlying asset
    double spotPriceOfUnderlying;

    //Struje price
    double strikePrice;

    //Risk-free interest rate
    double interestRate;

    //Years to maturity
    double yearsToMaturity;
    
    //Volatility of underlying asset
    double volatilityOfUnderlying;

//Define methods
public:

    //Constructor - will be cin user input
    BlackScholes();
    
    //Double method returning call price
    double getCallPrice() const;

    //Double method returning put price
    double getPutPrice() const;

    //Double method calculating the normal cumulative distribution function
    double getNormalDistribution() const;
};

#endif // BLACKSCHOLES_H