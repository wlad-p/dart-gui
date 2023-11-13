//Page Start
#include <gtk-3.0/gtk/gtk.h>
#include "page_start.h"

static void open_menu(GtkWidget *widget, gpointer data) {
    GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page_menu");
    
}

GtkWidget *create_page_start(GtkWidget *window, GtkWidget *stack){
	GtkWidget *grid = gtk_grid_new();

	GtkWidget *label1 = gtk_label_new("Wlarts");
	GtkWidget *label2 = gtk_label_new(" ");
	gtk_grid_attach(GTK_GRID(grid), label1, 0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid), label2, 0,1,1,1);	

	//Button
	GtkWidget *btn = gtk_button_new_with_label("Start");
	g_signal_connect(btn, "clicked", G_CALLBACK(open_menu),stack);
	//gtk_container_add(GTK_CONTAINER(window),btn);
	gtk_grid_attach(GTK_GRID(grid), btn, 0, 2, 1,1);

	gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);	

	return grid;
}
