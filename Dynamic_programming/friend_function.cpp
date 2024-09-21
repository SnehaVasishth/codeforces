#include<bits/stdc++.h>

using namespace std;

 class employee { 
    
    private: 
    int salary=0;
    
    friend void sal(employee e); 
    
    
    };
    
     void sal(employee e) 
     
     { 
    
        e.salary=1000;
        cout<<e.salary<<"\n";
         
         
          }


int main() 
 
 {
    
     employee e; 
     sal(e);
     
      }