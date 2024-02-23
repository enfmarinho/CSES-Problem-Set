// Problem: Point Location Test
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2189
// Memory Limit: 512
// Time Limit: 1000
// Start: 23/02/2024 00:21

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define ull unsigned ll
#define ld long double
#define range(a) a.begin(), a.end()
#define GO ios_base::sync_with_stdio(false);
#define FAST cin.tie(nullptr);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tuple<ll, ll, ll> tll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

using i128 = __int128_t;
using pi128 = pair<i128, i128>;
i128 cross_product(pi128 p1, pi128 p2) {
  return p1.first * p2.second - p1.second * p2.first;
}

pi128 subtract(pll p1, pll p2) {
  return {p1.first - p2.first, p1.second - p2.second};
}

int main() {
  GO FAST;
  int t;
  cin >> t;
  while (t--) {
    pair<ll, ll> p1, p2, p3;
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >>
        p3.second;

    pi128 r1 = subtract(p3, p1);
    pi128 r2 = subtract(p3, p2);
    i128 r = cross_product(r1, r2);
    if (r > 0) {
      cout << "LEFT\n";
    } else if (r < 0) {
      cout << "RIGHT\n";
    } else {
      cout << "TOUCH\n";
    }
  }
  return 0;
}
