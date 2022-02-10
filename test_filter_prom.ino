static int k;
float y_anterior;
static bool primerBucle = true;

int AddNoise();

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(primerBucle){
    primerBucle = false;
    y_anterior = 0;
    k = 1;
  }

  int Sensor = 500;
  float NoisySignal = Sensor + AddNoise();

  float alpha = float(k-1)/float(k);
  float y_k = alpha*y_anterior + (1-alpha)*NoisySignal;
  
  Serial.print(NoisySignal);
  Serial.print(",");
  Serial.println(y_k);
  y_anterior = y_k;
  k=k+1;
}

int AddNoise(){
  return random(0,200);
  
}
