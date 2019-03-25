#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
set<vvi> visit;
vvi final;
bool found = 0;
string st;
int N,
 dx[4] {0, 1, 0, -1},
 dy[4] {-1, 0, 1, 0};

void printState(vvi state)
{
 for (int i=0;i<N;i++) {
  for (int j=0;j<N;j++) {
   cout<<state[i][j]<<' ';
  }
  cout<<endl;
 }
}

void DFS(vvi currState, int x, int y, int depth, string step)
{
 visit.insert(currState);
 if (currState == final) {
  cout<<"Banyak langkah (belum tentu minimal): "<<depth<<endl;
  found = 1;
  st = step;
  return;
 }
 for (int i=0;i<4;i++) {
  if (x+dx[i] >= 0 && x+dx[i] < N && y+dy[i] >= 0 && y+dy[i] < N) {
   vvi temp = currState;
   string tmp = step;
   switch (i) {
    case 0 :
    tmp+="U";
    break;
    case 1 :
    tmp+="R";
    break;
    case 2 :
    tmp+="D";
    break;
    case 3 :
    tmp+="L";
    break;
    default :
    break;
   }
   swap(temp[y][x], temp[y+dy[i]][x+dx[i]]);
   if (visit.find(temp) == visit.end() && !found)
    DFS(temp, x+dx[i], y+dy[i], depth+1, tmp);
  }
 }
 return;
}

int main()
{
 cin>>N;
 vvi init;
 int x,y;
 for (int i=0;i<N;i++) {
  init.push_back(vi());
  final.push_back(vi());
  for (int j=0;j<N;j++) {
   if (i == N-1 && j == N-1) final[i].push_back(0);
   else final[i].push_back(N*i+j+1);
   int temp;
   cin>>temp;
   init[i].push_back(temp);
   if (init[i][j] == 0) {
    x=j;y=i;
   }
  }
 }
 cout<<endl;
 DFS(init, x, y, 0, "");
 if (found) {
  cout<<"Solusi:\n";
  for (auto c:st) {
   switch (c) {
    case 'R':
    cout<<"Kanan\n";
    swap(init[y][x], init[y][x+1]);
    x++;
    break;
    case 'D':
    cout<<"Bawah\n";
    swap(init[y][x], init[y+1][x]);
    y++;
    break;
    case 'L':
    cout<<"Kiri\n";
    swap(init[y][x], init[y][x-1]);
    x--;
    break;
    case 'U':
    cout<<"Atas\n";
    swap(init[y][x], init[y-1][x]);
    y--;
    break;
    default:
    break;
   }
   printState(init);
   cout<<endl;
  }
 }
 else cout<<"Solusi tidak ditemukan";
}