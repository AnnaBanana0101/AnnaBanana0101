//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int pairCubeCount(int N) 
    {
        int sum;
        int a, b;
        int count=0;
        
        for(a=1; a<=cbrt(N); a++)
        {
            /*while(0<=b<=cbrt(N-1))
            {
                sum= a*a*a+b*b*b;
                
                if(sum==N)
                {
                    count++;
                }
            }*/
            
            int diff=N-a*a*a;
            int cbrtDiff= cbrt(diff);
            
            if(cbrtDiff*cbrtDiff*cbrtDiff==diff)
            {
                count++;
            }
            
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.pairCubeCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends