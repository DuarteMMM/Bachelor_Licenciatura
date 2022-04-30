/*****************************************************
 *                                                   *
 *      Criação de um "Color Button"                 *
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

GtkWindowType       winType  = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos   = GTK_WIN_POS_CENTER  ;

gchar              *winTitle = "GTK3: Color Button" ;

int                 xlen     = 400 ;
int                 ylen     = 200 ;

GtkWidget          *label ;

gchar *cssData = "#label1 {color: red; font-family: Tahoma; font-weight: bold; font-size: 18px;}\n"
                 "#btAplica label {color: #ab0567; font-family: Tahoma; font-weight: bold; font-size: 14px;}\n";


void
color_chooser (GtkWidget *w  ,
	       GtkWidget *cb )
{
  gchar    cssData2[128], *c1 ;
  gchar   *str1 = "#label1 {color: #%2.2X%2.2X%2.2X; font-family: Tahoma; font-weight: bold; font-size: 18px;}";
  int      r1, g1, b1, t1    ;
  GdkRGBA  color1 ;
  
  gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER(cb), &color1);

  c1 = gdk_rgba_to_string (&color1);
  t1 = sscanf (c1, "rgb(%d,%d,%d)", &r1, &g1, &b1);
  if (t1 != 3)
    r1 = g1 = b1 = 0;
  sprintf (cssData2, str1, r1, g1, b1);

  create_style_from_data (cssData2);

  //printf ("Cor: %s - %d , %d , %d\n", c1, r1, g1, b1);
  //printf ("Len: %ld (%s)\n", strlen(cssData2), cssData2);

  free (c1);
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *cbutton1, *button1 ;
  GdkRGBA    color1 ;
  
  gtk_init (&argc, &argv);
  create_style_from_data (cssData);

  gdk_rgba_parse (&color1,"red");

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), xlen, ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  // label

  label = gtk_label_new ("Teste de Saida");
  gtk_widget_set_name (GTK_WIDGET(label), "label1");
  gtk_box_pack_start (GTK_BOX(vbox), label, FALSE, TRUE, 20);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER(vbox), hbox1);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 20);

  // color button
  
  cbutton1 = gtk_color_button_new_with_rgba (&color1);
  gtk_widget_set_size_request (cbutton1, 100, 22);
  gtk_box_pack_end (GTK_BOX(hbox2), cbutton1, FALSE, TRUE, 30);

  button1 = gtk_button_new_with_label ("Aplica");
  gtk_widget_set_name (GTK_WIDGET(button1), "btAplica");
  gtk_widget_set_size_request (button1, 100, 22);
  gtk_box_pack_start (GTK_BOX(hbox2), button1, FALSE, TRUE, 30);
  g_signal_connect (button1, "clicked", G_CALLBACK(color_chooser), cbutton1);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
