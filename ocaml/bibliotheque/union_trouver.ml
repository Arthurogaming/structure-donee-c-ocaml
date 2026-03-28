type union_trouver = {
  parents : int array;
  rangs : int array;
}

let creer_union_trouver nombre_elements =
  if nombre_elements < 0 then invalid_arg "nombre_elements negatif";
  {
    parents = Array.init nombre_elements (fun indice -> indice);
    rangs = Array.make nombre_elements 0;
  }

let verifier_element_union_trouver union_trouver element =
  if element < 0 || element >= Array.length union_trouver.parents then
    invalid_arg "element hors limites"

let rec trouver_representant_union_trouver union_trouver element =
  verifier_element_union_trouver union_trouver element;
  if union_trouver.parents.(element) = element then
    element
  else
    let representant =
      trouver_representant_union_trouver union_trouver union_trouver.parents.(element)
    in
    union_trouver.parents.(element) <- representant;
    representant

let unir_ensembles_union_trouver union_trouver premier_element second_element =
  let representant_premier =
    trouver_representant_union_trouver union_trouver premier_element
  in
  let representant_second =
    trouver_representant_union_trouver union_trouver second_element
  in
  if representant_premier <> representant_second then
    if union_trouver.rangs.(representant_premier) < union_trouver.rangs.(representant_second) then
      union_trouver.parents.(representant_premier) <- representant_second
    else if union_trouver.rangs.(representant_premier) > union_trouver.rangs.(representant_second) then
      union_trouver.parents.(representant_second) <- representant_premier
    else begin
      union_trouver.parents.(representant_second) <- representant_premier;
      union_trouver.rangs.(representant_premier) <- union_trouver.rangs.(representant_premier) + 1
    end

let sont_dans_le_meme_ensemble_union_trouver union_trouver premier_element second_element =
  trouver_representant_union_trouver union_trouver premier_element
  = trouver_representant_union_trouver union_trouver second_element

let parents_union_trouver union_trouver =
  Array.to_list union_trouver.parents
