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

int n, k;
vector<int>a;

bool good(double x)
{
    int ct = 0;
    for(int i = 0; i < n; ++i)
        ct += floor(a[i] / x);
    return ct >= k;
}

void solve()
{
    cin >> n >> k;
    a.resize(n);
    for(auto &i : a)    cin >> i;
    double l = 0;    // l is good
    double r = 1e8; // r is bad
    for(int t = 0; t < 100; ++t)
    {
        double m = (l + r) / 2;
        if(good(m))
            l = m;
        else
            r = m;
    }
    cout << setprecision(20) << l << "\n";
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