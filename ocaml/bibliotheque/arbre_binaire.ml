type arbre_binaire =
  | Vide
  | Noeud of int * arbre_binaire * arbre_binaire

let creer_arbre_binaire_vide () = Vide

let creer_noeud_arbre_binaire valeur fils_gauche fils_droit =
  Noeud (valeur, fils_gauche, fils_droit)

let rec taille_arbre_binaire arbre =
  match arbre with
  | Vide -> 0
  | Noeud (_, fils_gauche, fils_droit) ->
      1 + taille_arbre_binaire fils_gauche + taille_arbre_binaire fils_droit

let rec hauteur_arbre_binaire arbre =
  match arbre with
  | Vide -> 0
  | Noeud (_, fils_gauche, fils_droit) ->
      1 + max (hauteur_arbre_binaire fils_gauche) (hauteur_arbre_binaire fils_droit)

let rec parcours_prefixe_arbre_binaire arbre =
  match arbre with
  | Vide -> []
  | Noeud (valeur, fils_gauche, fils_droit) ->
      [ valeur ] @ parcours_prefixe_arbre_binaire fils_gauche @ parcours_prefixe_arbre_binaire fils_droit

let rec parcours_infixe_arbre_binaire arbre =
  match arbre with
  | Vide -> []
  | Noeud (valeur, fils_gauche, fils_droit) ->
      parcours_infixe_arbre_binaire fils_gauche @ [ valeur ] @ parcours_infixe_arbre_binaire fils_droit

let rec parcours_suffixe_arbre_binaire arbre =
  match arbre with
  | Vide -> []
  | Noeud (valeur, fils_gauche, fils_droit) ->
      parcours_suffixe_arbre_binaire fils_gauche @ parcours_suffixe_arbre_binaire fils_droit @ [ valeur ]
