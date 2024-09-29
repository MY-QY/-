#pragma once
//’ª


//À≥–Ú’ª.æ≤Ã¨∑÷≈‰
const int SS_sSize = 100;
typedef int sS_sEle;
struct seqStack_static
{
	sS_sEle element[SS_sSize];
	int top;
};

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰
const int SS_dSize = 100;
typedef int sS_dData;
struct seqStack_dynamic
{
	sS_dData* top = nullptr;
	sS_dData* base = nullptr;
	int size=0;
};


//¡¥’ª
typedef int lSData;
struct linkedStackNode
{
	lSData data;
	linkedStackNode* next = nullptr;
};

//À≥–Ú’ª.æ≤Ã¨∑÷≈‰.≥ı ºªØ
void seqStack_static_init(seqStack_static& sS_s)
{
	sS_s.top = 0;
}

//À≥–Ú’ª.æ≤Ã¨∑÷≈‰.≈–ø’
bool seqStack_static_empty(seqStack_static& sS_s)
{
	return sS_s.top == 0 ? true : false;
}

//À≥–Ú’ª.æ≤Ã¨∑÷≈‰.»Î’ª
bool seqStack_static_push(seqStack_static& sS_s,sS_sEle ele)
{
	if (sS_s.top == SS_sSize - 1)
	{
		std::cout << "’ª“—¬˙£°£°£°" << std::endl;
		return false;
	}
	else
	{
		sS_s.element[++sS_s.top] = ele;
		return true;
	}
}

//À≥–Ú’ª.æ≤Ã¨∑÷≈‰.≥ˆ’ª
sS_sEle seqStack_static_pop(seqStack_static& sS_s)
{
	if (seqStack_static_empty(sS_s))
	{
		std::cout << "’ªŒ™ø’£°£°£°" << std::endl;
		return -1;
	}
	else
	{
		return sS_s.element[sS_s.top--];
	}
}

//À≥–Ú’ª.æ≤Ã¨∑÷≈‰.’ª∂•‘™Àÿ
sS_sEle seqStack_static_top(seqStack_static& sS_s)
{
	if (seqStack_static_empty(sS_s))
	{
		std::cout << "’ªŒ™ø’£°£°£°" << std::endl;
		return -1;
	}
	return sS_s.element[sS_s.top];
}

//À≥–Ú’ª.æ≤Ã¨∑÷≈‰.≤‚ ‘
void test_seqStack_static(void)
{
	seqStack_static sStack_s;
	seqStack_static_init(sStack_s);
	std::cout << " ‰»Îƒ„œÎ“™»Î’ªµƒ‘™Àÿ∏ˆ ˝£®–°”⁄" << SS_sSize << ")£∫";
	int num = 0;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		std::cout << " ‰»Îƒ„œÎ“™»Î’ªµƒ‘™Àÿ£∫";
		sS_sEle ele;
		std::cin >> ele;
		seqStack_static_push(sStack_s, ele);
	}
	std::cout << "’ª∂•‘™Àÿ «£∫" << seqStack_static_top(sStack_s) << std::endl;
	seqStack_static_pop(sStack_s);
	std::cout<<"…æ≥˝’ª∂•‘™Àÿ∫Ûµƒ’ª∂•‘™Àÿ «£∫"<< seqStack_static_top(sStack_s) << std::endl;
	std::cout << "À≥–Ú’ª.æ≤Ã¨∑÷≈‰≤‚ ‘ÕÍ≥…£°£°!" << std::endl << std::endl;
}

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰.≥ı ºªØ
bool seqStack_dynamic_init(seqStack_dynamic& sS_d)
{
	sS_d.size = SS_dSize;
	sS_d.base = sS_d.top = new sS_dData[sS_d.size];
	if (sS_d.top == nullptr)
	{
		return false;
	}
	return true;
}

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰.≈–ø’
bool seqStack_dynamic_empty(seqStack_dynamic& sS_d)
{
	return sS_d.base == sS_d.top;
}

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰.»Î’ª
bool seqStack_dynamic_push(seqStack_dynamic& sS_d, sS_dData data)
{
	if (sS_d.top - sS_d.base == sS_d.size)
	{
		std::cout << "’ª“—¬˙£°£°£°" << std::endl;
		return false;
	}
	*sS_d.top++ = data;
	return true;
}

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰.≥ˆ’ª
bool seqStack_dynamic_pop(seqStack_dynamic& sS_d)
{
	if (seqStack_dynamic_empty(sS_d))
	{
		std::cout << "’ªŒ™ø’£°£°£°" << std::endl;
		return false;
	}
	return *--sS_d.top;
}

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰.’ª∂•‘™Àÿ
sS_dData seqStack_dynamic_top(seqStack_dynamic& sS_d)
{
	if (seqStack_dynamic_empty(sS_d))
	{
		std::cout << "’ªŒ™ø’£°£°£°" << std::endl;
		return -1;
	}
	return *(sS_d.top-1);
}

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰.¿©»›
bool seqStack_dynamic_expand(seqStack_dynamic& sS_d,double times)
{
	int length = sS_d.top - sS_d.base;
	int newSize = int(sS_d.size * times);
	sS_dData* ptr = sS_d.base;
	sS_d.base = new sS_dData[newSize];
	if (sS_d.base == nullptr)
	{
		return false;
	}
	sS_d.top = sS_d.base;
	for (int i = 0; i < length; i++)
	{
		*sS_d.top++ = ptr[i];
	}
	delete[]ptr;
	sS_d.size = newSize;
	return true;
}

