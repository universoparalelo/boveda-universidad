#include <bits/stdc++.h>
using namespace std;

bool valid(const string& s, int start, int firstValue){
  int expected = firstValue;

  for(int i=start; i<s.size(); i+=2){
    if(s[i] != '?' && s[i] - '0' != expected){
      return false;
    }
    expected ^= 1;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int par=0, impar=0;

    if(valid(s,0,0)){
      impar++;
    }
    if(valid(s,0,1)){
      impar++;
    }
    if(valid(s,1,0)){
      par++;
    }
    if(valid(s,1,1)){
      par++;
    }

    cout << impar * par << '\n';
  }

  return 0;
}
