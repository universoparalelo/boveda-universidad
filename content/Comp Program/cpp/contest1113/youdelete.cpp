#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    string s;
    cin >> s;
    int n = s.size();

    for(int i=0; i<n; i++){
      if(s[i] == '1'){
        s.erase(i,1);
        break;
      }
    }
    for(int i=0; i<n; i++){
      if(s[i] == '0'){
        s.erase(i,1);
        break;
      }
    }
    cout << s << '\n';
  }

  return 0;
}
