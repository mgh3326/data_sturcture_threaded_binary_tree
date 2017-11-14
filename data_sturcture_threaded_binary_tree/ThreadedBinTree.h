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

	//������ ����� inoder �湮�Լ�
	void threadedInoder() {
		if (!isEmpty()) {
			printf("������ ����Ʈ��: ");
			ThreadedBinNode *q = root;
			while (q->getLeft())
				q = q->getLeft();//���� ���ʳ��� �̵�
			do {
				printf("%c ", q->getData());//������ ���
				q = findSuccessor(q);
			} while (q);
			printf("\n");
		}
	}
	//�ļ��� �Լ� ȣ��
	ThreadedBinNode* findSuccessor(ThreadedBinNode* p) {
		ThreadedBinNode *q = p->getRight();

		//���� ������ �����Ͱ� NULL �̰ų� �������̸� ������ �����͸� ��ȯ
		if (q == NULL || p->bThread)return q;
		//���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
		while (q->getLeft() != NULL)q = q->getLeft();
		return q;
	}
};