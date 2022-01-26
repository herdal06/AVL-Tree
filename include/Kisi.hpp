#ifndef KISI_HPP
#define KISI_HPP

#include <iostream>
using namespace std;

class Kisi {
private:
    // txt dosyasindaki isim, yas ve boy 
    string name;
    int age;
    int height;
public:
    Kisi(); // varsayılan kurucu
    Kisi(string,int,int);
    // encapsulation
    string getName() const;
    int getAge() const;
    int getHeight() const;
};
#endif