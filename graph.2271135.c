//���� ����Ʈ�� �̿��� �׷��� ����>> adj_list

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define max_vertices 50

typedef struct GraphType {
	int vertexNum; //������ ����
	int adj_mat[max_vertices][max_vertices];	//��������� �̸�
}GraphType;

int visited[max_vertices];

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

//���� ��ķ� ǥ���� �׷����� ���� �켱 Ž��
void dfs_mat(GraphType* g, int v) {

	int w;
	visited[v] = True;
	printf("���� %d -> ", v);

	for (w = 0; w < g->vertexNum; w++) {
		if (g->adj_mat[v][w] && !visited[w])	//visited�� true�̰� adj_mat�� ���� ������
			//v�� ���� w ���̿� ������ �ְ�, ���� w�� �湮���� �ʾҴٸ�, �ش� ������ ��
			dfs_mat(g, w);
	}

}

int main(void) {

	GraphType* myGraph;
	myGraph = (GraphType*)malloc(sizeof(GraphType));
	init(myGraph);

	for (int i = 0; i < 4; i++) 	//4���� ������ ������ ��
		insertVertex(myGraph, i);

	insert_edge(myGraph, 0, 1);	
	insert_edge(myGraph, 0, 2);		
	insert_edge(myGraph, 0, 3);		
	insert_edge(myGraph, 1, 2);		
	insert_edge(myGraph, 2, 3);

	printf("���� �켱 Ž��\n");
	dfs_mat(myGraph, 0);
	printf("\n");

	free(myGraph);
}


