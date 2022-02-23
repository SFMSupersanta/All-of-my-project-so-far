/* Card Draw
 *  cardDraw.c
 *  BTP100
 *  Mar 8 2005
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define CARDS 52
 #define SUITS 4
 void initialize(int []);
 void lShuffle(int []);
 void draw(int [], int n);
 void display(int [], int []);

 int main ( ) {
     int card[CARDS], drawn[CARDS] = {0}, nDraw;

     srand(time(NULL));
     initialize(card);
     lShuffle(card);

     printf("Number of Cards to Draw : ");
     scanf("%d", &nDraw);

     draw(drawn, nDraw);
     display(card, drawn);

     return 0;
 }

 /* Initialize cards */
 void initialize(int card[]) {
     int i;

     for (i = 0; i < CARDS; i++)
         card[i] = i;
 }

 /* lShuffle shuffles a deck of cards in linear time
 */
 void lShuffle(int card[]) {
     int i, cardsLeft, j, temp;

     cardsLeft = CARDS;
     for (i = 0; i < CARDS; i++) {
         j = i + rand() % cardsLeft;
         temp = card[i];
         card[i] = card[j];
         card[j] = temp;
         cardsLeft--;
     }
 }

 /* drawCards draws n cards from a deck
 *  identifying the drawn cards by setting
 *  drawn[i] to 1;
 */
 void draw(int drawn[], int nDraw) {
     int i, j, notDrawn, card, skipped, keeplooking;

     notDrawn = CARDS;
     for (i = 0; i < nDraw; i++) {
         card = rand() % notDrawn;
         skipped = 0;
         keeplooking = 1;
         for (j = 0; j < CARDS && keeplooking == 1; j++) {
             if (drawn[j] == 0 && skipped == card) {
                 drawn[j] = 1;
                 keeplooking = 0;
             } else if (drawn[j] == 0)
                 skipped++;
         }
         notDrawn--;
     }
 }

 /* display displays cards on standard output
 */
 void display(int card[], int drawn[]) {
     char suit, face;
     int rank, i;

     for (i = 0; i < CARDS; i++) {
         if (drawn[i] == 1) {
             switch (card[i] / (CARDS/SUITS)) {
             case 0:
                 suit = 'S';
                 break;
             case 1:
                 suit = 'H';
                 break;
             case 2:
                 suit = 'D';
                 break;
             case 3:
                 suit = 'C';
                 break;
             }
             rank = card[i] % (CARDS/SUITS);
             if (rank < 8)
                 printf("%d of %c\n", rank + 2, suit); 
             else if (rank == 8)
                 printf("10 of %c\n", suit);
             else {
                 switch (rank) {
                 case 9:
                     face = 'J';
                     break;
                 case 10:
                     face = 'Q';
                     break;
                 case 11:
                     face = 'K';
                     break;
                 case 12:
                     face = 'A';
                     break;
                 }
                 printf("%c of %c\n", face, suit);
             }
         }
     }
 }