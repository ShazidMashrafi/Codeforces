#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n;
    cin >> n;
    vector<ll> x(n), t(n);
    for(auto &i : x)    cin >> i;
    for(auto &i : t)    cin >> i;
    double low = 0, high = 1e18, ans = 1e18;
    int itr = 100;
    while(itr--)
    {
        double mid = (low + high) / 2.0;
        double l = -1e20, r = 1e20;
        for(int i = 0; i < n; ++i)
        {
            double d = max(0.0, mid - t[i]);
            l = max(l, x[i] - d);
            r = min(r, x[i] + d);
        }
        if(l <= r)
        {
            ans = mid;
            high = mid;
        }
        else
            low = mid;
    }
    
    double p = 1e20;
    for(int i = 0; i < n; ++i)
    {
        double d = max(0.0, ans - t[i]);
        p = min(p, x[i] + d);
    }
    cout << Dpos(10) << p << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}