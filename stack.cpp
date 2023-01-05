#include "stack.h"
#include "queue.h"

StackBus penambahan_bus(int IDBus, string namaBus, string asal, string tujuan){
    StackBus bus;

    bus.IDBus = IDBus;
    bus.namaBus = namaBus;
    bus.tujuan = tujuan;
    bus.asal = asal;
    bus.top = -1;

    return bus;
}
void tampilkan_semua_penumpang(StackBus bus){
    cout<<"======================================="<<endl;
    cout<<"Nama Bus: "<<bus.namaBus<<endl;
    cout<<"Asal: "<<bus.asal<<endl;
    cout<<"Tujuan: "<<bus.tujuan<<endl;
    cout<<"======================================="<<endl;
    if(bus.top == -1){
        cout<<"Penumpang Kosong"<<endl;
        cout<<"======================================="<<endl;
    }else{
        cout<<"Data Penumpang Bus"<<endl;
        cout<<"======================================="<<endl;
        for(int a = 0; a <= bus.top; a++){
            addressQ penumpang = bus.penumpang[a];
            cout<<"Nomor kursi: "<<a + 1<<endl;
            cout<<"Nama: "<<info(penumpang).namaPenumpang<<endl;
            cout<<"Tujuan: "<<info(penumpang).tujuan<<endl;
            cout<<"======================================="<<endl;
        }
    }
}
void push(StackBus &bus, addressQ A){
    if(A != NULL){
        if(!isFull(bus)){
            bus.top++;
            bus.penumpang[bus.top] = A;
        }else{
            cout<<"Bus sudah penuh"<<endl;
        }
    }else{
        cout<<"Data Penumpang tidak ada"<<endl;
    }
}
int pencarian_penumpang(StackBus bus, string namaPenumpang){
    if(bus.top != -1){
        int kursiKe = 0;

        while(kursiKe <= bus.top){
            addressQ A = bus.penumpang[kursiKe];
            if(namaPenumpang == info(A).namaPenumpang){
                return kursiKe + 1;
            }
            kursiKe++;
        }
    }
    return 0;
}
bool isFull(StackBus bus){
    return bus.top == MAXKursi;
}
