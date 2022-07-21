// function for the calculator

#include <gtk/gtk.h>
#include <stdlib.h>
 #include <string.h>
 #include "functioncalc.h"
 
 void plus_calculation (GtkButton *entry, gpointer data) {

	struct info *p = (struct info *) data;
	char output_buffer[25] = {0};
	static char history_buffer[3][25] = { 0 };
	//char newline[]={"\n"};
	
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	
	

	
	//g_print("%s\n", text);
	
	float x = atof(text);
	float y = atof(text2);
	static int i=0;
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 2 is empty");
	}
	
	else {
	g_print("%f\nplus\n%f\nresult\n%f\n", x,y,x+y);
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%f\n", x+y);
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	}
	strncpy (history_buffer[i], output_buffer, strlen(output_buffer));
	
	gtk_label_set_text (GTK_LABEL (p->history_label), history_buffer[0]);
	gtk_label_set_text (GTK_LABEL (p->history_label2), history_buffer[1]);
	gtk_label_set_text (GTK_LABEL (p->history_label3), history_buffer[2]);
	
	
	i++;
	if (i ==3){
	i=0;
	for (int j = 0; j< 25; j++){
	for (int k = 0; k < 3 ; k++){
		history_buffer[k][j] = 0;
		}
				     }
	}
	
	
	
	


}

void minus_calculation (GtkButton *entry, gpointer data) {

	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	static char history_buffer2[3][25];
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	
	//g_print("%s\n", text);
	
	float x = atof(text);
	float y = atof(text2);
	static int n=0;
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 2 is empty");
	}
	
	else {
	
	g_print("%f\nminus\n%f\nresult\n%f\n", x,y,x-y);
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%f\n", x-y);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
	}
	strcpy (history_buffer2[n], output_buffer);
	
	gtk_label_set_text (GTK_LABEL (p->history_label), history_buffer2[0]);
	gtk_label_set_text (GTK_LABEL (p->history_label2), history_buffer2[1]);
	gtk_label_set_text (GTK_LABEL (p->history_label3), history_buffer2[2]);
	
	
	n++;
	if (n == 3){
	n=0;
	for (int j = 0; j< 25; j++){
	for (int k = 0; k < 3 ; k++){
		history_buffer2[k][j] = 0;
		}
				     }
	}
	
	

}

void multiplied_calculation (GtkButton *entry, gpointer data) {

	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	static char history_buffer3[3][25];
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	
	
	long double x = atof(text);
	long double y = atof(text2);
	static int l=0; 
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 2 is empty");
	}
	
	else {
	
	g_print("%Lf\nmultiplied\n%Lf\nresult\n%Lf\n", x,y,x*y);
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%Lf", x*y);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	}
	
	strcpy (history_buffer3[l], output_buffer);
	
	gtk_label_set_text (GTK_LABEL (p->history_label), history_buffer3[0]);
	gtk_label_set_text (GTK_LABEL (p->history_label2), history_buffer3[1]);
	gtk_label_set_text (GTK_LABEL (p->history_label3), history_buffer3[2]);
	
	
	l++;

	if (l == 3){
	l=0;
	for (int j = 0; j< 25; j++){
	for (int k = 0; k < 3 ; k++){
		history_buffer3[k][j] = 0;
		}
				     }
	}
	


}

void division_calculation (GtkButton *entry, gpointer data) {

	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	static char history_buffer4[3][25];
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	
	
	float x = atof(text);
	float y = atof(text2);
	static int s= 0;
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 and Operand 2 are empty");
	
	}
	else if (strlen(text) == 0 ){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 1 is empty");
	}
	
	else if (strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Operand 2 is empty");
	}
	
	
	else if (y==0.000000){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Division by zero is undefined");
	
	}
	
	
	else{
	
	g_print("%.5f\ndivided\n%f\nresult\n%f\n", x,y,x/y);
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%0.5f", x/y);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
	}
	
	strcpy (history_buffer4[s], output_buffer);
	
	gtk_label_set_text (GTK_LABEL (p->history_label), history_buffer4[0]);
	gtk_label_set_text (GTK_LABEL (p->history_label2), history_buffer4[1]);
	gtk_label_set_text (GTK_LABEL (p->history_label3), history_buffer4[2]);
	
	
	s++;
	if (s == 3){
	s=0;
	for (int j = 0; j< 25; j++){
	for (int k = 0; k < 3 ; k++){
		history_buffer4[k][j] = 0;
		}
				     }
	}


}

