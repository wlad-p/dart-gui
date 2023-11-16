
// Page Menu
#include <gtk-3.0/gtk/gtk.h>
#include "page_menu.h"
#include "../game_state.h"
#include "page_game.h"
#include <stdlib.h>

GtkWidget *box;
static GtkWidget *box_players_overview;


static void start_game(GtkWidget *widget, gpointer data) {

	reload_game();
    GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page_game");
}

static void open_page_new_player(GtkWidget* widget, gpointer data){
	if(game.num_players < 4){
		GtkStack *stack = GTK_STACK(data);
    	gtk_stack_set_visible_child_name(stack, "page_new_player");
	}
	else{
		g_print("More than 4 Players");
	}

}

static void delete_player(GtkWidget* widget, gpointer data){

	g_print("delete player button\n");

	const char *player_id_string = (char *)data;
	g_print("data: %s", player_id_string);

//	g_print("player id: %ld\n", player_id);

	//reload_menu();
}

void reload_menu(){

	gtk_widget_destroy(box_players_overview);
	box_players_overview = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

	for (int i=0;i<game.num_players;i++){

		GtkWidget *box_player = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
		GtkWidget *name = gtk_label_new(game.player_names[i]);
		
		GtkWidget *btn_delete_player = gtk_button_new_with_label("delete");
		char *player_id = (char *)malloc(sizeof(char) * 2);
		sprintf(player_id, "%d", i);

		g_print("reload func, i: %d\n", i);
		g_print("reload func, player_id: %s\n", player_id);
		
		g_signal_connect(btn_delete_player, "clicked", G_CALLBACK(delete_player),player_id);

		gtk_box_pack_start(GTK_BOX(box_player),name, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(box_player),btn_delete_player, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(box_players_overview),box_player, FALSE, FALSE, 0);

		free(player_id);
		
	}

	gtk_box_pack_start(GTK_BOX(box),box_players_overview, FALSE, FALSE, 50);
	gtk_widget_show_all(box);
}

GtkWidget *create_page_menu(GtkWidget *window, GtkWidget *stack) {

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);

	GtkWidget* label = gtk_label_new("Select Player");

	GtkWidget* btn_add_player = gtk_button_new_with_label("Add Player");
	g_signal_connect(btn_add_player, "clicked", G_CALLBACK(open_page_new_player),stack);
	GtkWidget* btn_start_game = gtk_button_new_with_label("Start Game");
	g_signal_connect(btn_start_game, "clicked", G_CALLBACK(start_game),stack);

	
	gtk_box_pack_start(GTK_BOX(box),label, FALSE, FALSE, 50);
	gtk_box_pack_start(GTK_BOX(box), btn_add_player, FALSE, FALSE, 50);
	gtk_box_pack_start(GTK_BOX(box), btn_start_game, FALSE, FALSE, 50);

	return box;
}
