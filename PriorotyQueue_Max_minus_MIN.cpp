#include<stdio.h>
#include<malloc.h>

#define MinPQSize 4
#define MinData -1000  //呀结点  相当于链表的头结点
#define MaxData 1000
typedef struct HeapStruct *priorityQueue;
struct HeapStruct
{
    int Capacity ;      //容量
    int Size  ;      // 大小数组的
    int *Elements ; //指向数组的指针
};
priorityQueue Initialize(int MaxElements  ) //初始发堆 ，返回 priorityQueue
{
    priorityQueue H ;
    if( MaxElements < MinPQSize )
    {
         printf(" priority queue size is too small ");
    }

    H = (priorityQueue)malloc(sizeof(struct HeapStruct)) ;
    if ( H == NULL )
    {
       printf(" out of space ! \n ") ;
    }

    H->Elements = (int*)malloc((MaxElements+1)*sizeof(int)); //Allocate the array plus one extra for sentinel
    if ( H->Elements == NULL )
    {
       printf("out of space ! \n");
    }

    H->Capacity = MaxElements ;
    H->Size = 0 ;
    H->Elements[0] = MaxData ;
    printf("Initalize is done \n") ;
    printf("The dummy element is : %d \n",H->Elements[0]);
    return H;
}
int IsFull(priorityQueue H)
{
    return (H->Size == H->Capacity);
}
int  ISEmpty(priorityQueue H)
{
    return ( H->Size == 0);
}
priorityQueue Insert(int x , priorityQueue H)
{
    int i ;
   #if 1
    if (IsFull((H)))
    {
        printf("prioity queue is full \n");
        return NULL;
    }
    #endif
    for(i = ++H->Size; H->Elements[i/2] < x ; i /= 2)
        H->Elements[i] = H->Elements[i/2] ;

    H->Elements[i] = x ;

    printf("The Current Inner Max_element is : %d \n",H->Elements[1])  ; //for test !
    return H;
}


priorityQueue Insert_SmallerHeap(int x , priorityQueue H)
{
    int i ;
   #if 1
    if (IsFull((H)))
    {
        printf("prioity queue is full \n");
        return NULL;
    }
    #endif
    for(i = ++H->Size; H->Elements[i/2] > x ; i /= 2)
        H->Elements[i] = H->Elements[i/2] ;

    H->Elements[i] = x ;  // store the current MINDataH->Elements[2]

    printf("The Current Inner Min_element is : %d \n",H->Elements[1])  ; //for test !
    return H;
}


int main()
{
    priorityQueue HH;
    HH =  Initialize(18);
    int a[] = {31,-3,41,59,26,53,58,97,-9};
    int len = sizeof(a)/sizeof(int); //数组的长度
    int MIN , MAX ;
    printf("The array length is : %d \n",len);

    for(int i = 0 ; i < len; i++)
         Insert(a[i],HH);

    printf("The First build priortyQueue Largest is: %d \n",HH->Elements[1]); //for test !
    MAX = HH->Elements[1] ;
#if 0 //for test ! Output the priortyQueue
    for(int ii = 0 ; ii <= len ; ii++)
        printf("The element is : %d , the Index is : %d\n",HH->Elements[ii] ,ii )  ;
#endif

    HH->Elements[0] = MinData ; //change the dummy node vaule;

    for(int i = 1 ; i <= len; i++) // start from index 1
        Insert_SmallerHeap(a[i] , HH);

    printf("The First build priortyQueue Smaller is: %d \n",HH->Elements[1]); //for test !
    MIN = HH->Elements[1]; //Store the min data
#if 0 //for test ! Output the priortyQueue
    for(int ii = 0 ; ii <= len ; ii++)
        printf("The element is : %d , the Index is : %d\n",HH->Elements[ii] ,ii )  ;
#endif
    return abs(MAX-MIN);
}

/*

Initalize is done
The dummy element is : 1000
The array length is : 9
The Current Inner Max_element is : 31
The Current Inner Max_element is : 31
The Current Inner Max_element is : 41
The Current Inner Max_element is : 59
The Current Inner Max_element is : 59
The Current Inner Max_element is : 59
The Current Inner Max_element is : 59
The Current Inner Max_element is : 97
The Current Inner Max_element is : 97
The First build priortyQueue Largest is: 97
The Current Inner Min_element is : -3
The Current Inner Min_element is : -3
The Current Inner Min_element is : -3
The Current Inner Min_element is : -3 
The Current Inner Min_element is : -3
The Current Inner Min_element is : -3
The Current Inner Min_element is : -3
The Current Inner Min_element is : -9
The Current Inner Min_element is : -9
The First build priortyQueue Smaller is: -9

Process returned 106 (0x6A)   execution time : 0.090 s
*/
