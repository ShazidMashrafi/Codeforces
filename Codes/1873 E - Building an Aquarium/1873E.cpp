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

bool check(vector<int> &v, int n, int x, int h)
{
    int s = 0;
    for(int i = 0; i < n; ++i)
    {
        s+= max(h - v[i], 0ll);
    }
    return s <= x;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &&i : v)   cin >> i;
    int low = 0, high = 1e10;
    while (low < high) 
    {
		int mid = low + (high - low + 1) / 2;
		if (check(v, n, x, mid)) 
            low = mid;
		else 
            high = mid - 1;
	}
    cout << low << endl;
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