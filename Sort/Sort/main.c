#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx =left;
    int rIdx = mid + 1;
    int i;
    
    //  병합 한 결과를 담을 배열 sortArr의 동적 할당!
    int * sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx =left;
    
    while(fIdx<=mid&&rIdx<=right)
    {
        // 병합 할 두 영역의 데이터를 비교하여, 정렬 순서대로 sortArr에 하나씩 옮겨 담는다.
        if(arr[fIdx]<=arr[rIdx])
            sortArr[sIdx] =arr[fIdx++];
        else
            sortArr[sIdx]= arr[rIdx++];
        
        sIdx++;
    }
    
    if(fIdx > mid) // 배열의 앞부분이 모두 SortArr에 옮겨 졌다면
    {
        //배열 뒷부분에 남은 데이터들을 모두 sortArr에 그대로 옮긴다.
        for(i=rIdx;i<=right;i++,sIdx++)
                sortArr[sIdx]= arr[i];
    }
    else{ // 배열의 뒷부분이 모두 옮겨졌다면
        for(i=fIdx;i<=mid;i++,sIdx++) //배열의 앞부분에 남은 데이터들을 그대로 옮긴다.
        sortArr[sIdx] = arr[i];
    }
    
    for(i=left; i<=right; i++)
    arr[i] = sortArr[i];
    
    free(sortArr);
    
}

void MergeSort(int arr[],int left,int right)
{
    int mid;
    
    if(left < right)
    {
        //중간 지점을 게산한다.
        mid = (left+right)/2;
        
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        
        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void)
{
    int arr[7]={3,2,4,1,7,6,5};
    int i;
    
    MergeSort(arr,0,sizeof(arr)/sizeof(int)-1);
    
    for (i=0; i<7; i++) {
        printf("%d ",arr[i]);
    }
    
    printf("\n");
    return 0;
}
