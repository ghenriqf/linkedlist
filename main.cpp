#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

struct ListaInteiro {
    Node* head;
    int tamanho;

    ListaInteiro() {
        head = nullptr;
        tamanho = 0;
    }

    void inserirFinal(int valor, Node*& atual) {
        if (atual == nullptr) {
            atual = new Node(valor);
            tamanho++;
            return;
        }
        inserirFinal(valor, atual->next);
    }

    void inserirPosicao(int valor, int pos, Node*& atual) {
        if (pos < 0 || pos > tamanho) {
            cout << "Posicao invalida!\n";
            return;
        }
        if (pos == 0) {
            Node* novo = new Node(valor);
            novo->next = atual;
            atual = novo;
            tamanho++;
            return;
        }
        inserirPosicao(valor, pos - 1, atual->next);
    }

    void removerPosicao(int pos, Node*& atual) {
        if (pos < 0 || pos >= tamanho) {
            cout << "Posicao invalida!\n";
            return;
        }
        if (pos == 0) {
            Node* temp = atual;
            atual = atual->next;
            delete temp;
            tamanho--;
            return;
        }
        removerPosicao(pos - 1, atual->next);
    }

    void exibir(Node* atual) {
        if (atual == nullptr) return;
        cout << atual->data << " ";
        exibir(atual->next);
    }

    void exibirInverso(Node* atual) {
        if (atual == nullptr) return;
        exibirInverso(atual->next);
        cout << atual->data << " ";
    }

    void limpar(Node* atual) {
        if (atual == nullptr) return;
        limpar(atual->next);
        delete atual;
    }
};

int main() {
    ListaInteiro lista;

    cout << "inserindo no final:" << endl;
    lista.inserirFinal(8, lista.head);
    lista.inserirFinal(12, lista.head);
    lista.inserirFinal(90, lista.head);
    lista.exibir(lista.head);
    cout << endl;

    cout << "inserindo em posicao:" << endl;
    lista.inserirPosicao(2, 1, lista.head);
    lista.exibir(lista.head);
    cout << endl;

    cout << "removendo por posicao:" << endl;
    lista.removerPosicao(2, lista.head);
    lista.exibir(lista.head);
    cout << endl;

    cout << "exibindo lista inversa:" << endl;
    lista.exibirInverso(lista.head);
    cout << endl;

    lista.limpar(lista.head);
    lista.head = nullptr;
    lista.tamanho = 0;

    cout << "lista depois de lipar memoria: ";
    lista.exibir(lista.head);
    cout << endl;

    return 0;
}