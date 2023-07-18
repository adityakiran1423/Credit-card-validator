//use git to upload to GitHub

#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include "accept.h"

using std::string;

string trim(string &cardnum);
bool card_regex(string &cardnum);
bool validate(string &cardnum);

int main()  
{
    char choice;
    int status=0;
    string cardnum=accept();
    here:
    trim(cardnum);
    bool check=card_regex(cardnum);
    if(check)
    {
        std::cout<<"The entered card number format is correct"<<std::endl;
        std::cout<<"Checking whether the entered card number is a valid card number or not\n"<<std::endl;
        bool valid=validate(cardnum);
        if(valid)
        {
            //check if the given number agrees with luhn's algorithm or not
            std::cout<<"The entered card number is valid"<<std::endl;
            std::cout<<"Please enter 'y' if you want to validate another card number"<<std::endl;
            std::cout<<"Press 'q' to quit"<<std::endl;
            std::cin>>choice;
            if(choice=='y'||choice=='Y')
            {
                string cardnum=accept();
                goto here;
            }
            else
                return 0;
        }
        else
        {
            std::cout<<"Entered card number is invalid"<<std::endl;
            std::cout<<"Please enter 'y' if you want to validate another card number"<<std::endl;
            std::cout<<"Press 'q' to quit\n";
            std::cin>>choice;
            if(choice=='y'||choice=='Y')
            {
                std::string cardnum=accept();
                goto here;
            }
            else
                return 0;
        }
    }
    else
        std::cout<<"The entered card number format is invalid\n";
    return 0;
}

string trim(string &cardnum)
{
    int length=cardnum.length();
    remove(cardnum.begin(), cardnum.end(), ' ');
    return cardnum;
}

bool card_regex(string &cardnum)
{
    const std::regex pattern("^[0-9]{4}-[0-9]{4}-[0-9]{4}$");
    return std::regex_match(cardnum,pattern);
}

bool validate(string &cardnum)
{
    int doubledigit=0;
    int validsum=0;
    int cardnumber[12];
    for(int i=0;i<13;i++)
    {
        if(i==4 || i==9)
            continue;
        else
            cardnumber[i]=(int)cardnum[i];
    }
    //int cardnumber array is now created
   for(int i=0;i<11;i++)
   {
        if(i%2==0)
        cardnumber[i]*=2; //digits have been doubled
        else
        continue;
   }
   for(int i=0;i<11;i++)
   {
        if(i%2==0 && cardnum[i]>=10)
        {   
            //checking if after doubling number is more (>1), add the digits, and add all digits
            doubledigit=1+cardnumber[i]%10;
            cardnumber[i]=doubledigit;
        }
        else
            continue;
   }
   for(int i=0;i<11;i++)
   {
        validsum=validsum+cardnumber[i]; //adding all the new digits
   }
   if(validsum%10==0) //if number is divisible by 10, then the number is a valid card number
        return true;
    else
        return false;
}