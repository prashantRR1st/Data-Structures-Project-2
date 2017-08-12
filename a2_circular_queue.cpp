#include <iostream>
#include "a2_circular_queue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	capacity_ = 16;
	size_ = 0;
	head_=0;
	tail_=0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	items_ = new QueueItem[capacity];
	capacity_ = capacity;
	size_ = 0;
	head_=0;
	tail_=0;
}

CircularQueue::~CircularQueue()
{
	delete [] items_;
	items_ = NULL;
	size_=0;
	capacity_=0;
	head_=0;
	tail_=0;
}

bool CircularQueue::empty() const
{
	return (size_==0);    
}

bool CircularQueue::full() const
{
	return (size_==capacity_ && size_!=0);
}

int CircularQueue::size() const
{
	return size_;  
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (CircularQueue::full()){
		return false;
	} else {
		tail_=(head_+size_)%capacity_;
		items_[tail_]= value;
		((tail_+1==capacity_) ? tail_=0:tail_++);
		size_++; 
		return true;
	}
}

QueueItem CircularQueue::dequeue()
{
	if(CircularQueue::empty()){
		return EMPTY_QUEUE;
	} else {
		QueueItem deqdItm= items_[head_];
		head_ = (head_+1)%capacity_;
		size_--;
		return deqdItm;
	}
	
}

QueueItem CircularQueue::peek() const
{
	if (size_==0){
		return EMPTY_QUEUE;
	} else {
		return items_[head_];
	}
}

void CircularQueue::print() const
{
	for (int i=0; i<size_; i++){
		cout<<items_[i];
	}
}

