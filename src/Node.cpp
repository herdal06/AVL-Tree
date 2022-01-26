#include "Node.hpp"
Node::Node() { // varsayilan kurucu metod
    this->left = NULL;
    this->right = NULL;
    height = 0;
}
// kisi nesnesi alan kurucu metodum
Node::Node(Kisi kisi) : kisi(kisi), left(NULL), right(NULL) { 
    height = 0; 
} 
Node::Node(Kisi kisi,Node* left, Node* right) : kisi(kisi), left(left), right(right) {  }

