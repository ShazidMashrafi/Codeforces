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
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<ll> p(n);
    for(auto &i : p)    cin >> i;
    
    ll tot = accumulate(all(p), 0ll);

    ll a = 0, b = 0;
    bool f0 = false, f1 = false;
    for(int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            a += p[i] / 2 + 1;
            f0 = true;
        } else {
            b += p[i] / 2 + 1;
            f1 = true;
        }
    }

    if(x + y < tot || x < a || y < b) { 
        yn(0); 
        return; 
    }
    
    if(f0 && f1) {
        yn(1);
    } else if(f0) {
        yn(x >= y + n);
    } else {
        yn(y >= x + n);
    }
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