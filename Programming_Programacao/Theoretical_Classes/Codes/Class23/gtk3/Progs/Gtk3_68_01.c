/*****************************************************
 *                                                   *
 *      Criação de uma "About Dialog"                *
 *                                                   *
 *      GTK+ 3                                       *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2014                        *
 *                                                   *
 *****************************************************/

#include <gtk/gtk.h>

GtkWindowType       winType   = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos    = GTK_WIN_POS_CENTER  ;

gchar              *winTitle  = "Gtk3: Dialog About" ;

gint                win_xlen  = 400 ;
gint                win_ylen  = 200 ;
gint                win2_xlen = 600 ;
gint                win2_ylen = 400 ;

#ifdef _WIN32
char *fimage = "images\\ist.png" ;
#else
char *fimage = "images/ist.png" ;
#endif


void
create_about (GtkWidget *w   ,
	      gpointer   win )
{
  GtkWidget    *dialog ;
  GdkPixbuf    *image  ;
  const gchar  *authors[] = {"Author1 - Eu", "Author2 - Tu", "Author3 - Ele", NULL};
  gchar        *info      = "Isto é um programa que serve para mostrar\ncomo funciona uma \"About Dialog\".";
  gchar        *copyright = "(c) Todos os direitos reservados para Mim";
  gchar        *website   = "http://label2.tecnico.ulisboa.pt/IC";

  image = gdk_pixbuf_new_from_file (fimage, NULL);

  dialog = gtk_about_dialog_new ();
  gtk_window_set_transient_for (GTK_WINDOW(dialog), GTK_WINDOW(win));
  gtk_window_set_default_size (GTK_WINDOW(dialog), win2_xlen, win2_ylen);
  gtk_about_dialog_set_program_name (GTK_ABOUT_DIALOG(dialog), "Apresentação de About Dialog");
  gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG(dialog), copyright);
  gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG(dialog), authors);
  gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG(dialog), info);
  gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG(dialog), image);
  gtk_about_dialog_set_website (GTK_ABOUT_DIALOG(dialog), website);
  gtk_about_dialog_set_website_label (GTK_ABOUT_DIALOG(dialog), website);
  g_object_unref (image);

  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *qmessage, *label ;

  gtk_init (&argc, &argv);

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), win_xlen, win_ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  /* label, button */ 

  label = gtk_label_new ("Teste de Saida");
  gtk_box_pack_start (GTK_BOX(vbox), label, FALSE, TRUE, 20);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER(vbox), hbox1);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 20);

  qmessage = gtk_button_new_with_label (" Dialog About ");
  g_signal_connect (qmessage, "clicked", G_CALLBACK (create_about), window);
  gtk_box_pack_end (GTK_BOX(hbox2), qmessage, FALSE, TRUE, 30);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
