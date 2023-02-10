int now_floor = 1;
String state = "UP";
bool turn = 0;

int start = 0;
int start1 = 1;
int start2 = 1;
int end = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT); // pb 1
  pinMode(3, INPUT); // pb 2
  pinMode(4, INPUT); // pb 3

  analogWrite(11, 200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 5(3),8(2),11(1)
  if (digitalRead(2)){
    if(now_floor != 1){
      state = "DOWN";

      analogWrite(A1, 200);
      delay(250);

      if(now_floor == 3){
        analogWrite(5, 200);
        delay(250);

        start = 5;
        end = 11;

        for (int i = 5; i < end; i++){
          analogWrite(i, 0);
          analogWrite(i+1, 200);

          if(digitalRead(3)){
            if(i < 8){            
              analogWrite(A2, 200);
            }
            else{
              analogWrite(A2, 200); 
              turn = 1;
              }
          }

          if(digitalRead(4)){
            analogWrite(A3, 200);
            turn = 1; }

          if((i+1)== 8){
            analogWrite(A2, 0);
            now_floor = 2;
          }

          if((i+1)== 11){
            analogWrite(A1, 0);
            now_floor = 1;
          }
          delay(250);
        }
      }
      else if (now_floor == 2){
        analogWrite(8, 200);
        delay(250);

        start = 8;
        end = 11;

        for (int i = 8; i < 11; i++){
          analogWrite(i, 0);
          analogWrite(i+1, 200);

          if(digitalRead(3) || digitalRead(4)){
            analogWrite(A3, 200);
            turn = 1;
          }
          delay(250);
        }
        analogWrite(A1, 0);
        now_floor = 1;
      }
      if (turn == 1){ // 3층 끝까지
        state = "UP";
        analogWrite(A3, 200);
        for (int j = 11; j > 5; j--){
          analogWrite(j, 0);
          analogWrite(j-1, 200);
          delay(250);
          if(j==9){
            analogWrite(A2, 0);
          }
        }
      
        analogWrite(A3, 0);
        turn = 0;
        now_floor = 3;
      }
    }
  }
  else if(digitalRead(3)){
    if (now_floor != 2){
      
      analogWrite(A2, 200);
      delay(250);

        if (now_floor == 3){

          state = "DOWN";
          
          analogWrite(5, 200);
          delay(250);
          
          start = 5;
          end = 8;
          
          for (int i = 5; i < end; i++){
            analogWrite(i, 0);
            analogWrite(i+1, 200);
  
            if(digitalRead(2)){
              end = 11;
              analogWrite(A1, 200);
            }

            if(digitalRead(4)){
              analogWrite(A3, 200);

              if (i < 8){
                start1 = 8;
              }
              else{
                start1 = 11;
              }
              turn = 1;
            }

            if(i > 8){
              if(digitalRead(3)){
                analogWrite(A2, 200);
                start1 = 11;
                turn = 1;
              }
            }

            if((i+1)== 8){
              analogWrite(A2, 0);
              now_floor = 2;
            }
            
            if((i+1)== 11){
              analogWrite(A1, 0);
              now_floor = 1;
            }
            delay(250);
        }

        if (turn == 1){ // 3층 끝까지
          state = "UP";
          analogWrite(A3, 200);

          for (int i = start1; i > 5; i--){
            analogWrite(i, 0);
            analogWrite(i-1, 200);
            delay(250);
          }
        
          analogWrite(A3, 0);
          turn = 0;
          now_floor = 3;
        }

      }
      else if (now_floor == 1){
        state = "UP";

        analogWrite(11, 200);
        delay(250);
        
        start = 11;
        end = 8;
        
        for (int i = 11; i > end; i--){
          analogWrite(i, 0);
          analogWrite(i-1, 200);

          if (digitalRead(4)){
            end = 5;
            analogWrite(A3, 200);
          }
        
          if (digitalRead(2)){
            analogWrite(A1, 200);
            
            if (i > 8){
              start2 = 8;
            }
            else{
              start2 = 5;
            }
            turn = 1;
          }

          if(i < 8){
            if(digitalRead(3)){
              analogWrite(A2, 200);
              start2 = 5;
              turn = 1;
            }
          }
                      
          if((i-1)== 8){
            analogWrite(A2, 0);
            now_floor = 2;
          }

          if((i-1)== 5){
            analogWrite(A3, 0);
            now_floor = 3;
          }
          delay(250);
        }
        if (turn == 1){ // 1층 끝까지
          state = "DOWN";
          analogWrite(A1, 200);

          for (int i = start2; i < 11; i++){
            analogWrite(i, 0);
            analogWrite(i+1, 200);
            delay(250);
          }
        
          analogWrite(A1, 0);
          turn = 0;
          now_floor = 1;
        }
      }
    }
  }
  else if (digitalRead(4)){
    if (now_floor != 3){
      state = "UP";
      analogWrite(A3, 200);
      delay(250);

      if(now_floor == 2){
        analogWrite(8, 200);
        delay(250);

        start = 8;
        end = 5;

        for (int i = 8; i > 5; i--){
          analogWrite(i, 0);
          analogWrite(i-1, 200);

          if(digitalRead(2) || digitalRead(3)){
            analogWrite(A1, 200);
            turn = 1;
            }
            delay(250);
          }
        analogWrite(A3, 0);
        now_floor = 3;
        
        if (turn == 1){ // 1층 끝까지
        state = "DOWN";
        analogWrite(A1, 200);

        for (int i = 5; i < 11; i++){
          analogWrite(i, 0);
          analogWrite(i+1, 200);
          delay(250);

          if(i == 8){
            analogWrite(A2, 0);
            }
          }
        
          analogWrite(A1, 0);
          turn = 0;
          now_floor = 1;
        }
      }
      else if (now_floor == 1){
        analogWrite(11, 200);
        delay(250);

        start = 11;
        end = 5;

        for (int i = 11; i > 5; i--){
          analogWrite(i, 0);
          analogWrite(i-1, 200);

          if(digitalRead(3)){
            analogWrite(A2, 200);
          }

          if(digitalRead(3)){
            if(i > 8){
              analogWrite(A2, 200);
            }
            else{ turn = 1; }
          }

          if(digitalRead(2)){ turn = 1; }

          if((i-1)== 8){
            analogWrite(A2, 0);
            now_floor = 2;
          }

          if((i-1)== 5){
            analogWrite(A3, 0);
            now_floor = 3;
          }
          delay(250);
        }
        if (turn == 1){ // 1층 끝까지
          state = "DOWN";
          analogWrite(A1, 200);

          for (int i = 5; i < 11; i++){
            analogWrite(i, 0);
            analogWrite(i+1, 200);
            delay(250);

            if(i == 8){
              analogWrite(A2, 0);
              }
            }

          analogWrite(A1, 0);
          turn = 0;
          now_floor = 1;
        }
      }
    }
  }
  else{}
}
