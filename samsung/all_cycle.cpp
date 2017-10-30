/*input
5 6
1 2
2 3
3 1
3 5
4 3
5 4
*/

#include <iostream>
#include <string.h>
// #define ll long long int
#define mod 1000000007
using namespace std;

void print_cycle (int *ans,int k)
{
    for (int i = 0; i <k; ++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

bool util(int u,int start,int k,int n,int **g,int *vis,int *ans)
{
        
        vis[u]=1;
        ans[k]=u;
        k++;

        for (int i = 1; i <=n; ++i)
        {
            if(g[u][i]==1 && i>=start)
            {
                if(!vis[i] && util(i,start,k,n,g,vis,ans))
                    return 1;
                else if(vis[i] && i==start)
                       { 
                        // stc[i]=u;
                        print_cycle(ans,k);                     
                        return 1;
                    }
            }
        }
        
        k--;
        vis[u]=0;
        return 0;
}


bool cycle(int **g,int n)
{

    int *vis=new int [n+1];
    int *ans=new int [n+1];
    // int *ans;
    memset(vis,0,sizeof(vis));
    // memset(vis,0,sizeof(stc));

    for (int i = 1; i <= n; ++i)
    {
        if(util(i,i,0,n,g,vis,ans))
           {
            // int c=0;
            // for (int j = 1; j <=n; ++j)
            // {
            //     if(stc[j]!=0)
            //         c++;
            // }
            //  ans=new int[c];
            //             int x=0,y=1;
            //             while(x<c && y<=n)
            //             {
            //                 if(stc[y]!=0)
            //                 {
            //                     ans[x]=y;
            //                     y++;
            //                     x++;
            //                 }
            //                 else y++;
            //             }
            // for (int j = 0; j < c; ++j)
            // {
            //     cout<<ans[j]<<" ";
            // }
            // cout<<"\n";
            // return 1;
           }
    }
    
    return 0;
}

int main()
 {
    
   
    int n;
    cin>>n;
    int **g=new int *[n+1];

    for(int i = 0; i <=n; i++)
        g[i] = new int[n+1];

    memset(g,0,sizeof(g));
    int k;
    cin>>k;
    
    for (int i = 0; i < k; ++i)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
    }

    cycle(g,n);
    // for (int i = 1; i <=n; ++i)
    // {
    //     for (int j = 1; j<=n; ++j)
    //     {
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    // cout<<0;
    return 0;
 }