/*
Nama program			: queue
Nama					: Fadlan Mulya Priatna
NPM						: 140810180041
Tanggal pembuatan		: 14 Mei 2019
Deskripsi progrram		: program ini berisikan kodingan queue menggunakan array
*/

#include <iostream>
using namespace std;

const int maxElement=255;

struct queue{
	char isi[maxElement];
	int head;
	int tail;
};
queue q;

void createElement(queue& q){
	q.head=0;
	q.tail=-1;
}

void insertQueue(queue& q, char element,int n){
	if(q.tail==n-1){
		cout<<"antrian penuh";
	}
	else{
		q.tail=q.tail+1;
		q.isi[q.tail]=element;
	}
}

void deleteQueue(queue& q,char& elementHapus){
	if(q.head>q.tail){
		cout<<"antrian kosong"<<endl;
	}
	else{
		elementHapus=q.isi[q.head];
		for(int i=0;i<q.tail;i++){
			q.isi[i]=q.isi[i+1];
		}
		q.tail=q.tail-1;
	}
}

int main(){
	int n,k;
	char b;
	cout<<"Masukan banyak antrian = ";cin>>n;
	createElement(q);
	for(int i=0;i<n;i++){
		cout<<"antrian ke- "<<i+1<<" = ";cin>>b;
		insertQueue(q,b,n);
	}
	
	cout<<"antrian"<<endl;
	for(int i=q.head;i<=q.tail;i++){
		cout<<q.isi[i]<<",";
	}
	cout<<endl;
	
	cout<<"Masukan jumlah antrian yang akan ditukar dari depan = ";cin>>k;
	for(int i=0;i<=q.tail;i++){
		if(i<k){
			cout<<q.isi[k-1-i]<<",";
		}
		else{
			cout<<q.isi[i]<<",";
		}
	}
}
