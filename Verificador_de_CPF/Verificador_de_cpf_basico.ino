int v1,v2;
void setup() {
  Serial.begin(112500);
}
void loop() {
  Serial.println("Digite o CPF:");
  while(Serial.available()==0);
  String CPF = Serial.readString();

  int a1 = CPF.charAt(0)-'0';
  int a2 = CPF.charAt(1)-'0';
  int a3 = CPF.charAt(2)-'0';
  int a4 = CPF.charAt(3)-'0';
  int a5 = CPF.charAt(4)-'0';
  int a6 = CPF.charAt(5)-'0';
  int a7 = CPF.charAt(6)-'0';
  int a8 = CPF.charAt(7)-'0';
  int a9 = CPF.charAt(8)-'0';
  int a10 = CPF.charAt(9)-'0';
  int a11 = CPF.charAt(10)-'0';

  if((((a1*10)+(a2*9)+(a3*8)+(a4*7)+(a5*6)+(a6*5)+(a7*4)+(a8*3)+(a9*2))%11)<2){
   v1 = 0; 
  }else{
   v1 = (11-(((a1*10)+(a2*9)+(a3*8)+(a4*7)+(a5*6)+(a6*5)+(a7*4)+(a8*3)+(a9*2))%11));
  }
  if((((a1*11)+(a2*10)+(a3*9)+(a4*8)+(a5*7)+(a6*6)+(a7*5)+(a8*4)+(a9*3)+(v1*2))%11)<2){
   v2 = 0;
  }else{
   v2 = (11-(((a1*11)+(a2*10)+(a3*9)+(a4*8)+(a5*7)+(a6*6)+(a7*5)+(a8*4)+(a9*3)+(v1*2))%11));
  }
  if (v1 == a10 && v2 == a11){
    Serial.println("CPF VALIDO");
  }else{
    Serial.println("CPF INVALIDO");
  }
}