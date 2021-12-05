//
// Created by god on 2021/12/4.
//

#ifndef HUFFMAN_EXAMPLE_MAIN_WINDOW_H
#define HUFFMAN_EXAMPLE_MAIN_WINDOW_H


#include <gtk/gtk.h>

GtkWidget *create_Enter_window();

void on_Enter_button_clicked(GtkWidget *button, gpointer window);

void on_About_button_clicked(GtkWidget *button, gpointer window);

GtkWidget *create_main_window();

void on_encode_button_clicked(GtkWidget *button, gpointer window);

void on_decode_button_clicked(GtkWidget *button, gpointer window);

GtkWidget *create_encode_window();
void on_encode_entry_activate(GtkWidget *entry,gpointer window);
void on_encode_import_button_clicked(GtkWidget *button,gpointer window);
void on_encode_export_button_clicked(GtkWidget *button,gpointer window);

GtkWidget *create_decode_window();
void on_decode_entry_activate(GtkWidget *entry,gpointer window);
void on_decode_import_button_clicked(GtkWidget *button,gpointer window);
void on_decode_export_button_clicked(GtkWidget *button,gpointer window);
#endif //HUFFMAN_EXAMPLE_MAIN_WINDOW_H
