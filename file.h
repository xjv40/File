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
};

File* creation_file(int taille);
Element* creation_element(int valeur);

#endif // __FILE
