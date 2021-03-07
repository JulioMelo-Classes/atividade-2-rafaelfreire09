#include "funcoes_classes.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

// Buscar musica na lista
int lista_musica::buscar(string nome1, string autor1){
    // Cria um novo objeto para percorrer a lista
	musica *atual=new musica;

    int existe=0;
    
    // Inicia a lista no head
	atual=head;

    //Percorre a lista até o fim
	while(atual!=NULL){
        if(atual->nome==nome1 && atual->autor==autor1){
            existe++;
        }
		atual=atual->next;
	}

    return existe;
}

// Adicionar uma nova música na lista
void lista_musica::inserir(string nome1, string autor1){

    // Cria um novo objeto para a música
    musica *novo = new musica;

    // Copia as informações para o objeto
	novo->nome = nome1;
    novo->autor = autor1;
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

// Excluir uma nova música na lista
void lista_musica::deletar(string nome2, string autor2){

    // Cria objetos para percorrer a lista e auxiliar na remoção
	musica *atual=new musica;
	musica *anterior=new musica;

    // Variáveis de identificação e contador
    int posi, achou=0;

    // Inicia a lista no head
	atual=head;
    
    //  Conta o tamanho da lista
    int tam=1;
	while(atual!=NULL){
        // Se achar a música
        if(atual->nome==nome2 && atual->autor==autor2){
            // Copia a localização
            posi = tam;
            achou++;
        }
		tam++;
        atual=atual->next;
	}

    tam--;

    // Recomeça o contador
    atual=head;

    // Se for 0 significa que não achou  
    if(achou==0){
        cout << "A musica nao foi encontrada!\n";
    // Se for maior que 0 significa que achou  
    }else{
        // Se for a primeira posição
        if(posi==1){
            // Retira da lista
            head=head->next;
            delete atual;
        // Se for a última posição
        }else if(posi==tam){
            // Percorre a té o final
            while(atual->next!=NULL){
                anterior=atual;
                atual=atual->next;	
            }
            // Retira da lista
            tail=anterior;
            anterior->next=NULL;
            delete atual;
        // Se estiver no meio
        }else{
            // Vai até a música
            for(int i=1; i<posi; i++){
                anterior=atual;
                atual=atual->next;
            }
            // Retira da lista
            anterior->next=atual->next;
        } 
    }
}

// Listar todas as músicas da lista
void lista_musica::listar(){

    // Cria um novo objeto para percorrer a lista
	musica *novo=new musica;
    
    // Inicia a lista no head
	novo=head;

	int i=1;
    //Percorre a lista até o fim
	while(novo!=NULL){
        // Imprime as informações
		cout << "--- Musica " << i << ":\n";
		cout<< "\tNome: " << novo->nome<<"\n";
        cout<< "\tAutor: " << novo->autor <<"\n";
		novo=novo->next;
		i++;
	}
}

// Mover a posição de uma música do sistema
void lista_musica::mover(int posi1, int posi2){

    // Cria objetos para percorrer a lista
	musica *atual=new musica;
	musica *anterior=new musica;
    // Objeto para a música que mudaremos as posiçao
    musica *movido=new musica;

    // Começamos do primmeiro nó
	atual=head;

    //  Conta o tamanho da lista
    int tam=0;
	while(atual!=NULL){
        atual=atual->next;
		tam++;
	}

    // Reomeçamos do primmeiro nó
    atual=head;

    // Se foram diferentes
    if(posi1!=posi2){
        // 1) Retirar a música da lista
        // Se for a primeira musica
        if(posi1 == 1){
            // Guarda o nó
            movido = atual;
            // E coloca o head a partir da segunda música
            head = head->next;
        // Se for a última
        }else if(posi1 == tam){
            // Percorre até o fim
            while(atual->next!=NULL){
                anterior=atual;
                atual=atual->next;	
            }
            // Guarda o nó
            movido = atual;
            // Coloca o tail no penultimo nó da lista
            tail=anterior;
            // E o último recebe NULL no seu ponteiro
            anterior->next=NULL;
        }else{
            // Remove da lista
            for(int i=1; i<posi1; i++){
                anterior=atual;
                atual=atual->next;
            }
            anterior->next=atual->next;
            // Copia as informações do nó para um objeto
            movido = atual;
        }

        // O tamanho da lista diminuiu em 1. Então...
        tam--;

        // Reomeçamos do primmeiro nó
        atual = head;

        // Recolocar a música na lista
        if(posi2 == 1){
            // Linka o novo nó que queremos incluir
            movido->next = head;
            // E coloca o head nele
            head = movido;
        }else if(posi2-1 == tam){
            // Coloca o tail no último nó da lista
            tail->next = movido;
            tail = movido;
            // E recebe NULL no seu ponteiro
            movido->next = NULL;
        }else{
            // Percorre a lista até chegar na posição
            for(int i=1; i<posi2-1; i++){
                atual=atual->next;
            }
            // Coloca a música devolta na lista
            movido->next=atual->next;
            atual->next=movido;
        }
    }else{
        cout << "\nMesma posição! Nada alterado...\n";
    }
}

// Listar todas as músicas da lista
void lista_musica::tocar(int posi){

    // Cria um novo objeto para percorrer a lista
	musica *novo=new musica;

    // Variável
    int achou=0;
    
    // Inicia a lista no head
	novo=head;

    cout << "\nPróxima tocada: \n";

    // 
    int i=1;
    while(novo!=NULL){
        if(i==posi){
            cout << "--- Musica " << i << ":\n";
		    cout<< "\tNome: " << novo->nome<<"\n";
            cout<< "\tAutor: " << novo->autor <<"\n\n";
            achou++;
        }
        novo=novo->next;
        i++;
    }

    if(achou==0){
        cout << "\nNão existe mais músicas para serem tocadas!\n";
    }
}

// Encontra a playlist na lista e retorna a posição
int lista_playlist::encontrar_playlist(string nome){

    // Cria um objeto para percorrer a lista
    playlist *atual = new playlist;

    // Variável de controle
    int i=0, n=0;

    // Inicia do head
    atual = head2;
    
    i++;
    do{
        // Se achar
        if(nome==atual->nome_playlist){
            // Passa a posição para n
            n=i;
        }
        atual=atual->next2;
        i++;
    // Não sai do laço até chegar no final
    } while (atual!=NULL);
    
    // Se não achar
    if(n==0){
        cout << "A playlist não foi encontrada" << endl;
    }

    // Retorna a posição da playlist
    return n;
}

// Adicionar uma nova música na lista
void lista_playlist::adicionar_playlist(string nome1){

    // Cria o novo objeto para a nova playlist
	playlist *novo = new playlist;

    // Passa as informações para o objeto
	novo->nome_playlist = nome1;
	novo->next2 = NULL;

    // Se não tiver nenhuma playlist
	if(head2==NULL){
		head2 = novo;
		tail2 = novo;
		novo = NULL;
	// Se já tiver
    }else{	
		tail2->next2 = novo;
		tail2 = novo;
	}
}

// Excluir uma nova música na lista
void lista_playlist::remover_playlist(string nome2){

    // Cria objetos para percorrer a lista e auxiliar na remoção
	playlist *atual=new playlist;
	playlist *anterior=new playlist;

    // Variáveis de identificação e contador
	int posi, achou=0;

    // Inicia a lista no head
	atual=head2;
    
    //  Conta o tamanho da lista
    int tam=1;
	while(atual!=NULL){
        // Se achar a música
        if(atual->nome_playlist==nome2){
            // Copia a localização
            posi = tam;
            achou++;
        }
		tam++;
        atual=atual->next2;
	}

    tam--;

    // Recomeça o contador
    atual=head2;

    // Se for 0 significa que não achou  
    if(achou==0){
        cout << "A playlist nao foi encontrada!\n";
    // Se for maior que 0 significa que achou 
    }else{
        // Se for a primeira posição
        if(posi==1){
            head2=head2->next2;
            delete atual;
        // Se for a última posição
        }else if(posi==tam){
            while(atual->next2!=NULL){
                anterior=atual;
                atual=atual->next2;	
            }
            tail2=anterior;
            anterior->next2=NULL;
            delete atual;
        }else{
            // Vai até a playlist
            for(int i=1; i<posi; i++){
                anterior=atual;
                atual=atual->next2;
            }
            // Retira da lista
            anterior->next2=atual->next2;
        } 
    }
}

// Listar todas as músicas da lista
void lista_playlist::listar_playlist(){

    // Cria um novo objeto para percorrer a lista
	playlist *novo=new playlist;

    // Inicia a lista no head
	novo=head2;

    cout << "\n";

    int i=1;
    //Percorre a lista até o fim
	while(novo!=NULL){
        // Imprime as informações
		cout<< "Nome da playlist " << i << ": " << novo->nome_playlist;
        if(novo->nome_playlist=="Todas as musicas"){
            cout << "(playlist padrao)\n";
        }else{
            cout << "\n";
        }
		novo=novo->next2;
		i++;
	}

    cin.ignore();    
    cout << "\n--- Tecle ENTER para continuar... ";
	getchar();
}

// Pega as informações da nova música e chama a função de adicionar na lista de músicas
void lista_playlist::adicionar_musica(lista_musica **musi, int n){

    // Variáveis para armazenar as informações da música
    string nome_mus, autor_mus;

    // Variável para verificar se tem a música na playlist do sistema
    int existe = 0;
            
	// Limpa o buffer
	cin.ignore();
    // Pega o nome da música
    cout << "\nDigite o nome da musica: ";
    getline(cin, nome_mus);

    // Pega o nome do autor
    cout << "Digite o nome do autor da musica: ";
    getline(cin, autor_mus);

    if(n==0){
        // Chama a função da lista de música para inserir, passando o nome da música e o nome do autor
        musi[n]->inserir(nome_mus, autor_mus);

        cout << "\n--- Musica adicionada com SUCESSO!\n";
    }else{
        // Chama a função de buscar muisca na playlist do sistema
        existe = musi[0]->buscar(nome_mus, autor_mus);
        // Se for 0, ou seja não existir
        if(existe==0){
            cout << "A música não existe no sistema\nAdicione primeiro no sistema para poder adicionar em outras playlists";
        }else{
            // Chama a função de buscar muisca na playlist do sistema
            musi[n]->inserir(nome_mus, autor_mus);

            cout << "\n--- Musica adicionada com SUCESSO!\n";
        }
    }

	cout << "\n--- Tecle ENTER para continuar... ";
	getchar();
}

// Pega as informações da música e chama a função de remover na lista de músicas
void lista_playlist::remover_musica(lista_musica **musi, int n, int tam){

    // Variáveis para armazenar as informações da música
    string nome_mus, autor_mus;

    // Variável para verificar se tem a música na playlist do sistema
    int existe = 0;

    // Pega o nome da música
    cout << "\nDigite o nome da musica a ser deletada: ";
    getline(cin, nome_mus);

    // Pega o nome do autor
    cout << "Digite o nome do autor da musica a ser deletada: ";
    getline(cin, autor_mus);

    // Chama a função da lista de música para deletar, passando o nome da música e o nome do autor
    musi[n]->deletar(nome_mus, autor_mus);

    // Se for na playlist do sistema
    if(n==0){
        // Percorre todas as listas
        for(int i=1; i<tam; i++){
            // Chama a função de buscar musica na playlist do sistema
            existe = musi[i]->buscar(nome_mus, autor_mus);
            // Se existir, ou seja diferente de 0
            if(existe!=0){
                // Chama a função da lista de música para deletar, passando o nome da música e o nome do autor
                musi[i]->deletar(nome_mus, autor_mus);
                cout << "\nMúsica removida em outra playlist\n";
            }
        }
    }

	cout << "\n--- Tecle ENTER para continuar... ";
	//getchar();
}

// Lista as músicas de uma playlist
void lista_playlist::listar_musica(lista_musica **musi, int n, string nome_play){

	cout << "\nNome da playlist: " << "-> " << nome_play<< " <-\n" << endl;
    // Chama a função da lista de música para listar
    musi[n]->listar();

	cout << "\n--- Tecle ENTER para continuar... ";
	getchar();
}

// Pega as informações da música e chama a função de mover na lista de músicas
void lista_playlist::mover_musica(lista_musica **musi, int n){

    // Variáveis para armazenar as posições desejadas
    int pos1, pos2;

    // Pega a posição para mover
    cout << "\nDigite a posição da musica para mover: ";
    cin >> pos1;

    // Pega a posição para realocar
    cout << "\nDigite a nova posição da musica para realocar: ";
    cin >> pos2;

    // Chama a função da lista de música para mover, passando as posições para mover a para realocar
    musi[n]->mover(pos1, pos2);

    cout << "\n--- Musica movida com SUCESSO!\n";

	cout << "\n--- Tecle ENTER para continuar... ";
	getchar();
}

// Lista as músicas de uma playlist
void lista_playlist::tocar_musica(lista_musica **musi, int n, string nome_play, int prox){

	cout << "\nNome da playlist: " << "-> " << nome_play<< " <-\n" << endl;
    // Chama a função da lista de música para listar
    musi[n]->tocar(prox);

    cin.ignore(); 
	cout << "\n--- Tecle ENTER para continuar... ";
	getchar();
}

// Pergunta ao usuário se deseja realizar outra operação
char outra_alteracao(char n){

    // Variável para pegar o caractere de resposta
    char esc1;

    switch (n){
        case '1':
            cout << "\nDeseja fazer outra alteração nas musicas do sistema?[s/n] ";
            cin >> esc1;
            break;
        case '2':
            cout << "\nDeseja fazer outra alteração nas playlists do sistema?[s/n] ";
            cin >> esc1;
            break;
        case '3':
            cout << "\nDeseja fazer outra alteração nas musicas da playlist?[s/n] ";
            cin >> esc1;
            break;
        default:
            break;
    }

    //Limpar a tela no windows ou linux
    cout << "\033[2J\033[1;1H";

    // Retorna a opção escolhida
    return esc1;
}
