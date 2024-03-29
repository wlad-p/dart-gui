//Page Start
#include <gtk-3.0/gtk/gtk.h>
#include "page_start.h"

static void open_menu(GtkWidget *widget, gpointer data) {
    GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page_menu");
    
}

GtkWidget *create_page_start(GtkWidget *window, GtkWidget *stack){
	GtkWidget *grid = gtk_grid_new();

	GtkStyleContext *start_context = gtk_widget_get_style_context(grid);
	gtk_style_context_add_class(start_context, "page_start");

	GtkWidget *label1 = gtk_label_new("Darts");
	GtkWidget *img_dartboard = gtk_image_new_from_file("images/dartboard.png");
	gtk_widget_set_size_request(img_dartboard, 100, 100);
	gtk_grid_attach(GTK_GRID(grid), label1, 0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid), img_dartboard, 0,1,1,1);
	

	//Button
	GtkWidget *btn = gtk_button_new_with_label("Start");
	gtk_widget_set_name(GTK_WIDGET(btn), "btn");
	g_signal_connect(btn, "clicked", G_CALLBACK(open_menu),stack);
	//gtk_container_add(GTK_CONTAINER(window),btn);
	gtk_grid_attach(GTK_GRID(grid), btn, 0, 2, 1,1);

	gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);	

	return grid;
}
