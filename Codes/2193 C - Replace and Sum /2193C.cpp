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
    ll n, q;
    cin >> n >> q;
    vector<ll>a(n), b(n), c(n), p(n);
    for(auto &i : a)    cin >> i;
    for(auto &i : b)    cin >> i;
    for(ll i = 0; i < n; ++i) {
        c[i] = max(a[i], b[i]);
    }
    // dbg(a, b, c);
    for(ll i = n - 2; i >= 0; --i) {
        c[i] = max(c[i], c[i + 1]);
    }
    // dbg(c);
    p[0] = c[0];
    for(ll i = 1; i < n; ++i) {
        p[i] = p[i - 1] + c[i]; 
    }

    dbg(c, p);
    while(q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        dbg(l, r);
        if(l == 0) {
            cout << p[r] << " ";
        } else {
            cout << p[r] - p[l - 1] << " ";
        } 
    }
    cout << endl;
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