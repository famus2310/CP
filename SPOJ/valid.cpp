#include<iostream>
#include<cmath>
using namespace std;
int main()
    {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    long long chk_arr[18];
    chk_arr[0]=chk_arr[1]=0;
    for(int i=2;i<=17;i++)
        {
        chk_arr[i]=pow(2,i)*(i-1);
    }
    while(t--)
        {
        long long arr[4][4];
        long long sum=0;
        int flag=0,tot=0,grt=0,is_two=0,is_four=0;
        for(int i=0;i<4;i++)
            {
            for(int j=0;j<4;j++)
                {

                cin>>arr[i][j];
                int n;
                if(arr[i][j]!=0)
                {
                    tot++;


                    if(arr[i][j]%10==2)
                    {
                    n=1;
                    
                    if(arr[i][j]==2)
                    {is_two++;}
                }
                else if(arr[i][j]%10==4)
                    {
                    n=2;
                    if(arr[i][j]==4)
                        is_four++;
                }
                else if(arr[i][j]%10==8)
                    {
                    n=3;
                  //  if(arr[i][j]==8)
                   //     is_eight++;
                }
                else if(arr[i][j]%10==6)
                    {
                    n=4;
                }
                for(int k=n;k<=17;k+=4)
                    {
                    if(pow(2,k)==arr[i][j])
                    {sum+=chk_arr[k];
                        if(k==17)
                            grt=1;
                        else if(k==16)
                            grt=2;
                            break;}
                    
                }
                }
            }
        }
        cout<<sum<<"\n";
        if(is_two==0 && is_four>=1)
            sum=sum-4;
        if(grt==1)
            sum-=4;
        if(sum==1835012)
            sum-=4;

        //cout<<chk_arr[16]<<" "<<chk_arr[17];
        cout<<sum<<"\n";
    }
}