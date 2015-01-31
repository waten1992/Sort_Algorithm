#if 1
/*
最大堆排序 ，基于数组排序
2014年 阿里巴巴在线笔试题
描述：编写一个函数，输入一个二叉树，返回二叉树的最大值和最小值的  差值的绝对值
解法：如果是纯算法题,
1-进行一次大根堆的筛选 选出最大值 MAX； 
2-进行一次小根堆的筛选 选出最小值 MIN； 
3-返回abs(MAX - MIN);

时间复杂度为O(LogN);

但是必须要指出这个在工程上最好不要这么做，因为如果需求一变，你的代码就不行了；
最好还是先排序，在求任意的值的差值
*/
#include<stdio.h>
#include<stdlib.h>
#define LeftChild(i) ( 2*i + 1 ) //为左孩子，因为数组的下标从0开始的，当 i = 0 ，2×i+1 = 1 ,所以是成立的
// 下标 i = 0 存储是最大的值 ， 所以leftchild 是 2×i + 1 ；
void PercDown(int a[] , int i , int n) //最小的下滤，求最大的堆
{
    int child , temp ;
    for( temp = a[i] ; LeftChild(i) < n ; i = child )
    {
        child = LeftChild(i); //孩子节点
        if ( (child != n -1) && (a[child+1] > a[child]) ) //选择最大的孩子节点，
            child++;
        if( temp < a[child] ) //如果 孩子节点大于 父节点
            a[i] = a[child] ; //把孩子节点赋值给  父节点
        else
            break;
    }
    a[i] = temp ;// 如果 存在孩子节点大于祖先节点  就把祖先节点赋值给孩子节点  因为i目前变成孩子节点的下标； 
                 //如果不存在  也就保持不变
}

void PercUp(int a[] , int i , int n) //最小的上滤 ，选出最小的节点
{
    int child , temp ;
    for( temp = a[i] ; LeftChild(i) < n ; i = child )
    {
        child = LeftChild(i);
        if ( (child != n -1) && (a[child+1] < a[child]) ) //选择最小的节点 若右孩子小于左孩子，所以要用右孩子去和根节点比较
                child++;
        if( temp > a[child] ) //如果 孩纸节点  比父节点更小
            a[i] = a[child] ;//把最小的孩子  赋值给父节点
        else
            break;
    }
    a[i] = temp ; //把祖先节点 赋值给当前的子的节点
}

void Swap(int *a , int *b)
{
    int *Tmp ;
    *Tmp = *a ;
    *a = *b ;
    *b = *Tmp ;
}
int HeapSort(int a[] ,int n )
{
    int i , Tmp_Larger ,Tmp_Smaller ;
    for(i = n/2 ; i >= 0 ; i-- ) // n/2 标号最大分支节点，即最大的非叶子节点标号 ；
        PercDown(  a , i , n ); //求最大堆，采用下滤，使最大的浮上来
    #if 0
    printf("The first build large heap:\n");
    for(i = 0 ; i < n ; i++ )
        printf("%d \t" , a[i]);
        printf("\n");
    #endif
    Tmp_Larger = a[0];
    printf("larger : %d \n" ,a[0]);
    #if 0 //this code for heap sort
    for(i = n -1 ; i > 0 ; i-- )
    {
        Swap( &a[0] , &a[i] ) ;  //本代码 堆排序是数组从下标0开始的 ,堆的最后元素和堆的首元素交换 ，仅仅用一个数组就可以排序
        PercDown(a , 0 , i ) ;
    }
    #endif
     for(i = n/2 ; i >= 0 ; i-- ) // n/2 标号最大分支节点，即最大的非叶子节点标号 ；
        PercUp(  a , i , n ); //求最小堆，采用上滤，使最小的浮上来
    #if 0
    printf("The first build smaller heap:\n");
    for(i = 0 ; i < n ; i++ )
        printf("%d \t" , a[i]);
        printf("\n");
    #endif
    Tmp_Smaller = a[0];
    printf("smaller : %d \n" ,a[0]);
    return abs(Tmp_Larger - Tmp_Smaller);
}

int main()
{   int a[] = {31,41,59,26,53,58,97,-1,100}; //测试数组
    int len , i ;
    len = sizeof(a)/sizeof(int);
    i = HeapSort( a , len );  //建立堆
    printf("This is a HeapSort Data: %d\n",i);


  #if 0
    for(i = 0 ; i < len ; i++ ) //遍历已经拍好序的数组
        printf("%d \t" , a[i]);
  #endif
    return 1;
}
#endif


/*
 *  链表实现，维持二叉树优先堆：最大堆 和  最小堆
 *
 *
 */
