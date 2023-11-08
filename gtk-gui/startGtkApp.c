#include <gtk-3.0/gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data){
	//gtk code here
	GtkWidget *window;
	window = gtk_application_window_new(app);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv){
	GtkApplication *app;
	int ret;

	app = gtk_application_new("in.Wlarts", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	ret = g_application_run(G_APPLICATION(app), argc, argv);

	g_object_unref (app);

	return 0;
}
