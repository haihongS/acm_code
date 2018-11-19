// DLX
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int maxn = 5000;

char _data[150];

struct DLX {
  int cnt;
  int ans[maxn];
  int L[maxn], R[maxn], U[maxn], D[maxn];
  int row[maxn], col[maxn]; // implies row & col position about this number
  int sum[maxn];

  void init(int n) {
    cnt = 0;
    for (int i = 0; i <= n; i++) {
      U[cnt] = cnt; D[cnt] = cnt;
      L[cnt] = cnt - 1; R[cnt] = cnt + 1;
      row[cnt] = 0; col[cnt] = i;
      sum[i] = 0;
      cnt++;
    }
    L[0] = n;
    R[n] = 0;
  }

  void addRow(int rr, vector<int> x) {
    int len = x.size();
    int fir = cnt;
    for (int i = 0; i < len; i++) {
      int cc = x[i];
      R[cnt] = cnt + 1; L[cnt] = cnt - 1;
      D[cnt] = cc; U[cnt] = U[cc];
      D[U[cc]] = cnt; U[cc] = cnt;
      row[cnt] = rr; col[cnt] = cc;
      sum[cc]++; cnt++;
    }
    L[fir] = cnt - 1; R[cnt - 1] = fir;
  }

  void remove(int _c) {
    R[L[_c]] = R[_c];
    L[R[_c]] = L[_c];
    for (int i = D[_c]; i != _c; i = D[i]) {
      for (int j = R[i]; j != i; j = R[j]) {
        D[U[j]] = D[j];
        U[D[j]] = U[j];
        sum[col[j]]--;
      }
    }
  }

  void resume(int _c) {
    for (int i = U[_c]; i != _c; i = U[i]) {
      for (int j = L[i]; j != i; j = L[j]) {
        D[U[j]] = j;
        U[D[j]] = j;
        sum[col[j]]++;
      }
    }
    R[L[_c]] = _c;
    L[R[_c]] = _c;
  }

  int dance(int cur) {
    if (R[0] == 0) {
      return cur;
    }
    int st = R[0];
    for (int i = R[0]; i != 0; i = R[i]) {
      if (sum[i] < sum[st]) st = i;
    }
    remove(col[st]);
    for (int i = D[st]; i != st; i = D[i]) {
      ans[cur] = row[i];
      for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
      int go = dance(cur + 1);
      if (go != 0) return go;
      for (int j = L[i]; j != i; j = L[j]) resume(col[j]);
    }
    resume(col[st]);
    return 0;
  }

  void decode(int m, int &x, int &y, int &z) {
    m--;
    z = m % 9; m /= 9;
    y = m % 9; m /= 9;
    x = m;
  }

  void getAns(int len) {
    for (int i = 0; i < len; i++) {
      int x, y, z;
      decode(ans[i], x, y, z);
      _data[x * 9 + y] = '1' + z;
      // printf("%d %d %d\n", x, y, z);
    }
  }
};

DLX v;

int encode(int x,int y, int z) {
  return x * 81 + y * 9 + z + 1;
}

int main() {
  // freopen("data.in", "r", stdin);
  while(~scanf("%s", _data)) {
    if (strcmp(_data, "end") == 0) break;
    v.init(9 * 9 * 4);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 9; k++) {
          int pos = i * 9 + j;
          // row i has k - 0
          // col j has k - 1
          // block i/3 * 3 + j/3 has k - 2
          // row i col j has a number - 3
          if (_data[pos] == '.' || _data[pos] == '1' + k) {
            vector<int> tmp;
            tmp.clear();
            tmp.push_back(encode(0, i, k));
            tmp.push_back(encode(1, j, k));
            tmp.push_back(encode(2, i / 3 * 3 + j / 3, k));
            tmp.push_back(encode(3, i, j));
            v.addRow(encode(i, j ,k), tmp);
          }
        }
      }
    }
    int len = v.dance(0);
    v.getAns(len);
    _data[81] = '\0';
    printf("%s\n", _data);

  }
  return 0;
}
