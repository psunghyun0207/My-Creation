#pragma once
#include <iostream>
using namespace std;

struct Edge {
	Edge* next_edge = 0;
	Edge* pre_Edge = 0;
	int weight = 0;
	int start = 0;
	int end = 0;
};

void insert_Edge(Edge* e, int st, int ed, int we, int weight_pos) {
	while (e->next_edge != nullptr && e->next_edge->weight != weight_pos) {
		e = e->next_edge;
	}
	if (e->next_edge != nullptr) {
		Edge* temp = new Edge;
		temp->start = st;
		temp->end = ed;
		temp->weight = we;

		temp->next_edge = e->next_edge;
		e->next_edge = temp;
	}
	else {
		e->next_edge = new Edge;
		e->next_edge->start = st;
		e->next_edge->end = ed;
		e->next_edge->weight = we;
	}
}

void make_Edge(Edge* e, int st, int ed, int we) {
	while (e->next_edge != nullptr) {
		if (we < e->next_edge->weight) {
			insert_Edge(e, st, ed, we, e->next_edge->weight);
			return;
		}
		e = e->next_edge;
	}
	e->next_edge = new Edge;

	e->next_edge->start = st;
	e->next_edge->end = ed;
	e->next_edge->weight = we;
}

void view_Edge(Edge* e) {
	cout << endl;
	e = e->next_edge;
	while (e->next_edge != nullptr) {
		cout << "start : " << e->start << "    end : " << e->end << "    weight : " << e->weight << endl;
		e = e->next_edge;
	}
	cout << "start : " << e->start << "    end : " << e->end << "    weight : " << e->weight << endl;
}