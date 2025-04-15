#include "pitches.h"

// change this to make the song slower or faster
int tempo = 200;
int tempo2 = 144;
int tempo3 = 115;
int tempo4 = 140;
int tempoRR = 114;

// change this to whichever pin you want to use
int buzzer = 4;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
// int melody[] = {

//   // Super Mario Bros theme
//   // Score available at https://musescore.com/user/2123/scores/2145
//   // Theme by Koji Kondo
  
//   NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
//   NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
//   NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
//   NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//   NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//   REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
//   NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
//   NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//   NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//   REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  
//   REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
//   REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
//   REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
//   NOTE_C5,2, REST,2,

//   REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
//   REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
//   REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
//   NOTE_C5,2, REST,2,

//   NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
//   NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

//   NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
//   REST,1, 
//   NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
//   NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
//   NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
//   NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
//   NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19
  
//   NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//   NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//   REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

//   NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
//   NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//   NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//   REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

//   NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
//   NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//   NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
//   NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
//   NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//   NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//   NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
//   NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

//   NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
//   NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//   NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
//   NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
//   NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//   NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//   NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
//   NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
//   NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
//   REST,1,

//   NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
//   NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
//   NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
//   NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
//   NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//   NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//   NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
//   NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
//   NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//   NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//   NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
//   NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  
//   //game over sound
//   NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
//   NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
//   NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  

// };

// int LOZmelody[] = {
//   //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=169
  
//   NOTE_AS4,-2,  NOTE_F4,8,  NOTE_F4,8,  NOTE_AS4,8,//1
//   NOTE_GS4,16,  NOTE_FS4,16,  NOTE_GS4,-2,
//   NOTE_AS4,-2,  NOTE_FS4,8,  NOTE_FS4,8,  NOTE_AS4,8,
//   NOTE_A4,16,  NOTE_G4,16,  NOTE_A4,-2,
//   REST,1, 

//   NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//7
//   NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
//   NOTE_AS5,-2,  NOTE_AS5,8,  NOTE_AS5,8,  NOTE_GS5,8,  NOTE_FS5,16,
//   NOTE_GS5,-8,  NOTE_FS5,16,  NOTE_F5,2,  NOTE_F5,4, 

//   NOTE_DS5,-8, NOTE_F5,16, NOTE_FS5,2, NOTE_F5,8, NOTE_DS5,8, //11
//   NOTE_CS5,-8, NOTE_DS5,16, NOTE_F5,2, NOTE_DS5,8, NOTE_CS5,8,
//   NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8, 
//   NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8,

//   NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//15
//   NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
//   NOTE_AS5,-2, NOTE_CS6,4,
//   NOTE_C6,4, NOTE_A5,2, NOTE_F5,4,
//   NOTE_FS5,-2, NOTE_AS5,4,
//   NOTE_A5,4, NOTE_F5,2, NOTE_F5,4,

//   NOTE_FS5,-2, NOTE_AS5,4,
//   NOTE_A5,4, NOTE_F5,2, NOTE_D5,4,
//   NOTE_DS5,-2, NOTE_FS5,4,
//   NOTE_F5,4, NOTE_CS5,2, NOTE_AS4,4,
//   NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8, 
//   NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8

// };

// int melodyCant[] = {
//   // Cantina BAnd - Star wars 
//   // Score available at https://musescore.com/user/6795541/scores/1606876
//   NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
//   NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8, 
//   NOTE_B4,8,  NOTE_AS4,8, NOTE_B4,8, NOTE_A4,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_G4,8,
//   NOTE_G4,4,  NOTE_E4,-2, 
//   NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
//   NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,

//   NOTE_A4,-4, NOTE_A4,-4, NOTE_GS4,8, NOTE_A4,-4,
//   NOTE_D5,8,  NOTE_C5,-4, NOTE_B4,-4, NOTE_A4,-4,
//   NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
//   NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,
//   NOTE_D5,4, NOTE_D5,-4, NOTE_B4,8, NOTE_A4,-4,
//   NOTE_G4,-4, NOTE_E4,-2,
//   NOTE_E4, 2, NOTE_G4,2,
//   NOTE_B4, 2, NOTE_D5,2,

//   NOTE_F5, -4, NOTE_E5,-4, NOTE_AS4,8, NOTE_AS4,8, NOTE_B4,4, NOTE_G4,4, 

// };

