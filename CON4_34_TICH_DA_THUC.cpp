#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        int a[n + 1], b[m + 1], c[m + n + 1] = {};
        for (int i = n; i >= 1; i--)
            cin>>a[i];
        for (int i = m; i >= 1; i--)
            cin>>b[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                c[i + j] += a[i] * b[j];
            }
        }
        for (int i = m + n; i >= 2; i--)
            cout<<c[i]<<" ";
        cout<<endl;
    }
}
