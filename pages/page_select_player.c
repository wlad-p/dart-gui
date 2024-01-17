#include <gtk-3.0/gtk/gtk.h>
#include "../game_state.h"
#include "page_menu.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXCHAR 500

typedef struct {
    char *player_name;
    GtkWidget *stack;
} PlayerSelection;

static void open_page_menu(GtkWidget* widget, gpointer data){

	GtkStack *stack = GTK_STACK(data);
	gtk_stack_set_visible_child_name(stack, "page_menu");

}

static void select_player(GtkButton* button, gpointer data){

    PlayerSelection *player = data;
    add_player(player->player_name);
    reload_menu();

    GtkStack *stack = GTK_STACK(player->stack);
    gtk_stack_set_visible_child_name(stack, "page_menu");

}

static void open_page_new_player(GtkWidget* widget, gpointer data){
    GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page_new_player");
}

GtkWidget *create_page_select_player(GtkWidget *window, GtkWidget *stack) {
    GtkWidget *box_main = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);

    GtkStyleContext *select_player_context = gtk_widget_get_style_context(box_main);
	gtk_style_context_add_class(select_player_context, "select_player");

	GtkWidget *box_top_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	GtkWidget *btn_back = gtk_button_new_with_label("<");
	g_signal_connect(btn_back, "clicked", G_CALLBACK(open_page_menu),stack);

	GtkWidget *label_title = gtk_label_new("Darts");

	GtkStyleContext *box_top_bar_context = gtk_widget_get_style_context(box_top_bar);
	gtk_style_context_add_class(box_top_bar_context, "box_top_bar");

	gtk_box_pack_start(GTK_BOX(box_top_bar),btn_back, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_top_bar),label_title, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box_main),box_top_bar, FALSE, FALSE, 0);


    FILE *fp;
    char name[MAXCHAR];
    fp = fopen("/home/darts/dart-gui/players.csv", "r");
    while(feof(fp) != true){
        fgets(name,MAXCHAR,fp);
        name[strcspn(name, "\n")] = 0;

        GtkWidget *box_player_card = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,20);

        char image_file[100] = "images/";
        strcat(image_file, name);
        strcat(image_file, ".jpg"); 
        GtkWidget *photo = gtk_image_new_from_file(image_file);
        
        GtkWidget *label_name = gtk_label_new(name);
        GtkWidget *btn_select = gtk_button_new_with_label(">");

        PlayerSelection *data = g_new0(PlayerSelection, 1);
        data->player_name = g_strdup(name);
        data->stack = stack;
        
        g_signal_connect(btn_select, "clicked", G_CALLBACK(select_player), data);

        gtk_box_pack_start(GTK_BOX(box_player_card),photo, FALSE, FALSE, 20);
        gtk_box_pack_start(GTK_BOX(box_player_card),label_name, FALSE, FALSE, 20);
        gtk_box_pack_start(GTK_BOX(box_player_card),btn_select, FALSE, FALSE, 20);

        gtk_box_pack_start(GTK_BOX(box_main), box_player_card, FALSE, FALSE, 20);
            
    }

    GtkWidget *btn_new_player = gtk_button_new_with_label("Create new Player");
    g_signal_connect(btn_new_player, "clicked", G_CALLBACK(open_page_new_player),stack);
    gtk_box_pack_end(GTK_BOX(box_main),btn_new_player, FALSE, FALSE, 20);

    return box_main;
}
