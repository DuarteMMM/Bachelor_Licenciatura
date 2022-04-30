/*****************************************************
 *                                                   *
 *      Mostra a posição da janela e o seu tamanho   *
 *      bem como a posição e tamanho de uma widget.  *
 *      Com cores, tipos de letra                    *
 *                                                   *
 *      GTK+ 3                                       *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2015                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include "Gtk3_CssAux.h"

GtkWindowType       winType     = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos      = GTK_WIN_POS_CENTER ;
gchar              *winTitle    = "GTK3-Ex: Window e Widget pos. size" ;
gint                xlen        = 450 ;
gint                ylen        = 200 ;

char               *ch_labela[] = {"Main Window: ", "       Posição: ", "       Size: "};
char               *ch_labelb[] = {"Button 'Exit': ", "       Posição: ", "       Size: "};

GtkWidget          *labela[3], *labelb[3], *bt1 ;

gchar              *cssData = "#Label01 {color: #000567; font-family: Tahoma; font-weight: bold; font-size: 14px;}\n"
                              "frame {color: blue; background-color: #eec591; font-family: Tahoma; font-weight: bold; font-size: 18px;}\n" ;

gboolean
cb_configure (GtkWidget      *widget ,
              GdkEventExpose *event  ,
              GtkWidget      *win    )
{
  gchar         str[32] ;
  GtkAllocation bt1_alloc, win_alloc ;

  gtk_window_get_position (GTK_WINDOW(win), &win_alloc.x, &win_alloc.y);
  gtk_window_get_size (GTK_WINDOW(gtk_widget_get_toplevel(win)), &win_alloc.width, &win_alloc.height);

  sprintf (str, "%s %3d, %3d", ch_labela[1], win_alloc.x, win_alloc.y);
  gtk_label_set_text (GTK_LABEL(labela[1]), str);

  sprintf (str, "%s %3d, %3d", ch_labela[2], win_alloc.width, win_alloc.height);
  gtk_label_set_text (GTK_LABEL(labela[2]), str);

  //bt1_alloc.width = gtk_widget_get_allocated_width (bt1);
  //bt1_alloc.height = gtk_widget_get_allocated_height (bt1);
  gtk_widget_get_allocation (bt1, &bt1_alloc);

  sprintf (str, "%s %3d, %3d", ch_labelb[1], bt1_alloc.x, bt1_alloc.y);
  gtk_label_set_text (GTK_LABEL(labelb[1]), str);

  sprintf (str, "%s %3d, %3d", ch_labelb[2], bt1_alloc.width, bt1_alloc.height);
  gtk_label_set_text (GTK_LABEL(labelb[2]), str);

  return FALSE;
}

GtkWidget *
create_hbox_label (GtkWidget *parent ,
		   char      *text   ,
		   int        border )

{
  GtkWidget *hbox, *label ;

  if (border > 0)
    {
      hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
      gtk_container_set_border_width (GTK_CONTAINER (hbox), border);
      gtk_box_pack_start (GTK_BOX(parent), hbox, FALSE, TRUE, 0);
    }

  hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox), 0);
  gtk_box_pack_start (GTK_BOX(parent), hbox, FALSE, TRUE, 0);

  label = gtk_label_new (text);
  gtk_widget_set_name (label, "Label01");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 0);

  return label;
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *frame, *vbox, *hbox1, *hbox1a, *hbox1b, *hbox2, *hbox3 ;

  gtk_init (&argc, &argv);
  create_style_from_data (cssData);

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), xlen, ylen);
  gtk_widget_set_size_request (window, 400, 180);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  // frame

  frame = gtk_frame_new ("  Posições dos Objectos  ");
  gtk_frame_set_label_align (GTK_FRAME(frame), 0.5, 1.0);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
  gtk_box_pack_start (GTK_BOX(vbox), frame, TRUE, TRUE, 0);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_container_set_border_width (GTK_CONTAINER (hbox1), 0);
  gtk_box_set_homogeneous (GTK_BOX(hbox1), TRUE);
  gtk_container_add (GTK_CONTAINER(frame), hbox1);

  // Main Window Info

  hbox1a = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);
  gtk_container_set_border_width (GTK_CONTAINER (hbox1a), 0);
  gtk_box_pack_start (GTK_BOX(hbox1), hbox1a, FALSE, TRUE, 10);

  labela[0] = create_hbox_label (hbox1a, ch_labela[0], 3);
  labela[1] = create_hbox_label (hbox1a, ch_labela[1], 0);
  labela[2] = create_hbox_label (hbox1a, ch_labela[2], 0);

  // Frame Info 

  hbox1b = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);
  gtk_container_set_border_width (GTK_CONTAINER (hbox1a), 0);
  gtk_box_pack_start (GTK_BOX(hbox1), hbox1b, FALSE, TRUE, 10);

  labelb[0] = create_hbox_label (hbox1b, ch_labelb[0], 3);
  labelb[1] = create_hbox_label (hbox1b, ch_labelb[1], 0);
  labelb[2] = create_hbox_label (hbox1b, ch_labelb[2], 0);

  // Final - Exit

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_set_homogeneous (GTK_BOX(hbox2), FALSE);
  gtk_container_set_border_width (GTK_CONTAINER (hbox2), 5);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 0);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_set_homogeneous (GTK_BOX(hbox2), TRUE);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 0);

  hbox3 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (hbox2), hbox3, FALSE, TRUE, 20);

  bt1 = gtk_button_new_with_label (" Exit ");
  //gtk_widget_set_size_request (bt1, 100, 15);
  gtk_box_pack_end (GTK_BOX (hbox2), bt1, FALSE, TRUE, 20);
  g_signal_connect (bt1, "clicked", G_CALLBACK(gtk_main_quit), NULL);

  // Final

  g_signal_connect (G_OBJECT(window), "configure-event", G_CALLBACK(cb_configure), window);
  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
