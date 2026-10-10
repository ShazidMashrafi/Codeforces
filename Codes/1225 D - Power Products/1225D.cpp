#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
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
ll binpow(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

const int N = 1e7 + 10;
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

vector<pair<int,int>> get_factors(int x) {
    vector<pair<int,int>> factors;
    while (x > 1) {
        int p = spf[x];
        int ct = 0;
        while(x % p == 0) {
            ct++;
            x /= p;
        }
        factors.pb({p, ct});
    }
    return factors;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    map<vector<pair<int,int>>, int> freq;
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        vector<pair<int,int>> factors = get_factors(a);
        dbg(factors);
        vector<pair<int,int>> sig, comp;
        for(auto [p, ct] : factors) {
            int r = ct % k;
            if(r > 0) {
                sig.pb({p, r});
                comp.pb({p, k - r});
            }
        }
        ans += freq[comp];
        freq[sig]++;
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
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}