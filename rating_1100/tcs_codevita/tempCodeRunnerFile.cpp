   int newi =  moveup(i,j,matrix,n,m,step1);
  
   if(newi!=(i-1)){
    up= step1+ solve(newi,j,destrow,destcol,matrix,dp,n,m,vis)+step;
   }