#include <gtk-3.0/gtk/gtk.h>
#include "game_state.h"
#include <stdlib.h>
#include <stdbool.h>

GameState game;

void init(){

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 3; j++){
			game.throws[j][i] = -1;
		}
	}

	for(int i=0; i < 3; i++){
		game.scores[i] = 501;
	}

	game.current_player = 0;
	
}

int modulo(int a, int b){
	int result = a % b;
	return result < 0 ? result + b : result;
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
	game.current_player = modulo(game.current_player + 1, game.num_players);
}

void previous_player(){
	game.current_player = modulo(game.current_player - 1, game.num_players);
	
}

void remove_player(int player_id){


	for(int i = player_id; i < game.num_players; i++){

		if(player_id != 3){
			*game.player_names[i] = '\0';
			strcpy(game.player_names[i], game.player_names[i+1]);
			*game.player_names[i+1] = '\0';
		}
		else if(player_id == 3){
			*game.player_names[player_id] = '\0';
		}
	}
	game.num_players--;
}

void submit_points(int points){
	game.scores[game.current_player] -= points;

	if(game.scores[game.current_player] <= 0){
		init();
	}

	for(int i=0; i < 100; i++){
		if(game.throws[game.current_player][i] == -1){
			game.throws[game.current_player][i] = points;
			break;
		}
	}

	next_player();
}

void revert(){
	if(game.throws[0][0] == -1){
		return; 
	}
	previous_player();

	int last_value;
	for(int i = 0; i < 100; i++){
		if(game.throws[game.current_player][i] == -1 && i>0 ){
			last_value = game.throws[game.current_player][i-1];
			game.throws[game.current_player][i-1] = -1;
			break;
		}
	}

	game.scores[game.current_player] += last_value;
	
}

char* get_last_value(int player){

	int last_value = 0;
	for(int i=1; i<100; i++){
		if(game.throws[player][i] == -1){
			last_value = game.throws[player][i-1];
			break;
		}
	}

	if(last_value == -1){
		return "";
	}

	int len = snprintf(NULL, 0, "%d", last_value);
	char *points_as_string = malloc(len + 1);
	snprintf(points_as_string, len+1, "%d", last_value);

	return points_as_string;

}
