#pragma once
#include <iostream>
using std::string;

string accept()
{
    int choice;
    string cardnum;
    acceptagain : 
    std::cout<<"Enter the credit card number"<<std::endl;
    std::cout<<"Please enter the card number in the following format : ****-****-****"<<std::endl;
    std::cin>>cardnum;
    std::cout<<"Checking for validity of Credit Card Number"<<std::endl;
    return cardnum;
}