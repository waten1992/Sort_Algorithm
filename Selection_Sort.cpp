/**
选择排序：每次选择一个最小的放在当前的位置，直到排完
 */
#include <iostream>
#include <algorithm>
using namespace std;


void Selection_Sort(int a[] , int n )
{
    int i , j ;
    for(i = 0 ; i < n ; i++) //每一趟只选 一个最小的放在当前的位置
    {
        int Tmp = i; //初值
        for( j = i ; j < n; j++) 
            if(a[i] > a[j])
                i = j; //只变下标
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

    return 0 ;
}

/*
The answer as follow--->
2
3
5
9

Process returned 0 (0x0)   execution time : 0.024 s
Press any key to continue.
*/
