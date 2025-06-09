#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll power(ll x,ll y,ll m=1e9+7){ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin >> v[i];
    }
    int ct = 0;
    for(int i = 1; i < n - 1; ++i)
    {
    	if(v[i] < v[i - 1] && v[i] < v[i + 1]) ct++;
    	if(v[i] > v[i - 1] && v[i] > v[i + 1]) ct++;
    }
    cout << ct << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}