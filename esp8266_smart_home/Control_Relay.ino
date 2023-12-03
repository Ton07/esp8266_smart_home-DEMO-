void Controlrelay();
BLYNK_WRITE(V0) {
  int val = param.asInt();
  if (val == 0) {
    digitalWrite(relay1, LOW);
    stateRelay1 = LOW;
    Serial.println("relay1 OFF");
  } else {
    digitalWrite(relay1, HIGH);
    stateRelay1 = HIGH;
    Serial.println("relay1 ON");
  }
}
BLYNK_WRITE(V1) {
  int val2 = param.asInt();
  if (val2 == 0) {
    digitalWrite(relay2, LOW);
    stateRelay2 = LOW;
    Serial.println("relay2 OFF");
  } else {
    digitalWrite(relay2, HIGH);
    stateRelay2 = HIGH;
    Serial.println("relay2 ON");
  }
}
BLYNK_WRITE(V2) {
  int val3 = param.asInt();
  if (val3 == 0) {
    digitalWrite(relay3, LOW);
    stateRelay3 = LOW;
    Serial.println("relay3 OFF");
  } else {
    digitalWrite(relay3, HIGH);
    stateRelay3 = HIGH;
    Serial.println("relay3 ON");
  }
}
BLYNK_WRITE(V3) {
  int val4 = param.asInt();
  if (val4 == 0) {
    digitalWrite(relay4, LOW);
    stateRelay4 = LOW;
    Serial.println("relay4 OFF");
  } else {
    digitalWrite(relay4, HIGH);
    stateRelay4 = HIGH;
    Serial.println("relay4 ON");
  }
}
