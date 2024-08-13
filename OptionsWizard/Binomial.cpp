//Header file
#include "Binomial.h"

using namespace std;

//Constructor
Binomial::Binomial(double S, double K, double R, double Y, double V, int steps, bool isCall)
    : spotPriceOfUnderlying(S), strikePrice(K), riskFreeRate(R), yearsToMaturity(Y), volatilityOfUnderlying(V), stepsForBinomial(steps), isCall(isCall) {}

//Method to calculate the payoff of the option at expiration for a given stock price.
double Binomial::optionPayoff(double stockPrice) {

    //If the option is a call
    if (isCall) {

        //Call option payoff by finding the greater of 0 or stockPrice - strikePrice
        return max(0.0, stockPrice - strikePrice);
    }

    //If the option is a put
    else {

        //Put option payoff by finding the greater of 0 or strikePrice - stockPrice
        return max(0.0, strikePrice - stockPrice);
    }
}

