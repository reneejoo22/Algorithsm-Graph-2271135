//인접 리스트를 이용한 그래프 구현>> adj_list

#include <stdio.h>
#include <stdlib.h>

#define max_vertices 50

typedef struct GraphNode {
	int vertex; //정점의 갯수
	struct GraphNode* link;	//인접행렬의 이름
}GraphNode;

typedef struct GraphType {
	int vertexNum; //정점의 갯수
	GraphNode* adj_list[max_vertices];	//인접행렬의 이름
}GraphType;


//그래프 초기화
void init(GraphType* g) {

	int r;

	g->vertexNum = 0;	//멤버변수_정점의 갯수 0으로 초기화
	for (r = 0; r < max_vertices; r++) {	//멤버변수_인접행렬 0으로 초기화 
			g->adj_list[r] = 0;
	}

}

//정점 삽입 함수
void insertVertex(GraphType* g, int v) {

	if ((g->vertexNum) + 1 > max_vertices) {
		fprintf(stderr, "그래프의 정점의 개수를 초과함");
		return;
	}
	g->vertexNum++;
}

//간선 삽입
void insert_edge(GraphType* g, int u, int v) {

	GraphNode* node;

	if (u >= g->vertexNum || v >= g->vertexNum) {	//start <= vertexNum <= end 
		fprintf(stderr, "그래프 정점 번호 오류");	//vertexNum은 start랑 end보다 같지 않고 커야됨
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	
	if (node) {
		node->vertex = v;	//정점 칸에 있는 수
		node->link = g->adj_list[u];
		g->adj_list[u] = node;
	}else printf("\n노드가 동적 할당되지 않음\n");
}


//인접 리스트 출력
void print_adjList(GraphType* g) {

	for (int i = 0; i < g->vertexNum; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점%d에 있는 인접 리스트 ", i);
		
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

	for (int i = 0; i < 4; i++) 	//4개의 정점을 삽입할 것
		insertVertex(myGraph, i);

	insert_edge(myGraph, 0, 1);		//0의 인접 리스트에 1이 추가
	insert_edge(myGraph, 1, 0);		//1의 인접 리스트에 0이 추가
	insert_edge(myGraph, 0, 2);		//0의 인접 리스트에 2이 추가
	insert_edge(myGraph, 2, 0);		//2의 인접 리스트에 0이 추가
	insert_edge(myGraph, 0, 3);		//0의 인접 리스트에 3이 추가
	insert_edge(myGraph, 3, 0);
	insert_edge(myGraph, 1, 2);
	insert_edge(myGraph, 2, 1);
	insert_edge(myGraph, 2, 3);
	insert_edge(myGraph, 3, 2);

	print_adjList(myGraph);

	free(myGraph);
}


