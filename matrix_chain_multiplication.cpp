#include<iostream>
using namespace std;
int s[50][50];
void print_optimal(int i,int j)
{if(i==j)
  cout<<" A"<<i<<" ";
else
{ cout<<"( ";
print_optimal(i,s[i][j]);
print_optimal(s[i][j]+1,j);
cout<<" ) ";
}
}

int main()
{
  int i,n,j,min,val,k;
  cout<<"Enter the number of matrices"<<endl;
  cin>>n;
  int a[n+1][3];
 cout<<"Enter the order of each matrix"<<endl;
  for(i=1;i<=n;i++)
    for(j=1;j<=2;j++)
       cin>>a[i][j];
  int d[n+1];
  for(i=0,j=1;i<n;i++,j++)
    d[i]=a[j][1];
  d[n]=a[n][2];
cout<<" The d matrix is "<<endl;
for(i=0;i<n+1;i++)
cout<<d[i]<<"\t";
cout<<endl;
  int m[n+1][n+1],diag;
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
    m[i][j]=0;
for(diag=1;diag<=n-1;diag++)
   {
    for(i=1;i<=n-diag;i++)
      {
        j=i+diag;
        min=999;
        for(k=i;k<=j-1;k++)
        { val=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
          if (val<min)
          {
            min=val;
            s[i][j]=k;
          }
        }
        m[i][j]=min;
    }
  }
  cout<<"The minimum number of Multiplications required is - "<<m[1][n]<<endl;
  for(i=1;i<=n;i++)
   {
    for(j=1;j<=i;j++)
    { s[i][j]=0;
      m[i][j]=0;
    }
   }
cout<<"--- The computation number matrix (M TABLE)--- "<<endl;
  for(i=1;i<=n;i++)
   {
    for(j=1;j<=n;j++)
cout<<m[i][j]<<"\t";
    cout<<endl;
  }
cout<<"--- The Solution number matrix (S TABLE)--- "<<endl;
  for(i=1;i<=n;i++)
   {
    for(j=1;j<=n;j++)
    cout<<s[i][j]<<"\t";
    cout<<endl;
  }

cout<<"The optimal solution is ";
print_opti(1,n);
 return 0;
}