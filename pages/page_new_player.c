// Page New Player
#include <gtk-3.0/gtk/gtk.h>
#include "page_new_player.h"
#include "../game_state.h"
#include "page_menu.h"
#include <string.h>
#include <stdlib.h>

GtkWidget *player_name;

static void press_key(GtkWidget* widget, gpointer data){

	const char *text = gtk_entry_get_text(GTK_ENTRY(player_name));
	const char *letter = (char *)data;

	//Append string
	char *new_text = (char *)malloc(strlen(text) + strlen(letter) +1 + 1);
	strcpy(new_text, text);
	strcat(new_text, letter);
	
	gtk_entry_set_text(GTK_ENTRY(player_name), new_text);
	free(new_text);
}

static void open_page_menu(GtkWidget* widget, gpointer data){

	GtkStack *stack = GTK_STACK(data);
	gtk_stack_set_visible_child_name(stack, "page_menu");

}

static void delete_character(GtkWidget *widget, gpointer data){
	const char *text = gtk_entry_get_text(GTK_ENTRY(player_name));
	int len = strlen(text);

	if(len > 0){
		char *new_text = (char *)malloc(len + 1);
		strcpy(new_text, text);
		new_text[len-1] = '\0';
		gtk_entry_set_text(GTK_ENTRY(player_name), new_text);
		free(new_text);
	}
}

static void confirm(GtkWidget *widget, gpointer data){

	const char *text = gtk_entry_get_text(GTK_ENTRY(player_name));
	add_player(text);
	gtk_entry_set_text(GTK_ENTRY(player_name), "");
	
	GtkStack *stack = GTK_STACK(data);
	reload_menu();
    gtk_stack_set_visible_child_name(stack, "page_menu");
}
static void cancel(GtkWidget *widget, gpointer data){
	
	GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page_menu");
}

