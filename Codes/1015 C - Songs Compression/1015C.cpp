#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  int  long long
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
ll power(ll x,ll y,ll m=1e9+7) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n, m, s = 0;
    cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        int d = a - b;
        v.push_back(d);
        s += a;   
    }
    if(s <= m)
    {
        cout << 0 << endl;
        return;
    }
    sort(all(v));
    reverse(all(v));
    // dbg(v);
    for(int i = 0; i < n; ++i)
    {
        s -= v[i];
        if(s <= m)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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