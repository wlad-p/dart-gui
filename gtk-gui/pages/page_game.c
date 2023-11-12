#include <gtk-3.0/gtk/gtk.h>

GtkWidget *entry_score;

static void press_key(GtkWidget* widget, gpointer data){

	const char *text = gtk_entry_get_text(GTK_ENTRY(entry_score));
	const char *letter = (char *)data;

	//Append string
	char *new_text = (char *)malloc(strlen(text) + strlen(letter) +1 + 1);
	strcpy(new_text, text);
	strcat(new_text, letter);
	
	gtk_entry_set_text(GTK_ENTRY(entry_score), new_text);
	free(new_text);
}

static void press_delete(GtkWidget *widget, gpointer data){
	const char *text = gtk_entry_get_text(GTK_ENTRY(entry_score));
	int len = strlen(text);

	if(len > 0){
		char *new_text = (char *)malloc(len + 1);
		strcpy(new_text, text);
		new_text[len-1] = '\0';
		gtk_entry_set_text(GTK_ENTRY(entry_score), new_text);
		free(new_text);
	}
}

static void press_enter(GtkWidget *widget, gpointer data){
	g_print("button confirm \n");
}

static void press_revert(GtkWidget *widget, gpointer data){
	g_print("button revert \n");
}

static void press_no_score(GtkWidget *widget, gpointer data){
	g_print("button no score \n");
}


GtkWidget *create_page_game(GtkWidget *window, GtkWidget *stack) {

	GtkWidget* main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);


	// ########### Keyboard ###################

	entry_score = gtk_entry_new();
	
	GtkWidget* row0 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	GtkWidget* row4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);

	gtk_box_set_homogeneous(GTK_BOX(row0), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row1), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row2), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row3), TRUE);
	gtk_box_set_homogeneous(GTK_BOX(row4), TRUE);

	// Row 0
	GtkWidget* btn_revert = gtk_button_new_with_label("Revert");
	g_signal_connect(btn_revert, "clicked", G_CALLBACK(press_revert), NULL);
	gtk_box_pack_start(GTK_BOX(row0), btn_revert, FALSE, FALSE, 0);

	entry_score = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(row0), entry_score, FALSE, FALSE, 0);

	GtkWidget* btn_delete = gtk_button_new_with_label("<x|");
	g_signal_connect(btn_delete, "clicked", G_CALLBACK(press_delete), NULL);
	gtk_box_pack_start(GTK_BOX(row0), btn_delete, FALSE, FALSE, 0);

	// Row 1
	GtkWidget* btn_one = gtk_button_new_with_label("1");
	g_signal_connect(btn_one, "clicked", G_CALLBACK(press_key), "1");
	gtk_box_pack_start(GTK_BOX(row1), btn_one, FALSE, FALSE, 0);

	GtkWidget* btn_two = gtk_button_new_with_label("2");
	g_signal_connect(btn_two, "clicked", G_CALLBACK(press_key), "2");
	gtk_box_pack_start(GTK_BOX(row1), btn_two, FALSE, FALSE, 0);
	
	GtkWidget* btn_three = gtk_button_new_with_label("3");
	g_signal_connect(btn_three, "clicked", G_CALLBACK(press_key), "3");
	gtk_box_pack_start(GTK_BOX(row1), btn_three, FALSE, FALSE, 0);
	
	//Row 2
	GtkWidget* btn_four = gtk_button_new_with_label("4");
	g_signal_connect(btn_four, "clicked", G_CALLBACK(press_key), "4");
	gtk_box_pack_start(GTK_BOX(row2), btn_four, FALSE, FALSE, 0);

	GtkWidget* btn_five = gtk_button_new_with_label("5");
	g_signal_connect(btn_five, "clicked", G_CALLBACK(press_key), "5");
	gtk_box_pack_start(GTK_BOX(row2), btn_five, FALSE, FALSE, 0);

	GtkWidget* btn_six = gtk_button_new_with_label("6");
	g_signal_connect(btn_six, "clicked", G_CALLBACK(press_key), "6");
	gtk_box_pack_start(GTK_BOX(row2), btn_six, FALSE, FALSE, 0);


	//Row3
	GtkWidget* btn_seven = gtk_button_new_with_label("7");
	g_signal_connect(btn_seven, "clicked", G_CALLBACK(press_key), "7");
	gtk_box_pack_start(GTK_BOX(row3), btn_seven, FALSE, FALSE, 0);

	GtkWidget* btn_eight = gtk_button_new_with_label("8");
	g_signal_connect(btn_eight, "clicked", G_CALLBACK(press_key), "8");
	gtk_box_pack_start(GTK_BOX(row3), btn_eight, FALSE, FALSE, 0);

	GtkWidget* btn_nine = gtk_button_new_with_label("9");
	g_signal_connect(btn_nine, "clicked", G_CALLBACK(press_key), "9");
	gtk_box_pack_start(GTK_BOX(row3), btn_nine, FALSE, FALSE, 0);

	//Row4
	GtkWidget* btn_no_score = gtk_button_new_with_label("X");
	g_signal_connect(btn_no_score, "clicked", G_CALLBACK(press_no_score), NULL);
	gtk_box_pack_start(GTK_BOX(row4), btn_no_score, FALSE, FALSE, 0);

	GtkWidget* btn_zero = gtk_button_new_with_label("0");
	g_signal_connect(btn_zero, "clicked", G_CALLBACK(press_key), "0");
	gtk_box_pack_start(GTK_BOX(row4), btn_zero, FALSE, FALSE, 0);

	GtkWidget* btn_enter = gtk_button_new_with_label("OK");
	g_signal_connect(btn_enter, "clicked", G_CALLBACK(press_enter), NULL);
	gtk_box_pack_start(GTK_BOX(row4), btn_enter, FALSE, FALSE, 0);


	GtkWidget *keyboard = gtk_grid_new();
	
	gtk_grid_attach(GTK_GRID(keyboard), row0, 0,0,1,1);	
	gtk_grid_attach(GTK_GRID(keyboard), row1, 0,1,1,1);
	gtk_grid_attach(GTK_GRID(keyboard), row2, 0,2,1,1);	
	gtk_grid_attach(GTK_GRID(keyboard), row3, 0,3,1,1);
	gtk_grid_attach(GTK_GRID(keyboard), row4, 0,4,1,1);


	gtk_box_pack_start(GTK_BOX(main_box),keyboard, FALSE, FALSE, 50);
	
		
	return main_box;
}
