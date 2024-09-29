#pragma once
//顺序队列
const int SeqQueueSize=100;
typedef int sQElement;
struct seqQueue
{
	sQElement element[SeqQueueSize];
	int front;
	int back;
};

//链式队列
typedef int lQData;
struct lQNode
{
	lQData data;
	lQNode* next;
};
struct linkedQueue
{
	lQNode* front;
	lQNode* back;
	int size;
};

//顺序队列.初始化
void seqQueue_init(seqQueue& sQ)
{
	sQ.front = sQ.back = 0;
}

//顺序队列.判空
bool seqQueue_empty(seqQueue& sQ)
{
	return sQ.front == sQ.back;
}

//顺序队列.入队
bool seqQueue_push(seqQueue& sQ,sQElement element)
{
	if ((sQ.back + 1) % SeqQueueSize == sQ.front)
	{
		return false;
	}
	sQ.element[sQ.back] = element;
	sQ.back = (sQ.back + 1) % SeqQueueSize;
	return true;
}

//顺序队列.出队
bool seqQueue_pop(seqQueue& sQ)
{
	if (seqQueue_empty(sQ))
	{
		return false;
	}
	sQ.front = (sQ.front + 1) % SeqQueueSize;
	return true;
}

//顺序队列.队长
int seqQueue_size(seqQueue& sQ)
{
	return (sQ.back - sQ.front + SeqQueueSize) % SeqQueueSize;
}

//顺序队列.队首元素
sQElement seqQueue_front(seqQueue& sQ)
{
	return sQ.element[sQ.front];
}

//顺序队列.队尾元素
sQElement seqQueue_back(seqQueue& sQ)
{
	return sQ.element[(sQ.back - 1 + SeqQueueSize) % SeqQueueSize];
}

//顺序队列.测试
void test_seqQueue(void)
{
	seqQueue sQueue;
	seqQueue_init(sQueue);
	std::cout << "输入要入队的元素个数(小于" << SeqQueueSize << ")：";
	int num = 0;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		sQElement element;
		std::cout << "输入想要入队的元素：";
		std::cin >> element;
		seqQueue_push(sQueue, element);
	}
	std::cout << "队长为：" << seqQueue_size(sQueue) << std::endl;
	std::cout << "队首元素是：" << seqQueue_front(sQueue) << ",队尾元素是：" << seqQueue_back(sQueue) << std::endl;
	seqQueue_pop(sQueue);
	std::cout << "出队后的队首元素是：" << seqQueue_front(sQueue) << std::endl;
	std::cout << "顺序队列测试完成！！！" << std::endl << std::endl;
}

//链式队列.初始化
bool linkedQueue_init(linkedQueue& lQueue)
{
	lQueue.front = nullptr;
	lQueue.back = nullptr;
	return true;
}

//链式队列.判空
bool linkedQueue_empty(linkedQueue& lQueue)
{
	return lQueue.front == nullptr;
}

//链式队列.入队
bool linkedQueue_push(linkedQueue& lQueue, lQData data)
{
	lQNode* newNode = new lQNode;
	if (newNode == nullptr)
	{
		return false;
	}
	newNode->data = data;
	newNode->next = nullptr;
	if (linkedQueue_empty(lQueue))
	{
		lQueue.front = newNode;
		lQueue.back = newNode;
	}
	else
	{
		lQueue.back->next = newNode;
		lQueue.back = newNode;
	}
	lQueue.size++;
	return true;
}

//链式队列.出队
lQData linkedQueue_pop(linkedQueue& lQueue)
{
	if (linkedQueue_empty(lQueue))
	{
		return -1;
	}
	lQNode* ptr = lQueue.front;
	lQData data = lQueue.front->data;
	lQueue.front = lQueue.front->next;
	delete ptr;
	lQueue.size--;
	return data;
}

//链式队列.队长
int linkedQueue_size(linkedQueue& lQueue)
{
	int count = 0;
	for (lQNode* ptr = lQueue.front; ptr != nullptr; ptr = ptr->next, count++);
	return count;
}

//链式队列.队首元素
lQData linkedQueue_front(linkedQueue& lQueue)
{
	if (linkedQueue_empty(lQueue))
	{
		return -1;
	}
	return lQueue.front->data;
}

//链式队列.队尾元素
lQData linkedQueue_back(linkedQueue& lQueue)
{
	if (linkedQueue_empty(lQueue))
	{
		return - 1;
	}
	return lQueue.back->data;
}

//链式队列.销毁
bool linkedQueue_destroy(linkedQueue& lQueue)
{
	lQNode* ptr=lQueue.front->next;
	lQueue.back = nullptr;
	for (; ptr->next != nullptr; lQueue.front=ptr,ptr = ptr->next)
	{
		delete lQueue.front;
	}
	delete ptr;
	return true;
}

//链式队列.测试
void test_linkedQueue(void)
{
	linkedQueue lQueue;
	linkedQueue_init(lQueue);
	std::cout << "输入想要入队的数据个数：";
	int num = 0;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		std::cout << "输入想要入队的数据：";
		lQData data;
		std::cin >> data;
		linkedQueue_push(lQueue, data);
	}
	std::cout << "队长是："<<linkedQueue_size(lQueue)<<",队首数据是：" << linkedQueue_front(lQueue) 
		      << ",队尾数据是：" << linkedQueue_back(lQueue) << std::endl;
	linkedQueue_pop(lQueue);
	std::cout << "出队后的队长是：" << linkedQueue_size(lQueue) << ",队首数据是：" << linkedQueue_front(lQueue) << std::endl;
	linkedQueue_destroy(lQueue);
	std::cout << "链式队列测试完成！！！" << std::endl << std::endl;
}