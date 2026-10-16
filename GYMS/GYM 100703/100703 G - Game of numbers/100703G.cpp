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
ll binpow(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 1);
    for(int i = 1; i <= n; ++i)  cin >> v[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, false));
    dp[0][0] = true;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            if(dp[i - 1][j]) {
                if(j + v[i] <= k)   dp[i][j + v[i]] = true;
                if(j - v[i] >= 0)   dp[i][j - v[i]] = true;
            }
        }
    }

    int d = 0, curr = 0;
    for(int i = 1; i <= n; ++i) {
        bool ok = false;
        for(int j = 0; j <= k; ++j) {
            if(dp[i][j]) {
                ok = true;
                curr = j;
                break;
            }
        }
        if(!ok)   break;
        d = i;
    }

    string ans;
    for(int i = d; i >= 1; --i) {
        if(curr - v[i] >= 0 && dp[i - 1][curr - v[i]]) {
            ans.pb('+');
            curr -= v[i];
        } else {
            ans.pb('-');
            curr += v[i];
        }
    }
    
    reverse(all(ans));
    cout << d << endl;
    cout << ans << endl;
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