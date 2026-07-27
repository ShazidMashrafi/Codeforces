#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...)
#endif
#define  int  long long
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  Dpos(n) fixed << setprecision(n)
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int>v(n);
    for(auto &i : v) cin >> i;
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++) {
        while(j < n && v[j] - v[i] <= d) j++;
        int len = j - i - 1;
        if(len >= 2) {
            ans += len * (len - 1) / 2;
        }
    }
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