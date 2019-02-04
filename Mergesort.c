#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int aux[], int start, int mid, int end)
{
    int i,j,k=0,h=0;
    i = start;
    j = mid+1;
    while(i <=mid && j <= end )
    {
        if(a[i] > a[j])
        {
            aux[k]=a[j];
            j++;
            k++;
        }
        else
        {
            aux[k]=a[i];
            i++;
            k++;
        }

    }
    if(i > mid)
    {
        while(j <= end)
        {
            aux[k] = a[j];
            j++;
            k++;
        }
    }
    if(j > end)
    {
        while(i <= mid)
        {
            aux[k] = a[i];
            i++;
            k++;
        }
    }
    for(i = start;i <= end;i++)
    {
        a[i] = aux[h++];
    }

}
void mergesort(int a[], int aux[], int start, int end)
{
    if(end <= start)
        return ;
    int mid = (start + end) / 2;
    mergesort(a, aux, start, mid);
    mergesort(a, aux, mid+1, end);
    merge(a, aux, start, mid, end);
}

int main()
{
    int i;
    int *a = (int *)malloc(sizeof(int)*5);
    int *aux = (int *)malloc(sizeof(int)*5);
    for(i = 0;i < 5;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a, aux, 0, 4);
    for(i = 0;i < 5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
