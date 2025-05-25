#include<bits/stdc++.h>

using namespace std;

string timsomin(int S, int D){
	if(S>9*D) return "-1";
	vector<int> digits(D,0);
	S--;
	for(int i = D-1;i>0;i--){
		if(S>9){
			digits[i]=9;
			S-=9;	
		}
		else{
			digits[i] = S;
			S = 0;
		}
	}
	digits[0] = S+1;
	string r = "";
	for(int i = 0;i<digits.size();i++){
		r  += (char)(digits[i]+'0');
	}
	return r;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int S,D;
		cin>>S>>D;
		cout<<timsomin(S,D)<<endl;
		
	}
	return 0;
}
