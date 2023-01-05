#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

#define head(Q) ((Q).head)
#define tail(Q) ((Q).tail)
#define info(Q) (Q)->info
#define next(Q) (Q)->next
#define nil NULL

struct antrianPenumpang{
    int IDPenumpang;
    string namaPenumpang;
    string asal;
    string tujuan;
    int harga;
};

typedef antrianPenumpang infotype;
typedef struct elementQueue *addressQ;

struct elementQueue{
    infotype info;
    addressQ next;
};

struct Queue{
    addressQ head, tail;
};

int menu();
antrianPenumpang buat_data_penumpang(int IDPenumpang, string namaPenumpang, string asal, string tujuan, int harga);
void createQueue(Queue &Q);
addressQ create_address(antrianPenumpang info);
void enqueue(Queue &Q, addressQ A);
void dequeue(Queue &Q, addressQ &A);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void tampilkan_antrian(Queue Q);
int hitung_banyak_antrian(Queue Q);
void tampilkan_antrian_terakhir(Queue Q);


#endif // QUEUE_H_INCLUDED
