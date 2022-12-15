#include<iostream>
#include<functional>
//���Ա�
	//���Ա��˳��洢�ṹ
typedef int sequentialListEle;
struct sequentialList
{
	sequentialListEle* element = nullptr;
	int length = 0;
	int size = 10;
};
void test_sequentialList();

    //���Ա����ʽ�洢�ṹ
typedef int linkedListData;
struct linkedListNode
{
	linkedListData data=0;
	linkedListNode* next=nullptr;
};
void test_linkedList();

    //��̬����
const int SLLSize = 1000;
typedef int sLLData;
typedef struct
{
	sLLData data = -1;
	int cursor = -1;
}sLL[SLLSize];
void test_staticallyLinkedList();

int main()
{
	//test_sequentialList();
	//test_linkedList();
	test_staticallyLinkedList();
	return 0;
}

//���Ա��˳��洢�ṹ.�쳣1
void sequentialList_exist(sequentialList*& sL)
{
	if (sL == nullptr)
	{
		throw std::string("���Ա����ڣ�����");
	}
	return;
}

//���Ա��˳��洢�ṹ.��ʼ��
void sequentialList_init(sequentialList*& sL, int length)
{
	sL = new sequentialList;
	sL->element = new sequentialListEle[length];
	sL->length = 0;
	sL->size = length;
	return;
}
//���Ա��˳��洢�ṹ.����
void sequentialList_destroy(sequentialList*& sL)
{
	if (sL == nullptr)
	{
		return;
	}
	if (sL->element != nullptr)
	{
		delete[]sL->element;
	}
	delete[]sL;
	sL = nullptr;
	return;
}

//���Ա��˳��洢�ṹ.���
void sequentialList_clear(sequentialList*& sL)
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		std::abort();
	}
	if (sL->element != nullptr)
	{
		delete[]sL->element;
		sL->element = nullptr;
	}
	sL->length = 0;
	return;
	
}
//���Ա��˳��洢�ṹ.����Ƿ�Ϊ��
bool sequentialList_empty(sequentialList*& sL)
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		std::abort();
	}
	if (sL->length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���Ա��˳��洢�ṹ.����
int sequentialList_length(sequentialList*& sL)
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		std::abort();
	}
	return sL->length;
}

//���Ա��˳��洢�ṹ.�����ȡ
sequentialListEle sequentialList_getEle(sequentialList*& sL, int pos)
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		std::abort();
	}
	if (pos >= sL->length)
	{
		std::cout << "�������ȡ������Խ�磡����" << std::endl;
		std::abort();
	}
	return sL->element[pos];
}

//���Ա��˳��洢�ṹ.����Ԫ��
int sequentialList_find_if(sequentialList*& sL, sequentialListEle ele,bool (*compare)(sequentialListEle a,sequentialListEle b))
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		std::abort();
	}
	int i = 0;
	for (i = 0; i < sL->length; i++)
	{
		if (compare(sL->element[i],ele))
		{
			return i;
		}
	}
	if (i == sL->length)
	{
		return sL->length;
	}
}

//���Ա��˳��洢�ṹ.����Ԫ��
bool sequentialList_insert(sequentialList*& sL, int pos, sequentialListEle ele)
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		return false;
	}
	if (sL->length == sL->size)
	{
		std::cout << "���Ա�˳��洢�ṹ�������������ݣ�����" << std::endl;
		return false;
	}
	if (pos > sL->length)
	{
		std::cout << "������Ԫ�أ�����Խ�磡����" << std::endl;
		return false;
	}
	for (int i = sL->length; i > pos; i--)
	{
		sL->element[i] = sL->element[i - 1];
	}
	sL->element[pos] = ele;
	sL->length++;
	return true;
}

//���Ա��˳��洢.ɾ��Ԫ��
bool sequentialList_delete(sequentialList*& sL, int pos)
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		return false;
	}
	if (sequentialList_empty(sL))
	{
		std::cout << "���Ա�Ϊ�գ�����" << std::endl;
		return false;
	}
	if (pos >= sL->length)
	{
		std::cout << "��ɾ��Ԫ�أ�����Խ�磡����" << std::endl;
		return false;
	}
	for (int i = pos; i < sL->length-1; i++)
	{
		sL->element[i] = sL->element[i + 1];
	}
	sL->length--;
	return true;
}

//���Ա��˳��洢.�������Ա�
void sequentialList_traverse(sequentialList*& sL)
{
	try
	{
		sequentialList_exist(sL);
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		return;
	}
	if (sequentialList_empty(sL))
	{
		std::cout << "���Ա�Ϊ�գ�����" << std::endl;
		return;
	}
	for (int i = 0; i < sL->length; i++)
	{
		std::cout << sL->element[i] <<" ";
	}
	return;
}

