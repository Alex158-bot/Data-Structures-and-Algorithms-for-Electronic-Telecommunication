#include<bits/stdc++.h>

using namespace std;

void changemoney(){
	int N;
	cin>>N;
	vector <int> cash = {1000,500,200,100,50,20,10,5,2,1};
	int count = 0;
	for(int i = 0;i<cash.size();i++){
		int c = cash[i];
		count += N/c;
		N%=c;
	}
	cout<<count<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		changemoney();
	}
	return 0;
}
