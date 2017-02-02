#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
// This is used to create a namespace
namespace datastructures{

	class Heap{
	public:
		std::vector<int> a;
		int length;
		int heap_size;

		int left(int i);
		int right(int i);
		int parent(int i);
		void max_heapify(int index);
		void build_heap();

		void printheap();
		Heap(std::vector<int> b){
			this->a = b;
			cout << "size of array" << a.size() << endl;
			this->length = a.size()-1;
			this->heap_size = a.size()-1;
			build_heap();
		}
		~Heap(){}

	};
}