if(s1.length()<s2.length())
        swap(s1,s2);
    
    int i=s1.length()-1,j=s2.length()-1,c=0;
    string s;
    while(j>=0)
    {
        if(s1[i]=='1' && s2[j]=='1')
        {
            if(c==0)
            {
            s+='0';
            c=1;
            }
            else{
            s+='1';
            c=1;
            } 
        }
        else if(s1[i]=='1' && s2[j]=='0' || s1[i]=='0' && s2[j]=='1')
        {
            if(c==0)
            {
            s+='1';
            c=0;
            }
            else{
            s+='0';
            c=1;
            }
        }
        else if(s1[i]=='0' && s2[j]=='0')
        {
            if(c==0)
            {
            s+='0';
            c=0;
            }
            else{
            s+='1';
            c=0;
            }
        }
       j--;
        i--;
    }
     while(i>=0)
    {
        if(s1[i]=='1')
        {
            if(c==0)
            {
                s+='1';
                c=0;
            }
            else {
                s+='0';
                c=1;
            }
        }
        else {
            if(c==0)
            {
                s+='0';
                c=0;
            }
            else {
                s+='1';
                c=0;
            }
        }
        i--;
    }

    if(c==1)
        s+='1';
  reverse(s.begin(), s.end());
    return s;