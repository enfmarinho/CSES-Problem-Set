// Problem: Meet in the Middle
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1628
// Memory Limit: 512
// Time Limit: 1000
// Start: 23/02/2024 14:11

#include <iostream>
#include <tuple>
#include <unordered_map>
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
typedef vector<vector<bool>> vvb;

#define SIZE 20

ll n, x, counter{0};
ll va[SIZE], vb[SIZE];
unordered_map<ll, ll> ha;

void dpa(ll sum, ll index) {
  if (sum == x) {
    ++counter;
  } else if (index == n / 2) {
    ++ha[sum];
  } else if (sum < x) {
    dpa(sum + va[index], index + 1);
    dpa(sum, index + 1);
  }
}

void dpb(ll sum, ll index) {
  if (sum == x) {
    ++counter;
  } else if (index == n - n / 2) {
    auto it = ha.find(x - sum);
    if (it != ha.end()) {
      counter += it->second;
    }
  } else if (sum < x) {
    dpb(sum + vb[index], index + 1);
    dpb(sum, index + 1);
  }
}

int main() {
  GO FAST;
  cin >> n >> x;
  for (int index{0}; index < n / 2; ++index) {
    cin >> va[index];
  }
  for (int index{0}; index < n - n / 2; ++index) {
    cin >> vb[index];
  }

  if (n > 1) {
    ha.reserve(1 << (n / 2 - 1));
  }
  dpa(0, 0);
  dpb(0, 0);
  cout << counter;
  return 0;
}
