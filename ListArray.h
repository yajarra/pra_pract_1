#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
	private : 
		T* arr;
		int max;
		int n;
		static const int MINSIZE =2;
	public : 
		ListArray();
		~ListArray();

		T operator[](int pos){
			if (pos > n-1 || pos<0){
				throw std::out_of_range("posicion fuera del rango");
				}
			return arr[pos];
			}

		friend std::ostream& operator<<(std::ostream &out,ListArray<T> &list){
				out << "List => [";
			for (int i=0; i<list.n; i++){
				out<<list[i];
				if (i<list.n-1){
					out << ",";
				}
			}
			out << "]";
			return out;
		}

		void rezise(int new_size){
			T* lista = new T[new_size];
			for (int i=0; i<n-1;i++){
				lista[i]=arr[i];
			max=new_size;
			delete[] arr;
			arr = lista;
			}
		}
};
#endif
