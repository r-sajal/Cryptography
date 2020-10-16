#include <bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y, int p) 
{ 
    int res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
bool check(int n){
	int r,x=n-1;
	
	while(x%2==0){
		x/=2;
		r+=1;
	}
	for(int s=0;s<5;s++){
		int a = 2 + rand() % (n - 4); 
	  
	    // Compute a^d % n 
	    int xx = power(a, x, n); 
	  
	    if (xx == 1  || xx == n-1) 
	       return true; 
	  
	    // Keep squaring x while one of the following doesn't 
	    // happen 
	    // (i)   d does not reach n-1 
	    // (ii)  (x^2) % n is not 1 
	    // (iii) (x^2) % n is not n-1 
	    while (x != n-1) 
	    { 
	        xx = (xx * xx) % n; 
	        x *= 2; 
	  
	        if (xx == 1) return false; 
	        if (xx == n-1) continue; 
	    } 
	  
	    return false; 
		}
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	if(n==1)cout << " Not prime " << endl;
	else if(n<=3) cout << "prime" << endl;
	else if(n%2==0) cout << "Not Prime" << endl;
	else{
		if(check(n)){
			cout << "Prime Probably" << endl;
		}
		else{
			cout << "Not Prime"  << endl;
		}
	}


	return 0;
}

