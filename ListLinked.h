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

};

#endif
