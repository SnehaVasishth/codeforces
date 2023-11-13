#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count_a=1;
        int count_a_w=1;
        int count_b=0;
        int count_b_w=0;
for(int i=1;i<=n;){
    if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            int x= n-count_a -count_b;
            count_b= n- count_a;
            count_b_w= count_b_w+ (x/2);
            break;
        }
        else{
            count_b+=i;
            count_b_w += (i/2);
            
        }
    }
        else
        break;

        if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            int y= n- count_a - count_b;
            count_b= n- count_a;
            count_b_w= count_b_w+ (y/2);
            break;
        }
        else{
            count_b+=i;
            count_b_w= count_b_w+ (i/2);
            
        }
    }
        else
        break;


        if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            if(i%2==0){
                int z= n- count_b- count_a;
            count_a= n- count_b;
            count_a_w+= (z/2);
            break;
            }
            else{
                int z1=n- count_b- count_a;
                 count_a= n- count_b;
            count_a_w+= ((z1/2)+1);
            break;
            }
        }
        else{
             if(i%2==0){
            count_a+=i;
            count_a_w+= (i/2);
            
            }
                        else{
                  count_a+=i;
            count_a_w+= ((i/2)+1);
            
            }

        }
    }
        else
        break;

        if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            if(i%2==0){
                int z2= n-count_b-count_a;
            count_a= n- count_b;
            count_a_w+= (z2/2);
            break;
            }
            else{
                int z3= n-count_b-count_a;
                count_a= n- count_b;
            count_a_w+= ((z3/2)+1);
            break;
            }
        }
        else{
             if(i%2==0){
            count_a+=i;
             count_a_w+= (i/2);
            
            }
            else{
                  count_a+=i;
                   count_a_w+= ((i/2)+1);
            

            }

        }
    }
        else
        break;
    }
    cout<< count_a_w<<" "<<count_a-count_a_w<<" "<<count_b_w<<" "<<count_b-count_b_w<<"\n";
    

    }
}