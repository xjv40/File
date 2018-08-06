#ifndef __FILE
#define __FILE

typedef struct File File;
typedef struct Element Element;

struct File {
  void* pointeur_tete;
  void* pointeur_queue;
  int taille;
  int nb_elements;
};

struct Element {
  int valeur;
  struct Element* element_suivant;
};

File* creation_file(unsigned int taille);
Element* creation_element(int valeur);
int enfiler(File* pfile, Element* pelement);
int nb_elements(File* pfile);

#endif // __FILE
