#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Queue {
	T* pMem;
	int size, head, tail;
public:
	Queue(int _size = 10) {
		pMem = new T[_size];
		size = _size;
		tail = -1;
		head = 0;
		count = 0;
	}

	~Queue();//деструктор
	Queue(const Queue& s);//конструктор копирования

};
//конструктор копирования
template <class T>
Queue<T>::Queue(const Queue& s) {
	size = s.size;
	tail = s.tail;
	head = s.head;
	pMem = new T[size];
	if (tail >= head) {
		for (int i = head; i <= tail; i++) {
			pMem[i] = s.pMem[i];
		}
	}
	else {
		for (int i = head; i < size; i++) {
			pMem[i] = s.pMem[i];
		}
		for (int i = 0; i < tail; i++) {
			pMem[i] = s.pMem[i];
		}
	}
}
template <class T>
int Front() {
	return pMem[head];
}
template <class T>
int Back() {
	return pMem[tail];
}
template <class T>
Queue<T>::~Queue()
{
	delete[] pMem;
}
template <class T>
bool isEmpty() {
	return count == 0;
}
template <class T>
bool isFull() {

	return count == size;
}
template <class T>
//добавление элемента 
void Push(int item) {
	if (!isFull) {
		tail = (tail + 1) % size;
		pMem[tail] = item;
		count++;
	}
}
//удаление элемента
template <class T>
int Delete(int item) {
	if (!isEmpty) {
		int x = pMem[head];
		head = (head + 1) % size;
		count--;
		return x;
	}
	else throw - 1;
}
struct TaskInfo {
	int ProcCount;
	int StepCont;
	int Id;
};
struct ProcInfo {
	bool Free;
	int TaskId;
	int CurrStep;
	int FreeTime;
	int TaskCount;
};
vector<ProcInfo> Procs;
//p-вероятность наступления задач

