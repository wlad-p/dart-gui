#include <gtk-3.0/gtk/gtk.h>


static void button_clicked(GtkWidget* widget, gpointer data){
	g_print("Button is pressed\n");	
}

int main(int argc, char **argv){

	gtk_init (&argc, &argv);
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 700,500);

	GtkWidget *btn = gtk_button_new_with_label("Click here");
	g_signal_connect(btn, "clicked", G_CALLBACK(button_clicked),NULL);
	gtk_container_add(GTK_CONTAINER(window),btn);
	
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show_all(window);
		
	gtk_main();

	return 0;
}
