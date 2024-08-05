#pragma once
#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H
class BlackScholes {
private:
    double spotPrice;
    double strikePrice;
    double interestRate;
    double yearsToMaturity;
    double volatility;
public:
    BlackScholes();
    void displayInputs() const;
};

#endif // BLACKSCHOLES_H