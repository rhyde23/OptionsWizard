//Include header file
#include "BlackScholes.h"
#include <iostream>

using namespace std;

//Constructor taking in:
//1: The spot price of the underlying asset
//2: The strike price
//3: The interest rate
//4: The time remaining until expiration date in years
//5: The volatility of underlying asset

BlackScholes::BlackScholes(double S, double K, double R, double Y, double V) : spotPriceOfUnderlying(S), strikePrice(K), interestRate(R), yearsToMaturity(Y), volatilityOfUnderlying(V) {}

//The "getCallPrice" method calculates the Black-Scholes call option price
double BlackScholes::getCallPrice() const {

    //Calculate d1 using the Black-Scholes formula
    double d1 = (log(spotPriceOfUnderlying / strikePrice) + (interestRate + 0.5 * volatilityOfUnderlying * volatilityOfUnderlying) * yearsToMaturity) / (volatilityOfUnderlying * sqrt(yearsToMaturity));
    
    // Calculate d2 using the Black-Scholes formula
    double d2 = d1 - volatilityOfUnderlying * sqrt(yearsToMaturity);

    //Calculate the call option price using the Black-Scholes formula
    return spotPriceOfUnderlying * getNormalDistribution(d1) - strikePrice * std::exp(-interestRate * yearsToMaturity) * getNormalDistribution(d2);
}

//The "getPutPrice" method calculates the Black-Scholes put option price
double BlackScholes::getPutPrice() const {

    //Calculate d1 using the Black-Scholes formula
    double d1 = (log(spotPriceOfUnderlying / strikePrice) + (interestRate + 0.5 * volatilityOfUnderlying * volatilityOfUnderlying) * yearsToMaturity) / (volatilityOfUnderlying * sqrt(yearsToMaturity));
    
    //Calculate d2 using the Black-Scholes formula
    double d2 = d1 - volatilityOfUnderlying * sqrt(yearsToMaturity);

    //Calculate the put option price using the Black-Scholes formula
    return strikePrice * exp(-interestRate * yearsToMaturity) * getNormalDistribution(-d2) - spotPriceOfUnderlying * getNormalDistribution(-d1);
}
//The "getNormalDistribution" method calculates the normal cumulative distribution function
double BlackScholes::getNormalDistribution(double x) const {

    //The normal CDF formula is: 0.5 * erfc(-x / sqrt(2))
    return 0.5 * erfc(-x / sqrt(2));
}