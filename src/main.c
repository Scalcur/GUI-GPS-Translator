/*=======================================================
//
//      Authors:    Kosorotova Valeria
//                  Pasechnikov Vyacheslav
//
//      15/8/2021
//
//=======================================================*/

#include "main.h"

int main(int argc, char *argv[])
{
    
    mainWindow(argc, argv);

    return 0;
}

void quit_button_activate(GtkMenuItem *menuitem)
{
    gtk_main_quit();
}

void about_activate(GtkMenuItem *menuitem)
{
    sprintf(tmp,authors);
    gtk_text_buffer_set_text(textbuffer1, (const gchar*)tmp, (gint) -1);
}

void on_clear_button_clicked(GtkMenuItem *menuitem)
{
    sprintf(tmp,"%s", "");
    gtk_text_buffer_set_text(textbuffer1, (const gchar*)tmp, (gint) -1);
    //gtk_entry_buffer_set_text(entrybuffer1, (const gchar*)tmp, (gint) -1);
    //gtk_entry_buffer_set_text(entrybuffer2, (const gchar*)tmp, (gint) -1);
    //gtk_entry_buffer_set_text(entrybuffer3, (const gchar*)tmp, (gint) -1);
}

void on_Translate_button_clicked(GtkWidget *b)
{

    if(translationFlag)
    {
        double B = atof(gtk_entry_buffer_get_text(entrybuffer1));
        double L = atof(gtk_entry_buffer_get_text(entrybuffer3));
        double H = atof(gtk_entry_buffer_get_text(entrybuffer2));

        from_PZ_90_11_to_SK42_GK(B, L, H);
        sprintf(tmp," X: %.9f\n Y: %.9f\n H: %.9f\n",GK42[0], GK42[1], GK42[2]);
        gtk_text_buffer_set_text(textbuffer1, (const gchar*)tmp, (gint) -1);
    }
    else
    {
        double X = atof(gtk_entry_buffer_get_text(entrybuffer1));
        double Y = atof(gtk_entry_buffer_get_text(entrybuffer3));
        double H = atof(gtk_entry_buffer_get_text(entrybuffer2));

        from_SK42_GK_to_PZ_90_11(X, Y, H);
        sprintf(tmp," X: %.9f\n Y: %.9f\n Z: %.9f\n",PZ_90_11[0], PZ_90_11[1], PZ_90_11[2]);
        gtk_text_buffer_set_text(textbuffer1, (const gchar*)tmp, (gint) -1);
    }
    
}

void on_from_PZ_toggled(GtkRadioButton *b)
{
    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

    if(T)
    {
        translationFlag = 1;
    }
    else
    {
        translationFlag = 0;
    }
}

void on_from_SK_toggled(GtkRadioButton *b)
{
    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

    if(T)
    {
        translationFlag = 0;
    }
    else
    {
        translationFlag = 1;
    }
}

void on_window_main_destroy()
{
    gtk_main_quit();
    remove("gui_gps_translator.glade");
}

