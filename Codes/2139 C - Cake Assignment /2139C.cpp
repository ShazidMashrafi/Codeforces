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
    ll k, x;
    cin >> k >> x;
    ll s = 1ll << k;
    ll total = s * 2;
    // dbg(s, total);
    
    if(x == s) {
        cout << 0 << endl;
        return;
    }
    
    vector<ll> ans;
    
    ll c = x;
    ll v = total - x;
    while(c != s) {
        if(c < v) {
            ans.pb(1);
            v = v - c;
            c *= 2;
        } else {
            ans.pb(2);
            c = c - v;
            v *= 2;
        }
    }
    
    reverse(all(ans));
    
    cout << sz(ans) << endl;
    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

signed main()
{
    FAST;
    
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        solve();
    }
}