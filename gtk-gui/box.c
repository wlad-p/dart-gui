#include <gtk-3.0/gtk/gtk.h>


static void start_game(GtkWidget* widget, gpointer data){
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






	

	GtkWidget *stack = gtk_stack_new();
	gtk_container_add(GTK_CONTAINER(window), stack);
	
	// Pages
	GtkWidget *page1 = gtk_label_new("Page1 content");
	gtk_stack_add_named(GTK_STACK(stack), page1, "page1");
	GtkWidget *page2 = gtk_label_new("Page2 content");
	gtk_stack_add_named(GTK_STACK(stack), page2, "page2");

	GtkWidget *buttonBox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);

	
	GtkWidget *btn_start = gtk_button_new_with_label("open page 2");
	g_signal_connect(btn_start, "clicked", G_CALLBACK(start_game),stack);
	gtk_container_add(GTK_CONTAINER(buttonBox), btn_start);

	gtk_container_add(GTK_CONTAINER(window), buttonBox);
	
	// FINAL
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show_all(window);	
	gtk_main();

	return 0;
}
