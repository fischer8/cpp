int cpf[] = {'a1','a2','a3','a4','a5','a6','a7','a8','a9','a10','a11'};
int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,r1,r2,v10,v11;
String CPF;

void setup() {
  Serial.begin(112500);
}
void loop() {
  Serial.println("Digite o CPF: ");
  while(Serial.available()==0);
  CPF = Serial.readString();
  
  cpf[0] = CPF.charAt(0)-'0';
  cpf[1] = CPF.charAt(1)-'0';
  cpf[2] = CPF.charAt(2)-'0';
  cpf[3] = CPF.charAt(3)-'0';
  cpf[4] = CPF.charAt(4)-'0';
  cpf[5] = CPF.charAt(5)-'0';
  cpf[6] = CPF.charAt(6)-'0';
  cpf[7] = CPF.charAt(7)-'0';
  cpf[8] = CPF.charAt(8)-'0';
  cpf[9] = CPF.charAt(9)-'0';
  cpf[10] = CPF.charAt(10)-'0';

  a1 = cpf[0];
  a2 = cpf[1];
  a3 = cpf[2];
  a4 = cpf[3];
  a5 = cpf[4];
  a6 = cpf[5];
  a7 = cpf[6];
  a8 = cpf[7];
  a9 = cpf[8];
  a10 = cpf[9];
  a11 = cpf[10];

  r1=((a1*10)+(a2*9)+(a3*8)+(a4*7)+(a5*6)+(a6*5)+(a7*4)+(a8*3)+(a9*2))%11;

  if(r1<2){
    v10=0; 
  }else{
    v10=(11-r1);
  }

  r2 = ((a1*11)+(a2*10)+(a3*9)+(a4*8)+(a5*7)+(a6*6)+(a7*5)+(a8*4)+(a9*3)+(v10*2))%11;

  if(r2<2){
    v11 = 0;
  }else{
    v11 = (11-r2);
  }
  if (v11 == a11 && v10 == a10){
    Serial.print("CPF ");
  for (int i = 0; i < 11; i++) {
    Serial.print(cpf[i]);
    delay(200);}
    Serial.println(" ");
    Serial.println(" VALIDO");
    Serial.println(" ");
  }else{
    Serial.print("CPF ");
  for (int i = 0; i < 11; i++) {
    Serial.print(cpf[i]);
    delay(200);}
    Serial.println(" ");
    Serial.println(" INVALIDO");
    Serial.print("VERIFICADOR CORRETO: ");
    Serial.print(v10);
    Serial.println(v11);
    Serial.println(" ");
  }
}