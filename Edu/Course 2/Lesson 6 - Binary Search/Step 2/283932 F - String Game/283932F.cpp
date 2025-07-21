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
    string t, p;
    cin >> t >> p;
    int n = sz(t), m = sz(p);
    vector<int>a(n);
    for(int i = 0; i < n; ++i)    
    {
        cin >> a[i];
        --a[i];
    }
    auto can = [&](int k)
    {
        vector<bool> removed(n, false);
        for(int i = 0; i < k; ++i)
            removed[a[i]] = true;
        int j = 0;
        for(int i = 0; i < n && j < m; ++i)
        {
            if(!removed[i] && t[i] == p[j]) ++j;
        }
        return j == m;
    };

    int low = 0, high = n, ans = 0;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(can(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << endl;;
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