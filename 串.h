#pragma once
//��

//��.�ѷ���                                     
struct HeapAlloString
{
	char* ch;
	int length;
};

//��.�ѷ���.��ʼ��
bool HAString_init(HeapAlloString& HAString)
{
	HAString.length = 0;
	HAString.ch = nullptr;
	return true;
}

//��.�ѷ���.���
void HAString_clear(HeapAlloString& HAString)
{
	if (HAString.ch != nullptr)
	{
		delete[]HAString.ch;
	}
	HAString.ch = nullptr;
	HAString.length = 0;
}

//��.�ѷ���.����
int HAString_length(const HeapAlloString& HAString)
{
	return HAString.length;
}

//��.�ѷ���.��ֵ
bool HAString_assign(HeapAlloString& HAString, char* str)
{
	HAString_clear(HAString);
	int count = strlen(str);
	if (count == 0)
	{
		return true;
	}
	else
	{
		HAString.ch = new char[count + 1];
		if (HAString.ch == nullptr)
		{
			return false;
		}
		for (int i = 0 ; i < count; i++)
		{
			HAString.ch[i] = str[i];
		}
		HAString.ch[count] = '\0';
		HAString.length = count;
		return true;
	}
}

//��.�ѷ���.����
bool HAString_concat(const HeapAlloString& str1,const HeapAlloString& str2, HeapAlloString& HAString)
{
	HAString_clear(HAString);
	if (str1.length + str2.length == 0)
	{
		return true;
	}
	HAString.ch = new char[str1.length + str2.length + 1];
	if (HAString.ch == nullptr)
	{
		return false;
	}
	HAString.length = str1.length + str2.length;
	for (int i = 0; i < str1.length; i++)
	{
		HAString.ch[i] = str1.ch[i];
	}
	for (int i = 0; i < str2.length; i++)
	{
		HAString.ch[str1.length + i] = str2.ch[i];
	}
	HAString.ch[HAString.length] = '\0';
	return true;
}

//��.�ѷ���.�Ƚ�
int HAString_compt(const HeapAlloString& str1, const HeapAlloString& str2)
{
	for (int i = 0; i < str1.length && i < str2.length; i++)
	{
		if (str1.ch[i] != str2.ch[i])
		{
			return str1.ch[i] - str2.ch[i];
		}
	}
	return str1.length - str2.length;
}

//��.�ѷ���.����
bool HAString_destroy(HeapAlloString& HAString)
{
	if (HAString.ch != nullptr)
	{
		delete HAString.ch;
	}
	return true;
}

// ��.�ѷ���.����ƥ��
int HAString_BF(const HeapAlloString& master, const HeapAlloString& pattern)
{
	int i = 0, j = 0;
	for (; i < master.length && j < pattern.length;)
	{
		if (master.ch[i] == pattern.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (pattern.ch[j] == '\0')
	{
		return i - j ;
	}
	return -1;
}

//��.�ѷ���.KMP
int HAString_KMP(const HeapAlloString& master, const HeapAlloString& pattern)
{
	int* next = new int[pattern.length];
	next[0] = -1;
	int i = 0, j = -1;
	while (i < pattern.length-1)
	{
		if (j == -1 || pattern.ch[i] == pattern.ch[j])
		{
			next[++i] = ++j;
//�Ľ���KMP�㷨
/*			if (pattern.ch[i] == pattern.ch[j])
			{
				next[++i] = ++j;
			}
			else
			{
				next[++i] = next[++j];
			}
*/
		}
		else
		{
			j = next[j];
		}
	}
	int cur1 = 0, cur2 = 0;
	while (cur1 < master.length && cur2 < pattern.length)
	{
		if (cur2 == -1 || master.ch[cur1] == pattern.ch[cur2])
		{
			++cur1;
			++cur2;
		}
		else
		{
			cur2 = next[cur2];
		}
	}
	delete[]next;
	if (cur2 >= pattern.length)
	{
		return cur1 - pattern.length;
	}
	else
	{
		return -1;
	}
}

//��ȡ���������ַ�������
char* getStr()
{
	char* str1 = nullptr, * str2 = nullptr;
	int count = 0;
	str1 = new char[count + 1];
	if (str1 == nullptr)
	{
		return nullptr;
	}
	while ((str1[count] = getchar()) != '\n')
	{
		count++;
		str2 = new char[count + 1];
		if (str2 == nullptr)
		{
			return nullptr;
		}
		for (int i = 0; i < count; i++)
		{
			str2[i] = str1[i];
		}
		delete[]str1;
		str1 = new char[count + 1];
		if (str1 == nullptr)
		{
			return nullptr;
		}
		for (int i = 0; i < count; i++)
		{
			str1[i] = str2[i];
		}
		delete[]str2;
	}
	str1[count] = '\0';
	return str1;
}

//��.�ѷ���.����
void test_HeapAlloString()
{
	HeapAlloString HAStringOne, HAStringTwo,HAStringThree,HAString;
	HAString_init(HAStringOne);
	HAString_init(HAStringTwo);
	HAString_init(HAStringThree);
	HAString_init(HAString);
	std::cout << "�����һ���ַ�����";
	char* str1 = getStr();
	std::cout << "����ڶ����ַ�����";
	char* str2 = getStr();
	HAString_assign(HAStringOne, str1);
	HAString_assign(HAStringTwo, str2);
	std::cout << "��һ���ַ����ĳ����ǣ�" << HAString_length(HAStringOne) << "���ڶ����ַ����ĳ����ǣ�" 
		                                  << HAString_length(HAStringTwo) << std::endl;
	HAString_concat(HAStringOne, HAStringTwo, HAString);
	std::cout << "�����ַ���ƴ�Ӻ�Ϊ��" << HAString.ch << std::endl;
	std::cout << "�����ַ����ȽϵĽ��Ϊ��" << HAString_compt(HAStringOne, HAStringTwo) << std::endl;
	std::cout << "������Ҫ�ڵ�һ���ַ����в�ѯ���Ӵ���";
	char* str3 = getStr();
	HAString_assign(HAStringThree, str3);
	std::cout << "BF�㷨�Ľ���ǣ�" << HAString_BF(HAStringOne, HAStringThree) << std::endl;
	std::cout << "KMP�㷨�Ľ���ǣ�" << HAString_KMP(HAStringOne, HAStringThree) << std::endl;
	HAString_clear(HAStringOne);
	std::cout << "��һ���ַ�����պ�ĳ���Ϊ��" << HAStringOne.length << std::endl;
	HAString_destroy(HAStringOne);
	HAString_destroy(HAStringTwo);
	HAString_destroy(HAStringThree);
	HAString_destroy(HAString);
	std::cout << "��.�ѷ��������ɣ�����" << std::endl << std::endl;
}