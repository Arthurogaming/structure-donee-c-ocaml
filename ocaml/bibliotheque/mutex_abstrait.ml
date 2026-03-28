type mutex_abstrait = {
  mutable est_verrouille : bool;
}

let creer_mutex_abstrait () =
  { est_verrouille = false }

let est_verrouille_mutex_abstrait mutex =
  mutex.est_verrouille

let verrouiller_mutex_abstrait mutex =
  if mutex.est_verrouille then
    false
  else begin
    mutex.est_verrouille <- true;
    true
  end

let deverrouiller_mutex_abstrait mutex =
  if mutex.est_verrouille then begin
    mutex.est_verrouille <- false;
    true
  end else
    false
