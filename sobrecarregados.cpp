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

// Função para o operador >>
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