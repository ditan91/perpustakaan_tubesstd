#include "listRelasi.h"
#include <iostream>
using namespace std;


void createListRelasi(listRelasi &L) {
    first(L) = NULL;
}
addressRelasi alokasiRelasi(addressParent q, addressChild r) {
    addressRelasi p = new elmListRelasi;
    toParent(p) = q;
    toChild(p) = r;
    next(p) = NULL;
    return p;
}
void dealokasiRelasi(addressRelasi &p) {
    delete p;
}
bool isEmpty(listRelasi L) {
    return (first(L) == NULL);
}
void insertRelasi(listRelasi &L, addressRelasi p) {
    if (first(L) == NULL){
        first(L) = p;
    } else {
        next(p) = first(L);
        first(L) = p;
    }
}
void deleteRelasi(listRelasi &L, addressRelasi &p) {
    if (p == first(L)) {
        first(L) = next(p);
    } else {
        addressRelasi q = first(L);
        while (next(q) != p) {
            q = next(q);
        }
        next(q) = next(p);
    }
    next(p) = NULL;
}
addressRelasi findElmRelasiParent(listRelasi L, addressParent P){
    addressRelasi Q = first(L);
    while (Q != NULL && toParent(Q) != P){
        Q = next(Q);
    }
    return Q;
}
addressRelasi findElmRelasiChild(listRelasi L, addressChild P){
    addressRelasi Q = first(L);
    while (Q != NULL && toChild(Q) != P){
        Q = next(Q);
    }
    return Q;
}
addressRelasi findElmRelasi(listRelasi L, string judulBuku, string NIM){
    addressRelasi P = first(L);
    while (P != NULL && infoChild(toChild(P)).NIM != NIM && infoParent(toParent(P)).judulBuku != judulBuku){
        P = next(P);
    }
    return P;
}
void printInfoRelasi(listRelasi &L){
    addressRelasi P;
    if (first(L) == NULL){
        cout<<"Belum ada data peminjaman"<<endl;
    } else {
        P = first(L);
        while (P != NULL){
            cout<<"NIM: "<<infoChild(toChild(P)).NIM<<endl;
            cout<<"Jurusan: "<<infoChild(toChild(P)).jurusan<<endl;
            cout<<"Nama Peminjam: "<<infoChild(toChild(P)).nama<<endl;
            cout<<"Urutan Peminjam: "<<infoChild(toChild(P)).urutanPeminjam<<endl;
            cout<<"Judul buku: "<<infoParent(toParent(P)).judulBuku<<endl;
            cout<<"Nomor buku: "<<infoParent(toParent(P)).nomorBuku<<endl;
            cout<<endl;
            P = next(P);
        }
    }
}
void bukuFavorit(listRelasi &L){
    int i,counter,min,max = 0;
    int jumlah = 1;
    addressRelasi R = first(L);
    while (next(R) != NULL){
        jumlah = jumlah + 1;
        R = next(R);
    }
    cout<<"Jumlah buku yang dipinjam: "<<jumlah<<endl;
    cout<<endl;
    addressRelasi Q;
    addressRelasi P = first(L);
    while (P != NULL){
       Q = first(L);
       counter = 0;
       while (Q != NULL) {
            if (infoParent(toParent(Q)).judulBuku == infoParent(toParent(P)).judulBuku && infoParent(toParent(Q)).nomorBuku == infoParent(toParent(P)).nomorBuku){
                counter = counter + 1;
            }
            Q = next(Q);
       }
       min = counter;
       if (counter >= max){
            max = counter;
       }
       for (i = 1; i < jumlah; i++){
            if (counter >= max){
                max = counter;
            }
            if (counter < min){
                min = counter;
            }
       }
       if (counter == max){
            cout<<"Buku Favorit: "<<infoParent(toParent(P)).judulBuku<<endl;
       }else if (counter == min){
            cout<<"Buku Non Favorit: "<<infoParent(toParent(P)).judulBuku<<endl;
       }
       P = next(P);
    }
}

