#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//Fun��o auxiliar que troca '\n' por '\0' (thx @Yarquen! :D)
void remove_newline_ch(char* line);

//Defini��o das palavras-chave, cada uma vai ter uma string e um apontamento para uma pr�xima, caso existir
typedef struct palavraChave
{
	char categoria[64];
	struct palavraChave* proxima;
	struct palavraChave* anterior;

} PalavraChave;

//Definindo que uma Lista de Palavras-chave.
typedef struct palavrasChave {

	PalavraChave* inicio;
	PalavraChave* fim;

} PalavrasChave;

//Defini��o do meu podcast, vai possuir um id, uma string nome(podcast), uma string nome(epis�dio) e um numero do epis�dio
typedef struct podcast
{
	int podcastId;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numeroEpisodio;

	PalavrasChave* palavrasChave;

	struct podcast* proximo;
	struct podcast* anterior;

} Podcast;

//Definindo que um ponteiro para um Podcast vai se chamar Podquest
typedef Podcast* Podquest;

//Defini��o da minha lista, possuindo 3 ponteiros: in�cio, atual e fim
typedef struct playlist
{
	Podquest inicio;
	Podquest atual;
	Podquest fim;
	
} Playlist;

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Playlist na mem�ria
* @return novaPlaylist, a nova Playlist com os apontamentos de mem�ria para o in�cio, fim e atual apontando para NULL
*/
Playlist* llcriaPlaylist();

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma lista de PalavraChave na mem�ria
* @return novaPalavrasChave, a nova lista de PalavraChave com os apontamentos de mem�ria para o in�cio e fim apontando para NULL
*/
PalavrasChave* criaPalavrasChave();

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma PalavraChave na mem�ria (dados dessa PalavraChave ser�o pedidos nessa fun��o)
* @return novaPalavrasChave, a nova PalavraChave com os apontamentos de mem�ria para o pr�ximo apontando para NULL
*/
PalavraChave* criaPalavraChave();

/**
* @brief adiciona uma palavra-chave no fim da lista de palavras-chave
* @param palavrasChave -> Lista de palavras-chave
* @return 1 -> se mais palavras v�o ser inseridas
* @return 0 -> se mais palavras v�o ser inseridas
*/
int adicionaPalavraChave(PalavrasChave* palavrasChave);

/**
* @brief Fun��o que aloca um espa�o do tamanho de um Podquest na mem�ria (dados desse Podquest ser�o pedidos nessa fun��o)
* @return novoPodquest, a nova Playlist com os apontamentos de mem�ria para o pr�ximo e anterior apontando para NULL
*/
Podquest criaPodquest();

/**
* @brief adiciona um Podquest na Playlist ordenado pelo ID
* @param playlist -> Lista de Podquest
*/
void llInserePodquestOrdenado(Playlist* playlist);

/**
* @brief adiciona um Podquest no final da Playlist
* @param playlist -> Lista de Podquest
*/
void llInserePodquestFim(Playlist* playlist);

/**
* @brief Fun��o que verifica se um Podquest existe na Playlist, e caso exista, o retorna
* @param playlist -> Playlist na qual vai acontecer a busca
* @param idBusca -> Id do Podquest que vai ser buscado
* @param epsBusca -> Episodio do Podquest que vai ser buscado
* @return aux -> O Podquest buscaso
* @return NULL -> Caso o Podquest n�o exista na lista
*/
Podquest llBuscaPodquest(Playlist* playlist, int idBusca, int epsBusca);

/**
* @brief Fun��o que busca um elemento na lista e se o encontrar, o remove
* @param playlist -> Playlist a qual vai ter o Podquest removido
*/
void llremovePodquest(Playlist* playlist);

/**
* @brief Fun��o que come�a a tocar a playlist
* @param playlist -> Playlist que vai ser tocada
*/
void lltocar(Playlist* playlist);

/**
* @brief Fun��o que toca o pr�ximo Podquest da PLaylist, caso o shuffle esteja ligado, toca um dos pr�ximos Podquests aleatoriamente
* @param playlist -> Playlist que vai ser tocada
* @param shuffle -> Boolean dizendo se est� ligado ou n�o
*/
void lltocaProximo(Playlist* playlist, bool shuffle);

/**
* @brief Fun��o que toca o pr�ximo Podquest da PLaylist, caso o shuffle esteja ligado, toca um dos pr�ximos Podquests aleatoriamente
* @param playlist -> Playlist que vai ser tocada
*/
void lltocaAnterior(Playlist* playlist);

/**
* @brief Fun��o que imprime os Podquests da Playlist
* @param playlist -> playlist que vai ser impressa
*/
void llrelatorio(Playlist* playlist);