/*input
15 1 2 3 4 5 9 10 8 -1 6 7 -1 -1 -1 -1
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int fib1(int n)
{
  int f[n+1];
  int i;

  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}
int fib(int n)
{
  int a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}

int main()
 {
    ios_base::sync_with_stdio(0);

   	// cout<<fib1(12000)<<"\n";
   	// cout<<fib(12000);
   	int i =0;
while(i<=3)
{
    int j=0;
    while(j <= i)
    {
        switch(j)
        {
            case 2:
                j = j * 2;
                break;

            case 3:
                j = j * 6;
                break;

            default:
                j++;
        }

        int k = 1;
        while(k < j)
        {
            k = k * 2;
            if(k > 3)
                continue;

            printf("%d ", k);
        }

        printf("%d ", j);
    }
    i++;
}

    return 0;

 }