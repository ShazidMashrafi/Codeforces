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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for(auto &i : p)    cin >> i;

    vector<int>a, b;
    for(int i = 0; i < x; ++i) {
        a.pb(p[i]);
    }
    for(int i = x; i < y; ++i) {
        b.pb(p[i]);
    }
    for(int i = y; i < n; ++i) {
        a.pb(p[i]);
    }

    int mn = INT_MAX;
    if(!b.empty()) {
        auto it = min_element(all(b));
        rotate(b.begin(), it, b.end());
        mn = b[0];
    }

    int idx = -1;
    for(int i = 0; i < sz(a); ++i) {
        if(a[i] > mn) {
            idx = i;
            break;
        }
        cout << a[i] << " ";
    }
    for(auto x : b) {
        cout << x << " ";
    }
    if(idx != -1) {
        for(int i = idx; i < sz(a); ++i) {
            cout << a[i] << " ";
        }
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