#include "Kisi.hpp"
#include "AVLTree.hpp"
#include<iostream>
#include <fstream> // dosya okumak icin
#include <sstream> // stringstream'i kullanmak icin
#include <string> // string metodlarini kullanmak icin
using namespace std;

int main() {
    AVLTree* tree = new  AVLTree();
    ifstream personFile; // okunacak dosya
    personFile.open("doc/Kisiler.txt"); // dosyayi actim. dosyanin yolunu verdim.
    if(!personFile) { // dosya acilirken hatayla karsilasildi demektir.
        cout<<"Dosya acilamadi..."<<endl; return 0;
    }
    Kisi kisi; // kisi nesnesi
    string line; // dosyadaki her bir satiri temsil eden degisken
    string tempString; // kopyalama islemini yapmak icin kullandigim gecici degisken
    // dosyadaki isim, yas ve boyu ,kisi constructor'ina parametre olarak vermek icin tanimlanmis olan degiskenler. 
    string name;
    int age;
    int height;
    while(getline(personFile, line)) { // getline metodu -> dosyayi satir satir okumak icin
        stringstream ss(line);
        getline(ss,name,'#'); // dosyada '#' karakterine kadar olan kismi name degiskenine aldim
        getline(ss,tempString,'#'); // isimden sonraki # karakterine kadar olanki kismi tuttum. gecici degiskene atadim.
        age = stoi(tempString); // gecici degiskenin tuttugu veriyi age degiskenime atadim. stoi fonksiyonu sayesinde karakterleri integer'a cevirdim
        getline(ss,tempString); // geriye kalan kisim boy.
        height = stoi(tempString); // boyu integer'a cevirdim
        kisi = Kisi(name,age,height); // yukarida aldigim isim, yas ve boyu kisi nesnesine parametre olarak verdim. 
        tree->Ekle(kisi);   // kisi nesnesini agaca verdim. agaca kisi eklenmis oldu. satir bittiginde getline metodu ile satir bittiginde alt satira gecilecek ve dosyadaki elemanlar tek tek kisi olarak agaca eklenmis olacak.
    } 
    cout<<"Level Order : "<<endl;
    personFile.close();  // dosyayi kapattim.
    tree->Levelorder();
    delete tree;

    return 0;
}