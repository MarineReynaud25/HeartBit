#include <esp_now.h>
#include <WiFi.h>

#define LEDPin 5
#define MOTORPin 8
#define INTERRUPT_PIN 7
#define DELTA 10

unsigned long time_last_int = millis();

bool led_state = false;
bool old_led_state = false;

const uint8_t broadcastAddress[] = {0xec, 0xda, 0x3b, 0xab, 0x08, 0x40};
//const uint8_t broadcastAddress[] = {0xec, 0xda, 0x3b, 0xaa, 0xf6, 0x34};


struct struct_message {
  String a;
  bool ledStatus;
};

struct_message myData;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int data_len) {
  struct_message incomingMessage;

  if (data_len == sizeof(struct_message)) {
    memcpy(&incomingMessage, data, sizeof(incomingMessage)); 
    Serial.println("Received data from another ESP32");
    Serial.print("Bytes received: ");
    Serial.print("String: ");
    Serial.println(incomingMessage.a);
    Serial.print("LED Status: ");
    Serial.println(incomingMessage.ledStatus ? "ON" : "OFF");
    digitalWrite(LEDPin, incomingMessage.ledStatus);
    digitalWrite(MOTORPin, incomingMessage.ledStatus);
  } 
}

void setup() {
  Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
  pinMode(MOTORPin, OUTPUT);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  attachInterrupt(INTERRUPT_PIN, isr_callback, CHANGE); //sur le pin interrupt si ya changement d'état on appelle isr callback

 
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void isr_callback(){
    if(millis() - time_last_int > DELTA){
      led_state = !led_state;
      time_last_int = millis();
    }
  
  }


void loop() {
  if (old_led_state != led_state){
    myData.a = "Hello";
    myData.ledStatus = led_state;
    
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));

    if (result == ESP_OK) {
      Serial.println("Sent with success");
      } else {
      Serial.println("Error sending the data");
      }

    old_led_state = led_state;

    //delay(500);

    }
}
