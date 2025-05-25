#include<bits/stdc++.h>

using namespace std;

int maxspace(vector<int>&A,int N, int K){
	sort(A.begin(),A.end());
	int total = 0;
	for(int i = 0;i<N;i++){
		total +=A[i];	
	}
	int sumsmall = 0;
	if(K<N-K){
		for(int i = 0;i<K;i++){
			sumsmall+=A[i];
		}
	}
		else{
		for(int i = 0;i<N-K;i++){
			sumsmall+=A[i];
		}
	}
	return abs(total-2*sumsmall);
	
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int N, K;
		cin>>N>>K;
		vector<int>A(N);
		for(int i = 0;i<N;i++){
			cin>>A[i];
		}
		cout<<maxspace(A,N,K)<<endl;
	}
	return 0;
}
