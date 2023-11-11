// stack_page1.c
#include <gtk-3.0/gtk/gtk.h>
#include "page_menu.h"

GtkWidget *create_page_menu(GtkWidget *window, GtkWidget *stack) {

    GtkWidget *page2 = gtk_label_new("Page 2 Content");
    //gtk_stack_add_named(GTK_STACK(stack), page2, "page2");

    return page2;
}
