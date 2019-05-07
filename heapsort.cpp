/* To compile:

g++ heapsort.cpp timer.cpp -o heapsort
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "timer.h"


void maxHeapify(int heap[],int n);
void buildMaxHeap(int heap[],int n);
void heapSort(int heap[],int n);

//In C/C++, any statement that begins with # is a pre-processor statement
//pre-processor statements are handled before compilation by the preprocessor
//it essentially generates more source code depending on the statement and it is
//this altered source that gets compiled.
//#define allows us to create labels and macros.
//we define the symbol (LEFT(idx)) and what it should be replaced with ((idx) * 2 + 1)
//the preprocessor will go through the source code and replace every LEFT(idx) with (idx) *2+1

//This is good for simple expressions and will speed up the program
//as they look like a function call within the program but 
//does not have the expense of the function call

#define LEFT(idx) (idx) * 2 + 1
#define RIGHT(idx) (idx) * 2 + 2




int leftIdx(int idx);
int rightIdx(int idx);

int main(int argc, char* argv[]){
  int size=atoi(argv[1]);
  int* myarr=new int[size];
  std::ofstream log("heap.log");
  Timer stopwatch;
  for(int i=0;i<size;i++){
    myarr[i]=rand();
  }
  stopwatch.start();
  heapSort(myarr,size);
  stopwatch.stop();
  std::cout << stopwatch.currtime() << std::endl;
  for(int i=0;i<size;i++){
    log <<myarr[i]<< std::endl;
  }
  return 0;
}
void maxHeapify(int heap[],int idx,int n){
	int left=LEFT(idx);
	int right=RIGHT(idx);
	int largest=idx;
	if(left < n && heap[left] > heap[largest]){
		largest=left;
	}
	if(right < n && heap[right] > heap[largest]){
		largest=right;
	}
	if(largest!=idx){
		int tmp=heap[idx];
		heap[idx]=heap[largest];
		heap[largest]=tmp;
		maxHeapify(heap,largest,n);
	}
}
void buildMaxHeap(int heap[],int n){
	for(int i=(n-1)/2;i>=0;i--){
		maxHeapify(heap,i,n);
	}
}
void heapSort(int heap[],int n){
	buildMaxHeap(heap,n);
	for(int i=n-1;i>0;i--){
		int tmp=heap[0];
		heap[0]=heap[i];
		heap[i]=tmp;
		maxHeapify(heap,0,i);
	}
}
