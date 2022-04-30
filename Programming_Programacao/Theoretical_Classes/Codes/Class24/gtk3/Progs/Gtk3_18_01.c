/*
   gtk3_02_04.c

   Exemplo inspirado no 'The GTK+ tutorial' (First Programs)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gtk/gtk.h>

#include "Gtk3_CssAux.h"

GtkWindowType       winType     = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos      = GTK_WIN_POS_CENTER  ;

gchar              *winTitle    = "GTK-Ex: box, buttons, label" ;
gchar               chlabel[32] = "Valor actual: " ;
gchar              *chhex       = "0123456789ABCDEF" ;

gint                xlen        = 450 ;
gint                ylen        = 280 ;
gint                contador    = 0   ;
gint                len_chlabel       ;

#if GTK_CHECK_VERSION(3,22,0)
gchar cssData[128] = "label {color: #000000; font-family: Tahoma; font-weight: bold; font-size: 16px;}" ;
#else
gchar cssData[128] = "GtkLabel {color: #000000; font-family: Tahoma; font-weight: bold; font-size: 16px;}" ;
#endif

void
nova_cor_rand (void)
{
  int    n1, n2   ;
  char  *ch1      ;

  ch1 = strstr (cssData, "#");
  for (n1 = 1 ; n1 <= 6 ; ++n1)
    {
      n2 = rand () % 16;
      
      ch1[n1] = chhex[n2];
    }
  
  create_style_from_data (cssData);
}

gboolean 
cb_plus (GtkWidget *widget , 
         gpointer   label  )
{
  ++contador;
  sprintf (&chlabel[len_chlabel], "%d", contador);

  nova_cor_rand ();
  gtk_label_set_text(label, chlabel);

  return FALSE;
}

gboolean 
cb_minus (GtkWidget *widget , 
          gpointer   label  )
{
  --contador;
  sprintf (&chlabel[len_chlabel], "%d", contador);

  nova_cor_rand ();
  gtk_label_set_text(label, chlabel);

  return FALSE;
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *label ;
  GtkWidget *bplus, *bminus, *image1 ;
  GdkPixbuf *pixbuf ;

  srand (time(NULL));

  len_chlabel = strlen (chlabel);
  sprintf (&chlabel[len_chlabel], "%d", contador);

  gtk_init (&argc, &argv);
  nova_cor_rand ();

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), xlen, ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX(vbox), hbox1, TRUE, TRUE, 0);

  label = gtk_label_new (chlabel);
  gtk_widget_set_name (GTK_WIDGET(label), "label1");
  gtk_box_pack_start (GTK_BOX(hbox1), label, TRUE, FALSE, 0);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 20);

  pixbuf = gdk_pixbuf_new_from_file ("images/casa_100.jpg", NULL);
  image1 = gtk_image_new_from_pixbuf (pixbuf);
  g_object_unref (pixbuf);

  bminus = gtk_button_new ();
  gtk_button_set_image (GTK_BUTTON(bminus), image1);
  g_signal_connect (bminus, "clicked", G_CALLBACK(cb_minus), label);
  gtk_box_pack_start (GTK_BOX(hbox2), bminus, FALSE, TRUE, 20);

  pixbuf = gdk_pixbuf_new_from_file ("images/cacto_100.jpg", NULL);
  image1 = gtk_image_new_from_pixbuf (pixbuf);
  g_object_unref (pixbuf);

  bplus = gtk_button_new ();
  gtk_button_set_image (GTK_BUTTON(bplus), image1);
  g_signal_connect (bplus, "clicked", G_CALLBACK(cb_plus), label);
  gtk_box_pack_end (GTK_BOX(hbox2), bplus, FALSE, TRUE, 20);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
