

class tempos
{
  private:
    unsigned long vt;   // calcul de la tempo qui se déroule
    float val_t = 1.0;  // par défaut la tempo est 1 seconde
    unsigned long t0;   // temps en cours
    unsigned long t_stop = val_t * 1000;   // temps d'arret
    

  public:
    bool run = false;   // état de la tempo

      /*********** ok *************/
      // retourne l'état de la tempo si false la tempo n'est pas finie si true la tempo est terminée
    int ok() {
      if (run) t0 = millis(); // si tempo active on mémorise le temps
      if (t0>vt)  { // si tempo écoulée
        run = false; // stop la tempo
        t_stop = val_t*1000.0; // mémorise une nouvelle valeur d'atter
        return true; // indique que la tempo est finie
         } 
      else
        return false; // la tempo est en cours

    }

    /*********** val *************/
    // retourne le temps qui reste avant la fin de la tempo en seconde
    float val() { 
      return (vt - t0)/1000.0; // retourne le valeur de la tempo
    }  

    /*********** set *************/
    // définit la durée de la tempo en seconde
    void set(float val) { 
      val_t = val; // mémorise la durée de la tempo
      t_stop = val * 1000.0; 
    } 

    /*********** Start sans argument *************/
    // démarre la tempo en fonction de la durée réglé avec .set() par défaut 1s
    void start() { 
      t0 = millis();
      vt = t0 + t_stop;
      run = true;
     // vt  = t0 + val_t * 1000.0;
    }     
    
    /*********** start avec argument *************/
      // démarre la tempo en fonction de la durée donnée en argument
    void start(float val) { 
      val_t = val;
      t_stop = val*1000.0;
      t0 = millis();
      run = true;
      vt  =  t0 + val_t * 1000.0;
    } 
    

    /*********** pause *************/
      // met en pause le décompte de la tempo
    void pause() { 
      run = false;
      t_stop = vt-millis();
    } 

    /*********** stop *************/
      // stop le décompte de la tempo
    void stop() { 
      run = false;
      t_stop = val_t*1000.0;
      vt=0;
    }     
}; 

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
