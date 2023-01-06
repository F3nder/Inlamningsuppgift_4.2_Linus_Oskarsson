/********************************************************************************
* car.h: Innehåller strukt för car-objekt och diverse funktionsdeklarationer.
********************************************************************************/
#ifndef CAR_H_
#define CAR_H_

/* Inkluderingsdirektiv */
#include <stdio.h>
#include <stdlib.h> 

/* Antalet Bliobjekt */
#define NUM_CARS 3

/* Enumerationer */
enum car_transmission { NONE, MANUAL, AUTOMATIC };

/********************************************************************************
* car_t: Strukt innehållande Märke, Modell, Färg, Lanseringsår och Växellåda 
*        samt funktionspekare för att byta färg, växellåda och utskrift.
********************************************************************************/
typedef struct
{
    char* brand;
    char* model;
    char* color;
    int year_of_launch;
    enum car_transmission transmission;
    void (*change_color)(struct car_t* self, char* color);
    void (*change_transmission)(struct car_t* self);
    void (*print)(struct car_t* self, FILE* ostream);
}car_t;

/********************************************************************************
* car_init: Initierar ett nytt car-objekt samt sätter funktions perkarna att
*           peka på respektive funktioner.
*
*
*           -self:           Pekare till bilen som skall initieras.
*
*           -brand:          BilMärke
*
*           -color:          Bilens Färg
*
*           -model:          Bilens Modell
*
*           -year_of_launch: Bilens Lanseringsår.
*
*           -transmission:   Bilens Växellåda.
********************************************************************************/
void car_init(car_t* self,
              char* brand,
              char* color,
              char* model,
              int year_of_launch,
              enum car_transmission transmission);

/********************************************************************************
* car_clear: Rensar/nollställer car-objekt.
*
*
*            -self: Pekare till car-objekt som skall nollställas.
********************************************************************************/
void car_clear(car_t* self);

/********************************************************************************
* car_new: Skapar och frigör minne för ett nytt car-objekt, returnerar 1 vid
*          misslyckad minnesallokering och returnerar skapat car-objekt vid
*          lyckad minnesallokering.
*
*
*           -self:           Pekare till det nya car-objektet.
*
*           -brand:          BilMärke
*
*           -color:          Bilens Färg
*
*           -model:          Bilens Modell
*
*           -year_of_launch: Bilens lLanseringsår.
*
*           -transmission:   Bilens Växellåda.
********************************************************************************/
car_t* car_new(car_t* self,
               char* brand,
               char* color,
               char* model,
               int year_of_launch,
               enum car_transmission transmission);

/********************************************************************************
* car_delete: Tar bort/raderar valt car-objektet och frigör minnet.
*
*
*             -self: Perkare till car-objektet.
********************************************************************************/
void car_delete(car_t* self);

/********************************************************************************
* car_print: Skriver ut car-objekt.
*
*
*             -self: Perkare till car-objektet.
*
*             -FILE: Filpekare
********************************************************************************/
void car_print(car_t* self,
               FILE* ostream);

/********************************************************************************
* car_change_color: Ändrar färg på angivet car-objekt.
*
*
*                   -self: Perkare till car-objektet.
*
*                   -color: Angiven ny färg.
********************************************************************************/
void car_change_color(car_t* self,
                      char* color);

/********************************************************************************
* car_change_transmission: Ändrar växellåda på angivet car-objekt.
*
*
*                          -self: Perkare till car-objektet.
*
*                          -transmission: Angiven ny växellåda.
********************************************************************************/
void car_change_transmission(car_t* self,
                             enum car_transmission transmission);

#endif // !CAR_H_

