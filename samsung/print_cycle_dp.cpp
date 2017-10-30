/*input
6 7
1 6
1 2
5 6
6 4
2 4
4 3
3 5
*/

#include <iostream>
#include <string.h>
// #define ll long long int
#define mod 1000000007
using namespace std;

void print_cycle (int *vis,int *stc,int x)
{
    int i,j,c;
    c=1;j=x;
    while(stc[j]!=x)
    {
        j=stc[j];
        c++;
    }
    int *a=new int [c];
    j=x;i=0;
    while(stc[j]!=x)
    {
        a[i]=stc[j];
        j=stc[j];
        i++;
    }
    a[i]=stc[j];
    for (int i = 0; i <c/2; ++i)
    {
        swap(a[i],a[c-i-1]);
    }
    for (int i = 0; i < c; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

bool util(int u,int **arr,int *vis,int *stc,int n,int p)
{
    if(vis[u]==0)
    {
        vis[u]=1;
        stc[u]=p;
        for (int i = 1; i <=n; ++i)
        {
            if(arr[u][i]==1)
            {
                if(!vis[i] && util(i,arr,vis,stc,n,u))
                    return 1;
                else if(vis[i] && stc[i]!=0)
                       { 
                        stc[i]=u;
                       print_cycle(vis,stc,i);                     
                        return 1;}
            }
        }
    }
    stc[u]=0;
    return 0;
}


bool cycle(int **arr,int n)
{

    int *vis=new int [n+1];
    int *stc=new int [n+1];
    int *ans;
    memset(vis,0,sizeof(vis));
    memset(vis,0,sizeof(stc));

    for (int i = 1; i <= n; ++i)
    {
        if(util(i,arr,vis,stc,n,-1))
           {
            int c=0;
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
            return 1;}
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
    }
    cout<<arr[1][1];
    // cycle(arr,n);
    // for (int i = 1; i <=n; ++i)
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