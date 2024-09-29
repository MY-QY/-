#pragma once
const int MAXSIZE = 100;             //ϡ�����Ԫ�ظ�������
const int MAXRC = 100;               //������������
//��Ԫ��
template<typename T>
struct Triple {
	int row=0, col=0;
	T value=0;
};

//��Ԫ��˳���
template<typename T>
class TSM {
protected:
	Triple<T> data[MAXSIZE + 1];
	int rows, cols, notZeros;

public:
	TSM();
	TSM(int);
	~TSM() {};
	void showTSM()const;
	TSM<T> transpose()const;
	TSM<T> fast_transpose()const;
};

//���߼����ӵ���Ԫ��˳���
template<typename T>
class RLTSM :public TSM<T> {
private:
	int firstOfNotZeros[MAXSIZE + 1];
public:
	RLTSM();
	RLTSM(int);
	~RLTSM() {};
	RLTSM<T> mult_RLTSM(const RLTSM<T>&)const;
	RLTSM<T> operator*(const RLTSM<T>&)const;
};



//��Ա��������

template<typename T>
TSM<T>::TSM() :rows(0), cols(0), notZeros(0) {};

template<typename T>
TSM<T>::TSM(int) {
	std::cout << "�����������";
	std::cin >> this->rows;
	std::cout << std::endl << "�����������";
	std::cin >> this->cols;
	std::cout << std::endl << "����ķ���Ԫ������";
	std::cin >> this->notZeros;
	std::cout << std::endl << "�������Ԫ����Ԫ�飺" << std::endl;
	for (int i = 1; i <= this->notZeros; i++) {
		std::cin >> this->data[i].row >> this->data[i].col >> this->data[i].value;
	}
}

template<typename T>
void TSM<T>::showTSM()const{
	std::cout << std::endl;
	std::cout << "������" << this->rows << "������" << this->cols 
		      << "����Ԫ������" << this->notZeros << std::endl;
	for (int i = 1; i <= this->notZeros; i++)
	{
		std::cout << this->data[i].row << " " << this->data[i].col << " " 
			      << this->data[i].value << std::endl;
	}
	return;
}

//ת��
template<typename T>
TSM<T> TSM<T>::transpose()const{
	TSM<T> result;
	result.cols = this->cols;
	result.rows = this->rows;
	result.notZeros = this->notZeros;
	if (result.notZeros != 0) {
		int notZeros = 1;
		for (int curCol = 1; curCol <= this->cols; curCol++) {
			for (int i = 1; i <= this->notZeros; i++) {
				if (this->data[i].col == curCol) {
					result.data[notZeros].row = this->data[i].col;
					result.data[notZeros].col = this->data[i].row;
					result.data[notZeros].value = this->data[i].value;
					++notZeros;
				}
			}
		}
	}
	return result;
}

//����ת��
template<typename T>
TSM<T> TSM<T>::fast_transpose() const{
	TSM<T> result;
	result.cols = this->cols;
	result.rows = this->rows;
	result.notZeros = this->notZeros;
	//int* num = new int[100] {};
	//int* firstOfNotZeros = new int[100] {};               ????????????????
	int num[MAXSIZE+1] = {};
    int firstOfNotZeros[MAXSIZE+1] = {};
	if (result.notZeros != 0) {
		for (int notZeros = 1; notZeros <= this->notZeros; ++notZeros) {
			++num[this->data[notZeros].col];
		}
		firstOfNotZeros[1] = 1;
		for (int col = 2; col <= this->cols; ++col) {
			firstOfNotZeros[col] = firstOfNotZeros[col - 1] + num[col - 1];
		}
		for (int i = 1; i <= this->notZeros; ++i) {
			int col = this->data[i].col;
			int order = firstOfNotZeros[col];
			result.data[order].row = this->data[i].col;
			result.data[order].col = this->data[i].row;
			result.data[order].value = this->data[i].value;
			++firstOfNotZeros[col];
		}
	}
	//delete num[];
	//delete firstOfNotZeros[];
	return result;
}


