#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    
	
	int x,y,z;
	cin>>x>>y>>z;
	
	ll rec= x*y;
	ll sqr= z*z;
	if(rec<=sqr)
	{
	    cout<<0<<"\n";
	}
	else if((x>z) && (y>z)){
	    
	    int maxi= max(x,y);
	    int mini= min(x,y);
	    
	    if(mini>sqr){
	        cout<<2<<"\n";
	    }
	    else{
	        cout<<1<<"\n";
	    }


}
else{
    cout<<1<<"\n";
}
}

}