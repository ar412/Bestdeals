/*input
5
5
1 2
1 5
2 3
2 4
4 4
*/

#include <iostream>
#include <string.h>
// #define ll long long int
#define mod 1000000007
using namespace std;

bool util(int u,int **arr,int *vis,int stc,int n)
{
    
        vis[u]=1;
        // stc[u]=1;
        for (int i = 1; i <=n; ++i)
        {
            if(arr[u][i]==1)
            {
                if(!vis[i])
                {
                    if( util(i,arr,vis,u,n))
                    return 1;
                }
                else if(stc!=i)
                        return 1;
            }
        }
    
    // stc[u]=0;
    return 0;
}


bool cycle(int **arr,int n)
{

    int *vis=new int [n+1];
    // int *stc=new int [n+1];
    memset(vis,0,sizeof(vis));
    // memset(vis,0,sizeof(stc));

    for (int i = 1; i <= n; ++i)
    {
        if(vis[i]==0)
        if(util(i,arr,vis,-1,n))
            return 1;
    }
    
    return 0;
}

int main()
 {
    
   
    int n,m;
    cin>>n;
    int **arr=new int *[n+1];

    for(int i = 0; i <=n; i++)
        arr[i] = new int[n+1];

    memset(arr,0,sizeof(arr));
   
    int k;
    cin>>k;
    
    for (int i = 0; i < k; ++i)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }

    if(cycle(arr,n))
        cout<<1;
    else cout<<0;

   
    //   for (int i = 1; i <=n; ++i)
    // {
    //     for (int j = 1; j<=n; ++j)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<0;
    return 0;
 }