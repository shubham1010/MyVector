#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;


template<class T>
class MyVector {
private:
	T *array;
	unsigned int vsize;
	unsigned int max_size;
	unsigned int vcapacity;
	unsigned int resize;
	unsigned int availableSize;

	const static int dyn_array_step = 0; // initial size of a vector
	
	const static int dyn_array_mul = 2; // refer the blog
	

public:
	MyVector(); // constructor
	MyVector(const MyVector &a); // copy constructor
	~MyVector(); // distructor to free memory
	MyVector& operator = (const MyVector &a); // assignment operator
	T& operator [] (unsigned int index); // to get array item
	unsigned int capacity(); // to get actual capacity of a vector
	unsigned int size(); // current size of a vector
	void reserve(unsigned int newsize); // allocate newsize amount of memory
	void Clear(); // reset the vector like a new one
	void display();

	enum exception { MEMFAIL };
	
	void push_back(const T &item); // push/add an element to end of the vector
	void pop_back();
	bool empty(); // check whether vector is empty or not


};

template <class T>
bool MyVector<T>::empty() {
	return vsize==0;
}

template <class T>
MyVector<T>::MyVector() {
	vcapacity = dyn_array_step;

	vsize=0;
	array = (T *)malloc(vcapacity*sizeof(T));

	if(array==NULL)
		throw MEMFAIL;
}

template <class T>
MyVector<T>::~MyVector() {
	if(array) {
		free(array);
		array=NULL;
		cout << "Vector is deleted successfully!" << endl;
	}
}

template <class T>
MyVector<T>::MyVector(const MyVector &a) {
	array = (T *)malloc(sizeof(T)*a.vcapacity);
	if(array==NULL)
		throw MEMFAIL;
	
	memcpy(array,a.array,sizeof(T)*a.vcapacity);
	vcapacity = a.vcapacity;
	vsize = a.vsize;
}

template <class T>
MyVector<T>& MyVector<T>:: operator = (const MyVector &a) {
	if(this == &a)
		return *this;
	if (a.vsize==0)
		Clear();

	reserve(a.vsize);

	memcpy(array,a.array,sizeof(T)*a.vsize);
	return *this;
}

template <class T>
T& MyVector<T>::operator [] (unsigned int index) {
	return array[index];
}

template <class T>
unsigned int MyVector<T>::capacity() {
	return vcapacity;
}

template <class T>
unsigned int MyVector<T>::size() {
	return vsize;
}

template <class T>
void MyVector<T>::reserve(unsigned int newsize) {
	//availableSize = vcapacity-vsize;
	if(vcapacity==0)
		vcapacity=1;
	if(newsize<=0)
		Clear();
	else if(newsize>vcapacity) {
		vcapacity=newsize;
		array = (T *)realloc(array,sizeof(T)*vcapacity);

		if(array==NULL)
			throw MEMFAIL;
	}
}

template <class T>
void MyVector<T>::Clear() {
	vsize=0;
	array=(T *)realloc(array,sizeof(T)*dyn_array_step);

	vcapacity=dyn_array_step;
}

template <class T>
void MyVector<T>::push_back(const T &item) {
	if(vcapacity==0)
		vcapacity=1;
	vsize++;

	if(vsize>vcapacity) {
		vcapacity *= dyn_array_mul;

		array = (T *)realloc(array,sizeof(T)*vcapacity);

		if(!array)
			throw MEMFAIL;
	}
	array[vsize-1] = item;
}

template <class T>
void MyVector<T>::display(void) {
	for(unsigned int i=0 ; i<vsize ; i++)
		cout << array[i] << " ";
	
	cout <<endl;
}



template <class T>
void MyVector<T>::pop_back(void) {
	if(!empty()) {
		cout << endl << array[vsize] << " is popped!" << endl;
		vsize -= 1;	

	}
	else
		cout << "Vector is already empty..!";
}
