//Header file
#include "MonteCarlo.h"

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

//Constructor taking in:
//1: The spot price of the underlying asset
//2: The strike price
//3: Risk-free rate
//4: The volatility of underlying asset
//5: Years to maturity
//6: Desired number of simulations

MonteCarlo::MonteCarlo(double S, double K, double R, double V, double Y, int s)
    : spotPriceOfUnderlying(S), strikePrice(K), riskFreeRate(R), volatilityOfUnderlying(V), yearsToMaturity(Y), simulations(s) {}

//The "generateRandomNormal" method generates and returns a random "shock value" from a normal distribution for simulating unexpected asset price flunctuations
double MonteCarlo::generateRandomNormal() {

    //Build random number generator object called "generator"
    static mt19937 generator(random_device{}());

    //The "distribution" object is a normal distribution
    static normal_distribution<double> distribution(0.0, 1.0);

    //Return a randomized number from the normal distribution
    return distribution(generator);
}

//The "simulatePrice" method simulates and returns a potential future price of the underlying asset
double MonteCarlo::simulatePrice() {
    
    //Expected part of asset price movement.
    double drift = (riskFreeRate - 0.5 * volatilityOfUnderlying * volatilityOfUnderlying) * yearsToMaturity;

    //Random part of asset price movement.
    double diffusion = volatilityOfUnderlying * sqrt(yearsToMaturity) * generateRandomNormal();

    //Return the simulated price using Monte Carlo method
    return spotPriceOfUnderlying * exp(drift + diffusion);
}

//The "priceOption" method returns the Monte Carlo option price
double MonteCarlo::priceOption() {
    
    //Sum of all simulated payoffs starts at 0
    double payoffSum = 0.0;

    //Loop through each simulation
    for (int i = 0; i < simulations; ++i) {

        //Simulate the future price for this iteration
        double simulatedPrice = simulatePrice();

        //Calculate the payoff
        double payoff = max(simulatedPrice - strikePrice, 0.0);

        //Add the payoff to the payoff sum
        payoffSum += payoff;
    }

    //The discount factor at the risk-free rate
    double discountFactor = exp(-riskFreeRate * yearsToMaturity);

    //Return average payoff times discount
    return discountFactor * (payoffSum / simulations);
}