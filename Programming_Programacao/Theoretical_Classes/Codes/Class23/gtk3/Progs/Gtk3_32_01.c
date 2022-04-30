/*
   
   Mostra a posição posição do rato

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>


GtkWindowType       winType     = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos      = GTK_WIN_POS_CENTER ;

gchar              *winTitle    = "GTK3-Ex: Rato - Posição e Carregar" ;

gint                xlen        = 500 ;
gint                ylen        = 300 ;

char               *ch_labela[] = {"Pointer motion: ", "       Position: ", "       Root: "};
char               *ch_labelb[] = {"Button (Mouse): ", "       Press: ", "       Release: ", "       Button: "};
char               *ch_labelc   = "Event: ";
char               *ch_labeld[] = {"Key Press: ", "       Keyval: ", "       String: ", "       Length: ", "       is_modifier: "};

GtkWidget          *labela[3], *labelb[4], *labelc, *labeld[5], *bt1 ;


gboolean
cb_motion_notify (GtkWidget      *widget ,
		  GdkEventExpose *event  ,
		  GtkWidget      *win    )
{
  gchar       str[64] ;

  static gint    press_count = 0, key_length = (-1), key_flag = (-1);
  static double  motion_x = 0., motion_y = 0.;
  static double  motion_root_x = 0, motion_root_y = 0;
  static double  bt_release_x = 0., bt_release_y = 0.;
  static double  bt_press_x = 0., bt_press_y = 0.;
  static guint   key_keyval = (-1), key_IsModif = (-1), bt_button = (-1);
  static gchar   key_string[16] = "";

  //if (event->type != 3) printf ("Evento: %d\n", event->type);

  if (event->type == GDK_MOTION_NOTIFY)
    {
      //printf ("Event: Motion Notify\n");
      motion_x = ((GdkEventMotion *)event)->x;
      motion_y = ((GdkEventMotion *)event)->y;
      motion_root_x = ((GdkEventMotion *)event)->x_root;
      motion_root_y = ((GdkEventMotion *)event)->y_root;
    }
  else if (event->type == GDK_BUTTON_PRESS)
    {
      //printf ("Event: Button Press\n");
      ++press_count;
      bt_press_x = ((GdkEventButton *)event)->x;
      bt_press_y = ((GdkEventButton *)event)->y;
      bt_button = ((GdkEventButton *)event)->button;
    }
  else if (event->type == GDK_BUTTON_RELEASE)
    {
      //printf ("Event: Button Release\n");
      ++press_count;
      bt_release_x = ((GdkEventButton *)event)->x;
      bt_release_y = ((GdkEventButton *)event)->y;
    }
  else if (event->type == GDK_KEY_PRESS)
    {
      key_flag = 1;
      key_keyval = ((GdkEventKey *) event)->keyval;
      key_length = ((GdkEventKey *) event)->length;
      strncpy (key_string, ((GdkEventKey *) event)->string, 16);
      key_IsModif = ((GdkEventKey *) event)->is_modifier;
    }

  sprintf (str, "%s %4.0lf, %4.0lf", ch_labela[1], motion_x, motion_y);
  gtk_label_set_text (GTK_LABEL(labela[1]), str);

  sprintf (str, "%s %4.0lf, %4.0lf", ch_labela[2], motion_root_x, motion_root_y);
  gtk_label_set_text (GTK_LABEL(labela[2]), str);

  if (press_count == 0)
    {
      gtk_label_set_text (GTK_LABEL(labelb[1]), ch_labelb[1]);
      gtk_label_set_text (GTK_LABEL(labelb[2]), ch_labelb[2]);
      gtk_label_set_text (GTK_LABEL(labelb[3]), ch_labelb[3]);
    }
  else
    {
      sprintf (str, "%s %4.0lf, %4.0lf", ch_labelb[1], bt_press_x, bt_press_y);
      gtk_label_set_text (GTK_LABEL(labelb[1]), str);

      sprintf (str, "%s %4.0lf, %4.0lf", ch_labelb[2], bt_release_x, bt_release_y);
      gtk_label_set_text (GTK_LABEL(labelb[2]), str);

      sprintf (str, "%s %u", ch_labelb[3], bt_button);
      gtk_label_set_text (GTK_LABEL(labelb[3]), str);

      sprintf (str, "%s %d", ch_labelc, event->type);
      gtk_label_set_text (GTK_LABEL(labelc), str);
    }
  if (key_flag < 0)
    {
      gtk_label_set_text (GTK_LABEL(labeld[1]), ch_labeld[1]);
      gtk_label_set_text (GTK_LABEL(labeld[2]), ch_labeld[2]);
      gtk_label_set_text (GTK_LABEL(labeld[3]), ch_labeld[3]);
      gtk_label_set_text (GTK_LABEL(labeld[4]), ch_labeld[4]);
    }
  else
    {
      sprintf (str, "%s %u", ch_labeld[1], key_keyval);
      gtk_label_set_text (GTK_LABEL(labeld[1]), str);

      sprintf (str, "%s '%s'", ch_labeld[2], key_string);
      gtk_label_set_text (GTK_LABEL(labeld[2]), str);

      sprintf (str, "%s %d", ch_labeld[3], key_length);
      gtk_label_set_text (GTK_LABEL(labeld[3]), str);

      sprintf (str, "%s %d", ch_labeld[4], key_IsModif);
      gtk_label_set_text (GTK_LABEL(labeld[4]), str);
    }    

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
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 0);

  return label;
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *frame, *vbox, *hbox1, *hbox1a, *hbox1b, *hbox2, *hbox3 ;

  gtk_init (&argc, &argv);

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), xlen, ylen);
  gtk_widget_set_size_request (window, 400, 180);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  // frame

  frame = gtk_frame_new ("  Posições de Rato e Teclas do Teclado  ");
  gtk_frame_set_label_align (GTK_FRAME(frame), 0.5, 0.5);
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

  labeld[0] = create_hbox_label (hbox1a, ch_labeld[0], 3);
  labeld[1] = create_hbox_label (hbox1a, ch_labeld[1], 0);
  labeld[2] = create_hbox_label (hbox1a, ch_labeld[2], 0);
  labeld[3] = create_hbox_label (hbox1a, ch_labeld[3], 0);
  labeld[4] = create_hbox_label (hbox1a, ch_labeld[4], 0);

  // Frame Info 

  hbox1b = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);
  gtk_container_set_border_width (GTK_CONTAINER (hbox1a), 0);
  gtk_box_pack_start (GTK_BOX(hbox1), hbox1b, FALSE, TRUE, 10);

  labelb[0] = create_hbox_label (hbox1b, ch_labelb[0], 3);
  labelb[1] = create_hbox_label (hbox1b, ch_labelb[1], 0);
  labelb[2] = create_hbox_label (hbox1b, ch_labelb[2], 0);
  labelb[3] = create_hbox_label (hbox1b, ch_labelb[3], 0);

  // Final - Exit

  //hbox2 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_set_homogeneous (GTK_BOX(hbox2), FALSE);
  gtk_container_set_border_width (GTK_CONTAINER (hbox2), 5);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 0);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_set_homogeneous (GTK_BOX(hbox2), TRUE);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, FALSE, 0);

  //labelc = create_hbox_label (hbox2, ch_labelc, 3);
  labelc = gtk_label_new (ch_labelc);
  gtk_box_pack_start (GTK_BOX(hbox2), labelc, FALSE, FALSE, 10);

  hbox3 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (hbox2), hbox3, FALSE, TRUE, 20);

  bt1 = gtk_button_new_with_label (" Exit ");
  gtk_box_pack_end (GTK_BOX (hbox2), bt1, FALSE, TRUE, 20);
  g_signal_connect (bt1, "clicked", G_CALLBACK(gtk_main_quit), NULL);

  // Final

  gtk_widget_set_events (window, GDK_POINTER_MOTION_MASK | GDK_BUTTON_PRESS_MASK | 
			 GDK_KEY_PRESS_MASK | GDK_BUTTON_RELEASE_MASK);

  g_signal_connect (window, "motion-notify-event", G_CALLBACK (cb_motion_notify), NULL);
  g_signal_connect (window, "button_press_event", G_CALLBACK (cb_motion_notify), NULL);
  g_signal_connect (window, "button_release_event", G_CALLBACK (cb_motion_notify), NULL);
  g_signal_connect (window, "key_press_event", G_CALLBACK (cb_motion_notify), NULL);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
