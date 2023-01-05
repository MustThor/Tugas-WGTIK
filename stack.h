#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "queue.h"

const int MAXKursi = 30;

typedef int address;

struct StackBus{
    int IDBus;
    string namaBus;
    addressQ penumpang[MAXKursi];
    string asal;
    string tujuan;
    address top;
};

StackBus penambahan_bus(int IDBus, string namaBus, string asal, string tujuan);
void tampilkan_semua_penumpang(StackBus bus);
void push(StackBus &bus, addressQ A);
void pop(StackBus &bus, addressQ &A);
int pencarian_penumpang(StackBus bus, string namaPenumpang);
bool isFull(StackBus bus);
#endif // STACK_H_INCLUDED
