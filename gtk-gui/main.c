#include <gtk-3.0/gtk/gtk.h>
#include "stack_page1.h"
#include "stack_page2.h"

int main(int argc, char **argv){

	gtk_init (&argc, &argv);
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 400,800);

	//Stack
	GtkWidget *stack = gtk_stack_new();
	gtk_container_add(GTK_CONTAINER(window), stack);

	GtkWidget *page1 = create_stack_page1(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page1, "page1");
	GtkWidget *page2 = create_stack_page2(window, stack);
	gtk_stack_add_named(GTK_STACK(stack), page1, "page2");



	
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
