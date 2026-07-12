#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n;
    cin >> n;

    long long count = 0;

    for (long long b=1; b<=n; b++){
      long long k = n/b;
      count += k*k;
    }

    cout << count << '\n';
  }

  return 0;
}
