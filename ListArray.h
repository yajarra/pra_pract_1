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
		
		void resize(int new_size){
              T* lista = new T[new_size];
              for (int i=0; i<n;i++){
                  lista[i]=arr[i];
              }
              max=new_size;
              delete[] arr;
              arr = lista;
 
          }

	public :
		
		ListArray(){
			max=MINSIZE;
			arr = new T[MINSIZE];
			n=0;
		}
		~ListArray() override{
			delete[] arr;
		}

		T operator[](int pos){
			if (pos > n-1 || pos<0){
				throw std::out_of_range("posicion fuera del rango");
				}
			return arr[pos];
			}

		friend std::ostream& operator<<(std::ostream &out,ListArray <T> &list){
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
		void insert(int pos, T e) override {
			  if (pos > n || pos<0){
				throw std::out_of_range("posicion fuera del rango");
			  }	
			if (n+1>max){
				resize(max*2);
			}
			n++;
			T last=arr[pos];
			arr[pos]=e;
			int i;
			for (i=pos;i<n-1;i++){
				T tmp = arr[i+1];
				arr[i+1]=last;
				last=tmp;
			}
		}

	void append(T e) override {
		if (n==max){
			resize(max*2);
			}
		arr[n]=e;
		n++;
	}
	void prepend(T e) override {
		if (n==max){
			resize(max*2);
		}
		n++;
		T last =arr[0];
		arr[0]=e;
		for (int i=0;i<n-1;i++){
			T tmp =arr[i+1];
			arr[i+1]=last;
			last=tmp;
		}
		}
	T remove (int pos) override {
		if (pos<0 || pos>=n){
			throw std::out_of_range("posicion invalida");
		}
		T tmp=arr[pos];
		for (int i=pos;i<n-1;i++){
			arr[i]=arr[i+1];	
		}
		n--;
		return tmp;
	}
	T get (int pos) override {
		if (pos<0 || pos>=n)
			throw std::out_of_range("fuera del rango");
		return arr[pos];
	}
	int search (T e) override {
		for (int i=0; i<n; i++){
			if (arr[i]==e){
				return i;
			}
		}
		return -1;
	}
	bool empty() override {
		if (n==0){
			return true;
		}
		return false;
	}
	int size() override {
		return n;
	}


};
#endif
