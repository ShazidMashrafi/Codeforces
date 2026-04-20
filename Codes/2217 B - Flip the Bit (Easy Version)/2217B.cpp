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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int p;
    cin >> p;
    int x = a[p - 1];

    vector<int>b(n + 2);
    b[0] = 1;
   	b[n + 1] = 1;

   	for(int i = 1; i <= n; ++i) {
   		b[i] = (a[i - 1] == x) ? 1 : 0;
   	}

   	int ct1 = 0;
   	for(int i = 0; i < p; ++i) {
   		if(b[i] != b[i + 1]) ct1++;
   	}

   	int ct2 = 0;
   	for(int i = p; i <= n; ++i) {
   		if(b[i] != b[i + 1]) ct2++;
   	}

   	cout << max(ct1, ct2) << endl;
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