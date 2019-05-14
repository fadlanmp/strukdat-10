/*
Nama program			: Tree
Nama					: Fadlan Mulya Priatna
NPM						: 140810180041 
Tanggal pembuatan		: 14 Mei 2019
Deskripsi progrram		: program ini berisikan kodingan Tree
*/

#include<iostream>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul(pointer& pBaru){
    pBaru=new Simpul;
    cout<<"Masukkan satu angka : ";
    cin>>pBaru->info;
    pBaru->left=NULL;
    pBaru->right=NULL;
}
void insertBST (Tree& Root, pointer pBaru){
    if(Root==NULL){
        Root=pBaru;
    }
    else if (pBaru->info < Root->info){
        insertBST(Root->left,pBaru);
    }
    else if (pBaru->info > Root->info){
        insertBST(Root->right,pBaru);
    }
    else{
        cout<<"Sudah ada"<<endl;
    }
}
void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<" ";
        preOrder(Root->left);
        preOrder(Root->right);
    }
}
void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info <<" ";
        inOrder(Root->right);
    }
}
void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<" ";
    }
}

int main(){
    Tree Root;
    pointer p;
	int pilihan;
	Root=NULL;
	while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Input Data"<<endl;
        cout<<"2. Pre Order"<<endl;
        cout<<"3. In Order"<<endl;
        cout<<"4. Post Order"<<endl;
		cout<<"5. Exit"<<endl;
        cout << "Masukkan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
			int data;
			cout<<"Masukkan jumlah data : ";cin>>data;
            for (int i=0;i<data;i++){
				createSimpul(p);
				insertBST(Root,p);
			}
			break;
        case 2:
            preOrder(Root);
			break;
        case 3:
            inOrder(Root);
			break;
        case 4:
			postOrder(Root);
		case 5:
			return 0;
            break;
        }
        system("pause");
    }
}
