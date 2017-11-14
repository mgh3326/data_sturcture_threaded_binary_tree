#include "ThreadedBinNode.h"
#include "ThreadedBinTree.h"//이게 왜 필요하지? include guard에 대해 알아보아야겠다.
void main() {
	ThreadedBinTree tree;
	//			G
	//		C		F
	//	A		B	D	E
	ThreadedBinNode*n1 = new ThreadedBinNode('A', NULL, NULL, true);
	ThreadedBinNode*n2 = new ThreadedBinNode('B', NULL, NULL, true);
	ThreadedBinNode*n3 = new ThreadedBinNode('C', n1, n2, true);
	ThreadedBinNode*n4 = new ThreadedBinNode('D', NULL, NULL, true);
	ThreadedBinNode*n5 = new ThreadedBinNode('E', NULL, NULL, true);
	ThreadedBinNode*n6 = new ThreadedBinNode('F', n4, n5, true);
	ThreadedBinNode*n7 = new ThreadedBinNode('G', n3, n6, true);
	tree.setRoot(n7);
	//스레드 설정
	n1->setRight(n3);
	n2->setRight(n7);
	n4->setRight(n6);
	//중위 순히
	tree.threadedInoder();


}