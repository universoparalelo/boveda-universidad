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
    string s;
    cin >> s;
    
    int sum = 0;
    char ant = ' ';
    for(int i=0; i<n; i++){
      if(ant == ' ' || ant != s[i]){
        sum++;
        ant = s[i];
      }
    }
    //cout << sum << '\n';
    int newsum, best = sum;
    for(int i=0; i<n-1; i++){
      newsum = sum;
      if(s[i] != s[i+1]){
        newsum--;
        best = min(newsum, sum);
        int f = s[i];
        int l = s[i+2];
        int j = i+3;
        while (f == l){
          newsum--;
          best = min(newsum, sum);
          l = s[j];
          j++;
        }
      }
    }
    cout << sum << " " << best << '\n';
    }

  return 0;
}
