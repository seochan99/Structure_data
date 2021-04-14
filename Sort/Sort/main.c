#include <stdio.h>

void Swap(int arr[],int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[],int left, int right)
{
    int pivot = arr[left]; // pivot is most left
    int low = left+1;
    int high = right;
    
    //교차되기전까지 반복
    while(low <= high)
    {
        // find higher than pivot
        while(pivot >= arr[low] && low<= right)
            low++; // low going right
        // find lower than pivot
        while(pivot<=arr[high] && high >= (left+1))
            high --;
        //교차 되지 않았을때 서로 교환
        if(low<=high)
            Swap(arr,low,high);
    }
    Swap(arr,left,high); // 피벗과 하이가 가리키는 대상 교환
    return high; // 옮겨진 피벗의 위치정보 반환.
}

void QuickSort(int arr[],int left, int right)
{
    if(left<=right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main(void)
{
//    int arr[7] = {3,2,4,1,7,6,5};
    int arr[3] = {3,3,3};
    
    int len = sizeof(arr)/sizeof(int);
    int i;
    
    QuickSort(arr, 0, len-1); //arr에 대해서 퀵 정렬 진행 시작 !
    
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
