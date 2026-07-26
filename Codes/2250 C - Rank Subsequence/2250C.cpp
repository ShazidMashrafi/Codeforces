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

struct e {
    int l, r, u, v;
};

void solve()
{
    int n;
    cin >> n;
    vector<e> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r >> v[i].u >> v[i].v;
    }
    
    auto check = [&](int m) -> bool {
        int idx = -1;
        for (int j = 1; j <= m; j++) {
            bool found = false;
            for (int i = idx + 1; i < n; i++) {
                bool left = (j < v[i].l || j > v[i].r);
                int rank = m - j + 1;
                bool right = (rank < v[i].u || rank > v[i].v);
                if (left && right) {
                    idx = i;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    };
    
    for (int m = n; m >= 0; m--) {
        if (check(m)) {
            cout << m << endl;
            return;
        }
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