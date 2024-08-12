//Include header file
#include "BlackScholes.h"
#include <iostream>

using namespace std;

//Constructor 
BlackScholes::BlackScholes(double s, double k, double r, double t, double v) : spotPriceOfUnderlying(s), strikePrice(k), interestRate(r), yearsToMaturity(t), volatilityOfUnderlying(v) {}

double BlackScholes::getCallPrice() const {
    double d1 = (log(spotPriceOfUnderlying / strikePrice) + (interestRate + 0.5 * volatilityOfUnderlying * volatilityOfUnderlying) * yearsToMaturity) / (volatilityOfUnderlying * sqrt(yearsToMaturity));
    double d2 = d1 - volatilityOfUnderlying * sqrt(yearsToMaturity);

    return spotPriceOfUnderlying * getNormalDistribution(d1) - strikePrice * std::exp(-interestRate * yearsToMaturity) * getNormalDistribution(d2);
}

double BlackScholes::getPutPrice() const {
    double d1 = (log(spotPriceOfUnderlying / strikePrice) + (interestRate + 0.5 * volatilityOfUnderlying * volatilityOfUnderlying) * yearsToMaturity) / (volatilityOfUnderlying * sqrt(yearsToMaturity));
    double d2 = d1 - volatilityOfUnderlying * sqrt(yearsToMaturity);

    return strikePrice * exp(-interestRate * yearsToMaturity) * getNormalDistribution(-d2) - spotPriceOfUnderlying * getNormalDistribution(-d1);
}

double BlackScholes::getNormalDistribution(double x) const {
    return 0.5 * erfc(-x / sqrt(2));
}