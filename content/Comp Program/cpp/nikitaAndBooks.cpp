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

    long long resto = 0;
    bool bandera = false;
    long long a;
    for(int i = 0; i < n; i++){
      cin >> a;
      if (bandera) continue;
      a += resto;
      resto = a - (i + 1);
      if (resto < 0){
        bandera = true;
      }
    }

    if (bandera){
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }

return 0;
}
