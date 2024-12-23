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
    ll N = 3380;
    // I don't know how to solve this one! Check out Jonathan Paulson's code instead!
    
}

void part1() {
    ifstream cin("input.txt");
    ll N = 3380;
    ll i, j, x;
    ll ans = 0;
    map<pair<string, string>, bool> conn;
    v<string> all;
    map<string, bool> did;
    For(i, N) {
        string S;
        cin >> S;
        conn[{S.substr(0, 2), S.substr(3, 2)}] = true;
        conn[{S.substr(3, 2), S.substr(0, 2)}] = true;
        if(!did[S.substr(0, 2)]) {
            all.push_back(S.substr(0, 2));
            did[S.substr(0, 2)] = true;
        }
        if(!did[S.substr(3, 2)]) {
            all.push_back(S.substr(3, 2));
            did[S.substr(3, 2)] = true;
        }
    }
    For(i, all.size()) {
        For(j, all.size()) {
            For(x, all.size()) {
                if(i != j && j != x && i != x && conn[{all[i], all[j]}] && conn[{all[i], all[x]}] && conn[{all[j], all[x]}] && (all[i][0] == 't' || all[j][0] == 't' || all[x][0] == 't')) {
                    ans++;
                }
            }
        }
    }
    cout << ans/6 << '\n';
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
