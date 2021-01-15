#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef bitset<8> byte;
int block_size = 3;
string key;

string padd(int diff){
	string r = "";
	while(diff--){
		r+='z';
	}
	return r;
}

string key_expansion(string r, int diff){
	string p = r;
	while(p.size()<diff+p.size()){
		r+=p;
		diff-=p.size();
	}
	for(int i = 0 ; i < diff; i++){
		r+=p[i];
	}
	return r;
}

byte encrypt(byte tr){
	
	return tr;	
}

byte decrypt(byte tr){
	
	return tr;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<byte > plaintext,bit_key,decrypttext;
	
	string s,key,x,encrypted;
	cin >> s >> key;
	
	int no_of_blocks = ceil((double)s.size()/block_size);
	
	if(no_of_blocks*block_size!=(s).size()){
		int diff = no_of_blocks*block_size-(s).size();
		x = padd(diff);
	}
	s+=x;
	if(key.size()!=no_of_blocks){
		int diff = no_of_blocks*block_size-(key).size();
		string key_ex = key_expansion(key,diff);
	}
	
	
	for(int i = 0 ; i < no_of_blocks ; i++){
		plaintext.push_back(int(s[i]));
		cout << plaintext[i].to_ulong() <<" ";
	}
	cout << endl;
	for(int i = 0 ; i < no_of_blocks ; i++){
		bit_key.push_back(int(key[i]));
	}
	
	
	int special_key = 4;
	byte temp = special_key;
	string cipher;
	for(int i = 0 ; i < no_of_blocks; i++){	
		auto blck = (plaintext[i]^temp);
		temp = encrypt(blck);
		cout << temp.to_ulong() << " ";
		cipher+=(char)temp.to_ulong();
		
		decrypttext.push_back(temp);
	}
	cout << endl;
//	for(int i = 0 ; i < cipher.size();i++){
//		cout << int(cipher[i]) << " ";
//	}
	temp = special_key;
	for(int i = 0;i<no_of_blocks;i++){
		auto blck = decrypt(decrypttext[i]);
		cout << (temp^blck).to_ulong() << " ";
		temp = decrypttext[i];
	}
	
	return 0;
}

