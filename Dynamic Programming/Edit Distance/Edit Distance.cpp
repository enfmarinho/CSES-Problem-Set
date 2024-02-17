// Problem: Edit Distance
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1639
// Memory Limit: 512
// Time Limit: 1000
// Start: 17/02/2024 16:09

#include <climits>
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

string s, t;
vvi memo;

int Levenshtein_distance(int s_index, int t_index) {
  if (s_index == -1) {
    return t_index + 1;
  } else if (t_index == -1) {
    return s_index + 1;
  } else if (memo[s_index][t_index] != INT_MAX) {
    return memo[s_index][t_index];
  } else if (s[s_index] == t[t_index]) {
    return memo[s_index][t_index] =
               Levenshtein_distance(s_index - 1, t_index - 1);
  } else {
    return memo[s_index][t_index] =
               min(Levenshtein_distance(s_index, t_index - 1) + 1,
                   min(Levenshtein_distance(s_index - 1, t_index) + 1,
                       Levenshtein_distance(s_index - 1, t_index - 1) + 1));
  }
}

int main() {
  GO FAST;
  cin >> s >> t;
  memo.resize(s.size(), vi(t.size(), INT_MAX));
  cout << Levenshtein_distance(s.size() - 1, t.size() - 1);
  return 0;
}
