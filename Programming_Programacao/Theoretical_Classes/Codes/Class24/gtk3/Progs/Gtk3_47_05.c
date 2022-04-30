#include <stdlib.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>

#include "Gtk3_CssAux.h"

#define POS_INIT_X     200.0
#define POS_INIT_Y     200.0
#define VELOC_INIT_X     3.0
#define VELOC_INIT_Y     2.0
#define BORDER_X        10.0
#define BORDER_Y        10.0

gchar  *winTitle    = "Gtk3-Cairo: Move seta com frame com scales RGB (show/hide)" ;
glong   win_xlen    = 650 ;
glong   win_ylen    = 450 ;

typedef struct
{
  GdkColor window   ;
  GdkColor scale[4] ;
  GdkColor zero     ;
  GdkColor frameRGB ;
  GdkColor labelRGB ;
  GdkColor bt_hide  ;
  GdkColor bt_exit  ;
  GdkColor black    ;
} ProgCores ;

typedef struct
{
  GtkWidget      *window     ;    // widget da window
  GtkWidget      *mbox       ;    // caixa central
  GtkWidget      *frameRGB   ;    // widget do frame RGB
  GtkWidget      *hbox2      ;    // caixa do frame RGB
  GtkWidget      *darea      ;    // drawing area
  GtkAdjustment  *adj[4]     ;    // adjustments para as escalas
  GtkWidget      *scale[4]   ;    // escalas para as cores
  GtkWidget      *moveBox    ;    // caixa em que se ve o movimento
  GtkWidget      *hsep       ;    // separador da caixa de baixo
  GtkWidget      *hboxb      ;    // caixa de baixo
  GtkWidget      *bt_hide    ;    // botao "hide" / "show"
  GtkWidget      *bt_exit    ;    // botao "exit"
  ProgCores       cor        ;    // cores

  gboolean        move       ;    // Permite so haver movimento com o timer
  gboolean        show_hide  ;    // Permite apagar ou nao o controle RGB
  double          v[2]       ;    // Velocidades em "x" e "y"
  double          pos[2]     ;    // Posicoes em "x" e "y"
  double          border[2]  ;    // Margens em "x" e "y"
} ProgInfo ;

gchar *cssData = "\n"
  "#window {background-color: Black;}\n"
  ".btMain {padding: 0px;}\n"
  ".btMain label {background-color: #CD7F32; color: Black; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n"
  ".frameRGB {background-color: #FFE4C4; color: Magenta; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n"
  ".frameRGB border {color: Magenta; border-width: 2px; border-color: Magenta;}\n"
  "scale {-range-slider-width: 18px; -range-trough-border: 1px; -scale-slider-length: 14px;}\n"
  ".scalePos {color: Tan; font-family: Tahoma; font-weight: bold; font-size: 12px; border-radius: 8px; border-width: 0px; padding: 1px;}\n"
  ".scalePos.trough.horizontal {margin: 6px 0px 6px 0px; border: 0px; background-color: Tan;}"
  ".scaleR {color: #FF0000; font-family: Tahoma; font-weight: bold; font-size: 14px; border-radius: 8px; border-width: 0px; padding: 4px;}\n"
  ".scaleR trough highlight {background-color: #FF0000;}\n"
  ".scaleG {color: #00FF00; font-family: Tahoma; font-weight: bold; font-size: 14px; border-radius: 8px; border-width: 0px; padding: 4px;}\n"
  ".scaleG trough highlight {background-color: #00FF00;}\n"
  ".scaleB {color: #0000FF; font-family: Tahoma; font-weight: bold; font-size: 14px; border-radius: 8px; border-width: 0px; padding: 4px;}\n"
  ".scaleB trough highlight {background-color: #0000FF;}\n";


void
set_hide_show (GtkWidget *widget, gpointer data)
{
  ProgInfo  *pinfo ;

  pinfo = (ProgInfo *) data;

  if (pinfo->show_hide)
    gtk_widget_hide (pinfo->frameRGB);
  else
    gtk_widget_show (pinfo->frameRGB);
  pinfo->show_hide = !pinfo->show_hide;

  gtk_widget_queue_draw (pinfo->darea);
}

