type arbre_binaire_de_recherche =
  | Vide
  | Noeud of int * arbre_binaire_de_recherche * arbre_binaire_de_recherche

let creer_arbre_binaire_de_recherche_vide () = Vide

let rec inserer_element_arbre_binaire_de_recherche arbre valeur =
  match arbre with
  | Vide -> Noeud (valeur, Vide, Vide)
  | Noeud (valeur_courante, fils_gauche, fils_droit) ->
      if valeur < valeur_courante then
        Noeud
          ( valeur_courante,
            inserer_element_arbre_binaire_de_recherche fils_gauche valeur,
            fils_droit )
      else if valeur > valeur_courante then
        Noeud
          ( valeur_courante,
            fils_gauche,
            inserer_element_arbre_binaire_de_recherche fils_droit valeur )
      else
        arbre

let rec rechercher_element_arbre_binaire_de_recherche arbre valeur =
  match arbre with
  | Vide -> false
  | Noeud (valeur_courante, fils_gauche, fils_droit) ->
      if valeur = valeur_courante then
        true
      else if valeur < valeur_courante then
        rechercher_element_arbre_binaire_de_recherche fils_gauche valeur
      else
        rechercher_element_arbre_binaire_de_recherche fils_droit valeur

let rec minimum_arbre_binaire_de_recherche arbre =
  match arbre with
  | Vide -> invalid_arg "arbre vide"
  | Noeud (valeur, Vide, _) -> valeur
  | Noeud (_, fils_gauche, _) -> minimum_arbre_binaire_de_recherche fils_gauche

let rec supprimer_element_arbre_binaire_de_recherche arbre valeur =
  match arbre with
  | Vide -> Vide
  | Noeud (valeur_courante, fils_gauche, fils_droit) ->
      if valeur < valeur_courante then
        Noeud
          ( valeur_courante,
            supprimer_element_arbre_binaire_de_recherche fils_gauche valeur,
            fils_droit )
      else if valeur > valeur_courante then
        Noeud
          ( valeur_courante,
            fils_gauche,
            supprimer_element_arbre_binaire_de_recherche fils_droit valeur )
      else
        match (fils_gauche, fils_droit) with
        | Vide, Vide -> Vide
        | Vide, _ -> fils_droit
        | _, Vide -> fils_gauche
        | _, _ ->
            let successeur = minimum_arbre_binaire_de_recherche fils_droit in
            Noeud
              ( successeur,
                fils_gauche,
                supprimer_element_arbre_binaire_de_recherche fils_droit successeur )

let rec parcours_prefixe_arbre_binaire_de_recherche arbre =
  match arbre with
  | Vide -> []
  | Noeud (valeur, fils_gauche, fils_droit) ->
      [ valeur ]
      @ parcours_prefixe_arbre_binaire_de_recherche fils_gauche
      @ parcours_prefixe_arbre_binaire_de_recherche fils_droit

let rec parcours_infixe_arbre_binaire_de_recherche arbre =
  match arbre with
  | Vide -> []
  | Noeud (valeur, fils_gauche, fils_droit) ->
      parcours_infixe_arbre_binaire_de_recherche fils_gauche
      @ [ valeur ]
      @ parcours_infixe_arbre_binaire_de_recherche fils_droit

let rec parcours_suffixe_arbre_binaire_de_recherche arbre =
  match arbre with
  | Vide -> []
  | Noeud (valeur, fils_gauche, fils_droit) ->
      parcours_suffixe_arbre_binaire_de_recherche fils_gauche
      @ parcours_suffixe_arbre_binaire_de_recherche fils_droit
      @ [ valeur ]
