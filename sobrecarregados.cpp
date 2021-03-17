#include "funcoes_classes.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
// Versão sobrecarregada de adicionar músicas na lista
void lista_musica::inserir(lista_musica *lista){

    // Cria objetos para percorrer a lista e auxiliar na remoção
	musica *atual=new musica;
	musica *anterior=new musica;

    // Inicia do head da lista principal
    atual = this->head;
    anterior = this->head;

    // Percorre até achar o último
    while(atual!=NULL){
        anterior=atual;
        atual = atual->next;
    }

    // Liga o ultimo nó da lista principal com a nova lista
    anterior->next = lista->head;

    // Percorre até achar o último
    while(anterior->next!=NULL){
        anterior = anterior->next;
    }

    // Passa o tail para o último
    tail = anterior;
    tail->next = anterior;

}
*/
// Versão sobrecarregada de adicionar músicas na lista
void lista_musica::inserir(lista_musica *lista){

    // Cria um novo objeto da lista principal
    musica *atual = new musica;

    // Inicia do head
    atual = head;

    // Se a lista for vazia
    if(head==NULL){
        // Passa o head para o da lista
        head = lista->head;
        atual = lista->head;
    // Se a lista não for
    }else{
        // Percorre até achar o último
        while(atual->next!=NULL){
            atual = atual->next;
        }
    }

    // Liga o ultimo nó da lista principal com a nova lista
    atual->next = lista->head;

    // Percorre até achar o último
    while(atual->next!=NULL){
        atual = atual->next;
    }

    // Passa o tail para o último
    tail = atual;
    tail->next = atual;
    
    cout << "\nChegou3\n";

}

// Versão sobrecarregada de excluir músicas na lista
void lista_musica::deletar(lista_musica *lista){

    // Variáveis para armazenar as informações das músicas
    string nome_mus, autor_mus;

    // Cria objetos para percorrer a lista
	musica *atual=new musica;

    // Variável para verificar se tem a música na lista
    int existe = 0;

    atual = lista->head;

    // Percorre até achar o último
    while(atual!=NULL){
        // Copia as informações
        nome_mus = atual->nome;
        autor_mus = atual->autor;

        // Chama a função de buscar musica na lista
        existe = this->buscar(nome_mus, autor_mus);
        // Se existir
        if(existe!=0){
            // Deleta a música
            this->deletar(nome_mus, autor_mus);
        }

        atual = atual->next;
    }
}

// Construtor cópia
lista_musica::lista_musica(const lista_musica &nova_playlist){
    head = nova_playlist.head;
    tail = nova_playlist.tail;
}

// Construtor cópia
lista_playlist::lista_playlist(const lista_playlist &nova_playlist){
    head2 = nova_playlist.head2;
    tail2 = nova_playlist.tail2;
}

// Função para o operador + para concatenar duas listas
lista_musica lista_musica::operator+(lista_musica &adicionada){

    // Cria o objeto que será concatenado
    lista_musica concatenada;

    // Copia o head
    concatenada.head = this->head;

    // Copia o tail
    concatenada.tail = this->tail;

    // Chama a função sobrecarregada de inserir uma lista 
    concatenada.inserir(&adicionada);

    // Retorna a lista concatenada
    return concatenada;
}

// Função para o operador << 
void lista_musica::operator<<(musica *&novo){

        // Variáveis para armazenar as informações da música
        string nome_mus, autor_mus;

        // Limpa o buffer
     //   cin.ignore();
        // Pega o nome da música
//        cout << "\nDigite o nome da musica para ser adicionado: ";
 //       getline(cin, nome_mus);

         // Pega o nome do autor
  //      cout << "Digite o nome do autor da musica para ser adicionado: ";
   ///     getline(cin, autor_mus);

        // Copia as informações para o objeto
     //   novo->nome = nome_mus;
      //  novo->autor = autor_mus;
        novo->next = NULL;

        // Se não tiver nenhuma música
        if(head==NULL){
            head = novo;
            tail = novo;
            novo = NULL;
        // Se já tiver
        }else{	
            tail->next = novo;
            tail = novo;
        }
}

// Função para o operador >>
void lista_musica::operator>>(musica *&removido){

    // Cria objetos para percorrer a lista e auxiliar na remoção
    musica *atual=new musica;
    musica *anterior=new musica;

    atual = head;
        
    while(atual->next!=NULL){
        anterior=atual;
        atual=atual->next;	
    }
    // Retira da lista
    tail=anterior;
    anterior->next=NULL;
    delete atual;
}

// Função para o operador + para adicionar uma nova música
lista_musica lista_musica::operator+(musica *&novo){

    // Cria a nova lista que vai ser retornada
    lista_musica nova_lista;

    // Copia o head
    nova_lista.head = this->head;

    // Copia o tail
    nova_lista.tail = this->tail;

    // Variáveis para armazenar as informações da música
    string nome_mus, autor_mus;

    // Limpa o buffer
    cin.ignore();
    // Pega o nome da música
    cout << "\nDigite o nome da musica para ser adicionada: ";
    getline(cin, nome_mus);

    // Pega o nome do autor
    cout << "Digite o nome do autor da musica para ser adicionada: ";
    getline(cin, autor_mus);

    nova_lista.inserir(nome_mus, autor_mus);

    return nova_lista;
}

// Função para o operador - para retornar uma playlist com a diferença de outras duas
lista_musica lista_musica::operator-(lista_musica const &segunda){

    // Cria a lista que será a diferença
    lista_musica diferenca;

    // Variáveis para percorrer as listas
    musica *atual1 = new musica;
    musica *atual2 = new musica;

    // Inicia do head
    atual1 = this->head;
    atual2 = segunda.head;

    // Percorre na primeira lista até chegar no final
    while(atual1!=NULL){
        // Percorre na segunda lista até chegar no final
        while(atual2!=NULL){
            // Se forem iguais quer dizer que achou
            if(atual1->nome==atual2->nome && atual1->autor==atual2->autor){
                // Chama a função de inserir na lista
                diferenca.inserir(atual1->nome, atual1->autor);
            }
            atual2 = atual2->next;    
        }
        atual1 = atual1->next;
        // Reinicia na segunda lista no head
        atual2 = segunda.head;
    }

    // Retorna a lista diferenca
    return diferenca;
}

// Função para o operador - para remover uma nova música
lista_musica lista_musica::operator-(musica *&removido){

    // Cria a nova lista que vai ser retornada
    lista_musica nova_lista;

    // Copia o head
    nova_lista.head = this->head;

    // Copia o tail
    nova_lista.tail = this->tail;

    // Variáveis para armazenar as informações da música
    string nome_mus, autor_mus;

    // Limpa o buffer
    cin.ignore();
    // Pega o nome da música
    cout << "\nDigite o nome da musica para ser removida: ";
    getline(cin, nome_mus);

    // Pega o nome do autor
    cout << "Digite o nome do autor da musica para ser removida: ";
    getline(cin, autor_mus);

    nova_lista.deletar(nome_mus, autor_mus);

    return nova_lista;
}
