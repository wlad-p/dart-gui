// Page Menu
#include <gtk-3.0/gtk/gtk.h>
#include "page_menu.h"

static void start_game(GtkWidget *widget, gpointer data) {
    g_print("Starting the game\n");
    GtkStack *stack = GTK_STACK(data);
    //gtk_stack_set_visible_child_name(stack, "page_menu");
}

static void add_player(GtkWidget* widget, gpointer data){
	g_print("Add Player\n");
	GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page_new_player");
}


GtkWidget *create_page_menu(GtkWidget *window, GtkWidget *stack) {

	GtkWidget *box;
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);

	GtkWidget* label = gtk_label_new("Select Player");
	gtk_box_pack_start(GTK_BOX(box),label, FALSE, FALSE, 50);

	GtkWidget* btn_add_player = gtk_button_new_with_label("Add Player");
	g_signal_connect(btn_add_player, "clicked", G_CALLBACK(add_player),stack);
	gtk_box_pack_start(GTK_BOX(box), btn_add_player, FALSE, FALSE, 50);

	GtkWidget* btn_start_game = gtk_button_new_with_label("Start Game");
	g_signal_connect(btn_start_game, "clicked", G_CALLBACK(start_game),stack);
	gtk_box_pack_start(GTK_BOX(box), btn_start_game, FALSE, FALSE, 50);

	return box;
}
