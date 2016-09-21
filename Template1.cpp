//Sahil Kumar
//210916
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

//----function template-----
template <typename T>
T const& Max (T const& a, T const& b)
{
	return a < b ? b:a;
}

//----class temnplate----
template <class T>
class Stack
{
private:
	vector<T> elements;
public:
	void Push(T const&);	//push element from stack
	void Pop();				//pop element from stack
	T Top() const;			//return top element
	bool empty()			//return true when stack is empty
	{
		return elements.empty();
	}
};

template <class T>
void Stack<T>::Push(T const& element)
{
	elements.push_back(element);
}

template <class T>
void Stack<T>::Pop()
{
	if (elements.empty()) 
	    throw out_of_range("Stack<>::pop(): empty stack"); 
	elements.pop_back();
}

template <class T>
T Stack<T>::Top() const
{
	if (elements.empty()) 
	    throw out_of_range("Stack<>::pop(): empty stack"); 

	return elements.back();
}


int main()
{
	int i = 30;
	int j = 28;
	float f = 12.9;
	float g = 1.1;
	string s1 = "Hello";
	string s2 = "World!";

	//----function template----
	cout<< "Max(i,j)    "   << Max(i,j)<<endl;
	cout<< "Max(f,g)    "   << Max(f,g)<<endl;
	cout<< "Max(s1,s2)  " << Max(s1,s2)<<endl;
	//----class template----
	Stack<int> intStack;
	Stack<string> stringStack;
	Stack<double> doubleStack;

	//int stack
	intStack.Push(1);
	intStack.Push(2);
	intStack.Push(3);
	intStack.Push(4);

	cout<<endl<<"IntStack Top   "<<intStack.Top()<<endl;
	//string stack 
	stringStack.Push("Servus");
	stringStack.Push("Hello");
	stringStack.Push("sahil");
	stringStack.Push("C++ 11");
	cout<<endl<<"StringStack Top   "<<stringStack.Top()<<endl;

	//double stack
	doubleStack.Push(2.33);
	doubleStack.Push(2.33);
	doubleStack.Push(9.33333);
	cout<<endl<<"DoubleStack Top   "<<doubleStack.Top()<<endl;

	return 0;
}