gboolean
on_expose_event (GtkWidget  *widget ,
                 cairo_t    *cr     ,
                 ProgInfo   *pinfo  )
{
  double         rgb1, rgb2, rgb3 ;
  double         pos1, pos2       ;
  GtkAllocation  alloc1 ;
  
  gtk_widget_get_allocation (pinfo->darea, &alloc1);

  pos1 = gtk_adjustment_get_value (pinfo->adj[3]);
  if (pos1 > alloc1.width)
    {
      pos1 = alloc1.width;
      gtk_adjustment_set_value (pinfo->adj[3], pos1);
    }
  gtk_adjustment_set_upper (pinfo->adj[3], alloc1.width);

  rgb1 = gtk_adjustment_get_value (pinfo->adj[0]);
  rgb2 = gtk_adjustment_get_value (pinfo->adj[1]);
  rgb3 = gtk_adjustment_get_value (pinfo->adj[2]);

  cairo_set_source_rgb (cr, 1., 1., 1.);
  cairo_set_line_width (cr, 2);
  cairo_move_to (cr, 0, 3. * alloc1.height / 4.);
  cairo_line_to (cr, alloc1.width, 3. * alloc1.height / 4.);
  cairo_stroke (cr);

  cairo_set_source_rgb (cr, rgb1, rgb2, rgb3);
  
  cairo_set_line_width (cr, 5);
  pos2 = 3. * alloc1.height / 4.;
  cairo_move_to (cr, pos1, pos2);
  cairo_line_to (cr, pos1, pos2 - 40);
  cairo_stroke (cr);

  cairo_move_to(cr, pos1 - 7, pos2 - 40);
  cairo_line_to(cr, pos1 + 7, pos2 - 40);
  cairo_line_to(cr, pos1, pos2 - 55);
  cairo_line_to(cr, pos1 - 7, pos2 - 40);
  //cairo_line_to(cr, pos1 + 7, pos2 - 40);
  cairo_fill(cr);
  cairo_stroke(cr);

  pinfo->move = 0;

  return FALSE;
}

void
change_scale (GtkWidget *w, gpointer data)
{
  ProgInfo  *pinfo ;

  pinfo = (ProgInfo *) data;
  gtk_widget_queue_draw (pinfo->darea);
}

void
create_frame_color (ProgInfo *pinfo, char *title)
{
  GtkWidget  *hbox2 ;

  pinfo->frameRGB = gtk_frame_new (title);
  gtk_style_context_add_class (gtk_widget_get_style_context (pinfo->frameRGB), "frameRGB");
  gtk_frame_set_label_align (GTK_FRAME (pinfo->frameRGB), 0.5, 0.5);
  gtk_widget_set_size_request (pinfo->frameRGB, 140, -1);

  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_set_homogeneous (GTK_BOX(hbox2), TRUE);
  gtk_container_add (GTK_CONTAINER (pinfo->frameRGB), hbox2);

  pinfo->adj[2] = (GtkAdjustment *) gtk_adjustment_new (0.3, 0.0, 1.0, 0.001, 1.0, 0.0); 
  pinfo->scale[2] = gtk_scale_new (GTK_ORIENTATION_VERTICAL, pinfo->adj[2]);
  gtk_style_context_add_class (gtk_widget_get_style_context (pinfo->scale[2]), "scaleB");
  gtk_range_set_inverted (GTK_RANGE (pinfo->scale[2]), TRUE);
  gtk_scale_set_digits (GTK_SCALE (pinfo->scale[2]), 2);
  gtk_scale_set_value_pos (GTK_SCALE (pinfo->scale[2]), GTK_POS_TOP);
  gtk_scale_set_draw_value (GTK_SCALE (pinfo->scale[2]), TRUE);
  gtk_box_pack_end (GTK_BOX (hbox2), pinfo->scale[2], FALSE, TRUE, 5);

  pinfo->adj[1] = (GtkAdjustment *) gtk_adjustment_new (0.5, 0.0, 1.0, 0.001, 1.0, 0.0); 
  pinfo->scale[1] = gtk_scale_new (GTK_ORIENTATION_VERTICAL, pinfo->adj[1]);
  gtk_style_context_add_class (gtk_widget_get_style_context (pinfo->scale[1]), "scaleG");
  gtk_range_set_inverted (GTK_RANGE (pinfo->scale[1]), TRUE);
  gtk_scale_set_digits (GTK_SCALE (pinfo->scale[1]), 2);
  gtk_box_pack_end (GTK_BOX (hbox2), pinfo->scale[1], FALSE, TRUE, 5);

  pinfo->adj[0] = (GtkAdjustment *) gtk_adjustment_new (0.7, 0.0, 1.0, 0.001, 1.0, 0.0); 
  pinfo->scale[0] = gtk_scale_new (GTK_ORIENTATION_VERTICAL, pinfo->adj[0]);
  gtk_style_context_add_class (gtk_widget_get_style_context (pinfo->scale[0]), "scaleR");
  gtk_range_set_inverted (GTK_RANGE (pinfo->scale[0]), TRUE);
  gtk_scale_set_digits (GTK_SCALE (pinfo->scale[0]), 2);
  gtk_box_pack_end (GTK_BOX (hbox2), pinfo->scale[0], FALSE, TRUE, 5);
}

gboolean
on_configure_event (GtkWidget     *widget ,
                    GtkScrollType  scroll ,
                    gdouble        value  ,
                    gpointer       data   )
{
  //printf ("Scroll: %d  ;  Value: %lf\n", scroll, value);
  change_scale (widget, data);
  
  return FALSE;
}

