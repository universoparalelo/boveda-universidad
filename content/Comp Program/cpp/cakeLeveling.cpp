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

    long long x, suma, h;
    cin >> h;
    suma = h;
    cout << h << " ";
    for(int i = 2; i < n+1; i++){
      cin >> x;
      suma += x;
      if ((suma/i) > h){
        cout << h << " ";
      } else {
        cout << suma/i << " ";
        h = suma/i;
      }
    }
    cout << "\n";
  }

  return 0;
}
