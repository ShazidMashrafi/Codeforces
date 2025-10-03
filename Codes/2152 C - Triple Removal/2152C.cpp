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

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<int> pre0(n+1, 0), pre1(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        pre0[i] = pre0[i-1] + (a[i] == 0);
        pre1[i] = pre1[i-1] + (a[i] == 1);
    }

    vector<int> pre(n + 1, 0);
    for(int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + (a[i] == a[i - 1]);
    }
    pre[n] = pre[n - 1];
    
    while (q--) {
        ll l, r;
        cin >> l >> r;
        
        ll ct0 = pre0[r] - pre0[l - 1];
        ll ct1 = pre1[r] - pre1[l - 1];
        if (ct0 % 3 != 0 || ct1 % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        
        ll ans = (r - l + 1) / 3;
        ll f = pre[r] - pre[l];
        // dbg(l, r, ans, f);
        if(f == 0) ans++;
        cout << ans << endl;
    }
}

signed main() {
    FAST;
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC) {
        solve();
    }
}