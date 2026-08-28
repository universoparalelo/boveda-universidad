#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n, k;
    cin >> n >> k;

    if(n >= k*2){
      string s = "";
      int u=0, z=0;
      for(int i=0; i<k; i++){
        if(i==0 || i%2==0){
          s += "00";
          z += 2;
        } else {
          s += "11";
          u += 2;
        }
      }
      n -= k*2;
      for(int i=0; i<n; i++){
        if(z < u){
          s += "0";
          z++;
        } else {
          s += "1";
          u++;
        }
      }
      cout << s << '\n';
    } else {
      cout << "-1" << '\n';
    }
  }

  return 0;
}
