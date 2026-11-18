// J3: 1=regulated 5V, 2=D8, 3=GND. Coil power does not come from D8.
const byte HDMI_ENABLE = 8;
void setup() {
  digitalWrite(HDMI_ENABLE, LOW);
  pinMode(HDMI_ENABLE, OUTPUT);
  Serial.begin(115200);
  Serial.println("Send 1=HDMI ON, 0=HDMI OFF");
}
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '1') digitalWrite(HDMI_ENABLE, HIGH);
    if (c == '0') digitalWrite(HDMI_ENABLE, LOW);
  }
}
