/*#include <stdio.h>
#include <string.h>*/
#include <gtk/gtk.h>

/*int count = 0; Variable commented out*/
/*char names[256];*/
GtkWidget *txt;
GtkWidget *txt2;

void end_program (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit ();
}

/*void count_button (GtkWidget *wid, gpointer ptr)
{
    char buffer[30];
    count++;
    sprintf (buffer, "Button pressed %d times.", count);
    gtk_label_set_text (GTK_LABEL (ptr), buffer);
}Function commented out*/

void add_text (GtkWidget *wid, gpointer ptr)
{
    const char *input = gtk_entry_get_text (GTK_ENTRY (txt));
    gtk_label_set_text (GTK_LABEL (ptr), input);
}

void add_text2 (GtkWidget *wid, gpointer ptr)
{
    const char *input = gtk_entry_get_text (GTK_ENTRY (txt2));
    gtk_label_set_text (GTK_LABEL (ptr), input);
}

void main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);
    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    /* Close Button and Exit function call */
    /*GtkWidget *btn = gtk_button_new_with_label ("Close");*/
    GtkWidget *btn = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
    g_signal_connect (win, "delete_event", G_CALLBACK (end_program), NULL);
    g_signal_connect_swapped (G_OBJECT (btn), "clicked", G_CALLBACK (end_program), (gpointer) win);
    /* add 2 invisible labels to be set as names are added to the lists*/
    GtkWidget *lbl3 = gtk_label_new("names here");
    GtkWidget *lbl4 = gtk_label_new("second names here");
    /* A label with a function button*/
    GtkWidget *lbl = gtk_label_new ("Add President Candidates:");
    /*GtkWidget *btn2 = gtk_button_new_with_label ("Add+");*/
    GtkWidget *btn2 = gtk_button_new_from_stock (GTK_STOCK_ADD);
    g_signal_connect (btn2, "clicked", G_CALLBACK (add_text), lbl3);
    GtkWidget *lbl2 = gtk_label_new ("Add Vice President Candidate:");
    /*GtkWidget *btn3 = gtk_button_new_with_label ("Add+");*/
    GtkWidget *btn3 = gtk_button_new_from_stock (GTK_STOCK_ADD);
    g_signal_connect (btn3, "clicked", G_CALLBACK (add_text2), lbl4);
    /* create GtkEntry itself "txt"*/
    GtkWidget *btn_done = gtk_button_new_from_stock (GTK_STOCK_OK);

    txt = gtk_entry_new ();
    txt2 = gtk_entry_new ();
    /* Table with widgets locations*/
    GtkWidget *tbl = gtk_table_new (7, 3, TRUE);
    gtk_table_attach_defaults (GTK_TABLE (tbl), lbl, 0, 3, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE (tbl), btn2, 2, 3, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE (tbl), btn, 1, 2, 6, 7);
    gtk_table_attach_defaults (GTK_TABLE (tbl), btn_done, 2, 3, 6, 7);
    gtk_table_attach_defaults (GTK_TABLE (tbl), txt, 0, 2, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE (tbl), lbl2, 0, 3, 3, 4);
    gtk_table_attach_defaults (GTK_TABLE (tbl), txt2, 0, 2, 5, 6);
    gtk_table_attach_defaults (GTK_TABLE (tbl), btn3, 2, 3, 5, 6);
    gtk_table_attach_defaults (GTK_TABLE (tbl), lbl3, 0, 1, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE (tbl), lbl4, 0, 1, 4, 5);
    /* table as main container, show window with all widgets, and generate this main code as gui*/
    gtk_container_add (GTK_CONTAINER (win), tbl);
    gtk_widget_show_all (win);
    gtk_main ();
}
