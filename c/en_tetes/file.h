#ifndef FILE_H
#define FILE_H

typedef struct CelluleFile {
    int valeur;
    struct CelluleFile *suivante;
} CelluleFile;

typedef struct {
    CelluleFile *tete;
    CelluleFile *queue;
} File;

File creer_file(void);
void detruire_file(File *file);
int est_vide_file(const File *file);
int enfiler_element_file(File *file, int valeur);
int defiler_element_file(File *file, int *valeur_defilee);
int obtenir_tete_file(const File *file, int *valeur);

#endif
