#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct _info
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



}info;





gboolean zero_to_nine_keys_callback ( GtkWidget *widget, GdkEventKey *event );

void plus_calculation (GtkButton *entry, gpointer data) {


	char output_buffer[19] = {0};
	char history_buffer[20]= {0};
	//char newline[]={"\n"};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));

	
	//g_print("%s\n", text);
	
	float x = atof(text);
	float y = atof(text2);
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 2 is empty");
	}
	
	else {
	g_print("%f\nplus\n%f\nresult\n%f\n", x,y,x+y);
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%f\n", x+y);
	strncpy (history_buffer, output_buffer, strlen(output_buffer));
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	}
	
	
	gtk_label_set_text (GTK_LABEL (info.history_label), history_buffer);
	


}

void minus_calculation (GtkButton *entry, gpointer data) {


	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));
	
	//g_print("%s\n", text);
	
	float x = atof(text);
	float y = atof(text2);
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 2 is empty");
	}
	
	else {
	
	g_print("%f\nminus\n%f\nresult\n%f\n", x,y,x-y);
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%f\n", x-y);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}


}

void multiplied_calculation (GtkButton *entry, gpointer data) {


	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));
	
	
	long double x = atof(text);
	long double y = atof(text2);
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 2 is empty");
	}
	
	else {
	
	g_print("%Lf\nmultiplied\n%Lf\nresult\n%Lf\n", x,y,x*y);
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%Lf", x*y);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	}
	


}

void division_calculation (GtkButton *entry, gpointer data) {


	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));
	
	
	float x = atof(text);
	float y = atof(text2);
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Operand 2 is empty");
	}
	
	
	else if (y==0.000000){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Division by zero is undefined");
	
	}
	
	
	else{
	
	g_print("%.5f\ndivided\n%f\nresult\n%f\n", x,y,x/y);
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%0.5f", x/y);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}


}

void squared_calculation (GtkButton *entry, gpointer data) {

	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));
	float x = atof(text);
	float y=atof(text2);
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "You should write in operand one or in operand 2");
	
	}
	
	else if (strlen(text) == 0){
	
	g_print("%.0f\nsquared is \n%.0f\n", y,y*y);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%.0f\n", y*y);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}
	
	else if (strlen(text2) == 0){
	
	g_print("%.0f\nsquared is \n%.0f\n", x,x*x);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%.0f\n", x*x);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "you should write only in one operand!");
	
	}
	

}

void square_root_calculation (GtkButton *entry, gpointer data){


	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));
	long double x = atof(text);
	long double y=atof(text2);
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "You should write in operand one or in operand 2");
	
	}
	
	else  if (strlen(text) == 0){
	
	
	//funtion for y
	
	long double result, temp;
	result = y /2;
	temp=0;
	
	while(result != temp){
	
	temp = result;
	result = (y/ temp + temp) /2;
	}
	
	g_print("the sequare root of %.0Lf\n is \n%.0Lf\n", y,result);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%.5Lf\n",result);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}
	
	else if (strlen(text2) == 0){
	
	//funtion for x
	
	long double result2, temp2;
	result2 = x/2;
	temp2=0;
	
	while(result2 != temp2){
	
	temp2 = result2;
	result2 = (x/ temp2 + temp2) /2;
	}
	
	g_print("the sequare root of %.0Lf\n is \n%.5Lf\n", x,result2);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%0.5Lf\n",result2);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "you should write only in one operand!");
	
	}

}
void comma_button (GtkButton *button, gpointer data){

	char output_buffer[19] = {0};
	char comma_buffer[]={","};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));
	
	
	
	
	 if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "You should write in operand one ");
	
	}
	
	
	
	else if (strlen(text2) == 0){
	
	sprintf(output_buffer, "%s", text);
	strcat(output_buffer,comma_buffer);
	gtk_entry_set_text(GTK_ENTRY(info.textentry), output_buffer);
	}
	
	else if (strlen(text) !=0) {
	
	sprintf(output_buffer, "%s", text2);
	strcat(output_buffer,comma_buffer);
	gtk_entry_set_text(GTK_ENTRY(info.textentry2), output_buffer);
	}
	
	else {
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "Please clear the secound operand and beginn with the first operand");
	}
	
	
}



void backspace_operation (GtkButton *entry, gpointer data){

	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));


	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "You should write in operand one or in operand 2");
	
	}

	else if (strlen(text)!=0 && strlen(text2) == 0){
	
	sprintf(output_buffer, "%s", text);
	output_buffer[strlen(output_buffer)-1] = '\0';
	gtk_entry_set_text(GTK_ENTRY(info.textentry), output_buffer);
	}
	
	else if ((strlen(text2)!=0 && strlen(text) == 0) || strlen(text2)!=0 ){
	
	sprintf(output_buffer, "%s", text2);
	output_buffer[strlen(output_buffer)-1] = '\0';
	gtk_entry_set_text(GTK_ENTRY(info.textentry2), output_buffer);
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "You should write in operand one or in operand 2");
	}

}

