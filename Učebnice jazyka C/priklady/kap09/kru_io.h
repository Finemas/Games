/*
 * kru_io.h    ver. 2.0
 *
 * Hlavickovy soubor pro modul kru_io.c
 * ====================================
 *
 * P. Herout,  rijen 2003
 *
 */

/* podmineny preklad proti opakovanemu inkludovani */
#ifndef KRU_IO_H
#define KRU_IO_H

/* definice symbolickych konstant vyuzivanych i v jinych
   modulech */
#define CHYBA_DAT    -1.0

/* definice maker s parametry */
  /* v tomto modulu zadne nejsou */

/* definice globalnich typu */
  /* v tomto modulu zadne nejsou */

/* deklarace globalnich promennych modulu kru_io.c */
  /* v tomto modulu zadne nejsou */

/* uplne funkcni prototypy globalnich funkci modulu kru_io.c */
extern double vstup_dat(void);
extern void   vystup_dat(double obsah);

#endif

