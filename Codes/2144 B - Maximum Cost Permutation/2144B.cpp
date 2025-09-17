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
    vector<int>a(n);
    map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        mp[x]++;
    }
    int val = n;
    for(int i = 0; i < n; ++i) {
        if(a[i] == 0) {
            while(mp[val]) val--;
            a[i] = val;
            mp[val]++;
            val--;
        }
    }
    dbg(a);
    int l = -1, r = -1;
    for(int i = 0; i < n; ++i) {
        if(a[i] != i + 1) {
            if(l == -1) {
                l = i + 1;
            }
            r = i + 1;
        }
    }
    dbg(l, r);
    if(l == -1) {
        cout << 0 << endl;
    } else {
        cout << r - l + 1 << endl;
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