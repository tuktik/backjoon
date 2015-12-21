#include<iostream>
#include<stdio.h>
using namespace std;
 
double numArr[10010];
 
int main()
{
    int testNum;
    cin>>testNum;
    double* sumArr=new double[testNum];
    for(int i=0;i<testNum;i++)
    {
        cin>>numArr[i];
        sumArr[i]=0;
    }
    sumArr[0]=numArr[0];
    double result=sumArr[0];
    for(int i=1;i<testNum;i++)
    {
        sumArr[i]=max(numArr[i],numArr[i]*sumArr[i-1]);
        if(sumArr[i]>result)
            result=sumArr[i];
    }
    printf("%.3f",result);
     
     
    return 0;
}
