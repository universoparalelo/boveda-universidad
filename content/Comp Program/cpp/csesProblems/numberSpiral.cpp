#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    long long x, y;
    cin >> y >> x;
    long long base = max(x,y) * max(x,y) - (max(x,y)-1);

    if (x>y && x%2 == 0){
      base -= (x-y);
    } else if (x>y && x%2 != 0){
      base += (x-y);
    } else if (y>x && y%2 == 0){
      base += (y-x);
    } else if (y>x && y%2 != 0){
      base -= (y-x);
    }
    cout << base << '\n';
  }
  

  return 0;
}
