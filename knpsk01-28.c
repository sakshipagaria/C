 #include<stdio.h>
 void knapsack(int W,int n,int val[],int wt[]);
 int Max(int x,int y);
 int main()

{
   int val[]={-1,100,20,60,40};  //val of items
   int wt[]={-1,3,2,4,1};
   
   int n=4;
   int W=5;
   knapsack(W,n,val,wt);
   return 0;
}

 int getMax(int x,int y)
 {
    if(x>y)
      return x;
    else
      return y;
 }
 
 
  void knapsack(int capacity,int n,int val[],int objwt[])
 {
   int i,weight;
   int V[n+1][capacity+1];
   for(weight=0;weight<=capacity;weight++)
   {
    V[0][weight]=0;
   }
 
  for (i=0;i<=n;i++)
   {
    V[i][0]=0;
   }
   for(i=1;i<=n;i++)
   {
    for(weight=1;weight<=capacity;weight++)
      {
       if(objwt[i]<=weight)
        {
          V[i][weight]=getMax(V[i-1][weight],val[i]+V[i-1][weight-objwt[i]]);
        }
       else
        {
          V[i][weight]=V[i-1][weight];
        }
     }
  }

   
   printf("Max value:%d\n", V[n][capacity]);   
}
 





