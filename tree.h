#pragma once
#include<string>
enum pointerTag{link,thread};

//三叉链表

template <typename T>
class BiTreeNode {
private:
	bool end = false;
	T value=0;
	BiTreeNode<T>* parent = nullptr, * lchild = nullptr, * rchild = nullptr;
	pointerTag tag=link;
public:
	BiTreeNode();
	BiTreeNode(int);
	~BiTreeNode() {};
	T getValue() { return this->value; }
	BiTreeNode<T>* getParent(){ return this->parent; }
	BiTreeNode<T>* getLchild(){ return this->lchild; }
	BiTreeNode<T>* getRchild(){ return this->rchild; }
	pointerTag getTag()const { return tag; }
	T setValue(T t) {
		T old = this->value;
		this->value = t;
		return old;
	}
	BiTreeNode<T>* setParent(BiTreeNode<T>* parent) {
		BiTreeNode<T>* old = this->parent;
		this->parent = parent; 
		return old;
	}
	BiTreeNode<T>* setLchild(BiTreeNode<T>* lchild) {
		BiTreeNode<T>* old = this->lchild;
		this->lchild = lchild; 
		return old;
	};
	BiTreeNode<T>* setRchild( BiTreeNode<T>* rchild) {
		BiTreeNode<T>* old = this->rchild;
		this->rchild = rchild;
		return old;
	}
	pointerTag setTag(const pointerTag&) {
		const pointerTag old = this->tag;
		tag = pointerTag;
		return old;
	}
};

template <typename T>
BiTreeNode<T>::BiTreeNode(int):end(false),value(0),parent(nullptr),lchild(nullptr),rchild(nullptr),tag(link) {
	std::cout << "请输入节点值（$结束，#为空）：" << std::endl;
	if (this->end == true) {
		return;
	}
	std::string str = "";
	std::cin >> str;
	if (str[0] == '$') {
		if(this->getParent()!=nullptr)
		this->getParent()->end = true;
		return;
	}
	else if (str[0] == '#') {
		return;
	}
	else {
		this->setValue((int)std::stoi(str));
		this->setLchild(new BiTreeNode<T>(5));
		this->getLchild()->setParent(this);
		if (this->getLchild()->end == true) {
			return;
		}
		this->setRchild(new BiTreeNode<T>(5));
		this->getRchild()->setParent(this);
	}
}

template <typename T>
class BiTree{
private:
	BiTreeNode<T>* root;
public:
	BiTree();
	BiTree(int);         //先序顺序初始化二叉树
	~BiTree();
	void BiTree_dest_aux(BiTreeNode<T>*);
	void preOrder(void (*)(T t));
	void preOrder_aux(BiTreeNode<T>* ptr, void (*fun)(T t));
};

template <typename T>
BiTree<T>::BiTree() :root(nullptr) {}


template <typename T>
BiTree<T>::BiTree(int):root(nullptr){
	
	std::cout << "是否为空树（y/n）：" << std::endl;
	if (std::cin.get() == 'y') {
		return;
	}
	else {
		this->root = new BiTreeNode<T>(5);
	}
}


template <typename T>
void BiTree<T>::BiTree_dest_aux(BiTreeNode<T>* ptr) {
	if (ptr != nullptr) {
		BiTreeNode<T>* lchild = ptr->getLchild();
		BiTreeNode<T>* rchild = ptr->getRchild();
		delete ptr;
		BiTree_dest_aux(lchild);
		BiTree_dest_aux(rchild);
	}
}

template <typename T>
BiTree<T>::~BiTree() {
	if (this->root == nullptr) {
		return;
	}
	else {
		this->BiTree_dest_aux(this->root);
	}
}

template <typename T>
void show(T t){
	std::cout << t << " ";
}

template <typename T>
void BiTree<T>::preOrder_aux(BiTreeNode<T>* ptr, void (*fun)(T t)) {
	if (ptr != nullptr) {
		BiTreeNode<T>* lchild = ptr->getLchild();
		BiTreeNode<T>* rchild = ptr->getRchild();
		fun(ptr->getValue());
		preOrder_aux(lchild, fun);
		preOrder_aux(rchild, fun);
	}
}

template <typename T>
void BiTree<T>::preOrder(void (* fun)(T t)) {
	if (this->root == nullptr) {
		return;
	}
	else {
		this->preOrder_aux(this->root, fun);
	}
}
