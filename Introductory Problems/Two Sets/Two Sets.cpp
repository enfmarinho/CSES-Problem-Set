// Problem: Two Sets
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1092
// Memory Limit: 512
// Time Limit: 1000
// Start: 24/11/2023 12:58

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define ll long long
#define ull unsigned ll
#define ld long double
#define F first
#define S second
#define FF F.F
#define FS F.S
#define SS S.S
#define SF S.F
#define range(a) a.begin(), a.end()
#define GO ios_base::sync_with_stdio(false);
#define FAST cin.tie(nullptr);
#define FOR(i, limit) for (int i = 0; i < limit; i++)
#define MOD 1000000007
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
  ll n;
  cin >> n;
  ll sum = (n * n + n) / 2;
  if (sum % 2 != 0) {
    cout << "NO";
  } else {
    ll curr_sum{0};
    set<int> elements;
    for (int i = n; i > 0; --i) {
      curr_sum += i;
      if (curr_sum > sum / 2) {
        curr_sum -= i;
      } else {
        elements.insert(i);
      }
    }

    if (curr_sum == sum / 2) {
      cout << "YES\n";
      cout << elements.size() << '\n';
      for (auto it = elements.begin(); it != elements.end(); ++it) {
        cout << *it << ' ';
      }
      cout << '\n' << n - elements.size() << '\n';
      for (int i = 1; i <= n; ++i) {
        if (elements.find(i) == elements.end()) {
          cout << i << ' ';
        }
      }
    } else {
      cout << "NO";
    }
  }
  return 0;
}
