#include <iostream>
#include <vector>


using namespace std;


struct MaxHeap {
	vector<int>heap_;
	int size_ = 0;
	int parent_index, maximum;

	void siftUp(int index) {
		if (index == 0) { // корень кучи, у него нет родителя
			return;
		}
		parent_index = (index - (index % 2 == 0)) / 2;
		if (heap_[index] > heap_[parent_index]) { // сын больше родителя
			swap(heap_[index], heap_[parent_index]);
			siftUp(parent_index);
		}
	}

	void siftDown(int index) {
		if ((2 * index + 1 < size_) && (2 * index + 2 < size_)) { // есть оба сына
			if (heap_[2 * index + 1] > heap_[2 * index + 2]) { //  левый сын больше
				if (heap_[index] < heap_[2 * index + 1]) { // родитель меньше сына
					swap(heap_[index], heap_[2 * index + 1]);
					siftDown(2 * index + 1);
				}
			} else { // правый сын больше
				if (heap_[index] < heap_[2 * index + 2]) { // родитель меньше сына
					swap(heap_[index], heap_[2 * index + 2]);
					siftDown(2 * index + 2);
				}
			}
		} else if (2 * index + 1 < size_) { // есть только левый сын
			if (heap_[index] < heap_[2 * index + 1]) { // родитель меньше сына
				swap(heap_[index], heap_[2 * index + 1]);
				siftDown(2 * index + 1);
			}
		}
	}

	void Insert(int x) {
		heap_.push_back(x);
		siftUp(size_);
		++size_;
	}

	int Extract() {
		maximum = heap_[0];
		heap_[0] = heap_[size_ - 1];
		heap_.pop_back();
		--size_;
		siftDown(0);
		return maximum;
	}
};


int main() {
	MaxHeap max_heap;
	int n; cin >> n;
	int operation, number;
	while (n--) {
		cin >> operation;
		if (operation == 0) {
			cin >> number;
			max_heap.Insert(number);
		} else {
			cout << max_heap.Extract() << '\n';
		}
	}
}


/*
2
0 10000
1

--10000


14
0 1
0 345
1
0 4346
1
0 2435
1
0 235
0 5
0 365
1
1
1
1

--345
4346
2435
365
235
5
1
*/
