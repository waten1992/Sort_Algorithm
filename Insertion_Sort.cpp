/**
插入排序：
把没有拍好序的值，插入到排好序的中间。
 */
#include <iostream>
#include <algorithm>
using namespace std;


void Insertion_Sort(int a[] , int n )
{
    int i , j ;
    for(i = 1 ; i < n ; i++)
    {
        int Tmp = a[i];
        for( j = i-1 ; j >= 0 && a[j] > Tmp; j--) //把无序的数值 插入到有序中
            a[j+1] = a[j];
        
        a[j+1] = Tmp;
    }

}
int main()
{
    int a[] = {9,3,5,2};
    int len = sizeof(a)/sizeof(a[0]);
    Insertion_Sort(a,len);
    for(int i = 0 ; i < len ; i++)
        cout<<a[i]<<endl;

    return 0 ;
}

/*

2
3
5
9

Process returned 0 (0x0)   execution time : 0.032 s
Press any key to continue.
*/
