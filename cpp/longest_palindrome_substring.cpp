/*input
THIS IS A TEST TEXT
TEST
*/
/***************************
 * THIS PROBLEM HAS A BETTER SOLUTION WITH O(1) SPACE
    BY TAKING 2N-1 CENTRES
 */
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 std::vector<vector<string> > dp;
string re(string s,int x,int y)
{	
	cout<<"\n";
	cout<<x<<" "<<y<<" ";
    int i=x,j=y,c=1;
    string a;
    
    if(i>=s.length() || j<0)
        {cout<<"lol ";
    return "";}

    if(dp[x][y]!="-1")
    	{
    		cout<<" dp ";
    		return dp[x][y];}
        
    while(s[i]==s[j])
    {
        c++;
        i++;
        j--;
        
        if(i>j)
            {
                for(int i=x;i<=y;i++)
                	a+=s[i];
               {//cout<<"yess "<<a;
                return dp[x][y]=a;}
            } 
    }
    
    string s1=re(s,x+1,y);
    string s2=re(s,x,y-1);
    
    cout<<"\ndobaara ";
    cout<<x<<" "<<y<<" "<<s1<<" "<<s2;
    
    if(s1.length()>s2.length())
       {cout<<" * "<<s1; return dp[x][y]=s1;}
    else {cout<<" $ "<<s2;return dp[x][y]=s2;}
    
}


string longestPalindrome(string A) {
	    int N=A.length();
     dp.resize(N,vector<string> (N,"-1"));
     cout<<"\nmain ans== "<<re(A,0,A.length()-1);
    return "fvjfv";
}

int main()
 {
    ios_base::sync_with_stdio(0);


    string a="aaaabaaa";

  	longestPalindrome(a);
    return 0;

 }