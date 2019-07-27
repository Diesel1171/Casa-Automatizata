int StangaSus;
int DreaptaSus;
int StangaJos;
int DreaptaJos;
int Intarziere = 1;

void setup() 
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  TCCR1A = 0;
  TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
  TCCR1B = 0;
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);
  ICR1 = 40000;
  OCR1A = 3000;
  OCR1B = 3600;
}

void loop() 
{
  StangaSus = analogRead(A0);
  DreaptaSus = analogRead(A1);
  StangaJos = analogRead(A2);
  DreaptaJos = analogRead(A3);

  if (StangaSus > DreaptaSus) 
   {
     OCR1A = OCR1A + 1;
     delay(Intarziere);
   }
   
  if (StangaJos > DreaptaJos) 
   {
     OCR1A = OCR1A + 1;
     delay(Intarziere);
   }
   
  if (StangaSus < DreaptaSus) 
   {
     OCR1A = OCR1A - 1;
     delay(Intarziere);
   }
   
  if (StangaJos < DreaptaJos) 
   {
     OCR1A = OCR1A - 1;
     delay(Intarziere);
   }
   
  if (OCR1A > 4000) 
   {
     OCR1A = 4000;
   }
   
  if (OCR1A < 2000) 
   {
     OCR1A = 2000;
   }
   
  if (StangaSus > StangaJos) 
   {
     OCR1B = OCR1B - 1;
     delay(Intarziere);
   }
   
  if (DreaptaSus > DreaptaJos) 
   {
     OCR1B = OCR1B - 1;
     delay(Intarziere);
   }
   
  if (StangaSus < StangaJos) 
   {
     OCR1B = OCR1B + 1;
     delay(Intarziere);
   }
   
  if (DreaptaSus < DreaptaJos) 
   {
     OCR1B = OCR1B + 1;
     delay(Intarziere);
   }
   
  if (OCR1B > 4200) 
   {
     OCR1B = 4200;
   }
   
  if (OCR1B < 3000) 
   {
     OCR1B = 3000;
   }
}
