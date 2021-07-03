#ifndef LISTCHILD_H_INCLUDED
#define LISTCHILD_H_INCLUDED
#include <iostream>
using namespace std;
///*CIRCULAR DOUBLE LINKED LIST (berisi data mahasiswa)
#define Nil NULL
#define first(L) ((L).first)
#define last(L) ((L).last)
#define next(p) (p)->next
#define infoChild(p) (p)->infoChild
#define prev(p) (p)->prev
#define peminjam(p) (p)->peminjam

typedef int infotype;

struct infotypeChild {
    string NIM;
    string jurusan;
    string nama;
    int urutanPeminjam;
};
typedef struct elmListChild *addressChild;
struct elmListChild {
    infotypeChild infoChild;
    addressChild next;
    addressChild prev;
};
struct listChild {
    addressChild first;
    addressChild last;
};

void createListChild(listChild &L);
addressChild createElmChild(string nama, string NIM, string jurusan, int urutanPeminjam);
void insertFirstChild(listChild &L, addressChild P);
void insertLastChild(listChild &L, addressChild P);
void insertAfterChild(listChild &L, addressChild Prec, addressChild P);
void insertSortChild(listChild&L, addressChild P);
void deleteFirstChild(listChild &L, addressChild &P);
void deleteLastChild(listChild &L, addressChild &P);
void deleteAfterChild(listChild &L, addressChild Prec, addressChild &P);
void deleteChild(listChild &L, string NIM);
void printInfoChild(listChild L);
addressChild findElmChild(listChild &L, string NIM);




#endif // LISTCHILD_H_INCLUDED
