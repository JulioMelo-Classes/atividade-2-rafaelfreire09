#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include "funcoes_classes.hpp"

using namespace std;

/*
void f2(Playlist l){
  l.list.remove(1);
  cout<<"lista l na funcao apos remocação"<<endl;
  l.list.show(l.list.head, 1);
}
*/
void f(lista_musica l){
  l.deletar("Just Dance", "Lagy Gaga");
  cout<<"lista l na funcao apos remocação"<<endl;
  l.listar();
}


void testes(){
  lista_musica l1;
  l1.inserir("Just Dance", "Lagy Gaga");
  l1.inserir("Shallow", "Lagy Gaga");
  l1.inserir("Where is the love", "BEP");
  l1.inserir("I gotta feeling", "BEP");

	lista_musica lr;
	//lr.inserir(&l1);
  /*Q1a 0.3, vi que vc implementou  mas não consigo listar a cópia!*/
//	lr.listar();
		
	
	/*Q2b 1, ok*/
	lista_musica l2;
  l2.inserir("Just Dance", "Lagy Gaga");

	//l1.deletar(&l2);
	//l1.listar();

	/*Q3c 0.5, vc implementou mas da forma como está as copias ficam interligadas com a principal*/
	//f(l1);
	//l1.listar();

	/*Q2a 0.5, loop infinito no caso abaixo (depois de listar) */
	//lista_musica lr2 = l1 + l2;
	//lr2.listar();

	/*Q2b 0.8, o operador não deveria perguntar ao usuário qualquer coisa...*/
	//musica *m = new musica;
	//m->nome = "n1";
	//m->autor = "a1";
	//l2 << m;
	//l2.listar();

	/*Q2c 0.5, vc removeu mas não preencheu no operando recebido*/
	//l2 >> m;
	//l2.listar();
	//cout << m->nome<<endl;
	
	/*Q3a e Q3b 0.3 e 1 inferido da classe lista_musica*/
	
	/*Q3c 0*/

	/*Q4a 0.5 inferido de lista_musica*/

	/*Q4b 0.8, o operador não deveria perguntar ao usuário qualquer coisa*/
	//lista_musica lr3 = l1 + m;
	//lr3.listar();

	/*Q4c 0.5, vc implementou mas a operação abaixo mostra que não está 100% ainda*/	
	//lista_musica lr4 = l1 - l2; 
	//lr4.listar();

	/*Q4d 0.8, não deveria perguntar qualquer coisa ao usuário*/
	
	/*Q4e e f 0*/

	exit(1);
}

