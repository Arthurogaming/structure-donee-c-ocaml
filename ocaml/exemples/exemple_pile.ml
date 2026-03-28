let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let pile =
    Pile.creer_pile ()
    |> fun pile -> Pile.empiler_element_pile pile 10
    |> fun pile -> Pile.empiler_element_pile pile 20
    |> fun pile -> Pile.empiler_element_pile pile 30
  in
  begin
    match Pile.obtenir_sommet_pile pile with
    | None -> print_endline "Pile vide."
    | Some sommet -> Printf.printf "Sommet de la pile : %d\n" sommet
  end;
  match Pile.depiler_element_pile pile with
  | None -> print_endline "Aucun element a depiler."
  | Some (valeur, pile_restante) ->
      Printf.printf "Element depile : %d\n" valeur;
      Printf.printf "Pile restante : %s\n" (chaine_de_liste_entiere pile_restante)
