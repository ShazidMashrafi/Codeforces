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

const ll INF = 1e18;

const int N = 2e5 + 10;
int spf[N];
vector<int> primes;

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p >= N) break;
            spf[i * p] = p;
        }
    }
}

vector<int> get_factors(int x) {
    vector<int> factors;
    while (x > 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    int mx = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int>cost(mx + 1, 0);
    for(int i = k + 1; i <= mx; ++i) {
        ll best = INF;
        for(int p : get_factors(i)) {
            best = min(best, 1LL * p * cost[i / p]);
        }
        cost[i] = 1 + best;
    }

    ll ans = 0;
    for(int x : a) {
        ans += cost[x];
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    sieve();

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}