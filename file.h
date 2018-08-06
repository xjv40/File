#ifndef __FILE
#define __FILE

typedef struct File File;

struct File {
  void* element;
  void* pointeur_tete;
  void* pointeur_queue;
  int taille;
  int nb_elements;
};

File* creation_file(int taille);

#endif // __FILE