void squared_calculation (GtkButton *entry, gpointer data) {

	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	static char history_buffer5[3][25];
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	float x = atof(text);
	float y=atof(text2);
	static int s=0;
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "You should write in operand one or in operand 2");
	
	}
	
	else if (strlen(text) == 0){
	
	g_print("%.0f\nsquared is \n%.0f\n", y,y*y);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%.0f\n", y*y);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
	}
	
	else if (strlen(text2) == 0){
	
	g_print("%.0f\nsquared is \n%.0f\n", x,x*x);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%.0f\n", x*x);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "you should write only in one operand!");
	
	}
	strcpy (history_buffer5[s], output_buffer);
	
	gtk_label_set_text (GTK_LABEL (p->history_label), history_buffer5[0]);
	gtk_label_set_text (GTK_LABEL (p->history_label2), history_buffer5[1]);
	gtk_label_set_text (GTK_LABEL (p->history_label3), history_buffer5[2]);
	
	
	s++;
	if (s == 3){
	s=0;
	for (int j = 0; j< 25; j++){
	for (int k = 0; k < 3 ; k++){
		history_buffer5[k][j] = 0;
		}
				     }
	}


}

void square_root_calculation (GtkButton *entry, gpointer data){


	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	static char history_buffer6[3][25];
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	long double x = atof(text);
	long double y=atof(text2);
	static int s=0;
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "You should write in operand one or in operand 2");
	
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
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%.5Lf\n",result);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
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
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%0.5Lf\n",result2);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "you should write only in one operand!");
	
	}
	
	strcpy (history_buffer6[s], output_buffer);
	
	gtk_label_set_text (GTK_LABEL (p->history_label), history_buffer6[0]);
	gtk_label_set_text (GTK_LABEL (p->history_label2), history_buffer6[1]);
	gtk_label_set_text (GTK_LABEL (p->history_label3), history_buffer6[2]);
	
	
	s++;
	if (s == 3){
	s=0;
	for (int j = 0; j< 25; j++){
	for (int k = 0; k < 3 ; k++){
		history_buffer6[k][j] = 0;
		}
				     }
	}

}
void comma_button (GtkButton *button, gpointer data){

	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	char comma_buffer[]={","};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	
	
	
	
	 if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "You should write in operand one ");
	
	}
	
	
	
	else if (strlen(text2) == 0){
	
	sprintf(output_buffer, "%s", text);
	strcat(output_buffer,comma_buffer);
	gtk_entry_set_text(GTK_ENTRY(p->textentry), output_buffer);
	}
	
	else if (strlen(text) !=0) {
	
	sprintf(output_buffer, "%s", text2);
	strcat(output_buffer,comma_buffer);
	gtk_entry_set_text(GTK_ENTRY(p->textentry2), output_buffer);
	}
	
	else {
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "Please clear the secound operand and beginn with the first operand");
	}
	
	
}


void percent_operation (GtkButton *entry, gpointer data){
	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	static char history_buffer7[3][25];
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));
	long double x = atof(text);
	long double y=atof(text2);
	static int s=0;
	
	
	
	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "You should write in operand one or in operand 2");
	
	}
	
	else  if (strlen(text) == 0){
	
	
	//funtion for y
	
	
	
	g_print("the precent of %.0Lf\n is \n%.5Lf\n", y,y/100);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%.5Lf\n",y/100);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
	}
	
	else if (strlen(text2) == 0){
	
	//funtion for x
	
	
	g_print("the precent of %.0Lf\n is \n%.5Lf\n", x,x/100);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	sprintf(output_buffer, "%.5Lf\n",x/100);
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), output_buffer);
	
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "you should write only in one operand!");
	
	}
	strcpy (history_buffer7[s], output_buffer);
	
	gtk_label_set_text (GTK_LABEL (p->history_label), history_buffer7[0]);
	gtk_label_set_text (GTK_LABEL (p->history_label2), history_buffer7[1]);
	gtk_label_set_text (GTK_LABEL (p->history_label3), history_buffer7[2]);
	
	
	s++;
	if (s == 3){
	s=0;
	for (int j = 0; j< 25; j++){
	for (int k = 0; k < 3 ; k++){
		history_buffer7[k][j] = 0;
		}
				     }
	}
	

}

