#include<bit/stdc++.h>

using namespace std;
#define MAX 1001;

int main(){
	int t;
	cin>>t;
	//khai bao bien
	int n;
	int a[MAX];
	//nhap du lieu
	cin>>n;
	for(int i = 1;i<=n;i++){
		//QHD
		int l[MAX];
		//1.KHOI TAO
		memset(l,1,sizeof(l));
		//2.TINH BANG PHUONG
		for(int i= 2;i<=n;i++){
			for(int j = 1;j<i;j++)
				if((l[i]<l[j]+1)&&(a[j]<a[i]))
					l[i]=l[j]+1;
					//in ketqua
					for(int j = 1;j<=n;j++)
					cout<<l[j]<<" ";
					cout<<endl;
		}
		//in ket qua
		int max = l[1];
		for(int  i = 2;i<=n;i++)
		maxi = l[i];
	}
}
