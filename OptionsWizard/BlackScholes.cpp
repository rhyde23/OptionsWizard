#include "BlackScholes.h"
#include <iostream>

using namespace std;

BlackScholes::BlackScholes() {
    cout << "Enter spot price: ";
    cin >> spotPrice;

    cout << "Enter strike price: ";
    cin >> strikePrice;

    cout << "Enter interest rate: ";
    cin >> interestRate;

    cout << "Enter years to maturity: ";
    cin >> yearsToMaturity;

    cout << "Enter volatility: ";
    cin >> volatility;
}

void BlackScholes::displayInputs() const {
    cout << "Spot Price: " << spotPrice << endl;
    cout << "Strike Price: " << strikePrice << endl;
    cout << "Interest Rate: " << interestRate << endl;
    cout << "Years to Maturity: " << yearsToMaturity << endl;
    cout << "Volatility: " << volatility << endl;
}