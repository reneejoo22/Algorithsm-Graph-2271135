//���� ����� �̿��� �׷��� ����>> adj_mat

#include <stdio.h>
#include <stdlib.h>

#define max_vertices 50

typedef struct GraphType {
	int vertexNum; //������ ����
	int adj_mat[max_vertices][max_vertices];	//��������� �̸�
}GraphType;

//�׷��� �ʱ�ȭ
void init(GraphType* g) {

	int r, c;

	g->vertexNum = 0;	//�������_������ ���� 0���� �ʱ�ȭ

	for (r = 0; r < max_vertices; r++) {	//�������_������� 0���� �ʱ�ȭ 
		for (c = 0; c < max_vertices; c++) {
			g->adj_mat[r][c] = 0;
		}
	}
}

//���� ���� �Լ�
void insertVertex(GraphType* g, int v) {

	if ((g->vertexNum) + 1 > max_vertices) {
		fprintf(stderr, "�׷����� ������ ������ �ʰ���");
		return;
	}
	g->vertexNum++;
}

//���� ����
void insert_edge(GraphType* g, int start, int end) {

	if (start >= g->vertexNum || end >= g->vertexNum) {	//start <= vertexNum <= end 
		fprintf(stderr, "�׷��� ���� ��ȣ ����");	//vertexNum�� start�� end���� ���� �ʰ� Ŀ�ߵ�
		return;
	}

	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


//���� ��� ��� �Լ�
void print_adjMat(GraphType* g) {

	for (int i = 0; i < g->vertexNum; i++) {
		for (int j = 0; j < g->vertexNum; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void main() {

	GraphType* myGraph;

	myGraph = (GraphType*)malloc(sizeof(GraphType));

	init(myGraph);

	for (int i = 0; i < 4; i++) 	//4���� ������ ������ ��
		insertVertex(myGraph, i);

	insert_edge(myGraph, 0, 1);	//0�̶� 1�� �پ�����
	insert_edge(myGraph, 0, 2);	//����� [0][2] �ڸ��� [2][0]�ڸ��� 1�� ����
	insert_edge(myGraph, 0, 3);	//����� [0][3] �ڸ��� [3][0]�ڸ��� 1�� ����
	insert_edge(myGraph, 1, 2);
	insert_edge(myGraph, 2, 3);

	print_adjMat(myGraph);

	free(myGraph);
}

//    g->vertexNum = v; �� ������� �ʴ� ������ �տ� ���� ���ǹ� ������

/*
//���� ���� �Լ�
void insertVertex(GraphType* g, int v) {

	if ((v + 1) > max_vertices) {
		fprintf(stderr, "�׷����� ������ ������ �ʰ���");
		return;
	}
	g->vertexNum = v;
}
//�̷��� ����ϸ� ���� �Լ����� �ݺ��� �Ƚᵵ �� �� ����
//Ʋ���� ���� ������ ����
*/
