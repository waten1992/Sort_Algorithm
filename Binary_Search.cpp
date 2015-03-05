/**
二分查找
 */
#include <iostream>
#include <algorithm>
using namespace std;


int Binary_search(int a[] , int n,int x )
{
    int low = 0 , high =n-1 , mid ;
    while(low <= high)
    {   mid = low + (high-low)/2; //防止溢出
        if(a[mid] == x)
            return mid;
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
void Selection_Sort(int a[] , int n )
{
    for(int i = 0 ; i < n ;i++)
    {
        int Tmp = i ;
        for(int j = i+1 ; j < n; j++)
            if(a[i] > a[j])
                i = j;
        if(Tmp != i)
        swap(a[Tmp] , a[i]);
    }
}
int main()
{
    int a[] = {9,3,5,2};
    int len = sizeof(a)/sizeof(a[0]);

    Selection_Sort(a,len);
    for(int i = 0 ; i < len ; i++)
        cout<<a[i]<<endl;
    cout<<"------::"<<Binary_search(a,len,6);
    return 0 ;
}

/*
The answer as follow--->
2
3
5
9
------::0
Process returned 0 (0x0)   execution time : 0.031 s
Press any key to continue.
*/