int main(int argc, char *argv[])
{
  ProgInfo   *pinfo        ;
  GtkWidget  *vbox, *hbox1 ;

  pinfo = (ProgInfo *) calloc (1, sizeof (ProgInfo));
  pinfo->pos[0] = POS_INIT_X;
  pinfo->pos[1] = POS_INIT_Y;
  pinfo->v[0] = VELOC_INIT_X;
  pinfo->v[1] = VELOC_INIT_Y;
  pinfo->border[0] = BORDER_X;
  pinfo->border[1] = BORDER_Y;
  pinfo->show_hide = TRUE;

  gtk_init(&argc, &argv);
  create_style_from_data (cssData);

  pinfo->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (GTK_WIDGET(pinfo->window), "window");
  gtk_window_set_position (GTK_WINDOW(pinfo->window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW(pinfo->window), win_xlen, win_ylen);
  gtk_widget_set_size_request (pinfo->window, win_xlen - 50, win_ylen - 50);
  gtk_window_set_title (GTK_WINDOW(pinfo->window), winTitle);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (pinfo->window), vbox);

  pinfo->mbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (pinfo->mbox), 10);
  gtk_box_pack_start (GTK_BOX (vbox), pinfo->mbox, TRUE, TRUE, 0);

  pinfo->darea = gtk_drawing_area_new ();
  gtk_box_pack_start (GTK_BOX ( pinfo->mbox), pinfo->darea, TRUE, TRUE, 5);

  // Frame das cores
  
  create_frame_color (pinfo, " Fundo ");
  gtk_box_pack_start (GTK_BOX (pinfo->mbox), pinfo->frameRGB, FALSE, TRUE, 5);

  // Zona de baixo (separadores e botes)

  pinfo->hboxb = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (pinfo->hboxb), 2);
  gtk_box_pack_end (GTK_BOX (vbox), pinfo->hboxb, FALSE, TRUE, 5);

  pinfo->hsep = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_end (GTK_BOX (vbox), pinfo->hsep, FALSE, TRUE, 5);

  pinfo->bt_hide = gtk_button_new_with_label ("Hide");
  gtk_style_context_add_class (gtk_widget_get_style_context (pinfo->bt_hide), "btMain");
  gtk_widget_set_size_request (pinfo->bt_hide, 112, 40);
  gtk_container_set_border_width (GTK_CONTAINER (pinfo->bt_hide), 5);
  g_signal_connect (pinfo->bt_hide, "clicked", G_CALLBACK (set_hide_show), pinfo);
  gtk_box_pack_start (GTK_BOX (pinfo->hboxb), pinfo->bt_hide, FALSE, TRUE, 5);
    
  pinfo->bt_exit = gtk_button_new_with_label ("Exit");
  gtk_style_context_add_class (gtk_widget_get_style_context (pinfo->bt_exit), "btMain");
  gtk_widget_set_size_request (pinfo->bt_exit, 112, 40);
  gtk_container_set_border_width (GTK_CONTAINER (pinfo->bt_exit), 5);
  g_signal_connect (pinfo->bt_exit, "clicked", G_CALLBACK (gtk_main_quit), NULL);
  gtk_box_pack_end (GTK_BOX (pinfo->hboxb), pinfo->bt_exit, FALSE, TRUE, 5);

  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox1), 5);
  gtk_box_pack_start (GTK_BOX (pinfo->hboxb), hbox1, TRUE, TRUE, 5);

  pinfo->adj[3] = (GtkAdjustment *) gtk_adjustment_new (50.0, 0.0, 400.0, 1.0, 1.0, 0.0); 
  pinfo->scale[3] = gtk_scale_new (GTK_ORIENTATION_HORIZONTAL, pinfo->adj[3]);
  gtk_style_context_add_class (gtk_widget_get_style_context (pinfo->scale[3]), "scalePos");
  g_signal_connect (pinfo->adj[3], "value-changed", G_CALLBACK(change_scale), pinfo);
  gtk_scale_set_digits (GTK_SCALE (pinfo->scale[3]), 2);
  gtk_box_pack_start (GTK_BOX (hbox1), pinfo->scale[3], TRUE, TRUE, 0);

  gtk_widget_add_events (pinfo->window, GDK_BUTTON_PRESS_MASK);

  g_signal_connect (pinfo->darea, "draw", G_CALLBACK(on_expose_event), pinfo);
  g_signal_connect (pinfo->scale[0], "change-value", G_CALLBACK(on_configure_event), pinfo);
  g_signal_connect (pinfo->scale[1], "change-value", G_CALLBACK(on_configure_event), pinfo);
  g_signal_connect (pinfo->scale[2], "change-value", G_CALLBACK(on_configure_event), pinfo);
  g_signal_connect (pinfo->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  // Mostra e executa

  gtk_widget_show_all(pinfo->window);
  gtk_main();

  return 0;
}


