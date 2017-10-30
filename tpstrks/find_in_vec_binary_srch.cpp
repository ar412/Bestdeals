 
int s=20;
v[]={10,20,20,30}

auto it =lower_bound(v.begin(),v.end(),s); 
        
        a=it-v.begin();


s=20 -> a=1
s=25 -> a=3
s=30 -> a=3
 

 auto it =upper_bound(v.begin(),v.end(),s);
        a=it-v.begin();

s=20 -> a=3
s=25 -> a=3
s=30 -> a=4

