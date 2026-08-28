#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int i=0, count=0, best=0;
  char valActual;

  while(i < s.size()){
    valActual = s[i];
    while(s[i]==valActual){
      count++;
      i++;
    }
    best = max(best,count);
    count = 0;
  }

  cout << best << '\n';

  return 0;
}
