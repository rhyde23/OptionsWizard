//Include header file
#include "Bachelier.h"
#include <cmath>

//Pi
double PI = 3.14159265358979323846;

using namespace std;

//Constructor taking in:
//1: The spot price of the underlying asset
//2: The strike price
//3: Years to maturity
//4: Interest rate
//5: The volatility of underlying asset

Bachelier::Bachelier(double S, double K, double Y, double R, double V)
    : spotPriceOfUnderlying(S), strikePrice(K), yearsToMaturity(Y), interestRate(R), volatilityOfUnderlying(V) {}

//The "getCallPrice" method calculates the Bachelier call option price
double Bachelier::getCallPrice() const {

    //Calculate d using the Bachelier formula
    double d = (spotPriceOfUnderlying - strikePrice) / (volatilityOfUnderlying * sqrt(yearsToMaturity));

    //Calculate the call option price using the Bachelier formula
    return (spotPriceOfUnderlying - strikePrice) * getNormalDistribution(d) + volatilityOfUnderlying * sqrt(yearsToMaturity) * (1.0 / sqrt(2.0 * PI)) * exp(-0.5 * d * d);
}

//The "getPutPrice" method calculates the Bachelier put option price
double Bachelier::getPutPrice() const {

    //Calculate d using the Bachelier formula
    double d = (spotPriceOfUnderlying - strikePrice) / (volatilityOfUnderlying * sqrt(yearsToMaturity));

    //Calculate the put option price using the Bachelier formula
    return (strikePrice - spotPriceOfUnderlying) * getNormalDistribution(-d) + volatilityOfUnderlying * sqrt(yearsToMaturity) * (1.0 / sqrt(2.0 * PI)) * exp(-0.5 * d * d);
}

//The "getNormalDistribution" method calculates the normal cumulative distribution function
double Bachelier::getNormalDistribution(double x) const {

    //The normal CDF formula is: 0.5 * erfc(-x / sqrt(2))
    return 0.5 * erfc(-x / sqrt(2));

}