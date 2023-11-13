#include <gtk-3.0/gtk/gtk.h>
#include "game_state.h"
#include <stdlib.h>

GameState game;

void init(){}

void print_current_player(){

	g_print("SCORE: %d", game.current_player);
}

void add_player(const char *name){
	int num_players_old = game.num_players;
	game.num_players = num_players_old + 1;
	strcpy(game.player_names[game.num_players - 1], name);
	game.scores[game.num_players -1] = 501;
}

void next_player(){
	game.current_player =(game.current_player + 1) % game.num_players;
}

void submit_points(int points){
	game.scores[game.current_player] -= points;
	next_player();
}
