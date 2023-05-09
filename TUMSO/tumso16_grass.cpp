#include <bits/stdc++.h>
using namespace std;

char x[105][105];

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

int n,m;

int fill(int i, int j) {
  if(i<0 || i>=n || j<0 || j>=m || x[i][j]=='#') return 0;
  x[i][j] = '#';
  for(int Q=0; Q<8; Q++) fill(i+dx[Q],j+dy[Q]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  memset(x,'#',sizeof(x));
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) {cin>>x[i][j];}
  int cnt=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(x[i][j]=='.') {
        cnt++;
        fill(i,j);
      }
    }
  }
  cout<<cnt;
}