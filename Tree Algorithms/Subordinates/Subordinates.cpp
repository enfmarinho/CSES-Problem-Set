// Problem: Subordinates
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1674
// Memory Limit: 512
// Time Limit: 1000
// Start: 24/11/2023 00:47

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <initializer_list>
#include <iomanip>
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

vvll adj_list;
vll children_number;
vb calculated;

ll dp(ll current) {
  if (adj_list[current].empty()) {
    calculated[current] = true;
    children_number[current] = 0;
    return 1;
  } else if (calculated[current]) {
    return children_number[current] + 1;
  } else {
    for (auto child : adj_list[current]) {
      children_number[current] += dp(child);
    }
  }

  calculated[current] = true;
  return children_number[current] + 1;
}

int main() {
  GO FAST;
  ll n;
  cin >> n;
  adj_list.resize(n + 1);
  children_number.resize(n + 1);
  calculated.resize(n + 1);
  for (int index{2}; index <= n; ++index) {
    ll tmp;
    cin >> tmp;
    adj_list[tmp].push_back(index);
  }
  dp(1);
  for (int index{1}; index <= n; ++index) {
    cout << children_number[index] << ' ';
  }
  return 0;
}
