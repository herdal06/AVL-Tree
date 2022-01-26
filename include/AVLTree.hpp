#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "Node.hpp"
class AVLTree {
private:
    Node* root; // agaca eklenecek ilk dugum. kok dugum
    Node* AraVeEkle(Node*, const Kisi&);
	Node* SolCocukIleDegistir(Node*); // Sağa dönüş
	Node* SagCocukIleDegistir(Node*); // Sola dönüş
	void SeviyeyiYazdir(Node*, int ) const;
	int Yukseklik(Node*) const;
	int maxDerinlik(Node*);  
	void agaciBosalt(Node*);
public:
    AVLTree();
	void Ekle(const Kisi&);
	void Levelorder() const;
	int Yukseklik() const;
	~AVLTree();
};
#endif