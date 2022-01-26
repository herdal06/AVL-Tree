#ifndef Node_HPP
#define Node_HPP
#include <iostream>
#include "Kisi.hpp"
#include "Stack.hpp"
using namespace std;
class Node {
public:
    Kisi kisi;
    Node* left;
    Node* right;
    int height; // dugumun yuksekligini tutacak
    Stack stack_height;
    Stack stack_depth;
    Node(); // varsayilan kurucu
    Node(Kisi, Node*, Node*);
    Node(Kisi);
};
#endif