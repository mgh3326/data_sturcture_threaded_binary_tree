#pragma once
#include "ThreadedBinNode.h"
#include<cstdlib>
#include<cstdio>
class ThreadBinTree {
	ThreadedBinNode* root;
public:
	ThreadBinTree() : root(NULL) {}
	void setRoot(ThreadedBinNode* node) { root = node; }
	bool isEmpty() { return root == NULL; }

	//스레드 방식의 inoder 방문함수
	void threadedInoder() {
		if (!isEmpty()) {
			printf("스레드 이진트리: ");
			ThreadedBinNode *q = root;
			while (q->getLeft())
				q = q->getLeft();//가장 왼쪽노드로 이동
			do {
				printf("%c ", q->getData());//데이터 출력
				q = findSuccessor(q);
			} while (q);
			printf("\n");
		}
	}
	//후속자 함수 호출
	ThreadedBinNode* findSuccessor(ThreadedBinNode* p) {
		ThreadedBinNode *q = p->getRight();

		//만약 오른쪽 포인터가 NULL 이거나 스레드이면 오른쪽 포인터를 반환
		if (q == NULL || p->bThread)return q;
		//만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
		while (q->getLeft() != NULL)q = q->getLeft();
		return q;
	}
};