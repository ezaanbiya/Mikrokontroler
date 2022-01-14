#include <Servo.h>                        //digunakan untuk menyertakan library Servo pada program Arduino
Servo myservo;                            //membuat variabel untuk Servo

int pos = 0;                              //deklarasi variabel untuk posisi sudut dari 0 derajat
const int pinIR = 2;                      //deklarasi konstanta untuk pin sensor infrared pada pin 2
const int pinLED = 3;                     //deklarasi konstanta untuk pin lampu LED pada pin 3
const int pinServo = 4;                   //deklarasi konstanta untuk pin Servo mini pada pin 4
const int pinSpeaker = 5;                 //deklarasi konstanta untuk pin Buzzer pada pin 5
const int pinSound = A0;                  //deklarasi konstanta untuk pin sensor suara pada pin analog 0
const int threshold = 200;                //deklarasi konstanta untuk tingkat ambang batas yang berada dalam kisaran input analog sensor suara

void setup(){                             //fungsi yang dipanggil ketika program dimulai dan hanya akan berjalan sekali saja setelah setiap powerUP atau ketika board Arduino direset
  pinMode(pinIR, INPUT);                  //meng-set mode pin pada pin sensor infrared sebagai pin input
  pinMode(pinSound, INPUT);               //meng-set mode pin pada pin sensor suara sebagai pin input
  pinMode(pinLED, OUTPUT);                //meng-set mode pin pada pin lampu LED sebagai pin output
  pinMode(pinSpeaker, OUTPUT);            //meng-set mode pin pada pin Buzzer sebagai pin output
  myservo.attach(4);                      //deklarasi Servo pada pin 4
}

void loop(){                              //bertujuan untuk mengeksekusi dan menjalankan program yang sudah dibuat
  int nilaiIR = digitalRead(pinIR);       //variabel nilaiIR digunakan untuk menampung nilai input dari pinIR
  int nilaiSound = analogRead(pinSound);  //variabel nilaiSound digunakan untuk menampung nilai input dari pinSound
  if(nilaiIR == LOW){                     //jika nilaiIR sama dengan low / 0, maka
    pos = 0;                              //posisi sudut Servo mini 0 derajat
    myservo.write(pos);                   //memerintahkan Servo ke posisi derajat sesuai nilai variabel pos
    digitalWrite(pinLED, HIGH);           //salah satu perintah yang berfungsi untuk memberi nilai HIGH atau 1 kepada pinLED
    digitalWrite(pinSpeaker, HIGH);       //salah satu perintah yang berfungsi untuk memberi nilai HIGH atau 1 kepada pinSpeaker
    delay(2000);                          //berfungsi untuk merepresentasikan waktu diukur dalam milidetik, maka program harus menunggu sampai pindah ke baris kode berikutnya
    
    pos = 180;                            //posisi sudut Servo mini 180 derajat
    myservo.write(pos);                   //memerintahkan Servo ke posisi derajat sesuai nilai variabel pos
    digitalWrite(pinLED, LOW);            //salah satu perintah yang berfungsi untuk memberi nilai LOW atau 0 kepada pinLED
    digitalWrite(pinSpeaker, LOW);        //salah satu perintah yang berfungsi untuk memberi nilai LOW atau 0 kepada pinSpeaker
    delay(500);                           //berfungsi untuk merepresentasikan waktu diukur dalam milidetik, maka program harus menunggu sampai pindah ke baris kode berikutnya
  }
  if(nilaiSound >= threshold){            //jika nilaiSound lebih dari sama dengan threshold yakni 200, maka
    pos = 0;                              //posisi sudut Servo mini 0 derajat
    myservo.write(pos);                   //memerintahkan Servo ke posisi derajat sesuai nilai variabel pos
    digitalWrite(pinLED, HIGH);           //salah satu perintah yang berfungsi untuk memberi nilai HIGH atau 1 kepada pinLED
    digitalWrite(pinSpeaker, HIGH);       //salah satu perintah yang berfungsi untuk memberi nilai HIGH atau 1 kepada pinSpeaker
    delay(2000);                          //berfungsi untuk merepresentasikan waktu diukur dalam milidetik, maka program harus menunggu sampai pindah ke baris kode berikutnya
 
    pos = 180;                            //posisi sudut Servo mini 180 derajat
    myservo.write(pos);                   //memerintahkan Servo ke posisi derajat sesuai nilai variabel pos
    digitalWrite(pinLED, LOW);            //salah satu perintah yang berfungsi untuk memberi nilai LOW atau 0 kepada pinLED
    digitalWrite(pinSpeaker, LOW);        //salah satu perintah yang berfungsi untuk memberi nilai LOW atau 0 kepada pinSpeaker
    delay(500);                           //berfungsi untuk merepresentasikan waktu diukur dalam milidetik, maka program harus menunggu sampai pindah ke baris kode berikutnya
  }
}
