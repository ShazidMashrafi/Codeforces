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

const int N = 1e6 + 7;
vector<int> lp(N);

void sieve()
{
    for(int i = 0; i < N; ++i) {
        lp[i] = i;
    }

    for(int i = 2; i * i < N; ++i)
    {
        if(lp[i] == i) {
            for(int j = i * i; j < N; j += i) {
                if(lp[j] == j) {
                    lp[j] = i;
                }
            }
        }
    }
}

vector<int> fun(int x) {
    if(x == 1) return {1};
    vector<int> res;
    while(x > 1 && lp[x] != x) {
        res.pb(lp[x]);
        x /= lp[x];
    }
    if(x > 1) res.pb(x);
    reverse(all(res));
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)    cin >> i;
    
    bool sorted = true;
    for(int i = 1; i < n; ++i) {
        if(a[i] < a[i - 1]) {
            sorted = false;
            break;
        }
    }

    if(sorted) {
        cout << "Bob" << endl;
        return;
    }

    vector<int> v;
    for(int x : a) {
        vector<int> temp = fun(x);
        for(int p : temp) {
            v.pb(p);
        }
    }
    
    sorted = true;
    for(int i = 1; i < sz(v); i++) {
        if(v[i] < v[i - 1]) {
            sorted = false;
            break;
        }
    }
    
    if(!sorted) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

signed main()
{
    FAST;

    sieve();

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        solve();
    }
}