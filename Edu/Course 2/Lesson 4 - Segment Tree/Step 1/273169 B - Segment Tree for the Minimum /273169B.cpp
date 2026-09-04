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

template <typename T>
struct SegmentTree {
    int n;
    vector<T> tree;
    T neutral = INT_MAX;
    T merge(T a, T b) {
        return min(a, b);
    }
    SegmentTree() : n(0) {}
    void build(const vector<T>& arr) {
        n = arr.size();
        tree.assign(2 * n, neutral);
        for (int i = 0; i < n; i++) tree[n + i] = arr[i];
        for (int i = n - 1; i > 0; --i) tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int p, T val) {
        for (tree[p += n] = val; p > 1; p >>= 1) {
            tree[p >> 1] = merge(tree[p], tree[p ^ 1]);
        }
    }

    // from l to r - 1
    T query(int l, int r) {
        T resL = neutral, resR = neutral;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = merge(resL, tree[l++]);
            if (r & 1) resR = merge(tree[--r], resR);
        }
        return merge(resL, resR);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(auto &i : v)    cin >> i;
    
    SegmentTree<ll>sg;
    sg.build(v);
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int ind;
            ll val;
            cin >> ind >> val;
            sg.update(ind, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sg.query(l, r) << endl;
        }
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