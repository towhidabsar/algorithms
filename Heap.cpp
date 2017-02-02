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
	// std::cout << "In max heapify: "<< endl;

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
	// std::cout << "In build heap" << endl;
	
	int i = floor(this->length/2);
	for(; i >= 0; i--){		
		max_heapify(i);	
	}
}

Heap heapsort(std::vector<int> &array){
	Heap to_sort(array);
	for (int i= to_sort.length; i>=1; i--){
		int temp = to_sort.a[0];
		to_sort.a[0] = to_sort.a[i];
		to_sort.a[i] = temp;

		to_sort.heap_size--;
		to_sort.max_heapify(0);	
	}

	return to_sort;

}
int main(int argc, char** argv){
	// std::cout << argv[6] << endl;
	std::vector<int> a;
	for (int i = 1; i<argc; i++){
		int j = int(*argv[i] - '0');
		a.push_back(j);
  }
	// std::cout << "Before sorting: "<<endl;
	// h.printheap();
	Heap h = heapsort(a);
	std::cout << "After sorting: "<<endl;
	h.printheap();
	return 1;
}