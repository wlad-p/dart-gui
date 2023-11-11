#include <gtk-3.0/gtk/gtk.h>
#include "page_start.h"
#include "page_menu.h"

int main(int argc, char **argv){

	gtk_init (&argc, &argv);
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 400,800);

	//Stack
	GtkWidget *stack = gtk_stack_new();
	gtk_container_add(GTK_CONTAINER(window), stack);

	// Pages
	GtkWidget *page_start = create_page_start(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page_start, "page_start");
	GtkWidget *page_menu = create_page_menu(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page_menu, "page_menu");


	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
