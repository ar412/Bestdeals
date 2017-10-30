  cin>>A>>a;

    for (int i = 0; i < A.length(); ++i)
    {
        int n=A[i]-'0';

        if(k!=0)
            n+=k;

        s+=n/a+'0';

        if(n%a!=0)
            k=n%a*10;
        else k=0;
          if(n<a)
            {
                k=n*10;
                continue;
            }
    }
    cout<<s;


  