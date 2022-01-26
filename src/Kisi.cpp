#include "Kisi.hpp"
// varsayilan kurucu
Kisi::Kisi() {      }
Kisi::Kisi(string name,int age,int height) : name(name), age(age), height(height) {     } // parametreli kurucu
// kapsulleme
string Kisi::getName() const {
    return name;
} 
int Kisi::getAge() const {
    return age;
}
int Kisi::getHeight() const {
    return height;
}