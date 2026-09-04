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
    unordered_map<char, int> mp;
    int mn = INT_MAX;

    for (int i = 0; i < sz(s); ++i) {
        mp[s[i]] = i;
        if (mp.count('1') && mp.count('2') && mp.count('3')) {
            int curr = i - min({mp['1'], mp['2'], mp['3']}) + 1;
            mn = min(mn, curr);
        }
    }B - Ternary String 	

    if(mn == INT_MAX) {
        cout << 0 << endl;
    } else {
        cout << mn << endl;
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