#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

int table[N][18];

int query(int i, int j){ // e.g [0, 4] = [0][2], [1][2]
    int lg = log2(j - i + 1);
    return min(table[i][lg], table[j - (1<<lg) + 1][lg]);
}

void solve(int T){
    int n, q;
    cin >> n >> q;
    vi arr(n);
    cin >> arr;
    
    for(int i = 0; i < n; ++i)
        table[i][0] = arr[i];

    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 0; i + (1<<(j-1)) < n; ++i){
            table[i][j] = min(table[i][j-1], table[i + (1<<(j-1))][j-1]);
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << query(l, r) << "\n";
    }
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
