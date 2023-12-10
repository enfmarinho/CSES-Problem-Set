// Problem: Coin Piles
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1754
// Memory Limit: 512
// Time Limit: 1000
// Start: 10/12/2023 17:45

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

int main() {
  GO FAST;
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    if ((a + b) % 3 != 0 or 2 * a < b or b * 2 < a) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
