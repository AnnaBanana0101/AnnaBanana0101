//CodeChef That's My Score; Problem Code: WATSCORE

#include<iostream>
using namespace std;

int main()
{
    int m, k;
    cin>>m;
    for(k=0; k<m; k++)
    {
        int a[1000][2]; //array to store the inputs
        int b[11]; //array to store the maximum score for each question number
        int i, j, n, x, sum=0;

        cin>>n; //input the number of questions 
        for(i=0; i<=11; i++)
        b[i]=0; //initialize the max score of each question to 0

        for(i=0; i<n; i++)
        for(j=0; j<2; j++)
        cin>>a[i][j]; //input

        for(i=0; i<n; i++)
        {
            for(x=0; x<=11; x++) //question numbers
            {
                if(a[i][0]==x) //if the question number appears in the input given
                {
                    if(x<9)
                    {
                        if (a[i][1]>b[x]) //if the score corresponding to the question number is greater than the previously encountererd score
                        b[x]=a[i][1];
                    }
                    else
                    b[x]=0;
                }
            }
        }

        for(i=0; i<=11; i++)
        {
            sum=sum+b[i];
        }

        cout<<sum<<endl;
    }
    return 0;
}