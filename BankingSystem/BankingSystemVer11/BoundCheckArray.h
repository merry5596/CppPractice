#pragma once

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int len;

	BoundCheckArray(const BoundCheckArray& copy) {}
	BoundCheckArray& operator=(const BoundCheckArray& ref) {}
public:
	BoundCheckArray(int n = 100);
	~BoundCheckArray();
	T& operator[] (int index);
	T operator[] (int index) const;
	int GetArrLen() const;
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int n) : len(n) {
	arr = new T[len];
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete []arr;
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int index) {
	if (index < 0 || index >= len) {
		cout << "AcountArray index out of bound exception." << endl;
		exit(1);
	}
	return arr[index];
}

template <typename T>
T BoundCheckArray<T>::operator[] (int index) const {
	if (index < 0 || index >= len) {
		cout << "AcountArray index out of bound exception." << endl;
		exit(1);
	}
	return arr[index];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {
	return len;
}