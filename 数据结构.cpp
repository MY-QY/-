#include<iostream>
#include<functional>
//线性表
	//线性表的顺序存储结构
typedef int sequentialListEle;
struct sequentialList
{
	sequentialListEle* element = nullptr;
	int length = 0;
	int size = 10;
};
void test_sequentialList();

    //线性表的链式存储结构
typedef int linkedListData;
struct linkedListNode
{
	linkedListData data=0;
	linkedListNode* next=nullptr;
};
void test_linkedList();

    //静态链表
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

//线性表的顺序存储结构.异常1
void sequentialList_exist(sequentialList*& sL)
{
	if (sL == nullptr)
	{
		throw std::string("线性表不存在！！！");
	}
	return;
}

//线性表的顺序存储结构.初始化
void sequentialList_init(sequentialList*& sL, int length)
{
	sL = new sequentialList;
	sL->element = new sequentialListEle[length];
	sL->length = 0;
	sL->size = length;
	return;
}
//线性表的顺序存储结构.销毁
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

//线性表的顺序存储结构.清空
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
//线性表的顺序存储结构.检查是否为空
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

//线性表的顺序存储结构.长度
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

//线性表的顺序存储结构.随机读取
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
		std::cout << "（随机读取）访问越界！！！" << std::endl;
		std::abort();
	}
	return sL->element[pos];
}

//线性表的顺序存储结构.查找元素
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

//线性表的顺序存储结构.插入元素
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
		std::cout << "线性表（顺序存储结构）已满，请扩容！！！" << std::endl;
		return false;
	}
	if (pos > sL->length)
	{
		std::cout << "（插入元素）访问越界！！！" << std::endl;
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

//线性表的顺序存储.删除元素
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
		std::cout << "线性表为空！！！" << std::endl;
		return false;
	}
	if (pos >= sL->length)
	{
		std::cout << "（删除元素）访问越界！！！" << std::endl;
		return false;
	}
	for (int i = pos; i < sL->length-1; i++)
	{
		sL->element[i] = sL->element[i + 1];
	}
	sL->length--;
	return true;
}

//线性表的顺序存储.遍历线性表
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
		std::cout << "线性表为空！！！" << std::endl;
		return;
	}
	for (int i = 0; i < sL->length; i++)
	{
		std::cout << sL->element[i] <<" ";
	}
	return;
}

//线性表的顺序存储.扩容
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

//线性表的顺序存储.测试
void test_sequentialList()
{
	std::cout << std::endl;
	sequentialList* sList = nullptr;
	sequentialList_init(sList, 5);
	for (int i = 0; i < 5; i++)
	{
		sequentialList_insert(sList, sList->length, i);
	}
	std::cout << "初始化后的线性表长度为" << sequentialList_length(sList) << std::endl;
	std::cout << "遍历线性表：" << std::endl;
	sequentialList_traverse(sList);
	std::cout << "最后一个元素是" << sList->element[sList->length - 1] << std::endl;
	sequentialList_delete(sList, sList->length - 1);
	std::cout << "删除最后一个元素后的线性表长度为" << sequentialList_length(sList) << std::endl;
	std::cout << "最后一个元素是" << sList->element[sList->length - 1] << std::endl;
	auto function = [](sequentialListEle x, sequentialListEle y) {return y == x; };
	int value = 0;
	std::cout << "输入要查找的值：";
	std::cin >> value;
	std::cout << sequentialList_find_if(sList, value, function) << std::endl;
	sequentialList_clear(sList);
	std::cout << "清空线性表后的长度为" << sequentialList_length(sList) << std::endl;
	std::cout << "线性表的容量是" << sList->size << std::endl;
	sequentialList_expand(sList,12.5);
	std::cout << "扩容后的容量是" << sList->size << std::endl;
	sequentialList_destroy(sList);
	std::cout << "线性表的顺序存储测试完成！！！" << std::endl;
	return;
}

//线性表的链式存储.初始化
void linkedList_init(linkedListNode*& lL)
{
	lL = new linkedListNode;
	lL->data = 0;
	lL->next = nullptr;
	return;
}

//线性表的链式存储.表长
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

