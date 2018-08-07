#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "file.h"

int main(void) {
  // File* pfile = creation_file(10);
  Element* pelement = creation_element(5);

  printf("%d\n", pelement->valeur);
  return 0;
}

Element* creation_element(int valeur) {
  Element* pelement = (Element*) malloc(sizeof(Element));
  if (pelement) {
    pelement->valeur = valeur;
    pelement->element_suivant = NULL;
  }
  return pelement;
}

File* creation_file(unsigned int taille) {
  if (taille == 0) {
    return NULL;
  }

  File* pfile = (File*) malloc(sizeof(File));
  if (pfile) {
    pfile->pointeur_tete = NULL;
    pfile->pointeur_queue = NULL;
    pfile->taille = taille;
    pfile->nb_elements = 0;
  }
  return pfile;
}

int enfiler(File* pfile, Element* pelement) {
  int valeur_retour = 0;
  if (!pfile || !pelement) {
    valeur_retour = -1;
  }
  else {
    if (pfile->nb_elements >= pfile->taille) {
      valeur_retour = -1;
    }
    else {
      if (!pfile->pointeur_tete) {
        pfile->pointeur_tete = pelement;
      }
      if (!pfile->pointeur_queue) {
        pfile->pointeur_queue = pelement;
      }
      else {
        Element* ptempElement = pfile->pointeur_queue;
        ptempElement->element_suivant = pelement;
        pfile->pointeur_queue = pelement;
        pelement->element_suivant = NULL;
      }
      pfile->nb_elements++;

      valeur_retour = 0;
    }
  }
  return valeur_retour;
}

Element* defiler(File* pfile) {
  if (!pfile || !pfile->pointeur_tete) {
    return NULL;
  }
  Element* ptempElement = pfile->pointeur_tete;
  pfile->pointeur_tete = ptempElement->element_suivant;
  pfile->nb_elements--;
  return ptempElement;
}

int nb_elements(File* pfile) {
  int valeur_retour = 0;
  if (pfile) {
    if (pfile->nb_elements == 0
        && pfile->pointeur_tete == NULL
        && pfile->pointeur_queue == NULL) {
    }
    else if (pfile->nb_elements != 0
             && pfile->pointeur_tete != NULL
             && pfile->pointeur_queue != NULL) {
      valeur_retour = pfile->nb_elements;
    }
    else {
      valeur_retour = -1;
    }
  }
  return valeur_retour;
}

bool est_vide(File* pfile) {
  bool valeur_retour = false;
  if (pfile) {
    if (pfile->nb_elements == 0
        && pfile->pointeur_tete == NULL
        && pfile->pointeur_queue == NULL) {
      valeur_retour = true;
    }
  }
  return valeur_retour;
}

void afficher_file(File* pfile) {
  if (!pfile || !pfile->pointeur_tete || !pfile->pointeur_queue) {
    return;
  }
  Element* ptempElement = pfile->pointeur_tete;
  do {
    printf("%d\n", ptempElement->valeur);
    ptempElement = ptempElement->element_suivant;
  } while(ptempElement);
}