GtkWidget *create_page_new_player(GtkWidget *window, GtkWidget *stack) {

	GtkWidget* main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);

	GtkStyleContext *new_player_context = gtk_widget_get_style_context(main_box);
	gtk_style_context_add_class(new_player_context, "page_new_player");

	GtkWidget *box_top_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *btn_back = gtk_button_new_with_label("<");
	g_signal_connect(btn_back, "clicked", G_CALLBACK(open_page_menu),stack);

	GtkWidget *label_title = gtk_label_new("Darts");

	GtkStyleContext *box_top_bar_context = gtk_widget_get_style_context(box_top_bar);
	gtk_style_context_add_class(box_top_bar_context, "box_top_bar");

	gtk_box_pack_start(GTK_BOX(box_top_bar),btn_back, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_top_bar),label_title, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_box),box_top_bar, FALSE, FALSE, 0);


	GtkWidget *label = gtk_label_new("Add a new player");
	GtkWidget *photo = gtk_image_new_from_file("images/default.png");

	//Buttons
	GtkWidget *buttons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget *btn_confirm = gtk_button_new_with_label("Confirm");
	g_signal_connect(btn_confirm, "clicked", G_CALLBACK(confirm),stack);
	GtkWidget *btn_cancel = gtk_button_new_with_label("Cancel");
	g_signal_connect(btn_cancel, "clicked", G_CALLBACK(cancel), stack);

	gtk_box_pack_start(GTK_BOX(buttons),btn_confirm, TRUE, TRUE, 50);
	gtk_box_pack_start(GTK_BOX(buttons),btn_cancel, TRUE, TRUE, 50);
	gtk_box_set_homogeneous(GTK_BOX(buttons), TRUE);


	// ########### Keyboard ###################

	player_name = gtk_entry_new();
	GtkWidget* row1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	
	gtk_box_set_homogeneous(GTK_BOX(row1), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row2), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row3), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row4), TRUE);


	// Row 1
	GtkWidget* a = gtk_button_new_with_label("A");
	g_signal_connect(a, "clicked", G_CALLBACK(press_key), "A");
	gtk_box_pack_start(GTK_BOX(row1), a, TRUE, TRUE, 0);

	GtkWidget* b = gtk_button_new_with_label("B");
	g_signal_connect(b, "clicked", G_CALLBACK(press_key), "B");
	gtk_box_pack_start(GTK_BOX(row1), b, TRUE, TRUE, 0);

	GtkWidget* c = gtk_button_new_with_label("C");
	g_signal_connect(c, "clicked", G_CALLBACK(press_key), "C");
	gtk_box_pack_start(GTK_BOX(row1), c, TRUE, TRUE, 0);

	GtkWidget* d = gtk_button_new_with_label("D");
	g_signal_connect(d, "clicked", G_CALLBACK(press_key), "D");
	gtk_box_pack_start(GTK_BOX(row1), d, TRUE, TRUE, 0);

	GtkWidget* e = gtk_button_new_with_label("E");
	g_signal_connect(e, "clicked", G_CALLBACK(press_key), "E");
	gtk_box_pack_start(GTK_BOX(row1), e, TRUE, TRUE, 0);

	GtkWidget* f = gtk_button_new_with_label("F");
	g_signal_connect(f, "clicked", G_CALLBACK(press_key), "F");
	gtk_box_pack_start(GTK_BOX(row1), f, TRUE, TRUE, 0);

	GtkWidget* g = gtk_button_new_with_label("G");
	g_signal_connect(g, "clicked", G_CALLBACK(press_key), "G");
	gtk_box_pack_start(GTK_BOX(row1), g, TRUE, TRUE, 0);

	// Row 2
	GtkWidget* h = gtk_button_new_with_label("H");
	g_signal_connect(h, "clicked", G_CALLBACK(press_key), "H");
	gtk_box_pack_start(GTK_BOX(row2), h, TRUE, TRUE, 0);

	GtkWidget* i = gtk_button_new_with_label("I");
	g_signal_connect(i, "clicked", G_CALLBACK(press_key), "I");
	gtk_box_pack_start(GTK_BOX(row2), i, TRUE, TRUE, 0);

	GtkWidget* j = gtk_button_new_with_label("J");
	g_signal_connect(j, "clicked", G_CALLBACK(press_key), "J");
	gtk_box_pack_start(GTK_BOX(row2), j, TRUE, TRUE, 0);

	GtkWidget* k = gtk_button_new_with_label("K");
	g_signal_connect(k, "clicked", G_CALLBACK(press_key), "K");
	gtk_box_pack_start(GTK_BOX(row2), k, TRUE, TRUE, 0);

	GtkWidget* l = gtk_button_new_with_label("L");
	g_signal_connect(l, "clicked", G_CALLBACK(press_key), "L");
	gtk_box_pack_start(GTK_BOX(row2), l, TRUE, TRUE, 0);

	GtkWidget* m = gtk_button_new_with_label("M");
	g_signal_connect(m, "clicked", G_CALLBACK(press_key), "M");
	gtk_box_pack_start(GTK_BOX(row2), m, TRUE, TRUE, 0);

	GtkWidget* n = gtk_button_new_with_label("N");
	g_signal_connect(n, "clicked", G_CALLBACK(press_key), "N");
	gtk_box_pack_start(GTK_BOX(row2), n, TRUE, TRUE, 0);

	// Row3
	GtkWidget* o = gtk_button_new_with_label("O");
	g_signal_connect(o, "clicked", G_CALLBACK(press_key), "O");
	gtk_box_pack_start(GTK_BOX(row3), o, TRUE, TRUE, 0);

	GtkWidget* p = gtk_button_new_with_label("P");
	g_signal_connect(p, "clicked", G_CALLBACK(press_key), "P");
	gtk_box_pack_start(GTK_BOX(row3), p, TRUE, TRUE, 0);

	GtkWidget* q = gtk_button_new_with_label("Q");
	g_signal_connect(q, "clicked", G_CALLBACK(press_key), "Q");
	gtk_box_pack_start(GTK_BOX(row3), q, TRUE, TRUE, 0);

	GtkWidget* r = gtk_button_new_with_label("R");
	g_signal_connect(r, "clicked", G_CALLBACK(press_key), "R");
	gtk_box_pack_start(GTK_BOX(row3), r, TRUE, TRUE, 0);

	GtkWidget* s = gtk_button_new_with_label("S");
	g_signal_connect(s, "clicked", G_CALLBACK(press_key), "S");
	gtk_box_pack_start(GTK_BOX(row3), s, TRUE, TRUE, 0);

	GtkWidget* t = gtk_button_new_with_label("T");
	g_signal_connect(t, "clicked", G_CALLBACK(press_key), "T");
	gtk_box_pack_start(GTK_BOX(row3), t, TRUE, TRUE, 0);

	GtkWidget* u = gtk_button_new_with_label("U");
	g_signal_connect(u, "clicked", G_CALLBACK(press_key), "U");
	gtk_box_pack_start(GTK_BOX(row3), u, TRUE, TRUE, 0);

	// Row4
	GtkWidget* v = gtk_button_new_with_label("V");
	g_signal_connect(v, "clicked", G_CALLBACK(press_key), "V");
	gtk_box_pack_start(GTK_BOX(row4), v, TRUE, TRUE, 0);

	GtkWidget* w = gtk_button_new_with_label("W");
	g_signal_connect(w, "clicked", G_CALLBACK(press_key), "W");
	gtk_box_pack_start(GTK_BOX(row4), w, TRUE, TRUE, 0);

	GtkWidget* x = gtk_button_new_with_label("X");
	g_signal_connect(x, "clicked", G_CALLBACK(press_key), "X");
	gtk_box_pack_start(GTK_BOX(row4), x, TRUE, TRUE, 0);

	GtkWidget* y = gtk_button_new_with_label("Y");
	g_signal_connect(y, "clicked", G_CALLBACK(press_key), "Y");
	gtk_box_pack_start(GTK_BOX(row4), y, TRUE, TRUE, 0);

	GtkWidget* z = gtk_button_new_with_label("Z");
	g_signal_connect(z, "clicked", G_CALLBACK(press_key), "Z");
	gtk_box_pack_start(GTK_BOX(row4), z, TRUE, TRUE, 0);

	GtkWidget* del = gtk_button_new_with_label("<x|");
	g_signal_connect(del, "clicked", G_CALLBACK(delete_character),stack);
	gtk_box_pack_start(GTK_BOX(row4), del, TRUE, TRUE, 0);

	GtkWidget* space = gtk_button_new_with_label(" ");
	g_signal_connect(space, "clicked", G_CALLBACK(press_key), " ");
	gtk_box_pack_start(GTK_BOX(row5), space, TRUE, TRUE, 0);

	gtk_widget_set_size_request(row1, 100, 80);
	gtk_widget_set_size_request(row2, 100, 80);
	gtk_widget_set_size_request(row3, 100, 80);
	gtk_widget_set_size_request(row4, 100, 80);
	gtk_widget_set_size_request(row5, 100, 80);

	gtk_widget_set_hexpand(row1, TRUE);
	gtk_widget_set_hexpand(row2, TRUE);
	gtk_widget_set_hexpand(row3, TRUE);
	gtk_widget_set_hexpand(row4, TRUE);
	gtk_widget_set_hexpand(row5, TRUE);

	GtkWidget *keyboard = gtk_grid_new();

	GtkStyleContext *keyboard_context = gtk_widget_get_style_context(keyboard);
	gtk_style_context_add_class(keyboard_context, "keyboard");

	gtk_grid_attach(GTK_GRID(keyboard), row1, 0,0,1,1);
	gtk_grid_attach(GTK_GRID(keyboard), row2, 0,1,1,1);	
	gtk_grid_attach(GTK_GRID(keyboard), row3, 0,2,1,1);
	gtk_grid_attach(GTK_GRID(keyboard), row4, 0,3,1,1);
	gtk_grid_attach(GTK_GRID(keyboard), row5, 0,4,1,1);

	

	gtk_box_pack_start(GTK_BOX(main_box),label, TRUE, TRUE, 50);
	gtk_box_pack_start(GTK_BOX(main_box),photo, TRUE, TRUE, 50);	
	gtk_box_pack_start(GTK_BOX(main_box),player_name, TRUE, TRUE, 50);	
	gtk_box_pack_start(GTK_BOX(main_box),buttons, TRUE, TRUE, 50);
	gtk_box_pack_end(GTK_BOX(main_box),keyboard, FALSE, FALSE, 0);
	
		
	return main_box;
}