template<typename T>
RLTSM<T>::RLTSM() :TSM<T>(), firstOfNotZeros{}{
};


template<typename T>
RLTSM<T>::RLTSM(int) :TSM<T>(6), firstOfNotZeros{}{
	int num[MAXSIZE + 1] = {};
	if (this->notZeros != 0) {
		for (int notZeros = 1; notZeros <= this->notZeros; ++notZeros) {
			++num[this->data[notZeros].row];
		}
		this->firstOfNotZeros[1] = 1;
		for (int col = 2; col <= this->rows; ++col) {
			this->firstOfNotZeros[col] = this->firstOfNotZeros[col - 1] + num[col - 1];
			//std::cout << "��" << col << "�з�����Ԫ����ţ�" << this->firstOfNotZeros[col] << std::endl;
		}
	}
};

template<typename T>
RLTSM<T> RLTSM<T>::mult_RLTSM(const RLTSM<T>& M)const {
	RLTSM<T> result;
	if (this->cols != M.rows) {
		std::cout << "�����޷���ˣ�" << std::endl;
		return result;
	}
	result.rows = this->rows;
	result.cols = M.cols;
	result.notZeros = 0;
	if (this->notZeros * M.notZeros == 0) {
		return result;
	}
	else {
		int cur_row, M_col;
		for (cur_row = 1; cur_row <= this->rows; ++cur_row) {
			//std::cout << "��"<<cur_row<<"��,��һ������Ԫ�����:"<<this->firstOfNotZeros[cur_row] << std::endl;
			int result_tem[MAXRC + 1] = {};
			
			result.firstOfNotZeros[cur_row] = result.notZeros + 1;
			int this_firstOfNextRow;
			if (cur_row < this->rows) {
				this_firstOfNextRow = this->firstOfNotZeros[cur_row + 1];
			}
			else {
				this_firstOfNextRow = this->notZeros + 1;
			}
			//std::cout << "��" << cur_row << "��,��һ�еĵ�һ������Ԫ�����:" << this_firstOfNextRow << std::endl;
			int M_cur_row;
			for (int i = this->firstOfNotZeros[cur_row]; i < this_firstOfNextRow; ++i) {
				M_cur_row = this->data[i].col;
				//std::cout << "M_cur_row:" << M_cur_row << std::endl;
				int M_firstOfNextRow;
				//std::cout <<"M.rows:"<< M.rows << std::endl;
				if (M_cur_row < M.rows) {
					M_firstOfNextRow = M.firstOfNotZeros[M_cur_row + 1];
				}
				else {
					M_firstOfNextRow = M.notZeros + 1;
				}
				//std::cout << "M�ĵ�" << M_cur_row << "��,��һ�еĵ�һ������Ԫ�����:" << M_firstOfNextRow << std::endl;
				for (int j = M.firstOfNotZeros[M_cur_row]; j < M_firstOfNextRow; ++j) {
					M_col = M.data[j].col;
					result_tem[M_col] += ((this->data[i].value) *( M.data[j].value));
					//std::cout << "this->data[i].value:" << this->data[i].value << " "
					//	<< " M.data[j].value:" << M.data[j].value << std::endl;
				}
			}
			for (M_col = 1; M_col <= result.cols; ++M_col) {
				if (result_tem[M_col] != 0) {
					//std::cout << "result_tem[" << M_col << "]:" << result_tem[M_col]<< std::endl;
					if (++result.notZeros > MAXSIZE) {
						return result;
					}
					else {
						result.data[result.notZeros].row = cur_row;
						result.data[result.notZeros].col = M_col;
						result.data[result.notZeros].value = result_tem[M_col];
					}
				}
			}
		}
		return result;
	}
}


template<typename T>
RLTSM<T> RLTSM<T>::operator*(const RLTSM<T>& M)const {
	return this->mult_RLTSM(M);
}
