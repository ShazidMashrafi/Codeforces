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

pair<int, int> check(vector<int>&v, int d, double x)
{
    int n = sz(v);
    vector<double> pre(n + 1, 0);
    
    for(int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + v[i] - x;

    vector<double> mn(n + 1);
    vector<int> pos(n + 1);
    
    mn[0] = pre[0];
    pos[0] = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (pre[i] < mn[i-1]) 
        {
            mn[i] = pre[i];
            pos[i] = i;
        } 
        else 
        {
            mn[i] = mn[i-1];
            pos[i] = pos[i-1];
        }
    }
        
    for(int r = d; r <= n; ++r)
    {
        if(mn[r - d] <= pre[r])
            return {pos[r - d] + 1, r};
    }
    return {-1, -1};
}

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(auto &i : v)    cin >> i;
    
    double low = *min_element(all(v));
    double high = *max_element(all(v));
    pair<int, int> ans = {1, d};
    int itr = 100;
    while(itr--)
    {
        double mid = (low + high) / 2.0;
        
        int l = -1, r = -1;
        pair<int, int> seg = check(v, d, mid);
        if(seg.ff != -1)
        {
            low = mid;
            ans = seg;
        }
        else
            high = mid;
    }
    cout << ans.ff << " " << ans.ss << endl;
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