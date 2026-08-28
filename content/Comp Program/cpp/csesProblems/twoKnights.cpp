#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for(long long k=1; k<=n; k++){
    long long k2 = k*k;
    long long total = k2*(k2-1)/2;
    long long atacan = 4*(k-1)*(k-2);
    cout << total - atacan << '\n';
  }

  return 0;
}
