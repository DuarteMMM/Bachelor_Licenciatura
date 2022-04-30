/*****************************************************
 *                                                   *
 *      Criação de um "Font Chooser Dialog"         *
 *                                                   *
 *      GTK+ 3                                       *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2014                        *
 *                                                   *
 *****************************************************/

#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "Gtk3_CssAux.h"

GtkWindowType       winType     = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos      = GTK_WIN_POS_CENTER  ;

gchar              *winTitle    = "GTK3: Font Chooser Dialog" ;
gchar              *strStyle[8] = {"normal", "oblique", "italic"};

int                 xlen        = 500 ;
int                 ylen        = 300 ;

GtkWidget          *label ;
gchar              *fontname2   = "font-family: Tahoma; font-weight: bold; font-size: 18px;";
gchar              *fontname ;

gchar *cssData = "#label1 {color: red; font-family: Tahoma; font-weight: bold; font-size: 18px; font-style: italic;}\n"
                 "#btAplica label {color: #ab0567; font-family: Tahoma; font-weight: bold; font-size: 12px;}\n";

void
font_chooser_cancel (GtkWidget *w      ,
		     GtkWidget *dialog )
{
  g_print ("font_chooser_quit - Cancel\n");

  gtk_widget_destroy (dialog);
}

void
font_chooser_ok (GtkWidget *w      ,
	         GtkWidget *dialog )
{
  gchar *cssData2 ;

  g_free (fontname);
  fontname = gtk_font_chooser_get_font (GTK_FONT_CHOOSER(dialog));
  g_print ("font_chooser_ok - Font: %s\n", fontname);

  gchar *str1 = "#label1 {color: red; ";

  const PangoFontDescription *fontDesc = gtk_font_chooser_get_font_desc(GTK_FONT_CHOOSER(dialog));
  const char *fontFamily = pango_font_description_get_family (fontDesc);
  int fontSize = gtk_font_chooser_get_font_size (GTK_FONT_CHOOSER(dialog));
  PangoWeight weight = pango_font_description_get_weight (fontDesc);
  PangoStyle style = pango_font_description_get_style (fontDesc);
  
  cssData2 = (char *) malloc (strlen(str1) + strlen(fontFamily) + 64);
  sprintf (cssData2, "%s font-family: %s; font-size: %dpx; font-weight: %d; font-style: %s;}",
	   str1, fontFamily, fontSize/1000, weight, strStyle[style]);
  g_print ("cssData2: %s\n", cssData2);
  
  create_style_from_data (cssData2);

  gtk_widget_destroy (dialog);
  free (cssData2);
}

void
font_chooser (GtkWidget *w      ,
              GtkWidget *window )
{
  GtkWidget *dialog, *button ;

  dialog = gtk_font_chooser_dialog_new ("GTK3: Font Chooser Dialog", GTK_WINDOW(window));
  gtk_font_chooser_set_font (GTK_FONT_CHOOSER(dialog), fontname); 

  button = gtk_dialog_get_widget_for_response (GTK_DIALOG(dialog), GTK_RESPONSE_OK);
  g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK(font_chooser_ok), dialog);

  button = gtk_dialog_get_widget_for_response (GTK_DIALOG(dialog), GTK_RESPONSE_CANCEL);
  g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK(font_chooser_cancel), dialog);

  gtk_widget_show (dialog);
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *button1 ;

  fontname = strdup (fontname2);

  gtk_init (&argc, &argv);
  create_style_from_data (cssData);

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), xlen, ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  /* label, button */ 

  label = gtk_label_new ("Font Chooser Dialog");
  gtk_widget_set_name (GTK_WIDGET(label), "label1");
  gtk_box_pack_start (GTK_BOX(vbox), label, FALSE, TRUE, 20);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER(vbox), hbox1);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 20);

  button1 = gtk_button_new_with_label ("Nova Fonte");
  gtk_widget_set_name (GTK_WIDGET(button1), "btAplica");
  gtk_widget_set_size_request (button1, 140, 22);
  gtk_box_pack_end (GTK_BOX(hbox2), button1, FALSE, TRUE, 30);
  g_signal_connect (button1, "clicked", G_CALLBACK(font_chooser), window);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
