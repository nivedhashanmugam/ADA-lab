#include<iostream>
using namespace std;
int i,n;
class sorting
{
int arr[10];
public:
void read()
{
cout<<"Enter the number of array elements:  ";
cin>>n;
cout<<"Enter "<<n<<" integers ";
for(i=0;i<n;i++)
{
cin>>arr[i];
}
}
void inssort()
{
int d,t;
for(i=1;i<n;i++)
{
d=i;
while(d>0&&arr[d]<arr[d-1])
{
t=arr[d];
arr[d]=arr[d-1];
arr[d-1]=t;
d--;
}
}
}
 void sortit(int arr[], int lb, int ub){
    int j;
    if(lb >= ub)
    return;
   
    partition(arr,lb,ub,j);
    sortit(arr,lb,j-1);
    sortit(arr,j+1,ub);
}
void partition(int arr[],int lb,int ub,int &pj){
    int a, down, temp, up;
    a =arr[lb];
    up = ub;
    down = lb;
    while(down < up){
        while(arr[down] <= a)
            down++;
        while(arr[up]  > a)
            up--;
        if(down < up){
            temp = arr[down];
            arr[down] = arr[up];
            arr[up] = temp;
        }
    }
    arr[lb] = arr[up];
    arr[up] = a;
    pj = up;
}
void Merge(int arr[], int low, int high, int mid)
{
	
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
      while (i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
 
	while (j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
 
	for (i = low; i <= high; i++)
	{
		arr[i] = temp[i-low];
	}
}
 

void MergeSort(int arr[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		Merge(arr, low, high, mid);
	}
}
 
void display()
{
cout<<"list after sorting is";
for(i=0;i<n;i++)
cout<<" \t"<<arr[i]<<endl;
}
void qs()
{
sortit(arr,0,n-1);
}
void ms()
{
MergeSort(arr,0,n-1);
}
};
int main()
{
sorting ob;
cout<<"\nfor INSERTIONSORT inputs\n";
ob.read();
ob.inssort();
ob.display();
cout<<"\n for QUICKSORT inputs\n";
ob.read();
ob.qs();
ob.display();
cout<<"\n For MERGESORT inputs\n";
ob.read();
ob.ms();
ob.display();
}


