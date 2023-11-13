#include<bits/stdc++.h>

using namespace std;
 int main(){
    long long int sneha;
    cin>>sneha;
    while(sneha--){
        long long int n,k,a,b;
        cin>>n>>k>>a>>b;
        pair<pair<long long int,long long int>,long long int>one;
        pair<pair<long long int,long long int>,long long int>last;
        set<pair<pair<long long int,long long int>,long long int>>s;
        for(long long int i=0;i<n;i++){
            pair<pair<long long int,long long int>,long long int>p;
            cin>>p.first.first;
            cin>>p.first.second;
            p.second=i+1;
            s.insert(p);
            if((i+1)==a){
                one=p;
            }
            if((i+1)==b){
                last=p;
            }
        }
       
        auto it1= s.find(one);
        auto it2= s.find(last);
        long long int hai=(abs(one.first.first-last.first.first)+ abs(one.first.second-last.first.second));
        
        if(one.second<=k && last.second<=k){
            cout<<0<<"\n";
        }
        else if(k<=1){
           
            cout<<hai<<"\n";
        }

        else if(k>1){
            auto it3=it1;
            auto it4= it2;
            it3++; it4++;it4++;
            long long int mini=INT_MAX;
            long long int mini1=INT_MAX;
            long long dist;
            long long int ans;
            long long int ans2;
            for(it3;it3!=s.end();it3++){
                if(it3->second<=k || it3==it2){
                  ans  = it3->first.first;
                   ans2 = it3->first.second;
                    if(one.second>k)
                    dist= (abs(ans-one.first.first)+abs(ans2-one.first.second));
                   else{
                    dist=0;
                   }
                

                    mini= min(mini,dist);
                }
                    
                    if(it3!=it2){
                        if(last.second>k)
                    dist= (abs(ans-last.first.first)+abs(ans2-last.first.second));
                    else{
                        dist=0;
                    }
                    mini1=min(mini1,dist);
               
                    }

                                  


            }
            if(mini!=mini1){
                long long int aaa=mini+mini1;
            cout<<min((aaa),hai)<<"\n";
            }
           
        }
        else{
             cout<<hai<<"\n";
        }
        
    }
}