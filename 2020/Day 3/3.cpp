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
    ll N = 323;
    ll M = 31;
    v<string> map(N);
    ll i;
    For(i, N) {
        cin >> map[i];
    }
    ll ans = 1;
    v<vl> slopes = {{1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}};
    For(i, slopes.size()) {
        ll x = slopes[i][0];
        ll y = slopes[i][1];
        ll curr = 0;
        while(x < N) {
            if(map[x][y] == '#') {
                curr++;
            }
            x += slopes[i][0];
            y += slopes[i][1];
            if(y >= M) {
                y -= M;
            }
        }
        ans *= curr;
    }
    cout << ans << '\n';
}

void part1() {
    ifstream cin("input.txt");
    ll N = 323;
    ll M = 31;
    v<string> map(N);
    ll i;
    For(i, N) {
        cin >> map[i];
    }
    ll x = 1;
    ll y = 3;
    ll ans = 0;
    while(x < N) {
        if(map[x][y] == '#') {
            ans++;
        }
        x++;
        y += 3;
        if(y >= M) {
            y -= M;
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
