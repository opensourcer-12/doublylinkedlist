#include<stdio.h>
#include<stdlib.h>

void insertion();
void merges();
void quicks();

int a[5]={5,4,7,2,9};

int main(){
int i;
insertion(a,5);
for(i=0;i<5;i++){
    printf("%d\n",a[i]);
}
return 0;
}
void swap(int *k, int *l){
    int temp;
    temp=*k;
    *k=*l;
    *l=temp;
}

void insertion(int *a,int size){
 int i, key, j;
   for (i = 1; i < size; i++)
   {
       key = a[i];
       j = i-1;
       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
}

void merge(int *a, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void merges(int *a,int size){
merge1(a,0,size-1);
}

void merge1(int *a, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        merge1(a, l, m);
        merge1(a, m+1, r);

        merge(a, l, m, r);
    }
}

int partition (int *a, int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quicks(int *a,int size){
quick(a,0,size-1);
}

void quick(int *a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quick(a, low, pi - 1);
        quick(a, pi + 1, high);
    }
}
