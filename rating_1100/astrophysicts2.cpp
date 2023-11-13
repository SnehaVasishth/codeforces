#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,g;
        cin>>n>>k>>g;
        ll no_of_people;
        if(k==0 || g==0){
            cout<<0<<"\n";
        }
        else{
        ll dist= k*g;
        int target= ceil(g/2)-1;
        if(target >=1){
        no_of_people= (dist)/target;
        }
        else 
        no_of_people= (dist)/(target+1);

        ll amount_to_give;
        ll no_of_people_left;
        ll amount_left;
        if(no_of_people< n){
            amount_to_give= no_of_people * target;

            no_of_people_left= n - no_of_people;
            amount_left= k*g - amount_to_give;

        }
        else if (no_of_people>=n){

            no_of_people= ((n-1) > 0)? (n-1) : n;
           target= (n==1)? dist : target;
            no_of_people_left= (n==1)? 0  : (n-1);
            amount_to_give= target * no_of_people;
            amount_left= k*g- amount_to_give;
        }

        int r= target % g;
        ll give=0, save=0, total=0;

       
        if(r>=ceil(g/2)){
            give= (target+(g-r))* (no_of_people);
            save= amount_to_give - give;
            total+=save;

            
        }
         else{
            give= (target- r) * (no_of_people);
            save= amount_to_give - give;
            total+=save;

        }
        target= amount_left;
        no_of_people=1;
        amount_to_give= amount_left;
        r= target%g;
        
        if(r>=ceil(g/2) && no_of_people_left>0){
            give= (target+(g-r))* (no_of_people);
            save= amount_to_give - give;
            total+=save;

            
        }
        else if (no_of_people_left>0){
            give= (target- r) * (no_of_people);
            save= amount_to_give - give;
            total+=save;

        }

        total= (total<0)? 0 : total;

cout<<total<<"\n";
        }

    }
}