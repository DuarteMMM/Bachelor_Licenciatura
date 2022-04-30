/*****************************************************
 *                                                   *
 *      Menu                                         *
 *                                                   *
 *      GTK+ 3                                       *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2014                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

GtkWindowType       winType     = GTK_WINDOW_TOPLEVEL ;
GtkWindowPosition   winPos      = GTK_WIN_POS_CENTER  ;

gchar              *winTitleDef = "Criação de um menus" ;
gchar              *winTitle ;
gchar               chlabel[32] = "Valor actual: " ;

gint                xlen        = 350 ;
gint                ylen        = 200 ;
gint                contador    = 0   ;
gint                len_chlabel       ;


void
cb_plus (GtkWidget *widget , 
         gpointer   label  )
{
  ++contador;
  sprintf (&chlabel[len_chlabel], "%d", contador);
  gtk_label_set_text(label, chlabel);
}

void
cb_minus (GtkWidget *widget , 
          gpointer   label  )
{
  --contador;
  sprintf (&chlabel[len_chlabel], "%d", contador);
  gtk_label_set_text(label, chlabel);
}

GtkWidget *
cria_toolbar (void)
{
  GtkWidget *toolbar ;
  GtkToolItem *tb_new, *tb_open, *tb_save, *tb_sep, *tb_exit ;

  toolbar = gtk_toolbar_new ();
  gtk_toolbar_set_style (GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
  gtk_container_set_border_width(GTK_CONTAINER (toolbar), 2);

  tb_new = gtk_tool_button_new (NULL, "New");
  gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(tb_new), "document-new");
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_new, -1);

  tb_open = gtk_tool_button_new (NULL, "Open");
  gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(tb_open), "document-open");
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_open, -1);

  tb_save = gtk_tool_button_new (NULL, "Save");
  gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(tb_save), "document-save");
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_save, -1);

  tb_sep = gtk_separator_tool_item_new ();
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_sep, -1); 

  tb_exit = gtk_tool_button_new (NULL, "Save");
  gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(tb_exit), "application-exit");
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_exit, -1);

  //gtk_box_pack_start (GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  g_signal_connect (G_OBJECT(tb_exit), "clicked", G_CALLBACK(gtk_main_quit), NULL);

  return toolbar;
}


int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *hbox1, *hbox2, *bplus, *bminus, *label, *toolbar ;

  len_chlabel = strlen (chlabel);
  sprintf (&chlabel[len_chlabel], "%d", contador);

  gtk_init (&argc, &argv);

  window = gtk_window_new (winType);
  gtk_window_set_default_size (GTK_WINDOW(window), xlen, ylen);
  gtk_window_set_title (GTK_WINDOW(window), winTitle);
  gtk_window_set_position (GTK_WINDOW(window), winPos);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  // Cria toolbar

  toolbar = cria_toolbar();
  gtk_box_pack_start (GTK_BOX(vbox), toolbar, FALSE, FALSE, 3);

  // label, buttons

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX(vbox), hbox1, TRUE, TRUE, 0);

  label = gtk_label_new (chlabel);
  gtk_box_pack_start (GTK_BOX(hbox1), label, TRUE, FALSE, 0);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(vbox), hbox2, FALSE, TRUE, 20);

  bminus = gtk_button_new_with_label ("-");
  gtk_widget_set_size_request (bminus, 80, 35);
  g_signal_connect (bminus, "clicked", G_CALLBACK(cb_minus), label);
  gtk_box_pack_start (GTK_BOX(hbox2), bminus, FALSE, TRUE, 20);

  bplus = gtk_button_new_with_label ("+");
  gtk_widget_set_size_request (bplus, 80, 35);
  g_signal_connect (bplus, "clicked", G_CALLBACK(cb_plus), label);
  gtk_box_pack_end (GTK_BOX(hbox2), bplus, FALSE, TRUE, 20);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
