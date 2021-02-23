#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include "funcoes_classes.hpp"

using namespace std;

int main(){

    // Variáveis para escolha no menu
    char n_esc='0', n_esc2='0';
    char esc='s';

    // Variável de contador de listas de músicas
    int i=0;

    // Variável para controlar as musicas que seram tocadas
    int prox;

    // Variável
    int pos_playlist;

    // Variável
	string nome_playlist1;

    // Cria o objeto da classe de lista de playlsts
    lista_playlist playlists;

    // Cria o objeto da classe de lista de musicas
    lista_musica **listas;
    listas = new lista_musica*[1];

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
            << "4 - Encerrar o programa."<<"\n\n"
            << ">>> Tecle 1, 2, 3 ou 4 para escolher: ";
            
            // Recebe o comando
            cin >> n_esc;

            //Limpar a tela no windows ou linux
            cout << "\033[2J\033[1;1H";
        // Só sai do laço se escolher entre 1 e 4
        } while(n_esc<48 && n_esc>51);

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
                            playlists.adicionar_musica(listas, 0);

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
                            playlists.remover_musica(listas, 0, i);

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
                            playlists.adicionar_musica(listas, pos_playlist-1);

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
                            playlists.remover_musica(listas, pos_playlist-1, i);

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
                break;
            break;
        }

        // Limpar a tela no Windows ou linux
        cout << "\033[2J\033[1;1H";

    }

    cout << "Programa encerrado" << endl;

	return 0;
}