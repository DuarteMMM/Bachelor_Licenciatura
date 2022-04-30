/*****************************************************
 *                                                   *
 *      spin button + cores                          *
 *                                                   *
 *      GTK+ 3                                       *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2018                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "Gtk3_CssAux.h"

GtkWidget  *entry1, *spin1, *label1;

gchar *cssData = "@define-color colorButton #8e2323;\n"
  //  "#window1 {background-color: Wheat1;}\n"
  "#button1 {color: magenta; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n"
  "#label1 {color: blue; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n"
  "#spin1 {padding: 10px; color: green; background-color: Wheat2; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n"
#if GTK_CHECK_VERSION(3,22,0)
  "#spin1 button.down {color: red;}\n"
  "#spin1 button.up {color: blue;}\n"
#else
#endif
  ;

void
func_button1 (GtkWidget  *w    ,
              gpointer    data )
{
  gdouble x1       ;
  gchar   str1[16] ;

  x1 = gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin1));
  sprintf (str1, "%.2lf", x1);
  gtk_label_set_text (GTK_LABEL(label1), str1);
}

GtkWidget *
create_spin_button (void)
{
  GtkWidget      *spinButton ;
  GtkAdjustment  *adj1       ;

  adj1 = (GtkAdjustment *) gtk_adjustment_new (1.0, -10.0, 31.0, 0.5, 5.0, 0);
  spinButton = gtk_spin_button_new (adj1, 1, 0);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON(spinButton), TRUE);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON(spinButton), 2);
  gtk_widget_set_size_request (spinButton, 150, 30);

  return spinButton;
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox0, *hbox1, *hbox2, *button1 ;

  gtk_init (&argc, &argv);
  create_style_from_data (cssData);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (GTK_WIDGET(window), "window1");
  gtk_window_set_default_size (GTK_WINDOW(window), 450, 300);
  gtk_widget_set_size_request (window, 400, 250);

  gtk_window_set_title (GTK_WINDOW(window), "GTK3-Ex: SpinButtun");
  gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  g_signal_connect_swapped (G_OBJECT(window), "destroy",
                            G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  // label

  hbox0 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox0, FALSE, TRUE, 50);

  // Cria o 'spin button'
  
  spin1 = create_spin_button ();
  gtk_widget_set_name (spin1, "spin1");
  gtk_box_pack_start (GTK_BOX (hbox0), spin1, TRUE, FALSE, 10);
  
  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_set_homogeneous (GTK_BOX(hbox2), TRUE);
  gtk_box_pack_end (GTK_BOX (vbox), hbox2, FALSE, TRUE, 20);

  label1 = gtk_label_new ("Value");
  gtk_widget_set_name (label1, "label1");
  gtk_box_pack_start (GTK_BOX (hbox2), label1, FALSE, TRUE, 20);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 20);
  gtk_box_set_homogeneous (GTK_BOX(hbox1), TRUE);
  gtk_box_pack_end (GTK_BOX (vbox), hbox1, FALSE, TRUE, 10);

  button1 = gtk_button_new_with_label ("Spin Value");
  gtk_widget_set_name (button1, "button1");
  gtk_widget_set_size_request (button1, 150, 30);
  g_signal_connect (button1, "clicked", G_CALLBACK (func_button1), NULL);
  gtk_box_pack_start (GTK_BOX (hbox1), button1, TRUE, FALSE, 10);

  gtk_widget_grab_focus (button1);
  
  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