void backspace_operation (GtkButton *entry, gpointer data){

	struct info *p = (struct info *) data;
	char output_buffer[19] = {0};
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(p->textentry));
	const gchar* text2 = gtk_entry_get_text(GTK_ENTRY(p->textentry2));


	if (strlen(text) == 0 && strlen(text2) == 0){
	
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "You should write in operand one or in operand 2");
	
	}

	else if (strlen(text)!=0 && strlen(text2) == 0){
	
	sprintf(output_buffer, "%s", text);
	output_buffer[strlen(output_buffer)-1] = '\0';
	gtk_entry_set_text(GTK_ENTRY(p->textentry), output_buffer);
	}
	
	else if ((strlen(text2)!=0 && strlen(text) == 0) || strlen(text2)!=0 ){
	
	sprintf(output_buffer, "%s", text2);
	output_buffer[strlen(output_buffer)-1] = '\0';
	gtk_entry_set_text(GTK_ENTRY(p->textentry2), output_buffer);
	}
	
	else {
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "You should write in operand one or in operand 2");
	}

}





void clear_operation (GtkButton *entry, gpointer data){

	
	struct info *p = (struct info *) data;
	gtk_entry_set_text(GTK_ENTRY(p->textentry), "");
	gtk_entry_set_text(GTK_ENTRY(p->textentry2), "");
	gtk_entry_set_text(GTK_ENTRY(p->textentry3), "");
	
	
}




void make_window(GtkApplication *app, gpointer data){

	struct info *p = (struct info *) data;
	GtkWidget *window;
	
	//window = gtk_application_window_new(app);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	
	gtk_window_set_title(GTK_WINDOW(window), "My Text APP");
	
	GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 4);
	 
	gtk_container_add(GTK_CONTAINER(window), vbox);
	
	p->op1_label= gtk_label_new("\nOperand 1: ");
	
	gtk_box_pack_start(GTK_BOX(vbox), p->op1_label, TRUE, TRUE, 4);
	
	p->textentry= gtk_entry_new();
	
	gtk_box_pack_start(GTK_BOX(vbox), p->textentry, TRUE, TRUE, 4);
	
	gtk_entry_set_max_length( GTK_ENTRY(p->textentry), 8);
	
	gtk_entry_set_alignment (GTK_ENTRY(p->textentry), 0.05f);
	
	p->op2_label = gtk_label_new("\nOperand 2: ");
	
	gtk_box_pack_start(GTK_BOX(vbox), p->op2_label, TRUE, TRUE, 4);
	
	p->textentry2 = gtk_entry_new();
	
	
	gtk_box_pack_start(GTK_BOX(vbox), p->textentry2, FALSE, FALSE, 4);
	
	gtk_entry_set_max_length( GTK_ENTRY(p->textentry2), 8);
	
	gtk_entry_set_alignment (GTK_ENTRY(p->textentry2), 0.05f);
	
	p->res_label= gtk_label_new("\nresult: ");
	
	
	
	
	gtk_box_pack_start(GTK_BOX(vbox), p->res_label, FALSE, TRUE, 4);
	
	p->textentry3= gtk_entry_new();
	
	gtk_box_pack_start(GTK_BOX(vbox), p->textentry3, FALSE, FALSE, 4);
	
	gtk_entry_set_max_length( GTK_ENTRY(p->textentry3), 100);
	
	gtk_entry_set_alignment (GTK_ENTRY(p->textentry3), 0.05f);
	
	
	p->history_label= gtk_label_new("");
	
	gtk_box_pack_start(GTK_BOX(vbox), p->history_label, FALSE, TRUE, 4);
	
	p->history_label2= gtk_label_new("");
	
	gtk_box_pack_start(GTK_BOX(vbox), p->history_label2, FALSE, TRUE, 4);
	
	p->history_label3= gtk_label_new("");
	
	gtk_box_pack_start(GTK_BOX(vbox), p->history_label3, FALSE, TRUE, 4);
	
	

	
	p->grid= gtk_grid_new();
	gtk_grid_set_column_homogeneous (GTK_GRID(p->grid), TRUE);
	gtk_grid_set_column_spacing (GTK_GRID(p->grid), 5);
	gtk_grid_set_row_spacing (GTK_GRID(p->grid), 3);
	
	gtk_box_pack_start(GTK_BOX(vbox), p->grid, FALSE, TRUE, 100);
	
	
	p->button[0] = gtk_button_new_with_label ("C");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[0]), 0);
	gtk_widget_set_size_request(p->button[0], 50,50);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[0], 0,0,3,1);
	
	p->button[1] = gtk_button_new_with_label ("√");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[1]), 0);
	gtk_widget_set_size_request(p->button[1], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[1], 0,4,1,1);
	
	p->button[2] = gtk_button_new_with_label ("÷");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[2]), 0);
	gtk_widget_set_size_request(p->button[2], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[2], 0,1,1,2);
	
	p->button[3] = gtk_button_new_with_label ("*");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[3]), 0);
	gtk_widget_set_size_request(p->button[3], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[3], 1,1,1,2);
	
	p->button[4] = gtk_button_new_with_label (",");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[4]), 0);
	gtk_widget_set_size_request(p->button[4], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[4], 1,4,1,1);
	
	p->button[5] = gtk_button_new_with_label ("-");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[5]), 0);
	gtk_widget_set_size_request(p->button[5], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[5], 2,1,1,2);
	
	
	p->button[6] = gtk_button_new_with_label ("x²");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[6]), 0);
	gtk_widget_set_size_request(p->button[6], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[6], 3,0,1,1);
	
	p->button[7] = gtk_button_new_with_label ("+");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[7]), 0);
	gtk_widget_set_size_request(p->button[7], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[7], 3,1,1,2);
	
	
	p->button[8] = gtk_button_new_with_label ("⌫");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[8]), 0);
	gtk_widget_set_size_request(p->button[8], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[8], 2,4,1,1);
	
	p->button[9] = gtk_button_new_with_label ("%");
	gtk_container_set_border_width( GTK_CONTAINER(p->button[9]), 0);
	gtk_widget_set_size_request(p->button[9], 100,100);
	gtk_grid_attach(GTK_GRID(p->grid), p->button[9], 3,4,1,1);

