#include<iostream>
#include<omp.h>

using namespace std;

int main(){
	
	int arr[7] = {4, 5, 6, 2, 3, 1, 0};
	int min = arr[0];
	int max = arr[0];
	int size = 7, sum =0, i=0, x;
	
	double start, stop, average;
	
	start = omp_get_wtime();
	
	#pragma omp parallel num_threads(6)
	x = omp_get_num_threads();
	cout << "Threads being used " << x << endl;
	while(i < size){
		
		if(arr[i] < min) min = arr[i];
		if(arr[i] > max) max = arr[i];
		sum += arr[i];
		i++;
		
		}
	average = sum/size;	
	
	stop = omp_get_wtime();
	
	cout << "Minimum: " << min << endl;
	cout << "Maximum: " << max << endl;
	cout << "Sum: " << sum << endl;
	cout << "Average: " << average << endl;
	
	cout << "Execution time: " << stop - start << endl;
	
	return 0;
	
	}
