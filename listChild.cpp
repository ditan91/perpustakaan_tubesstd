#include <iostream>
#include "listChild.h"
using namespace std;
void createListChild(listChild &L){
    first(L) = NULL;
    last(L) = NULL;
}
addressChild createElmChild(string nama, string NIM, string jurusan, int urutanPeminjam){
    addressChild P = new elmListChild;
    infoChild(P).nama = nama;
    infoChild(P).NIM = NIM;
    infoChild(P).urutanPeminjam = urutanPeminjam;
    infoChild(P).jurusan = jurusan;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertFirstChild(listChild &L, addressChild P){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
        next(first(L)) = P;
        prev(first(L)) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
    prev(first(L)) = last(L);
    next(last(L)) = first(L);
}
void insertLastChild(listChild &L, addressChild P){
    if (last(L) == NULL && first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
    prev(first(L)) = last(L);
    next(last(L)) = first(L);
}
void insertAfterChild(listChild &L, addressChild Prec, addressChild P){
    if (Prec == NULL){
        cout<<"data not found";
    } else if (Prec == last(L) && Prec == first(L)){
        insertLastChild(L,P);
    } else {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}
void insertSortChild(listChild&L, addressChild P){
    if (first(L) == NULL || infoChild(P).urutanPeminjam >= infoChild(first(L)).urutanPeminjam){
        insertFirstChild(L,P);
    } else if (infoChild(P).urutanPeminjam <= infoChild(last(L)).urutanPeminjam ){
        insertLastChild(L,P);
    } else {
        addressChild Q = first(L);
        while (infoChild(Q).urutanPeminjam > infoChild(P).urutanPeminjam){
            Q = next(Q);
        }
        insertAfterChild(L, Q, P);
    }
}
void deleteFirstChild(listChild &L, addressChild &P){
    P = first(L);
    if(first(L) == NULL){
        cout<<"List is empty"<<endl;
    }else if (next(P)==first(L)){
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }else{
        first(L)=next(P);
        next(prev(P))=first(L);
        prev(first(L))=prev(P);
        next(P)=NULL;
        prev(P)=NULL;
    }

}
void deleteLastChild(listChild &L, addressChild &P){
    P = last(L);
    next(prev(P)) = first(L);
    prev(first(L)) = first(L);
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteAfterChild(listChild &L, addressChild Prec, addressChild &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteChild(listChild &L, string NIM){
    addressChild P = findElmChild(L, NIM);
    if (first(L) == NULL){
        cout<<"data not found";
    } else if (P == last(L)){
        deleteLastChild(L, P);
    } else if (P == first(L)){
        deleteFirstChild(L, P);
    } else {
        deleteAfterChild(L, prev(P), P);
    }
}
void printInfoChild(listChild L){
    addressChild P = first(L);
    do{
        cout<<"Nama Peminjam: "<<infoChild(P).nama<<endl;
        cout<<"NIM : "<<infoChild(P).NIM<<endl;
        cout<<"Jurusan : "<<infoChild(P).jurusan<<endl;
        cout<<"Urutan Peminjam: "<<infoChild(P).urutanPeminjam<<endl;
        cout<<endl;
        P = next(P);
    }while(P != first(L));
    cout<<endl;
}
addressChild findElmChild(listChild &L, string NIM){
    addressChild P = first(L);
    if(P != NULL){
        do{
            if (infoChild(P).NIM == NIM){
                return P;
            }
            P = next(P);
        }while (P != first(L));
        return NULL;
    } else {
        return NULL;
    }
}
