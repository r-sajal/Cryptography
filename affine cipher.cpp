#include<bits/stdc++.h> 
using namespace std; 

// a is chosen relatively prime which means a should not share any factors except 1 with m
// m we are going to use is 26 so -- a != 2,13,26,...
// m needs not to be 26 it is just the set of numbers you want to choose
int a = 3; 
int b = 5; 

 /* encryption - ( a x + b ) mod m 
 here x is plain_text[i] and m is 26 and added 'A' */
string encrypt(string plaintxt) 
{ 
    string cipher = "";  
    for (int i = 0; i < plaintxt.length(); i++) 
    { 
        // avoiding spaces  
        if(plaintxt[i]!=' ')  
            cipher +=  (char) ((((a * (plaintxt[i]-'A') ) + b) % 26) + 'A'); 
        else
            cipher += plaintxt[i];      
    } 
    return cipher; 
} 

/*decryption - a^-1 ( x - b ) mod m  
here x is cipher[i] and m is 26 */
string decrypt(string cipher) 
{ 
    string plaintxt = ""; 
    int ainv = 0; 
    int f = 0; 
    
    // a^-1
    // ax = 1 (mod m)
    // which means we are searching for gcd
    for (int i = 0; i < 26; i++) 
    { 
        f = (a * i) % 26;
        //Check if (a*i)%26 == 1, 
        // if f comes out to be 1 that means equation is satisfied and we have inverse
        if (f == 1) 
            ainv = i; 
    } 
    for (int i = 0; i < cipher.length(); i++) 
    { 
        if(cipher[i]!=' ')
            plaintxt += (char) (((ainv * ((cipher[i]+'A' - b)) % 26)) + 'A'); 
        else
            plaintxt += cipher[i];  
    } 
  
    return plaintxt; 
} 



int main() 
{ 
    string plaintxt = "HELLO WORLD"; 
    string cipher = "ARMMV TVEMO";

    // 1 - encrypt
    // 2 - decrypt
    // 0 - exit
    int x,f=0;
	while(1){
		cin >> x;
		switch(x){
			case 0: 
				f = 1;
				break;
			case 1:
				cipher = encrypt(plaintxt);
    			cout << "Encrypted Text : " << encrypt(plaintxt)<<endl;
				break;
			case 2:
				cout << cipher;
				cout << "Decrypted Text : " << decrypt(cipher);
				break;
			default: 
				f = 1;
				break;
		}
		// Getting out of loop
		if(f)break;
	}
    return 0; 
} 
