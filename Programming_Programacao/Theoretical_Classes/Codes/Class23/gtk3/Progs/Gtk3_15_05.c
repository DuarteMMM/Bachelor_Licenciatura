/*****************************************************
 *                                                   *
 *      Frame                                        *
 *                                                   *
 *      GTK+ 3                                       *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2015                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <gtk/gtk.h>

#include "Gtk3_CssAux.h"

GtkWindowType       winType     = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos      = GTK_WIN_POS_CENTER  ;

gchar              *winTitle    = "GTK3-Ex: Frame" ;
gchar               chlabel[48] = "xalign/yalign: " ;

glong               xlen        = 400 ;
glong               ylen        = 250 ;
gfloat              xalign      = 0.5 ;
gfloat              yalign      = 0.5 ;
gint                len_chlabel       ;

GtkWidget          *frame ;

gchar *cssData = "@define-color color1 #0000ff;\n"
                 "@define-color color2 #000567;\n"
                 "@define-color color3 #ff0000;\n"
                 "@define-color color5 #00dddd;\n"
                 "@define-color color6 #eec591;\n"
                 "@define-color color7 #8e2323;\n"
                 "#Label01 {color: @color7; font-family: Tahoma; font-weight: bold; font-size: 12px;}\n"
                 "#Frame01 {color: @color1; background-color: @color6; font-family: Tahoma; font-weight: bold; font-size: 11px;}\n"
                 "#Button01 {color: @color2; background: @color5; border: 1px; font-family: Tahoma; font-weight: bold; font-size: 10px;}\n"
                 "#Button02 {color: @color3; background: @color5; border: 1px; font-family: Tahoma; font-weight: bold; font-size: 10px;}\n";

gboolean 
cb_xalign (GtkWidget *widget , 
          gpointer   label  )
{
  xalign = xalign + 0.1;
  if (xalign > 1.01)
    xalign = 0;
  gtk_frame_set_label_align (GTK_FRAME(frame), xalign, yalign);

  sprintf (&chlabel[len_chlabel], "( %.1f , %.1f )", xalign, yalign);
  gtk_label_set_text(label, chlabel);

  return FALSE;
}

gboolean 
cb_yalign (GtkWidget *widget , 
           gpointer   label  )
{
  yalign = yalign + 0.1;
  if (yalign > 1.01)
    yalign = 0;
  gtk_frame_set_label_align (GTK_FRAME(frame), xalign, yalign);

  sprintf (&chlabel[len_chlabel], "( %.1f , %.1f )", xalign, yalign);
  gtk_label_set_text(label, chlabel);

  return FALSE;
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *bxalign, *byalign, *label ;

  len_chlabel = strlen (chlabel);
  sprintf (&chlabel[len_chlabel], "( %.1f , %.1f )", xalign, yalign);

  gtk_init (&argc, &argv);
  setlocale (LC_NUMERIC, "en_US.UTF-8");
  create_style_from_data (cssData);

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), xlen, ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox), 5);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX(vbox), hbox1, TRUE, TRUE, 0);

  label = gtk_label_new (chlabel);
  gtk_widget_set_name (label, "Label01");
  gtk_box_pack_start (GTK_BOX(hbox1), label, TRUE, FALSE, 0);

  frame = gtk_frame_new (" Frame dos Botões ");
  gtk_widget_set_name (frame, "Frame01");
  gtk_frame_set_label_align (GTK_FRAME(frame), xalign, yalign);
  gtk_box_pack_end (GTK_BOX(vbox), frame, FALSE, TRUE, 0);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox2), 5);
  gtk_container_add (GTK_CONTAINER(frame), hbox2);

  bxalign = gtk_button_new_with_label ("xalign");
  gtk_widget_set_name (bxalign, "Button01");
  gtk_widget_set_size_request (bxalign, 90, 30);
  gtk_box_pack_start (GTK_BOX(hbox2), bxalign, FALSE, TRUE, 10);
  g_signal_connect (bxalign, "clicked", G_CALLBACK(cb_xalign), label);

  byalign = gtk_button_new_with_label ("yalign");
  gtk_widget_set_name (byalign, "Button02");
  gtk_widget_set_size_request (byalign, 90, 30);
  gtk_box_pack_end (GTK_BOX(hbox2), byalign, FALSE, TRUE, 10);
  g_signal_connect (byalign, "clicked", G_CALLBACK(cb_yalign), label);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
