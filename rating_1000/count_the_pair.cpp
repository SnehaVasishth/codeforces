#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(26,0);
        vector<int>b(26,0);
        int ans=0;
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            if(x>=97 && x<=122){
                a[x-'a']++;

            }
            else if(x>=65 && x<=90){
                b[x-'A']++;
            }

        }

        for(int i=0;i<26;i++){
            if(a[i]>=1 && b[i]>=1){
                int o=min(a[i],b[i]);
                ans= ans+ o;
                a[i]=a[i]- o;
                b[i]=b[i]- o;
                
            }
        }
        if(k>0){
            for(int i=0;i<n && k>0;i++){
                
                if(a[i]>=2){
                   
                    int pair=a[i]/2;
                    if(pair<=k){
                        a[i]=a[i]-2*pair;
                        k=k-pair;
                        ans=ans+pair;
                       
                    }
                    else{
                        pair=k;
                        k=0;
                        a[i]=a[i]-2*pair;
                        ans=ans+pair;
                        
                    }
                }
                else if(b[i]>=2){
                    
                     int pair=b[i]/2;
                     if(pair<=k){
                        b[i]=b[i]-2*pair;
                        k=k-pair;
                        ans=ans+pair;
                        
                    }
                    else{
                        pair=k;
                        k=0;
                        b[i]=b[i]-2*pair;
                        ans=ans+pair;
                       
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
