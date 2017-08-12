#include <iostream>
#include "a2_dynamic_stack.hpp"

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	size_ = 0;
	init_capacity_ = 16;
	capacity_ = init_capacity_;
	items_ = new StackItem[16];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	size_ = 0;
	init_capacity_ = capacity;
	capacity_ = init_capacity_;
	items_ = new StackItem[capacity];
}

DynamicStack::~DynamicStack()
{
	delete [] items_;
	items_ = NULL;
	size_=0;
	capacity_=0;
	init_capacity_=0;
}

bool DynamicStack::empty() const
{
	return (size_ == 0);
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_ == capacity_){
		capacity_ *= 2;				// doubles capacity
		StackItem* tmpItems_= new StackItem[capacity_];		//initializes new temp array for data to be transfered		
		for (int i=0; i<size_; i++){ //runs a loop that copies each entry from items_ to the tmpItems_
			tmpItems_[i]=items_[i];
		}
		delete [] items_;
		items_=tmpItems_;				//items_ now points to the new array tmpItems_ pointed to before
		tmpItems_=NULL;
	}
	items_[size_]=value;				//enters new value into the top of the stack
	size_++;								
}

StackItem DynamicStack::pop()
{
	if(size_==0){
		return EMPTY_STACK;
	}
	else if(size_-1 <= capacity_/4 && capacity_/2>=init_capacity_){
		capacity_/=2;
		StackItem* tmpItems_= new StackItem[capacity_];		//initializes new temp array for data to be transfered		
		for (int i=0; i<size_; i++){ //runs a loop that copies each entry from items_ to the tmpItems_
			tmpItems_[i]=items_[i];
		}
		delete [] items_;
		items_=tmpItems_;				//items_ now points to the new array tmpItems_ pointed to before
		tmpItems_=NULL;
	}
	StackItem tmpOutput = items_[size_-1];		//stores the value to be popped in a temp variable
	// delete items_[size_-1];						//deletes the top item and decrements size,
	size_--;
	return tmpOutput;							//returns what was the top element
		
}

StackItem DynamicStack::peek() const
{
	if(size_ == 0){
		return EMPTY_STACK;
	}
	else return items_[size_ - 1];
}

void DynamicStack::print() const
{
	for (int i = (size_ - 1); i >= 0; i--){
		cout << items_[i];
	}
		
}

