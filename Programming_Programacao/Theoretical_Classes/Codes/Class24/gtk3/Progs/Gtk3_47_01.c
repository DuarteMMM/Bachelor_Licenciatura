/*********************************************************
 *                                                       *
 *      gtk3 - Cairo: Rectangulo a mover-se numa janela  *
 *                                                       *
 *      GTK+ 3                                           *
 *      Versao: 1.0                                      *
 *      Samuel Eleuterio 2015                            *
 *                                                       *
 *********************************************************/

#include <stdlib.h>
#include <string.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>

#include "Gtk3_CssAux.h"

#define POS_INIT_X     200.0
#define POS_INIT_Y     200.0
#define VELOC_INIT_X     6.0
#define VELOC_INIT_Y     4.5
#define BORDER_X        10.0
#define BORDER_Y        10.0

gchar  *winTitle    = "Gtk3-Cairo: Frame com scales RGB" ;
glong   win_xlen    = 600 ;
glong   win_ylen    = 400 ;

typedef struct
{
  GdkRGBA scale[3] ;
  GdkRGBA zero     ;
  GdkRGBA frameRGB ;
  GdkRGBA labelRGB ;
} ProgCores ;

typedef struct
{
  GtkWidget      *window     ;    // widget da window
  GtkWidget      *darea      ;    // widget da drawing area
  GtkWidget      *frameRGB   ;    // widget do frame RGB
  GtkAdjustment  *adj[3]     ;    // adjustments para as escalas
  GtkWidget      *scale[3]   ;    // Escalas para as cores
  gboolean        move       ;    // Permite so haver movimento com o timer
  double          v[2]       ;    // Velocidades em "x" e "y"
  double          pos[2]     ;    // Posicoes em "x" e "y"
  double          border[2]  ;    // Margens em "x" e "y"      pinfo->border[1]
} ProgInfo ;

gchar *cssData = "\n"
  //"window {background-color: Black;}\n"
  ".frameRGB {color: Magenta; font-family: Tahoma; font-weight: bold; font-size: 16px;}\n"
  ".frameRGB border {color: Magenta; border-width: 2px; border-color: Magenta;}\n"
  "scale {-range-slider-width: 18px; -range-trough-border: 1px; -scale-slider-length: 14px;}\n"
  ".scaleR {color: #FF0000; font-family: Tahoma; font-weight: bold; font-size: 14px; border-radius: 8px; border-width: 0px; padding: 4px;}\n"
  ".scaleR trough highlight {background-color: #FF0000;}\n"
  ".scaleG {color: #00FF00; font-family: Tahoma; font-weight: bold; font-size: 14px; border-radius: 8px; border-width: 0px; padding: 4px;}\n"
  ".scaleG trough highlight {background-color: #00FF00;}\n"
  ".scaleB {color: #0000FF; font-family: Tahoma; font-weight: bold; font-size: 14px; border-radius: 8px; border-width: 0px; padding: 4px;}\n"
  ".scaleB trough highlight {background-color: #0000FF;}\n";


gboolean 
cb_draw_event (GtkWidget  *darea , 
               cairo_t    *cr    , 
               ProgInfo   *pinfo )
{      
  gdouble         rgb1, rgb2, rgb3 ;
  GtkAllocation   alloc1 ;

  gtk_widget_get_allocation (pinfo->darea, &alloc1);

  rgb1 = gtk_adjustment_get_value (pinfo->adj[0]);
  rgb2 = gtk_adjustment_get_value (pinfo->adj[1]);
  rgb3 = gtk_adjustment_get_value (pinfo->adj[2]);

  cairo_set_source_rgb (cr, rgb1, rgb2, rgb3);
  cairo_set_line_width (cr, 2);

  cairo_move_to (cr, pinfo->pos[0], pinfo->pos[1]);
  
  if (pinfo->move == 1)
    {
      pinfo->pos[0] = pinfo->pos[0] + pinfo->v[0];
      pinfo->pos[1] = pinfo->pos[1] + pinfo->v[1];
  
      if (pinfo->pos[0] < pinfo->border[0])
	{
          pinfo->v[0] = fabs (pinfo->v[0]);
          pinfo->pos[0] = pinfo->border[0];
	}
      if (pinfo->pos[0] > (alloc1.width - pinfo->border[0]))
	{
	  pinfo->v[0] = - fabs (pinfo->v[0]);
          pinfo->pos[0] = alloc1.width - pinfo->border[0];
	}
      if (pinfo->pos[1] < pinfo->border[1])
	{
          pinfo->v[1] = fabs (pinfo->v[1]);
          pinfo->pos[1] = pinfo->border[1];
	}
      if (pinfo->pos[1] > (alloc1.height - pinfo->border[1]))
	{
	  pinfo->v[1] = - fabs (pinfo->v[1]);
          pinfo->pos[1] = alloc1.height - pinfo->border[1];
	}
    }
  
  /* Circulo */

  cairo_arc (cr, pinfo->pos[0], pinfo->pos[1], 10, 0., 2. * M_PI);
  cairo_fill (cr);
  cairo_stroke (cr);

  pinfo->move = 0;

  return FALSE;
}

