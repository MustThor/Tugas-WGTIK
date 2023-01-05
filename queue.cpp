#include "queue.h"

int menu(){
    int pilihMenu;

    cout<<"======================================="<<endl;
    cout<<"Tubes Ticketing Bus"<<endl;
    cout<<"======================================="<<endl;
    cout<<"1. Tampilkan semua antrian"<<endl;
    cout<<"2. Hitung banyak antrian"<<endl;
    cout<<"3. Tampilkan antrian terakhir"<<endl;
    cout<<"4. Pembelian tiket bus"<<endl;
    cout<<"5. Tampilkan semua penumpang"<<endl;
    cout<<"6. Pencarian penumpang"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"======================================="<<endl;
    cout<<"Pilih Menu: ";
    cin>>pilihMenu;

    return pilihMenu;
}
antrianPenumpang buat_data_penumpang(int IDPenumpang, string namaPenumpang, string asal, string tujuan, int harga){
    antrianPenumpang info;
    info.IDPenumpang = IDPenumpang;
    info.namaPenumpang = namaPenumpang;
    info.asal = asal;
    info.tujuan = tujuan;
    info.harga = harga;
    return info;
}
void createQueue(Queue &Q){
    head(Q) = nil;
    tail(Q) = nil;
}
addressQ create_address(antrianPenumpang info){
    addressQ A = new elementQueue;

    info(A) = info;
    next(A) = nil;

    return A;
}
void enqueue(Queue &Q, addressQ A){
    if(head(Q) == nil){
        head(Q) = A;
        tail(Q) = A;
    }else{
        next(tail(Q)) = A;
        tail(Q) = A;
    }
}
void dequeue(Queue &Q, addressQ &A){
    if(head(Q) != nil){
        A = head(Q);
        head(Q) = next(A);
        next(A) = nil;
    }else if(head(Q) == tail(Q)){
        A = head(Q);
        head(Q) = nil;
        tail(Q) = nil;
    }else{
        A = NULL;
    }
}
void tampilkan_antrian(Queue Q){
    addressQ A = head(Q);
    cout<<"======================================="<<endl;
    if(A != NULL){
        cout<<"Data Antrian"<<endl;
        cout<<"======================================="<<endl;
        while(A != NULL){
            cout<<"Nama: "<<info(A).namaPenumpang<<endl;
            cout<<"Asal: "<<info(A).asal<<endl;
            cout<<"Tujuan: "<<info(A).tujuan<<endl;
            cout<<"======================================="<<endl;
            A = next(A);
        }
    }else{
        cout<<"Data antrian kosong"<<endl;
        cout<<"======================================="<<endl;
    }
}
int hitung_banyak_antrian(Queue Q){
    addressQ A = head(Q);
    int banyak = 0;

    while(A != NULL){
        banyak++;
        A = next(A);
    }

    return banyak;
}
void tampilkan_antrian_terakhir(Queue Q){
    if(tail(Q) == nil){
        cout<<"Tidak ada antrian saat ini"<<endl;
    }else{
        cout<<"======================================="<<endl;
        cout<<"Data Antrian Terakhir"<<endl;
        cout<<"======================================="<<endl;
        cout<<"Nama: "<<info(tail(Q)).namaPenumpang<<endl;
        cout<<"Tujuan: "<<info(tail(Q)).tujuan<<endl;
        cout<<"======================================="<<endl;
    }
}
