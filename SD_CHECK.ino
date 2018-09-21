#include<SD.h>
#include<SPI.h>

int file_read,reading;

File myFile;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Serial connected");

  Serial.println("Initializing SD card...");
  if(!SD.begin(4)){
    Serial.println("INIT FAILED");
    delay(3000);
    exit(0);
  }
  Serial.println("INIT Successful");
 myFile=SD.open("data.txt",FILE_READ);
}

void loop() {
  // put your main code here, to run repeatedly:
  file_read=0;
  if(myFile.available()){
  while(myFile.available())
    {reading=myFile.read()-'0';
      if(reading!='\n'&&reading>0)
        file_read=10*file_read+reading;
    }
   Serial.println(file_read);
  }
  else
    exit(0);
}
