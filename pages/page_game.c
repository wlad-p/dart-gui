#include <gtk-3.0/gtk/gtk.h>
#include "../game_state.h"
#include <stdlib.h>

GtkWidget *entry_score;
GtkWidget *box_score_cards_overview;
GtkWidget *box_main;

static void press_key(GtkWidget* widget, gpointer data){

	const char *text = gtk_entry_get_text(GTK_ENTRY(entry_score));
	const char *letter = (char *)data;

	//Append string
	char *new_text = (char *)malloc(strlen(text) + strlen(letter) +1 + 1);
	strcpy(new_text, text);
	strcat(new_text, letter);
	
	gtk_entry_set_text(GTK_ENTRY(entry_score), new_text);
	free(new_text);
}

static void open_page_menu(GtkWidget* widget, gpointer data){

	GtkStack *stack = GTK_STACK(data);
	gtk_stack_set_visible_child_name(stack, "page_menu");

}

void reload_game(){
	
	gtk_widget_destroy(box_score_cards_overview);
	box_score_cards_overview = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
	

	for (int i=0;i<game.num_players;i++){

		GtkWidget *box_score_card = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
		GtkStyleContext *box_score_card_context = gtk_widget_get_style_context(box_score_card);
		gtk_style_context_add_class(box_score_card_context, "box_score_card");
		gtk_widget_set_size_request(GTK_WIDGET(box_score_card), 100, 150);

		GtkWidget *label_name = gtk_label_new(game.player_names[i]);

		//points to string
		int len = snprintf(NULL, 0, "%d", game.scores[i]);
		char *points_as_string = malloc(len + 1);
		snprintf(points_as_string, len+1, "%d", game.scores[i]);
		
		GtkWidget *label_points = gtk_label_new(points_as_string);

		char image_file[100] = "images/";
        strcat(image_file, game.player_names[i]);
        strcat(image_file, ".jpg");

		GtkWidget *photo;

		if (access(image_file, F_OK) == 0) {
			photo = gtk_image_new_from_file(image_file);
		} else {
			photo = gtk_image_new_from_file("images/default.jpg");
		}

		GtkWidget *player_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
		gtk_box_pack_start(GTK_BOX(player_container), photo, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(player_container), label_name, FALSE, FALSE, 10);
		
		
		gtk_box_pack_start(GTK_BOX(box_score_card),player_container, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(box_score_card),label_points, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(box_score_cards_overview),box_score_card, FALSE, FALSE, 0);

		gtk_box_set_homogeneous(GTK_BOX(box_score_card), TRUE);
		free(points_as_string);
		
	}

	gtk_box_pack_start(GTK_BOX(box_main),box_score_cards_overview, TRUE, TRUE, 50);
	gtk_widget_show_all(box_main);
}


static void press_delete(GtkWidget *widget, gpointer data){
	const char *text = gtk_entry_get_text(GTK_ENTRY(entry_score));
	int len = strlen(text);

	if(len > 0){
		char *new_text = (char *)malloc(len + 1);
		strcpy(new_text, text);
		new_text[len-1] = '\0';
		gtk_entry_set_text(GTK_ENTRY(entry_score), new_text);
		free(new_text);
	}
}

static void press_enter(GtkWidget *widget, gpointer data){
	const char *text = gtk_entry_get_text(GTK_ENTRY(entry_score));
	int points_entered = atoi(text);

	if(points_entered >= 0 && points_entered <= 180){
		submit_points(points_entered);
	}
	gtk_entry_set_text(GTK_ENTRY(entry_score), "");
	reload_game();
}

static void press_revert(GtkWidget *widget, gpointer data){

	revert();
	
	reload_game();
}

static void press_no_score(GtkWidget *widget, gpointer data){
	next_player();
}



