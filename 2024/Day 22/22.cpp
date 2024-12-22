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
    ll N = 1787;
    ll i, j;
    v<vl> all(N);
    v<vl> curr(N);
    For(i, N) {
        ll num;
        cin >> num;
        ll org = 0;
        For(j, 2000) {
            org = stoll(to_string(num).substr(to_string(num).length()-1, 1));
            num ^= num * 64;
            num %= 16777216;
            num ^= num / 32;
            num %= 16777216;
            num ^= num * 2048;
            num %= 16777216;
            all[i].push_back(stoll(to_string(num).substr(to_string(num).length()-1, 1))-org);
            curr[i].push_back(stoll(to_string(num).substr(to_string(num).length()-1, 1)));
        }
    }
    map<vl, ll> bana;
    For(i, N) {
        map<vl, bool> done;
        For(j, all[i].size()-3) {
            if(!done[{all[i][j], all[i][j+1], all[i][j+2], all[i][j+3]}]) {
                bana[{all[i][j], all[i][j+1], all[i][j+2], all[i][j+3]}] += curr[i][j+3];
                done[{all[i][j], all[i][j+1], all[i][j+2], all[i][j+3]}] = true;
            }
        }
    }
    ll ans = 0;
    For(i, N) {
        map<vl, bool> done;
        For(j, all[i].size()-3) {
            ans = max(ans, bana[{all[i][j], all[i][j+1], all[i][j+2], all[i][j+3]}]);
        }
    }
    cout << ans << '\n';
}

void part1() {
    ifstream cin("input.txt");
    ll N = 1787;
    ll i, j;
    ll ans = 0;
    For(i, N) {
        ll num;
        cin >> num;
        For(j, 2000) {
            num ^= num * 64;
            num %= 16777216;
            num ^= num / 32;
            num %= 16777216;
            num ^= num * 2048;
            num %= 16777216;
        }
        ans += num;
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
