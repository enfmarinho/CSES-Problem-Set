// Problem: Palindrome Reorder
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1755
// Memory Limit: 512
// Time Limit: 1000
// Start: 10/12/2023 18:22

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

int main() {
  GO FAST;
  string s;
  cin >> s;

  vi letters(26);
  for (const char &c : s) {
    ++letters[c - 'A'];
  }

  bool odd = (s.size() % 2 != 0);
  bool has_solution = true;
  int odd_letter{INT_MAX};
  for (int index{0}; index < 26; ++index) {
    if (letters[index] % 2 != 0 and odd) {
      odd = false;
      odd_letter = index;
    } else if (letters[index] % 2 != 0) {
      has_solution = false;
      break;
    }
  }

  if (odd or not has_solution) {
    cout << "NO SOLUTION\n";
  } else {
    string ans;
    ans.resize(s.size());

    if (odd_letter != INT_MAX) {
      ans[s.size() / 2] = 'A' + odd_letter;
      --letters[odd_letter];
    }

    int curr_letter{0};
    for (int index{0}; index < s.size() / 2; ++index) {
      while (letters[curr_letter] < 2) {
        ++curr_letter;
      }
      letters[curr_letter] -= 2;
      ans[index] = ans[s.size() - index - 1] = 'A' + curr_letter;
    }
    cout << ans << '\n';
  }

  return 0;
}
