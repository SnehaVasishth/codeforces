#include <iostream>
 using namespace std;


 class Test {
    
     private: 
     int count; 
     public: 
     Test( )
     {
        count=21;
         //writing function name followed by data member and passed on value works like constructor // Test(): count(101) same as writing count = 101; here
      } // we write operator before overloading such operators
      void operator ++( ) {
        
         count = count+100; 
         
         } 
         
         void Display( ) 
         { cout << "Count: " << count; 
         
         }
         
          }; 
          
          int main( ) 
          { Test t; // this calls function “void operator ++()"
           ++t; 
           t.Display( );
           
            return 0; 
            
            }