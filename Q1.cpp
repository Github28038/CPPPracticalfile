#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n,i=1;
    float sum = 0;
    cout<<"Enter Length of the series : ";
    cin>> n ;
    while (i<=n)
    {
        if (i%2==0)
        {
            sum =sum-1/pow(i,i);
        }

        else
        {
            sum= sum +1/pow(i,i);
        }

        i++;
    }
    cout<<sum;
    return 0;
}
