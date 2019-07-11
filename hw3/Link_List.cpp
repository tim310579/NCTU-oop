#include <iostream>
#include "Link_List.h"
using namespace std;

template <typename T>
Link_List<T>::Link_List(){
	size=0;
	head=NULL;
	tail=NULL;
}
template <typename T> 
Link_List<T>::Link_List(const Link_List &right){
	int num=right.getSize();
	size=num;
	Int_Node<T>*current;
	Int_Node<T>*temp;
	Int_Node<T>*x=new Int_Node<T>;
	Int_Node<T>*y;
	current=right.head;
	head=x;
	temp=NULL;
	if(right.head==NULL&&right.tail==NULL){
		head=NULL;
		tail==NULL;
		}
	else if(right.head==right.tail){
		x->value=right.head->value;
		x->next=NULL;
		x->pre=NULL;
	}
	else{
		for(int i=0;i<right.size;i++){
			x->pre=temp;
			temp=x;
			x->value=current->value;
			y=new Int_Node<T>;
			x->next=y;
			x=x->next;
			current=current->next;
		}
	}
	


}

template <typename T>
Link_List<T>::~Link_List(){

}
template <typename T>
int Link_List<T>::getSize() const{
	return size;
}
template <typename T>
const Link_List<T> & Link_List<T>::operator =(const Link_List &right){
	int num=right.getSize();
	size=num;
	Int_Node<T>current;
	Int_Node<T>temp;
	Int_Node<T>*x=new Int_Node<T>;
	Int_Node<T>*y;
	current=right.head;
	head=x;
	temp=NULL;
	if(right.head==NULL&&right.tail==NULL){
		head=NULL;
		tail==NULL;
		}
	else if(right.head==right.tail){
		x->value=right.head->value;
		x->next=NULL;
		x->pre=NULL;
	}
	else{
		for(int i=0;i<right.size;i++){
			x->pre=temp;
			temp=x;
			x->value=current->value;
			y=new Int_Node<T>;
			x->next=y;
			x=x->next;
			current=current->next;
		}
	
	}
	

}
template <typename T>
bool Link_List<T>::operator==(const Link_List &a)const{
	Int_Node<T>*current=head;
	Int_Node<T>*temp=a.head;
	
	if(size!=a.getSize()){
		return false;
	}
	for (int i=0;i<a.getSize();i++){
		if(current->value!=temp->value){
			return false;
		}
		current=current->next;
		temp=temp->next;		
	}
	
	return true;
}
template <typename T>
ostream &operator<<(ostream &output, const Link_List<T> &a){
	Int_Node<T>*current=a.head;
	if(current!=NULL){
	
		for(int i=0;i<a.getSize();i++){
			output <<  current->value<<" ";
			current=current->next;	
			if(current==NULL){
				break;
			}
		}
	} 
	
	return output;
} 
template <typename T>
istream &operator>>(istream &input, Link_List<T> &a){
	Int_Node<T>*current=new Int_Node<T>;
	if (a.head==NULL&&a.tail==NULL){
		
		a.head=current;
		a.tail=current;
		a.head->value;
		a.head->next=NULL;
		a.head->pre=NULL;
		a.tail->next=NULL;
		a.tail->pre=NULL;
		input >> a.head->value;;
		a.size++;
	
		
	} 
	else if(a.head==a.tail&&a.tail!=NULL){
		
		current->next=NULL;
		a.tail=current;
		a.tail->next=NULL;
		a.tail->pre=a.head;
		a.head->pre=NULL;
		a.head->next=a.tail;
	
		input >>a.tail->value;
		a.size++;
		
		
		
	}
	else {
		Int_Node<T>*temp=a.head;
		a.head->pre=NULL;
		temp=a.head;
		for(int i=1;i<a.size;i++){
		
		temp=temp->next;
	
		}
		a.tail=temp;
		a.tail->next=current;
		current->next=NULL;
		current->pre=a.tail;
		a.tail=current;
		
		input >> a.tail->value;
		a.size++;
		
		
	}
	return input;
} 
template <typename T>
T &Link_List<T>::operator[](int index){
	Int_Node<T>*current=head;
	if(index==0){
		current = head;
	}
	
	
	for(int i=1;i<size;i++){
		current=current->next;
		if(index==i){
			break;
		}
	}
	return current->value;	
}
template <typename T>
T Link_List<T>::operator[](int index) const{
	Int_Node<T>*current=head;
	if(index==0){
		current = head;
	}
	

	for(int i=1;i<size;i++){
		current=current->next;
		if(index==i){
			break;
		}
	}
	return current->value;	
}
template <typename T>
bool Link_List<T>::insert_node(T value){
	Int_Node<T>*current=new Int_Node<T>;
	if (head==NULL&&tail==NULL){
		
		head=current;
		tail=current;
		head->value=value;
		head->next=NULL;
		head->pre=NULL;
		tail->next=NULL;
		tail->pre=NULL;
		size++;
		return true;
		
	} 
	else if(head==tail&&tail!=NULL){
		
		current->next=NULL;
		tail=current;
		tail->next=NULL;
		tail->pre=head;
		head->pre=NULL;
		head->next=tail;
		tail->value=value;
		size++;
		return true;
		
	}
	else {
		Int_Node<T>*temp=head;
		head->pre=NULL;
		temp=head;
		for(int i=1;i<size;i++){
		
		temp=temp->next;
	
		}
		tail=temp;
		tail->next=current;
		current->next=NULL;
		current->pre=tail;
		tail=current;
		tail->value=value;
		size++;
		return true;
		
	}
	
}
template <typename T>
bool  Link_List<T>::delete_node(){
	Int_Node<T>*current=head;
	if(head==NULL&&tail==NULL){
		return false;
	}
	else if(head==tail){
		head=NULL;
		tail=NULL;
		size=0;
		return true;
	}
	else{
	for(int i=1;i<size;i++){
		current=current->next;
	}
    tail=current->pre;
    
    delete current;
    tail->next=NULL;
    size--;
    return true;
}
}
template <typename T>
bool Link_List<T>::insert_node(int index, T value){
	Int_Node<T>*current=new Int_Node<T>;
	Int_Node<T>*temp=head;
	Int_Node<T>*temp1=head;	
	if(index==0){
		temp=head;
		current->next=temp;
		temp->pre=current;
		head=current;
		head->value=value;
		size++;
	}
	else{
		for(int i=1;i<index;i++){
			temp=temp->next;
		}
		for(int i=0;i<index;i++){
			temp1=temp1->next;
		}
		current->next=temp1;
	
		current->pre=temp;
		temp1->pre=current;
		temp->next=current;
		current->value=value;
		size++;
	}
	return true;
}
template <typename T>
bool Link_List<T>::delete_node(int index){
	Int_Node<T>*current;
	Int_Node<T>*current1;
	Int_Node<T>*temp=head;
	if(index==0){
		temp=head->next;
		delete head;
		current=temp;
		current->pre=NULL;
		head=current;
	}
	else{
	
		for(int i=0;i<index;i++){
			temp=temp->next;
		}
		current=temp->pre;
		current1=temp->next;
		delete temp;
		current->next=current1;
		current1->pre=current;
	}
	size--;
	return true;
}
