#include <gtk-3.0/gtk/gtk.h>
#include "game_state.h"
#include <stdlib.h>

GameState game;

void init(){

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 4; j++){
			game.throws[j][i] = -1;
		}
	}
	
}

void print_current_player(){
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

void previous_player(){
	game.current_player = (game.current_player - 1) % game.num_players;
}

void submit_points(int points){
	game.scores[game.current_player] -= points;

	for(int i=0; i < 100; i++){
		if(game.throws[game.current_player][i] == -1){
			game.throws[game.current_player][i] = points;
			break;
		}
	}

	next_player();
}

void revert(){
	previous_player();

	int last_value;
	for(int i = 0; i < 100; i++){
		if(game.throws[game.current_player][i] == -1 && i>0 ){
			last_value = game.throws[game.current_player][i-1];
			game.throws[game.current_player][i-1] == -1;
			break;
		}
	}

	game.scores[game.current_player] += last_value;
	
}
