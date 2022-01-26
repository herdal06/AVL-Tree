#include "Stack.hpp"
bool Stack::IsFull() { // stack bos mu dolu mu kontrolu yapar
    return length == capacity;
}
void Stack::Reserve(int capacity) {
    int *tmp = new int[capacity];
    for (int j = 0; j < length; j++)
        tmp[j] = items[j];
    if (items != NULL)
        delete[] items;
    items = tmp;
    this->capacity = capacity;
}
Stack::Stack() { // yapici metod
    items = NULL;
    head = -1;
    length = 0;
    capacity = 0;
}
bool Stack::IsEmpty() const {
    return head == -1;
}
void Stack::Push(const int &obj) { // ekleme metodu
    if (IsFull()) // stack fullse
    {
        Reserve(max(1, 2 * capacity)); // kapasitesini arttir.
    }
    head++;
    items[head] = obj;
    length++;
}
void Stack::Pop() {
    if (IsEmpty())
        return;
    head--;
    length--;
}
const int& Stack::Top() const { // bastaki elemani doner
    if (IsEmpty())
        throw "Stack is empty!";
    return items[head];
}
void Stack::Clear() { // stack'i temizler
    head = -1;
    length = 0;
}
Stack::~Stack() { // destructor. cop olusmamasi icin elemanlar bellege iade ediliyor
    if (items != NULL)
        delete[] items;
    items = NULL;
}
void Stack::display() { // yazdirma metodu
    if(head>=0) {
        for(int i=head; i>=0; i--) {
            if(i == 0) cout<<items[i]; // son elemandan sonra virgul koymasini engellemek icin.
            else cout<<items[i]<<",";
        }
    } 
    else cout<<"Stack is empty";
}