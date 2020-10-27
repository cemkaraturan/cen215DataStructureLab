#include<stdio.h>
#include<string.h>
#include<time.h>

 void mergeName(char arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 


	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 


void mergeSortName(char arr[], int l, int r) 
{ 
	if (l < r) { 
		
		int m = l + (r - l) / 2; 

		
		mergeSortName(arr, l, m); 
		mergeSortName(arr, m + 1, r); 

		mergeName(arr, l, m, r); 
	} 
} 





void merge(int arr[],int left,int middle,int right){
	int lsize=middle - left+1;
	int rsize=right - middle;
	int Left[lsize];
	int Right[rsize];
	int i,j;
	for(i=0;i<lsize;++i){
		Left[i]=arr[left+i];
	}
	for(j=0;j<rsize;++j){
		Right[j]=arr[middle+1 + j];
	}
	i=0; j=0; int org = left;
	while(i<lsize && j<rsize){
		if (Left [i] <= Right[j]){
			arr[org]=Left[i];
			i++;
		}else{
			arr[org]=Right[j];
			j++;
		}
		org++;
	}
	while(i<lsize){
		arr[org]=Left[i];
		org++;
		i++;
	}
	while(j<rsize){
		arr[org]=Right[j];
		org++;
		j++;
	}
}

void mergesort (int arr[],int left,int right){
	if(left<right){
		int middle=(left+right)/2;
		mergesort(arr,left,middle);
		mergesort(arr,middle+1,right);
		merge(arr,left,middle,right);
		
	}
}

void selectionsort (int arr[],int size){
	int i,j,min;
	int temp;
	for(i=0;i<size;i++){
		min=i;	
	for(j=i;j<size;j++){
		if(arr[j]<arr[min]){
			min=j;
		}
	}
	temp=arr[i];
	arr[i]=arr[min];
	arr[min]=temp;	
}
}
void selectionsort2 (char arr[],int size){
	int i,j,min;
	for(i=0;i<size;i++){
		min=i;
	for(j=i;j<size;j++){
		if(arr[j]<arr[min]){
			min=j;
		}
	}
	int temp=arr[i];
	arr[i]=arr[min];
	arr[min]=temp;	
}
}

void insertionsort2 (char arr[],int boyut2){
	int i,j,temp;
	for(i=1;i<boyut2;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp){
		arr[j+1]=arr[j];
		j--;
	}
	arr[j+1]=temp;
	}	
}
void insertionsort (int arr[],int boyut){
	int i,j,temp;
	for(i=1;i<boyut;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp){
		arr[j+1]=arr[j];
		j--;
	}
	arr[j+1]=temp;
	}	
}
void bubblesort2(char string[],int boyut){
	int a,b,t;
	for(a=0;a<boyut;a++){
		for(b=1;b<boyut;b++){
			if(string[b-1]>string[b]){
				t=string[b];
				string[b]=string[b-1];
				string[b-1]=t;
			}
		}
	}	
}  
void bubblesort (int arr[],int boyut){
	int i,j,temp;
	for(i=0;i<boyut;i++){
		for(j=1;j<boyut;j++){
			if(arr[j-1]>arr[j]){
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}	
}

void printArray (int arr[],int size){
	int k;
	printf("Okul numaramin kucukten buyuge siralanmis hali:");
	for(k=0;k<10;k++){
	printf("%d",arr[k]);	
	}	
	printf("\n");	
}
void printArray2 (char arr[],int size){
	int k;
	printf("Adimin a dan z ye siralanmis hali:");
	for(k=0;k<15;k++){
	printf("%c",arr[k]);	
	}
	printf("\n");	
}

int main(){
	int k,l,t;
	int okulnumaram[]={2,0,1,8,5,5,6,0,4,3};
	int boyut=10;
	int boyut2=15;
	printf("Okul numaramin siralanmamis hali:");
	for(l=0;l<10;l++){
	printf("%d",okulnumaram[l]);	
	}
	printf("\n");
	
	bubblesort(okulnumaram,boyut);
	printArray(okulnumaram,boyut);
	
	insertionsort(okulnumaram,boyut);
	printArray(okulnumaram,boyut);
	
	selectionsort(okulnumaram,boyut);
	printArray(okulnumaram,boyut);
	
	mergesort(okulnumaram,0,boyut-1);
	printArray(okulnumaram,boyut);
	printf("\n");
	
	char ismim[]="cemkaraturan";
	printf("Adimin siralanmamis hali:");
	for(k=0;k<15;k++){
	printf("%c",ismim[k]);	
	}
	printf("\n");
	bubblesort2(ismim,boyut2);
	printArray2(ismim,boyut2);
	
	insertionsort2(ismim,boyut2);
	printArray2(ismim,boyut2);
	
	selectionsort2(ismim,boyut2);
	printArray2(ismim,boyut2);
	
	t = clock();
	mergeSortName(ismim, 0, 15);
	t = clock() - t;
	printArray2(ismim, 15);

	
	
	return 0;
}