int main(){
		testes();


		

    // Variáveis para escolha no menu
    char n_esc='0', n_esc2='0';
    char esc='s';

    int tipo=1;

    // Variável de contador de listas de músicas
    int i=0;

    // Variável para controlar as musicas que seram tocadas
    int prox;

    // Variável para identificar a localização de uma playlist
    int pos_playlist, pos_playlist2;

    int caso_playlist=0;

    // Variáveis para armazenar as informações da música
    string nome_mus, autor_mus;

    // Variáveis para guardar os nomes das playlists
    string conca_playlist1, conca_playlist2;

    // Variável
	string nome_playlist1, nome_playlist2;

    // Cria o objeto da classe de lista de playlsts
    lista_playlist playlists;

    // Cria o objeto da classe de lista de musicas
    lista_musica **listas;
    listas = new lista_musica*[1];

    // Variável para os construtores cópia
    lista_musica **listas2;
    lista_playlist nova_lista_playlist;

    // Variável para as operações sobrecarregadas
    lista_musica nova_lista;

    // Variável para o operador << 
    musica *aux = new musica;

    // Cria a primeira playlist, que será a principal com todas as músicas
    listas[i] = new lista_musica();
    // Variável para o nome
    string todas_musicas = "Todas as musicas";
    // Adiciona a lista de playlist
    playlists.adicionar_playlist(todas_musicas);
    // Aloca o nome na lista
    listas[i]->nome_playlist = todas_musicas;

    while(n_esc!='4'){

        // Primeira opção de escolha
        do{
            cout 
            << "\n1 - Gerenciar músicas do sistema."<<"\n"
            << "\t1.1 - Adicionar."<<"\n"
            << "\t1.2 - Remover."<<"\n"
            << "\t1.3 - Listar."<<"\n"
            << "2 - Gerenciar playlists do sistema."<<"\n"
            << "\t2.1 - Adicionar."<<"\n"
            << "\t2.2 - Remover."<<"\n"
            << "\t2.3 - Listar."<<"\n"
            << "3 - Gerenciar músicas em uma playlist."<<"\n"
            << "\t3.1 - Adicionar."<<"\n"
            << "\t3.2 - Remover."<<"\n"
            << "\t3.3 - Listar."<<"\n"
            << "\t3.4 - Mover."<<"\n"
            << "\t3.5 - Tocar."<<"\n"
            << "4 - Gerenciar funções sobrecarregadas."<<"\n"
            << "\t4.1 - Adicionar elementos(lista ligada)"<<"\n"
            << "\t4.2 - Remover elementos(lista ligada)"<<"\n"
            << "\t4.3 - Construtor cópia(lista ligada)"<<"\n"
            << "\t4.4 - Adicionar músicas(playlist)"<<"\n"
            << "\t4.5 - Remover músicas(playlist)"<<"\n"
            << "\t4.6 - Construtor cópia(playlist)"<<"\n"
            << "5 - Gerenciar operações sobrecarregadas."<<"\n"
            << "\t5.1 - Operador + 1(lista ligada)"<<"\n"
            << "\t5.1 - Operador de extração >>(lista ligada)"<<"\n"
            << "\t5.2 - Operador de inserção <<(lista ligada)"<<"\n"
            << "\t5.1 - Operador + 1(playlist)"<<"\n"
            << "\t5.2 - Operador + 2(playlist)"<<"\n"
            << "\t5.1 - Operador - 1(playlist)"<<"\n"
            << "\t5.2 - Operador - 2(playlist)"<<"\n"
            << "\t5.1 - Operador de extração >>(playlist)"<<"\n"
            << "\t5.2 - Operador de inserção <<(playlist)"<<"\n"
            << "6 - Encerrar o programa."<<"\n\n"
            << ">>> Tecle 1, 2, 3, 4, 5 ou 6 para escolher: ";
            
            // Recebe o comando
            cin >> n_esc;

            //Limpar a tela no windows ou linux
            cout << "\033[2J\033[1;1H";
        // Só sai do laço se escolher entre 1 e 4
        } while(n_esc<48 && n_esc>54);

        switch (n_esc){
            case '1':
                
                esc='s';
                do{
                    do{
                        cout
                        << ">>> Gerenciar músicas do sistema.<<<"<<"\n\n"
                        << "1 - Adicionar musica ao sistema."<<"\n"
                        << "2 - Remover musica do sistema."<<"\n"
                        << "3 - Listar musicas do sistema."<<"\n"
                        << "4 - Voltar."<<"\n\n"
                        << ">>> Tecle 1, 2, 3 ou 4 para escolher: ";

                        // Recebe o comando
                        cin >> n_esc2;

                        //Limpar a tela no windows ou linux
                        cout << "\033[2J\033[1;1H";

                    }while(n_esc2<49 && n_esc2>52);

                    switch (n_esc2){
                        case '1':

                            cout
                            << ">>> Gerenciar músicas do sistema.<<<"<<"\n\n"
                            << "1 - Adicionar musica ao sistema."<<"\n";

                            // Chama a função de listar músicas, passando a lista de músicas, a posição 0 e o nome da playlist para listar
                            playlists.listar_musica(listas, 0, todas_musicas);

                            // Chama a função de adicionar música, passando a lista de músicas e a posição 0
                            playlists.adicionar_musica(listas, 0, tipo, caso_playlist);

                            // Chama a função de listar músicas, passando a lista de músicas, a posição 0 e o nome da playlist para listar
                            playlists.listar_musica(listas, 0, todas_musicas);

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);

                        break;

                        case '2':
                            
                            cout
                            << ">>> Gerenciar músicas do sistema.<<<"<<"\n\n"
                            << "2 - Remover musica do sistema."<<"\n";

                            // Chama a função de listar músicas, passando a lista de músicas, a posição 0 e o nome da playlist para listar
                            playlists.listar_musica(listas, 0, todas_musicas);

                            // Chama a função de remover, passando a lista de músicas e a posição 0
                            playlists.remover_musica(listas, 0, i, tipo, caso_playlist);

                            // Chama a função de listar músicas, passando a lista de músicas, a posição 0 e o nome da playlist para listar
                            playlists.listar_musica(listas, 0, todas_musicas);

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);

                        break;

                        case '3':

                            // Chama a função de listar músicas, passando a lista de músicas, a posição 0 e o nome da playlist para listar
                            playlists.listar_musica(listas, 0, todas_musicas);

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                            
                        break;

                        case '4':
                            esc='n';
                        break;
                    }
                }while(esc!='n');
            break;

            case '2':

                esc='s';
                do{
                    do{
                    
                        cout
                        << ">>> Gerenciar playlists do sistema.<<<"<<"\n\n"
                        << "1 - Adicionar playlist."<<"\n"
                        << "2 - Remover playlist."<<"\n"
                        << "3 - Listar playlists."<<"\n"
                        << "4 - Voltar."<<"\n\n"
                        << ">>> Tecle 1, 2, 3 ou 4 para escolher: ";

                        // Recebe o comando
                        cin >> n_esc2;

                        //Limpar a tela no windows ou linux
                        cout << "\033[2J\033[1;1H";

                    } while(n_esc2<49 && n_esc2>51);

                    switch (n_esc2){
                        case '1':

                            cout
                            << ">>> Gerenciar playlists do sistema.<<<"<<"\n"
                            << "\n1 - Adicionar playlist."<<"\n\n";

                            // Chama a função de listar as playlists da lista encadeada
                            playlists.listar_playlist();

                            // Limpa o buffer
                            cin.ignore();
                            // Pega o nome da playlist
                            cout << "Qual o nome da nova playlist: ";
                            getline(cin, nome_playlist1);
                            
                            // Chama a função de adicionar playlist, passando o nome da playlist
                            playlists.adicionar_playlist(nome_playlist1);

                            // Aumenta o contador de quantidade de músicas
                            i++;

                            // Cria uma nova posição para a playlist
                            listas[i] = new lista_musica();
                            // Armazena o nome
                            listas[i]->nome_playlist = nome_playlist1;

                            // Chama a função de listar as playlists da lista encadeada
                            playlists.listar_playlist();

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                            
                        break;

                        case '2':

                            cout
                            << ">>> Gerenciar playlists do sistema.<<<"<<"\n"
                            << "\n2 - Remover playlist."<<"\n\n";

                            // Chama a função de listar as playlists da lista encadeada
                            playlists.listar_playlist();

                            // Pega o nome da playlist
                            cout << "\nQual o nome da playlist para remover: ";
                            getline(cin, nome_playlist1);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(nome_playlist1);

                            // Deleta lista com a respectiva posição
                            delete listas[pos_playlist];

                            // Chama a função de remover playlist e passando o nome da playlist
                            playlists.remover_playlist(nome_playlist1);

                            // Aumenta o contador de quantidade de músicas
                            i--;

                            // Chama a função de listar as playlists da lista encadeada
                            playlists.listar_playlist();

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                            
                        break;

                        case '3':
                            // Chama a função de listar as playlists da lista encadeada
                            playlists.listar_playlist();

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                        break;

                        case '4':
                            esc='n';
                        break;
                    }
                }while(esc!='n');

            break;

            case '3':

                prox = 1;

				cout 
                << ">>> Gerenciar músicas em uma playlist.<<<"<<"\n\n";

                // Chama a função de listar as playlists da lista encadeada
                playlists.listar_playlist();

                pos_playlist=0;
				do{
                    // Pega o nome da playlist
                    cout << "\nQual o nome da playlist para gerenciar: ";
                    getline(cin, nome_playlist1);

                    // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                    pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                    if(pos_playlist==0){
                        cout << "\nDigite uma playlist valida!\n";
                    }
                }while(pos_playlist==0);

				// Limpar a tela no windows ou linux
				//cout << "\033[2J\033[1;1H";

                esc='s';
                do{
                    do{

                        cout
                        << ">>> Gerenciar músicas em uma playlist.<<<"<<"\n\n"
                        << "1 - Adicionar musica em "<< "> " << nome_playlist1 << " <" <<"\n"
                        << "2 - Remover musica em "<< "> " << nome_playlist1 << " <" <<"\n"
                        << "3 - Listar musica em "<< "> " << nome_playlist1 << " <" <<"\n"
                        << "4 - Mover musica em "<< "> " << nome_playlist1 << " <" <<"\n"
                        << "5 - Tocar próxima música em "<< "> " << nome_playlist1 << " <" <<"\n"
                        << "6 - Reiniciar o tocador para o início em "<< "> " << nome_playlist1 << " <" <<"\n"
                        << "7 - Voltar."<<"\n\n"
                        << ">>> Tecle 1, 2, 3, 4, 5, 6 ou 7 para escolher: ";

                        // Recebe o comando
                        cin >> n_esc2;

                        // Limpar a tela no windows ou linux
                        cout << "\033[2J\033[1;1H";

                    } while(n_esc2<49 && n_esc2>54);

                    switch (n_esc2){
                        case '1':
                            cout << ">>> Lista de todas as musicas no sistema.<<<"<<"\n";

                            // Chama a função de listar as músicas da playlist com todas as músicas do sistema, passando o objeto com todas as listas, a posição e o nome da playlist
                            playlists.listar_musica(listas, 0, todas_musicas);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                            // Chama a função de adicionar música, passando a lista de músicas e a posição da playlist
                            playlists.adicionar_musica(listas, pos_playlist-1, tipo, caso_playlist);

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);

                        break;

                        case '2':

                            cout << ">>> Lista de todas as musicas na playlist " << nome_playlist1 <<"\n";

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                            // Chama a função de listar as músicas da playlist, passando o objeto com todas as listas, a posição e o nome da playlist
                            playlists.listar_musica(listas, pos_playlist-1, nome_playlist1);
                            // Chama a função de remover, passando a lista de músicas e a posição da playlist
                            playlists.remover_musica(listas, pos_playlist-1, i, tipo, caso_playlist);

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                        break;

                        case '3':

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                            // Chama a função de listar as músicas da playlist, passando o objeto com todas as listas, a posição e o nome da playlist
                            playlists.listar_musica(listas, pos_playlist-1, nome_playlist1);

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                        break;

                        case '4':
                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                            // Chama a função de listar as músicas da playlist, passando o objeto com todas as listas, a posição e o nome da playlist
                            playlists.listar_musica(listas, pos_playlist-1, nome_playlist1);
                            // Chama a função de mover as músicas da playlist, passando o objeto com todas as listas e a posição
                            playlists.mover_musica(listas, pos_playlist-1);

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                        break;

                        case '5':

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(nome_playlist1);

                            //
                            playlists.tocar_musica(listas, pos_playlist-1, nome_playlist1, prox);

                            // Avança para a próxima música
                            prox++;

                            // Chama a função para perguntar se deseja fazer outra alteração no mesmo menu
                            esc = outra_alteracao(n_esc);
                        break; 

                        case '6':
                            // Reinicia o contador
                            prox=0;
                        break;

                        case '7':
                            esc='n';
                        break;
                    }
                }while(esc!='n');

            break;

            case '4':

                // Chama a função de listar as playlists da lista encadeada
                playlists.listar_playlist();

                pos_playlist=0;
				do{
                    // Pega o nome da playlist
                    cout << "\nQual o nome da playlist para gerenciar: ";
                    getline(cin, nome_playlist1);

                    // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                    pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                    if(pos_playlist==0){
                        cout << "\nDigite uma playlist valida!\n";
                    }
                }while(pos_playlist==0);

                // Limpar a tela no windows ou linux
				cout << "\033[2J\033[1;1H";

                do{
                    cout
                    << "\n>>> Gerenciar funções sobrecarregadas em -> "<< nome_playlist1 <<"\n"
                    << "1 - Adicionar elementos(lista ligada)"<<"\n"
                    << "2 - Remover elementos(lista ligada)"<<"\n"
                    << "3 - Construtor cópia(lista ligada)"<<"\n"
                    << "4 - Adicionar músicas(playlist)"<<"\n"
                    << "5 - Remover músicas(playlist)"<<"\n"
                    << "6 - Construtor cópia(playlist)"<<"\n"
                    << "\n>>> Tecle 1, 2, 3, 4, 5 ou 6 para escolher: ";

                    // Recebe o comando
                    cin >> n_esc2;

                    // Limpar a tela no windows ou linux
                    cout << "\033[2J\033[1;1H";

                } while(n_esc2<49 && n_esc2>54);

                tipo=2;                

                switch(n_esc2){
                    case '1':

                        // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                        pos_playlist = playlists.encontrar_playlist(nome_playlist1);

                        // Chama a função de adicionar música, passando a lista de músicas, a posição, e dois identificadores
                        playlists.adicionar_musica(listas, pos_playlist-1, tipo, caso_playlist);
                    break;
                    case '2':

                        // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                        pos_playlist = playlists.encontrar_playlist(nome_playlist1);

                        // Chama a função de remover música, passando a listas de músicas, a posição, e dois identificadores
                        playlists.remover_musica(listas, pos_playlist-1, i, tipo, caso_playlist);
                    break;
                    case '3':

                        i++;
                        // Chama o construtor cópia
                        listas[i] = listas[pos_playlist-1];

                    break;
                    case '4':

                        pos_playlist2=0;
                        do{
                            // Limpa o buffer
                            cin.ignore();

                            // Pega o nome da playlist
                            cout << "\nQual o nome da playlist para adicionar: ";
                            getline(cin, nome_playlist2);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist2 = playlists.encontrar_playlist(nome_playlist2);
                            if(pos_playlist2==0){
                                cout << "\nDigite uma playlist valida!\n";
                            }
                        }while(pos_playlist2==0);

                        caso_playlist = pos_playlist;
                        // Chama a função de adicionar música, passando a lista de músicas e a posição da playlist
                        playlists.adicionar_musica(listas, pos_playlist2-1, tipo, caso_playlist);
                    break;
                    case '5':

                        // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                        pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                        
                        // Chama a função de remover música, passando a listas de músicas, a posição, e dois identificadores
                        playlists.remover_musica(listas, pos_playlist, i, tipo, caso_playlist);

                    break;
                    case '6':
                        // Chama o construtor cópia
                        nova_lista_playlist = playlists;
                    break;
                }
            break;

            case '5':

                // Chama a função de listar as playlists da lista encadeada
                playlists.listar_playlist();

                pos_playlist=0;
				do{
                    // Pega o nome da playlist
                    cout << "\nQual o nome da playlist para gerenciar: ";
                    getline(cin, nome_playlist1);

                    // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                    pos_playlist = playlists.encontrar_playlist(nome_playlist1);
                    if(pos_playlist==0){
                        cout << "\nDigite uma playlist valida!\n";
                    }
                }while(pos_playlist==0);

                // Limpar a tela no windows ou linux
				cout << "\033[2J\033[1;1H";

                do{
                    cout
                    << "\n>>> Gerenciar operações sobrecarregadas em -> "<< nome_playlist1 <<"\n"
                    << "1 - Operador +(lista ligada)"<<"\n"
                    << "2 - Operador de extração >>(lista ligada)"<<"\n"
                    << "3 - Operador de inserção <<(lista ligada)"<<"\n"
                    << "4 - Operador + 1(playlist)"<<"\n"
                    << "5 - Operador + 2(playlist)"<<"\n"
                    << "6 - Operador - 1(playlist)"<<"\n"
                    << "7 - Operador - 2(playlist)"<<"\n"
                    << "8 - Operador de extração >>(playlist)"<<"\n"
                    << "9 - Operador de inserção <<(playlist)"<<"\n"
                    << "\n>>> Tecle 1, 2, 3, 4, 5, 6, 7, 8 ou 9 para escolher: ";

                    // Recebe o comando
                    cin >> n_esc2;

                    // Limpar a tela no windows ou linux
                    cout << "\033[2J\033[1;1H";

                } while(n_esc2<49 && n_esc2>57);

                tipo=2;                

                switch(n_esc2){
                    case '1':
                        // Chama a função de listar as playlists da lista encadeada
                        playlists.listar_playlist();

                        pos_playlist=0, pos_playlist2=0;

                        do{
                            // Pega o nome da playlist
                            cout << "\nQual a primeira playlist para concatenar: ";
                            getline(cin, conca_playlist1);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(conca_playlist1);
                            if(pos_playlist==0){
                                cout << "\nDigite uma playlist valida!\n";
                            }
                        }while(pos_playlist==0);

                        do{
                            // Pega o nome da playlist
                            cout << "\nQual a segunda playlist para concatenar: ";
                            getline(cin, conca_playlist1);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist2 = playlists.encontrar_playlist(conca_playlist1);
                            if(pos_playlist2==0){
                                cout << "\nDigite uma playlist valida!\n";
                            }
                        }while(pos_playlist2==0);

                        //nova_lista = listas[pos_playlist] + listas[pos_playlist2];

                        nova_lista.listar();
                    break;
                    case '2':
                        // Verifica se a playlist está vazia
                        if(listas[pos_playlist]->head == NULL){
                            cout << "\nNada feito\n";
                        }else{
                            //listas[pos_playlist] >> aux;
                        }
                    break;
                    case '3':
                        // Limpa o buffer
                        cin.ignore();
                        // Pega o nome da música
                        cout << "\nDigite o nome da musica(digite 'nullptr' para ser nulo): ";
                        getline(cin, nome_mus);

                        // Pega o nome do autor
                        cout << "Digite o nome do autor da musica(digite 'nullptr' para ser nulo): ";
                        getline(cin, autor_mus);

                        /*
                        if(nome_mus=='nullptr' || autor_mus=='nullptr'){
                            cout << "\nNada feito\n";
                        }else{
                            //listas[pos_playlist] << aux;
                        }
                        */
                    
                    break;
                    case '4':
                        // Chama a função de listar as playlists da lista encadeada
                        playlists.listar_playlist();

                        pos_playlist=0, pos_playlist2=0;

                        do{
                            // Pega o nome da playlist
                            cout << "Qual a primeira playlist para unir: ";
                            getline(cin, conca_playlist1);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(conca_playlist1);
                            if(pos_playlist==0){
                                cout << "\nDigite uma playlist valida!\n";
                            }
                        }while(pos_playlist==0);

                        do{
                            // Pega o nome da playlist
                            cout << "Qual a segunda playlist para unir: ";
                            getline(cin, conca_playlist1);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist2 = playlists.encontrar_playlist(conca_playlist1);
                            if(pos_playlist2==0){
                                cout << "\nDigite uma playlist valida!\n";
                            }
                        }while(pos_playlist2==0);

                        //nova_lista = listas[pos_playlist] + listas[pos_playlist2];
                    break;
                    case '5':

                        // nova_lista = listas[pos_playlist] + aux;

                    break;
                    case '6':
                        // Chama a função de listar as playlists da lista encadeada
                        playlists.listar_playlist();

                        pos_playlist=0, pos_playlist2=0;

                        do{
                            // Pega o nome da playlist
                            cout << "Qual a primeira playlist para fazer a diferença: ";
                            getline(cin, conca_playlist1);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist = playlists.encontrar_playlist(conca_playlist1);
                            if(pos_playlist==0){
                                cout << "\nDigite uma playlist valida!\n";
                            }
                        }while(pos_playlist==0);

                        do{
                            // Pega o nome da playlist
                            cout << "Qual a segunda playlist para fazer a diferença: ";
                            getline(cin, conca_playlist1);

                            // Chama a função de encontar, passando o nome da playlist e retornando a posição na lista
                            pos_playlist2 = playlists.encontrar_playlist(conca_playlist1);
                            if(pos_playlist2==0){
                                cout << "\nDigite uma playlist valida!\n";
                            }
                        }while(pos_playlist2==0);

                        // nova_lista = listas[pos_playlist] - listas[pos_playlist2];
                    break;
                    case '7':
                        // nova_lista = listas[pos_playlist] - aux;
                    break;
                    case '8':
                        // Verifica se a playlist está vazia
                        if(listas[pos_playlist]->head == NULL){
                            cout << "\nNada feito\n";
                        }else{
                            //listas[pos_playlist] >> aux;
                        }
                    break;
                    case '9':
                        // Limpa o buffer
                        cin.ignore();
                        // Pega o nome da música
                        cout << "\nDigite o nome da musica(digite 'nullptr' para ser nulo): ";
                        getline(cin, nome_mus);

                        // Pega o nome do autor
                        cout << "Digite o nome do autor da musica(digite 'nullptr' para ser nulo): ";
                        getline(cin, autor_mus);

                        /*
                        if(nome_mus=='nullptr' || autor_mus=='nullptr'){
                            cout << "\nNada feito\n";
                        }else{
                            //listas[pos_playlist] << aux;
                        }
                        */
                    break;
                }
            break;
            case 6: 
                break;
            break;
        }

        // Limpar a tela no Windows ou linux
        cout << "\033[2J\033[1;1H";

    }

    cout << "Programa encerrado" << endl;

	return 0;
}
