COMPILATEUR = cc
OPTIONS_COMPILATION = -std=c11 -Wall -Wextra -Werror -I$(DOSSIER_EN_TETES)
OPTIONS_EDITION_DE_LIENS = -pthread

DOSSIER_SOURCES = sources
DOSSIER_EN_TETES = en_tetes
DOSSIER_EXEMPLES = exemples
DOSSIER_OBJETS = objets
DOSSIER_BINAIRES = binaires

FICHIERS_SOURCES_BIBLIOTHEQUE = \
	$(DOSSIER_SOURCES)/liste_chainee_simple.c \
	$(DOSSIER_SOURCES)/pile.c \
	$(DOSSIER_SOURCES)/file.c \
	$(DOSSIER_SOURCES)/file_de_priorite.c \
	$(DOSSIER_SOURCES)/table_de_hachage.c \
	$(DOSSIER_SOURCES)/arbre_binaire.c \
	$(DOSSIER_SOURCES)/arbre_binaire_de_recherche.c \
	$(DOSSIER_SOURCES)/union_trouver.c \
	$(DOSSIER_SOURCES)/graphe_matrice_adjacence.c \
	$(DOSSIER_SOURCES)/graphe_liste_adjacence.c \
	$(DOSSIER_SOURCES)/automate_fini.c \
	$(DOSSIER_SOURCES)/mutex.c \
	$(DOSSIER_SOURCES)/semaphore.c

FICHIERS_OBJETS_BIBLIOTHEQUE = $(patsubst $(DOSSIER_SOURCES)/%.c,$(DOSSIER_OBJETS)/%.o,$(FICHIERS_SOURCES_BIBLIOTHEQUE))

FICHIERS_SOURCES_EXEMPLES = $(wildcard $(DOSSIER_EXEMPLES)/*.c)
FICHIERS_BINAIRES_EXEMPLES = $(patsubst $(DOSSIER_EXEMPLES)/%.c,$(DOSSIER_BINAIRES)/%,$(FICHIERS_SOURCES_EXEMPLES))

.PHONY: tout bibliotheque exemples nettoyer

tout: bibliotheque exemples

bibliotheque: $(DOSSIER_BINAIRES)/bibliotheque_structures_de_donnees.a

exemples: $(FICHIERS_BINAIRES_EXEMPLES)

$(DOSSIER_BINAIRES)/bibliotheque_structures_de_donnees.a: $(FICHIERS_OBJETS_BIBLIOTHEQUE) | $(DOSSIER_BINAIRES)
	ar rcs $@ $^

$(DOSSIER_BINAIRES)/%: $(DOSSIER_EXEMPLES)/%.c $(FICHIERS_OBJETS_BIBLIOTHEQUE) | $(DOSSIER_BINAIRES)
	$(COMPILATEUR) $(OPTIONS_COMPILATION) $< $(FICHIERS_OBJETS_BIBLIOTHEQUE) -o $@ $(OPTIONS_EDITION_DE_LIENS)

$(DOSSIER_OBJETS)/%.o: $(DOSSIER_SOURCES)/%.c | $(DOSSIER_OBJETS)
	$(COMPILATEUR) $(OPTIONS_COMPILATION) -c $< -o $@

$(DOSSIER_OBJETS):
	mkdir -p $(DOSSIER_OBJETS)

$(DOSSIER_BINAIRES):
	mkdir -p $(DOSSIER_BINAIRES)

nettoyer:
	rm -rf $(DOSSIER_OBJETS) $(DOSSIER_BINAIRES)
