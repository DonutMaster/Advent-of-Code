#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
#define For(i,N) for(i = 0; i < N; ++i)
#define FOR(i,K,N) for(i = K; i <= N; ++i)
#define vl vector<ll>
#define vp vector<pair<ll, ll>>
#define vd vector<ld>
#define v vector
#define m multiset
ll MOD = 1e9 + 7;

struct P { // Geometry
    ll x, y;
    void read() {
        cin >> x >> y;
    }
    P operator -(const P& b) const {
        return P{x-b.x, y-b.y};
    }
    bool operator == (const P& b) const {
        return x == b.x && y == b.y;
    }
    void operator -=(const P& b) {
        x -= b.x;
        y -= b.y;
    }
    ll operator *(const P& b) const {
        return (ll)(x*b.y) - (ll)(y*b.x);
    }
    ll triangle(const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }
    bool operator <(const P& b) const {
        return make_pair(x, y) < make_pair(b.x, b.y);
    }
};

void part2() {
    ifstream cin("input.txt");
    ll N = 400;
    v<string> av;
    v<string> A(N);
    while(true) {
        string S;
        cin >> S;
        if(S[S.length()-1] == ',') {
            av.push_back(S.substr(0, S.length()-1));
        } else {
            av.push_back(S);
            break;
        }
    }
    ll i, j, x;
    For(i, N) {
        string S;
        cin >> S;
        A[i] = S;
    }
    ll ans = 0;
    For(i, N) {
        string S = A[i];
        vl dp(S.length()+1, 0);
        For(j, av.size()) {
            if(S.length() >= av[j].length() && S.substr(0, av[j].length()) == av[j]) {
                dp[av[j].length()]++;
            }
        }
        For(j, S.length()+1) {
            if(dp[j] > 0) {
                For(x, av.size()) {
                    if(S.length()-j >= av[x].length() && S.substr(j, av[x].length()) == av[x] && av[x].length()+j <= S.length()) {
                        dp[av[x].length()+j] += dp[j];
                    }
                }
            }
        }
        ans += dp[S.length()];
    }
    cout << ans << '\n';
}

void part1() {
    ifstream cin("input.txt");
    ll N = 400;
    v<string> av;
    v<string> A(N);
    while(true) {
        string S;
        cin >> S;
        if(S[S.length()-1] == ',') {
            av.push_back(S.substr(0, S.length()-1));
        } else {
            av.push_back(S);
            break;
        }
    }
    ll i, j;
    For(i, N) {
        string S;
        cin >> S;
        A[i] = S;
    }
    ll ans = 0;
    For(i, N) {
        queue<ll> q;
        string S = A[i];
        q.push(0);
        map<ll, bool> seen;
        while(q.size() > 0) {
            ll pos = q.front();
            q.pop();
            if(pos == S.length()) {
                ans++;
                break;
            }
            if(seen[pos]) {
                continue;
            }
            seen[pos] = true;
            For(j, av.size()) {
                if(S.length()-pos >= av[j].length() && S.substr(pos, av[j].length()) == av[j]) {
                    q.push(pos+av[j].length());
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << "part1: ";
    part1();
    cout << "part2: ";
    part2();
    return 0;
}
