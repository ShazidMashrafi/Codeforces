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
    ll n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    
    bool f = true;
    for (int k = 1; k <= n; k++) {
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] >= k) {
                if (l == -1) l = i;
                r = i;
            }
        }
        
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= k) ct++;
        }
        
        if (r - l + 1 != ct) {
            f = false;
            break;
        }
    }
    
    yn(f);
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