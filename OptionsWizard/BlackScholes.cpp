//Include header file
#include "BlackScholes.h"
#include <iostream>

using namespace std;

//Constructor - cin user inputs
BlackScholes::BlackScholes() {

    cout << "Enter spot price: ";
    cin >> spotPriceOfUnderlying;

    cout << "Enter strike price: ";
    cin >> strikePrice;

    cout << "Enter interest rate: ";
    cin >> interestRate;

    cout << "Enter years to maturity: ";
    cin >> yearsToMaturity;

    cout << "Enter volatility of underlying asset: ";
    cin >> volatilityOfUnderlying;
}

double BlackScholes::getCallPrice() const {

}

double BlackScholes::getPutPrice() const {

}

double BlackScholes::getNormalDistribution() const {

}