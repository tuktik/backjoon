#include <iostream>
#include <math.h>
 
using namespace std;
 
int main()
{
    int num;
    int output=1;
    int divNumsize=1;
    int count =0;
    cin>> num;
 
    for(int i =1; i<=num; i++)
    {
        divNumsize = log10((double)i);
        output*=i;
        while(output%10==0)
        {
            output=output/10;
			count++;
        }
        output=output%(int)pow(10.0,divNumsize+1);
    }
 
    cout<<count<<endl;
 
    return 0;
}