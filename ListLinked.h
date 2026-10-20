#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
		Node<T>* first;
		int n;

    public:
		T data;
		Node <T>* next;
        ListLinked();
		~ListLinked(){
			for (int i=0;i<n;i++){
				Node<T>* aux=first->next;
				delete first;
				first=aux;
			}
		}
		T operator[](int pos){
			if (pos >n-1 || pos <0){
				throw std::out_of_range("fuera del rango");
			}
			Node<T>* tmp=first;
			int i=0;
			while ( i!=pos){
				tmp=tmp->next;
				i++;
			}
			return tmp->data;
		}

		friend std::ostream& operator<<(std::ostream &out,ListLinked &list){
			out << "secuencia";
		Node<T>* tmp=list.first;
		for (int i=0; i<list.n;i++){
			out<<tmp;
			tmp=tmp->next;
		}
		out<<tmp;
		return out;
		}

		int size() {
    return n;
}

bool empty() {
    return n == 0;
}

T get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("fuera del rango");
    }

    Node<T>* tmp = first;

    for (int i = 0; i < pos; i++) {
        tmp = tmp->next;
    }

    return tmp->data;
}

void prepend(T e) {
    Node<T>* nuevo = new Node<T>(e);

    nuevo->next = first;
    first = nuevo;

    n++;
}

void append(T e) {
    Node<T>* nuevo = new Node<T>(e);

    if (first == nullptr) {
        first = nuevo;
    } else {
        Node<T>* tmp = first;

        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }

        tmp->next = nuevo;
    }

    n++;
}

void insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("fuera del rango");
    }

    if (pos == 0) {
		prepend(e);
        return;
    }

    Node<T>* tmp = first;

    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }

    Node<T>* nuevo = new Node<T>(e);

    nuevo->next = tmp->next;
    tmp->next = nuevo;

    n++;
}

void remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("fuera del rango");
    }

    Node<T>* borrar;

    if (pos == 0) {
        borrar = first;
        first = first->next;
    } else {
        Node<T>* tmp = first;

        for (int i = 0; i < pos - 1; i++) {
            tmp = tmp->next;
        }

        borrar = tmp->next;
        tmp->next = borrar->next;
    }

    delete borrar;
    n--;
}

int search(T e) {
    Node<T>* tmp = first;
    int pos = 0;

    while (tmp != nullptr) {
        if (tmp->data == e) {
            return pos;
        }

        tmp = tmp->next;
        pos++;
    }

    return -1;
}
};

#endif
