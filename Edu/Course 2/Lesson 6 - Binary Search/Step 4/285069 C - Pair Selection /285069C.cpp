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

bool canAchieveRatio(vector<pair<int, int>>& pairs, int k, double x) 
{
    vector<double> values;
    
    for (auto& p : pairs)
        values.push_back(p.first - x * p.second);
    
    sort(all(values), greater<double>());
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += values[i];
    }
    return sum >= 0;
}

void solve() 
{
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) 
        cin >> pairs[i].first >> pairs[i].second;
    
    double left = 0;
    double right = 1e6;
    
    int itr = 100;
    while(itr--)
    {
        double mid = (left + right) / 2.0;
        if (canAchieveRatio(pairs, k, mid)) 
            left = mid; 
        else 
            right = mid;
    }
    cout << Dpos(10) << left << endl;
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