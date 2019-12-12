#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

void
on_login_clicked                       (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{

  GtkWidget *input1;  
  GtkWidget *input2;
  GtkWidget *output;
  GtkWidget *acceuil; 
  GtkWidget *espaceadmin;
  char login[20];
  char password[20];
  int logg;
  
  input1=lookup_widget(objet_graphique,"entry1");
  strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));

  input2=lookup_widget(objet_graphique,"entry2"); 
  strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

  output=lookup_widget(objet_graphique,"labelerrorr"); 
  logg=verifier(login,password);

switch(logg)
{
	case 1://pour afficher(espace admin)
                               
               espaceadmin= create_espaceadmin();		
                
		gtk_widget_show(espaceadmin);
		acceuil=lookup_widget(objet_graphique,"acceuil");
		gtk_widget_hide(acceuil);
		break;
	default :
gtk_label_set_text(GTK_LABEL(output),"Verifier vos paramètres !!");
}


}


void
on_gestionagent_clicked                (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
    
  GtkWidget *espaceadmin;
   GtkWidget *gestionagent;
  espaceadmin=create_espaceadmin();
  espaceadmin=lookup_widget(objet_graphique,"espaceadmin");
   gtk_widget_hide(espaceadmin);
  gestionagent = create_gestionagent ();
  gtk_widget_show (gestionagent);
}



void
on_afficher_clicked                    (GtkWidget     *objet_graphique,
                                        gpointer         user_data)

{

  GtkWidget *gestionagent;
  GtkWidget *treeview1;
  gestionagent=lookup_widget(objet_graphique,"gestionagent");
  treeview1=lookup_widget(gestionagent,"treeview1");
  afficheremploye(treeview1);

}



void
on_ajouteragent_clicked                (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
agent a;  
  GtkWidget *input1;  
  GtkWidget *input2; 
  GtkWidget *input3;  
  GtkWidget *input4;  
  GtkWidget *input5;  
  GtkWidget *input6;  
  GtkWidget *input7;  
  GtkWidget *input8; 
  GtkWidget *input9;
  GtkWidget *radiobutton1;
  GtkWidget *radiobutton2;

  input1=lookup_widget(objet_graphique,"entry3"); 
  input2=lookup_widget(objet_graphique,"entry4"); 
  radiobutton1=lookup_widget(objet_graphique,"radiobutton1"); 
  radiobutton2=lookup_widget(objet_graphique,"radiobutton2"); 
  input5=lookup_widget(objet_graphique,"spinbutton1"); 
  input6=lookup_widget(objet_graphique,"spinbutton2"); 
  input7=lookup_widget(objet_graphique,"spinbutton3"); 
  input8=lookup_widget(objet_graphique,"spinbutton4");
  input9=lookup_widget(objet_graphique,"spinbutton5"); 
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))==TRUE)
  {strcpy(a.sexe,"Homme");;}
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))==TRUE)
  {strcpy(a.sexe,"Femme");;}
  strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(a.num_CIN,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(a.num_tel,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(a.jour,gtk_entry_get_text(GTK_ENTRY(input7)));
  strcpy(a.mois,gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(a.annee,gtk_entry_get_text(GTK_ENTRY(input9)));
  ajouteragent(a);
}



void
on_modifieragent_clicked               (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{


char nom[20] ;char prenom[20];char sexe [20];char num_CIN[20];char num_tel[20]; char jour[20];char mois[20];char annee[20];
 agent a;
  GtkWidget *input1;  
  GtkWidget *input2; 
  GtkWidget *input3;  
  GtkWidget *input4;  
  GtkWidget *input5;  
  GtkWidget *input6;  
  GtkWidget *input7;  
  GtkWidget *input8; 
  GtkWidget *input9;
  GtkWidget *radiobutton3;
  GtkWidget *radiobutton4;

  input1=lookup_widget(objet_graphique,"entry5"); 
  input2=lookup_widget(objet_graphique,"entry6"); 
  radiobutton3=lookup_widget(objet_graphique,"radiobutton3"); 
  radiobutton4=lookup_widget(objet_graphique,"radiobutton4"); 
  input5=lookup_widget(objet_graphique,"spinbutton6"); 
  input6=lookup_widget(objet_graphique,"spinbutton7"); 
  input7=lookup_widget(objet_graphique,"spinbutton8"); 
  input8=lookup_widget(objet_graphique,"spinbutton9");
  input9=lookup_widget(objet_graphique,"spinbutton10"); 
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))==TRUE)
  {strcpy(a.sexe,"Homme");;}
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))==TRUE)
  {strcpy(a.sexe,"Femme");;}
  strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(a.num_CIN,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(a.num_tel,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(a.jour,gtk_entry_get_text(GTK_ENTRY(input7)));
  strcpy(a.mois,gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(a.annee,gtk_entry_get_text(GTK_ENTRY(input9)));
  modifieragent(a.nom,a.prenom,a.sexe,a.num_CIN,a.num_tel,a.jour,a.mois,a.annee);
}


void
on_supprimeragent_clicked              (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
  char cin[20];
  GtkWidget *input1;
  input1=lookup_widget(objet_graphique,"entry7"); 
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
  supprimeragent(cin);

}

