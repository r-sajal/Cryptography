#include <bits/stdc++.h>
using namespace std;

string cipher(string s, string key){
	string ans = "";
	int j=0;
	for(int i = 0 ; i < s.size() ; i++){
		if(i<key.size()){
			char tmp = ((s[i]+key[i])%26);
			tmp+='A';
			ans+=tmp;
		}
		else{
			char tmp = ((s[i]+s[j])%26);
			tmp+='A';
			ans+=tmp;
			j+=1;
		}		
	}
	return ans;
}

string decipher(string s , string key){
	string ans="";
	int j=0;
	for(int i = 0 ; i < s.size() ; i++){
		if(i<key.size()){
			char tmp = ((s[i]-key[i]+26)%26);
			tmp+='A';
			ans+=tmp;
		}
		else{
			char tmp = ((s[i]-ans[j]+26)%26);
			tmp+='A';
			ans+=tmp;
			j+=1;
		}		
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << "Input String and Key: \n";
	string s,key;
	cin >> s >> key;

	string ciphertxt = cipher(s,key);
	cout << (ciphertxt) << endl;
	
	string dectxt = decipher(ciphertxt,key);
	cout << dectxt;
	return 0;
}

