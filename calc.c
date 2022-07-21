#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functioncalc.h"



struct info_cal
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











int main (int argc, char *argv[]){

	GtkApplication *app;
	int status;
	
	struct data *d = g_malloc (sizeof (struct info_cal));
	
	app = gtk_application_new ("org.gtk.minimal", G_APPLICATION_FLAGS_NONE);
	
	g_signal_connect (app, "activate", G_CALLBACK (make_window), (gpointer) d);
	
	status = g_application_run (G_APPLICATION (app), argc, argv);
	
	g_object_unref (app);

	g_free (d);
	
	return status;



}


