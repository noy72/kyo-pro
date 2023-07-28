#include <ctgmath>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl
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

bool isOk(const int length, const int k, const vector<int>& a) {
  int sliceCount = 0;
  int back = 0;
  for (int i : a) {
    if (i - back >= length) {
      // cout << i << ' ' << back << ' ' << length << endl;
      back = i;
      sliceCount++;
    }
  }
  return k + 1 <= sliceCount;
}

int main() {
  int n, l, k;
  cin >> n >> l >> k;

  vector<int> a(n + 1);
  cin >> a;
  a[n] = l;

  int ok = 1, ng = l;
  rep(i, 100) {
    int mid = (ok + ng) / 2;
    if (isOk(mid, k, a))
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
}
