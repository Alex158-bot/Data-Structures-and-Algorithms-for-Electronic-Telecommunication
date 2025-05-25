#include<bits/stdc++.h>

using namespace std;

int timso(int N,long long K){
	while(true){
		long long mid =(1LL <<(N-1));
		if(K==mid) return N;
		if(K<mid) N--;
		else{
			K-=mid;
			N--;
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		long long K;
		cin>>K;
		cout<<timso(N,K)<<endl;
	}
	return 0;
}
