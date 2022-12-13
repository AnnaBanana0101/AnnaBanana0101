//GCD of an array of N numbers

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int gcd(int N, int arr[])
    {
    	
    	int gcd=arr[0], gcd_temp;
    	int rem;
    	int next;
    	if(N==1)
    	{
    	  return arr[0];  
    	}
    	else
    	{
        	for(int i=0; i<N-1; i++)
        	{
        	    gcd_temp = gcd;
        	    next = arr[i+1];
        	    
        	    while(next!=0)
        	    {
        	        rem=gcd_temp%next;
        	        gcd_temp=next;
        	        next=rem;
        	    }
        	    gcd=gcd_temp;
        	}
        	return gcd;
    	}
    	
    }
};


//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}
// } Driver Code Ends