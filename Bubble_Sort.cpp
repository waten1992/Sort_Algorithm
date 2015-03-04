/**
冒泡排序：
每一趟选出一个最小的元素出来
 */
#include <iostream>
#include <algorithm>
using namespace std;

void Bubble_Sort(int a[] , int n)
{
    for(int i = 0 ; i < n-1 ; i++)
        for(int j = i+1 ; j < n ; j++)
        {
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
}

int main()
{
    int a[] = {9,3,5,2};
    int len = sizeof(a)/sizeof(a[0]);
    Bubble_Sort(a,len);
    for(int i = 0 ; i < len ; i++)
        cout<<a[i]<<endl;

    return 0 ;
}

/*
2
3
5
9

Process returned 0 (0x0)   execution time : 0.050 s
Press any key to continue.
*/

