/*****************************************************
 *                                                   *
 *      Sair com Pergunta                            *
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

gchar              *winTitle = "Gtk3: Sair com butão imagem 'jpg'" ;

int                 win_xlen = 600 ;
int                 win_ylen = 400 ;

gchar *cssData = "#window {background-color: Wheat1;}\n"
                 "#label3 {color: blue; font-family: Tahoma; font-weight: bold; font-size: 14px;}\n"
                 "#label2 {color: magenta; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n"
                 "#label1 {color: #ab0567; font-family: Tahoma; font-weight: bold; font-size: 18px;}\n";


void
set_name_labels (GtkWidget *box, int nivel)
{
  int        i1        ;
  GtkWidget *w1        ;
  GList     *gl1, *gl2 ;

  gl1 = gl2 = gtk_container_get_children (GTK_CONTAINER(box));

  i1 = 0;
  while (gl1)
    {
      w1 = gl1->data;
      if ((nivel == 3) && (!GTK_IS_BOX(w1)))
	gtk_widget_set_name (GTK_WIDGET(w1), "label3");

      printf ("%2d.%2d - w1: %p (%d)\n", nivel, i1, w1, GTK_IS_BOX(w1));
      if (GTK_IS_BOX(w1) && (nivel < 4))
	set_name_labels (w1, nivel+1);
      gl1 = gl1->next;
      ++i1;
    }
 
  g_list_free (gl2);
}

gboolean
faz_pergunta (GtkWidget *win) 
{

  GtkWidget *dialog, *label;
  gchar *message = "Quer Sair?";
  gint  resultado ;
   
  dialog = gtk_dialog_new_with_buttons ("Message", GTK_WINDOW(win), 
					GTK_DIALOG_DESTROY_WITH_PARENT,
					"_Yes", GTK_RESPONSE_ACCEPT,
					"_Cancel", GTK_RESPONSE_REJECT,
					NULL);
  gtk_window_set_default_size (GTK_WINDOW(dialog), 300, 300);
  gtk_window_set_modal (GTK_WINDOW(dialog), TRUE);

  label = gtk_label_new (message);
  gtk_widget_set_name (GTK_WIDGET(label), "label2");
  gtk_box_pack_start (GTK_BOX(gtk_bin_get_child (GTK_BIN(dialog))), label, TRUE, FALSE, 0);
  gtk_widget_show_all (dialog);
  set_name_labels (gtk_bin_get_child (GTK_BIN(dialog)), 1);

  resultado = gtk_dialog_run (GTK_DIALOG(dialog));
  g_print ("Resultado: %d\n", resultado);
  gtk_widget_destroy (dialog);

  if (resultado == GTK_RESPONSE_ACCEPT)
    return TRUE;
  else
    return FALSE;
}

void
Teste_BotaoSair (GtkWidget *w, GtkWidget *win ) 
{
  gboolean teste ;

  teste = faz_pergunta (win);
  if (!teste)
    return;

  gtk_main_quit();
}

gboolean
Teste_DeleteEvent (GtkWidget *w     ,
		   GdkEvent  *event ,
		   GtkWidget *win   ) 
{
  gboolean teste ;

  teste = faz_pergunta (win);
  if (!teste)
    return TRUE;

  // Nota se se descomentar o callback associado a "destroy" 
  // a linha seguinte deve ser retirada

  gtk_main_quit();

  return FALSE;
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *qmessage, *label, *image1 ;
  GdkPixbuf *pixbuf ;

  gtk_init (&argc, &argv);
  create_style_from_data (cssData);

  window = gtk_window_new (winType);
  gtk_widget_set_name (GTK_WIDGET(window), "window");
  gtk_window_set_default_size (GTK_WINDOW(window), win_xlen, win_ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  //g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect (G_OBJECT(window), "delete_event", G_CALLBACK(Teste_DeleteEvent), window);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  // label, button

  label = gtk_label_new ("Teste de Saida");
  gtk_widget_set_name (GTK_WIDGET(label), "label1");
  gtk_box_pack_start (GTK_BOX(vbox), label, FALSE, TRUE, 20);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER (vbox), hbox1);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 20);

  pixbuf = gdk_pixbuf_new_from_file ("images/casa_100.jpg", NULL);
  image1 = gtk_image_new_from_pixbuf (pixbuf);

  qmessage = gtk_button_new ();
  gtk_button_set_image (GTK_BUTTON(qmessage), image1);
  g_object_unref (pixbuf);
  g_signal_connect (qmessage, "clicked", G_CALLBACK (Teste_BotaoSair), window);
  gtk_box_pack_end (GTK_BOX (hbox2), qmessage, FALSE, TRUE, 30);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
