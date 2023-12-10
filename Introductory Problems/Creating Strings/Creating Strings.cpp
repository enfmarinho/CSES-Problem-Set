// Problem: Creating Strings
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1622
// Memory Limit: 512
// Time Limit: 1000
// Start: 09/12/2023 22:25

#include <iostream>
#include <set>
#include <string>
#include <tuple>
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

string s;
set<string> words;
vb used;

void generate(string &tmp) {
  if (tmp.size() == s.size()) {
    words.insert(tmp);
    return;
  }
  for (int index{0}; index < s.size(); ++index) {
    if (not used[index]) {
      tmp.push_back(s[index]);
      used[index] = true;
      generate(tmp);
      used[index] = false;
      tmp.pop_back();
    }
  }
}

int main() {
  GO FAST;
  cin >> s;
  used.resize(s.size(), false);
  string aux;
  generate(aux);
  cout << words.size() << '\n';
  for (const string &word : words) {
    cout << word << '\n';
  }
  return 0;
}
