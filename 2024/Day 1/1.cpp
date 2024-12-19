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
    ll N = 1000;
    ll i;
    vl A(N);
    map<ll, ll> B;
    For(i, N) {
        ll B2;
        cin >> A[i] >> B2;
        B[B2]++;
    }
    ll ans = 0;
    For(i, N) {
        ans += A[i] * B[A[i]];
    }
    cout << ans << '\n';
}

void part1() {
    ifstream cin("input.txt");
    ll N = 1000;
    ll i;
    vl A(N);
    vl B(N);
    For(i, N) {
        cin >> A[i] >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll ans = 0;
    For(i, N) {
        ans += abs(A[i] - B[i]);
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
