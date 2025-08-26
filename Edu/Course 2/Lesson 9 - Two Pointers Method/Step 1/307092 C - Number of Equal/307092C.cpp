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
    int n, m;
    cin >> n >> m;
    vector<int>a(n), b(m), c(n + m);
    for(auto &i : a)    cin >> i;
    for(auto &i : b)    cin >> i;
    
    int i = 0, j = 0;
    ll ans = 0;
    while(i < n || j < m) {
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else {
            int ct1 = 1;
            while(i + ct1 < n && a[i + ct1] == a[i]) ct1++;
            int ctb = 1;
            while(j + ctb < m && b[j + ctb] == b[j]) ctb++;
            ans += 1LL * ct1 * ctb;
            i += ct1;
            j += ctb;
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