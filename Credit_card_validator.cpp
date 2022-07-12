#include <bits/stdc++.h>
#include <iostream>


using namespace std;

bool containAlpha(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string ccn;
    
    cout << "The credit card number is validated by using the Luhn Algorithm" << endl;
    cout << "You can enter 'exit' anytime to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a credit card number to validate: ";
        cin >> ccn;
         int len = ccn.length();
        
        if (ccn == "exit")
            break;
        
        else if (!containAlpha(ccn)) {
            cout << "Credit card number should not contain alphabet! "<<endl;
            continue;
        }
       
        else if (len < 13)
	    {
		cout << "Credit card number is too short!" << endl;
		continue;
	    }
            
       
        int evenSum = 0;   
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((ccn[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            evenSum += dbl;
        }
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            evenSum += (ccn[i] - 48);
        }
        
        cout << (evenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;
    if(evenSum % 10 == 0)  
    {
        if ((ccn[0]-48) == 4)
	   {
		cout << "type: Visa Card" << endl;
	   }
	   if (((ccn[0]-48) == 3) && ((ccn[1]-48) == 7))
	   {
		cout << "type: American Express" << endl;
    	}
    	if ((ccn[0]-48) == 5)
	    {
		cout << "type: Master Card" << endl;
	    }
	    if ((ccn[0]-48) == 6)
	    {
		cout << "type: Discover Card" << endl;
	    }
    }
        
        continue;        
    }

    return 0;
}
