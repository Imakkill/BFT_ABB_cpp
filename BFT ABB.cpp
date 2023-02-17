#include<queue>
#include<iostream>   

class ArvoreB {
protected:
    struct no {
            no *esquerda;  
            no *direita; 
            int v;   

            no() {}
            no( 
               int v,
               no *l = nullptr,
               no *r = nullptr)
             : esquerda(l), direita(r), v(v) {}
    };

    no* raiz_;      
    size_t numElementos_;    

public:
    ArvoreB(): raiz_(nullptr), numElementos_(0) {}

    void inserir(int v) {
        no *novoNo = new no(v);
            no *pai = nullptr;

        if(!raiz_) {
            raiz_ = novoNo;
            ++numElementos_;
            return;
        }
        no* actual = raiz_;

        while(actual) {
            pai = actual;
            actual = novoNo->v > actual->v ? actual->direita : actual->esquerda;
        }

        if(novoNo->v < pai->v) {
            pai->esquerda = novoNo;
        }
        else {
            pai->direita = novoNo;
        }
        ++numElementos_;
    }

    void inserir(std::vector<int> v) {
        for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
            inserir(*it); 
        }
    }

    void buscaLargura() {      
        std::queue<no*> q;
        q.push(raiz_);  

        while (q.size() > 0)
        {
            no* n = q.front();
            q.pop();
            std::cout << n->v << " ";

            if (n->esquerda !=nullptr) {
                    q.push(n->esquerda);
            }
            if (n->direita !=nullptr) {
                q.push(n->direita);
            }
        }

        std::cout << std::endl;
    }   

    void mostraArvore() {
        std::queue<no*> nivelActual, nivelSeguinte;
        nivelActual.push(raiz_);
        while(!nivelActual.empty()) {
            no* noActual = nivelActual.front();
            nivelActual.pop();

            if(noActual) {
                std::cout << noActual->v << " ";
                nivelSeguinte.push(noActual->esquerda);
                nivelSeguinte.push(noActual->direita);
            }
            if(nivelActual.empty()) {
                std::cout << std::endl;
                swap(nivelActual, nivelSeguinte);
            }
        }
    }

};

int main(int argc, char *argv[]) {
    std::vector<int> v = {15, 6, 3, 7, 2, 5, 8, 1, 4, 20, 22, 25, 23};
    BTree t;
    t.inserir(v);

    //t.inserir(15);
    //t.inserir(6);
    //t.inserir(3);
    //t.inserir(7);
    //t.inserir(2);
    //t.inserir(5);
    //t.inserir(8);
    //t.inserir(1);
    //t.inserir(4);
    //t.inserir(20);
    //t.inserir(22);
    //t.inserir(25);
    //t.inserir(23);

    t.buscaLargura();

    t.mostraArvore();
    return 0;
}