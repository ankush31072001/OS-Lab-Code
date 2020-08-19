#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* a,int l,int r){
    int pivot=a[r];
    int i=l,j;
    for(j=l;j<r;j++){
        if(a[j]<pivot){
            swap(&a[i],&a[j]);
            i++;
        }
    }
    swap(&a[r],&a[i]);
    return i;
}
void quickSort(int*a,int l,int r){
    if(l>=r)return;
    int p=partition(a,l,r);
    quickSort(a,l,p-1);
    quickSort(a,p+1,r);
}


void merge(int* a,int l,int m,int r){
    int i=0,j=0,k=l;
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    
    for(i=0;i<n1;i++)L[i]=a[l+i];
    for(i=0;i<n2;i++)R[i]=a[m+1+i];
    i=0;
    
    while(i<n1&&j<n2){
        if(L[i]<=R[j])a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1)a[k++]=L[i++];
    while(j<n2)a[k++]=R[j++];
}
void mergeSort(int* a,int l,int r){
    if(l>=r)return;
    int m=(l+r-1)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
    
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    pid_t pid = fork();
    if(pid == 0){
        quickSort(a,0,n-1);
        printf("Child Process-> QuickSort\n");
        for(int i=0;i<n;i++)printf("%d ", a[i]);
        printf("\n");
    }
    else{
        printf("Parent Started\n");
        wait(NULL);
        printf("Child Terminated\n");
        mergeSort(a,0,n-1);
        printf("Parent Process-> MergeSort\n");
        for(int i=0;i<n;i++)printf("%d ", a[i]);
        printf("\n");
    }

}