void percent_operation (GtkButton *entry, gpointer data){
	
	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(info.textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(info.textentry2));
	long double x = atof(text);
	long double y=atof(text2);
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "You should write in operand one or in operand 2");
	
	}
	
	else  if (strlen(text) == 0){
	
	
	//funtion for y
	
	
	
	g_print("the precent of %.0Lf\n is \n%.5Lf\n", y,y/100);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%.5Lf\n",y/100);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}
	
	else if (strlen(text2) == 0){
	
	//funtion for x
	
	
	g_print("the precent of %.0Lf\n is \n%.5Lf\n", x,x/100);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	sprintf(output_buffer, "%.5Lf\n",x/100);
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), output_buffer);
	
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "you should write only in one operand!");
	
	}
	

}



void clear_operation (GtkButton *entry, gpointer data){

	
	
	gtk_entry_set_text(GTK_ENTRY(info.textentry), "");
	gtk_entry_set_text(GTK_ENTRY(info.textentry2), "");
	gtk_entry_set_text(GTK_ENTRY(info.textentry3), "");
	
	
}


void close_window(){

	gtk_main_quit();

}

void make_window(){

	
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	
	gtk_window_set_title(GTK_WINDOW(window), "My Text APP");
	
	GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 4);
	 
	gtk_container_add(GTK_CONTAINER(window), vbox);
	
	info.op1_label= gtk_label_new("\nOperand 1: ");
	
	gtk_box_pack_start(GTK_BOX(vbox), info.op1_label, FALSE, TRUE, 4);
	
	info.textentry= gtk_entry_new();
	
	gtk_box_pack_start(GTK_BOX(vbox), info.textentry, FALSE, FALSE, 4);
	
	gtk_entry_set_max_length( GTK_ENTRY(info.textentry), 8);
	
	gtk_entry_set_alignment (GTK_ENTRY(info.textentry), 0.05f);
	
	info.op2_label = gtk_label_new("\nOperand 2: ");
	
	gtk_box_pack_start(GTK_BOX(vbox), info.op2_label, FALSE, TRUE, 4);
	
	info.textentry2 = gtk_entry_new();
	
	
	gtk_box_pack_start(GTK_BOX(vbox), info.textentry2, FALSE, FALSE, 4);
	
	gtk_entry_set_max_length( GTK_ENTRY(info.textentry2), 8);
	
	gtk_entry_set_alignment (GTK_ENTRY(info.textentry2), 0.05f);
	
	info.res_label= gtk_label_new("\nresult: ");
	
	
	
	
	gtk_box_pack_start(GTK_BOX(vbox), info.res_label, FALSE, TRUE, 4);
	
	info.textentry3= gtk_entry_new();
	
	gtk_box_pack_start(GTK_BOX(vbox), info.textentry3, FALSE, FALSE, 4);
	
	gtk_entry_set_max_length( GTK_ENTRY(info.textentry3), 100);
	
	gtk_entry_set_alignment (GTK_ENTRY(info.textentry3), 0.05f);
	
	
	info.history_label= gtk_label_new("\nhistory: ");
	
	gtk_box_pack_start(GTK_BOX(vbox), info.history_label, FALSE, TRUE, 4);
	
	

	
	info.grid= gtk_grid_new();
	gtk_grid_set_column_homogeneous (GTK_GRID(info.grid), TRUE);
	gtk_grid_set_column_spacing (GTK_GRID(info.grid), 5);
	gtk_grid_set_row_spacing (GTK_GRID(info.grid), 3);
	
	gtk_box_pack_start(GTK_BOX(vbox), info.grid, FALSE, TRUE, 100);
	
	
	info.button[0] = gtk_button_new_with_label ("C");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[0]), 0);
	gtk_widget_set_size_request(info.button[0], 50,50);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[0], 0,0,3,1);
	
	info.button[1] = gtk_button_new_with_label ("√");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[1]), 0);
	gtk_widget_set_size_request(info.button[1], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[1], 0,4,1,1);
	
	info.button[2] = gtk_button_new_with_label ("÷");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[2]), 0);
	gtk_widget_set_size_request(info.button[2], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[2], 0,1,1,2);
	
	info.button[3] = gtk_button_new_with_label ("*");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[3]), 0);
	gtk_widget_set_size_request(info.button[3], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[3], 1,1,1,2);
	
	info.button[4] = gtk_button_new_with_label (",");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[4]), 0);
	gtk_widget_set_size_request(info.button[4], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[4], 1,4,1,1);
	
	info.button[5] = gtk_button_new_with_label ("-");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[5]), 0);
	gtk_widget_set_size_request(info.button[5], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[5], 2,1,1,2);
	
	
	info.button[6] = gtk_button_new_with_label ("x²");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[6]), 0);
	gtk_widget_set_size_request(info.button[6], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[6], 3,0,1,1);
	
	info.button[7] = gtk_button_new_with_label ("+");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[7]), 0);
	gtk_widget_set_size_request(info.button[7], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[7], 3,1,1,2);
	
	
	info.button[8] = gtk_button_new_with_label ("⌫");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[8]), 0);
	gtk_widget_set_size_request(info.button[8], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[8], 2,4,1,1);
	
	info.button[9] = gtk_button_new_with_label ("%");
	gtk_container_set_border_width( GTK_CONTAINER(info.button[9]), 0);
	gtk_widget_set_size_request(info.button[9], 100,100);
	gtk_grid_attach(GTK_GRID(info.grid), info.button[9], 3,4,1,1);
	
	
	

	