//线性表的链式存储.下标插入
bool linkedList_insert(linkedListNode*& lL, int pos, linkedListData data)
{
	if (pos > linkedList_length(lL) || pos < 0)
	{
		std::cout << "访问越界！！！" << std::endl;
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

//线性表的链式存储.头插法
bool linkedList_headInsert(linkedListNode*& lL, linkedListData data)
{
	linkedListNode* newNode = new linkedListNode;
	newNode->data = data;
	newNode->next = lL->next;
	lL->next = newNode;
	lL->data++;
	return  true;
}

//线性表的链式存储.尾插法
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

//线性表的链式存储.下标删除
bool linkedList_delete(linkedListNode*& lL, int pos)
{
	int i = 0;
	linkedListNode* ptr = lL;
	if (pos > linkedList_length(lL) || pos < 0)
	{
		std::cout << "访问越界！！！" << std::endl;
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

//线性表的链式存储.查找
int linkedList_find(linkedListNode*& lL, linkedListData data)
{
	int count = 1;
	linkedListNode* ptr = lL->next;
	for (; ptr->data != data&&ptr->next!=nullptr; ptr = ptr->next,count++);
	return ptr->next != nullptr ? count : 0;
}

//线性表的链式存储.访问
linkedListData linkedList_getData(linkedListNode*& lL, int pos)
{
	if (linkedList_length(lL) == 0)
	{
		std::cout << "线性表为空！！！";
		std::abort();
	}
	if (pos > linkedList_length(lL) || pos < 0)
	{
		std::cout << "访问越界！！！" << std::endl;
		std::abort();
	}
	int count = 0;
	linkedListNode* ptr = lL;
	for (; count < pos; count++, ptr = ptr->next);
	return ptr->data;
}

//线性表的链式存储.遍历输出
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

//线性表的链式存储.销毁
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

//线性表的链式存储.测试
void test_linkedList()
{
	std::cout << std::endl;
	linkedListNode* lList=nullptr;
	linkedList_init(lList);
	for (int i = 0; i < 10; i++)
	{
		linkedList_tailInsert(lList, i);
	}
	std::cout << "尾插法完成后的线性表长度为" << linkedList_length(lList) << std::endl;
	std::cout << "遍历线性表：";
	linkedList_traverse(lList);
	std::cout << "第二个数据是" << linkedList_getData(lList, 2) << std::endl;
	std::cout << "输入想要查询的数据（1-10）：";
	int data = 0;
	std::cin >> data;
	std::cout << "查询数据为：" << linkedList_find(lList,data) << std::endl;
	linkedList_delete(lList, 2);
	std::cout << "删除第二个数据后的线性表长度为：" << linkedList_length(lList) << std::endl;
	linkedList_destroy(lList);
	std::cout << "线性表的链式存储测试完成！！！" << std::endl;
	return;
}

//静态链表.初始化
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

//静态链表.长度
int staticallyLinkedList_length(sLL& sLL)
{
	int count = 0;
	for (int i = 1; sLL[i].cursor != -1; count++)
	{
		i = sLL[i].cursor;
	}
	return count;
}

//静态链表.分配空间
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

//静态链表.释放空间
void staticallyLinkedList_free(sLL& sLL, int pos)
{
	sLL[pos].cursor = sLL[0].cursor;
	sLL[0].cursor = pos;
	return;
}

//静态链表.下标插入
bool staticallyLinkedList_Insert(sLL& sLL, int pos, sLLData data)
{
	if (pos<1 || pos>staticallyLinkedList_length(sLL))
	{
		std::cout << "插入越界！！！" << std::endl;
		return false;
	}
	int newNode = staticallyLinkedList_malloc(sLL);
	if (newNode == -1)
	{
		std::cout << "空间已满，分配空间失败！！！" << std::endl;
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


//静态链表.头插法
bool staticallyLinkedList_headInsert(sLL& sLL, sLLData data)
{
	int newNode = staticallyLinkedList_malloc(sLL);
	if (newNode == -1)
	{
		std::cout << "空间已满，分配空间失败！！！" << std::endl;
		return false;
	}
	sLL[newNode].data = data;
	sLL[newNode].cursor = sLL[1].cursor;
	sLL[1].cursor = newNode;
	return true;
}

//静态链表.尾插法
bool staticallyLinkedList_tailInsert(sLL& sLL , sLLData data)
{
	int newNode = staticallyLinkedList_malloc(sLL);
	if (newNode == -1)
	{
		std::cout << "空间已满，分配空间失败！！！" << std::endl;
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

//静态链表.删除元素
sLLData staticallyLinkedList_delete(sLL& sLL, int pos)
{
	if (pos<1 || pos>staticallyLinkedList_length(sLL))
	{
		std::cout << "访问越界！！！" << std::endl;
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

//静态链表.查找
int staticallyLinkedList_find(sLL& sLL, sLLData data)
{
	int cur = sLL[1].cursor;
	int pos = 1;
	for (; sLL[cur].data != data && pos <= staticallyLinkedList_length(sLL); cur = sLL[cur].cursor, pos++);
	if (pos > staticallyLinkedList_length(sLL))
	{
		std::cout << "静态链表中未查找到此数据！！！";
	}
	return pos;
}

//静态链表.访问
sLLData staticallyLinkedList_visit(sLL& sLL, int pos)
{
	if (pos<1 || pos>staticallyLinkedList_length(sLL))
	{
		std::cout << "访问越界（将返回最大值）！！！" << std::endl;
		return INT_MAX;
	}
	int cur = 1;
	int i = 0;
	for (; i < pos; i++, cur = sLL[cur].cursor);
	return sLL[cur].data;
}

//静态链表.遍历输出
void staticallyLinkedList_traverse(sLL& sLL)
{
	if (staticallyLinkedList_length == 0)
	{
		std::cout << "静态链表为空！！！" << std::endl;
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

//静态链表.测试
void test_staticallyLinkedList()
{
	sLL sLList;
	staticallyLinkedList_init(sLList);
	for (int i = 0; i < 10; i++)
	{
		sLLData data;
		std::cout << "输入要添加的数据：";
		std::cin >> data;
		staticallyLinkedList_tailInsert(sLList, data);
	}
	std::cout << "静态链表的长度为：" << staticallyLinkedList_length(sLList) << std::endl;
	sLLData da;
	std::cout << "输入想要查找的数据：";
	std::cin >> da;
	std::cout << "所查找数据的下标是：" << staticallyLinkedList_find(sLList, da) << std::endl;
	std::cout << "输入想要查找的数据的序号：";
	int order;
	std::cin >> order;
	std::cout << "序号为" << order << "的位置的数据为：" << staticallyLinkedList_visit(sLList, order) << std::endl;
	std::cout << "遍历输出静态链表：";
	staticallyLinkedList_traverse(sLList);
	staticallyLinkedList_delete(sLList, 3);
	std::cout << "删除第三个数据后的静态链表长度为：" << staticallyLinkedList_length(sLList)
		<< std::endl << "遍历输出删除数据后的静态链表：";
	staticallyLinkedList_traverse(sLList);
	std::cout << std::endl << "静态链表测试完成！！！" << std::endl;
}