//Find the largest prime factor of the given number
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N)
    {
        int num, rem;
        int flag;
        int root= sqrt(N);
        int factor;
        
        for (int i=2; i<=N; i++)
        {
            if (N%i==0)
            {
                flag=0;
                for (int j=2; j<i; j++)
                {
                    if (i%j==0)
                    {
                        flag=1;
                    }
                }
                
            }
            else
            {
                flag=2;
            }
            //cout<<"flag: "<<flag<<endl;
            
            
            //cout<<"flag: "<<flag<<endl;
            
            if(flag==0)
            {
                factor = max(factor, i);
            }
        }
        
        return factor;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends