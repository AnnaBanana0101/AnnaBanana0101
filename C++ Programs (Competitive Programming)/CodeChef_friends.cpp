#include <iostream>
using namespace std;

int main()
 {
	int m, k;
    //cout<<"Enter the test cases: \n";
	cin>>m;

	for(k=0; k<m; k++)
	{
        int n, a[50], b[50], i, c=0;
    
	    
	    //cout<<"Enter the number of friends:\n";
	    cin>>n;
	    //cout<<"Enter the selected days of each:\n";
	    for(i=0; i<n; i++)
	    {
	    cin>>a[i];
	    }
	    for(i=0; i<n; i++)
	{
	    for(int j=0; j!=i; j++)
	    {
	        if(a[i]==a[j])
	        {
	            c++;
	   	    }
	    }
	}
	
	cout<<n-c;
	}
    return 0;
}