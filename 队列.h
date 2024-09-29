#pragma once
//˳�����
const int SeqQueueSize=100;
typedef int sQElement;
struct seqQueue
{
	sQElement element[SeqQueueSize];
	int front;
	int back;
};

//��ʽ����
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

//˳�����.��ʼ��
void seqQueue_init(seqQueue& sQ)
{
	sQ.front = sQ.back = 0;
}

//˳�����.�п�
bool seqQueue_empty(seqQueue& sQ)
{
	return sQ.front == sQ.back;
}

//˳�����.���
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

//˳�����.����
bool seqQueue_pop(seqQueue& sQ)
{
	if (seqQueue_empty(sQ))
	{
		return false;
	}
	sQ.front = (sQ.front + 1) % SeqQueueSize;
	return true;
}

//˳�����.�ӳ�
int seqQueue_size(seqQueue& sQ)
{
	return (sQ.back - sQ.front + SeqQueueSize) % SeqQueueSize;
}

//˳�����.����Ԫ��
sQElement seqQueue_front(seqQueue& sQ)
{
	return sQ.element[sQ.front];
}

//˳�����.��βԪ��
sQElement seqQueue_back(seqQueue& sQ)
{
	return sQ.element[(sQ.back - 1 + SeqQueueSize) % SeqQueueSize];
}

//˳�����.����
void test_seqQueue(void)
{
	seqQueue sQueue;
	seqQueue_init(sQueue);
	std::cout << "����Ҫ��ӵ�Ԫ�ظ���(С��" << SeqQueueSize << ")��";
	int num = 0;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		sQElement element;
		std::cout << "������Ҫ��ӵ�Ԫ�أ�";
		std::cin >> element;
		seqQueue_push(sQueue, element);
	}
	std::cout << "�ӳ�Ϊ��" << seqQueue_size(sQueue) << std::endl;
	std::cout << "����Ԫ���ǣ�" << seqQueue_front(sQueue) << ",��βԪ���ǣ�" << seqQueue_back(sQueue) << std::endl;
	seqQueue_pop(sQueue);
	std::cout << "���Ӻ�Ķ���Ԫ���ǣ�" << seqQueue_front(sQueue) << std::endl;
	std::cout << "˳����в�����ɣ�����" << std::endl << std::endl;
}

//��ʽ����.��ʼ��
bool linkedQueue_init(linkedQueue& lQueue)
{
	lQueue.front = nullptr;
	lQueue.back = nullptr;
	return true;
}

//��ʽ����.�п�
bool linkedQueue_empty(linkedQueue& lQueue)
{
	return lQueue.front == nullptr;
}

//��ʽ����.���
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

//��ʽ����.����
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

//��ʽ����.�ӳ�
int linkedQueue_size(linkedQueue& lQueue)
{
	int count = 0;
	for (lQNode* ptr = lQueue.front; ptr != nullptr; ptr = ptr->next, count++);
	return count;
}

//��ʽ����.����Ԫ��
lQData linkedQueue_front(linkedQueue& lQueue)
{
	if (linkedQueue_empty(lQueue))
	{
		return -1;
	}
	return lQueue.front->data;
}

//��ʽ����.��βԪ��
lQData linkedQueue_back(linkedQueue& lQueue)
{
	if (linkedQueue_empty(lQueue))
	{
		return - 1;
	}
	return lQueue.back->data;
}

//��ʽ����.����
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

//��ʽ����.����
void test_linkedQueue(void)
{
	linkedQueue lQueue;
	linkedQueue_init(lQueue);
	std::cout << "������Ҫ��ӵ����ݸ�����";
	int num = 0;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		std::cout << "������Ҫ��ӵ����ݣ�";
		lQData data;
		std::cin >> data;
		linkedQueue_push(lQueue, data);
	}
	std::cout << "�ӳ��ǣ�"<<linkedQueue_size(lQueue)<<",���������ǣ�" << linkedQueue_front(lQueue) 
		      << ",��β�����ǣ�" << linkedQueue_back(lQueue) << std::endl;
	linkedQueue_pop(lQueue);
	std::cout << "���Ӻ�Ķӳ��ǣ�" << linkedQueue_size(lQueue) << ",���������ǣ�" << linkedQueue_front(lQueue) << std::endl;
	linkedQueue_destroy(lQueue);
	std::cout << "��ʽ���в�����ɣ�����" << std::endl << std::endl;
}