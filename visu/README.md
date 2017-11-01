Ce programme fournit un visuel lors de l'exécution de la vm du filler (eg : filler_vm [usage] | visufiller)

Son comportement en cas d'utilisation seul ou dans un contexte différent est inconnu.
En cas d'arguments non fournis par la vm sur l'entrée standard le comportement est inconnu.

Realisé avec la MinilibX

-f n'affiche l'exécution de la vm que jusqu'à la première pièce de différence entre les joueurs et quitte dès la fin de lecture.

-k continue l'affichage de la fenêtre jusqu'à fermeture par l'utilisateur. Si l'option 'f' est précisé impose un affichage 5 secondes après la fin de lecture.

-n comportement de fin d'exécution par défaut. Si 'f' ou 'k' sont précédemment précisé ceux-ci sont ignorés.

-s impose un délai de 100000000 ms entre chaque update jusqu'à la fin de la lecture.
