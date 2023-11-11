// Page New Player
#include <gtk-3.0/gtk/gtk.h>
#include "page_new_player.h"

typedef struct {
	GtkWidget *entry;
	char *message;
} KeyInput;


static void press_q(GtkWidget* widget, gpointer data){

	KeyInput *key = (KeyInput *)data;
	gtk_entry_set_text(GTK_ENTRY(key->entry), key->message);
}

GtkWidget *create_page_new_player(GtkWidget *window, GtkWidget *stack) {

	GtkWidget *grid = gtk_grid_new();

	GtkWidget *text_input = gtk_entry_new();
	
	
	GtkWidget* row1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);

	// Row 1

	KeyInput *data;
	data->entry = text_input;
	data->message = "alo";
	
	GtkWidget* q = gtk_button_new_with_label("Q");
	g_signal_connect(q, "clicked", G_CALLBACK(press_q), data);
	gtk_box_pack_start(GTK_BOX(row1), q, FALSE, FALSE, 50);

	/*
	GtkWidget* w = gtk_button_new_with_label("W");
	g_signal_connect(w, "clicked", G_CALLBACK(press_w),stack);
	gtk_box_pack_start(GTK_BOX(row1), w, FALSE, FALSE, 50);

	GtkWidget* e = gtk_button_new_with_label("E");
	g_signal_connect(e, "clicked", G_CALLBACK(press_e),stack);
	gtk_box_pack_start(GTK_BOX(row1), e, FALSE, FALSE, 50);

	GtkWidget* r = gtk_button_new_with_label("R");
	g_signal_connect(r, "clicked", G_CALLBACK(press_r),stack);
	gtk_box_pack_start(GTK_BOX(row1), r, FALSE, FALSE, 50);

	GtkWidget* t = gtk_button_new_with_label("t");
	g_signal_connect(t, "clicked", G_CALLBACK(press_t),stack);
	gtk_box_pack_start(GTK_BOX(row1), t, FALSE, FALSE, 50);

	GtkWidget* z = gtk_button_new_with_label("z");
	g_signal_connect(z, "clicked", G_CALLBACK(press_z),stack);
	gtk_box_pack_start(GTK_BOX(row1), z, FALSE, FALSE, 50);

	// Row 2

	GtkWidget* a = gtk_button_new_with_label("A");
	g_signal_connect(a, "clicked", G_CALLBACK(press_a),stack);
	gtk_box_pack_start(GTK_BOX(row2), a, FALSE, FALSE, 50);

	GtkWidget* s = gtk_button_new_with_label("s");
	g_signal_connect(s, "clicked", G_CALLBACK(press_s),stack);
	gtk_box_pack_start(GTK_BOX(row2), s, FALSE, FALSE, 50);

	GtkWidget* d = gtk_button_new_with_label("d");
	g_signal_connect(d, "clicked", G_CALLBACK(press_d),stack);
	gtk_box_pack_start(GTK_BOX(row2), d, FALSE, FALSE, 50);

	GtkWidget* y = gtk_button_new_with_label("Y");
	g_signal_connect(y, "clicked", G_CALLBACK(press_y),stack);
	gtk_box_pack_start(GTK_BOX(row3), y, FALSE, FALSE, 50);

	GtkWidget* x = gtk_button_new_with_label("X");
	g_signal_connect(x, "clicked", G_CALLBACK(press_x),stack);
	gtk_box_pack_start(GTK_BOX(row3), x, FALSE, FALSE, 50);

	GtkWidget* c = gtk_button_new_with_label("c");
	g_signal_connect(c, "clicked", G_CALLBACK(press_c),stack);
	gtk_box_pack_start(GTK_BOX(row3), c, FALSE, FALSE, 50);

	GtkWidget* v = gtk_button_new_with_label("v");
	g_signal_connect(v, "clicked", G_CALLBACK(press_v),stack);
	gtk_box_pack_start(GTK_BOX(row3), v, FALSE, FALSE, 50); */

	
	gtk_grid_attach(GTK_GRID(grid), row1, 0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid), row2, 0,1,1,1);	
	gtk_grid_attach(GTK_GRID(grid), row3, 0,2,1,1);	
	gtk_grid_attach(GTK_GRID(grid),text_input, 0,3,1,1);

	//gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
	//gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
	

	return grid;
}