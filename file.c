#include <stdlib.h>
#include <stdio.h>

#include "file.h"

int main(void) {
  return 0;
}

Element* creation_element(int valeur) {
  Element* pelement = (Element*) malloc(sizeof(Element));
  if (pelement) {
    pelement->valeur = valeur;
  }
  return pelement;
}

File* creation_file(int taille) {
  File* pfile = (File*) malloc(sizeof(File));
  if (pfile) {
  pfile->element = NULL;
  pfile->pointeur_tete = NULL;
  pfile->pointeur_queue = NULL;
  pfile->taille = taille;
  pfile->nb_elements = 0;
  }
  return pfile;
}
