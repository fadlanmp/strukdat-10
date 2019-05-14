/*
Nama program			: queue
Nama					: Fadlan Mulya Priatna
NPM						: 14081018004
Tanggal pembuatan		: 14 Mei 2019
Deskripsi progrram		: program ini berisikan kodingan Queue menggunakan Single Linked List
*/

#include<iostream>
using namespace std;

struct ElemenQueue {
	char info;
	ElemenQueue* next;
};

typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
	List Head;
	List Tail;
};
Queue Q;

void createQueue (Queue& Q){
	Q.Head=NULL;
    Q.Tail=NULL;
}

void createElmt(pointer& pBaru){
	pBaru= new ElemenQueue;
	cout<<"Masukan satu huruf : ";
	cin>>pBaru->info;
	pBaru->next=NULL;	
}

void insertQueue( Queue& Q, pointer pBaru){
	if (Q.Head==NULL && Q.Tail==NULL) {
		Q.Head = pBaru;
		Q.Tail = pBaru;
	} 
	else {
		Q.Tail->next = pBaru;
		Q.Tail = pBaru;
	}
}

void deleteQueue(Queue& Q, pointer& pHapus){
	cout<<"Delete Queue"<<endl;
	if (Q.Head==NULL && Q.Tail==NULL) {
		pHapus=NULL;
		cout<<"List Queue kosong "<<endl;
	}
	else if (Q.Head->next==NULL) {
		pHapus=Q.Head;
		Q.Head=NULL;
		Q.Tail=NULL;
	}
	else {
		pHapus=Q.Head;
		Q.Head=Q.Head->next;
		pHapus->next=NULL;
	}
}

void printQueue(Queue& Q){
	pointer pTemp = Q.Head;

	while (pTemp != NULL){
    	cout<<pTemp->info<<", ";
        pTemp = pTemp->next;
    }	
}

int main(){
	Queue Q;
	pointer p;
	int antrian;
	
	createQueue(Q);
	
	cout<<"masukkan banyak antrian : ";cin>>antrian;
	for(int i=0; i<antrian; i++){	
	createElmt(p);
	insertQueue(Q, p);
	}
	
	printQueue(Q);
	
}
