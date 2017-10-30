/*input
-2147483648  
-10000000
*/


#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int divide(int dividend, int divisor) {
    unsigned int n=abs(dividend);
    unsigned int d=abs(divisor),s;
    if(dividend<0 && divisor<0 || dividend>0 && divisor>0)
        s=0;
    else s=1;
    // if(d==1)
    //     return n;
    int t=n-d,a=0;
     cout<<a<<" n "<<n<<" "<<d<<" "<<t<<" "<<s<<"\n";
    while(t>=0)
    {
        a+=1;
        a+=a>>1;
        n=n>>1;
        t=n-d;
        cout<<a<<" "<<n<<" "<<t<<"\n";
    }
    if(s==0)
    return a;
    else return -a;
    
 }
int divide2(int dividend, int divisor) {
    // unsigned int nu=fabs(dividend);
    // unsigned int de=abs(divisor),s;
    long long int n,d;
    int s;
    n=(ll)dividend;
    d=(ll)divisor;

    if (n<0)
        n=-1*n;
    if(d<0)
        d=-1*d;



    if(dividend<0 && divisor<0 || dividend>0 && divisor>0)
        s=0;
    else s=1;
    ll t=n-d;
    int q=0;
    cout<<n<<" "<<d<<" "<<t<<"\n\n";
  
    while(t>=0)
    {
        q+=1;
        n=t;
        n=n>>1;
        t=n-d;
        cout<<n<<" "<<q<<" "<<t<<"\n";
    }
    if(s==1)
        q=-1-q;

    return q;

}


int main() {
  
   int n,d;
  
  cin>>n>>d;
 
   
    
  cout<<divide2(n,d);
    
    
    return 0;
}
