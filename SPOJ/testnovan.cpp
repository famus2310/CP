#include<bits/stdc++.h>
     
    int tab[710];
    int dp[710][710];
    int n;
     
    int gcd(int a,int b)
    {
      return (b == 0 ? a : gcd(b,a % b));
    }
     
    int rec(int l,int r,int root)
    {
      // printf("%d %d %d %d\n",l,r,tab[root],root);
      if (l == r) return 1;
      if (dp[l][r] != -1)
      {
        // puts("yo");
        return dp[l][r];
      }
      int i;
      int satu = (root == l),dua = (root == r);
      for (i = l ; i <= root - 1; i++) if (gcd(tab[i],tab[root]) != 1 && tab[i] < tab[root])
      {
        // printf("%d\n",i);
        satu |= rec(l,root - 1,i);
        // if (satu) break;
      }
      for (i = root + 1 ; i <= r ; i++) if (gcd(tab[i],tab[root]) != 1 && tab[i] > tab[root])
      {
        // printf("%d %d %d\n",tab[i],tab[root],gcd(tab[i],tab[root]));
        // printf("%d\n",i);
        dua |= rec(root + 1,r,i);
        // if (dua) break;
      }
      int ans = satu & dua;
      // printf("%d %d %d %d %d\n",l,r,tab[root],satu,dua);
      return dp[l][r] = ans;
    }
     
    // int cmpfunc(const void * a,const void * b)
    // {
    //  return ( *(int*)a - *(int*)b );
    // }
     
    int main() {
      memset(dp,-1,sizeof(dp));
      // printf("%d\n",gcd(7,17));
      scanf("%d",&n);
      int i;
      for (i = 1 ; i <= n ; i++)
      {
        scanf("%d",tab + i);
        if (tab[i] == tab[i - 1])
        {
          assert(false);
        }
      }
      // qsort(tab,n + 1,sizeof(int),cmpfunc);
      int ans = 0;
      for (i = 1 ; i <= n ; i++)
      {
        ans |= rec(1,n,i);
        // if (ans == 1)
        // {
        //  // printf("%d\n",i);
        //  break;
        // }
      }
      memset(dp,-1,sizeof(dp));
      for (i = n ; i <= n ; i++)
      {
        ans |= rec(1,n,i);
        // if (ans == 1)
        // {
        //  // printf("%d\n",i);
        //  break;
        // }
      }
      // for (i = 1 ; i <= n ; i++) if (dp[1][n])
      // {
      //  printf("%d\n",i);
      // }
      // for (i = 1 ; i < n ; i++) if (dp[1][4][i])
      // {
      //  printf("%d\n",i);
      // }
      if (ans)
        puts("Yes");
      else
        puts("No");
    }