#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string>
#include "listChild.h"
#include "listParent.h"
using namespace std;
///*SINGLE LINKED LIST
#define Nil NULL
#define toParent(p) (p)->toParent
#define toChild(p) (p)->toChild
#define first(L) ((L).first)
#define next(p) (p)->next
#define infoParent(p) (p)->infoParent
#define infoChild(p) (p)->infoChild

typedef int infotype;
typedef struct elmListRelasi *addressRelasi;
typedef struct elmListParent *addressParent;
typedef struct elmListChild *addressChild;
struct elmListRelasi {
    addressParent toParent;
    addressChild toChild;
    addressRelasi next;
};
struct listRelasi {
    addressRelasi first;
};

void createListRelasi(listRelasi &L);
addressRelasi alokasiRelasi(addressParent q, addressChild r);
void dealokasiRelasi(addressRelasi &p);
bool isEmpty(listRelasi L);
void insertRelasi(listRelasi &L, addressRelasi p);
void deleteRelasi(listRelasi &L, addressRelasi &p);
addressRelasi findElmRelasiParent(listRelasi L, addressParent P);
addressRelasi findElmRelasiChild(listRelasi L, addressChild P);
addressRelasi findElmRelasi(listRelasi L, string judulBuku, string NIM);
void printInfoRelasi(listRelasi &L);
void bukuFavorit(listRelasi &L);
#endif // LISTRELASI_H_INCLUDED
