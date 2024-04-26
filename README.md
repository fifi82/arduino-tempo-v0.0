# arduino-tempo
arduino tempo


classe pour créer des temporisations rapidement

les commandes :

création d'un objet tempo :

tempos t0;   // cré la tempo t0

utililisation :

- définir la durée de la tempo en seconde :
set(float val) 
ex:  t0.set(1.5);  // donne la durée de la tempo

- démarrer la tempo pour la première fois ou aprés une pause:
start()
ex: t0.start();  // démarre la tempo de 1.5 secondes

start(float val)
ex: t0.start(2.6);  // démarre la tempo de 2.6 secondes

- arrêt de la tempo
stop()
ex: t0.stop(); // stope la tenpo comme si elle est écoulée ok() passe à true

- met en pause la tempo
pause()
ex: t0.pause(); // suspend la tempo, pour la redémarrer faire .start()

- lecture de l'état de la tempo
ok()
ex:
if ( t0.ok() ) {  }

exemple Blink:

// Blink 
#define p_led 13
tempos t0;  // création de la tempo t0

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // pin 13 pour la led des arduino uno ou nano
  t0.start(0.5);          // règle la tempo à 500 ms et la démarre
}

void loop() {
  if( t0.ok() ) {         // si la tempo est écoulée     
    digitalWrite( LED_BUILTIN, !digitalRead(LED_BUILTIN) ); // inverse l'état de la led
    t0.start();           // redémarre la tempo    
  }
}



