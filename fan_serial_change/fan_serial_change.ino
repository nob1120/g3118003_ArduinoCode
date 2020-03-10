//以下のコード類だけは絶対に忘れないように！！！
int PWM=000; //PWMの値218が距離1.7mに対して風速4.2msでちょうど良い値となる

void setup () {
        Serial.begin(9600);
        pinMode(6, OUTPUT);  //fan1
        pinMode(9, OUTPUT);  //fan2
        pinMode(10, OUTPUT); //fan3
        pinMode(11, OUTPUT); //fan4
  }

void loop() {
  int inputchar;
 
  // シリアルポートより1文字読み込む
  inputchar = Serial.read();
 
  if(inputchar != -1 ){
    // 読み込んだデータが -1 以外の場合　以下の処理を行う
 
    switch(inputchar){
      case 'w': // 読み込みデータが w の場合にfan1とfan3を駆動
        Serial.print("PWM W");
        analogWrite(6, PWM);
        analogWrite(10, PWM);
        delay(0);
        break;

      case 'e': // 読み込みデータが e の場合にfan1を駆動
        Serial.print("PWM e");
        analogWrite(6, PWM);
        delay(30000);
        break;

      case 'd': // 読み込みデータが d の場合にfan1とfan2を駆動
        Serial.print("PWM d");
        analogWrite(6, PWM);
        analogWrite(9, PWM);
        delay(30000);
        break;

      case 'x': // 読み込みデータが x の場合にfan2を駆動
        Serial.print("PWM x");
        analogWrite(9, PWM);
        delay(30000);
        break;

      case 's': // 読み込みデータが s の場合にfan2とfan4を駆動
        Serial.print("PWM d");
        analogWrite(9, PWM);
        analogWrite(11, PWM);
        delay(30000);
        break;


      case 'z': // 読み込みデータが s の場合にfan4を駆動
        Serial.print("PWM z");
        analogWrite(11, PWM);
        delay(30000);
        break;

      case 'a': // 読み込みデータが a の場合にfan3とfan4を駆動
        Serial.print("PWM a");
        analogWrite(10, PWM);
        analogWrite(11, PWM);
        delay(30000);
        break;

      case 'q': // 読み込みデータが q の場合にfan3を駆動
        Serial.print("PWM q");
        analogWrite(10, PWM);
        delay(30000);
        break;



      case '0':  
        // 読み込みデータが　0 の場合にファンを切る
 
        Serial.print("PWM OFF\L");
        digitalWrite(6, LOW);
        break;
    }
    Serial.print("Ready\n");
  } else {
    // 読み込むデータが無い場合は何もしない
  }
}
