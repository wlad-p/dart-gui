#ifndef GAME_STATE_H
#define GAME_STATE_H



typedef struct {
	int num_players;
	char player_names[4][30];
	int scores[4];
	int current_player;
} GameState;

extern GameState game;

void print_current_player();
void init();
void add_player(const char *name);

#endif 


