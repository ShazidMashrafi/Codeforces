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
    int n;
    cin >> n;
    n = 1 << n;
    vector<int>ans;
    vector<bool> used(n, false);
    int m = n - 1;
    while(sz(ans) < n) {
        bool f = false;
        for(int i = 0; i < n; ++i) {
            if(!used[i] && (i & m) == m) {
                ans.pb(i);
                used[i] = true;
                f = true;
            }
        }
        
        if(f) continue;
        int best = -1, best_ct = -1;
        for(int i = 0; i < n; ++i) {
            if(used[i])     continue;
            int ct = __builtin_popcount(i & m);
            if(ct > best_ct || (best_ct == ct && i < best)) {
                best_ct = ct;
                best = i;
            }
        }
        ans.pb(best);
        used[best] = true;
        m &= best;
    }

    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
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