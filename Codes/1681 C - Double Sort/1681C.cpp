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
    ll n;
    cin >> n;
    vector<int>a(n), b(n);
    for(auto &e : a)   cin >> e;
    for(auto &e : b)   cin >> e;
    vector<pair<pair<int, int>, int>> v(n);
    for(int i = 0; i < n; ++i)  
        v[i] = {{a[i], b[i]}, i};

    sort(all(v), [&](auto p, auto q) {
        if(p.ff.ff == q.ff.ff)
            return p.ff.ss < q.ff.ss;
        return p.ff.ff < q.ff.ff;
    });

    for(int i = 1; i < n; i++) {
        if(v[i].ff.ss < v[i-1].ff.ss) {
            cout << -1 << endl;
            return;
        }
    }

    vector<pair<int, int>> swaps;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1] || (a[j] == a[j+1] && b[j] > b[j+1])) {
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
                swaps.pb({j+1, j+2});
            }
        }
    }
    // dbg(a, b);
    cout << sz(swaps) << endl;
    for(auto &p : swaps) {
        cout << p.ff << " " << p.ss << endl;
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