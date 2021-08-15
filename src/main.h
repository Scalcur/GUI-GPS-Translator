/*=======================================================
//
//      Authors:    Kosorotova Valeria
//                  Pasechnikov Vyacheslav
//
//      15/8/2021
//
//=======================================================*/

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "algorithm.h"

#include "gui_gps_translator-resources.h"

#ifndef __MAIN_H
#define __MAIN_H

GtkBuilder      *builder;

GtkWindow       *main_window;
GtkWidget       *window;
GtkWidget		*quit_button;
GtkWidget		*about;
GtkWidget		*to_SK_button;
GtkWidget		*clear_button;
GtkWidget       *from_PZ;
GtkWidget       *from_SK;
GtkWidget       *textView;
GtkWidget       *entry1;
GtkWidget       *entry2;
GtkWidget       *entry3;

GtkTextBuffer   *textbuffer1;

GtkEntryBuffer   *entrybuffer1;
GtkEntryBuffer   *entrybuffer2;
GtkEntryBuffer   *entrybuffer3;

char tmp[256];

char const authors[] = "Simple GUI GPS Translator\n\nAuthors:\nKosorotova Valeria\nPasechnikov Vyacheslav\n\n\t\t15/08/2021";

uint8_t translationFlag = 1;

void mainWindow(int argc, char *argv[]);

void mainWindow(int argc, char *argv[])
{

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_resource("/glade/gui_gps_translator.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    main_window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));

    gtk_builder_connect_signals(builder, NULL);

    gtk_window_set_title(main_window, "GUI GPS Translator");

    GdkPixbuf   *icon =  gdk_pixbuf_new_from_resource("/icon.ico", NULL);

    gtk_window_set_icon(main_window, icon);

	quit_button = GTK_WIDGET(gtk_builder_get_object(builder, "quit_button"));
    about = GTK_WIDGET(gtk_builder_get_object(builder, "about"));
	to_SK_button = GTK_WIDGET(gtk_builder_get_object(builder, "to_SK_button"));
    clear_button = GTK_WIDGET(gtk_builder_get_object(builder, "clear_button"));

    from_PZ = GTK_WIDGET(gtk_builder_get_object(builder, "from_PZ"));
    from_SK = GTK_WIDGET(gtk_builder_get_object(builder, "from_SK"));

    textView = GTK_WIDGET(gtk_builder_get_object(builder, "textView"));
    entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    entry3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry3"));

    entrybuffer1 = gtk_entry_get_buffer(GTK_ENTRY(entry1));
    entrybuffer2 = gtk_entry_get_buffer(GTK_ENTRY(entry2));
    entrybuffer3 = gtk_entry_get_buffer(GTK_ENTRY(entry3));

    textbuffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));

    gtk_widget_show(window);
    gtk_main();
}

#endif
