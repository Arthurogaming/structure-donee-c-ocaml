type semaphore_abstrait

val creer_semaphore_abstrait : int -> semaphore_abstrait
val obtenir_valeur_semaphore_abstrait : semaphore_abstrait -> int
val attendre_semaphore_abstrait : semaphore_abstrait -> bool
val signaler_semaphore_abstrait : semaphore_abstrait -> unit