//���Ա��˳��洢.����
void sequentialList_expand(sequentialList*& sL,double times)
{
	int n = sL->length;
	sequentialListEle* arr = new sequentialListEle[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = sL->element[i];
	}
	delete[]sL->element;
	sL->element = new sequentialListEle[n * times];
	for (int i = 0; i < n; i++)
	{
		sL->element[i] = arr[i];
	}
	delete[]arr;
	sL->size *= times;
}

//���Ա��˳��洢.����
void test_sequentialList()
{
	std::cout << std::endl;
	sequentialList* sList = nullptr;
	sequentialList_init(sList, 5);
	for (int i = 0; i < 5; i++)
	{
		sequentialList_insert(sList, sList->length, i);
	}
	std::cout << "��ʼ��������Ա���Ϊ" << sequentialList_length(sList) << std::endl;
	std::cout << "�������Ա�" << std::endl;
	sequentialList_traverse(sList);
	std::cout << "���һ��Ԫ����" << sList->element[sList->length - 1] << std::endl;
	sequentialList_delete(sList, sList->length - 1);
	std::cout << "ɾ�����һ��Ԫ�غ�����Ա���Ϊ" << sequentialList_length(sList) << std::endl;
	std::cout << "���һ��Ԫ����" << sList->element[sList->length - 1] << std::endl;
	auto function = [](sequentialListEle x, sequentialListEle y) {return y == x; };
	int value = 0;
	std::cout << "����Ҫ���ҵ�ֵ��";
	std::cin >> value;
	std::cout << sequentialList_find_if(sList, value, function) << std::endl;
	sequentialList_clear(sList);
	std::cout << "������Ա��ĳ���Ϊ" << sequentialList_length(sList) << std::endl;
	std::cout << "���Ա��������" << sList->size << std::endl;
	sequentialList_expand(sList,12.5);
	std::cout << "���ݺ��������" << sList->size << std::endl;
	sequentialList_destroy(sList);
	std::cout << "���Ա��˳��洢������ɣ�����" << std::endl;
	return;
}

//���Ա����ʽ�洢.��ʼ��
void linkedList_init(linkedListNode*& lL)
{
	lL = new linkedListNode;
	lL->data = 0;
	lL->next = nullptr;
	return;
}

