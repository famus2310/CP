#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define SET(x, y) memset(x, y, sizeof(x))

long long int dt[2][1000007];
char a[1000007];
long long int b[1000007];
int build(int id,int l,int r,int tp)
{
	if(l==r)
	{
		dt[tp][id]=a[l]-'a';
		return 0;
	}
	int mid=(l+r)/2;
	build(2*id,l,mid,tp);
	build(2*id+1,mid+1,r,tp);
	dt[tp][id]=(dt[tp][2*id+1]*b[mid-l+1]+dt[tp][2*id])%1000000007;
	return 0;
}
int update(int id,int l,int r,int index,int val,int tp)
{
	if(l==r&&l==index)
	{
		dt[tp][id]=val-'a';
		return 0;
	}
	int mid=(l+r)/2;
	if(index<=mid)
		update(2*id,l,mid,index,val,tp);
	else
		update(2*id+1,mid+1,r,index,val,tp);
	dt[tp][id]=(dt[tp][2*id+1]*b[mid-l+1]+dt[tp][2*id])%1000000007;
	return 0;
}
pair<int,int> query(int id,int l,int r,int la,int ra,int tp)
{
	if(l>ra||r<la)
		return mp(0,0);
	if(l>=la&&r<=ra)
		return mp(dt[tp][id],r-l+1);
	int mid=(l+r)/2;
	pair<int,int>aa=query(2*id,l,mid,la,ra,tp);
	pair<int,int>bb=query(2*id+1,mid+1,r,la,ra,tp);
	return mp((bb.fi*b[aa.se]+aa.fi)%1000000007,aa.se+bb.se);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        SET(dt, 0);
        SET(a, 0);
        SET(b, 0);
    	int m,p;
    	scanf("%d %d",&m,&p);
    	int i;
    	b[0]=1;
    	for(i=1;i<=m;i++)
    		b[i]=(b[i-1]*14553)%1000000007;
    	scanf("%s",a+1);
    	build(1,1,m,0);
    	reverse(a+1,a+m+1);
    	build(1,1,m,1);
    	reverse(a+1,a+m+1);
    	for(i=0;i<p;i++)
    	{
    		int tp;
    		scanf("%d",&tp);
    		if(tp==1)
    		{
    			int tem;
    			char d[2];
    			scanf("%d %s",&tem,d);
    			update(1,1,m,tem,d[0],0);
    			update(1,1,m,m-tem+1,d[0],1);
    		}
    		else
    		{
    			int l,r;
    			scanf("%d %d",&l,&r);
    			int aa=query(1,1,m,l,r,0).fi;
    			int bb=query(1,1,m,m-r+1,m-l+1,1).fi;
    			if(aa==bb)
    				printf("Adnan Wins\n");
    			else
    				printf("ARCNCD!\n");
    		}
    	}
    }
	return 0;
}

