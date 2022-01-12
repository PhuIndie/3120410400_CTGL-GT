#include <iostream>
using namespace std;

// Hàm hợp nhất các mảng con bên trái và phải của arr
void mergeTwoSortedArray(int leftSubArray[], int rightSubArray[], int arr[], int n, int m)
{
    // i là độ dài leftSubArray, j là độ dài rightSubArray, k là độ dài arr
     int i = 0;
     int j = 0;
     int k = 0;
    while (i < n && j < m) {
        if (leftSubArray[i] <= rightSubArray[j]) {
            arr[k] = leftSubArray[i];
            i++;
        }
        else {
            arr[k] = rightSubArray[j];
            j++;
        }
        k++;
    }

    // sao chép các phần tử của leftSubArray[] 
    while (i < n) {
        arr[k] = leftSubArray[i];
        i++;
        k++;
    }

    // sao chép các phần tử còn lại của rightSubArray[]
    while (j < m) {
        arr[k] = rightSubArray[j];
        j++;
        k++;
    }
   
     
}

void mergeSort(int arr[], int size){
    //kiểm tra hàm rỗng, vì merge sort chỉ hoạt động khi số phần tử lớn hơn hoặc bằng 2
    if (size == 0) {
        return;
}

     // nếu chỉ có một phần tử trong arr thì không cần phải chia mảng thêm nữa vì một phần tử được sắp xếp chính nó.
       if(size == 1)
       {
            return;
       }
    // tạo leftSubArray và rightSubArray – sau đó sao chép các phần tử đó từ arr
        int n  = size / 2;
        int m = size - n;

        int leftSubArray[n];
        int rightSubArray[m];
        
   //tạo con trỏ arr
        int k = 0;

        for(int i = 0; i < n; i++)
        {
            leftSubArray[i] = arr[k];
            k++;
        }

        for(int j = 0; j < m; j++)
        {
            rightSubArray[j] = arr[k];
            k++;
        }
    
     //gọi mergeSort trên mảng con bên trái
        mergeSort(leftSubArray, n);
    
     //gọi mergeSort trên mảng con bên phải
        mergeSort(rightSubArray, m);
    
     //hợp nhất 2 mảng con đã sắp xếp thành mảng ban đầu
        mergeTwoSortedArray(leftSubArray, rightSubArray, arr, n, m);
        return;
}
int main()
{
    int arr[] = { 14, 17, 22, 4, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,n);
    
    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++)
    {
         cout<<arr[i]<<" ";
    }
   
    return 0;
}