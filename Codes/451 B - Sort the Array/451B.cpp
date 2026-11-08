#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include <debug.h>
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

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i : v)    cin >> i;
    
    int l = -1, r = -1;
    for(int i = 0; i < n - 1; ++i) {
        if(v[i] > v[i + 1]) {
            if(l == -1) l = i;
            r = i + 1;
        }
    }

    if(l == -1) {
        cout << "yes\n1 1\n";
        return;
    }

    reverse(v.begin()+l, v.begin() + r + 1);
    
    if(is_sorted(all(v))) {
        cout << "yes" << endl << l + 1 << " " << r + 1 << endl;
    } else {
        cout << "no" << endl;
    }
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