GtkWidget *create_page_game(GtkWidget *window, GtkWidget *stack) {

	box_main = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);

	GtkStyleContext *game_context = gtk_widget_get_style_context(box_main);
	gtk_style_context_add_class(game_context, "page_game");

	GtkWidget *box_top_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *btn_back = gtk_button_new_with_label("<");
	g_signal_connect(btn_back, "clicked", G_CALLBACK(open_page_menu),stack);

	GtkWidget *label_title = gtk_label_new("Darts");

	GtkStyleContext *box_top_bar_context = gtk_widget_get_style_context(box_top_bar);
	gtk_style_context_add_class(box_top_bar_context, "box_top_bar");

	gtk_box_pack_start(GTK_BOX(box_top_bar),btn_back, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_top_bar),label_title, FALSE, FALSE, 0);

	
	// ########### Keyboard ###################

	entry_score = gtk_entry_new();
	
	GtkWidget* row0 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);


	gtk_box_set_homogeneous(GTK_BOX(row0), FALSE);
	gtk_box_set_homogeneous(GTK_BOX(row1), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row2), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row3), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row4), TRUE);

	// Row 0
	GtkWidget* btn_revert = gtk_button_new_with_label("<-");
	g_signal_connect(btn_revert, "clicked", G_CALLBACK(press_revert), NULL);
	gtk_box_pack_start(GTK_BOX(row0), btn_revert, TRUE, TRUE, 0);

	entry_score = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(row0), entry_score, TRUE, TRUE, 0);

	GtkWidget* btn_delete = gtk_button_new_with_label("<x|");
	g_signal_connect(btn_delete, "clicked", G_CALLBACK(press_delete), NULL);
	gtk_box_pack_start(GTK_BOX(row0), btn_delete, TRUE, TRUE, 0);

	// Row 1
	GtkWidget* btn_one = gtk_button_new_with_label("1");
	g_signal_connect(btn_one, "clicked", G_CALLBACK(press_key), "1");
	gtk_box_pack_start(GTK_BOX(row1), btn_one, TRUE, TRUE, 0);
	//gtk_widget_set_hexpand(btn_one, TRUE);

	GtkWidget* btn_two = gtk_button_new_with_label("2");
	g_signal_connect(btn_two, "clicked", G_CALLBACK(press_key), "2");
	gtk_box_pack_start(GTK_BOX(row1), btn_two, TRUE, TRUE, 0);
	//gtk_widget_set_hexpand(btn_two, TRUE);

	GtkWidget* btn_three = gtk_button_new_with_label("3");
	g_signal_connect(btn_three, "clicked", G_CALLBACK(press_key), "3");
	gtk_box_pack_start(GTK_BOX(row1), btn_three, TRUE, TRUE, 0);
	//gtk_widget_set_hexpand(btn_three, TRUE);	
	//Row 2
	GtkWidget* btn_four = gtk_button_new_with_label("4");
	g_signal_connect(btn_four, "clicked", G_CALLBACK(press_key), "4");
	gtk_box_pack_start(GTK_BOX(row2), btn_four, TRUE, TRUE, 0);

	GtkWidget* btn_five = gtk_button_new_with_label("5");
	g_signal_connect(btn_five, "clicked", G_CALLBACK(press_key), "5");
	gtk_box_pack_start(GTK_BOX(row2), btn_five, TRUE, TRUE, 0);

	GtkWidget* btn_six = gtk_button_new_with_label("6");
	g_signal_connect(btn_six, "clicked", G_CALLBACK(press_key), "6");
	gtk_box_pack_start(GTK_BOX(row2), btn_six, TRUE, TRUE, 0);


	//Row3
	GtkWidget* btn_seven = gtk_button_new_with_label("7");
	g_signal_connect(btn_seven, "clicked", G_CALLBACK(press_key), "7");
	gtk_box_pack_start(GTK_BOX(row3), btn_seven, TRUE, TRUE, 0);

	GtkWidget* btn_eight = gtk_button_new_with_label("8");
	g_signal_connect(btn_eight, "clicked", G_CALLBACK(press_key), "8");
	gtk_box_pack_start(GTK_BOX(row3), btn_eight, TRUE, TRUE, 0);

	GtkWidget* btn_nine = gtk_button_new_with_label("9");
	g_signal_connect(btn_nine, "clicked", G_CALLBACK(press_key), "9");
	gtk_box_pack_start(GTK_BOX(row3), btn_nine, TRUE, TRUE, 0);

	//Row4
	GtkWidget* btn_no_score = gtk_button_new_with_label("X");
	g_signal_connect(btn_no_score, "clicked", G_CALLBACK(press_no_score), NULL);
	gtk_box_pack_start(GTK_BOX(row4), btn_no_score, TRUE, TRUE, 0);

	GtkWidget* btn_zero = gtk_button_new_with_label("0");
	g_signal_connect(btn_zero, "clicked", G_CALLBACK(press_key), "0");
	gtk_box_pack_start(GTK_BOX(row4), btn_zero, TRUE, TRUE, 0);

	GtkWidget* btn_enter = gtk_button_new_with_label("OK");
	g_signal_connect(btn_enter, "clicked", G_CALLBACK(press_enter), NULL);
	gtk_box_pack_start(GTK_BOX(row4), btn_enter, TRUE, TRUE, 0);

	gtk_widget_set_size_request(row0, 180, 55);
	gtk_widget_set_size_request(row1, 180,100);
	gtk_widget_set_size_request(row2, 180, 100);
	gtk_widget_set_size_request(row3, 180, 100);
	gtk_widget_set_size_request(row4, 180, 100);

	gtk_widget_set_hexpand(row0, TRUE);
	gtk_widget_set_hexpand(row1, TRUE);
	gtk_widget_set_hexpand(row2, TRUE);
	gtk_widget_set_hexpand(row3, TRUE);
	gtk_widget_set_hexpand(row4, TRUE);


	GtkWidget *keyboard = gtk_grid_new();
	
	gtk_grid_attach(GTK_GRID(keyboard), row0, 0,0,1,1);	
	gtk_grid_attach(GTK_GRID(keyboard), row1, 0,1,1,1);
	gtk_grid_attach(GTK_GRID(keyboard), row2, 0,2,1,1);	
	gtk_grid_attach(GTK_GRID(keyboard), row3, 0,3,1,1);
	gtk_grid_attach(GTK_GRID(keyboard), row4, 0,4,1,1);


	gtk_box_pack_start(GTK_BOX(box_main), box_top_bar, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(box_main),keyboard, TRUE, TRUE, 0);

	gtk_widget_set_vexpand(box_main, TRUE);
	
		
	return box_main;
}
