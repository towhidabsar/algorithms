#include"Heap.h"

using namespace datastructures;

int Heap::left(int i){
	return (i<<1) + 1;
}
int Heap::right(int i){
	return (i<<1) + 2;
}
int Heap::parent(int i){
	return (i>>1);
}

void Heap::printheap(){
	for(int i = 0; i <= this->length ; i++)
		cout << this->a[i] << endl;
}

void Heap::max_heapify(int index){
	std::cout << "In max heapify: "<< endl;

	// Algorithm	
	int left_index= left(index);
	int right_index= right(index);

	int largest_index = index;

	//cout << "index :" << index << "left_index" << left_index << "right_index" << right_index << endl;

	if(left_index <= this->heap_size) 
		if(this->a[left_index] > this->a[index])
			largest_index = left_index;
	if(right_index <= this->heap_size) 
		if(this->a[right_index] > this->a[largest_index])
			largest_index = right_index;
	if(largest_index != index){
		int temp = this->a[index];
		this->a[index] =this->a[largest_index];
		this->a[largest_index] = temp;
		max_heapify(largest_index);
	}
}
void Heap::build_heap(){
	std::cout << "In build heap" << endl;
	
	int i = floor(this->length/2);
	for(; i >= 0; i--){		
		max_heapify(i);	
	}
}

void heapsort(Heap &to_sort){
	for (int i= to_sort.length; i>=1; i--){
		int temp = to_sort.a[0];
		to_sort.a[0] = to_sort.a[i];
		to_sort.a[i] = temp;

		to_sort.heap_size--;
		to_sort.max_heapify(0);	
	}

}
int main(){
	std::vector<int> a = {4,1,3,2,16,9,10,14,8,7};
	Heap h(a);
	heapsort(h);
	h.printheap();
	return 1;
}