int melodyTetris[] = {

  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
  
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
  

  NOTE_E5,2,  NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,2,   NOTE_A4,2,
  NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
  NOTE_E5,2,   NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2,

};


// int melodyRR[] = {

//   // Never Gonna Give You Up - Rick Astley
//   // Score available at https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
//   // Arranged by Chlorondria

//   NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //1
//   NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
//   NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
//   NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
//   NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //repeat from 1
//   NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
//   NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
//   NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
//   REST,4, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_D5,8, NOTE_E5,8, NOTE_CS5,-8,
//   NOTE_B4,16, NOTE_A4,2, REST,4, 

//   REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,4, NOTE_A4,8, //7
//   NOTE_A5,8, REST,8, NOTE_A5,8, NOTE_E5,-4, REST,4, 
//   NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,8, REST,8,
//   REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//   REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
//   NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, REST,4,
   
//   NOTE_D5,2, NOTE_E5,8, NOTE_FS5,8, NOTE_D5,8, //13
//   NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, NOTE_A4,4,
//   REST,2, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8,
//   REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

//   NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
//   NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
//   NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

//   NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
//   NOTE_E5,4, NOTE_D5,2, REST,4,
//   REST,8, NOTE_B4,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,4, REST,8,
//   REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//   REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
//   REST,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_D5,8,
  
//   REST,8, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //29
//   REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//   NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4, REST,8,
//   REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,4, NOTE_E5,-4, 
//   NOTE_D5,2, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, 
//   NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_A4,8, NOTE_A4,4,

//   REST,-4, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //35
//   REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 

//    NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //40
//   NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
//   NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
   
//   NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
//   NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
//   NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
  
//   NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 

//   NOTE_E5,4, NOTE_D5,2, REST,4
// };

// int melodySonic[] = {

//   // Gren Hill Zone - Sonic the Hedgehog
//   // Score available at https://musescore.com/user/248346/scores/461661
//   // Theme by Masato Nakamura, arranged by Teddy Mason
  
//   REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

//   REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
//   NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
//   REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

//   REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
//   NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
//   NOTE_E4,-1,
//   REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

//   REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
//   REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,-1, //end 1

//   //repeats from 1

//   REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

//   REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
//   NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
//   REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

//   REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
//   NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
//   REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
//   NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
//   NOTE_E4,-1,
//   REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

//   REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
//   REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,8, //end 2
//   NOTE_E4,-2, NOTE_A4,8, NOTE_CS5,8, 
//   NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8, NOTE_A5,-4,

// };

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
// int notesSonic = sizeof(melodySonic) / sizeof(melodySonic[0]) / 2;
// int notesRR = sizeof(melodyRR) / sizeof(melodyRR[0]) / 2;
int notesTetris = sizeof(melodyTetris)/sizeof(melodyTetris[0])/2;
// int notes = sizeof(melody) / sizeof(melody[0]) / 2;
// int notesLOZ = sizeof(LOZmelody) / sizeof(LOZmelody[0]) / 2;
// int notesCant = sizeof(melodyCant) / sizeof(melodyCant[0]) / 2;
int noters;

// int notesFunction(int tempos, int mellonys[]) {
//   noters = sizeof(mellonys) / sizeof(mellonys[0]) / 2;
//   int wholes = (60000 * 4) / tempos;
//   return noters, wholes;
// }

// this calculates the duration of a whole note in ms
// int wholenote = (60000 * 4) / tempo;
int wholenote2 = (60000 * 4) / tempo2;
// int wholenote3 = (60000 * 4) / tempo3;
// int wholenote4 = (60000 * 4) / tempo4;
// int wholenoteRR = (60000 * 4) / tempoRR;

int divider = 0, noteDuration = 0;

void Musicfunction(int notes, int wholenotes, int melodys[]) {
    divider = 0;
    noteDuration = 0;
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melodys[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenotes) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenotes) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer, melodys[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
    }
  }


const int motorPin = 8;
const int xxx = 7;

