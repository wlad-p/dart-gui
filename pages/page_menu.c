
// Page Menu
#include <gtk-3.0/gtk/gtk.h>
#include "page_menu.h"
#include "../game_state.h"
#include "page_game.h"
#include <stdlib.h>
#include "unistd.h"

GtkWidget *box;
static GtkWidget *box_players_overview;


static void start_game(GtkWidget *widget, gpointer data) {

	reload_game();
    GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page_game");
}

static void open_page_select_player(GtkWidget* widget, gpointer data){
	if(game.num_players < 3){
		GtkStack *stack = GTK_STACK(data);
    	gtk_stack_set_visible_child_name(stack, "page_select_player");
	}
	else{
	//	g_print("More than 4 Players");
	}

}

static void open_page_start(GtkWidget* widget, gpointer data){

	GtkStack *stack = GTK_STACK(data);
	gtk_stack_set_visible_child_name(stack, "page_start");

}


void delete_player(GtkWidget* widget, gpointer data){

	char *player_id_string = (char *)data;
	int player_id = atoi(player_id_string);
	g_print("MENU ID: %d", player_id);
	remove_player(player_id);
	reload_menu();
}

void reload_menu(){

	gtk_widget_destroy(box_players_overview);
	box_players_overview = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

	gtk_widget_set_size_request(box_players_overview, 100, 500);
	gtk_widget_set_vexpand(box_players_overview, TRUE);

	GtkStyleContext *box_players_overview_context = gtk_widget_get_style_context(box_players_overview);
	gtk_style_context_add_class(box_players_overview_context, "box_players_overview");


	for (int i=0;i<game.num_players;i++){

		GtkWidget *box_player = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
		GtkStyleContext *box_player_context = gtk_widget_get_style_context(box_player);
		gtk_style_context_add_class(box_player_context, "box_player");

		
		char image_file[100] = "images/";
        strcat(image_file, game.player_names[i]);
        strcat(image_file, ".png");

		GtkWidget *photo;

		if (access(image_file, F_OK) == 0) {
			photo = gtk_image_new_from_file(image_file);
		} else {
			photo = gtk_image_new_from_file("images/default.png");
		}

		GtkWidget *name = gtk_label_new(game.player_names[i]);
		
		GtkWidget *btn_delete_player = gtk_button_new_with_label("X");
		char *player_id = (char *)malloc(sizeof(char) * 2);
		sprintf(player_id, "%d", i);
		g_signal_connect(btn_delete_player, "clicked", G_CALLBACK(delete_player),player_id);

		gtk_box_pack_start(GTK_BOX(box_player),photo, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(box_player),name, FALSE, FALSE, 10);
		gtk_box_pack_end(GTK_BOX(box_player),btn_delete_player, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(box_players_overview),box_player, FALSE, FALSE, 0);
	}

	gtk_box_pack_start(GTK_BOX(box),box_players_overview, FALSE, FALSE, 50);
	gtk_widget_show_all(box);
}

GtkWidget *create_page_menu(GtkWidget *window, GtkWidget *stack) {

	init();
	

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);

	GtkStyleContext *menu_context = gtk_widget_get_style_context(box);
	gtk_style_context_add_class(menu_context, "page_menu");

	GtkWidget *box_top_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *btn_back = gtk_button_new_with_label("<");
	g_signal_connect(btn_back, "clicked", G_CALLBACK(open_page_start),stack);

	GtkWidget *label_title = gtk_label_new("Darts");

	GtkStyleContext *box_top_bar_context = gtk_widget_get_style_context(box_top_bar);
	gtk_style_context_add_class(box_top_bar_context, "box_top_bar");

	gtk_box_pack_start(GTK_BOX(box_top_bar),btn_back, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_top_bar),label_title, FALSE, FALSE, 0);

	GtkWidget* label = gtk_label_new("Select Players");

	GtkWidget* btn_add_player = gtk_button_new_with_label("Add Player");
	g_signal_connect(btn_add_player, "clicked", G_CALLBACK(open_page_select_player),stack);
	GtkStyleContext *btn_add_player_context = gtk_widget_get_style_context(btn_add_player);
	gtk_style_context_add_class(btn_add_player_context, "btn_add_player");

	GtkWidget* btn_start_game = gtk_button_new_with_label("Start Game");
	g_signal_connect(btn_start_game, "clicked", G_CALLBACK(start_game),stack);
	GtkStyleContext *btn_start_game_context = gtk_widget_get_style_context(btn_start_game);
	gtk_style_context_add_class(btn_start_game_context, "btn_start_game");

	
	gtk_box_pack_start(GTK_BOX(box), box_top_bar, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box),label, FALSE, FALSE, 50);
	gtk_box_pack_end(GTK_BOX(box), btn_start_game, FALSE, FALSE, 50);
	gtk_box_pack_end(GTK_BOX(box), btn_add_player, FALSE, FALSE, 0);

	box_players_overview = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
	gtk_widget_set_size_request(box_players_overview, 100, 500);
	gtk_widget_set_vexpand(box_players_overview, TRUE);

	GtkStyleContext *box_players_overview_context = gtk_widget_get_style_context(box_players_overview);
	gtk_style_context_add_class(box_players_overview_context, "box_players_overview");
	gtk_box_pack_start(GTK_BOX(box),box_players_overview, FALSE, FALSE, 50);


	return box;
}
