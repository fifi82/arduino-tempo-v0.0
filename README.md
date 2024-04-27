# arduino-tempos
arduino tempos


classe pour créer des temporisations rapidement pour arduino<br>
la classe utilise millis() de arduino.h<br>
les commandes :

création d'un objet tempo :

	tempos t0;   // cré la tempo t0


définir la durée de la tempo en seconde :

	-set(float val) 
	-ex:  t0.set(1.5);  // donne la durée de la tempo


démarrer la tempo pour la première fois ou aprés une pause:

	start()
	ex: t0.start();  // démarre la tempo de 1.5 secondes


start(float val)

	ex: t0.start(2.6);  // démarre la tempo de 2.6 secondes


arrêt de la tempo

	stop()
	ex: t0.stop(); // stope la tenpo comme si elle est écoulée ok() passe à true

*met en pause la tempo

	pause()
	ex: t0.pause(); // suspend la tempo, pour la redémarrer faire .start()


lecture de l'état de la tempo

	ok()
	ex: if ( t0.ok() ) {  }


lecture du temps qui reste  

	val()
	ex: temps_restant = t0.val();


savoir si la tempo est en marche ou arret

	run
	ex: if(t0.run) Serial.println("tempo en marche"); else Serial.println("tempo en stop");
 
Blink :
	
	////////////////////////////////////////////////////
	//                  exemple Blink:
	/////////////////////////////////////////////////////
	// fifi82 2024
	
	#include <tempos.h>
	
	tempos t0;  // création de la tempo t0
	
	void setup() {
	  Serial.begin(9600);     // démarre le port série
	  pinMode(LED_BUILTIN, OUTPUT); // pin 13 pour la led des arduino uno ou nano
	  t0.start(0.5);          // règle la tempo à 500 ms et la démarre
	}
	
	void loop() {
	  if( t0.ok() ) {         // si la tempo est écoulée     
	    Serial.println("fin tempo"); // affiche "fin tempo"
	    digitalWrite( LED_BUILTIN, !digitalRead(LED_BUILTIN) ); // inverse l'état de la led
	    t0.start();           // redémarre la tempo    
	  }
	}
	
	
	
