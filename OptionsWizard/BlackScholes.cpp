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
    return 0;
}

double BlackScholes::getPutPrice() const {
    return 0;
}

double BlackScholes::getNormalDistribution() const {
    return 0;
}