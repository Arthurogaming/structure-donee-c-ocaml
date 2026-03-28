type semaphore_abstrait = {
  mutable valeur : int;
}

let creer_semaphore_abstrait valeur_initiale =
  if valeur_initiale < 0 then invalid_arg "valeur_initiale negative";
  { valeur = valeur_initiale }

let obtenir_valeur_semaphore_abstrait semaphore =
  semaphore.valeur

let attendre_semaphore_abstrait semaphore =
  if semaphore.valeur <= 0 then
    false
  else begin
    semaphore.valeur <- semaphore.valeur - 1;
    true
  end

let signaler_semaphore_abstrait semaphore =
  semaphore.valeur <- semaphore.valeur + 1
