#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define dbg(...)
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
    string s;
    cin >> s;
    int n = sz(s);

    // pref[k] = # (: in s[0 .. k-1]
    vector<int> pref(n + 1, 0);
    for (int k = 2; k <= n; ++k) {
        pref[k] = pref[k - 1] + (s[k - 2] == '(' && s[k - 1] == ':');
    }

    // suff[k] = # :) in s[k .. n-1]
    vector<int> suff(n + 2, 0);
    for (int k = n - 2; k >= 0; --k) {
        suff[k] = suff[k + 1] + (s[k] == ':' && s[k + 1] == ')');
    }

    int mx = 0;
    for (int k = 1; k <= n; ++k) {
        int ct = pref[k] + suff[k];
        if (k < n && s[0] == ':' && s[k] == ')')    ct++;
        mx = max(mx, ct);
    }

    cout << mx << endl;
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