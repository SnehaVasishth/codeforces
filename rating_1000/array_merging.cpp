#include<bits/stdc++.h>

using namespace std;
int main(){
int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector<int>c;
        int size=0,ind=0;
        int i=0,j=0,k=0;
        int maxi=INT_MIN;
        while(i<n && j<n){
            if(a[i]==a[i+1]|| a[i]==b[j-1]||a[i]==b[j]||a[i]==a[i-1]){
                c.push_back(a[i]);
                i++;
              
               
            }
            else if(b[j]==a[i-1]|| b[j]==b[j+1]|| b[j]==a[i]||b[j]==b[j-1]){
                c.push_back(b[j]);
                j++;
                
            }
            else{
                c.push_back(a[i]);
                i++;
               
            }
            if(k==0){
                size=1;
                maxi= max(maxi,size);
                
            }
            else if(k>0 && c[k]==c[k-1]){
                                size=k-ind+1;
                                maxi=max(maxi,size);
                               
            }
            else if(k>0 && c[k]!=c[k-1]){
                ind =k;
                size=k-ind+1;
                maxi=max(maxi,size);
                
            }
            k++;
        }
        while(i<n){
            c.push_back(a[i]);
            i++;
           
            if((k)==0){
                size=1;
                maxi= max(maxi,size);
            }
            else if(k>0 && c[k]==c[k-1]){
                                size=k-ind+1;
                                maxi=max(maxi,size);

            }
            else if(k>0 && c[k]!=c[k-1]){
                ind =k;
                size=k-ind+1;
                maxi=max(maxi,size);
            }
            k++;
        }
         while(j<n){
            c.push_back(b[j]);
            j++;
            
            if(k==0){
                size=1;
                maxi= max(maxi,size);
                
            }
            else if(k>0 && c[k]==c[k-1]){
                                size=k-ind+1;
                                maxi=max(maxi,size);
                                


            }
            else if(k>0 && c[k]!=c[k-1]){
                ind =k;
                size=k-ind+1;
                maxi=max(maxi,size);
                
            }
            k++;
          
        }
        for(auto it:c){
            cout<<it<<"  ";
        }
         
        cout<<"\n"<<maxi<<"\n";
    }
}