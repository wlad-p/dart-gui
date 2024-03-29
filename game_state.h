#ifndef GAME_STATE_H
#define GAME_STATE_H


typedef struct node {
	int num_players;
	char player_names[3][30];
	int scores[3];
	int throws[3][100];
	int current_player;
} GameState;

extern GameState game;

void print_current_player();
void init();
void add_player(const char *name);
void next_player();
void remove_player(int player_id);
void revert();
void submit_points(int points);
char* get_last_value(int player);


#endif 


