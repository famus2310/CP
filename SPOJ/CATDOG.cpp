#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1005;


int n;
vector<int> adjList[1005 + 5];
int matched[1005 + 5];
int Distance[1005 + 5];

struct node {
	int in, out;
};

node arr[1005 + 5];

void preprocess() {
	SET(matched, 0);
	SET(Distance, 0);
	for (int i = 0; i < 1005; i++)
		adjList[i].clear();
}

bool bfs( ) {
    queue<int> q ;
    for( int i = 1 ; i <= N ; i ++ )
        if( matched[i] == 0 ) {  q.push(i) ;
             Distance[i] = 0 ;
          }
        else Distance[i] = INF ; 
     Distance[0] = INF ; 
     while( !q.empty() )  {
          int Left = q.front( ); 
          q.pop() ;
          for( int Right : adjList[Left] )  {
               if( Distance[ matched[Right] ] == INF ) {
                      Distance[ matched[Right] ] = Distance[Left] + 1 ; 
                      q.push( matched[Right] ) ;
                 }
            }
      }
     return ( Distance[ 0  ] != INF )  ; 
 }
bool dfs(  int Left ) {
    if( Left == 0 )return true ;
    for( int Right : adjList[Left] )  {
         if(  Distance[matched[Right]] == Distance[Left] + 1  )
               if( dfs( matched[Right] ) ) {
                    matched[Left] = Right ;
                    matched[Right] = Left ;
                    return true ;
                 }
      }
      Distance[ Left ] = INF ;
      return false ;
 }
void Hopcroft( ) {
     int matching = 0 ;
     while( bfs( ) )  {
         for(  int i = 1 ; i <= N ; i ++ )
              if( matched[i] == 0 and dfs(  i ) )
                       matching++ ;  
      }
      cout<<matching<<endl;
 }



int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		preprocess();
		int a, b, n;
		scanf("%d %d %d", &a, &b, &n);
		for (int i = 1; i <= n; i++) {
			int x, y;
			char dummy1, dummy2;
			scanf(" %c%x %c%x", &dummy1, &x, &dummy2, &y);
			if (dummy1 == 'C')
				x = -x;
			if (dummy2 == 'C')
				y = -y;
			arr[i] = {x, y};
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (arr[i].in == arr[j].out || arr[i].out == arr[j].in) {
					adjList[i].pb(j);
					adjList[j].pb(i);
				}
			}
		}
		Hopcroft();
	}
	return 0;
}
		