#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    vector <int> v(3);

    for(int i=0; i<3; i++){
      cin >> v[i];
    }
    sort(v.begin(), v.end()); 

    if(v[0]==v[1] || v[1]==v[2] || v[0]==v[2]){
      cout << "0" << "\n";
    } else if (v[1]-v[0] > v[2]-v[1]){
      cout << v[2] - v[1] << '\n';
    } else {
      cout << v[1] - v[0] << '\n';
    }
  }

  return 0;
}
