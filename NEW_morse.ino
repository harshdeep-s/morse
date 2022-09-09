int time1 = 500;
int time2 = 1500;
String name = "harsh";


String alpha = "abcdefghijklmnopqrstuvwxyz";

String morse[26][4] = {{"d","s"},{"s","d","d","d"},{"s","d","s","d"},{"s","d","d"},{"d"},
{"d","d","s","d"},{"s","s","d"},{"d","d","d","d"},{"d","d"},{"d","s","s","s"},{"s","d","s"},{"d","s","d","d"},{"s","s"},
{"s","d"},{"s","s","s"},{"d","s","s","d"},{"s","s","d","s"},{"d","s","d"},{"d","d","d"},{"s"},{"d","d","s"},
{"d","d","d","s"},{"d","s","s"},{"s","d","d","s"},{"s","d","s","s"},{"s","s","d","d"}};
 



void setup()
{
Serial.begin(9600);  
   pinMode(11, OUTPUT);
   
}

void loop()
{
          
          
            int l;
            String light;

            Serial.println("Enter your name: ");  
            name = Serial.readString();
            
            if(name.length() > 1)
            {
                for(int i = 0; i < name.length(); i++)
                {
                    l = checkalpha(name[i]);
      
                    Serial.println(name[i]);
                    
                
                    for(int j =0; j < 4; j++)
                    {
                       light = morse[l][j];
        
                           if(light == "d")
                             {
                              dot(time1);
                            
                             }
                        
                           else if(light == "s")
                             {
                              dash(time2);
                     
                             }
                    }
      
                    delay(2000);
                  
                }

            }
}

void dash(int time)
    {
      digitalWrite(11, HIGH);  
      delay(time);                     
      digitalWrite(11, LOW);  
      delay(100);     
    }

 void dot(int time)
{
  digitalWrite(11, HIGH);  
  delay(time);                     
  digitalWrite(11, LOW);  
  delay(100);     
}

int checkalpha(char words)
{
  for(int i = 0; i < alpha.length(); i++)
  {
    if(alpha[i] == words)
    {
      return i;
    }
    
  }

}
