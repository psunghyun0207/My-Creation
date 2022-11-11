#pragma once
#include <iostream>
using namespace std;

struct Vertex {
	Vertex* next_vertex = 0;
	int num = 0;
	int check = 0;
	int weight = 9999999;
};

void make_Vertex(Vertex* v, int n) { //���� ����
	while (v->next_vertex != nullptr) {
		v = v->next_vertex;
	}
	v->next_vertex = new Vertex;
	v->num = n;
}

void check_Vertex(Vertex* v) { //���� ���� ���� ǥ��
	cout << endl;
	cout << "Vertex Check------------------" << endl;
	while (v->next_vertex != nullptr) {
		cout << v->num << " : check : " << v->check << "     weight : " << v->weight << "     " << endl;
		v = v->next_vertex;
	}
}

void Vertex_Weight(Vertex* v, int num, int weight, int pre_weight, int mx) { //����ġ ������Ʈ, ��ȯȽ�� üũ
	int c = 0;
	while (v->next_vertex != nullptr) {
		if (v->num == num) {
			c = 1;
			break;
		}
		v = v->next_vertex;
	}

	if (c == 1 && v->check != mx) {
		v->check++;
		if (v->weight > weight + pre_weight) v->weight = weight + pre_weight;
	}
	return;
}