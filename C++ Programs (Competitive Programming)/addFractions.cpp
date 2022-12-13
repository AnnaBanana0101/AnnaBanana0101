//Add two fractions and print the reduced output
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void addFraction(int num1, int den1, int num2,
                 int den2);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,resultNum,resultDen;
        cin>>a>>b>>c>>d;
        addFraction(a,b,c,d);

    }
}

// } Driver Code Ends


/*You are required to complete this function*/
int GCD(int n1, int n2)
{
    int rem;
    
    while(n2!=0)
    {
        rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    
    return n1;
}

void addFraction(int num1, int den1, int num2,int den2)
{
    int num_sum, denom;
    int gcd, lcm, n1=den1, n2=den2;
    
    
    
    gcd= GCD(den1, den2);
    
    lcm= den1*den2/gcd;
    
    int q1, q2;
    
    q1=lcm/den1;
    q2=lcm/den2;
    
    num_sum= num1*q1+num2*q2;
    denom=lcm;
    
    int gcd2= GCD(num_sum, denom);
    
    if(gcd2==1)
    {
        cout<<num_sum<<"/"<<denom<<endl;
    }
    else
    {
        num_sum=num_sum/gcd2;
        denom=denom/gcd2;
        cout<<num_sum<<"/"<<denom<<endl;
    }
    
    
}