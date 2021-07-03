#include "listParent.h"
#include <iostream>
using namespace std;


void createListParent(listParent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressParent alokasiParent(string judulBuku, int nomorBuku, int tahunTerbit) {
    addressParent p = new elmListParent;
    infoParent(p).judulBuku = judulBuku;
    infoParent(p).nomorBuku = nomorBuku;
    infoParent(p).tahunTerbit = tahunTerbit;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void dealokasiParent(addressParent &p) {
    delete p;
}
bool isEmpty(listParent L) {
    if (first(L) == NULL && last(L) == NULL){
        return true;
    } else {
        return false;
    }

}
addressParent findElmParent(listParent L, string judulBuku, int nomorBuku) {
    addressParent p = first(L);
    if (!(isEmpty(L))) {
        while (p != NULL && infoParent(p).judulBuku != judulBuku && infoParent(p).nomorBuku != nomorBuku) {
            p = next(p);
        }
        return p;
    }
    return NULL;
}

void printInfo(listParent &L) {
    addressParent p;
    if (isEmpty(L)) {
        cout << "Tidak ada buku dalam daftar" <<endl;
    } else {
        p = first(L);
        do {
            cout <<infoParent(p).judulBuku<<" - ";
            cout <<infoParent(p).nomorBuku<<" - ";
            cout <<infoParent(p).tahunTerbit;
            cout<<endl;
            p = next(p);
        } while (p != NULL);
    }
}
void insertParent(listParent &L, addressParent p) {
    if (isEmpty(L)) {
        first(L) = p;
        last(L) = p;
    } else {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}
void deleteParent(listParent &L, string judulBuku, int nomorBuku) {

    addressParent q = findElmParent(L, judulBuku, nomorBuku);
    if (isEmpty(L) == false && q != NULL) {
        if (q == first(L) && q == last(L)) {
            last(L) = NULL;
            first(L) = NULL;
            next(q) = NULL;
            prev(q) = NULL;
        } else if (q == first(L)) {
            first(L) = next(q);
            next(q) = NULL;
        } else if (q == last(L)) {
            last(L) = prev(q);
            prev(q) = NULL;
            next(last(L)) = NULL;
        } else {
            next(prev(q)) = next(q);
            prev(next(q)) = prev(q);
        }
        dealokasiParent(q);
    }
}
void totalBuku(listParent &L, string judulBuku, int nomorBuku){
    int counter = 0;
    addressParent P = first(L);
    addressParent P1 = findElmParent(L, judulBuku, nomorBuku);
    if (P1 == NULL){
        cout<<endl;
        cout<<"Sorry!! data not found"<<endl;
    } else {
        while (P != NULL){
            if (infoParent(P).judulBuku == infoParent(P1).judulBuku && infoParent(P).nomorBuku == infoParent(P1).nomorBuku){
                counter = counter + 1;
            }
            P = next(P);
        }
        cout<<"Total buku "<<infoParent(P1).judulBuku<<": "<<counter<<endl;
    }

}
