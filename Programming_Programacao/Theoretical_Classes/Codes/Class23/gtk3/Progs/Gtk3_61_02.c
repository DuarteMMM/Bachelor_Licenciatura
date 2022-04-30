/*****************************************************
 *                                                   *
 *      Pergunta e duas respostas                    *
 *                                                   *
 *      GTK+ 3                                       *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2015                        *
 *                                                   *
 *****************************************************/

#include <gtk/gtk.h>

#include "Gtk3_CssAux.h"

GtkWindowType       winType  = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos   = GTK_WIN_POS_CENTER  ;

gchar              *winTitle = "GTK3: Pergunta e Duas Respostas (Sim / Não)" ;

int                 win_xlen = 600 ;
int                 win_ylen = 400 ;

gchar *cssData = "window {background-color: Wheat1;}\n"
                 "label {color: #ab0567; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n";


void
cb_dialog (GtkWidget *w, GtkWidget *win) 
{

  GtkWidget *dialog, *label;
  gchar     *message = "Quer dizer 'Sim' ou 'Não'?";
  gchar     *bt_label = "   _Sim...   ";
  gint       resultado ;
   
  dialog = gtk_dialog_new_with_buttons ("Message", GTK_WINDOW(win), 
					GTK_DIALOG_DESTROY_WITH_PARENT,
					bt_label, GTK_RESPONSE_ACCEPT,
					"_Não", GTK_RESPONSE_REJECT,
					NULL);
  gtk_window_set_default_size (GTK_WINDOW(dialog), 400, 300);
  gtk_window_set_modal (GTK_WINDOW(dialog), TRUE);

  label = gtk_label_new (message);
  gtk_box_pack_start (GTK_BOX(gtk_bin_get_child (GTK_BIN(dialog))), label, TRUE, FALSE, 0);
  gtk_widget_show_all (dialog);

  resultado = gtk_dialog_run (GTK_DIALOG(dialog));
  //g_print ("Resultado: %d\n", resultado);
  gtk_widget_destroy (dialog);

  if (resultado == GTK_RESPONSE_ACCEPT)
    g_print ("Resultado (%d): (Sim)\n", resultado);
  else if (resultado == GTK_RESPONSE_REJECT)
    g_print ("Resultado (%d): (Não)\n", resultado);
  else
    g_print ("Resultado (%d): Não houve resposta...\n", resultado);
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *qmessage, *label ;

  gtk_init (&argc, &argv);
  create_style_from_data (cssData);

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), win_xlen, win_ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  // label, button

  label = gtk_label_new ("Pergunta...");
  gtk_box_pack_start (GTK_BOX(vbox), label, FALSE, TRUE, 20);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER (vbox), hbox1);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 20);

  qmessage = gtk_button_new_with_label ("Pergunta");
  gtk_widget_set_size_request (qmessage, 100, 20);
  g_signal_connect (qmessage, "clicked", G_CALLBACK(cb_dialog), window);
  gtk_box_pack_end (GTK_BOX(hbox2), qmessage, FALSE, TRUE, 30);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
