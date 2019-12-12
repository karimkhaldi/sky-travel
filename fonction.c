#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int verifier (char login[20], char password[20]){
FILE *f ;
int test=0;
f=fopen("user.txt","r") ;
char login1[20]; char password1[20]; int role;
if (f!=NULL) {
while ((fscanf(f,"%s %s %d",login1,password1,&role)!=EOF)) {
if ((strcmp(login1,login)==0) && (strcmp(password1,password))==0){ 
test=role;
}}
fclose(f);
}
return test;
}
void afficheremploye(GtkWidget *treeview1)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;
char nom [100];
char prenom[100] ;
char sexe [10];
char num_cin[10];
char num_tel [10];
char jour [10] ;
char mois [10] ;
char annee [10] ;
FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prenom",renderer,"text",PRENOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("sexe",renderer,"text",SEXE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("num_cin",renderer,"text",NUMERO_CIN,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("num_tel",renderer,"text",NUMERO_TELEPHONE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Jour",renderer,"text",JOUR,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
            
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("mois",renderer,"text",MOIS,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
            
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("annee",renderer,"text",ANNEE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
}
            store =gtk_list_store_new(NUM_COL,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("agent.txt","r");
            if (f!=NULL){
while (fscanf(f,"%s %s %s %s %s %s %s %s",nom,prenom,sexe,num_cin,num_tel,jour,mois,annee)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,NOM,nom,PRENOM,prenom,SEXE,sexe,NUMERO_CIN,num_cin,NUMERO_TELEPHONE,num_tel,JOUR,jour,MOIS,mois,ANNEE,annee,-1);
}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
            g_object_unref(store);
}
void ajouteragent(agent a) {
FILE * f; 

f=fopen("agent.txt","a+") ;
if(f!=NULL) {


fprintf(f,"%s %s %s %s %s %s %s %s\n ",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.jour,a.mois,a.annee );
}

fclose(f); 
}
void modifieragent(char nom[20] ,char prenom[20],char sexe [20],char num_CIN[20],char num_tel[20] ,char jour[20],char mois[20],char annee[20] )
{
agent a;
FILE *f;
FILE *f1;
f1=NULL ;
f=fopen("agent.txt","r+");
f1=fopen("agent1.txt","w");
if (f!= NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s\n ",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.jour,a.mois,a.annee)!=EOF) {
if (strcmp(num_CIN ,a.num_CIN)==0)
{
fprintf(f1,"%s %s %s %s %s %s %s %s \n",nom,prenom,sexe,num_CIN,num_tel,jour,mois,annee) ;
}
else
fprintf(f1,"%s %s %s %s %s %s %s %s\n ",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.jour,a.mois,a.annee) ;
}
fclose(f1);
fclose(f);
remove("agent.txt");
rename ("agent1.txt","agent.txt");
}
}

void supprimeragent(char num_CIN[] ){
agent a;
FILE *f;
FILE *f1 ;
f1 =NULL;
f=fopen("agent.txt","r") ;
if (f!= NULL)
{

while (fscanf(f," %s %s %s %s %s %s %s %s ",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.jour,a.mois,a.annee)!=EOF) {
if (strcmp(num_CIN,a.num_CIN))
{
f1=fopen("agent1.txt","a");

fprintf(f1,"%s %s %s %s %s %s %s %s \n",a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.jour,a.mois,a.annee) ;
fclose(f1);
}
}
}


fclose(f);
remove("agent.txt");
rename("agent1.txt","agent.txt");

}

