#pragma once

using namespace std;

class TNode {
public:
	double val;
	TNode* pNext;
};

class List {
private:
	TNode* pFirst;
public:
	List() {
		pFirst = nullptr;
	}
	~List() {
		while (pFirst != nullptr) {
			TNode* t = pFirst;
			pFirst = pFirst->pNext;
			delete t;
		}
	}
	void push(double a) {
		TNode* node = new TNode;
		node->val = a;
		node->pNext = pFirst;
		pFirst = node;
	}
	double pop() {
		if (pFirst == nullptr)
			throw "error";
		double t= pFirst->val;
		TNode* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		return t;
	}
	double top() {
		if (pFirst == nullptr)
			throw "error";
		return pFirst->val;
	}


	void del_less_average() {
		if (pFirst == nullptr)
			return;
		TNode *prev, *node;
		prev = nullptr;
		node = pFirst;
		double avrg = 0;
		int cnt = 0;
		while (node != nullptr) {
			avrg += node->val;
			cnt++;
			node = node->pNext;
		}
		avrg /= cnt;////cnt!=0
		TNode *thlp;
		node = pFirst;
		while (node != nullptr) {
			if (node->val<avrg){
				thlp = node->pNext;
				delete node;
				if (prev != nullptr)
					prev->pNext = thlp;
				else
					pFirst = thlp;
				node = thlp;
			}
			else {
				prev = node;
				node = node->pNext;
			}
		}
	}

	void print_stdout() {
		TNode* node = pFirst;
		int cnt = 0;
		while (node != nullptr) {
			cnt++;
			node = node->pNext;
		}
		cout << "size = " << cnt << "\n";
		node = pFirst;
		while (node != nullptr) {
			cout << node->val << " ";
			node = node->pNext;
		}
		cout << "\n";
	}
};