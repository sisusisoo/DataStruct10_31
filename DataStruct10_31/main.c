#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAX_VERTICSES 50
//���� ����Ʈ�� ǥ���� �׷����� ���� �ʺ� �켱 Ž�� 
int visited[MAX_VERTICSES];

typedef struct GraphNode {

	int vertex;
	struct GraphNode* link;

}GraphNode;

typedef struct GraphType {

	int n; // �����ǰ���    
	GraphNode* adj_list[MAX_VERTICSES];

}GraphType;

typedef struct QueueType {

	int element[MAX_VERTICSES];
	int front, rear;
	int size;
}QueueType;

//ť �ʱ�ȭ

void initQueue(QueueType* q) {

	int i;
	q->size = 0;
	q->front = -1;
	q->rear = -1;
	for (i = 0; i < MAX_VERTICSES; i++)
		q->element[i] = 0;
}
//ť ����
void enqueue(QueueType* q, int item) {

	q->element[++(q->rear)] = item;
	q->size++;
}

//ť ����
int dequeue(QueueType* q) {

	int item;
	item = q->element[++(q->front)];
	q->size--;
	return item;
}

void graph_init(GraphType* g) {

	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICSES; v++)
		g->adj_list[v] = NULL;
}
//���� ����
void insert_vertex(GraphType* g, int v) {

	if ((g->n) + 1 > MAX_VERTICSES) {
		printf("�׷���: ���� ���� ");
		return;
	}
	g->n++;
}
//�������� 
void insert_edge(GraphType* g, int u, int v) {//3 2 

	GraphNode* node;
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
//�ݺ� 
void bfs_list(GraphType* g, int v,int last) {

	GraphNode* w;
	QueueType q;
	initQueue(&q);
	visited[v] = TRUE;
	printf(" %d ", v);
	enqueue(&q, v);
	while (q.size != 0) {
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link){
		
			if (!visited[w->vertex]) {
				visited[w->vertex] = TRUE;
				printf("%d ", w->vertex);
				enqueue(&q, w->vertex);
			}
		if (w->vertex == last) return;}
	
		
		
	}
}


int main() {

	int i;
	GraphType g;
	graph_init(&g);

	for (i = 0; i < 11; i++) {
		insert_vertex(&g, i);
	}
	int sel;
	insert_edge(&g, 0, 6);
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 5);
	insert_edge(&g, 0, 9);


	insert_edge(&g, 1, 5);
	insert_edge(&g, 1, 4);
	insert_edge(&g, 1, 7);
	insert_edge(&g, 1, 10);

	insert_edge(&g, 2, 0);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 4);

	insert_edge(&g, 3, 5);
	insert_edge(&g, 3, 2);
	insert_edge(&g, 3, 4);

	insert_edge(&g, 4, 0);
	insert_edge(&g, 4, 2);
	insert_edge(&g, 4, 3);
	insert_edge(&g, 4, 5);
	insert_edge(&g, 4, 1);
	insert_edge(&g, 4, 7);
	insert_edge(&g, 4, 6);

	insert_edge(&g, 5, 0);
	insert_edge(&g, 5, 3);
	insert_edge(&g, 5, 4);
	insert_edge(&g, 5, 1);

	insert_edge(&g, 6, 0);
	insert_edge(&g, 6, 4);
	insert_edge(&g, 6, 7);
	insert_edge(&g, 6, 8);

	insert_edge(&g, 7, 4);
	insert_edge(&g, 7, 6);
	insert_edge(&g, 7, 1);
	insert_edge(&g, 7, 10);

	insert_edge(&g, 8, 9);
	insert_edge(&g, 8, 6);
	insert_edge(&g, 8, 10);
	
	insert_edge(&g, 9, 8);
	insert_edge(&g, 9, 0);

	insert_edge(&g, 9, 8);
	insert_edge(&g, 9, 0);


	insert_edge(&g, 10, 7);
	insert_edge(&g, 10, 1);
	insert_edge(&g, 10, 8);

	bfs_list(&g, 1, 9);

	int star, stop;
	//printf("�޴��Է�:");
	scanf_s("%d", &sel);
	printf("���۹�ȣ Ž�� �� �Է�:");
	//scanf_s("%d", &sel);











}