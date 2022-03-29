/*
 Atbash cipher
 Author: Abdelrahman Elsayed
 Id: 20210222
 Date: 17/3/2022
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string atbash();

int main()
{
    atbash();
}

string atbash()
{
    string input;
    int encryption,decryption;
    int slop = -1 , y_intersept = 155;
    cout << "welcome user,enter your text: \n";
    getline(cin,input);

    for (int i = 0 ; i < input.length() ; i++)
    {
        while(isdigit(input.at(i)))
        {
            cout << "dont write numbers!,write your text again:\n";
            getline(cin,input);
            break;
        }
    }

    for (int i = 0 ; i < input.length() ; i++)
    {
        input.at(i) = toupper(input.at(i));
    }

    for (int i = 0 ; i < input.length() ; i++)
    {

        // to avoid space in the calculation
        while (int (input.at(i)) == 32)
        {
            i+= 1;
            // equivilant to pass in python
        }

        if(int(input.at(i)) <= 77) // as ascii m is 77
        {
            encryption = (slop * int(input.at(i))) + y_intersept;
            input.at(i) = char(encryption);

            /* i got this equation from link that the was at the assignment it was e(x) = ax +c
             first i did not understand what does it mean then i thought to susbtitute in it as e(x) = ascii of the char that i want
             and x = the ascii of the char that in the input of user, for example: A must be Z , B must be Y, ascii A = 65, ascii z = 90, ascii B = 66, ascii Y = 89
             so lets say that 90 = a*65 + c -----> 1
             and              89 = a*66 + c -----> 2
             then by subtracting 2 from 1 we deduce that a = -1 then if we substitute c will = 155
             */
        }


        else if (int(input.at(i)) > 77 && int(input.at(i)) <= 90)
        {
            decryption = (slop * int(input.at(i))) + 155;
            input.at(i) = char (decryption);
        }  // as ascii n is 78

    }

    cout << "cipher text: \n" <<input;
    return (input);
}

