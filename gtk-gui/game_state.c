#include <gtk-3.0/gtk/gtk.h>
#include "game_state.h"
#include <stdlib.h>

GameState game;

void init(){

	
}

void print_current_player(){

	g_print("SCORE: %d", game.current_player);
}

void add_player(const char *name){
	int num_players_old = game.num_players;
	game.num_players = num_players_old + 1;
	strcpy(game.player_names[game.num_players - 1], name);
	game.scores[game.num_players -1] = 501;
}
