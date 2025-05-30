#include <bits/stdc++.h>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long P[1001][1001] = {}, mod = 1e9 + 7;
	for (int i = 1; i <= 1000; i++)
		P[i][1] = i;
	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= i; j++)
			P[i][j] = (P[i - 1][j - 1] * i) % mod;
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << P[n][k] << endl;
	}
}
