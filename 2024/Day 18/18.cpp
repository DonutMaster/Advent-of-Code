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
    ifstream cin("input2.txt");
    ll N = 3450;
    ll M = 71;
    ll K = 1024;
    ll i, j;
    string S(M, '.');
    v<string> grid(M, S);
    ll x = -1;
    ll y = -1;
    For(i, K) {
        cin >> S;
        string curr = "";
        For(j, S.length()) {
            if(j == S.length()-1) {
                curr += S[j];
                y = stoll(curr);
            } else if(S[j] == ',') {
                x = stoll(curr);
                curr = "";
            } else {
                curr += S[j];
            }
        }
        grid[y][x] = '#';
    }
    ll lastX = x;
    ll lastY = y;
    queue<pair<pair<ll, ll>, ll>> q;
    map<pair<ll, ll>, bool> seen;
    for(i = K; i < N; i++) {
        if(i < N) {
            cin >> S;
            string curr = "";
            For(j, S.length()) {
                if(j == S.length()-1) {
                    curr += S[j];
                    y = stoll(curr);
                } else if(S[j] == ',') {
                    x = stoll(curr);
                    curr = "";
                } else {
                    curr += S[j];
                }
            }
            grid[y][x] = '#';
            lastX = x;
            lastY = y;
        }
        q.push({{0, 0}, 0});
        bool work = false;
        seen.clear();
        while(q.size() > 0) {
            pair<pair<ll, ll>, ll> d = q.front();
            q.pop();
            x = d.first.first;
            y = d.first.second;
            ll steps = d.second;
            if(x == M-1 && y == M-1) {
                work = true;
                break;
            }
            if(seen[{x, y}]) {
                continue;
            }
            seen[{x, y}] = true;
            if(x != 0 && grid[x-1][y] != '#' && !seen[{x-1, y}]) {
                q.push({{x-1, y}, steps+1});
            }
            if(x != M-1 && grid[x+1][y] != '#' && !seen[{x+1, y}]) {
                q.push({{x+1, y}, steps+1});
            }
            if(y != 0 && grid[x][y-1] != '#' && !seen[{x, y-1}]) {
                q.push({{x, y-1}, steps+1});
            }
            if(y != M-1 && grid[x][y+1] != '#' && !seen[{x, y+1}]) {
                q.push({{x, y+1}, steps+1});
            }
        }
        if(!work) {
            cout << lastX << ',' << lastY << '\n';
            return;
        }
    }
}

void part1() {
    ifstream cin("input.txt");
    ll N = 1024; // 
    ll M = 71;
    ll i, j;
    vp all(N);
    string S(M, '.');
    v<string> grid(M, S);
    For(i, N) {
        ll x, y;
        cin >> S;
        string curr = "";
        For(j, S.length()) {
            if(j == S.length()-1) {
                curr += S[j];
                y = stoll(curr);
            } else if(S[j] == ',') {
                x = stoll(curr);
                curr = "";
            } else {
                curr += S[j];
            }
        }
        grid[y][x] = '#';
    }
    queue<pair<pair<ll, ll>, ll>> q;
    map<pair<ll, ll>, bool> seen;
    q.push({{0, 0}, 0});
    while(q.size() > 0) {
        pair<pair<ll, ll>, ll> d = q.front();
        q.pop();
        ll x = d.first.first;
        ll y = d.first.second;
        ll steps = d.second;
        if(x == M-1 && y == M-1) {
            cout << steps << '\n';
            return;
        }
        if(seen[{x, y}]) {
            continue;
        }
        seen[{x, y}] = true;
        if(x != 0 && grid[x-1][y] != '#' && !seen[{x-1, y}]) {
            q.push({{x-1, y}, steps+1});
        }
        if(x != M-1 && grid[x+1][y] != '#' && !seen[{x+1, y}]) {
            q.push({{x+1, y}, steps+1});
        }
        if(y != 0 && grid[x][y-1] != '#' && !seen[{x, y-1}]) {
            q.push({{x, y-1}, steps+1});
        }
        if(y != M-1 && grid[x][y+1] != '#' && !seen[{x, y+1}]) {
            q.push({{x, y+1}, steps+1});
        }
    }
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
