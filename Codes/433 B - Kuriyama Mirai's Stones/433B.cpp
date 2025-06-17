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
    vector<ll>v(n), pre(n + 1, 0), pre2(n + 1, 0);
    for(auto &i : v)    cin >> i;
    for(ll i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + v[i - 1];
    sort(all(v));
    for(ll i = 1; i <= n; ++i)
        pre2[i] = pre2[i - 1] + v[i - 1];
    ll m;
    cin >> m;
    while(m--)
    {
        ll type, l, r;
        cin >> type >> l >> r;
        if(type == 1)
            cout << pre[r] - pre[l - 1] << endl; 
        else
            cout << pre2[r] - pre2[l - 1] << endl; 
    }
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}