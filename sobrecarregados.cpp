#include "funcoes_classes.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

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

// Pega as informações da nova música e chama a função de adicionar na lista de músicas
void lista_playlist::adicionar_musica(lista_musica **musi, int n, int tipo){

    // Variáveis para armazenar as informações da música
    string nome_mus, autor_mus;

    // Cria um objeto para ser a lista das novas músicas a serem adicionadas
    lista_musica lista_aux;

    string nome_playlist;

    if(tipo==1){

    char escolha='s';

    do{
        // Limpa o buffer
        cin.ignore();
        // Pega o nome da música
        cout << "\nDigite o nome da musica: ";
        getline(cin, nome_mus);

        // Pega o nome do autor
        cout << "Digite o nome do autor da musica: ";
        getline(cin, autor_mus);

        // Chama a função da lista de música para inserir, passando o nome da música e o nome do autor
        lista_aux.inserir(nome_mus, autor_mus);

        cout << "Deseja adicionar outra música a lista de adição?(s/n)";
        cin >> escolha;

    }while(escolha!='n');

    // Chama a função da lista de música para inserir, passando o nome da música e o nome do autor
    musi[n]->inserir(&lista_aux);

    }else if(tipo==2){
        // Pega o nome da playlist
        cout << "\nQual o nome da playlist para adicionar: ";
        getline(cin, nome_playlist1);

        // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
        pos_playlist = playlists.encontrar_playlist(nome_playlist1);
    }

	cout << "\n--- Tecle ENTER para continuar... ";
	getchar();
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

// Pega as informações da música e chama a função de remover na lista de músicas
void lista_playlist::remover_musica(lista_musica **musi, int n){

    // Variáveis para armazenar as informações das músicas
    string nome_mus, autor_mus;

    // Cria um objeto para ser a lista das novas músicas a serem removidas
    lista_musica lista_aux;

    char escolha='s';

    do{
        // Limpa o buffer
        cin.ignore();
        // Pega o nome da música
        cout << "\nDigite o nome da musica para ser removida: ";
        getline(cin, nome_mus);

        // Pega o nome do autor
        cout << "Digite o nome do autor da musica para ser removida: ";
        getline(cin, autor_mus);

        // Chama a função da lista de música para inserir, passando o nome da música e o nome do autor
        lista_aux.inserir(nome_mus, autor_mus);

        cout << "Deseja adicionar outra música a essa lista de remoção?(s/n)";
        cin >> escolha;

    }while(escolha!='n');

    // Chama a função da lista de música para deletar, passando o nome da música e o nome do autor
    musi[n]->deletar(&lista_aux);

    cout << "Os elementos que existiam na lista foram excluídos\n";

	cout << "\n--- Tecle ENTER para continuar... ";
	//getchar();
}

