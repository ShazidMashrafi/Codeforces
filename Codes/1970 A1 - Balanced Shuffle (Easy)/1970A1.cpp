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

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if(a.ff == b.ff)    return a.ss > b.ss;
    return a.ff < b.ff;
}

void solve()
{
    string s;
    cin >> s;
    ll ct = 0;
    vector<pair <ll, ll> > v;
    for(ll i = 0; i < sz(s); ++i)
    {
        v.push_back({ct, i});
        if(s[i] == '(') ct++;
        else ct --;
        // dbg(i, s[i], ct);
    }
    sort(all(v), cmp);
    // dbg(v);
    for(auto [ct, i] : v)
        cout << s[i];
    cout << endl;
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