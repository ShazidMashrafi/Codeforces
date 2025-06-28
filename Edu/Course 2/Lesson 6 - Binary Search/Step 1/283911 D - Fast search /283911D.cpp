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
    vector<int>v(n);
    for(auto &i : v)   cin >> i;
    sort(all(v));
    int k;
    cin >> k;
    while(k--)
    {
        int l, r;
        cin >> l >> r;
        int L = -1;  // v[L] < l;
        int R = n;   // v[R] => l;
        while(R > L + 1)
        {
            int m = (L + R) / 2;
            if(v[m] < l)
                L = m;
            else
                R = m;
        }
        int i = R;
        
        L = -1; // v[L] <= r
        R = n; // v[R] > r
        while(R > L + 1)
        {
            int m = (L + R) / 2;
            if(v[m] <= r)
                L = m;
            else
                R = m;
        }
        int j = L;
        cout << j - i + 1 << " ";
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