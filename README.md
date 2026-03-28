# Structures de donnees en C et en OCaml

Ce depot propose des implementations pedagogiques de structures de donnees fondamentales en **C** et en **OCaml**. Le code vise un niveau **MPI** : il est volontairement simple, lisible, decoupe par structure, et n'utilise pas d'abstractions complexes.

## Organisation du projet

```text
README.md
c/
  Makefile
  en_tetes/
  sources/
  exemples/
ocaml/
  dune-project
  bibliotheque/
  exemples/
```

## Contenu principal

### Partie C

Chaque structure est separee en un fichier d'en-tete `.h`, un fichier source `.c`, et un exemple d'utilisation.

Structures implementees :

- liste chainee simple
- pile
- file
- file de priorite par tas binaire
- table de hachage par chainage
- arbre binaire
- arbre binaire de recherche
- union-trouver
- graphe par matrice d'adjacence
- graphe par liste d'adjacence
- automate fini deterministe
- mutex
- semaphore

### Partie OCaml

Chaque structure est separee en un module `.ml/.mli` et un petit programme d'exemple.

Structures implementees :

- liste personnalisee
- pile
- file
- file de priorite
- table de hachage
- arbre binaire
- arbre binaire de recherche
- union-trouver
- graphe par matrice d'adjacence
- graphe par liste d'adjacence
- automate fini
- mutex abstrait
- semaphore abstrait

## Compilation

### C

Depuis la racine du depot :

```sh
cd c
make
```

Le `Makefile` propose les cibles suivantes :

- `make` ou `make tout` : construit la bibliotheque et tous les exemples
- `make bibliotheque` : construit la bibliotheque statique
- `make exemples` : construit tous les executables d'exemple
- `make nettoyer` : supprime les fichiers construits

### OCaml

Depuis la racine du depot :

```sh
cd ocaml
dune build
```

Pour executer un exemple en particulier :

```sh
dune exec ./exemples/exemple_liste_personnalisee.exe
dune exec ./exemples/exemple_automate_fini.exe
```

## Exemples d'utilisation

### C

```sh
cd c
make
./binaires/exemple_pile
./binaires/exemple_automate_fini
```

### OCaml

```sh
cd ocaml
dune build
dune exec ./exemples/exemple_pile.exe
dune exec ./exemples/exemple_union_trouver.exe
```

