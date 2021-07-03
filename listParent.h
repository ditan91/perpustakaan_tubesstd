#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
///*DOUBLE LINKED LIST (berisi data buku)
#define Nil NULL
#define first(L) ((L).first)
#define last(L) ((L).last)
#define next(p) (p)->next
#define infoParent(p) (p)->infoParent
#define prev(p) (p)->prev
#define jumlahPinjam(p) (p)->jumlahPinjam

typedef int infotype;
typedef struct elmListParent *addressParent;
struct infotypeParent {
    string judulBuku;
    int nomorBuku;
    int tahunTerbit;
};
struct elmListParent {
    infotypeParent infoParent;
    addressParent next;
    addressParent prev;
    int jumlahPinjam;
};
struct listParent {
    addressParent first;
    addressParent last;
};

void createListParent(listParent &L);
addressParent alokasiParent(string judulBuku, int nomorBuku, int tahunTerbit);
void dealokasiParent(addressParent &p);
bool isEmpty(listParent L);
addressParent findElmParent(listParent L, string judulBuku, int nomorBuku);
void printInfo(listParent &L);
void insertParent(listParent &L, addressParent p);
void deleteParent(listParent &L, string judulBuku, int nomorBuku);
void totalBuku(listParent &L, string judulBuku, int nomorBuku);


#endif // LISTPARENT_H_INCLUDED
