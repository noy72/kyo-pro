#include <algorithm>
#include <cstdio>
#include <ctgmath>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T> auto vectors(X x, T a) {
  return vector<T>(x, a);
}
template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
  auto cont = vectors(y, z, zs...);
  return vector<decltype(cont)>(x, cont);
}
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {
  rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
  return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) {
    is >> x;
  }
  return is;
}

bool check(const string& s) {
  int cnt = 0;
  for (auto i : s) {
    // cout << i << ' ' << cnt << endl;
    if (i == '(')
      cnt++;
    else
      cnt--;
    if (cnt < 0)
      return false;
  }
  return true;
}

int main() {
  int n;

  cin >> n;

  // 2^20 * 20 * 10 = 209715200 = 1e8 * 2

  if (n % 2) {
    cout << endl;
    return 0;
  }

  string s;
  rep(i, n / 2) s += "(";
  rep(i, n / 2) s += ")";

  set<string> ans;
  do {
    show(s);
    if (check(s))
      ans.insert(s);
  } while (next_permutation(all(s)));

  for (auto i : ans)
    cout << i << endl;
}
