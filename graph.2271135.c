//���� ����Ʈ�� �̿��� �׷��� ����>> adj_list

#include <stdio.h>
#include <stdlib.h>

#define max_vertices 50

typedef struct GraphNode {
	int vertex; //������ ����
	struct GraphNode* link;	//��������� �̸�
}GraphNode;

typedef struct GraphType {
	int vertexNum; //������ ����
	GraphNode* adj_list[max_vertices];	//��������� �̸�
}GraphType;


//�׷��� �ʱ�ȭ
void init(GraphType* g) {

	int r;

	g->vertexNum = 0;	//�������_������ ���� 0���� �ʱ�ȭ
	for (r = 0; r < max_vertices; r++) {	//�������_������� 0���� �ʱ�ȭ 
			g->adj_list[r] = 0;
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
void insert_edge(GraphType* g, int u, int v) {

	GraphNode* node;

	if (u >= g->vertexNum || v >= g->vertexNum) {	//start <= vertexNum <= end 
		fprintf(stderr, "�׷��� ���� ��ȣ ����");	//vertexNum�� start�� end���� ���� �ʰ� Ŀ�ߵ�
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	
	if (node) {
		node->vertex = v;	//���� ĭ�� �ִ� ��
		node->link = g->adj_list[u];
		g->adj_list[u] = node;
	}else printf("\n��尡 ���� �Ҵ���� ����\n");
}


//���� ����Ʈ ���
void print_adjList(GraphType* g) {

	for (int i = 0; i < g->vertexNum; i++) {
		GraphNode* p = g->adj_list[i];
		printf("����%d�� �ִ� ���� ����Ʈ ", i);
		
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main() {

	GraphType* myGraph;
	myGraph = (GraphType*)malloc(sizeof(GraphType));
	init(myGraph);

	for (int i = 0; i < 4; i++) 	//4���� ������ ������ ��
		insertVertex(myGraph, i);

	insert_edge(myGraph, 0, 1);		//0�� ���� ����Ʈ�� 1�� �߰�
	insert_edge(myGraph, 1, 0);		//1�� ���� ����Ʈ�� 0�� �߰�
	insert_edge(myGraph, 0, 2);		//0�� ���� ����Ʈ�� 2�� �߰�
	insert_edge(myGraph, 2, 0);		//2�� ���� ����Ʈ�� 0�� �߰�
	insert_edge(myGraph, 0, 3);		//0�� ���� ����Ʈ�� 3�� �߰�
	insert_edge(myGraph, 3, 0);
	insert_edge(myGraph, 1, 2);
	insert_edge(myGraph, 2, 1);
	insert_edge(myGraph, 2, 3);
	insert_edge(myGraph, 3, 2);

	print_adjList(myGraph);

	free(myGraph);
}


