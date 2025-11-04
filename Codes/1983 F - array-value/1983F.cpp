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

const int MAXBIT = 30;

class Trie {
public:
    vector<ll>maxIndex;
    vector<array<ll, 2>> children;
    
    ll createNode() {
        maxIndex.pb(-1);
        children.pb({-1, -1});
        return sz(children) - 1;
    }
    
    Trie() {
        createNode();
    }

    void insert(ll num, ll index) {
        ll node  = 0;
        maxIndex[node] = max(maxIndex[node], index);

        for(ll i = MAXBIT - 1; i >= 0; i--) {
            bool bit = (num >> i) & 1;

            if(children[node][bit] == -1) {
                children[node][bit] = createNode();
            }

            node = children[node][bit];
            maxIndex[node] = max(maxIndex[node], index);
        }
    }

    ll query(ll num, ll x) {
        ll node =  0;
        ll result = -1;
        
        for(ll i = MAXBIT - 1; i >= 0; --i) {
            if(node == -1)  break;

            bool numBit = (num >> i) & 1;
            bool xBit = (x >> i) & 1;

            if(numBit && xBit) {
                if(children[node][1] != -1) {
                    result = max(result, maxIndex[children[node][1]]);
                }
                node = children[node][0];
            }
            else if(!numBit && xBit) {
                if(children[node][0] != -1) {
                    result = max(result, maxIndex[children[node][0]]);
                }
                node = children[node][1];
            }
            else if(numBit && !xBit) {
                node = children[node][1];
            }
            else {
                node = children[node][0];
            }
        }

        if(node != -1) {
            result = max(result, maxIndex[node]);
        }

        return result;
    }
};

ll countSubarrays(auto &a, ll x) {
    ll n = sz(a);
    ll count = 0;
    Trie trie;
    ll left = -1;
    
    for(ll i = 0; i < n; ++i) {
        left = max(left, trie.query(a[i], x));
        count += (left + 1);
        trie.insert(a[i], i);
    }
    return count;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    }

    ll left = 0, right = (1LL << 30) - 1, ans = right;
    while(left <= right) {
        ll mid = left + (right - left) / 2;
        ll count = countSubarrays(a, mid);

        if(count >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        solve();
    }
}