gboolean
time_handler (ProgInfo *pinfo)
{
  if((!GTK_IS_WIDGET(pinfo->darea)) || (!gtk_widget_get_window (pinfo->darea)))
    return FALSE;

  pinfo->move = 1;
  gtk_widget_queue_draw (pinfo->darea);

  return TRUE;
}

void
create_frame_color (ProgInfo  *pinfo ,
		    char      *title )
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

int main(int argc, char *argv[])
{
  GtkWidget  *mbox, *vbox ;
  ProgInfo   *pinfo       ;

  pinfo = (ProgInfo *) calloc (1, sizeof (ProgInfo));
  pinfo->pos[0] = POS_INIT_X;
  pinfo->pos[1] = POS_INIT_Y;
  pinfo->v[0] = VELOC_INIT_X;
  pinfo->v[1] = VELOC_INIT_Y;
  pinfo->border[0] = BORDER_X;
  pinfo->border[1] = BORDER_Y;

  gtk_init(&argc, &argv);
  create_style_from_data (cssData);

  pinfo->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position (GTK_WINDOW(pinfo->window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW(pinfo->window), win_xlen, win_ylen);
  gtk_widget_set_size_request (pinfo->window, win_xlen - 50, win_ylen - 50);
  gtk_window_set_title (GTK_WINDOW(pinfo->window), winTitle);

  mbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (mbox), 10);
  gtk_container_add (GTK_CONTAINER (pinfo->window), mbox);

  pinfo->darea = gtk_drawing_area_new ();
  gtk_box_pack_start (GTK_BOX (mbox), pinfo->darea, TRUE, TRUE, 5);

  vbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (mbox), vbox, FALSE, TRUE, 0);

  create_frame_color (pinfo, " R G B ");
  gtk_box_pack_start (GTK_BOX (vbox), pinfo->frameRGB, TRUE, TRUE, 5);

  //gtk_widget_add_events (pinfo->window, GDK_BUTTON_PRESS_MASK);

  g_signal_connect (G_OBJECT(pinfo->darea), "draw", G_CALLBACK(cb_draw_event), pinfo);  
  g_signal_connect (pinfo->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  
  g_timeout_add (50, (GSourceFunc) time_handler, pinfo);

  gtk_widget_show_all (pinfo->window);
  gtk_main();

  return 0;
}
/*
  ".scaleR3 { position: absolute;  top: 50%;  transform: translateY(-50%);  height: 8px;  border-style: solid;  border-width: 2px;  border-radius: 4px;  left: 0; right: 0;  border-color: #a7a7a7;  background-color: #b1b3b1;  background-image: linear-gradient(to bottom, #a7a7a7, #bebebe);  box-shadow: 0 1px 0 rgba(255,255,255,0.8);}"

".scaleR2 {  position: absolute;  width: 48px; height: 48px;  top: 50%;  left: 0%;  transform: translateY(-50%) translateX(0%) rotate(0deg);  border-style: solid;  border-width: 2px;  border-color: #a7a7a7;  border-radius: 0;  background-color: #e0e0e0;  background-image: linear-gradient(135deg, #ededed, #d3d3d3);  box-shadow: inset 0 0 0 2px rgba(255,255,255,0.2),              2px 2px 2px rgba(0,0,0,0.1);}"

 */
