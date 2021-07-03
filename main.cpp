#include <iostream>

using namespace std;
#include "listParent.h"
#include "listChild.h"
#include "listRelasi.h"

int main()
{

    listParent LP;
    listChild LC;
    listRelasi LR;
    addressChild C;
    addressParent P;
    addressRelasi R;

    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    int pilih;
    cout<<"KELOMPOK 8"<<endl;
    cout<<"Dita Noviyanti - 1301194125"<<endl;
    cout<<"Nadia Ariana - 1301190208"<<endl;
    do
    {
        cout<<endl;
        cout<<endl;
        cout<<"=============================Telkom University Library==================================="<<endl;
        cout<<"Selamat datang di Perpustakaan Telkom University"<<endl;
        cout<<"Membaca adalah jendela dunia"<<endl;
        cout<<"Silahkan pilih menu"<<endl;
        cout<<"=============Menu=============="<<endl;
        cout<<"1. Tambah Buku"<<endl;
        cout<<"2. Masukan Data Peminjam"<<endl;
        cout<<"3. Tampilkan List Buku"<<endl;
        cout<<"4. Tampilkan List Peminjam"<<endl;
        cout<<"5. Total Buku"<<endl;
        cout<<"6. Hapus Data Buku"<<endl;
        cout<<"7. Hapus Data Peminjam"<<endl;
        cout<<"8. Peminjaman"<<endl;
        cout<<"9. Pengembalian"<<endl;
        cout<<"10. Data Buku dan Peminjam"<<endl;
        cout<<"11. Buku favorit dan Non Favorit"<<endl;
        cout<<"Pilih menu : "<<endl;
        cin>>pilih;
        switch(pilih)
        {
        case 1:
            {
                int tahunTerbit, nomorBuku;
                string judulBuku, yesNo;
                bool done = false;
                while (done == false){
                    cout<<"Ingin menambahkan koleksi buku?(Yes/No)"<<endl;
                    cin>>yesNo;
                    if (yesNo == "Yes" || yesNo == "yes"){
                        cout<<"=====================Silahkan masukan data================ "<<endl;
                        cout<<"Judul buku: ";
                        cin>>judulBuku;
                        cout<<"Nomor buku: ";
                        cin>>nomorBuku;
                        cout<<"Tahun terbit: ";
                        cin>>tahunTerbit;
                        addressParent P = alokasiParent(judulBuku, nomorBuku, tahunTerbit);
                        insertParent(LP, P);
                    }
                    if (yesNo == "no" || yesNo == "No"){
                        cout<<"Terimakasih"<<endl;
                        done = true;
                    }
                }
                break;
            }
        case 2:
            {
                int urutanPeminjaman, counter;
                string nama, jurusan, NIM, yesNo;
                bool done = false;
                counter = 0;
                while (done == false){
                    cout<<"Ingin menambahkan data Mahasiswa?(Yes/No)"<<endl;
                    cin>>yesNo;
                    if (yesNo == "Yes" || yesNo == "yes"){
                        cout<<"====================Silahkan masukan data================ "<<endl;
                        cout<<"Nama: ";
                        cin>>nama;
                        cout<<"NIM: ";
                        cin>>NIM;
                        cout<<"Jurusan: ";
                        cin>>jurusan;
                        counter = counter + 1;
                        cout<<"Urutan Peminjam: "<<counter<<endl;
                        addressChild P = createElmChild(nama, NIM, jurusan, urutanPeminjaman);
                        insertFirstChild(LC, P);
                    }
                    if (yesNo == "no" || yesNo == "No"){
                        cout<<"Terimakasih"<<endl;
                        done = true;
                    }
                }
                break;
            }
        case 3 :
            {
                printInfo(LP);
                break;
            }
        case 4 :
            {
                printInfoChild(LC);
                break;
            }
        case 5 :
            {
                string judulBuku;
                int nomorBuku;
                cout<<"====================Chek persediaan buku==================="<<endl;
                cout<<"Judul buku yang dicari?"<<endl;
                cin>>judulBuku;
                cout<<"Nomor buku: "<<endl;
                cin>>nomorBuku;
                totalBuku(LP, judulBuku, nomorBuku);
                break;
            }
        case 6 :
            {
                int nomorBuku;
                string judulBuku;
                cout<<"Masukan data buku yang ingin dihapus: "<<endl;
                cout<<"Judul buku: ";
                cin>>judulBuku;
                cout<<"Nomor buku: ";
                cin>>nomorBuku;
                addressParent P = findElmParent(LP, judulBuku, nomorBuku);
                addressRelasi Q = findElmRelasiParent(LR, P);
                if (Q != NULL){
                    cout<<"Masih ada buku yang belum kembali"<<endl;
                } else {
                    deleteParent(LP, judulBuku, nomorBuku);
                }
                break;
            }
        case 7 :
            {
                string NIM;
                cout<<"Masukan data peminjam yang ingin dihapus: "<<endl;
                cout<<"NIM: ";
                cin>>NIM;
                addressChild P = findElmChild(LC, NIM);
                addressRelasi Q = findElmRelasiChild(LR, P);
                if (Q != NULL){
                    cout<<"Masih ada buku yang belum kembali"<<endl;
                } else {
                    deleteChild(LC, NIM);
                }
                break;
            }
        case 8 : //PEMINJAMAN MAX 5 BUKU
            {
                string NIM, judulBuku;
                char yesNo;
                int nomorBuku;
                int counter = 0;
                bool done = false;
                while (done == false && counter < 5){
                    cout<<"Apakah anda ingin meminjam buku?(Y/N)"<<endl;
                    cin>>yesNo;
                    if (yesNo == 'Y' || yesNo == 'y'){
                        cout<<"Masukan NIM: ";
                        cin>>NIM;
                        cout<<"Masukan judul buku: ";
                        cin>>judulBuku;
                        cout<<"Masukan nomor buku: ";
                        cin>>nomorBuku;
                        addressChild R = findElmChild(LC, NIM);
                        addressParent B = findElmParent(LP, judulBuku, nomorBuku);
                        while (R == NULL || B == NULL){
                            if (R == NULL){
                                cout<<"data not found"<<endl;
                                cout<<"Masukan NIM: ";
                                cin>>NIM;
                                R = findElmChild(LC, NIM);
                            } else if (B == NULL ){
                                cout<<"data not found"<<endl;
                                cout<<"Masukan judul buku: ";
                                cin>>judulBuku;
                                cout<<"Masukan nomor buku: ";
                                cin>>nomorBuku;
                                B = findElmParent(LP, judulBuku, nomorBuku);
                            }
                        }
                        addressRelasi P;
                        P = alokasiRelasi(B, R);
                        insertRelasi(LR, P);
                        counter = counter + 1;
                        cout<<"Selamat anda berhasil meminjam buku"<<endl;
                        if (counter == 5){
                            cout<<"Maaf peminjaman buku maksimal hanya lima. Terimakasih"<<endl;
                        }
                    } else if (yesNo == 'N' || yesNo == 'n'){
                        done = true;
                    }
                }
                break;
            }
        case 9 :
            {
               string NIM, judulBuku;
               char yesNo;
               bool done = false;
               while (done == false){
                    cout<<"Apakah anda ingin mengembalikan buku?(Y/N)"<<endl;
                    cin>>yesNo;
                    if (yesNo == 'Y' || yesNo == 'y'){
                        cout<<"Masukan NIM: ";
                        cin>>NIM;
                        cout<<"Masukan judul buku: ";
                        cin>>judulBuku;
                        addressRelasi R = findElmRelasi(LR, judulBuku, NIM);
                        while (R == NULL){
                            cout<<"Data not found"<<endl;
                            cout<<"Masukan NIM: ";
                            cin>>NIM;
                            cout<<"Masukan judul buku: ";
                            cin>>judulBuku;
                            R = findElmRelasi(LR, judulBuku, NIM);
                        }
                        deleteRelasi(LR, R);
                        cout<<"Pengembalian buku berhasil. Terimakasih"<<endl;
                    } else if (yesNo == 'N'|| yesNo == 'n'){
                        done = true;
                    }
               }
               break;
            }
        case 10 :
            {
                printInfoRelasi(LR);
                break;
            }
        case 11 :
            {
                bukuFavorit(LR);
                break;
            }
        }
    }
    while(pilih != 0);

        return 0;
}

