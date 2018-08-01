#include <bits/stdc++.h>

using namespace std;

void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)//合并 
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)//
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);//一直分割 
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}
 
int main()
{
	//freopen("txt1.txt","r",stdin);
	//freopen("txt2.txt","w",stdout);
	int a[10005];
    int i, b[10005];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	scanf("%d",&a[i]);
    int s=clock();
    MergeSort(a, b, 0, n-1);
    int e=clock();
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
    //printf("%.12lfs\n",(double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