g_signal_connect_swapped ( info.textentry, "activate", G_CALLBACK ( zero_to_nine_keys_callback ), info.textentry );
g_signal_connect_swapped ( info.textentry, "key_press_event", G_CALLBACK ( zero_to_nine_keys_callback ), info.textentry);
	
g_signal_connect (G_OBJECT(window),"destroy", G_CALLBACK(close_window), NULL);
	
g_signal_connect_swapped ( info.textentry2, "activate", G_CALLBACK ( zero_to_nine_keys_callback ), info.textentry2 );
	
g_signal_connect_swapped ( info.textentry2, "key_press_event", G_CALLBACK ( zero_to_nine_keys_callback ), info.textentry2);

g_signal_connect_swapped ( info.textentry3, "activate", G_CALLBACK ( zero_to_nine_keys_callback ), info.textentry3 );
	
g_signal_connect_swapped ( info.textentry3, "key_press_event", G_CALLBACK ( zero_to_nine_keys_callback ), info.textentry3);


g_signal_connect_swapped ( info.button[7], "clicked", G_CALLBACK ( plus_calculation), info.button[7] );
	
g_signal_connect_swapped ( info.textentry3, "key_press_event", G_CALLBACK ( plus_calculation ), info.button[7]);


g_signal_connect_swapped ( info.button[5], "clicked", G_CALLBACK ( minus_calculation), info.button[5] );
	
g_signal_connect_swapped ( info.textentry3, "key_press_event", G_CALLBACK ( minus_calculation), info.button[5]);



g_signal_connect_swapped ( info.button[3], "clicked", G_CALLBACK ( multiplied_calculation), info.button[3] );
	
g_signal_connect_swapped ( info.textentry3, "key_press_event", G_CALLBACK ( multiplied_calculation), info.button[3]);


g_signal_connect_swapped ( info.button[2], "clicked", G_CALLBACK ( division_calculation), info.button[2] );
	
g_signal_connect_swapped ( info.textentry3, "key_press_event", G_CALLBACK ( division_calculation), info.button[2]);


g_signal_connect_swapped ( info.button[0], "clicked", G_CALLBACK ( clear_operation), info.button[0] );
	
g_signal_connect_swapped ( info.textentry, "activate", G_CALLBACK ( clear_operation), info.button[0]);


g_signal_connect_swapped ( info.button[6], "clicked", G_CALLBACK ( squared_calculation), info.button[6] );
	
g_signal_connect_swapped ( info.textentry, "activate", G_CALLBACK ( squared_calculation), info.button[6]);

g_signal_connect_swapped ( info.button[1], "clicked", G_CALLBACK (square_root_calculation), info.button[1] );
	
g_signal_connect_swapped ( info.textentry, "activate", G_CALLBACK ( square_root_calculation), info.button[1]);


g_signal_connect_swapped ( info.button[4], "clicked", G_CALLBACK (comma_button), info.button[4] );
	
g_signal_connect_swapped ( info.textentry, "activate", G_CALLBACK ( comma_button), info.button[4]);



g_signal_connect_swapped ( info.button[8], "clicked", G_CALLBACK (backspace_operation), info.button[8] );
	
g_signal_connect_swapped ( info.textentry, "activate", G_CALLBACK ( backspace_operation), info.button[8]);


g_signal_connect_swapped ( info.button[9], "clicked", G_CALLBACK (percent_operation), info.button[9] );
	
g_signal_connect_swapped ( info.textentry, "activate", G_CALLBACK ( percent_operation), info.button[9]);



	//g_signal_connect (info.button[7],"clicked", G_CALLBACK(calculate), NULL);
	//g_signal_connect_swapped (info.textentry,"activate", G_CALLBACK(calculate), NULL);
	g_signal_connect (G_OBJECT(window),"destroy", G_CALLBACK(close_window), NULL);
	
gtk_widget_show_all(window);
}


int main (int argc, char *argv[]){

	gtk_init(&argc, &argv);
	
	make_window();





	gtk_main();
	return 0; 
}

gboolean zero_to_nine_keys_callback ( GtkWidget *widget, GdkEventKey *event )
{
    ( void ) widget;
    int keys[14] =
    {
        GDK_KEY_0, GDK_KEY_1, GDK_KEY_2, GDK_KEY_3, GDK_KEY_4,
        GDK_KEY_5, GDK_KEY_6, GDK_KEY_7, GDK_KEY_8, GDK_KEY_9,
        GDK_KEY_BackSpace, GDK_KEY_comma, GDK_KEY_minus, GDK_KEY_plus

    };

    for ( guint i = 0 ; i < 14 ; i++ )
    {
        if ( event->keyval == keys[i] )
        {
          
            return FALSE;
        }
    }

    return TRUE;
}
