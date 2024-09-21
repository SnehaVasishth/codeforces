#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll row,col,x0,y0,l;
	    cin>>row>>col>>x0>>y0>>l;
	    // cout<<"hii  "<<row<<"  "<<col<<"\n";
	    
	    queue<pair<ll,ll>>q;
	//    vector<vector<ll>>visited(row+1,vector<ll>(col+1,0));
     set<pair<ll,ll>>st;
	//    ll a=-1*l;
	   vector<ll>dx(4),dy(4);
	   
    dx[0]=l;
    dx[1]= -1*l;
    dx[2]=0;
    dx[3]=0;
    dy[0]=0;
    dy[1]=0;
    dy[2]=-1*l;
    dy[3]=l;
    
	    
	   
	    
	    q.push({x0,y0});
	    // visited[x0][y0]=1;
        st.insert({x0,y0});
	    ll cnt=1;
	    
	    while(!q.empty()){
	        ll x_row=q.front().first;
	        ll y_col=q.front().second;
	        
             cout<<"sneha  "<<x_row<<"  "<<y_col<<"\n";
	        
	        q.pop();
	        
	        for(ll i=0;i<4;i++){
	            ll x=x_row+dx[i];
	            ll y=y_col+dy[i];
	            // cout<<"daksh  "<<x<<"  "<<y<<"\n";
	            if( x>=1 && x<=row && y>=1 && y<=col && (st.find({x,y})==st.end())){
	                q.push({x,y});
	              st.insert({x,y});
	                cnt++;
	                // cout<<"cont  "<<cnt<<"\n";
	            }
	        }
	    }
	   
	    
	  cout<<  "ans  "<<cnt<<"\n";
	    
	    
	    
	}

}
