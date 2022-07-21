#ifndef _functionalcalc_
#define _functionalcalc_
#include <gtk/gtk.h>

struct info
{

	
	GtkWidget *op1_label;
	GtkWidget *textentry;
	GtkWidget *op2_label;
	GtkWidget *res_label;
	GtkWidget *textentry2;
	GtkWidget *textentry3;
	GtkWidget *button[11];
	GtkWidget *grid;
	GtkWidget *history_label;
	GtkWidget *history_label2;
	GtkWidget *history_label3;

};

gboolean zero_to_nine_keys_callback ( GtkWidget *widget, GdkEventKey *event );
 void plus_calculation (GtkButton *entry, gpointer data);
 void minus_calculation (GtkButton *entry, gpointer data);
 void multiplied_calculation (GtkButton *entry, gpointer data);
 void division_calculation (GtkButton *entry, gpointer data);
 void squared_calculation (GtkButton *entry, gpointer data);
 void square_root_calculation (GtkButton *entry, gpointer data);
 void comma_button (GtkButton *button, gpointer data);
 void percent_operation (GtkButton *entry, gpointer data);
 void clear_operation (GtkButton *entry, gpointer data);
 void backspace_operation (GtkButton *entry, gpointer data);
 void make_window(GtkApplication *app, gpointer data);


#endif
