#include<iostream>
using namespace std;
void swap(int &x , int &y){
    int tmp=x;
    x=y;
    y=tmp;
}
int patrition(int a[],int min , int max){
    int middle=(min+max)/2;
    int p=a[middle];
    swap(a[min],a[middle]);
    int i=min+1;
    for(int j=min+1;j<=max;j++){
        if(a[j]<p){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[min],a[i-1]);
    return i-1;
}
void quick_sort(int a[],int min ,int max){
     if(min<max){
        int pivot=patrition(a,min,max);
        quick_sort(a,min,pivot-1);
        quick_sort(a,pivot+1,max);
     }
}
void nhap(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<"a["<<i+1<<"]=";
        cin>>a[i];
    }
}
void in(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
main(){
   int n;
   cout<<"Nhap vao so luong phan tu mang:";
   cin>>n;
   int *a= new int[n];
   nhap(a,n);
   quick_sort(a,0,n-1);
   in(a,n);
	
}