//À≥–Ú’ª.∂ØÃ¨∑÷≈‰.≤‚ ‘
void test_seqStack_dynamic(void)
{
	seqStack_dynamic sStack_d;
	seqStack_dynamic_init(sStack_d);
	std::cout << " ‰»Îƒ„œÎ“™»Î’ªµƒ‘™Àÿ∏ˆ ˝£∫";
	int num = 0;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		sS_dData data;
		std::cout << " ‰»Îƒ„œÎ“™ÃÌº”µƒ ˝æ›£∫";
		std::cin >> data;
		seqStack_dynamic_push(sStack_d, data);
	}
	std::cout << "’ª∂•‘™Àÿ «£∫" << seqStack_dynamic_top(sStack_d) << std::endl;
	seqStack_dynamic_pop(sStack_d);
	seqStack_dynamic_expand(sStack_d,1.333);
	std::cout << "…æ≥˝’ª∂•‘™Àÿ∫Ûµƒ’ª∂•‘™Àÿ «£∫" << seqStack_dynamic_top(sStack_d) << std::endl
		<< "À≥–Ú’ª.∂ØÃ¨∑÷≈‰≤‚ ‘ÕÍ≥…£°£°£°" << std::endl << std::endl;
	return;
}

//¡¥’ª.≥ı ºªØ
bool linkedStack_init(linkedStackNode*& lS)
{
	lS = new linkedStackNode;
	if (lS == nullptr)
	{
		return false;
	}
	lS->next = nullptr;
	return true;
}

//¡¥’ª.≈–ø’
bool linkedStack_empty(linkedStackNode*& lS)
{
	return lS->next == nullptr;
}

//¡¥’ª.»Î’ª
bool linkedStack_push(linkedStackNode*& lS, lSData data)
{
	linkedStackNode* newNode = new linkedStackNode;
	if (newNode == nullptr)
	{
		return false;
	}
	newNode->data = data;
	newNode->next = lS->next;
	lS->next = newNode;
	return true;
}

//¡¥’ª.≥ˆ’ª
lSData linkedStack_pop(linkedStackNode*& lS)
{
	if (linkedStack_empty(lS))
	{
		std::cout << "’ªŒ™ø’£°£°£°" << std::endl;
		return -1;
	}
	lSData data;
	linkedStackNode* ptr = lS->next;
	data = ptr->data;
	lS->next = ptr->next;
	delete ptr;
	return data;
}

//¡¥’ª.’ª∂•‘™Àÿ
lSData linkedStack_top(linkedStackNode*& lS)
{
	if (linkedStack_empty(lS))
	{
		std::cout << "’ªŒ™ø’£°£°£°" << std::endl;
		return -1;
	}
	return lS->next->data;
}

//¡¥’ª.œ˙ªŸ
bool linkedStack_destroy(linkedStackNode*& lS)
{
	linkedStackNode* ptr = lS->next;
	for (; ptr != nullptr;)
	{
		lS->next = ptr->next;
		delete ptr;
		ptr = lS->next;
	}
	delete lS;
	return true;
}

//¡¥’ª.≤‚ ‘
void test_linkedStack(void)
{
	linkedStackNode* lStack = nullptr;
	linkedStack_init(lStack);
	int num = 0;
	std::cout << " ‰»ÎœÎ“™»Î’ªµƒ‘™Àÿ∏ˆ ˝£∫";
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		lSData data;
		std::cout << " ‰»ÎœÎ“™»Î’ªµƒ‘™Àÿ£∫";
		std::cin >> data;
		linkedStack_push(lStack, data);
	}
	std::cout << "’ª∂•‘™Àÿ «£∫" << linkedStack_top(lStack) << std::endl;
	linkedStack_pop(lStack);
	std::cout << "…æ≥˝’ª∂•‘™Àÿ∫Ûµƒ’ª∂•‘™Àÿ «£∫" << linkedStack_top(lStack) << std::endl;
	linkedStack_destroy(lStack);
	std::cout << "¡¥’ª≤‚ ‘ÕÍ≥…£°£°£°" << std::endl << std::endl;
}
