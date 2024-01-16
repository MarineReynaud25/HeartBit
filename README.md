# Description

## Composants
- 2 cœurs en résine
- 2 PCB
- 2 batteries

## Deploy
1. Ouvrir les couvercles des 2 cœurs.
2. Vérifier que les PCB soient bien branchés à chacune des batteries.
3. Allumer l'interrupteur du PCB sur ON.
   
![turn on the pcb](https://github.com/MarineReynaud25/HeartBit/blob/main/turnonpcb.png)

5. Fermer le couvercle.
6. Mettre les 2 pendentifs en présentation.
7. Appuyer sur le bouton d'un cœur pour allumer l'autre.

## Debug
Si la communication entre les deux cartes ne fonctionne plus :
- Assurez-vous que la batterie lithium soit suffisamment chargée.
  
![charge the bttery](https://github.com/MarineReynaud25/HeartBit/blob/main/charge.png)

- Recharger le code Arduino ci-dessous sur la carte en faisant attention aux macAdress (voir le fichier macAdress pour avoir le code).
- Si les led ne s'allument pas correctement éteindre attendre un instnat puis rallumer les pcb
