#include <iostream>
using namespace std;

// Hàm để hoán đổi hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void nhap(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<"#"<<i+1<<"=";
        cin>>arr[i];
    }
}

// Hàm phân hoạch mảng với pivot là phần tử đầu tiên
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // chọn phần tử đầu tiên làm pivot
    int i = low + 1;       // chỉ số của phần tử lớn hơn pivot

    for (int j = low + 1; j <= high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;  // tăng chỉ số của phần tử lớn hơn
        }
    }
    // Đưa pivot về đúng vị trí
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Hàm QuickSort đệ quy
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Phân hoạch mảng và trả về vị trí pivot
        int pi = partition(arr, low, high);

        // Gọi đệ quy sắp xếp phần trước và sau của pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout<<"Nhap n:";
    cin>>n;
    int *a;
    a=new(nothrow) int[n];
    
    nhap(a,n);

    cout << "Mảng ban đầu: ";
    printArray(a, n);

    quickSort(a, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(a, n);

    return 0;
}
