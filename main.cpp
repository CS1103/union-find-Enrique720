#include <iostream>
#include <map>
#include <cassert>
#include <vector>
using namespace std;
struct node{
    int indice;
    int root;
public:
    node(int indice):indice{indice}, root{indice}{
    }
};
class Union_find {
    vector <node*> nodos;
public:
    Union_find(vector<node*> a): nodos{a}{};
    int find(node* a){
        return a->root;
    }
    void Union(node* a, node* b){
        for( int i = 0 ; i <nodos.size(); i++){
            if(nodos[i]->root == a->root){
                nodos[i]->root = b->root;
            }
        }
        a->root = b->root;
    };
};
int main() {
    vector <node*> vector1;
    auto a = new node(1);
    auto b = new node(2);
    auto c = new node(3);
    auto d = new node(4);
    vector1.push_back(a); vector1.push_back(b); vector1.push_back(c); vector1.push_back(d);
    Union_find uf(vector1);
    //primero el indice y el root deben ser el mismo
    assert(uf.find(a) == 1);
    //luego se une el nodo indice 1 con el nodo indice 2;
    uf.Union(a,b);
    //el root del nodo de indice 1 ahora debe ser 2
    assert(uf.find(a) == 2 );
    //se une el nodo 2 con el 3 por lo que el nodo 1 tambien tiene que tener como root el 3
    uf.Union(b,c);
    //el root del nodo de indice 1 ahora es 3
    assert(uf.find(a)==3);

}