//���Ա����ʽ�洢.��
int linkedList_length(linkedListNode*& lL)
{
	int count = 0;
	linkedListNode* ptr = lL;
	while (ptr->next != nullptr)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

//���Ա����ʽ�洢.�±����
bool linkedList_insert(linkedListNode*& lL, int pos, linkedListData data)
{
	if (pos > linkedList_length(lL) || pos < 0)
	{
		std::cout << "����Խ�磡����" << std::endl;
		std::abort();
	}
	int i = 0;
	linkedListNode* ptr = lL;
	linkedListNode* newNode = new linkedListNode;
	newNode->data = data;
	for (i = 0; i < pos - 1 && ptr != nullptr; i++)
	{
		ptr = ptr->next;
	}
	if (ptr == nullptr || i > pos - 1)
	{
		delete newNode;
		return false;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
	lL->data++;
	return true;
}

//���Ա����ʽ�洢.ͷ�巨
bool linkedList_headInsert(linkedListNode*& lL, linkedListData data)
{
	linkedListNode* newNode = new linkedListNode;
	newNode->data = data;
	newNode->next = lL->next;
	lL->next = newNode;
	lL->data++;
	return  true;
}

//���Ա����ʽ�洢.β�巨
bool linkedList_tailInsert(linkedListNode* lL, linkedListData data)
{
	linkedListNode* ptr = lL;
	linkedListNode* newNode = new linkedListNode;
	newNode->data = data;
	newNode->next = nullptr;
	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
	}
	ptr->next = newNode;
	lL->data++;
	return true;
}

//���Ա����ʽ�洢.�±�ɾ��
bool linkedList_delete(linkedListNode*& lL, int pos)
{
	int i = 0;
	linkedListNode* ptr = lL;
	if (pos > linkedList_length(lL) || pos < 0)
	{
		std::cout << "����Խ�磡����" << std::endl;
		std::abort();
	}
	for (i = 0; i < pos - 1 && ptr != nullptr; i++)
	{
		ptr = ptr->next;
	}
	if (ptr == nullptr || i > pos - 1)
	{
		return false;
	}
	linkedListNode* nextPtr = ptr->next;
	ptr->next = nextPtr->next;
	delete nextPtr;
	return true;
}

//���Ա����ʽ�洢.����
int linkedList_find(linkedListNode*& lL, linkedListData data)
{
	int count = 1;
	linkedListNode* ptr = lL->next;
	for (; ptr->data != data&&ptr->next!=nullptr; ptr = ptr->next,count++);
	return ptr->next != nullptr ? count : 0;
}

//���Ա����ʽ�洢.����
linkedListData linkedList_getData(linkedListNode*& lL, int pos)
{
	if (linkedList_length(lL) == 0)
	{
		std::cout << "���Ա�Ϊ�գ�����";
		std::abort();
	}
	if (pos > linkedList_length(lL) || pos < 0)
	{
		std::cout << "����Խ�磡����" << std::endl;
		std::abort();
	}
	int count = 0;
	linkedListNode* ptr = lL;
	for (; count < pos; count++, ptr = ptr->next);
	return ptr->data;
}

//���Ա����ʽ�洢.�������
void linkedList_traverse(linkedListNode*& lL)
{
	linkedListNode* ptr=lL->next;
	while (ptr != nullptr)
	{
		std::cout << ptr->data <<" ";
		ptr = ptr->next;
	}
	return;
}

//���Ա����ʽ�洢.����
bool linkedList_destroy(linkedListNode*& lL)
{
	linkedListNode* ptr = lL->next;
	while (lL->next != nullptr)
	{
		lL->next = ptr->next;
		delete ptr;
		ptr = lL->next;
	}
	delete lL;
	return true;
}

//���Ա����ʽ�洢.����
void test_linkedList()
{
	std::cout << std::endl;
	linkedListNode* lList=nullptr;
	linkedList_init(lList);
	for (int i = 0; i < 10; i++)
	{
		linkedList_tailInsert(lList, i);
	}
	std::cout << "β�巨��ɺ�����Ա���Ϊ" << linkedList_length(lList) << std::endl;
	std::cout << "�������Ա�";
	linkedList_traverse(lList);
	std::cout << "�ڶ���������" << linkedList_getData(lList, 2) << std::endl;
	std::cout << "������Ҫ��ѯ�����ݣ�1-10����";
	int data = 0;
	std::cin >> data;
	std::cout << "��ѯ����Ϊ��" << linkedList_find(lList,data) << std::endl;
	linkedList_delete(lList, 2);
	std::cout << "ɾ���ڶ������ݺ�����Ա���Ϊ��" << linkedList_length(lList) << std::endl;
	linkedList_destroy(lList);
	std::cout << "���Ա����ʽ�洢������ɣ�����" << std::endl;
	return;
}

//��̬����.��ʼ��
void staticallyLinkedList_init(sLL& sLL)
{

	for (int i = 0; i < SLLSize - 1; i++)
	{
		sLL[i].cursor = i + 1;
	}
	sLL[SLLSize - 1].cursor = -1;
	sLL[0].cursor = sLL[1].cursor;
	sLL[1].cursor = -1;
	return;
}

//��̬����.����
int staticallyLinkedList_length(sLL& sLL)
{
	int count = 0;
	for (int i = 1; sLL[i].cursor != -1; count++)
	{
		i = sLL[i].cursor;
	}
	return count;
}

//��̬����.����ռ�
int staticallyLinkedList_malloc(sLL& sLL)
{
	int cur = sLL[0].cursor;
	if (cur != -1)
	{
		sLL[0].cursor = sLL[cur].cursor;
		return cur;
	}
	else
	{
		return -1;
	}
}

//��̬����.�ͷſռ�
void staticallyLinkedList_free(sLL& sLL, int pos)
{
	sLL[pos].cursor = sLL[0].cursor;
	sLL[0].cursor = pos;
	return;
}

//��̬����.�±����
bool staticallyLinkedList_Insert(sLL& sLL, int pos, sLLData data)
{
	if (pos<1 || pos>staticallyLinkedList_length(sLL))
	{
		std::cout << "����Խ�磡����" << std::endl;
		return false;
	}
	int newNode = staticallyLinkedList_malloc(sLL);
	if (newNode == -1)
	{
		std::cout << "�ռ�����������ռ�ʧ�ܣ�����" << std::endl;
		return false;
	}
	int preCur = 1, count = 0;
	for (; count < pos - 1; count++)
	{
		preCur = sLL[preCur].cursor;
	}
	sLL[newNode].cursor = sLL[preCur].cursor;
	sLL[preCur].cursor = newNode;
	return true;
}


//��̬����.ͷ�巨
bool staticallyLinkedList_headInsert(sLL& sLL, sLLData data)
{
	int newNode = staticallyLinkedList_malloc(sLL);
	if (newNode == -1)
	{
		std::cout << "�ռ�����������ռ�ʧ�ܣ�����" << std::endl;
		return false;
	}
	sLL[newNode].data = data;
	sLL[newNode].cursor = sLL[1].cursor;
	sLL[1].cursor = newNode;
	return true;
}

//��̬����.β�巨
bool staticallyLinkedList_tailInsert(sLL& sLL , sLLData data)
{
	int newNode = staticallyLinkedList_malloc(sLL);
	if (newNode == -1)
	{
		std::cout << "�ռ�����������ռ�ʧ�ܣ�����" << std::endl;
		return false;
	}
	else
	{
		sLL[newNode].data = data;
		sLL[newNode].cursor = -1;
		int currentCursor = 1;
		for (currentCursor = 1; sLL[currentCursor].cursor != -1; currentCursor = sLL[currentCursor].cursor);
		sLL[currentCursor].cursor = newNode;
		return true;
	}
}

//��̬����.ɾ��Ԫ��
sLLData staticallyLinkedList_delete(sLL& sLL, int pos)
{
	if (pos<1 || pos>staticallyLinkedList_length(sLL))
	{
		std::cout << "����Խ�磡����" << std::endl;
		return INT_MAX;
	}
	int preCur = 1, count = 0;
	for (; count < pos - 1; count++)
	{
		preCur = sLL[preCur].cursor;
	}
	int currentCur = sLL[preCur].cursor;
	sLL[preCur].cursor = sLL[currentCur].cursor;
	staticallyLinkedList_free(sLL, currentCur);
}

//��̬����.����
int staticallyLinkedList_find(sLL& sLL, sLLData data)
{
	int cur = sLL[1].cursor;
	int pos = 1;
	for (; sLL[cur].data != data && pos <= staticallyLinkedList_length(sLL); cur = sLL[cur].cursor, pos++);
	if (pos > staticallyLinkedList_length(sLL))
	{
		std::cout << "��̬������δ���ҵ������ݣ�����";
	}
	return pos;
}

//��̬����.����
sLLData staticallyLinkedList_visit(sLL& sLL, int pos)
{
	if (pos<1 || pos>staticallyLinkedList_length(sLL))
	{
		std::cout << "����Խ�磨���������ֵ��������" << std::endl;
		return INT_MAX;
	}
	int cur = 1;
	int i = 0;
	for (; i < pos; i++, cur = sLL[cur].cursor);
	return sLL[cur].data;
}

//��̬����.�������
void staticallyLinkedList_traverse(sLL& sLL)
{
	if (staticallyLinkedList_length == 0)
	{
		std::cout << "��̬����Ϊ�գ�����" << std::endl;
		return;
	}
	else
	{
		for (int cur = sLL[1].cursor; cur != -1; cur=sLL[cur].cursor)
		{
			std::cout << sLL[cur].data << " ";
		}
		return;
	}
}

//��̬����.����
void test_staticallyLinkedList()
{
	sLL sLList;
	staticallyLinkedList_init(sLList);
	for (int i = 0; i < 10; i++)
	{
		sLLData data;
		std::cout << "����Ҫ��ӵ����ݣ�";
		std::cin >> data;
		staticallyLinkedList_tailInsert(sLList, data);
	}
	std::cout << "��̬����ĳ���Ϊ��" << staticallyLinkedList_length(sLList) << std::endl;
	sLLData da;
	std::cout << "������Ҫ���ҵ����ݣ�";
	std::cin >> da;
	std::cout << "���������ݵ��±��ǣ�" << staticallyLinkedList_find(sLList, da) << std::endl;
	std::cout << "������Ҫ���ҵ����ݵ���ţ�";
	int order;
	std::cin >> order;
	std::cout << "���Ϊ" << order << "��λ�õ�����Ϊ��" << staticallyLinkedList_visit(sLList, order) << std::endl;
	std::cout << "���������̬����";
	staticallyLinkedList_traverse(sLList);
	staticallyLinkedList_delete(sLList, 3);
	std::cout << "ɾ�����������ݺ�ľ�̬������Ϊ��" << staticallyLinkedList_length(sLList)
		<< std::endl << "�������ɾ�����ݺ�ľ�̬����";
	staticallyLinkedList_traverse(sLList);
	std::cout << std::endl << "��̬���������ɣ�����" << std::endl;
}