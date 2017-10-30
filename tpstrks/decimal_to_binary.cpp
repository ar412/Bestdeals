string db(int n)
{

  string a;
  while(n>0)
  {
     //cout<<pow(10,i)<<" "<<n<<" "<<a<<"\n";
    a+=(n%2)+'0';
    n/=2;
  
   //cout<<n%2<<" "<<n<<" "<<a<<"\n\n";
  
  }
  if(s.length()==0)
      s+='0';
  reverse(a.begin(), a.end());
  return a;
}