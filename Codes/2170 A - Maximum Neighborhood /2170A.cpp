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
    ll mx = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            ll a, b, c, d;
            a = b = c = d = 0; 
            ll x = n * (i - 1) + j;
            if(i - 1 > 0)   a = n * (i - 2) + j;
            if(i + 1 <= n)  b = n * i + j;
            if(j - 1 > 0)   c = n * (i - 1) + j - 1;
            if(j + 1 <= n)  d = n * (i - 1) + j + 1;
            ll val = x + a + b + c + d;
            // dbg(x, a, b, c, d);
            // dbg(val, mx);
            mx = max(val, mx);
        }
    }
    cout << mx << endl; 
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