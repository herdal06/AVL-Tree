#include "AVLTree.hpp"

Node* AVLTree::AraVeEkle(Node *alt_Node, const Kisi& kisi) {
    // alt_Node = z, alt_Node->left = y, yeni = x,w
    if (alt_Node == NULL) { // agacta hic dugum yoksa
        alt_Node = new Node(kisi); // dugum ekle.
    }
    else if (kisi.getHeight() < alt_Node->kisi.getHeight()) { // y, z'nin left çocuğu ise
        alt_Node->left = AraVeEkle(alt_Node->left, kisi); // 

        if (Yukseklik(alt_Node->left) - Yukseklik(alt_Node->right) == 2)
        {
            // left left Durumu
            if (kisi.getHeight() < alt_Node->left->kisi.getHeight()) // x, y'nin left çocuğu ise
                alt_Node = SolCocukIleDegistir(alt_Node); //sağa dönüş z
            else { // left Sağ Durumu														  
                alt_Node->left = SagCocukIleDegistir(alt_Node->left); // lefta dönüş y
                alt_Node = SolCocukIleDegistir(alt_Node); // sağa dönüş z
            }
        }
    }
    else if (kisi.getHeight() > alt_Node->kisi.getHeight()) {
        alt_Node->right = AraVeEkle(alt_Node->right, kisi);

        if (Yukseklik(alt_Node->right) - Yukseklik(alt_Node->left) == 2) {
            // Sağ Sağ Durumu
            if (kisi.getHeight() > alt_Node->right->kisi.getHeight())
                alt_Node = SagCocukIleDegistir(alt_Node);
            else { // Sağ left Durumu
                alt_Node->right = SolCocukIleDegistir(alt_Node->right);
                alt_Node = SagCocukIleDegistir(alt_Node);
            }
        }
    }
    else { // esit elemanin eklenmesi durumu
        alt_Node->left = AraVeEkle(alt_Node->left, kisi);
    
        if (Yukseklik(alt_Node->left) - Yukseklik(alt_Node->right) == 2) {
            // left left Durumu
            if (kisi.getHeight() == alt_Node->left->kisi.getHeight()) // x, y'nin left çocuğu ise
                alt_Node = SolCocukIleDegistir(alt_Node); //sağa dönüş z
            else { // left Sağ Durumu
                alt_Node->left = SagCocukIleDegistir(alt_Node->left); // lefta dönüş y
                alt_Node = SolCocukIleDegistir(alt_Node); // sağa dönüş z
            }
        }
    }
   
    // Yuksekligi guncelledim.
    alt_Node->height = Yukseklik(alt_Node);

    // yukseklik ve derinlikleri stack'lere push ediyorum
    alt_Node->stack_height.Push(Yukseklik(alt_Node));
    alt_Node->stack_depth.Push(maxDerinlik(alt_Node));

    return alt_Node;
}
Node* AVLTree::SolCocukIleDegistir(Node *alt_Node) { // Sağa dönüş
    //swap
    Node *tmp = alt_Node->left;
    alt_Node->left = tmp->right;
    tmp->right = alt_Node;

    // Yükseklikleri Güncelle
    alt_Node->height = Yukseklik(alt_Node);
    tmp->height = max(Yukseklik(tmp->left), alt_Node->height) + 1; // Bir düğümün yüksekliği en yüksek çocuğunun bir fazlasıdır

    return tmp;
}
Node* AVLTree::SagCocukIleDegistir(Node *alt_Node) {    // lefta dönüş 
    //swap
    Node *tmp = alt_Node->right;
    alt_Node->right = tmp->left;
    tmp->left = alt_Node;

    // Yukseklikleri Guncelle
    alt_Node->height = Yukseklik(alt_Node);
    tmp->height = max(Yukseklik(tmp->right), alt_Node->height) + 1;

    return tmp;
}
void AVLTree::SeviyeyiYazdir(Node *alt_Node, int seviye) const {
    if (alt_Node == NULL)
        return;
    if (seviye == 0) {
        // yazdirdigim yer.
        cout << alt_Node->kisi.getName() << " " << alt_Node->kisi.getAge() << " " << alt_Node->kisi.getHeight()<< " ";
        cout<<"Y("; alt_Node->stack_height.display(); cout<<"),";
        cout<<"D("; alt_Node->stack_depth.display(); cout<<") ";
    }
    else {
        SeviyeyiYazdir(alt_Node->left, seviye - 1);
        SeviyeyiYazdir(alt_Node->right, seviye - 1);
    }
}
int AVLTree::Yukseklik(Node *alt_Node) const {
    if (alt_Node == NULL)
        return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 datalmektedir.
    return 1 + max(Yukseklik(alt_Node->left), Yukseklik(alt_Node->right));
}
int AVLTree::maxDerinlik(Node* node) {  // derinligi bulur
    if (node == NULL)  // agacta eleman yok. derinlik 0
        return 0;  
    else{  
        /* her alt agacin derinligini hesapla */
        int lDepth = maxDerinlik(node->left);   // gidebildigin kadar sola git.
        int rDepth = maxDerinlik(node->right);  // gidebildigin kadar saga git.

        // hangisi daha buyukse onu kullan      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  
AVLTree::AVLTree() { // kurucu metod
    root = NULL;
}
int AVLTree::Yukseklik() const {
    return Yukseklik(root);
}
void AVLTree::Ekle(const Kisi& kisi) {
    root = AraVeEkle(root, kisi);
}

void AVLTree::Levelorder() const { // levelorder yazdirma metodu
    int h = Yukseklik();
    for (int level = 0; level <= h; level++)
        SeviyeyiYazdir(root, level);
}
void AVLTree::agaciBosalt(Node* node) { // agactaki tum dugumleri sildigim metod
    if(node == NULL) // eleman yok silinecek bir sey yok
        return;
    // rekursif
    agaciBosalt(node->left); // gidebildigin kadar sola  ve saga git tek tek sil.
    agaciBosalt(node->right);
    delete node;
}
AVLTree::~AVLTree() { // destructor metod. cop olusmamasi icin agaci bosalttim.
    agaciBosalt(root);
}