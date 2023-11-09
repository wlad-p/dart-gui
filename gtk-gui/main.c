#include <gtk-3.0/gtk/gtk.h>


static void button_clicked(GtkWidget* widget, gpointer data){
	g_print("Button is pressed\n");	
	GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page2");
}

int main(int argc, char **argv){

	//main
	gtk_init (&argc, &argv);
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 400,800);

	//Stack
	GtkWidget *stack = gtk_stack_new();
	gtk_container_add(GTK_CONTAINER(window), stack);

	//Grid
	GtkWidget *grid = gtk_grid_new();
	gtk_stack_add_named(GTK_STACK(stack), grid, "page1");

	GtkWidget *page2 = gtk_label_new("Page 2 Content");
    gtk_stack_add_named(GTK_STACK(stack), page2, "page2");

	GtkWidget *label1 = gtk_label_new("Wlarts");
	GtkWidget *label2 = gtk_label_new(" ");
	gtk_grid_attach(GTK_GRID(grid), label1, 0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid), label2, 0,1,1,1);	

	//Button
	GtkWidget *btn = gtk_button_new_with_label("Click here");
	g_signal_connect(btn, "clicked", G_CALLBACK(button_clicked),stack);
	gtk_container_add(GTK_CONTAINER(window),btn);
	gtk_grid_attach(GTK_GRID(grid), btn, 0, 2, 1,1);

	gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);	
	


	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show_all(window);	
	gtk_main();

	return 0;
}
