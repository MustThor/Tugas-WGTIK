#include "queue.h"
#include "stack.h"

int main()
{
    int pilihMenu, banyakAntrian, kursiJakarta, kursiJogja;
    antrianPenumpang info;
    char pilihKembali;
    string namaPenumpang;
    StackBus busJakarta = penambahan_bus(1, "MekarJaya", "Bandung", "Jakarta");
    StackBus busJogja = penambahan_bus(2, "JayaRaya", "Bandung", "Jogja");
    Queue Q;
    addressQ A;

    createQueue(Q);

    info = buat_data_penumpang(1, "Fathin", "Bandung", "Jakarta", 50000);
    enqueue(Q, create_address(info));
    info = buat_data_penumpang(2, "Ilham", "Bandung", "Jogja", 199000);
    enqueue(Q, create_address(info));
    info = buat_data_penumpang(3, "Jarwo", "Bandung", "Jakarta", 50000);
    enqueue(Q, create_address(info));


    pilihMenu = menu();

    while(pilihMenu != 0){
        if(pilihMenu == 1){
            tampilkan_antrian(Q);
        }else if(pilihMenu == 2){
            banyakAntrian = hitung_banyak_antrian(Q);
            cout<<"Banyak Antrian saat ini: "<<banyakAntrian<<endl;
        }else if(pilihMenu == 3){
            tampilkan_antrian_terakhir(Q);
        }else if(pilihMenu == 4){
            dequeue(Q, A);
            if(A != NULL){
                if(info(A).tujuan == "Jakarta"){
                    push(busJakarta, A);
                    cout<<"Penumpang: "<<info(A).namaPenumpang;
                    cout<<" dengan tujuan: "<<info(A).tujuan<<endl;
                    cout<<"Berhasil terdaftar sebagai penumpang bus: "<<busJakarta.namaBus<<endl;
                }else if(info(A).tujuan == "Jogja"){
                    push(busJogja, A);
                    cout<<"Penumpang: "<<info(A).namaPenumpang;
                    cout<<" dengan tujuan: "<<info(A).tujuan<<endl;
                    cout<<"Berhasil terdaftar sebagai penumpang bus: "<<busJogja.namaBus<<endl;
                }else{
                    cout<<"Bus dengan tujuan ini tidak tersedia"<<endl;
                }
            }else{
                cout<<"Antrian kosong"<<endl;
            }
        }else if(pilihMenu == 5){
            tampilkan_semua_penumpang(busJakarta);
            tampilkan_semua_penumpang(busJogja);
        }else if(pilihMenu == 6){
            cout<<"Nama Penumpang: ";
            cin>>namaPenumpang;

            kursiJakarta = pencarian_penumpang(busJakarta, namaPenumpang);
            kursiJogja = pencarian_penumpang(busJogja, namaPenumpang);

            if(kursiJakarta != 0){
                cout<<"======================================="<<endl;
                cout<<"Penumpang ditemukan pada bus: "<<busJakarta.namaBus<<endl;
                cout<<"Dengan tujuan ke: "<<busJakarta.tujuan<<endl;
                cout<<"Penumpang berada di nomor kursi: "<<kursiJakarta<<endl;
                cout<<"======================================="<<endl;
            }else if(kursiJogja != 0){
                cout<<"======================================="<<endl;
                cout<<"Penumpang ditemukan pada bus: "<<busJogja.namaBus<<endl;
                cout<<"Dengan tujuan ke: "<<busJogja.tujuan<<endl;
                cout<<"Penumpang berada di nomor kursi: "<<kursiJogja<<endl;
                cout<<"======================================="<<endl;
            }else{
                cout<<"Penumpang tidak ditemukan"<<endl;
            }
        }

        cout<<"Kembali ke menu?(Y/N): ";
        cin>>pilihKembali;

        if(pilihKembali == 'n' || pilihKembali == 'N'){
            pilihMenu = 0;
        }else{
            pilihMenu = menu();
        }
    }
    return 0;
}
