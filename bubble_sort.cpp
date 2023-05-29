#include <iostream>
#include <chrono>
#include <omp.h>
#include <functional>
#include <string>

using namespace std;

void pbs(int *array, int n){
	
	int i, j, temp;
	#pragma omp parallel for shared(array, n) private(i, j, temp)
	for(i = 0; i < n-1; i++){
		
		for(j = 0; j < n-1; j++){
			
			if(array[j] > array[j+1]){
				
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				
				}
			
			}
		
		}	
	
	}
	
void sbs(int *array, int n){
	
	int i, j, temp;
	
	for(i = 0; i < n-1; i++){
		
		for(j = 0; j < n-1; j++){
			
			if(array[j] > array[j+1]){
				
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				
				}
			
			}
		
		} 	
	
	}

int main(){

	int *arr, n;
	cout << "Enter number of elements in array : ";
	cin >> n;
	for(int i = 0; i < n; i++){
		
		arr[i] = rand()%n;
		
		}
		
	double start = omp_get_wtime();
	pbs(arr, n);
	double end = omp_get_wtime();
	
	cout << "\nParallel Bubble Sort Time: " << end - start << " seconds" << endl;
	
	start = omp_get_wtime();
	sbs(arr, n);
	end = omp_get_wtime();
	
	cout <<"Seqential Bubble Sort Time: " << end - start << " seconds" << endl;
	
	cout <<"Random Array : \n";
	
	for(int i = 0; i < n; i++){
		
		cout << arr[i] << " ";
		
		}
	 return 0;
	
	}
	
	
	
