    #include "funcoes_classes.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

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

// Versão sobrecarregada de adicionar músicas na lista
void lista_musica::inserir(lista_musica *lista){

    // Cria um novo objeto da lista principal
    musica *atual = new musica;

    // Inicia do head
    atual = head;

    // Percorre até achar o último
    while(atual->next!=NULL){
        atual = atual->next;
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
        if(existe==1){
            // Deleta a música
            this->deletar(nome_mus, autor_mus);
        }

        atual = atual->next;
    }
}

lista_musica::lista_musica(const lista_musica &nova_playlist){
    head = nova_playlist.head;
    tail = nova_playlist.tail;
}


lista_playlist::lista_playlist(const lista_playlist &nova_playlist){
    head2 = nova_playlist.head2;
    tail2 = nova_playlist.tail2;
}

// Função para o operador +
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
std::ostream& operator<<(std::ostream &posi, lista_musica **musi){

    // Se for nullptr
    if(nullptr){
        cout << "\nNada alterado\n";
    }else{

        // Variáveis para armazenar as informações da música
        string nome_mus, autor_mus;

        // Limpa o buffer
        cin.ignore();
        // Pega o nome da música
        cout << "\nDigite o nome da musica para ser adicionado: ";
        getline(cin, nome_mus);

         // Pega o nome do autor
        cout << "Digite o nome do autor da musica para ser adicionado: ";
        getline(cin, autor_mus);

        // Chama a função da lista de música para inserir, passando o nome da música e o nome do autor
        musi[]->inserir(nome_mus, autor_mus);
    }
}

// Função para o operador <<
std::ostream& operator>>(std::ostream &posi, lista_musica **musi){

    // Se for nullptr
    if(nullptr){
        cout << "\nNada alterado\n";
    }else{

        // Variáveis para armazenar as informações da música
        string nome_mus, autor_mus;

        // Limpa o buffer
        cin.ignore();
        // Pega o nome da música
        cout << "\nDigite o nome da musica para ser adicionado: ";
        getline(cin, nome_mus);

         // Pega o nome do autor
        cout << "Digite o nome do autor da musica para ser adicionado: ";
        getline(cin, autor_mus);

        // Chama a função da lista de música para inserir, passando o nome da música e o nome do autor
        musi[]->inserir(nome_mus, autor_mus);
    }
}

// Função para o operador +
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

