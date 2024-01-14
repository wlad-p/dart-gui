#include <gtk-3.0/gtk/gtk.h>
#include "pages/page_start.h"
#include "pages/page_menu.h"
#include "pages/page_new_player.h"
#include "pages/page_game.h"

int main(int argc, char **argv){

	gtk_init (&argc, &argv);
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_default_size(GTK_WINDOW(window), 50,50);
	//gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_fullscreen(GTK_WINDOW(window));
	
	
	//Stack
	GtkWidget *stack = gtk_stack_new();
	gtk_container_add(GTK_CONTAINER(window), stack);

	// Pages
	GtkWidget *page_start = create_page_start(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page_start, "page_start");
	GtkWidget *page_menu = create_page_menu(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page_menu, "page_menu");
	GtkWidget* page_new_player = create_page_new_player(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page_new_player, "page_new_player");
	GtkWidget *page_game = create_page_game(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page_game, "page_game");

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
