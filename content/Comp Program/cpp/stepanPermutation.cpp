#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n, x, y;
    cin >> n >> x >> y;

    bool bandera = false;

    for (int i=0; i<n; i++){
      int a;
      int dif;
      cin >> a;
      if (bandera) continue;
      if (a != i+1){
        dif = abs(a - (i+1));
        if (dif % 2 != 0 && x % 2 == 0 && y % 2 == 0){
          cout << "NO" << '\n';
          bandera = true;
        }
      } 
    }

    if (!bandera) cout << "YES" << '\n';
  }

  return 0;
}
