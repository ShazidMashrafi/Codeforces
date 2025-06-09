#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll power(ll x,ll y,ll m=1e9+7){ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int l, r;
    cin >> l >> r;
    int ct = 0;
    while (l || r)
    {
        ct += r - l;
        l /= 10;
        r /= 10;
    }
    cout << ct << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}