void setup() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  pinMode(motorPin, OUTPUT);
  pinMode(xxx, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  divider = 0;
  noteDuration = 0;

  // Legends of Zelda
  //Musicfunction(notesLOZ, wholenote3, LOZmelody);
  //Musicfunction(notesTetris, wholenote2, melodyTetris);
  tone(buzzer, NOTE_E5, 0);
  digitalWrite(motorPin, HIGH);
  digitalWrite(xxx, HIGH);
  delay(333);
  // digitalWrite(motorPin, LOW);
  // delay(333);
  // digitalWrite(motorPin, HIGH);
  // delay(333);
  // noTone(buzzer);
  // digitalWrite(motorPin, LOW);
  // digitalWrite(xxx, LOW);
  // delay(333);
  // Musicfunction(notesRR, wholenoteRR, melodyRR);
  //Musicfunction(notes, wholenote, melody); /* Mario Song 0*/
  // Musicfunction(notesCant, wholenote4, melodyCant);
  // Musicfunction(notesSonic, wholenote4, melodySonic);



  // Musicfunction(notesFunction(melodySonic), wholenote4, melodySonic);

  // for (int thisNote = 0; thisNote < notesLOZ * 2; thisNote = thisNote + 2) {
  //   divider = LOZmelody[thisNote + 1];
  //   if (divider > 0) {
  //     noteDuration = (wholenote3) / divider;
  //   } else if (divider < 0) {
  //     noteDuration = (wholenote3) / abs(divider);
  //     noteDuration *= 1.5;
  //   }
  //   tone(buzzer, LOZmelody[thisNote], noteDuration*0.9);
  //   delay(noteDuration);
  //   noTone(buzzer);
  // }

  // divider = 0;
  // noteDuration = 0;

  // // Mos Eisley Cantina
  // for (int thisNote = 0; thisNote < notesCant * 2; thisNote = thisNote + 2) {
  //   divider = melodyCant[thisNote + 1];
  //   if (divider > 0) {
  //     noteDuration = (wholenote4) / divider;
  //   } else if (divider < 0) {
  //     noteDuration = (wholenote4) / abs(divider);
  //     noteDuration *= 1.5;
  //   }
  //   tone(buzzer, melodyCant[thisNote], noteDuration*0.9);
  //   delay(noteDuration);
  //   noTone(buzzer);
  // }

  // divider = 0;
  // noteDuration = 0;

  // // Tetris
  // for (int thisNote = 0; thisNote < notesTetris * 2; thisNote = thisNote + 2) {
  //   divider = melodyTetris[thisNote + 1];
  //   if (divider > 0) {
  //     noteDuration = (wholenote2) / divider;
  //   } else if (divider < 0) {
  //     noteDuration = (wholenote2) / abs(divider);
  //     noteDuration *= 1.5;
  //   }
  //   tone(buzzer, melodyTetris[thisNote], noteDuration*0.9);
  //   delay(noteDuration);
  //   noTone(buzzer);
  // }
  
  // divider = 0;
  // noteDuration = 0;

  // SUPER MARIO MELODY!!!
  // for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
  //   divider = melody[thisNote + 1];
  //   if (divider > 0) {
  //     noteDuration = (wholenote) / divider;
  //   } else if (divider < 0) {
  //     noteDuration = (wholenote) / abs(divider);
  //     noteDuration *= 1.5;
  //   }
  //   tone(buzzer, melody[thisNote], noteDuration * 0.9);
  //   delay(noteDuration);
  //   noTone(buzzer);
  // }

  // divider = 0;
  // noteDuration = 0;

  // // Rick Roll
  // for (int thisNote = 0; thisNote < notesRR * 2; thisNote = thisNote + 2) {
  //   divider = melodyRR[thisNote + 1];
  //   if (divider > 0) {
  //     noteDuration = (wholenoteRR) / divider;
  //   } else if (divider < 0) {
  //     noteDuration = (wholenoteRR) / abs(divider);
  //     noteDuration *= 1.5;
  //   }
  //   tone(buzzer, melodyRR[thisNote], noteDuration * 0.9);
  //   delay(noteDuration);
  //   noTone(buzzer);
  // }

// // Sonic
// for (int thisNote = 0; thisNote < notesSonic * 2; thisNote = thisNote + 2) {
//     divider = melodySonic[thisNote + 1];
//     if (divider > 0) {
//       noteDuration = (wholenote4) / divider;
//     } else if (divider < 0) {
//       noteDuration = (wholenote4) / abs(divider);
//       noteDuration *= 1.5;
//     }
//     tone(buzzer, melodySonic[thisNote], noteDuration * 0.9);
//     delay(noteDuration);
//     noTone(buzzer);
//   }
// Sonic notes - notesSonic
// Speed = wholenote4
// SonicMelody = melodySonic

}


