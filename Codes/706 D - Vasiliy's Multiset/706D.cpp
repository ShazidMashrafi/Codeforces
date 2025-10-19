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

class Trie {
private:
    struct TrieNode {
        TrieNode* children[2];
        int count;
        
        TrieNode() {
            for (int i = 0; i < 2; i++)
                children[i] = nullptr;
            count = 0;
        }
    };
    
    TrieNode* root;
    static const int MAX_BITS = 31;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        for(int i = MAX_BITS; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if(!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
            node->count++;
        }
    }

    void erase(int num) {
        TrieNode* node = root;
        for(int i = MAX_BITS; i >= 0; --i) {
            int bit = (num >> i) & 1;
            node = node->children[bit];
            node->count--;
        }
    }
    
    int maxXOR(int num) {
        TrieNode* node = root;
        int result = 0;
        for(int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if(node->children[opposite] && node->children[opposite]->count > 0) {
                result |= (1 << i);
                node = node->children[opposite];
            } else {
                node = node->children[bit];
            }
        }
        return result;
    }
};

void solve()
{
    int q;
    cin >> q;

    Trie trie;
    trie.insert(0);

    while(q--) {
        char op;
        int x;
        cin >> op >> x;

        if(op == '+') {
            trie.insert(x);
        } else if(op == '-') {
            trie.erase(x);
        } else {
            cout << trie.maxXOR(x) << endl;
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