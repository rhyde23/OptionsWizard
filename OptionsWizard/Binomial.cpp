//Header file
#include "Binomial.h"

using namespace std;

//Constructor taking in:
//1: The spot price of the underlying asset
//2: The strike price
//3: Years to maturity
//4: Risk-free rate
//5: The volatility of underlying asset
//6: The number of steps in Binomial tree
//7: Call or Put?

Binomial::Binomial(double S, double K, double Y, double R, double V, int steps, bool isCall)
    : spotPriceOfUnderlying(S), strikePrice(K), yearsToMaturity(Y), riskFreeRate(R), volatilityOfUnderlying(V), stepsForBinomial(steps), isCall(isCall) {}

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

//Method to calculate option price for calls and puts
double Binomial::priceOption() {

    //Calculate the time step size
    double stepSize = yearsToMaturity / stepsForBinomial;

    //Calculate the discount factor for each step
    double discount = exp(-riskFreeRate * stepSize);

    //Calculate the up and down factors based on volatility and time step size.
    double up = exp(volatilityOfUnderlying * sqrt(stepSize));
    double down = 1.0 / up;

    //Calculate the probability of the stock price moving up.
    double probabilityOfIncrease = (std::exp(riskFreeRate * stepSize) - down) / (up - down);

    //The "optionPrices" vector will contain the option prices at maturity
    double* optionPrices = new double[stepsForBinomial + 1];

    //Loop through each step
    for (int i = 0; i <= stepsForBinomial; ++i) {

        //Calculate the stock price at this node
        double stockPrice = spotPriceOfUnderlying * pow(up, stepsForBinomial - i) * pow(down, i);

        //Calculate the option payoff at this stock price
        optionPrices[i] = optionPayoff(stockPrice);
    }

    //Nested loops to perform backward induction to calculate the option price at every node
    for (int j = stepsForBinomial - 1; j >= 0; --j) {
        for (int i = 0; i <= j; ++i) {

            //Calculate the option price at this node (j,i)
            optionPrices[i] = discount * (probabilityOfIncrease * optionPrices[i] + (1.0 - probabilityOfIncrease) * optionPrices[i + 1]);
        }
    }

    //The "optionPrice" option price at the base node is the final calculation.
    double optionPrice = optionPrices[0];

    //Delete the optionPrices array to free memory
    delete[] optionPrices;

    //Return the final option price calculation
    return optionPrice;
}

