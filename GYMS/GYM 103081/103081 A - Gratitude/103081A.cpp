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


map<string, int> mp;
map<string, int> mp2;
vector<string>v;

bool cmp(string& a, string& b) {
    // dbg(a, mp[a], b, mp[b]);
    if(mp[a] == mp[b]) {
        return mp2[a] > mp2[b];
    }
    return mp[a] > mp[b];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cin.ignore();
    for(int i = 0; i < 3 * n; ++i) {
    	string s;
        getline(cin, s);
        // dbg(s);
    	mp[s]++;
        // dbg(mp[s]);
        mp2[s] = i;
        // dbg(mp2[s]);
    }

    for(auto [x, ct] : mp) {
        v.pb(x);
    }

    // dbg(v);
    sort(all(v), cmp);
    // dbg(v);

    for(auto x : v) {
        if(k == 0) {
            break;
        }
        cout << x << endl;
        k--;
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