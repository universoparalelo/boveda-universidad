#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n, s;
    cin >> n >> s;

    vector<vector <int>> matriz(n, vector<int>(4, 0));
    int cont = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < 4; j++){
        cin >> matriz[i][j];
      }
    }

    for(int i=0; i<n; i++){
      if ((matriz[i][0] == 1 && matriz[i][1] == -1) || (matriz[i][0] == -1 && matriz[i][1] == 1)){
        if (matriz[i][2] + matriz[i][3] == s){
          cont++;
        }
      } 
      else if ((matriz[i][0] == 1 && matriz[i][1] == 1) || (matriz[i][0] == -1 && matriz[i][1] == -1)){
        if (matriz[i][2] == matriz[i][3]){
            cont++;
        }
      }
    }

    cout << cont << '\n';
  }
  return 0;
}
