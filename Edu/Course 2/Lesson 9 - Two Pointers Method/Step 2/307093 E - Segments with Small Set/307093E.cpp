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

int n, k;
map<int, int> cnt;
int ct;

void add(int x) {
    cnt[x]++;
    if(cnt[x] == 1) ct++;
}

void remove(int x) {
    cnt[x]--;
    if(cnt[x] == 0) ct--;
}

bool good() {
    return ct <= k;
}

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a)    cin >> i;

    ll l = 0, x = 0, res = 0;
    for(ll r = 0; r < n; r++) {
        add(a[r]);
        while(!good()) {
            remove(a[l]);
            l++;
        }
        res += r - l + 1;
    }
    cout << res << endl;
}

signed main() {
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