g_signal_connect_swapped ( p->textentry, "activate", G_CALLBACK ( zero_to_nine_keys_callback ), p->textentry );
g_signal_connect_swapped ( p->textentry, "key_press_event", G_CALLBACK ( zero_to_nine_keys_callback ), p->textentry);

	
	
	
g_signal_connect_swapped ( p->textentry2, "activate", G_CALLBACK ( zero_to_nine_keys_callback ), p->textentry2 );
	
g_signal_connect_swapped ( p->textentry2, "key_press_event", G_CALLBACK ( zero_to_nine_keys_callback ), p->textentry2);

g_signal_connect_swapped ( p->textentry3, "activate", G_CALLBACK ( zero_to_nine_keys_callback ), p->textentry3 );
	
g_signal_connect_swapped ( p->textentry3, "key_press_event", G_CALLBACK ( zero_to_nine_keys_callback ), p->textentry3);

g_signal_connect (p->button[7], "clicked", G_CALLBACK (plus_calculation), (gpointer) p);
g_signal_connect (p->button[5], "clicked", G_CALLBACK(minus_calculation), (gpointer) p);
g_signal_connect ( p->button[3], "clicked", G_CALLBACK ( multiplied_calculation),(gpointer) p );
g_signal_connect ( p->button[2], "clicked", G_CALLBACK ( division_calculation), (gpointer) p );
g_signal_connect ( p->button[0], "clicked", G_CALLBACK ( clear_operation), (gpointer) p );
g_signal_connect ( p->button[6], "clicked", G_CALLBACK ( squared_calculation),(gpointer) p );
g_signal_connect ( p->button[1], "clicked", G_CALLBACK (square_root_calculation), (gpointer) p);
g_signal_connect( p->button[4], "clicked", G_CALLBACK (comma_button), (gpointer) p);
g_signal_connect ( p->button[8], "clicked", G_CALLBACK (backspace_operation), (gpointer) p );
g_signal_connect( p->button[9], "clicked", G_CALLBACK (percent_operation),(gpointer) p );
	
	
	
gtk_widget_show_all(window);
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


